#pragma once

#include "Logger.h"
#include "WrongPassSemanticException.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Globalization;
	using namespace System::Text;
	using namespace System::IO;
	using namespace SemanticCore;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Класс надстройка над API Semantic
	/// </summary>
	public ref class Semantic 
	{
	public:
		ISCCore^ Core;

	private:
		Logger^ Log;

		String^ _user;
		String^ _pass;
		
		SCLogon^ _logon;


	public:
		Semantic(String^ user, String^ pass) 
		{
			Log = gcnew Logger("sem", ".sss");
			Log->WriteLine("----------------------------------------- NEW SESSION ----------------------------------------------");
			Log->WriteLine("user -" + user + "\npass -" + pass);
			_user = user;
			_pass = pass;
			
			 if (Init())
			 {
				 //"Constructor", "111"
				 //"Administrator", "1990"
				 if (_logon->LogonAsParams(user, pass, ""))
				 {
					 //vkl core
					 ISCObjectList^ objs = Core->ObjectList();
				 }
				 else
				 {
					 WrongPassSemanticException^ ex = gcnew WrongPassSemanticException(_logon->GetLastErrorCode(), _logon->GetLastErrorMessage(), user, pass);
					 Log->WriteError(ex->ToString());
					 _logon->ClearLastError();
					 Clear();
					 throw ex;
				 }
			 }
		}

		List<String^>^ GetAllFolderBooks()
		{
			List<String^>^ list = gcnew List<String ^>();
			ISCGroupList^ groups = Core->GroupList();
			int nGroup = groups->CountGroups;
			for (int i = 0; i < nGroup; i++)
			{
				ISCReferGroup^ group = groups->GroupByIndex(i);
				list->Add(group->NameGroup);
			}
			return list;
		}

		Dictionary<String^, String^>^ GetAllBooks(String^ folder)
		{
			Dictionary<String^, String^>^ dictionary = gcnew Dictionary<String^, String^>();
			ISCGroupList^ groups = Core->GroupList();
			ISCReferGroup^ group = groups->GroupByName(folder);

			int nDicts = group->CountRootClass;
			for (int i = 0; i < nDicts; i++)
			{
					ISCRootClass^ dict = group->RootClassByIndex(i);
					dictionary->Add(dict->NameRootClass, dict->NameScreenRootClass);
			}
			return dictionary;
		}

		Dictionary<String^, String^>^ GetAllGroups(String^ bookCode)
		{
			Dictionary<String^, String^>^ list = gcnew Dictionary<String^, String^>();
			ISCGroupList^ groups = Core->GroupList();
			int nGroup = groups->CountGroups;
			for (int i = 0; i < nGroup; i++)
			{
				ISCReferGroup^ group = groups->GroupByIndex(i);
				int nDicts = group->CountRootClass;
				for (int j = 0; j < nDicts; j++)
				{
					ISCRootClass^ dict = group->RootClassByIndex(j);
					if (dict->NameRootClass == bookCode)
					{
						int nCls = dict->CountClasses;
						nCls = dict->CountClasses;
						for (int k = 0; k < nCls; k++)
						{
							ISCClass^ clas = dict->ClassByIndex(k);
							//bug in 0-class
							if (clas == nullptr)
							{
								clas = dict->ClassByIndex(k+1)->ParentClass();
							}
							list->Add(clas->NameClass, clas->NameScreenClass);
						}
						return list;
					}
				}
			}
			return list;
		}

		List<array<Object^>^>^ GetClassAttrs(List<String^>^ fullCode)
		{
			ISCGroupList^ groups = Core->GroupList();
			ISCReferGroup^ group = groups->GroupByIndex(Int32::Parse(fullCode[0]));
			ISCRootClass^ dict = group->RootClassByName(fullCode[1]);
			ISCClass^ clas = dict->ClassByName(fullCode[2]);			
			int i = 3;
			while(i < fullCode->Count)
			{
				clas = clas->ChildClass();
				i++;
			}

			List<array<Object^>^>^ attrs = gcnew List<array<Object^>^>();
			int n = clas->CountAttrClasses;
			for (int j = 0; j < n; j++)
			{
				ISCClassAttribute^ attr = clas->AttrClassByIndex(j);
				array<Object^>^ arr = gcnew array<Object ^>(5);
				arr[0] = false;
				arr[1] = attr->NameAttr;
				arr[2] = attr->NameScreen;
				arr[3] = GetTypeName(attr->DataType);
				arr[4] = attr->SizeAttr + "";
				attrs->Add(arr);
			}

			array<Object^>^ arr = gcnew array<Object ^>(5);
			arr[0] = false;
			arr[1] = "^GUID";
			arr[2] = "Глобальный идентификатор";
			arr[3] = "Строка";
			arr[4] = "22";
			attrs->Add(arr);
			return attrs;
		}

	public:
		Void WriteToLog(String^ message)
		{
			Log->WriteLine(message);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Semantic() 
		{
			Clear();
		}


	private:

		static String^ GetTypeName(SCAttrDataType dataType)
		{
			switch(dataType)
			{
			case SCAttrDataType::ADT_BOOL:
				return "Логический";
			case SCAttrDataType::ADT_COLOR:
				return "Цвет";
			case SCAttrDataType::ADT_DATETIME:
				return "Дата";
			case SCAttrDataType::ADT_DOUBLE:
				return "Число с плавающей точкой";
			case SCAttrDataType::ADT_FLEXTABLE:
				return "Произвольная таблица";
			case SCAttrDataType::ADT_IMAGE:
				return "Изображение";
			case SCAttrDataType::ADT_INTEGER:
				return "Целое число";
			case SCAttrDataType::ADT_INTLINK:
				return "Внутренняя ссылка на объект";
			case SCAttrDataType::ADT_STRING:
				return "Строка";
			case SCAttrDataType::ADT_TEMPLATE:
				return "Шаблон";
			case SCAttrDataType::ADT_TEXT:
				return "Текст";
			case SCAttrDataType::ADT_UNKNOWN:
				return "Неизвестный тип";

			}
			return "Неизвестный тип";
		}
		
		Void Clear()
		{
			_logon = nullptr;
			Core = nullptr;
		}

		bool Init()
		{
			try
			{
				Core = gcnew SCCore();
				if (Core->GetLastErrorCode() != 0)
				{
					String^ mess = Core->GetLastErrorMessage();
					Log->WriteError(mess);
					MessageBox::Show(mess);
					return false;
				}

				ISCSettings^ settings = Core->Settings();
				if (settings == nullptr)
				{
					String^ mess = Core->GetLastErrorMessage();
					Log->WriteError(mess);
					MessageBox::Show(mess);
					return false;
				}
				if (Core->GetLastErrorCode() != 0)
				{
					String^ mess = Core->GetLastErrorMessage();
					Log->WriteError(mess);
					MessageBox::Show(mess);
					return false;
				}

				_logon = settings->Logon();
				if (_logon == nullptr)
				{
					String^ mess = Core->GetLastErrorMessage();
					Log->WriteError(mess);
					MessageBox::Show(mess);
					return false;
				}
				if (_logon->GetLastErrorCode() != 0)
				{
					String^ mess = _logon->GetLastErrorMessage();
					Log->WriteError(mess);
					MessageBox::Show(mess);
					return false;
				}
				return true;
			}
			catch (Exception^ e)
			{
				String^ mess = "Ошибка запуска Semantic!";
				Log->WriteError(mess + "\n" + e->StackTrace);
				MessageBox::Show(mess);
				return false;
			}
		}



	};
}