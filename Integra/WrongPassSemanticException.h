#pragma once


namespace Integra {

	using namespace System;

	/// <summary>
	/// 
	/// </summary>
	public ref class WrongPassSemanticException  : public Exception
	{
	public:
		String^ Login;
		String^ Pass;
		String^ SemErrorMessage;
		int SemErrorCode;

	private:
		static String^ _errorMessage = "Неверно задан логин и/или пароль для входа в систему!";

	public:

		WrongPassSemanticException(int semErrorCode, String^ semErrorMessage, String^ login, String^ pass) : Exception(_errorMessage)
		{
			SemErrorCode = semErrorCode;
			SemErrorMessage = semErrorMessage;
			Login = login;
			Pass = pass;
		}

		virtual String^ ToString() override
		{
			return Message + "\nLogin: " + Login + "\nPassword: " + Pass;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~WrongPassSemanticException() 
		{

		}

	
	};
}