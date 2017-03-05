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
	public ref class Role 
	{
	public:
		property String^ RoleName
		{
			String^ get()
			{
				return _roleName;
			}
		}
		property String^ RoleDescription
		{
			String^ get()
			{
				return _roleDescription;
			}
		}
		property int Id
		{
			int get()
			{
				return _id;
			}
		}

	private:

		int _id;
		String^ _roleName;
		String^ _roleDescription;


	public:
		Role(int id, String^  roleName, String^ roleDescription)
		{
			_id = id;
			_roleName = roleName;
			_roleDescription = roleDescription;
		}

		static List<Role^>^ GetAllRoles(OdbcClass^ odbc)
		{
			String^ sQuery =  String::Format("select RR.ID, RR.NAME, RR.DESCRIPTION from {0}ROLES RR order by RR.ID", odbc->schema);
			List<Object^>^ resList = odbc->ExecuteQuery(sQuery);

			List<Role^>^ roleList;
			if (resList != nullptr && resList->Count > 0)
			{
				roleList = gcnew List<Role ^>();
			}
			Dictionary<int, String^>^ list = gcnew Dictionary<int, String^>();
			for (int i = 0; i < resList->Count; i+=3)
			{
				int id = odbc->GetResInt(resList[i]);
				String^ name = resList[i+1]->ToString();
				String^ roleDesc = resList[i+2]->ToString();
				Role^ user = gcnew Role(id, name, roleDesc);
				roleList->Add(user);
			}

			return roleList;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Role() 
		{

		}


	};
}