#pragma once

#include "ODBCclass.h"
#include "Attribute.h"
#include "BookSettings.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class IntegrationSettings 
	{
	public:
		enum class IntegrationType
		{
			OneWay, TwoWay
		};

		property int Id
		{
			int get()
			{
				return _id;
			}
		}
		property BookSettings^ SourceBook
		{
			BookSettings^ get()
			{
				return _sourceBook;
			}
		}
		property BookSettings^ TargetBook
		{
			BookSettings^ get()
			{
				return _targetBook;
			}
		}
		property IntegrationType Type
		{
			IntegrationType get()
			{
				return _type;
			}
		}

		property List<Attribute^>^ SourceAttributes
		{
			List<Attribute^>^ get()
			{
				List<Attribute^>^ list = gcnew List<Attribute ^>();
				for each(KeyValuePair<Attribute^, Attribute^>^ pair in AttributePairs)
				{
					list->Add(pair->Key);
				}
				return	list;
			}
		}

		property List<Attribute^>^ TargetAttributes
		{
			List<Attribute^>^ get()
			{
				List<Attribute^>^ list = gcnew List<Attribute ^>();
				for each(KeyValuePair<Attribute^, Attribute^>^ pair in AttributePairs)
				{
					list->Add(pair->Value);
				}
				return	list;
			}
		}
		property Attribute^ SourceEquivAttr
		{
			Attribute^ get()
			{
				return _sourceAttributeEquil;
			}
		}
		property Attribute^ TargetEquivAttr
		{
			Attribute^ get()
			{
				return _targetAttributeEquil;
			}
		}

		Dictionary<Attribute^, Attribute^>^ AttributePairs;

	private:
		OdbcClass^ _odbc;

		int _id;
		BookSettings^ _sourceBook;
		BookSettings^ _targetBook;
		IntegrationType _type;
		Attribute^ _sourceAttributeEquil;
		Attribute^ _targetAttributeEquil;
		


		Dictionary<String^, String^>^ _fields;

	public:
		IntegrationSettings(int parametrsId, OdbcClass^ odbc)
		{
			_id = parametrsId;
			_odbc = odbc;
			Set(_id);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~IntegrationSettings() 
		{

		}

	private:
		Void Set(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select ID_SOURCE_BOOK, ID_TARGET_BOOK, TYPE, ID_SOURCE_ATTR_EQ, ID_TARGET_ATTR_EQ from " + _odbc->schema + "INTEGRATION_PARAMS where ID = " + id);
			SetSourceBook(Decimal::ToInt32((Decimal)parametrs[0]));
			SetTargetBook(Decimal::ToInt32((Decimal)parametrs[1]));
			Decimal^ typ = (Decimal)parametrs[2];
			if (typ->Equals((Decimal)1))
			{
				_type = IntegrationType::TwoWay;
			}
			else
			{
				_type = IntegrationType::OneWay;
			}
			if (!String::IsNullOrEmpty(parametrs[3]->ToString()))
			{
				_sourceAttributeEquil = gcnew Attribute(Decimal::ToInt32((Decimal)parametrs[3]), _odbc);
			}
			if (!String::IsNullOrEmpty(parametrs[4]->ToString()))
			{
				_targetAttributeEquil = gcnew Attribute(Decimal::ToInt32((Decimal)parametrs[4]), _odbc);
			}

			AttributePairs = gcnew Dictionary<Attribute^, Attribute^>();
			parametrs = _odbc->ExecuteQuery("select ID_SOURCE_ATTRIBUTE, ID_TARGET_ATTRIBUTE from " + _odbc->schema + "ATTRIBUTE_PAIRS where ID_PARAMETRS = " + id);
			for (int i = 0; i < parametrs->Count / 2; i++)
			{
				Attribute^ sourceAttr = gcnew Attribute(Decimal::ToInt32((Decimal)parametrs[i * 2]), _odbc);
				Attribute^ targetAttr = gcnew Attribute(Decimal::ToInt32((Decimal)parametrs[i * 2 + 1]), _odbc);
				AttributePairs->Add(sourceAttr, targetAttr);
			}
		}

		Void SetSourceBook(int id)
		{
			_sourceBook = gcnew BookSettings(id, _odbc);
		}

		Void SetTargetBook(int id)
		{
			_targetBook = gcnew BookSettings(id, _odbc);
		}
	};
}