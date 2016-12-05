#pragma once

#include"ODBCclass.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class RoleStation abstract sealed
	{
	public:
		static enum class Role
		{
			Master, Administrator, Operator, Guest
		};

	private:
		static OdbcClass^ _odbc;


			 static String^ _login;
		static String^ _description;
		static String^ _roleName;

		static Role _role;
		static array<String^, 2>^ _roles;
		static int _nRoles = 4;
	


	public:
		static void SetOdbc(OdbcClass^ odbc)
		{
			_odbc = odbc;
		}


		static void SetRole(String^ userCode)
		{
			SetRoles();
			String^ sq = "select role_id from " + _odbc->schema + "role_users where user_bd_code = \'" + userCode->Trim()->ToUpper() + "\'";
			List<Object^>^ list = _odbc->ExecuteQuery(sq);
			int roleId = Int32::Parse(list[0]->ToString());
			for(int i = 0; i < _nRoles; i++)
			{
				int roleI = Int32::Parse(_roles[i, 0]);
				if (roleI == roleId)
				{
					_roleName = _roles[i, 1];
					_description = _roles[i, 2];
					SetRoleStation(roleId);
					break;
				}
			}
		}

		static bool BookSettingsHidden()
		{
			if	(_role == Role::Master ||
				 _role == Role::Administrator ||
				 _role == Role::Operator)
			{
				return false;
			}
			return true;
		}

		static bool AddEditSystemHidden()
		{
			if	(_role == Role::Master ||
				_role == Role::Administrator)
			{
				return false;
			}
			return true;
		}

		static bool AddEditBookHidden()
		{
			if	(_role == Role::Master ||
				_role == Role::Administrator)
			{
				return false;
			}
			return true;
		}

		static bool AddNewIntegrSchemaHidden()
		{
			if	(_role == Role::Master ||
				_role == Role::Administrator ||
				_role == Role::Operator)
			{
				return false;
			}
			return true;
		}

		static bool AddSystemBookHidden()
		{
			if	(_role == Role::Master ||
				_role == Role::Administrator)
			{
				return false;
			}
			return true;
		}

		
	private:
		static void SetRoles()
		{
			_roles = gcnew array<String^, 2>(_nRoles, 3);
			String^ sq = "select id, name, description from " + _odbc->schema + "roles order by id";
			List<Object^>^ list = _odbc->ExecuteQuery(sq);
			int iRow = 0;
			for(int i = 0; i < list->Count; i+=3)
			{
				_roles[iRow, 0] = list[i]->ToString();
				_roles[iRow, 1] = list[i+1]->ToString();
				_roles[iRow, 2] = list[i+2]->ToString();
				iRow++;
			}
		}

		static void SetRoleStation(int roleId)
		{
			switch(roleId)
			{
			case 1:
				_role = Role::Master;
				break;
			case 2:
				_role = Role::Administrator;
				break;
			case 3:
				_role = Role::Operator;
				break;
			case 4:
				_role = Role::Guest;
				break;
			}
		}

	};
}