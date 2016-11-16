#pragma once

#include "Logger.h"

namespace Integra {

	using namespace System;
	using namespace System::Data::Odbc;
	using namespace System::Windows::Forms;
 
	/// <summary>
	/// Класс для работы с ODBC
	/// </summary>
	public ref class OdbcClass 
	{
	public:
		static OdbcClass^ Odbc;
		static String^ schema = "";
		static String^ LoginFromDriver;
		//static String^ schema = "ULGU1.";

		private:
			OdbcConnection^ _connection;
			Logger^ _logger;
			String^ _driver;

		public:
			OdbcClass(String^ driver) 
			{
				_driver = driver;
				_logger = gcnew Logger("sql", ".sss");
				_logger->WriteLine("----------------------------------------- NEW SESSION ----------------------------------------------");
				_logger->WriteLine("Driver - " + driver);
				SetLoginFromDriver();
				_connection = gcnew OdbcConnection(driver);
			}

			OdbcClass(String^ login, String^ pass, String^ database) 
			{
				_logger = gcnew Logger("sql", ".sss");
				_logger->WriteLine("----------------------------------------- NEW SESSION ----------------------------------------------");
				_driver = "Driver={Microsoft ODBC for Oracle};Server=" + database + ";Uid=" + login + ";Pwd=" + pass + ";";
				_logger->WriteLine("Driver - " + _driver);
				LoginFromDriver = login;
				_connection = gcnew OdbcConnection(_driver);
			}

		protected:
			/// <summary>
			/// Освободить все используемые ресурсы.
			/// </summary>
			~OdbcClass() 
			{
				//_logger->WriteLine("-------------          ---------------- END SESSION -------------------           ------------------");
			}


		public: 

			static int GetMinFreeIdStatic(String^ fullTableName)
			{
				return Odbc->GetMinFreeId(fullTableName);
			}

			static void AddColumnComment(String^ fullCode, String^ comment)
			{
				String^ sQuery = "COMMENT ON COLUMN " + fullCode + " is \'" + comment + "\'";
				ExecuteNonQueryStatic(sQuery);
			}

			static String^ GetSqlString(String^ s)
			{
				if (String::IsNullOrEmpty(s))
				{
					s = "NULL";
				}
				else
				{
					return "\'" + s + "\'";
				}
				return s;
			}

			static void ExecuteNonQueryStatic(String^ queryString)
			{
				Odbc->ExecuteNonQuery(queryString);
			}

			static List<Object^>^ ExecuteQueryStatic(String^ queryString)
			{
				return Odbc->ExecuteQuery(queryString);
			}

			List<Object^>^ GetTableInfo7(String^ schtab)
			{
				array<String^>^ arr = schtab->Split('.');
				return GetTableInfo7(arr[0], arr[1]);
			}

			List<Object^>^ GetTableInfo7(String^ schema, String^ tableName)
			{
				String^ sQuery = "select " + 
					"COL.COLUMN_NAME," + 
					"COM.COMMENTS," + 
					"col.data_type," + 
					"COL.DATA_LENGTH," + 
					"col.data_precision," + 
					"col.data_scale," + 
					"COL.NULLABLE " + 
					"from ALL_TAB_COLUMNS col " + 
					"left join user_col_comments com " + 
					"on (col.table_name = com.table_name " + 
					"AND COL.COLUMN_NAME = com.column_name) " + 
					"WHERE COL.TABLE_NAME = \'" + tableName + "\' and COL.owner = \'" + schema + "\' " + 
					"ORDER BY col.table_name, col.column_name";
				List<Object^>^ list = ExecuteQuery(sQuery);
				return list;
			}

			Void ExecuteNonQuery(String^ queryString) 
			{
				OdbcCommand^ command = gcnew OdbcCommand(queryString);
				try 
				{
					command->Connection = _connection;
					_connection->Open();
					_logger->WriteLine("Соединение открыто!");
					_logger->WriteLine("queryString: " + queryString);
					command->ExecuteNonQuery();
					_logger->WriteLine("+--+--+--+--+--+--+--+--+\nЗапрос прошел успешно!");
				}
				catch (OdbcException^ e)
				{
					String^ errorMessages = "";
					for (int i = 0; i < e->Errors->Count; i++)
					{
						errorMessages += "Index #" + i + "\n" +
							"Message: " + e->Errors[i]->Message + "\n" +
							"NativeError: " + e->Errors[i]->NativeError + "\n" +
							"Source: " + e->Errors[i]->Source + "\n" +
							"SQL: " + e->Errors[i]->SQLState + "\n";
					}
					_logger->WriteError(errorMessages + "\n" + e->StackTrace);
					MessageBox::Show(errorMessages, "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				finally 
				{
					_connection->Close();
					delete command;
					_logger->WriteLine("Соединение закрыто!");
				}
			}

			List<Object^>^ ExecuteQuery(String^ queryString) 
			{
				OdbcCommand^ command = gcnew OdbcCommand(queryString);
				OdbcDataReader^ reader;
				List<Object^>^ list;
				try 
				{
					command->Connection = _connection;
					_connection->Open();
					_logger->WriteLine("Соединение открыто!");
					_logger->WriteLine("queryString: " + queryString);

					list = gcnew List<Object^>();
					reader = command->ExecuteReader();
					while (reader->Read())
					{
						for	(int i = 0; i < reader->FieldCount; i++)
						{
							Object^ ob;
							if (reader->IsDBNull(i))
							{
								ob = "";
							}
							else
							{
								ob = reader[i];
							}
							list->Add(ob);
						}
						
					}

					String^ mess = "+--+--+--+--+--+--+--+--+\nЗапрос прошел успешно!\nПервые 15 результатов:";
					for (int i = 0; i < list->Count; i++)
					{
						if (list[i] == nullptr)
						{
							mess += "\n NULL";
						}
						else
						{
							mess += "\n" + list[i]->ToString();
						}
						
						if	(i == 14)
							break;
					}
					_logger->WriteLine(mess);
				}
				catch (OdbcException^ e)
				{
					String^ errorMessages = "";
					String^ mess = e->Errors[0]->Message;
					for (int i = 0; i < e->Errors->Count; i++)
					{
						errorMessages += "Index #" + i + "\n" +
							"Message: " + e->Errors[i]->Message + "\n" +
							"NativeError: " + e->Errors[i]->NativeError + "\n" +
							"Source: " + e->Errors[i]->Source + "\n" +
							"SQL: " + e->Errors[i]->SQLState + "\n";
					}
					_logger->WriteError(errorMessages + "\n" + e->StackTrace);
					MessageBox::Show(mess, "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
					throw gcnew TimeoutException();
				}
				finally 
				{
					if (reader != nullptr)
					{
						reader->Close();
					}
					_connection->Close();
					delete reader;
					delete command;
					_logger->WriteLine("Соединение закрыто!");
				}
				return list;
			}	

			int GetMinFreeId(String^ fullTableName)
			{
				List<Object^>^ query = ExecuteQuery("select ID from " + fullTableName + " order by ID");
				int i = 1;
				for each (Object^ o in query)
				{
					int p = Decimal::ToInt32((Decimal)o);
					if (p > i)
					{
						return i;
					}
					i++;
				}
				return i;
			}

			Void SaveLogs()
			{
				_logger->SaveLog();
			}

		private:
			
			void SetLoginFromDriver()
			{
				String^ login = "";
				for (int i = 0; i < _driver->Length; i++)
				{
					String^ s = _driver->Substring(i, 4);
					if (s->ToUpper() == "UID=")
					{
						int j = i+4;
						wchar_t c = _driver[j];
						while (c != ';')
						{
							login += Char::ToString(c);
							c = _driver[++j];
						}
						LoginFromDriver = login;
						return;
					}
				}
			}
	};
}