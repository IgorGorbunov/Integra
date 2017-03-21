#pragma once

#include "ODBCclass.h"
#include "Attribute.h"

namespace Integra {

	using namespace System;
	using namespace System::Threading;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Класс для р
	/// </summary>
	public ref class TestExeIntegration
	{
	private:
		OdbcClass^ _odbc;
		String^ _driver;

		array<System::String ^> ^ _args;
		List<Attribute^>^ _sourceAttrVals;

	public:
		TestExeIntegration(array<System::String ^> ^args) 
		{
			_args = args;
		}

		void StartService()
		{
			SetAttrs(_args);
			WriteToDB();
		}

	private:

		void WriteToDB()
		{
			if (_sourceAttrVals != nullptr && _sourceAttrVals->Count > 0)
			{
				_odbc = gcnew OdbcClass("Driver={Microsoft ODBC for Oracle};Server=OTL.KTPP.AVIASTAR.LINK-UL.RU;Uid=ulgu1;Pwd=1;");

				String^ sQuery = String::Format("insert into INTEGRA.BOOKS (ID, NAME, CREATE_USER) values (");
				array<String^>^ sVals = gcnew array<String^>(3);

				for each (Attribute^ attr in _sourceAttrVals)
				{
					String^ sVal = _odbc->GetSqlValue(attr->Table, attr->Code);
					if (attr->Name == "Атрибут1")
					{
						sVals[0] = sVal;
					}
					else if (attr->Name == "Атрибут2")
					{
						sVals[1] = sVal;
					}
					else if (attr->Name == "Атрибут 3")
					{
						sVals[2] = sVal;
					}
				}

				for (int i = 0; i < sVals->Length; i++)
				{
					sQuery += String::Format("{0},", sVals[i]);
				}
				sQuery = sQuery->Substring(0, sQuery->Length - 1);
				sQuery += ")";

				_odbc->ExecuteNonQuery(sQuery);
			}
		}

		void SetAttrs(array<System::String ^> ^args)
		{
			if (args != nullptr && args->Length > 0)
            {
				_sourceAttrVals = gcnew List<Attribute^>();
                int i = 0;
                while (i < args->Length)
                {
                    String^ s = args[i];
                    if (s == ",")
                    {
                        i++;
                        s = args[i];
                    }

                    if (s == "{")
                    {
                        i++;
                        s = args[i];
                    }

                    String^ name = "";
                    while (s != "[")
                    {
                        name += args[i] + " ";
                        i++;
                        s = args[i];
                    }

					i++;
					s = args[i];
					String^ attrType = "";
                    while (s != "]")
                    {
                        attrType += args[i] + " ";
                        i++;
                        s = args[i];
                    }

					i++;
					s = args[i];
                    while (s != "-")
                    {
                        attrType += args[i] + " ";
                        i++;
                        s = args[i];
                    }

                    i++;
                    s = args[i];
                    String^ value = "";
                    while (s != "}" && s != "},")
                    {
                        value += args[i] + " ";
                        i++;
                        s = args[i];
                    }

					Attribute^ attr = gcnew Attribute("", attrType->Trim(), value->Trim(), name->Trim());
					_sourceAttrVals->Add(attr);

                    i++;
                }
            }
		}



	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TestExeIntegration() 
		{

		}
	};
}