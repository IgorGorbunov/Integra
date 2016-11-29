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
	private: System::Windows::Forms::GroupBox^  groupBox2;
	protected: 
	private: System::Windows::Forms::Button^  bEditBook;
	private: System::Windows::Forms::Label^  label3;
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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->bEditBook = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->bEditBook);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->tbName);
			this->groupBox2->Location = System::Drawing::Point(12, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(349, 105);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Изменить справочник";
			// 
			// bEditBook
			// 
			this->bEditBook->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bEditBook->Enabled = false;
			this->bEditBook->Location = System::Drawing::Point(127, 58);
			this->bEditBook->Name = L"bEditBook";
			this->bEditBook->Size = System::Drawing::Size(103, 37);
			this->bEditBook->TabIndex = 2;
			this->bEditBook->Text = L"Изменить";
			this->bEditBook->UseVisualStyleBackColor = false;
			this->bEditBook->Click += gcnew System::EventHandler(this, &EditForm::bEditBook_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Наименование";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(27, 32);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(300, 20);
			this->tbName->TabIndex = 0;
			this->tbName->TextChanged += gcnew System::EventHandler(this, &EditForm::tbName_TextChanged);
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(274, 130);
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
			this->ClientSize = System::Drawing::Size(377, 165);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->groupBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"EditForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Изменить справочник";
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

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
			 String^ table = "";
			 if (_typeI == 0)
			 {
				 table = "" + _odbc->schema + "BOOKS";
			 }
			 if (_typeI == 1)
			 {
				 table = "" + _odbc->schema + "INTEGRATED_SYSTEMS";
			 }
			 _odbc->ExecuteNonQuery("update " + table + " set NAME = \'" + tbName->Text->Trim() + "\' where ID = " + _bookId);
			 this->Visible = false;
			 Close();
		 }
};
}
