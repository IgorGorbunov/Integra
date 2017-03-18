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
	public ref class Notice 
	{
	public:
		property int Id
		{
			int get()
			{
				return _id;
			}
		}
		property String^ CreateDate
		{
			String^ get()
			{
				return _createDate->ToString("dd.MM.yyyy hh:mm:ss");
			}
		}
		property bool IsSoglas
		{
			bool get()
			{
				return _isSoglas;
			}
		}
		property String^ Type
		{
			String^ get()
			{
				return _reason;
			}
		}
		property String^ CreateUser
		{
			String^ get()
			{
				return _createUser;
			}
		}
		property String^ IntSchemaName
		{
			String^ get()
			{
				return _intSchemaName;
			}
		}
		property String^ BookType
		{
			String^ get()
			{
				return _bookType;
			}
		}
		property String^ System
		{
			String^ get()
			{
				return _system;
			}
		}
		property String^ SoglasDate
		{
			String^ get()
			{
				return _soglasDate;
			}
		}
		property String^ SoglasUser
		{
			String^ get()
			{
				return _soglasUser;
			}
		}

	private:
		OdbcClass^ _odbc;

		int _id;
		int _intgrationId;
		int _attrId;
		String^ _reason;
		bool _isSoglas;
	    int _soglas;
		String^ _posId;
		String^ _caption;
		int _integrationBookId;

		String^ _soglasUser;
		String^ _soglasDate;

		String^ _intSchemaName;
		String^ _bookType;
		String^ _system;

		String^ _createUser;
		DateTime^ _createDate;
		String^ _updateUser;
		DateTime^ _updateDate;

	public:

		static void Delete(OdbcClass^ odbc, int id)
		{
			String^ squery = String::Format("delete from {0}NOTICES IBB where IBB.ID = {1}", odbc->schema, id);
			odbc->ExecuteNonQuery(squery);
		}

		static void SoglasNotice(OdbcClass^ odbc, int id)
		{
			String^ sUser = OdbcClass::GetSqlString(odbc->Login);
			String^ sDate = odbc->GetSqlDate(DateTime::Now);
			String^ squery = String::Format("update {0}NOTICES set SOGLAS = 1, SOGLAS_USER = {1}, SOGLAS_DATE = {2}, UPDATE_USER = {1}, UPDATE_DATE = {2} where ID = {3}", 
				odbc->schema, sUser, sDate, id);
			odbc->ExecuteNonQuery(squery);
		}

		Notice(OdbcClass^ odbc, int integrationId, String^ reason, String^ posId, String^ caption, int integrationBookId)
		{
			_odbc = odbc;
			_intgrationId = integrationId;
			_reason = reason;
			_posId = posId;
			_caption = caption;
			_integrationBookId = integrationBookId;
		}

		Notice(OdbcClass^ odbc, int id, DateTime^ creationDate, int isSoglas, String^ reason, String^ createUser, String^ integrationName, String^ bookName, String^ systemName, String^ soglasUser, String^ soglasDate, String^ caption)
		{
			_odbc = odbc;
			_id = id;
			_createDate = creationDate;
			_soglas = isSoglas;
			if (_soglas == 0)
			{
				_isSoglas = false;
			}
			else if (_soglas == 1)
			{
				_isSoglas = true;
			}
			_reason = reason;
			_createUser = createUser;
			_intSchemaName = integrationName;
			_bookType = bookName;
			_system = systemName;
			_soglasUser = soglasUser;
			_soglasDate = soglasDate;
			_caption = caption;
		}

		void InsertToDb()
		{
			String^ columns = "ID,ID_INTGR,REASON,SOGLAS,CREATE_USER,CREATE_DATE,ID_POS,CAPTION,ID_INTGR_BOOK";
			String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
			String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);
			String^ sPos = OdbcClass::GetSqlString(_posId);
			String^ sCaption = OdbcClass::GetSqlString(_caption);

			int id = _odbc->GetLastFreeId(_odbc->schema + "NOTICES");

			String^ sReason = OdbcClass::GetSqlString(_reason);

			String^ sQuery = String::Format("insert into {0}NOTICES ({1}) values ({2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10})",
				_odbc->schema, columns, id, _intgrationId, sReason, _soglas, sqlUser, sqlDate, sPos, sCaption, _integrationBookId);
			_odbc->ExecuteNonQuery(sQuery);
		}

		static List<Notice^>^ GetAllNotices(OdbcClass^ odbc)
		{
			String^ squery = "select NN.ID, NN.CREATE_DATE, NN.SOGLAS, NN.REASON, NN.CREATE_USER, IPP.INT_NAME, BB.NAME, ISS.NAME, NN.SOGLAS_USER, NN.SOGLAS_DATE, NN.CAPTION " +
				"from {0}NOTICES NN, {0}INTEGRATION_RESULTS IRR, {0}INTEGRATION_PARAMS IPP, {0}INTEGRATION_BOOK IBB, {0}BOOKS BB, {0}INTEGRATED_SYSTEMS ISS " +
			    "where NN.ID_INTGR = IRR.ID and IPP.ID = IRR.ID_INTGR and IBB.ID = NN.ID_INTGR_BOOK and BB.ID = IBB.ID_BOOK and IBB.ID_SYSTEM = ISS.ID";
			squery = String::Format(squery, odbc->schema);

			List<Object^>^ resList = odbc->ExecuteQuery(squery);
			List<Notice^>^ notices;
			if (resList != nullptr && resList->Count > 0)
			{
				notices = gcnew List<Notice ^>();
			}

			for (int i = 0; i < resList->Count; i+=11)
			{
				int id = odbc->GetResInt(resList[i+0]);
				DateTime^ createDate = odbc->GetResDate(resList[i+1]);
				int soglas = odbc->GetResInt(resList[i+2]);
				String^ reason = odbc->GetResString(resList[i+3]);
				String^ createUser = odbc->GetResString(resList[i+4]);
				String^ integrationSchemaName = odbc->GetResString(resList[i+5]);
				String^ bookName = odbc->GetResString(resList[i+6]);
				String^ systemName = odbc->GetResString(resList[i+7]);
				String^ soglasUser = odbc->GetResString(resList[i+8]);
				String^ soglasDate = odbc->GetResString(resList[i+9]);
				String^ caption = odbc->GetResString(resList[i+10]);

				Notice^ notice = gcnew Notice(odbc, id, createDate, soglas, reason, createUser, integrationSchemaName, bookName, systemName, soglasUser, soglasDate, caption);
				notices->Add(notice);
			}
			return notices;
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Notice() 
		{

		}


	};
}