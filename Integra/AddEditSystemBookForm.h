#pragma once

#include "Settings.h"
#include "ODBCclass.h"
#include "AddDbAttrsForm.h"
#include "AddSemAttrForm.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddEditSystemBook
	/// </summary>
	public ref class AddEditSystemBookForm : public System::Windows::Forms::Form
	{
	private:
		OdbcClass^ _odbc;

	public:
		AddEditSystemBookForm(Settings^ settings, OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
			_settings = settings;
			_bookList = settings->Books;
			_systemList = settings->Systems;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddEditSystemBookForm()
		{
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::ComboBox^  cbBook;
	private: System::Windows::Forms::Button^  bAddAttrs;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  tbDriver;
	private: System::Windows::Forms::ComboBox^  cbConnType;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbDb;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tbPass;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tbLogin;

	private: System::Windows::Forms::ComboBox^  cbSystem;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  bOk;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbBook = (gcnew System::Windows::Forms::ComboBox());
			this->bAddAttrs = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tbDriver = (gcnew System::Windows::Forms::TextBox());
			this->cbConnType = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbDb = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbPass = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbLogin = (gcnew System::Windows::Forms::TextBox());
			this->cbSystem = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 13);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Справочник";
			// 
			// cbBook
			// 
			this->cbBook->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->cbBook->FormattingEnabled = true;
			this->cbBook->Location = System::Drawing::Point(23, 34);
			this->cbBook->Name = L"cbBook";
			this->cbBook->Size = System::Drawing::Size(216, 21);
			this->cbBook->TabIndex = 16;
			// 
			// bAddAttrs
			// 
			this->bAddAttrs->Location = System::Drawing::Point(36, 336);
			this->bAddAttrs->Name = L"bAddAttrs";
			this->bAddAttrs->Size = System::Drawing::Size(177, 23);
			this->bAddAttrs->TabIndex = 5;
			this->bAddAttrs->Text = L"Задать реквизиты";
			this->bAddAttrs->UseVisualStyleBackColor = true;
			this->bAddAttrs->Click += gcnew System::EventHandler(this, &AddEditSystemBookForm::bAddAttrs_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tbDriver);
			this->groupBox1->Controls->Add(this->cbConnType);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->tbDb);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->tbPass);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->tbLogin);
			this->groupBox1->Location = System::Drawing::Point(23, 128);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(216, 202);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Соединение";
			// 
			// tbDriver
			// 
			this->tbDriver->Location = System::Drawing::Point(13, 56);
			this->tbDriver->Multiline = true;
			this->tbDriver->Name = L"tbDriver";
			this->tbDriver->Size = System::Drawing::Size(177, 129);
			this->tbDriver->TabIndex = 10;
			this->tbDriver->Text = L"Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\\\Test.accdb;Uid=Admin;Pw" 
				L"d=;";
			this->tbDriver->Visible = false;
			// 
			// cbConnType
			// 
			this->cbConnType->FormattingEnabled = true;
			this->cbConnType->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L" Логин, пароль, база данных", L"Драйвер"});
			this->cbConnType->Location = System::Drawing::Point(13, 30);
			this->cbConnType->Name = L"cbConnType";
			this->cbConnType->Size = System::Drawing::Size(177, 21);
			this->cbConnType->TabIndex = 8;
			this->cbConnType->Text = L" Логин, пароль, база данных";
			this->cbConnType->SelectedIndexChanged += gcnew System::EventHandler(this, &AddEditSystemBookForm::cbConnType_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 149);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"База данных";
			// 
			// tbDb
			// 
			this->tbDb->Location = System::Drawing::Point(13, 165);
			this->tbDb->Name = L"tbDb";
			this->tbDb->Size = System::Drawing::Size(177, 20);
			this->tbDb->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 106);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Пароль";
			// 
			// tbPass
			// 
			this->tbPass->Location = System::Drawing::Point(13, 122);
			this->tbPass->Name = L"tbPass";
			this->tbPass->Size = System::Drawing::Size(177, 20);
			this->tbPass->TabIndex = 4;
			this->tbPass->UseSystemPasswordChar = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 64);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Логин";
			// 
			// tbLogin
			// 
			this->tbLogin->Location = System::Drawing::Point(13, 80);
			this->tbLogin->Name = L"tbLogin";
			this->tbLogin->Size = System::Drawing::Size(177, 20);
			this->tbLogin->TabIndex = 0;
			// 
			// cbSystem
			// 
			this->cbSystem->FormattingEnabled = true;
			this->cbSystem->Location = System::Drawing::Point(23, 85);
			this->cbSystem->Name = L"cbSystem";
			this->cbSystem->Size = System::Drawing::Size(216, 21);
			this->cbSystem->TabIndex = 3;
			this->cbSystem->SelectedIndexChanged += gcnew System::EventHandler(this, &AddEditSystemBookForm::cbSystem_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Система";
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(83, 381);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 17;
			this->bOk->Text = L"ОК";
			this->bOk->UseVisualStyleBackColor = true;
			this->bOk->Click += gcnew System::EventHandler(this, &AddEditSystemBookForm::bOk_Click);
			// 
			// bCancel
			// 
			this->bCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->bCancel->Location = System::Drawing::Point(164, 381);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 18;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &AddEditSystemBookForm::bCancel_Click);
			// 
			// AddEditSystemBookForm
			// 
			this->AcceptButton = this->bOk;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->CancelButton = this->bCancel;
			this->ClientSize = System::Drawing::Size(255, 416);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->bAddAttrs);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->cbBook);
			this->Controls->Add(this->cbSystem);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddEditSystemBookForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление/изменение справочника СУБД";
			this->Load += gcnew System::EventHandler(this, &AddEditSystemBookForm::AddEditSystemBookForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:
			Settings^ _settings;
			int _systemId;
			array<String^, 2>^ _bookList;
			array<String^, 2>^ _systemList;
			int _systemTypeId;

			List<array<String^>^>^ _dbAttrs;
			Attribute^ _idCol;
			Attribute^ _titleCol;
			int _intgrId;

			Void SetComboBox(ComboBox^ comboBox, array<String^, 2>^ list)
			{
				for (int i = 0; i < list->GetLength(0); i++)
				{
					comboBox->Items->Add(list[i,1]);
				}
			}

			int GetListId3(String^ name, array<String^, 2>^ list, int% typeId)
			{
				for (int i = 0; i < list->GetLength(0); i++)
				{
					if (name == list[i,1])
					{
						if (String::IsNullOrEmpty(list[i,2]))
						{
							typeId = 0;
						} 
						else
						{
							typeId = Int32::Parse(list[i,2]);
						}

						return Int32::Parse(list[i,0]);
					}
				}
				return 0;
			}

			Void WriteIntegrBook()
			{
				String^ query = "insert into " + _odbc->schema + "INTEGRATION_BOOK values (";
				_intgrId = _odbc->GetMinFreeId("" + _odbc->schema + "INTEGRATION_BOOK");
				List<Object^>^ idBook = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "BOOKS where NAME = \'" + cbBook->Text + "\'");
				List<Object^>^ idSystem = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "INTEGRATED_SYSTEMS where NAME = \'" + cbSystem->Text + "\'");
				query += _intgrId + ", " + Decimal::ToInt32((Decimal)idSystem[0]) + ", " + Decimal::ToInt32((Decimal)idBook[0]) + ", ";
				if (_systemTypeId == 1)
				{
					query += "\'" + tbLogin->Text + "\', \'" + tbPass->Text + "\', NULL, NULL, NULL, NULL, NULL, NULL, " + _systemTypeId + ", NULL, NULL)";
				} 
				else
				{
					if (cbConnType->SelectedIndex == 1)
					{
						query += "NULL, NULL, NULL, NULL, NULL, NULL, NULL, \'" + tbDriver->Text + "\', " + _systemTypeId + ", NULL, NULL)";
					}
					else
					{
						query += "\'" + tbLogin->Text + "\', \'" + tbPass->Text + "\', \'" + tbDb->Text + 
							"\', NULL, NULL, NULL, NULL, NULL, " + _systemTypeId + ", NULL, NULL)";
					}
				}
				_odbc->ExecuteNonQuery(query);
			}

			int WriteIdTitleAttr(Attribute^ col, int intgrId)
			{
				List<Object^>^ query = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "integration_attributes where full_code = \'" + col->FullCode + "\' and attr_name = \'" + col->Code + "\' and ID_INTGR_BOOK = " + intgrId);
				if (query != nullptr && query->Count > 0)
				{
					return Decimal::ToInt32((Decimal)query[0]);
				}
				else
				{
					int id = _odbc->GetMinFreeId("" + _odbc->schema + "integration_attributes");
					String^ squery = String::Format("insert into " + _odbc->schema + "integration_attributes values ({0}, \'{1}\', \'{2}\', NULL, \'{3}\', \'{4}\', {5})", 
						id, col->FullCode, col->Name, col->Table, col->Code, intgrId);
					_odbc->ExecuteNonQuery(squery);
					return id;
				}
			}


			void WriteDbAttrs(Attribute^ idCol, Attribute^ titleCol, List<array<String^>^>^ dbAttrs, int intgrId)
			{
				for (int i = 0; i < dbAttrs->Count; i++)
				{
					int id = _odbc->GetMinFreeId("" + _odbc->schema + "integration_attributes");
					String^ squery = String::Format("insert into " + _odbc->schema + "integration_attributes values ({0}, \'{1}\', \'{2}\', \'{3}\', \'{4}\', \'{5}\', {6})", 
						id, dbAttrs[i][0], dbAttrs[i][1], dbAttrs[i][2], dbAttrs[i][3], dbAttrs[i][4], intgrId);
					_odbc->ExecuteNonQuery(squery);
				}

				int id = WriteIdTitleAttr(idCol, intgrId);
				String^ squery = "update INTEGRATION_BOOK set ATTR_ID = " + id + " where ID = " + intgrId;
				_odbc->ExecuteNonQuery(squery);

				int titleAttrId = WriteIdTitleAttr(titleCol, intgrId);
				squery = "update INTEGRATION_BOOK set ATTR_TITLE = " + titleAttrId + " where ID = " + intgrId;
				_odbc->ExecuteNonQuery(squery);
			}

			Void WriteToDb()
			{
				WriteIntegrBook();
				WriteDbAttrs(_idCol, _titleCol, _dbAttrs, _intgrId);
			}

	private: System::Void cbSystem_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 _systemId = GetListId3(cbSystem->Text, _systemList, _systemTypeId);
				 if (_systemTypeId == 1)
				 {
					 cbConnType->SelectedIndex = 0;
					 cbConnType_SelectedIndexChanged(sender, e);
					 tbDb->Text = "";
					 tbDb->Enabled = false;
					 cbConnType->Enabled = false;
				 }
				 else
				 {
					 tbDb->Enabled = true;
					 cbConnType->Enabled = true;
				 }
			 }
private: System::Void AddEditSystemBookForm_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetComboBox(cbBook, _bookList);
			 SetComboBox(cbSystem, _systemList);
		 }
private: System::Void cbConnType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (cbConnType->SelectedIndex == 0)
			 {
				 tbDriver->Visible = false;
				 tbLogin->Visible = true;
				 tbPass->Visible = true;
				 tbDb->Enabled = true;
				 tbDb->Visible = true;
			 }
			 else
			 {
				 tbDriver->Visible = true;
				 tbLogin->Visible = false;
				 tbPass->Visible = false;
				 tbDb->Visible = false;
			 }
		 }
private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (String::IsNullOrEmpty(cbBook->Text))
			 {
				 MessageBox::Show("Не задан справочник!");
				 return;
			 }
			 else if (String::IsNullOrEmpty(cbSystem->Text))
			 {
				 MessageBox::Show("Не задана система!");
				 return;
			 }
			 else if (_dbAttrs == nullptr || _dbAttrs->Count == 0)
			 {
				 MessageBox::Show("Не заданы атрибуты системного справочника!");
				 return;
			 }
			 else if (_idCol == nullptr)
			 {
				 MessageBox::Show("Не задан атрибут-идентификатор!");
				 return;
			 }
			 else if (_titleCol == nullptr)
			 {
				 MessageBox::Show("Не задан основной атрибут!");
				 return;
			 }
			 else if (cbConnType->SelectedIndex == 1)
			 {
				 if (String::IsNullOrEmpty(tbDriver->Text))
				 {
					 MessageBox::Show("Не задан драйвер для системы!");
					 return;
				 }
			 }
			 else
			 {
				 if (String::IsNullOrEmpty(tbLogin->Text))
				 {
					 MessageBox::Show("Не задан логин для соединения с системой!");
					 return;
				 }
				 else if (String::IsNullOrEmpty(tbPass->Text))
				 {
					 MessageBox::Show("Не задан пароль для соединения с системой!");
					 return;
				 }
				 if (_systemTypeId != 1)
				 {
					 if (String::IsNullOrEmpty(tbDb->Text))
					 {
						 MessageBox::Show("Не задана база данных для соединения с системой!");
						 return;
					 }
				 }
			 }
			 WriteToDb();
			 Close();
		 }
private: System::Void bAddAttrs_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (_systemTypeId == 1)
			 {
				 if (String::IsNullOrEmpty(tbLogin->Text))
				 {
					 MessageBox::Show("Не задан логин для соединения с системой!");
					 return;
				 }
				 else if (String::IsNullOrEmpty(tbPass->Text))
				 {
					 MessageBox::Show("Не задан пароль для соединения с системой!");
					 return;
				 }
				 AddSemAttrForm^ addAttrForm = gcnew AddSemAttrForm(tbLogin->Text->Trim(), tbPass->Text->Trim());
				 addAttrForm->ShowDialog();
				 _idCol = addAttrForm->IdCol;
				 _titleCol = addAttrForm->TitleCol;
				 _dbAttrs = addAttrForm->Attributes;
			 }
			 else
			 {
				 AddDbAttrsForm^ addAttrForm;
				 if (cbConnType->SelectedIndex == 1)
				 {
					 if (String::IsNullOrEmpty(tbDriver->Text))
					 {
						 MessageBox::Show("Не задан драйвер для системы!");
						 return;
					 }
					 addAttrForm = gcnew AddDbAttrsForm(tbDriver->Text->Trim());
				 }
				 else
				 {
					 if (String::IsNullOrEmpty(tbLogin->Text))
					 {
						 MessageBox::Show("Не задан логин для соединения с системой!");
						 return;
					 }
					 else if (String::IsNullOrEmpty(tbPass->Text))
					 {
						 MessageBox::Show("Не задан пароль для соединения с системой!");
						 return;
					 }
					 if (_systemTypeId != 1)
					 {
						 if (String::IsNullOrEmpty(tbDb->Text))
						 {
							 MessageBox::Show("Не задана база данных для соединения с системой!");
							 return;
						 }
					 }
					 addAttrForm = gcnew AddDbAttrsForm(tbLogin->Text->Trim(), tbPass->Text->Trim(), tbDb->Text->Trim());
				 }
				 if (!addAttrForm->WrongPass)
				 {
					 addAttrForm->ShowDialog();
					 _idCol = addAttrForm->IdCol;
					 _titleCol = addAttrForm->TitleCol;
					 _dbAttrs = addAttrForm->Attributes;
				 }
				 
			 }
			 
		 }
};
}
