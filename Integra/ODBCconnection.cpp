namespace Integra {

	using namespace System;
	using namespace System::Data::Odbc;
 
	/// <summary>
	/// ����� ��� ������ � ODBC
	/// </summary>
	public ref class OdbcClass 
	{
		private:
			OdbcConnection^ _connection;

		public:
			OdbcClass(String^ driver) 
			{
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
						_connection->Open();
						command->ExecuteNonQuery();
					}
					finally 
					{
						_connection->Close();
					}
				}	
	};
}