#pragma once

#include "ODBCclass.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class PosGroupParam 
	{
	public:
		property Attribute^ Attribute1
		{
			Attribute^ get()
			{
				return _attr1;
			}
		}
		property Attribute^ Attribute2
		{
			Attribute^ get()
			{
				return _attr2;
			}
		}


	private:
		OdbcClass^ _odbc;
		int _id;
		int _idIntegrationBook;

		int _attr1Id;
		Attribute^ _attr1;
		int _attr2Id;
		Attribute^ _attr2;


	public:

		static List<PosGroupParam^>^ GetGroupParams(OdbcClass^ odbc, int intgrBookId)
		{
			List<PosGroupParam^>^ list;
			String^ squery = "select PGAPP.ID,PGAPP.ID_TITLE,PGAPP.ID_VALUE from {0}POSITION_GROUP_ATTRIBUTE_PAIRS PGAPP where PGAPP.ID_INTEGRATION_BOOK = {1} order by PGAPP.ID";
			squery = String::Format(squery, odbc->schema, intgrBookId);

			List<Object^>^ resList = odbc->ExecuteQuery(squery);
			if (resList != nullptr && resList->Count > 0)
			{
				list = gcnew List<PosGroupParam ^>();
				for (int i = 0; i < resList->Count; i+=3)
				{
					int id = odbc->GetResInt(resList[i+0]);
					int attrId1 = odbc->GetResInt(resList[i+1]);
					int attrId2 = odbc->GetResInt(resList[i+2]);

					PosGroupParam^ grParam = gcnew PosGroupParam(id, attrId1, attrId2, intgrBookId);
					list->Add(grParam);
				}
			}

			return list;
		}

		static bool ListContains(Attribute^ attr, List<PosGroupParam^>^ list)
		{
			for each (PosGroupParam^ posGroupParam in list)
			{
				if (posGroupParam->Contains(attr))
				{
					return true;
				}
			}
			return false;
		}



		PosGroupParam(Attribute^ attr1, Attribute^ attr2)
		{
			_attr1 = attr1;
			_attr2 = attr2;
			_attr1Id = _attr1->Id;
			_attr2Id = _attr2->Id;
		}

		PosGroupParam(int id, int attr1Id, int attr2Id, int intgrBookId)
		{
			_id = id;
			_attr1Id = attr1Id;
			_attr2Id = attr2Id;
			_idIntegrationBook = intgrBookId;
		}

		void InsertToDb(OdbcClass^ odbc, int intgrBookId, int attr1Id, int attr2Id)
		{
			_odbc = odbc;
			_attr1->Id = attr1Id;
			_attr2->Id = attr2Id;

			String^ columns = "ID,ID_TITLE,ID_VALUE,ID_INTEGRATION_BOOK,CREATE_USER,CREATE_DATE";
			String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
			String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);

			_id = _odbc->GetLastFreeId(_odbc->schema + "POSITION_GROUP_ATTRIBUTE_PAIRS");

			String^ sQuery = String::Format("insert into {0}POSITION_GROUP_ATTRIBUTE_PAIRS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7})",
				_odbc->schema, columns, _id, attr1Id, attr2Id, intgrBookId, sqlUser, sqlDate);
			_odbc->ExecuteNonQuery(sQuery);
		}

		bool Contains(Attribute^ attr)
		{
			if (attr->Id == _attr1Id || attr->Id == _attr2Id ||
				attr == _attr1 || attr == _attr2)
			{
				return true;
			}
			return false;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PosGroupParam() 
		{

		}

	private:

	};
}