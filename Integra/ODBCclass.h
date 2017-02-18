#pragma once

#include "Logger.h"

namespace Integra {

	using namespace System;
	using namespace System::Data;
	using namespace System::Data::Odbc;
	using namespace System::Windows::Forms;
 
	/// <summary>
	/// Класс для работы с ODBC
	/// </summary>
	public ref class OdbcClass 
	{
	public:
		property String^ DataSource
		{
			String^ get()
			{
				return _dataSource;
			}
		}

		String^ Login;
  
		String^ schema;

		

		private:
			OdbcConnection^ _connection;
			Logger^ _logger;
			String^ _driver;
			String^ _dataSource;

		public:
			void Init()
			{
				schema = ""; 
				//schema = "INTEGRA.";
			}

			OdbcClass(String^ driver) 
			{
				Init();
				_driver = driver;
				_logger = gcnew Logger("sql", ".sss");
				_logger->WriteLine("----------------------------------------- NEW SESSION ----------------------------------------------");
				_logger->WriteLine("Driver - " + _driver);
				SetLoginFromDriver();
				Connect();
			}

			OdbcClass(String^ login, String^ pass, String^ database) 
			{
				Init();
				_logger = gcnew Logger("sql", ".sss");
				_logger->WriteLine("----------------------------------------- NEW SESSION ----------------------------------------------");
				_driver = "Driver={Microsoft ODBC for Oracle};Server=" + database + ";Uid=" + login + ";Pwd=" + pass + ";";
				_logger->WriteLine("Driver - " + _driver);
				Login = login;
				Connect();
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

			/*static int GetMinFreeIdStatic(String^ fullTableName)
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
			}*/

			List<Object^>^ GetTables(String^ schema)
			{
				if (String::IsNullOrEmpty(schema))
				{
					return GetAccessTables();
				}
				return GetOracleTables(schema);
			}

			List<Object^>^ GetOracleTables(String^ schema)
			{
				String^ squery = String::Format("select table_name from all_tables where owner = '{0}'", schema);
				return ExecuteQuery(squery);
			}

			List<Object^>^ GetSchemas()
			{
				String^ squery = "select distinct OWNER from SYS.DBA_OBJECTS order by OWNER";
				return ExecuteQuery(squery);
			}

			static String^ GetResString(Object^ o)
			{
				if (o == nullptr)
				{
					return "";
				}
				else
				{
					return o->ToString();
				}
			}

			static DateTime^ GetResDate(Object^ o)
			{
				DateTime^ date;
				if (o == nullptr || String::IsNullOrEmpty(o->ToString()))
				{
					return nullptr;
					//return DateTime::ParseExact("1111-01-01 00:00:00", "yyyy-MM-dd HH:mm:ss", System::Globalization::CultureInfo::InvariantCulture);
				}
				else
				{
					date = (DateTime^)o;
					return date;
				}
			}


			static String^ GetSqlString(String^ s)
			{
				if (String::IsNullOrEmpty(s))
				{
					s = "NULL";
				}
				else
				{
					return String::Format("'{0}'", s);
				}
				return s;
			}

			static int GetInt(Object^ o)
			{
				if (o == nullptr || String::IsNullOrEmpty(o->ToString()))
				{
					return -1;
				}
				int i;
				try
				{
					double is;
					bool isParse = double::TryParse(o->ToString(), is);
					if (isParse)
					{
						i = Decimal::ToInt32((Decimal)is);
					}
					else
					{
						i = Decimal::ToInt32((Decimal)o);
					}
				}
				catch (InvalidCastException^)
				{
					i = (int)o;
				}
				return i;
			}

			String^ GetSqlDate(DateTime^ dateTime)
			{
				if (_dataSource == "ACCESS")
				{
					return String::Format("CDate('{0}')", dateTime->ToString("yyyy-MM-dd HH:mm:ss"));
				}
				else
				{
					return String::Format("TO_DATE('{0}', 'YYYY-MM-DD HH24:MI:SS')", dateTime->ToString("yyyy-MM-dd HH:mm:ss"));
				}
			}

			void AddColumnComment(String^ fullCode, String^ comment)
			{
				String^ sQuery = "COMMENT ON COLUMN " + fullCode + " is \'" + comment + "\'";
				ExecuteNonQuery(sQuery);
			}

			String^ GetActionDataTo()
			{
				return String::Format("'{0}', CDate('{1}')", Login->ToUpper(), DateTime::Now.ToString());
			}

			List<Object^>^ GetTableInfo7(String^ schtab)
			{
				array<String^>^ arr = schtab->Split('.');
				return GetTableInfo7(arr[0], arr[1]);
			}

			List<Object^>^ GetTableInfo7(String^ schema, String^ tableName)
			{
				if (schema == "без схемы")
				{
					OdbcCommand^ command = gcnew OdbcCommand("SELECT TOP 1 * FROM " + tableName);
					OdbcDataReader^ reader;
					List<Object^>^ list = gcnew List<Object ^>();
					try 
					{
						command->Connection = _connection;
						_connection->Open();
						_logger->WriteLine("Соединение открыто!");
						_logger->WriteLine("Получение столбцов из таблицы: " + tableName);

						list = gcnew List<Object^>();
						reader = command->ExecuteReader();
						DataTable^ table = reader->GetSchemaTable();
						for (int i = 0; i < table->Rows->Count; i++)
						{
							DataRow^ row = table->Rows[i];
							list->Add(row[0]);
							list->Add("");//комменты
							list->Add(row[5]->ToString());
							list->Add(row[2]);
							list->Add("");//data_precision
							list->Add("");//data_scale
							list->Add(row[1]);
						}
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

			List<Object^>^ GetTableCols(String^ schtab)
			{
				array<String^>^ arr = schtab->Split('.');
				if (arr->Length > 1)
				{
					return GetTableCols(arr[0], arr[1]);
				}
				else
				{
					return GetTableCols("", arr[0]);
				}
				
			}

			List<Object^>^ GetTableCols(String^ schema, String^ tableName)
			{
				if (String::IsNullOrEmpty(schema))
				{
					OdbcCommand^ command = gcnew OdbcCommand("SELECT TOP 1 * FROM " + tableName);
					OdbcDataReader^ reader;
					List<Object^>^ list = gcnew List<Object ^>();
					try 
					{
						command->Connection = _connection;
						_connection->Open();
						_logger->WriteLine("Соединение открыто!");
						_logger->WriteLine("Получение столбцов из таблицы: " + tableName);

						list = gcnew List<Object^>();
						reader = command->ExecuteReader();
						DataTable^ table = reader->GetSchemaTable();
						for (int i = 0; i < table->Rows->Count; i++)
						{
							DataRow^ row = table->Rows[i];
							list->Add(row[0]);
						}
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

				String^ sQuery = "select " + 
					"COL.COLUMN_NAME " + 
					"from ALL_TAB_COLUMNS col " + 
					"WHERE COL.TABLE_NAME = \'" + tableName + "\' and COL.owner = \'" + schema + "\' " + 
					"ORDER BY col.column_name";
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
					int p = GetInt(o);

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

			void Connect()
			{
				_connection = gcnew OdbcConnection(_driver);
				try 
				{
					_connection->Open();
					_dataSource = _connection->DataSource;
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
					_logger->WriteLine("Соединение закрыто!");
				}
				
			}
			
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
						Login = login;
						return;
					}
				}
			}

			List<Object^>^ GetAccessTables()
			{
				return ExecuteQuery("SELECT NAME FROM MSysObjects WHERE (((Left([Name],1)<>'~') AND (Left([Name],4) <> 'MSys')) AND Type = 1)");
			}
	};
}