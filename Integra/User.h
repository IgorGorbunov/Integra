#pragma once


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
		String^ _login;
		String^ _pass;
	

	public:
		User(String^ login, String^ password)
		{
			_login = login;
			_pass = pass;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~User() 
		{

		}

	private:
		void SetRole()
		{

		}

	};
}