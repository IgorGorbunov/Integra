#pragma once

#include "ODBCclass.h"
#include "Attribute.h"
#include "BookSettings.h"
#include "ComplexAttribute.h"
#include "AttributePair.h"
#include "IntegrationGroupPair.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class IntegrationSettings 
	{
	public:
		enum class IntegrationType
		{
			OneWay, TwoWay
		};

		property int Id
		{
			int get()
			{
				return _id;
			}
		}
		property BookSettings^ SourceBook
		{
			BookSettings^ get()
			{
				return _sourceBook;
			}
		}
		property BookSettings^ TargetBook
		{
			BookSettings^ get()
			{
				return _targetBook;
			}
		}
		property IntegrationType Type
		{
			IntegrationType get()
			{
				return _type;
			}
		}
		property String^ Name
		{
			String^ get()
			{
				return _name;
			}
		}

		property List<Attribute^>^ SimpleSourceAttributes
		{
			List<Attribute^>^ get()
			{
				/*List<Attribute^>^ list = gcnew List<Attribute ^>();
				for each(AttributePair^ attrPair in AttributePairs)
				{
					if (attrPair->SimpleSourceAttribute != nullptr && !list->Contains(attrPair->SimpleSourceAttribute))
					{
						list->Add(attrPair->SimpleSourceAttribute);
					}
				}
				return	list;*/
				if (_simpleSourceAttributes == nullptr || _simpleSourceAttributes->Count <= 0)
				{
					_simpleSourceAttributes = Attribute::GetAttributes(_odbc, SourceBook->Id);
				}
				return	_simpleSourceAttributes;
			}
		}

		property List<Attribute^>^ SimpleTargetAttributes
		{
			List<Attribute^>^ get()
			{
				if (_simpleTargetAttributes == nullptr || _simpleTargetAttributes->Count <= 0)
				{
					_simpleTargetAttributes = Attribute::GetAttributes(_odbc, TargetBook->Id);
				}
				return	_simpleTargetAttributes;
			}
		}
		property Attribute^ SourceEquivAttr
		{
			Attribute^ get()
			{
				if (_attrEquivs == nullptr || _attrEquivs->Count <= 0)
				{
					for each (KeyValuePair<Attribute^, Attribute^>^ pair in _attrEquivs)
					{
						return pair->Key;
					}
				}
				return nullptr;
			}
		}
		property Attribute^ TargetEquivAttr
		{
			Attribute^ get()
			{
				if (_attrEquivs == nullptr || _attrEquivs->Count <= 0)
				{
					for each (KeyValuePair<Attribute^, Attribute^>^ pair in _attrEquivs)
					{
						return pair->Value;
					}
				}
				return nullptr;
			}
		}
		property List<AttributePair^>^ AttributePairs
		{
			List<AttributePair^>^ get()
			{
				if (_attributePairs == nullptr || _attributePairs->Count <= 0)
				{
					_attributePairs = AttributePair::GetPairs(Id, _odbc);
				}
				
				return _attributePairs;
			}
		}
		/*property List<String^>^ AttributePairFullCodes
		{
		List<String^>^ get()
		{
		List<String^>^ list = gcnew List<String ^>();
		for each (KeyValuePair<Attribute^, Attribute^>^ pair in AttributePairs)
		{
		list->Add(pair->Key->FullCode);
		list->Add(pair->Value->FullCode);
		}
		return list;
		}
		}*/

	private:
		OdbcClass^ _odbc;

		int _id;
		BookSettings^ _sourceBook;
		BookSettings^ _targetBook;
		IntegrationType _type;
		int _intType;
		String^ _name;
		Attribute^ _sourceAttributeEquil;
		Attribute^ _targetAttributeEquil;
		
		List<Attribute^>^ _simpleSourceAttributes;
		List<Attribute^>^ _simpleTargetAttributes;

		List<AttributePair^>^ _attributePairs;
		Dictionary<Attribute^, Attribute^>^ _attributeSimplePairs;
		Dictionary<Attribute^, Attribute^>^ _attrEquivs;
		List<ComplexAttribute^>^ _complexAttrs;

		Dictionary<String^, String^>^ _fields;

	public:
		IntegrationSettings(int parametrsId, OdbcClass^ odbc)
		{
			_id = parametrsId;
			_odbc = odbc;
			Set(_id);
		}

		IntegrationSettings(OdbcClass^ odbc, String^ name, BookSettings^ sourceBook, BookSettings^ targetBook, int type, Dictionary<Attribute^, Attribute^>^ attrSimplePairs, Dictionary<Attribute^, Attribute^>^ attrEquivs, List<ComplexAttribute^>^ complexAttrs)
		{
			_odbc = odbc;
			_name = name;
			_sourceBook = sourceBook;
			_targetBook = targetBook;

			_attrEquivs = attrEquivs;
			_attributeSimplePairs = attrSimplePairs;
			_complexAttrs = complexAttrs;

			_intType = type;
			CreateIntgrSchema();
			CreateAttrPairs(_attributeSimplePairs, _attrEquivs, "NULL");
			CreateComplexAttrs(_complexAttrs, "NULL");
		}

		IntegrationSettings(OdbcClass^ odbc, String^ name, BookSettings^ sourceBook, BookSettings^ targetBook, int type, List<IntegrationGroupPair^>^ integrationPairs)
		{
			_odbc = odbc;
			_name = name;
			_sourceBook = sourceBook;
			_targetBook = targetBook;


			_intType = type;
			CreateIntgrSchema();
			for each (IntegrationGroupPair^ groupPair in integrationPairs)
			{
				groupPair->InsertToDb(_odbc, _id);
				CreateAttrPairs(groupPair->SimpleAttrs, groupPair->EquivAttrs, groupPair->Id + "");
				CreateComplexAttrs(groupPair->ComplexAttrs, groupPair->Id + "");
			}
			
		}

		

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~IntegrationSettings() 
		{

		}

	private:
		Void Set(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select ID_SOURCE_BOOK, ID_TARGET_BOOK, TYPE, CREATE_USER, CREATE_DATE, INT_NAME from " + _odbc->schema + "INTEGRATION_PARAMS where ID = " + id);
			SetSourceBook(OdbcClass::GetResInt(parametrs[0]));
			SetTargetBook(OdbcClass::GetResInt(parametrs[1]));
			int typ = OdbcClass::GetResInt(parametrs[2]);
			if (typ == 1)
			{
				_type = IntegrationType::TwoWay;
			}
			else
			{
				_type = IntegrationType::OneWay;
			}
			_name = parametrs[5]->ToString();

			String^ squery = "select APP.ID, " +
				"(select IAA1.ID from {0}INTEGRATION_ATTRIBUTES IAA1 where IAA1.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA2.NAME from {0}INTEGRATION_ATTRIBUTES IAA2 where IAA2.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA3.SCHEMA_NAME from {0}INTEGRATION_ATTRIBUTES IAA3 where IAA3.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA4.TABLE_NAME from {0}INTEGRATION_ATTRIBUTES IAA4 where IAA4.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA5.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IAA5 where IAA5.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA6.ID_INTGR_BOOK from {0}INTEGRATION_ATTRIBUTES IAA6 where IAA6.ID = APP.ID_SOURCE_ATTRIBUTE), " +
				"(select IAA7.DATA_TYPE from {0}INTEGRATION_ATTRIBUTES IAA7 where IAA7.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA8.MAX_LENGTH from {0}INTEGRATION_ATTRIBUTES IAA8 where IAA8.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA9.ID from {0}INTEGRATION_ATTRIBUTES IAA9 where IAA9.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA10.NAME from {0}INTEGRATION_ATTRIBUTES IAA10 where IAA10.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA11.SCHEMA_NAME from {0}INTEGRATION_ATTRIBUTES IAA11 where IAA11.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA12.TABLE_NAME from {0}INTEGRATION_ATTRIBUTES IAA12 where IAA12.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA13.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IAA13 where IAA13.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA14.ID_INTGR_BOOK from {0}INTEGRATION_ATTRIBUTES IAA14 where IAA14.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA15.DATA_TYPE from {0}INTEGRATION_ATTRIBUTES IAA15 where IAA15.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA16.MAX_LENGTH from {0}INTEGRATION_ATTRIBUTES IAA16 where IAA16.ID = APP.ID_TARGET_ATTRIBUTE) " +
				"from {0}ATTRIBUTE_PAIRS APP where APP.ID_PARAMETRS = {1} and APP.IS_EQUIV = 1";
			parametrs = _odbc->ExecuteQuery(String::Format(squery, _odbc->schema, _id));

			if (parametrs != nullptr && parametrs->Count > 0)
			{
				int attrId1 = OdbcClass::GetResInt(parametrs[1]);
				String^ attrName1 = OdbcClass::GetResString(parametrs[2]);
				String^ attrSchemaName1 = OdbcClass::GetResString(parametrs[3]);
				String^ attrTableName1 = OdbcClass::GetResString(parametrs[4]);
				String^ attrCode1 = OdbcClass::GetResString(parametrs[5]);
				int attrIntBookId1 = _odbc->GetResInt(parametrs[6]);
				String^ attrDataType1 = OdbcClass::GetResString(parametrs[7]);
				int attrMaxLength1 = _odbc->GetResInt(parametrs[8]);
				Attribute^ attr1 = gcnew Attribute(attrId1, attrName1, attrSchemaName1, attrTableName1, attrCode1, attrIntBookId1, attrDataType1, attrMaxLength1 + "", _odbc);

				int attrId2 = OdbcClass::GetResInt(parametrs[9]);
				String^ attrName2 = OdbcClass::GetResString(parametrs[10]);
				String^ attrSchemaName2 = OdbcClass::GetResString(parametrs[11]);
				String^ attrTableName2 = OdbcClass::GetResString(parametrs[12]);
				String^ attrCode2 = OdbcClass::GetResString(parametrs[13]);
				int attrIntBookId2 = _odbc->GetResInt(parametrs[14]);
				String^ attrDataType2 = OdbcClass::GetResString(parametrs[15]);
				int attrMaxLength2 = _odbc->GetResInt(parametrs[16]);
				Attribute^ attr2 = gcnew Attribute(attrId2, attrName2, attrSchemaName2, attrTableName2, attrCode2, attrIntBookId2, attrDataType2, attrMaxLength2 + "", _odbc);

				_attrEquivs = gcnew Dictionary<Attribute^, Attribute^>();
				_attrEquivs->Add(attr1, attr2);
			}
		}

		Void SetSourceBook(int id)
		{
			_sourceBook = gcnew BookSettings(id, _odbc);
		}

		Void SetTargetBook(int id)
		{
			_targetBook = gcnew BookSettings(id, _odbc);
		}

		void CreateIntgrSchema()
		{
			String^ columns = "ID,ID_SOURCE_BOOK,ID_TARGET_BOOK,TYPE,CREATE_USER,CREATE_DATE,BOOK_TYPE_ID,INT_NAME";
			_id = _odbc->GetLastFreeId(_odbc->schema + "INTEGRATION_PARAMS");
			int idS = _sourceBook->Id;
			int idT = _targetBook->Id;
			String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
			String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);
			String^ sqlName = OdbcClass::GetSqlString(_name);

			String^ squery = String::Format("insert into {0}INTEGRATION_PARAMS ({1}) values ({2},{3},{4},{5},{6},{7},{8},{9})",
				_odbc->schema, columns, _id, idS, idT, _intType, sqlUser, sqlDate, _sourceBook->BookId, sqlName);
			_odbc->ExecuteNonQuery(squery);
		}

		void CreateAttrPairs(Dictionary<Attribute^, Attribute^>^ attrSimplePairs, Dictionary<Attribute^, Attribute^>^ attrEquivs, String^ sqlIdGroup)
		{
			String^ columns = "ID,ID_SOURCE_ATTRIBUTE,ID_TARGET_ATTRIBUTE,ID_PARAMETRS,CREATE_USER,CREATE_DATE,IS_EQUIV,ID_GROUP";
			for each (KeyValuePair<Attribute^, Attribute^>^ pair in attrSimplePairs)
			{
				int idPair = _odbc->GetLastFreeId(_odbc->schema + "ATTRIBUTE_PAIRS");
				int idS = pair->Key->Id;
				int idT = pair->Value->Id;
				String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
				String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);
				int isEqiuv = 0;

				String^ squery = String::Format("insert into {0}ATTRIBUTE_PAIRS ({1}) values ({2},{3},{4},{5},{6},{7},{8},{9})",
					_odbc->schema, columns, idPair, idS, idT, _id, sqlUser, sqlDate, isEqiuv, sqlIdGroup);
				_odbc->ExecuteNonQuery(squery);
			}

			columns = "ID,ID_SOURCE_ATTRIBUTE,ID_TARGET_ATTRIBUTE,ID_PARAMETRS,CREATE_USER,CREATE_DATE,IS_EQUIV,ID_GROUP";
			for each (KeyValuePair<Attribute^, Attribute^>^ pair in attrEquivs)
			{
				int idPair = _odbc->GetLastFreeId(_odbc->schema + "ATTRIBUTE_PAIRS");
				int idS = pair->Key->Id;
				int idT = pair->Value->Id;
				String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
				String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);
				int isEqiuv = 1;

				String^ squery = String::Format("insert into {0}ATTRIBUTE_PAIRS ({1}) values ({2},{3},{4},{5},{6},{7},{8},{9})",
					_odbc->schema, columns, idPair, idS, idT, _id, sqlUser, sqlDate, isEqiuv, sqlIdGroup);
				_odbc->ExecuteNonQuery(squery);
			}
			
		}

		void CreateComplexAttrs(List<ComplexAttribute^>^ complexAttrs, String^ sGroupId)
		{
			for each (ComplexAttribute^ cAttr in complexAttrs)
			{
				cAttr->InsertToDb(_id, sGroupId);
			}
		}

	};
}