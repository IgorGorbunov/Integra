#pragma once

#include "Book.h"
#include "DbPosition.h"
#include "IntegrationSettings.h"
#include "Results2.h"

namespace Integra {

	using namespace System::Collections::Generic;

	/// <summary>
	/// Класс spravochnika Semantic
	/// </summary>
	public ref class DbBook : Book
	{

	private:
		Attribute^ _equivAttr;
		bool _isSource;

		List<Attribute^>^ _attributes;

	public:
		DbBook(BookSettings^ bookSettings, IntegrationSettings^ intSettings, bool isSource) : Book(bookSettings, intSettings)
		{
			_isSource = isSource;
			if (_isSource)
			{
				_attributes = intSettings->SourceAttributes;
				_equivAttr = _intSettings->SourceEquivAttr;
			} 
			else
			{
				_attributes = intSettings->TargetAttributes;
				_equivAttr = _intSettings->TargetEquivAttr;
			}
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DbBook() 
		{

		}

	public:
		virtual List<Position^>^ GetAllPositions() override
		{
			List<Position^>^ list = gcnew List<Position ^>();
			List<Object^>^ query = OdbcClass::Odbc->ExecuteQuery("select " + _equivAttr->Code + " from " + _equivAttr->FullTable + " order by " + _equivAttr->Code);
			for each (Object^ o in query)
			{
				String^ sId = o->ToString();
				int number;
				bool result = Int32::TryParse(sId, number);
				Position^ pos = gcnew DbPosition(sId, _equivAttr->Code, _attributes);
				list->Add(pos);
			}

			return list;
		}



		virtual List<Position^>^ GetAllPositions2(System::ComponentModel::BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs^ e) override
		{
			List<Position^>^ list = gcnew List<Position ^>();
			String^ strQuery = "select ";
			int nAttr = _attributes->Count;
			int iId;
			String^ codeId;
			for (int i = 0; i < nAttr; i++)
			{
				strQuery += String::Format("{0}.{1}, ", _attributes[i]->FullTable, _attributes[i]->Code);
				if (_attributes[i]->Code == _equivAttr->Code)
				{
					iId = i;
					codeId = _attributes[i]->Code;
				}
			}
			strQuery = strQuery->Substring(0, strQuery->Length - 2);
			strQuery += " from ";

			List<Object^>^ titleList;
			if (_isSource)
			{
				titleList = GetSourceTitle();
			}
			else
			{
				titleList = GetTargetTitle();
			}

			int n = titleList->Count;
			for (int i = 0; i < n; i++)
			{
				strQuery += String::Format("{0}, ", titleList[i]->ToString());
			}
			strQuery = strQuery->Substring(0, strQuery->Length - 2);
			strQuery += String::Format(" order by {0}.{1}", _equivAttr->FullTable, _equivAttr->Code);

			List<Object^>^ query = OdbcClass::Odbc->ExecuteQuery(strQuery);

			if ( worker->CancellationPending )
			{
				e->Cancel = true;
			}
			else
			{
				n = query->Count;
				for (int i = 0; i < n; i += nAttr)
				{
					Dictionary<Attribute^, String^>^ dic = gcnew Dictionary<Attribute ^, String ^>();
					for (int j = 0; j < nAttr; j++)
					{
						dic->Add(_attributes[j], query[i+j]->ToString());
					}
					String^ sId = query[i+iId]->ToString();
					Position^ pos = gcnew DbPosition(sId, codeId, _attributes, dic);
					list->Add(pos);
					worker->ReportProgress(i/nAttr, nullptr);

					if ( worker->CancellationPending )
					{
						e->Cancel = true;
						break;
					}
				}
			}
			return list;
		}

		virtual List<Position^>^ GetAllPositions22(int% nc) override
		{
			List<Position^>^ list = gcnew List<Position ^>();
			String^ strQuery = "select ";
			int nAttr = _attributes->Count;
			int iId;
			String^ codeId;
			for (int i = 0; i < nAttr; i++)
			{
				strQuery += String::Format("{0}.{1}, ", _attributes[i]->FullTable, _attributes[i]->Code);
				if (_attributes[i]->Code == _equivAttr->Code)
				{
					iId = i;
					codeId = _attributes[i]->Code;
				}
			}
			strQuery = strQuery->Substring(0, strQuery->Length - 2);
			strQuery += " from ";

			List<Object^>^ titleList;
			if (_isSource)
			{
				titleList = GetSourceTitle();
			}
			else
			{
				titleList = GetTargetTitle();
			}

			int n = titleList->Count;
			for (int i = 0; i < n; i++)
			{
				strQuery += String::Format("{0}, ", titleList[i]->ToString());
			}
			strQuery = strQuery->Substring(0, strQuery->Length - 2);
			strQuery += String::Format(" order by {0}.{1}", _equivAttr->FullTable, _equivAttr->Code);

			List<Object^>^ query = OdbcClass::Odbc->ExecuteQuery(strQuery);

				n = query->Count;
				for (int i = 0; i < n; i += nAttr)
				{
					Dictionary<Attribute^, String^>^ dic = gcnew Dictionary<Attribute ^, String ^>();
					for (int j = 0; j < nAttr; j++)
					{
						dic->Add(_attributes[j], query[i+j]->ToString());
					}
					String^ sId = query[i+iId]->ToString();
					Position^ pos = gcnew DbPosition(sId, codeId, _attributes, dic);
					list->Add(pos);
				}

				nc = n/nAttr;
			return list;
		}

	};
}