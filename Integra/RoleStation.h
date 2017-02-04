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
			Master, Administrator, SystemProgrammer, SpecialistUGT, Operator, Guest
		};

	private:
		static OdbcClass^ _odbc;


			 static String^ _login;
		static String^ _description;
		static String^ _roleName;
		static int _roleId;

		static Role _role;
		static array<String^, 2>^ _roles;
		static int _nRoles = 6;
	


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

			int roleId;
			if	(list == nullptr || list->Count < 1 || list[0] == nullptr || list[0]->ToString() == "")
			{
				roleId = 6;
			}
			else
			{
				roleId = Int32::Parse(list[0]->ToString());
			}

			 
			for(int i = 0; i < _nRoles; i++)
			{
				int roleI = Int32::Parse(_roles[i, 0]);
				if (roleI == roleId)
				{
					_roleName = _roles[i, 1];
					_description = _roles[i, 2];
					_roleId = roleId;
					SetRoleStation(roleId);
					break;
				}
			}
		}

		static String^ GetRoleDoc()
		{
			String^ squery = String::Format("select DOC from {0}ROLES where ID = {1}", _odbc->schema, _roleId);
			List<Object^>^ results = _odbc->ExecuteQuery(squery);
			return results[0]->ToString();
		}

		static bool BookSettingsHidden()
		{
			if	(_role == Role::Master ||
				 _role == Role::Administrator ||
				 _role == Role::SystemProgrammer ||
				 _role == Role::Operator)
			{
				return false;
			}
			return true;
		}

		static bool AddEditSystemHidden()
		{
			if	(_role == Role::Master ||
				 _role == Role::Administrator ||
				 _role == Role::SystemProgrammer)
			{
				return false;
			}
			return true;
		}

		static bool AddEditBookHidden()
		{
			if	(_role == Role::Master ||
				 _role == Role::Administrator ||
				 _role == Role::SystemProgrammer)
			{
				return false;
			}
			return true;
		}

		static bool AddNewIntegrSchemaHidden()
		{
			if	(_role == Role::Master ||
				_role == Role::Administrator ||
				_role == Role::SpecialistUGT ||
				_role == Role::Operator)
			{
				return false;
			}
			return true;
		}

		static bool AddSystemBookHidden()
		{
			if	(_role == Role::Master ||
				 _role == Role::Administrator ||
				 _role == Role::SystemProgrammer)
			{
				return false;
			}
			return true;
		}

		static bool IntegrationHidden()
		{
			if	(_role == Role::Master ||
				 _role == Role::Administrator ||
				 _role == Role::SpecialistUGT ||
				 _role == Role::Operator)
			{
				return false;
			}
			return true;
		}

		static bool IzveHidden()
		{
			if	(_role == Role::Master ||
				 _role == Role::Administrator ||
				 _role == Role::SpecialistUGT)
			{
				return false;
			}
			return true;
		}

		static bool IzmeHidden()
		{
			if	(_role == Role::Master ||
				 _role == Role::Administrator ||
				 _role == Role::SystemProgrammer ||
				 _role == Role::SpecialistUGT)
			{
				return false;
			}
			return true;
		}

		static bool UsersHidden()
		{
			if	(_role == Role::Master ||
				 _role == Role::Administrator ||
				 _role == Role::SystemProgrammer)
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
				_role = Role::SystemProgrammer;
				break;
			case 4:
				_role = Role::SpecialistUGT;
				break;
			case 5:
				_role = Role::Operator;
				break;
			case 6:
				_role = Role::Guest;
				break;
			}
		}

	};
}