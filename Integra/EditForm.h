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
	/// ������ ��� EditForm
	/// </summary>
	public ref class EditForm : public System::Windows::Forms::Form
	{
	private:
		Object^ _bookId;
		OdbcClass^ _odbc;
		// 0 - system, 1 - book
		int _typeI;
		// 0 - add, 1 - edit, 2 - delete
		int _actionType;

	public:
		EditForm(Object^ id, String^ name, int typeI, int actType, OdbcClass^ odbc)
		{
			InitializeComponent();

			_bookId = id;
			_odbc = odbc;
			// 0 - system, 1 - book
			_typeI = typeI;
			// 0 - add, 1 - edit, 2 - delete
			_actionType = actType;

			tbName->Text = name;
			Text = "��������";
			bEditBook->Text = "��������";
			String^ sItem;
			if	(typeI == 0)
			{
				sItem = " �������";
			}
			else
			{
				sItem = " ����������";
			}
			Text += sItem;

			if (_actionType == 2)
			{
				System::Windows::Forms::DialogResult result = 
					MessageBox::Show("�� ������������� ������ �������" + sItem + "?", "��������������", 
					MessageBoxButtons::YesNoCancel, MessageBoxIcon::Warning);

				if (result == System::Windows::Forms::DialogResult::Yes)
				{
					DeleteItem();
					Close();
				}
				else
				{
					Close();
				}
			}
		}

		EditForm(int type, OdbcClass^ odbc)
		{
			InitializeComponent();

			_odbc = odbc;
			// 0 - system, 1 - book
			_typeI = type;
			Text = "��������";
			if	(type == 0)
			{
				Text += " ����� �������";
			}
			else
			{
				Text += " ����� ����������";
			}
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

		void AddItem()
		{
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
			 int id = _odbc->GetLastFreeId(_odbc->schema + table);
			 String^ columns = "ID,NAME,CREATE_USER,CREATE_DATE";
			 String^ squery = String::Format("insert into {0}{1} ({2}) values ({3},{4},{5},{6})", _odbc->schema, table, 
				 columns, id, name, OdbcClass::GetSqlString(_odbc->Login), _odbc->GetSqlDate(DateTime::Now));
			 _odbc->ExecuteNonQuery(squery);
		}

		void EditItem()
		{
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
			 String^ user = OdbcClass::GetSqlString(_odbc->Login);
			 String^ date = _odbc->GetSqlDate(DateTime::Now);
			 int id = _odbc->GetResInt(_bookId);
			 
			 String^ squery = String::Format("update {0}{1} set NAME = {2}, UPDATE_USER = {3}, UPDATE_DATE = {4} where ID = {5}", _odbc->schema, table, 
				 name, user, date, id);
			 _odbc->ExecuteNonQuery(squery);
		}

		void DeleteItem()
		{
			 String^ table;
			 if	(_typeI == 0)
			 {
				 table = "INTEGRATED_SYSTEMS";
			 }
			 else
			 {
				 table = "BOOKS";
			 }
			 int id = _odbc->GetResInt(_bookId);
			 
			 String^ squery = String::Format("delete from {0}{1} where ID = {2}", _odbc->schema, table, id);
			 _odbc->ExecuteNonQuery(squery);
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
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
			this->bEditBook->Text = L"��������";
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
			this->bCancel->Text = L"������";
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
			 switch (_actionType)
			 {
			 case 0:
				 AddItem();
				 break;
			 case 1:
				 EditItem();
				 break;
			 default:
				 break;
			 }

			 Close();
		 }
};
}
