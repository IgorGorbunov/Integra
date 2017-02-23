#pragma once

#include "ODBCclass.h"
#include "Attribute.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class DbLink 
	{
	public:
		property Attribute^ Attribute1
		{
			Attribute^ get()
			{
				return _firstAttribute;
			}
		}
		property Attribute^ Attribute2
		{
			Attribute^ get()
			{
				return _secondAttribute;
			}
		}


	private:
		OdbcClass^ _odbc;
		Attribute^ _firstAttribute;
		Attribute^ _secondAttribute;
		
		int _id;

	public:

		DbLink(Attribute^ firstAttribute, Attribute^ secondAttribute)
		{
			_firstAttribute = firstAttribute;
			_secondAttribute = secondAttribute;
		}

		DbLink(int id, OdbcClass^ odbc, Attribute^ firstAttribute, Attribute^ secondAttribute)
		{
			_odbc = odbc;
			_id = id;

			_firstAttribute = firstAttribute;
			_secondAttribute = secondAttribute;
		}

		void InsertToDb(OdbcClass^ odbc, int intgrBookId, int attr1Id, int attr2Id)
		{
			_odbc = odbc;
			_firstAttribute->Id = attr1Id;
			_secondAttribute->Id = attr2Id;

			String^ columns = "ID,ATTR_ID1,ATTR_ID2,ID_INTGR_BOOK,CREATE_USER,CREATE_DATE";
			String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
			String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);

			_id = _odbc->GetLastFreeId(_odbc->schema + "DB_LINKS");

			String^ sQuery = String::Format("insert into {0}DB_LINKS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7})",
				_odbc->schema, columns, _id, attr1Id, attr2Id, intgrBookId, sqlUser, sqlDate);
			_odbc->ExecuteNonQuery(sQuery);
		}

		static List<Object^>^ GetLinks(int integrationBookId, OdbcClass^ odbc)
		{
			List<Object^>^ list;
			String^ squery = "select DBL.ID," +
				"(select IAA1.ID from {0}INTEGRATION_ATTRIBUTES IAA1 where IAA1.ID = DBL.ATTR_ID1)," +
				"(select IAA2.NAME from {0}INTEGRATION_ATTRIBUTES IAA2 where IAA2.ID = DBL.ATTR_ID1)," +
				"(select IAA3.SCHEMA_NAME from {0}INTEGRATION_ATTRIBUTES IAA3 where IAA3.ID = DBL.ATTR_ID1)," +
				"(select IAA4.TABLE_NAME from {0}INTEGRATION_ATTRIBUTES IAA4 where IAA4.ID = DBL.ATTR_ID1)," +
				"(select IAA5.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IAA5 where IAA5.ID = DBL.ATTR_ID1)," +
				"(select IAA6.ID_INTGR_BOOK from {0}INTEGRATION_ATTRIBUTES IAA6 where IAA6.ID = DBL.ATTR_ID1)," +
				"(select IAA7.DATA_TYPE from {0}INTEGRATION_ATTRIBUTES IAA7 where IAA7.ID = DBL.ATTR_ID1)," +
				"(select IAA8.MAX_LENGTH from {0}INTEGRATION_ATTRIBUTES IAA8 where IAA8.ID = DBL.ATTR_ID1)," +
				"(select IAA9.ID from {0}INTEGRATION_ATTRIBUTES IAA9 where IAA9.ID = DBL.ATTR_ID2)," +
				"(select IAA10.NAME from {0}INTEGRATION_ATTRIBUTES IAA10 where IAA10.ID = DBL.ATTR_ID2)," +
				"(select IAA11.SCHEMA_NAME from {0}INTEGRATION_ATTRIBUTES IAA11 where IAA11.ID = DBL.ATTR_ID2)," +
				"(select IAA12.TABLE_NAME from {0}INTEGRATION_ATTRIBUTES IAA12 where IAA12.ID = DBL.ATTR_ID2)," +
				"(select IAA13.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IAA13 where IAA13.ID = DBL.ATTR_ID2)," +
				"(select IAA14.ID_INTGR_BOOK from {0}INTEGRATION_ATTRIBUTES IAA14 where IAA14.ID = DBL.ATTR_ID2)," +
				"(select IAA15.DATA_TYPE from {0}INTEGRATION_ATTRIBUTES IAA15 where IAA15.ID = DBL.ATTR_ID2)," +
				"(select IAA16.MAX_LENGTH from {0}INTEGRATION_ATTRIBUTES IAA16 where IAA16.ID = DBL.ATTR_ID2)" +
				" from {0}DB_LINKS DBL where DBL.ID_INTGR_BOOK = {1} order by DBL.ID";
			squery = String::Format(squery, odbc->schema, integrationBookId);

			List<Object^>^ resList = odbc->ExecuteQuery(squery);
			if (resList != nullptr && resList->Count > 0)
			{
				list = gcnew List<Object ^>();
				for (int i = 0; i < resList->Count; i+=17)
				{
					int linkId = odbc->GetResInt(resList[i+0]);
					int attrId1 = odbc->GetResInt(resList[i+1]);
					String^ attrName1 = resList[i+2]->ToString();
					String^ attrSchemaName1 = resList[i+3]->ToString();
					String^ attrTableName1 = resList[i+4]->ToString();
					String^ attrCode1 = resList[i+5]->ToString();
					int attrIntBookId1 = odbc->GetResInt(resList[i+6]);
					String^ attrDataType1 = resList[i+7]->ToString();
					int attrMaxLength1 = odbc->GetResInt(resList[i+8]);
					Attribute^ attr1 = gcnew Attribute(attrId1, attrName1, attrSchemaName1, attrTableName1, attrCode1, attrIntBookId1, attrDataType1, attrMaxLength1 + "", odbc);

					int attrId2 = odbc->GetResInt(resList[i+9]);
					String^ attrName2 = resList[i+10]->ToString();
					String^ attrSchemaName2 = resList[i+11]->ToString();
					String^ attrTableName2 = resList[i+12]->ToString();
					String^ attrCode2 = resList[i+13]->ToString();
					int attrIntBookId2 = odbc->GetResInt(resList[i+14]);
					String^ attrDataType2 = resList[i+15]->ToString();
					int attrMaxLength2 = odbc->GetResInt(resList[i+16]);
					Attribute^ attr2 = gcnew Attribute(attrId2, attrName2, attrSchemaName2, attrTableName2, attrCode2, attrIntBookId2, attrDataType2, attrMaxLength2 + "", odbc);

					DbLink^ link = gcnew DbLink(linkId, odbc, attr1, attr2);
					list->Add(link);
				}
			}

			return list;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DbLink() 
		{

		}


	};
}