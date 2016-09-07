#pragma once

#include "Logger.h"

namespace Integra {

	using namespace System;
	using namespace System::Data::Odbc;
	using namespace System::Windows::Forms;
 
	/// <summary>
	/// ����� ��� ������ � ODBC
	/// </summary>
	public ref class OdbcClass 
	{
		private:
			OdbcConnection^ _connection;
			Logger^ _logger;

		public:
			OdbcClass(String^ driver) 
			{
				_logger = gcnew Logger("sql", ".sss");
				_logger->WriteLine("----------------------------------------- NEW SESSION ----------------------------------------------");
				_logger->WriteLine("Driver - " + driver);
				_connection = gcnew OdbcConnection(driver);
			}

		protected:
			/// <summary>
			/// ���������� ��� ������������ �������.
			/// </summary>
			~OdbcClass() 
			{

			}


		public: Void ExecuteNonQuery(String^ queryString) 
				{
					OdbcCommand^ command = gcnew OdbcCommand(queryString);
					try 
					{
						command->Connection = _connection;
						_connection->Open();
						_logger->WriteLine("���������� �������!");
						_logger->WriteLine("queryString: " + queryString);
						command->ExecuteNonQuery();
						_logger->WriteLine("+--+--+--+--+--+--+--+--+\n������ ������ �������!");
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
						_logger->WriteError(errorMessages);
						MessageBox::Show(errorMessages, "������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
					finally 
					{
						_connection->Close();
						_logger->WriteLine("���������� �������!");
					}
				}	
	};
}