#pragma once

#include "Role.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class User 
	{
	public:
		property String^ Code
		{
			String^ get()
			{
				return _login;
			}
		}
		property String^ RoleName
		{
			String^ get()
			{
				return _role->RoleName;
			}
		}
		property int RoleId
		{
			int get()
			{
				return _role->Id;
			}
		}

	private:
		OdbcClass^ _odbc;


		String^ _login;
		int _id;
		String^ _roleName;
		String^ _roleDescription;
		Role^ _role;

	public:
		User(int id, String^ code, int roleId, String^ roleName, String^ roleDescription, OdbcClass^ odbc)
		{
			_odbc = odbc;

			_login = code;
			_id = id;
			_role = gcnew Role(roleId, roleName, roleDescription);
		}

		static List<User^>^ GetAllUsers(OdbcClass^ odbc)
		{
			String^ sQuery =  String::Format("select RU.ID, RU.USER_BD_CODE, RR.ID, RR.NAME, RR.DESCRIPTION from {0}ROLE_USERS RU, {0}ROLES RR where RR.ID = RU.ROLE_ID", odbc->schema);
			List<Object^>^ resList = odbc->ExecuteQuery(sQuery);

			List<User^>^ userList;
			if (resList != nullptr && resList->Count > 0)
			{
				userList = gcnew List<User ^>();
			}
			Dictionary<int, String^>^ list = gcnew Dictionary<int, String^>();
			for (int i = 0; i < resList->Count; i+=5)
			{
				int id = odbc->GetResInt(resList[i]);
				String^ code = resList[i+1]->ToString();
				int roleId = odbc->GetResInt(resList[i+2]);
				String^ roleName = resList[i+3]->ToString();
				String^ roleDesc = resList[i+4]->ToString();
				User^ user = gcnew User(id, code, roleId, roleName, roleDesc, odbc);
				userList->Add(user);
			}

			return userList;
		}

		static void AddNewUser(String^ login, int roleId, OdbcClass^ odbc)
		{
			String^ columns = "ID, USER_BD_CODE, ROLE_ID, CREATE_USER, CREATE_DATE";
			String^ sqlUser = OdbcClass::GetSqlString(odbc->Login);
			String^ sqlDate = odbc->GetSqlDate(DateTime::Now);

			int id = odbc->GetLastFreeId(odbc->schema + "ROLE_USERS");
			String^ sLogin = OdbcClass::GetSqlString(login);

			String^ sQuery =  String::Format("insert into {0}ROLE_USERS ({1}) values ({2}, {3}, {4}, {5}, {6})", 
				odbc->schema, columns, id, sLogin,  roleId, sqlUser, sqlDate);
			odbc->ExecuteNonQuery(sQuery);

		}

		void SetNewRole(int iRole)
		{
			//todo add updateuser, updatedate
			String^ squery = String::Format("update {0}ROLE_USERS set ROLE_ID = {1} where ID = {2}", _odbc->schema, iRole, _id);
			_odbc->ExecuteNonQuery(squery);
		}




	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~User() 
		{

		}


	};
}