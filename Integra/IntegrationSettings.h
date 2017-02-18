#pragma once

#include "ODBCclass.h"
#include "Attribute.h"
#include "BookSettings.h"

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

		property List<Attribute^>^ SourceAttributes
		{
			List<Attribute^>^ get()
			{
				List<Attribute^>^ list = gcnew List<Attribute ^>();
				for each(KeyValuePair<Attribute^, Attribute^>^ pair in AttributePairs)
				{
					list->Add(pair->Key);
				}
				return	list;
			}
		}

		property List<Attribute^>^ TargetAttributes
		{
			List<Attribute^>^ get()
			{
				List<Attribute^>^ list = gcnew List<Attribute ^>();
				for each(KeyValuePair<Attribute^, Attribute^>^ pair in AttributePairs)
				{
					list->Add(pair->Value);
				}
				return	list;
			}
		}
		property Attribute^ SourceEquivAttr
		{
			Attribute^ get()
			{
				return _sourceAttributeEquil;
			}
		}
		property Attribute^ TargetEquivAttr
		{
			Attribute^ get()
			{
				return _targetAttributeEquil;
			}
		}
		property Dictionary<Attribute^, Attribute^>^ AttributePairs
		{
			Dictionary<Attribute^, Attribute^>^ get()
			{
				if (_attributePairs == nullptr || _attributePairs->Count == 0)
				{
					SetAttrPairs();
				}
				
				return _attributePairs;
			}
		}
		property List<String^>^ AttributePairFullCodes
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
		}

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
		
		Dictionary<Attribute^, Attribute^>^ _attributePairs;

		Dictionary<String^, String^>^ _fields;

	public:
		IntegrationSettings(int parametrsId, OdbcClass^ odbc)
		{
			_id = parametrsId;
			_odbc = odbc;
			Set(_id);
		}

		IntegrationSettings(OdbcClass^ odbc, String^ name, BookSettings^ sourceBook, BookSettings^ targetBook, int type, Dictionary<Attribute^, Attribute^>^ attrPairs)
		{
			_odbc = odbc;
			_name = name;
			_sourceBook = sourceBook;
			_targetBook = targetBook;
			_attributePairs = attrPairs;
			_intType = type;
			CreateIntgrSchema();
			CreateAttrPairs();
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
			SetSourceBook(Decimal::ToInt32((Decimal)parametrs[0]));
			SetTargetBook(Decimal::ToInt32((Decimal)parametrs[1]));
			Decimal^ typ = (Decimal)parametrs[2];
			if (typ->Equals((Decimal)1))
			{
				_type = IntegrationType::TwoWay;
			}
			else
			{
				_type = IntegrationType::OneWay;
			}
			_name = parametrs[5]->ToString();



			//if (!String::IsNullOrEmpty(parametrs[3]->ToString()))
			//{
			//	//_sourceAttributeEquil = gcnew Attribute(Decimal::ToInt32((Decimal)parametrs[3]), _odbc);
			//}
			//if (!String::IsNullOrEmpty(parametrs[4]->ToString()))
			//{
			//	//_targetAttributeEquil = gcnew Attribute(Decimal::ToInt32((Decimal)parametrs[4]), _odbc);
			//}

			///**/
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

			String^ squery = String::Format("insert into {0}INTEGRATION_PARAMS ({1}) values ({2},{3},{4},{5},{6},{7},{8}, {9})",
				_odbc->schema, columns, _id, idS, idT, _intType, sqlUser, sqlDate, _sourceBook->BookId, sqlName);
			_odbc->ExecuteNonQuery(squery);
		}

		void CreateAttrPairs()
		{
			String^ columns = "ID,ID_SOURCE_ATTRIBUTE,ID_TARGET_ATTRIBUTE,ID_PARAMETRS,CREATE_USER,CREATE_DATE";
			for each (KeyValuePair<Attribute^, Attribute^>^ pair in AttributePairs)
			{
				int idPair = _odbc->GetLastFreeId(_odbc->schema + "ATTRIBUTE_PAIRS");
				int idS = pair->Key->Id;
				int idT = pair->Value->Id;
				String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
				String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);

				String^ squery = String::Format("insert into {0}ATTRIBUTE_PAIRS ({1}) values ({2},{3},{4},{5},{6},{7})",
					_odbc->schema, columns, idPair, idS, idT, _id, sqlUser, sqlDate);
				_odbc->ExecuteNonQuery(squery);
			}
			
		}

		void SetAttrPairs()
		{
			_attributePairs = gcnew Dictionary<Attribute^, Attribute^>();
			List<Object^>^ parametrs  = _odbc->ExecuteQuery("select AP.ID_SOURCE_ATTRIBUTE, AP.ID_TARGET_ATTRIBUTE from " + _odbc->schema + "ATTRIBUTE_PAIRS AP where AP.ID_PARAMETRS = " + _id);
			for (int i = 0; i < parametrs->Count / 2; i++)
			{
				Attribute^ sourceAttr = gcnew Attribute(Decimal::ToInt32((Decimal)parametrs[i * 2]), _odbc);
				Attribute^ targetAttr = gcnew Attribute(Decimal::ToInt32((Decimal)parametrs[i * 2 + 1]), _odbc);
				_attributePairs->Add(sourceAttr, targetAttr);
			}
		}
	};
}