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
			List<Object^>^ query = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "BOOKS where NAME = \'" + name->Trim() + "\'");
			if (query->Count == 0)
			{
				int id = _odbc->GetLastFreeId(_odbc->schema + "BOOKS");
				String^ squery = String::Format("insert into {0}BOOKS (ID, NAME, CREATE_USER, CREATE_DATE) values ({1}, '{2}', {3})", _odbc->schema,  id, name, _odbc->GetActionDataTo());
				_odbc->ExecuteNonQuery(squery);
				return true;
			}
			else
			{
				return false;
			}
		}

		bool AddSystem(String^ name)
		{
			List<Object^>^ query = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "INTEGRATED_SYSTEMS where NAME = \'" + name->Trim() + "\'");
			if (query->Count == 0)
			{
				int id = _odbc->GetLastFreeId(_odbc->schema + "INTEGRATED_SYSTEMS");
				String^ squery = String::Format("insert into {0}INTEGRATED_SYSTEMS (ID, NAME, CREATE_USER, CREATE_DATE) values ({1}, '{2}', {3})", _odbc->schema,  id, name, _odbc->GetActionDataTo());
				_odbc->ExecuteNonQuery(squery);
				return true;
			}
			else
			{
				return false;
			}
		}

		array<String^, 2>^ GetSystemBooks(String^ systemName)
		{
			array<String^, 2>^ systemBooks = SetList("select " + _odbc->schema + "BOOKS.NAME, (SELECT  NAME FROM " + _odbc->schema + "INTEGRATION_ATTRIBUTES WHERE ID  = ATTR_ID), (SELECT  NAME FROM " + _odbc->schema + "INTEGRATION_ATTRIBUTES WHERE ID  = ATTR_TITLE) " +
				"from " + _odbc->schema + "BOOKS, " + _odbc->schema + "INTEGRATION_BOOK, " + _odbc->schema + "INTEGRATED_SYSTEMS " +
				"where " + _odbc->schema + "INTEGRATED_SYSTEMS.NAME = '" + systemName + "' and " +
				_odbc->schema + "BOOKS.ID = " + _odbc->schema + "INTEGRATION_BOOK.ID_BOOK and " +
				_odbc->schema + "INTEGRATED_SYSTEMS.ID = " + _odbc->schema + "INTEGRATION_BOOK.ID_SYSTEM", 3);
			return systemBooks;
		}

		array<String^, 2>^ GetSystemBooks(int bookTypeId)
		{
			String^ squery = String::Format("select INTEGRATION_BOOK.ID, BOOKS.NAME, INTEGRATED_SYSTEMS.NAME " +
				"from {0}BOOKS, {0}INTEGRATION_BOOK, {0}INTEGRATED_SYSTEMS where BOOKS.ID = {1} and BOOKS.ID = INTEGRATION_BOOK.ID_BOOK and INTEGRATED_SYSTEMS.ID = INTEGRATION_BOOK.ID_SYSTEM", _odbc->schema, bookTypeId);
			array<String^, 2>^ systemBooks = SetList(squery, 3);
			return systemBooks;
		}

		array<String^, 2>^ GetSystemBooks()
		{
			String^ squery = String::Format("select IBB.ID, IBB.NAME, BB.NAME, ISS.NAME " +
				"from {0}BOOKS BB, {0}INTEGRATION_BOOK IBB, {0}INTEGRATED_SYSTEMS ISS where BB.ID = IBB.ID_BOOK and ISS.ID = IBB.ID_SYSTEM", _odbc->schema);
			_systemBooks = SetList(squery, 4);
			return _systemBooks;
		}


	private:
		Void SetBooks()
		{
			_books = SetList("select ID, NAME from " + _odbc->schema + "BOOKS order by ID");
		}

		Void SetSystems()
		{
			_systems = SetList3("select ID, NAME, TYPE from " + _odbc->schema + "INTEGRATED_SYSTEMS order by ID");
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