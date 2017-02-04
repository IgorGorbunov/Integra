#pragma once

#include "ODBCclass.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для EditForm
	/// </summary>
	public ref class EditForm : public System::Windows::Forms::Form
	{
	private:
		String^ _bookId;
		OdbcClass^ _odbc;
		int _typeI;

	public:
		EditForm(Object^ id, String^ name, int typeI, OdbcClass^ odbc)
		{
			_bookId = id->ToString();
			_odbc = odbc;
			// 0 - book, 1 - system
			_typeI = typeI;
			InitializeComponent();
			tbName->Text = name;
		}

		EditForm(int type, OdbcClass^ odbc)
		{
			_odbc = odbc;
			_typeI = type;
			if	(type == 0)
			{
				Text += " новую систему";
			}
			else
			{
				Text += " новый справочник";
			}
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EditForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Windows::Forms::Button^  bEditBook;

	private: System::Windows::Forms::TextBox^  tbName;
	private: System::Windows::Forms::Button^  bCancel;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bEditBook = (gcnew System::Windows::Forms::Button());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bEditBook
			// 
			this->bEditBook->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bEditBook->Enabled = false;
			this->bEditBook->Location = System::Drawing::Point(128, 61);
			this->bEditBook->Name = L"bEditBook";
			this->bEditBook->Size = System::Drawing::Size(103, 37);
			this->bEditBook->TabIndex = 2;
			this->bEditBook->Text = L"Добавить";
			this->bEditBook->UseVisualStyleBackColor = false;
			this->bEditBook->Click += gcnew System::EventHandler(this, &EditForm::bEditBook_Click);
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(28, 35);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(300, 20);
			this->tbName->TabIndex = 0;
			this->tbName->TextChanged += gcnew System::EventHandler(this, &EditForm::tbName_TextChanged);
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(253, 130);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 5;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &EditForm::bCancel_Click);
			// 
			// EditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(354, 164);
			this->Controls->Add(this->bEditBook);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->tbName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"EditForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавить";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Close();
			 }
private: System::Void tbName_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (String::IsNullOrEmpty(tbName->Text))
			 {
				 bEditBook->Enabled = false;
			 }
			 else
			 {
				 bEditBook->Enabled = true;
			 }
		 }
private: System::Void bEditBook_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 /*String^ table = "";
			 if (_typeI == 0)
			 {
				 table = "" + _odbc->schema + "BOOKS";
			 }
			 if (_typeI == 1)
			 {
				 table = "" + _odbc->schema + "INTEGRATED_SYSTEMS";
			 }
			 _odbc->ExecuteNonQuery("update " + table + " set NAME = \'" + tbName->Text->Trim() + "\' where ID = " + _bookId);
			 this->Visible = false;*/
			 String^ name = OdbcClass::GetSqlString(tbName->Text->Trim());
			 String^ table;
			 if	(_typeI == 0)
			 {
				 table = "INTEGRATED_SYSTEMS";
			 }
			 else
			 {
				 table = "BOOKS";
			 }
			 int id = _odbc->GetMinFreeId(_odbc->schema + table);
			 String^ columns = "ID,NAME,CREATE_USER,CREATE_DATE";
			 String^ squery = String::Format("insert into {0}{1} ({2}) values ({3},{4},{5},{6})", _odbc->schema, table, 
				 columns, id, name, OdbcClass::GetSqlString(_odbc->Login), _odbc->GetSqlDate(DateTime::Now));
			 _odbc->ExecuteNonQuery(squery);

			 Close();
		 }
};
}
