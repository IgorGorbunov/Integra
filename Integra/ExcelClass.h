#pragma once


namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;
	using namespace Microsoft::Office::Interop;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class ExcelClass 
	{

	public:
		ExcelClass()
		{
			_xlApp = gcnew Microsoft::Office::Interop::Excel::ApplicationClass();
		}


		void OpenDocument(String^ fileName, bool isVisible)
		{
			_xlWorkBook = _xlApp->Workbooks->Open(fileName, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
				nullptr, nullptr, nullptr, nullptr);
			_xlApp->Visible = isVisible;
			_xlWorkSheet = safe_cast<Microsoft::Office::Interop::Excel::Worksheet^>(_xlApp->ActiveSheet);
			//_xlWorkSheet = (Microsoft::Office::Interop::Excel::Worksheet^)_xlWorkBook->Worksheets.get_Item(1);
		}

		String^ GetCellStringValue(int iCol, int iRow)
		{
			Object^ o = GetCellValue((Microsoft::Office::Interop::Excel::Range^)_xlWorkSheet->Cells[iRow, iCol]);
			if(o == nullptr)
			{
				return "";
			}
			else
			{
				return o->ToString();
			}
		}

		void CloseDocument(bool save)
		{
			if (_xlApp->ActiveWorkbook != nullptr)
			{
				_xlWorkBook->Close(save, nullptr, nullptr);
			}
			_xlApp->Quit();
			GC::GetTotalMemory(true);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ExcelClass() 
		{
			releaseObject(_range);
			releaseObject(_xlWorkSheet);
			releaseObject(_xlWorkBook);
			releaseObject(_xlApp);
			GC::GetTotalMemory(true);
		}

	private:
		Microsoft::Office::Interop::Excel::ApplicationClass^ _xlApp;
		Microsoft::Office::Interop::Excel::Workbook^ _xlWorkBook;      
		Microsoft::Office::Interop::Excel::Worksheet^ _xlWorkSheet;
		Microsoft::Office::Interop::Excel::Range^ _range;


		Object^ GetCellValue(Microsoft::Office::Interop::Excel::Range^ range)
		{
			return range->Value2;
		}

		void releaseObject(Object^ obj)
		{
			if (obj == nullptr)
				return;

			try
			{
				System::Runtime::InteropServices::Marshal::ReleaseComObject(obj);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Exception Occured while releasing object " + ex);
			}
			finally
			{
				GC::Collect();
			}
		}
	};
}