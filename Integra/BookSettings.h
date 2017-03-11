#pragma once

#include "ODBCclass.h"
#include "Attribute.h"
#include "DbFilter.h"
#include "DbLink.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class BookSettings 
	{
	public:
		property String^ Name
		{
			String^ get()
			{
				return _name;
			}
		}
		property String^ SystemName
		{
			String^ get()
			{
				return _systemName;
			}
		}
		property String^ BookName
		{
			String^ get()
			{
				return _bookName;
			}
		}
		property bool IsSemantic
		{
			bool get()
			{
				return _isSemantic;
			}
		}
		property String^ Login
		{
			String^ get()
			{
				return _login;
			}
		}
		property String^ Password
		{
			String^ get()
			{
				return _password;
			}
		}
		property bool HasGroup
		{
			bool get()
			{
				if (_groupId == -1)
				{
					return false;
				}
				return true;
			}
		}
		property int Id
		{
			int get()
			{
				return _id;
			}
		}
		property OdbcClass^ Odbc
		{
			OdbcClass^ get()
			{
				if (_workOdbc == nullptr)
				{
					if (String::IsNullOrEmpty(_driver))
					{
						_workOdbc = gcnew OdbcClass(_login, _password, _tnsDatabase);
					}
					else
					{
						_workOdbc = gcnew OdbcClass(_driver);
					}
				}
				return _workOdbc;
			}
		}
		property String^ AttrIdFullcode
		{
			String^ get()
			{
				if (_attrIdFullcode == nullptr)
				{
					SetAttrIdName();
				}
				return _attrIdFullcode;
			}

		}
		property String^ ExePath
		{
			String^ get()
			{
				return _exePath;
			}

		}


		property String^ AttrTitleFullcode
		{
			String^ get()
			{
				if (_attrTitleFullcode == nullptr)
				{
					SetAttrTitleName();
				}
				return _attrTitleFullcode;
			}

		}
		property Attribute^ AttrId
		{
			Attribute^ get()
			{
				if (_attrId == nullptr)
				{
					SetAttrId();
				}
				return _attrId;
			}
		}
		property Attribute^ AttrCaption
		{
			Attribute^ get()
			{
				if (_attrCaption == nullptr)
				{
					SetAttrCaption();
				}
				return _attrCaption;
			}
		}

		property Attribute^ AttrGroupId
		{
			Attribute^ get()
			{
				if (_attrGroupId == nullptr)
				{
					SetAttrGroup();
				}
				return _attrGroupId;
			}
		}
		property Attribute^ AttrGroupName
		{
			Attribute^ get()
			{
				if (_attrGroupName == nullptr)
				{
					SetAttrGroup();
				}
				return _attrGroupName;
			}
		}
		property Attribute^ AttrPosGroupId
		{
			Attribute^ get()
			{
				if (_attrPosGroupId == nullptr && _groupId != -1)
				{
					_attrPosGroupId = gcnew Attribute(_idAttrPosGroupId, _odbc);
				}
				return _attrPosGroupId;
			}
		}
		property String^ GroupFullTable
		{
			String^ get()
			{
				if (_groupId != -1 && String::IsNullOrEmpty(_groupFullTable))
				{
					SetAttrGroup();
				}
				return _groupFullTable;
			}
		}

		property Attribute^ RoughAttr
		{
			Attribute^ get()
			{
				if (_roughAttrId != -1 && _roughAttr == nullptr)
				{
					_roughAttr = gcnew Attribute(_roughAttrId, _odbc);
				}
				return _roughAttr;
			}
		}
		property array<String^, 1>^ RoughSymbols
		{
			array<String^, 1>^ get()
			{
				if (_roughAttrId != -1 && (_arrRoughSymbols == nullptr || _arrRoughSymbols->Length <= 0))
				{
					_roughSymbols += " ";
					_arrRoughSymbols = gcnew array<String^, 1>(_roughSymbols->Length);
					for (int i = 0; i < _roughSymbols->Length; i++)
					{
						String^ c = _roughSymbols->Substring(i, 1);
						_arrRoughSymbols[i] = c;
					}
				}
				return _arrRoughSymbols;
			}
		}

		property List<Attribute^>^ Attributes
		{
			List<Attribute^>^ get()
			{
				if (_attributes == nullptr || _attributes->Count < 0)
				{
					_posAndGroupAttributes = Attribute::GetAttributes(_odbc, Id);
					if (_groupId != -1)
					{
						_attributes = gcnew List<Attribute ^>();
						for each (Attribute^ attr in _posAndGroupAttributes)
						{
							if (attr->FullTable != GroupFullTable)
							{
								_attributes->Add(attr);
							}
						}
					}
					else
					{
						_attributes = _posAndGroupAttributes;
					}
				}
				return _attributes;
			}
		}
		property List<Object^>^ DbFilters
		{
			List<Object^>^ get()
			{
				if (!_dbFiltersIsSet)
				{
					_dbFilters = DbFilter::GetFilters(_id, _odbc);
					_dbFiltersIsSet = true;
				}
				return _dbFilters;
			}
		}
		property List<Object^>^ DbLinks
		{
			List<Object^>^ get()
			{
				if (!_dbLinksIsSet)
				{
					_dbLinks = DbLink::GetLinks(_id, _odbc);
					_dbLinksIsSet = true;
				}
				return _dbLinks;
			}
		}

		int BookId;

	private:
		OdbcClass^ _odbc;
		OdbcClass^ _workOdbc;
		int _id;

		String^ _systemName;
		String^ _bookName;
		String^ _name;
		String^ _exePath;

		String^ _login;
		String^ _password;

		String^ _tnsDatabase;
		String^ _host;
		String^ _port;
		String^ _serviceName;
		String^ _sid;
		String^ _driver;
		bool _isSemantic;
		int _groupId;

		int _attrIdId;
		String^ _attrIdFullcode;
		int _attrTitleId;
		String^ _attrTitleFullcode;

		List<Attribute^>^ _attributes;
		List<Attribute^>^ _posAndGroupAttributes;

		bool _dbFiltersIsSet;
		List<Object^>^ _dbFilters;
		bool _dbLinksIsSet;
		List<Object^>^ _dbLinks;

		Attribute^ _attrId;
		Attribute^ _attrCaption;
		Attribute^ _attrGroupId;
		Attribute^ _attrGroupName;

		int _idAttrPosGroupId;
		Attribute^ _attrPosGroupId;
		String^ _groupFullTable;

		int _roughAttrId;
		Attribute^ _roughAttr;
		String^ _roughSymbols;
		array<String^, 1>^ _arrRoughSymbols;


	public:
		BookSettings(int parametrsId, OdbcClass^ odbc)
		{
			_odbc = odbc;
			_id = parametrsId;
			Set(parametrsId);

			_dbFiltersIsSet = false;
			_dbLinksIsSet = false;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~BookSettings() 
		{

		}

	public:
		List<Attribute^>^ GetUseAttrs()
		{
			String^ squery = String::Format("select ID from {0}INTEGRATION_ATTRIBUTES where ID_INTGR_BOOK = {1}", _odbc->schema, _id);
			List<Object^>^ oList = _odbc->ExecuteQuery(squery);
			List<Attribute^>^ list = gcnew List<Attribute ^>();
			for (int i = 0; i < oList->Count; i++)
			{
				int id = OdbcClass::GetResInt(oList[i]);
				Attribute^ attr = gcnew Attribute(id, _odbc);
				list->Add(attr);
			}
			return list;
		}

		Dictionary<Attribute^, Attribute^>^ GetGroupAttrs()
		{
			String^ squery = String::Format("select GAAP.ID_TITLE, GAAP.ID_NAME from {0}INTEGRATION_BOOK IBB, {0}GROUP_ATTRIBUTE_PAIRS GAAP where IBB.GROUP_ID = GAAP.ID_GROUP_PARAMS and IBB.ID = {1}", _odbc->schema, _id);
			List<Object^>^ oList = _odbc->ExecuteQuery(squery);
			Dictionary<Attribute^, Attribute^>^ list = gcnew Dictionary<Attribute^, Attribute^>();
			for (int i = 0; i < oList->Count; i+=2)
			{
				int id1 = OdbcClass::GetResInt(oList[i]);
				int id2 = OdbcClass::GetResInt(oList[i+1]);
				Attribute^ attr1 = gcnew Attribute(id1, _odbc);
				Attribute^ attr2 = gcnew Attribute(id2, _odbc);
				list->Add(attr1, attr2);
			}
			return list;
		}

		Dictionary<Attribute^, Attribute^>^ GetPosGroupAttrs()
		{
			Dictionary<Attribute^, Attribute^>^ list;
			String^ squery = "select DBL.ID, (select IAA1.ID from {0}INTEGRATION_ATTRIBUTES IAA1 where IAA1.ID = DBL.ID_TITLE)," +
				"(select IAA2.NAME from {0}INTEGRATION_ATTRIBUTES IAA2 where IAA2.ID = DBL.ID_TITLE)," +
				"(select IAA3.SCHEMA_NAME from {0}INTEGRATION_ATTRIBUTES IAA3 where IAA3.ID = DBL.ID_TITLE)," +
				"(select IAA4.TABLE_NAME from {0}INTEGRATION_ATTRIBUTES IAA4 where IAA4.ID = DBL.ID_TITLE)," +
				"(select IAA5.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IAA5 where IAA5.ID = DBL.ID_TITLE)," +
				"(select IAA6.ID_INTGR_BOOK from {0}INTEGRATION_ATTRIBUTES IAA6 where IAA6.ID = DBL.ID_TITLE)," +
				"(select IAA7.DATA_TYPE from {0}INTEGRATION_ATTRIBUTES IAA7 where IAA7.ID = DBL.ID_TITLE)," +
				"(select IAA8.MAX_LENGTH from {0}INTEGRATION_ATTRIBUTES IAA8 where IAA8.ID = DBL.ID_TITLE)," +
				"(select IAA17.MAX_DOUBLE from {0}INTEGRATION_ATTRIBUTES IAA17 where IAA17.ID = DBL.ID_TITLE)," +
				"(select IAA9.ID from {0}INTEGRATION_ATTRIBUTES IAA9 where IAA9.ID = DBL.ID_VALUE)," +
				"(select IAA10.NAME from {0}INTEGRATION_ATTRIBUTES IAA10 where IAA10.ID = DBL.ID_VALUE)," +
				"(select IAA11.SCHEMA_NAME from {0}INTEGRATION_ATTRIBUTES IAA11 where IAA11.ID = DBL.ID_VALUE)," +
				"(select IAA12.TABLE_NAME from {0}INTEGRATION_ATTRIBUTES IAA12 where IAA12.ID = DBL.ID_VALUE)," +
				"(select IAA13.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IAA13 where IAA13.ID = DBL.ID_VALUE)," +
				"(select IAA14.ID_INTGR_BOOK from {0}INTEGRATION_ATTRIBUTES IAA14 where IAA14.ID = DBL.ID_VALUE)," +
				"(select IAA15.DATA_TYPE from {0}INTEGRATION_ATTRIBUTES IAA15 where IAA15.ID = DBL.ID_VALUE)," +
				"(select IAA16.MAX_LENGTH from {0}INTEGRATION_ATTRIBUTES IAA16 where IAA16.ID = DBL.ID_VALUE)," +
				"(select IAA18.MAX_DOUBLE from {0}INTEGRATION_ATTRIBUTES IAA18 where IAA18.ID = DBL.ID_VALUE)" +
				" from {0}POSITION_GROUP_ATTRIBUTE_PAIRS DBL where DBL.ID_INTEGRATION_BOOK = {1} order by DBL.ID";
			squery = String::Format(squery, _odbc->schema, Id);

			List<Object^>^ resList = _odbc->ExecuteQuery(squery);
			if (resList != nullptr && resList->Count > 0)
			{
				list = gcnew Dictionary<Attribute^, Attribute^>();
				for (int i = 0; i < resList->Count; i+=19)
				{
					int linkId = _odbc->GetResInt(resList[i+0]);
					int attrId1 = _odbc->GetResInt(resList[i+1]);
					String^ attrName1 = resList[i+2]->ToString();
					String^ attrSchemaName1 = resList[i+3]->ToString();
					String^ attrTableName1 = resList[i+4]->ToString();
					String^ attrCode1 = resList[i+5]->ToString();
					int attrIntBookId1 = _odbc->GetResInt(resList[i+6]);
					String^ attrDataType1 = resList[i+7]->ToString();
					int attrMaxLength1 = _odbc->GetResInt(resList[i+8]);
					int attrMaxDouble1 = _odbc->GetResInt(resList[i+9]);
					Attribute^ attr1 = gcnew Attribute(attrId1, attrName1, attrSchemaName1, attrTableName1, attrCode1, attrIntBookId1, attrDataType1, attrMaxLength1 + "", attrMaxDouble1, _odbc);

					int attrId2 = _odbc->GetResInt(resList[i+10]);
					String^ attrName2 = resList[i+11]->ToString();
					String^ attrSchemaName2 = resList[i+12]->ToString();
					String^ attrTableName2 = resList[i+13]->ToString();
					String^ attrCode2 = resList[i+14]->ToString();
					int attrIntBookId2 = _odbc->GetResInt(resList[i+15]);
					String^ attrDataType2 = resList[i+16]->ToString();
					int attrMaxLength2 = _odbc->GetResInt(resList[i+17]);
					int attrMaxDouble2 = _odbc->GetResInt(resList[i+18]);
					Attribute^ attr2 = gcnew Attribute(attrId2, attrName2, attrSchemaName2, attrTableName2, attrCode2, attrIntBookId2, attrDataType2, attrMaxLength2 + "", attrMaxDouble2, _odbc);

					list->Add(attr1, attr2);
				}
			}

			return list;
		}

	private:
		void Set(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select ID_SYSTEM, ID_BOOK, LOGIN, PASSWORD, TNS_DATABASE, HOST, PORT, SERVICE_NAME, SID, DRIVER, IS_SEMANTIC, GROUP_ID, ATTR_ID, ATTR_TITLE, NAME, ATTR_GROUP, ATTR_ROUGH, ROUGH_SYMBOLS, EXE_PATH from " + _odbc->schema + "INTEGRATION_BOOK where ID = " + id);
			SetSystem(OdbcClass::GetResInt(parametrs[0]));
			SetBook(OdbcClass::GetResInt(parametrs[1]));
			SetLogPass(parametrs[2]->ToString(), parametrs[3]->ToString());
			_tnsDatabase = parametrs[4]->ToString();
			_host = parametrs[5]->ToString();
			_port = parametrs[6]->ToString();
			_serviceName = parametrs[7]->ToString();
			_sid = parametrs[8]->ToString();
			_driver = parametrs[9]->ToString();
			int isSemantic = OdbcClass::GetResInt(parametrs[10]);
			if (isSemantic == 1)
			{
				_isSemantic = true;
			}
			else
			{
				_isSemantic = false;
			}

			_groupId = OdbcClass::GetResInt(parametrs[11]);
			_attrIdId = OdbcClass::GetResInt(parametrs[12]);
			_attrTitleId = OdbcClass::GetResInt(parametrs[13]);
			_name = parametrs[14]->ToString();
			_idAttrPosGroupId = OdbcClass::GetResInt(parametrs[15]);
			_roughAttrId = OdbcClass::GetResInt(parametrs[16]);
			_roughSymbols = OdbcClass::GetResString(parametrs[17]);
			_exePath = OdbcClass::GetResString(parametrs[18]);
		}

		void SetSystem(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select NAME from " + _odbc->schema + "INTEGRATED_SYSTEMS where ID = " + id);
			_systemName = parametrs[0]->ToString();
		}

		void SetBook(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select ID, NAME from " + _odbc->schema + "BOOKS where ID = " + id);
			BookId = OdbcClass::GetResInt(parametrs[0]);
			_bookName = parametrs[1]->ToString();

		}

		void SetAttrIdName()
		{
			String^ squery = String::Format("select IA.FULL_CODE, IA.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IA, {0}INTEGRATION_BOOK IB " +
				"where IB.ATTR_ID = IA.ID and IB.ID = {1}", _odbc->schema, _id);
			List<Object^>^ list = _odbc->ExecuteQuery(squery);
			_attrIdFullcode = String::Format("{0}.{1}", list[0], list[1]);
		}

		void SetAttrId()
		{
			_attrId = gcnew Attribute(_attrIdId, _odbc);
		}

		void SetAttrGroup()
		{
			String^ squery = String::Format("select GPP.ID_ATTR, GPP.NAME_ATTR, GPP.FULL_TABLE from {0}INTEGRATION_BOOK IBB, {0}GROUP_PARAMS GPP where IBB.GROUP_ID = GPP.ID and IBB.ID = {1}", _odbc->schema, _id);
			List<Object^>^ oList = _odbc->ExecuteQuery(squery);

			int id1 = OdbcClass::GetResInt(oList[0]);
			int id2 = OdbcClass::GetResInt(oList[1]);
			_groupFullTable = OdbcClass::GetResString(oList[2]);

			_attrGroupId = gcnew Attribute(id1, _odbc);
			_attrGroupName = gcnew Attribute(id2, _odbc);
		}

		void SetAttrCaption()
		{
			_attrCaption = gcnew Attribute(_attrTitleId, _odbc);
		}

		void SetAttrTitleName()
		{
			String^ squery = String::Format("select IA.FULL_CODE, IA.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IA, {0}INTEGRATION_BOOK IB " +
				"where IB.ATTR_TITLE = IA.ID and IB.ID = {1}", _odbc->schema, _id);
			List<Object^>^ list = _odbc->ExecuteQuery(squery);
			_attrTitleFullcode = String::Format("{0}.{1}", list[0], list[1]);
		}

		void SetLogPass(String^ login, String^ password)
		{
			_login = login;
			_password = password;
		}

	};
}