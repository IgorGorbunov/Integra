#pragma once

#include "ODBCclass.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс для работы с настройками систем
	/// </summary>
	public ref class Settings
	{
	public:
		property array<String^, 2>^ Books
		{
			array<String^, 2>^ get()
			{
				SetBooks();
				return _books;
			}
		}
		property array<String^, 2>^ Systems
		{
			array<String^, 2>^ get()
			{
				SetSystems();
				return _systems;
			}
		}

		static String^ UserConfigs = "configs.ini";

	private:
		OdbcClass^ _odbc;

		array<String^, 2>^ _books;
		array<String^, 2>^ _systems;
		array<String^, 2>^ _systemBooks;

	public:
		Settings(OdbcClass^ odbc)
		{
			_odbc = odbc;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Settings() 
		{

		}

	public:
		bool AddBook(String^ name)
		{
			List<Object^>^ query = _odbc->ExecuteQuery("select ID from " + OdbcClass::schema + "BOOKS where NAME = \'" + name->Trim() + "\'");
			if (query->Count == 0)
			{
				int id = _odbc->GetMinFreeId(OdbcClass::schema + "BOOKS");
				_odbc->ExecuteNonQuery("insert into " + OdbcClass::schema + "BOOKS values (" + id + ", \'" + name + "\')");
				return true;
			}
			else
			{
				return false;
			}
		}

		bool AddSystem(String^ name)
		{
			List<Object^>^ query = _odbc->ExecuteQuery("select ID from " + OdbcClass::schema + "INTEGRATED_SYSTEMS where NAME = \'" + name->Trim() + "\'");
			if (query->Count == 0)
			{
				int id = _odbc->GetMinFreeId(OdbcClass::schema + "INTEGRATED_SYSTEMS");
				_odbc->ExecuteNonQuery("insert into " + OdbcClass::schema + "INTEGRATED_SYSTEMS values (" + id + ", \'" + name + "\')");
				return true;
			}
			else
			{
				return false;
			}
		}

		array<String^, 2>^ GetSystemBooks(String^ systemName)
		{
			_systemBooks = SetList("select " + OdbcClass::schema + "BOOKS.NAME, (SELECT  NAME FROM " + OdbcClass::schema + "INTEGRATION_ATTRIBUTES WHERE ID  = ATTR_ID), (SELECT  NAME FROM " + OdbcClass::schema + "INTEGRATION_ATTRIBUTES WHERE ID  = ATTR_TITLE) " +
				"from " + OdbcClass::schema + "BOOKS, " + OdbcClass::schema + "INTEGRATION_BOOK, " + OdbcClass::schema + "INTEGRATED_SYSTEMS " +
				"where " + OdbcClass::schema + "INTEGRATED_SYSTEMS.NAME = '" + systemName + "' and " +
				OdbcClass::schema + "BOOKS.ID = " + OdbcClass::schema + "INTEGRATION_BOOK.ID_BOOK and " +
				OdbcClass::schema + "INTEGRATED_SYSTEMS.ID = " + OdbcClass::schema + "INTEGRATION_BOOK.ID_SYSTEM", 3);
			return _systemBooks;
		}

	private:
		Void SetBooks()
		{
			_books = SetList("select ID, NAME from " + OdbcClass::schema + "BOOKS order by ID");
		}

		Void SetSystems()
		{
			_systems = SetList3("select ID, NAME, TYPE from " + OdbcClass::schema + "INTEGRATED_SYSTEMS order by ID");
		}

		
		

		array<String^, 2>^ SetList(String^ queryString, int nFields)
		{
			List<Object^>^ query = _odbc->ExecuteQuery(queryString);
			array<String^, 2>^ list = gcnew array<String ^, 2>(query->Count/nFields, nFields);
			int k = 0;
			for (int i = 0; i < query->Count; i += nFields)
			{
				for (int j = 0; j < nFields; j++)
				{
					list[k, j] = query[i + j]->ToString();
				}
				k++;
			}
			return list;
		}

		array<String^, 2>^ SetList(String^ queryString)
		{
			List<Object^>^ query = _odbc->ExecuteQuery(queryString);
			array<String^, 2>^ list = gcnew array<String ^, 2>(query->Count/2, 2);
			int k = 0;
			for (int i = 0; i < query->Count; i += 2)
			{
				list[k, 0] = query[i]->ToString();
				list[k, 1] = query[i + 1]->ToString();
				k++;
			}
			return list;
		}

		array<String^, 2>^ SetList3(String^ queryString)
		{
			List<Object^>^ query = _odbc->ExecuteQuery(queryString);
			array<String^, 2>^ list = gcnew array<String ^, 2>(query->Count/3, 3);
			int k = 0;
			for (int i = 0; i < query->Count; i += 3)
			{
				list[k, 0] = query[i]->ToString();
				list[k, 1] = query[i + 1]->ToString();
				list[k, 2] = query[i + 2]->ToString();
				k++;
			}
			return list;
		}
	};
}