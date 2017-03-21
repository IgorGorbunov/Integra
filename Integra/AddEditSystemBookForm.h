#pragma once

#include "Settings.h"
#include "ODBCclass.h"
#include "AddDbAttrsForm.h"
#include "AddSemAttrForm.h"
#include "UserBookAccessForm.h"

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
		bool isDllExeBook;

	public:
		AddEditSystemBookForm(Settings^ settings, OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
			_settings = settings;
			_bookList = settings->Books;
			_systemList = settings->Systems;

			//release
			//tbDriver->Text = "Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=D:\\_Test.accdb;Uid=Admin;Pwd=;";
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
	private: System::Windows::Forms::Button^  bAddEditUsers;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  tbName;
	private: System::Windows::Forms::Button^  bAddExeFile;
	private: System::Windows::Forms::TextBox^  tbExePath;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Panel^  pExeFile;

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
			this->pExeFile = (gcnew System::Windows::Forms::Panel());
			this->bAddExeFile = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbExePath = (gcnew System::Windows::Forms::TextBox());
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
			this->bAddEditUsers = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->pExeFile->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 13);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Тип справочника:";
			// 
			// cbBook
			// 
			this->cbBook->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->cbBook->FormattingEnabled = true;
			this->cbBook->Location = System::Drawing::Point(12, 78);
			this->cbBook->Name = L"cbBook";
			this->cbBook->Size = System::Drawing::Size(216, 21);
			this->cbBook->TabIndex = 16;
			// 
			// bAddAttrs
			// 
			this->bAddAttrs->Location = System::Drawing::Point(25, 380);
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
			this->groupBox1->Controls->Add(this->pExeFile);
			this->groupBox1->Controls->Add(this->cbConnType);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->tbDb);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->tbPass);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->tbLogin);
			this->groupBox1->Location = System::Drawing::Point(12, 172);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(216, 202);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Соединение";
			// 
			// tbDriver
			// 
			this->tbDriver->Location = System::Drawing::Point(13, 59);
			this->tbDriver->Multiline = true;
			this->tbDriver->Name = L"tbDriver";
			this->tbDriver->Size = System::Drawing::Size(177, 134);
			this->tbDriver->TabIndex = 10;
			this->tbDriver->Visible = false;
			// 
			// pExeFile
			// 
			this->pExeFile->Controls->Add(this->bAddExeFile);
			this->pExeFile->Controls->Add(this->label7);
			this->pExeFile->Controls->Add(this->tbExePath);
			this->pExeFile->Location = System::Drawing::Point(13, 62);
			this->pExeFile->Name = L"pExeFile";
			this->pExeFile->Size = System::Drawing::Size(177, 131);
			this->pExeFile->TabIndex = 14;
			this->pExeFile->Visible = false;
			// 
			// bAddExeFile
			// 
			this->bAddExeFile->Location = System::Drawing::Point(48, 57);
			this->bAddExeFile->Name = L"bAddExeFile";
			this->bAddExeFile->Size = System::Drawing::Size(75, 23);
			this->bAddExeFile->TabIndex = 13;
			this->bAddExeFile->Text = L"Обзор";
			this->bAddExeFile->UseVisualStyleBackColor = true;
			this->bAddExeFile->Click += gcnew System::EventHandler(this, &AddEditSystemBookForm::bAddExeFile_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 18);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(77, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Путь к файлу:";
			// 
			// tbExePath
			// 
			this->tbExePath->Location = System::Drawing::Point(3, 34);
			this->tbExePath->Name = L"tbExePath";
			this->tbExePath->Size = System::Drawing::Size(171, 20);
			this->tbExePath->TabIndex = 12;
			// 
			// cbConnType
			// 
			this->cbConnType->FormattingEnabled = true;
			this->cbConnType->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Логин, пароль, база данных", L"Драйвер", L"Сторонний DLL/EXE файл"});
			this->cbConnType->Location = System::Drawing::Point(13, 30);
			this->cbConnType->Name = L"cbConnType";
			this->cbConnType->Size = System::Drawing::Size(177, 21);
			this->cbConnType->TabIndex = 8;
			this->cbConnType->Text = L"Логин, пароль, база данных";
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
			this->cbSystem->Location = System::Drawing::Point(12, 129);
			this->cbSystem->Name = L"cbSystem";
			this->cbSystem->Size = System::Drawing::Size(216, 21);
			this->cbSystem->TabIndex = 3;
			this->cbSystem->SelectedIndexChanged += gcnew System::EventHandler(this, &AddEditSystemBookForm::cbSystem_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 113);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Система:";
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(72, 456);
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
			this->bCancel->Location = System::Drawing::Point(153, 456);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 18;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &AddEditSystemBookForm::bCancel_Click);
			// 
			// bAddEditUsers
			// 
			this->bAddEditUsers->Location = System::Drawing::Point(25, 409);
			this->bAddEditUsers->Name = L"bAddEditUsers";
			this->bAddEditUsers->Size = System::Drawing::Size(177, 23);
			this->bAddEditUsers->TabIndex = 19;
			this->bAddEditUsers->Text = L"Задать доступ пользователй";
			this->bAddEditUsers->UseVisualStyleBackColor = true;
			this->bAddEditUsers->Click += gcnew System::EventHandler(this, &AddEditSystemBookForm::bAddEditUsers_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(22, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(154, 13);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Наименование справочника:";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(12, 29);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(216, 20);
			this->tbName->TabIndex = 21;
			// 
			// AddEditSystemBookForm
			// 
			this->AcceptButton = this->bOk;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->CancelButton = this->bCancel;
			this->ClientSize = System::Drawing::Size(245, 502);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->bAddEditUsers);
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
			this->pExeFile->ResumeLayout(false);
			this->pExeFile->PerformLayout();
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

			List<Attribute^>^ _dbAttrs;
			Attribute^ _idCol;
			Attribute^ _titleCol;
			Attribute^ _dateCol;

			Attribute^ _annulCol;
			String^ _annulAction;
			String^ _annulValue;

			List<DbFilter^>^ _dbFilters;
			List<DbLink^>^ _dbLinks;

			Attribute^ _roughCol;
			String^ _roughSymbols;

			int _intgrBookId;

			String^ _groupSchtab;
			Attribute^ _groupIdCol;
			Attribute^ _groupNameCol;
			Dictionary<Attribute^,Attribute^>^ _groupAttrs;

			List<PosGroupParam^>^ _posParamAttrs;

			Dictionary<int, String^>^ _users;

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
				String^ columns = "ID,ID_SYSTEM,ID_BOOK,LOGIN,PASSWORD,TNS_DATABASE,DRIVER,IS_SEMANTIC,CREATE_USER,CREATE_DATE,NAME,EXE_PATH,ANNUL_ACTION,ANNUL_VALUE";
				
				_intgrBookId = _odbc->GetLastFreeId(_odbc->schema + "INTEGRATION_BOOK");
				List<Object^>^ idBook = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "BOOKS where NAME = \'" + cbBook->Text + "\'");
				List<Object^>^ idSystem = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "INTEGRATED_SYSTEMS where NAME = \'" + cbSystem->Text + "\'");

				String^ sqlIdBook = OdbcClass::GetResInt(idBook[0]->ToString()) + "";
				String^ sqlIdSystem = OdbcClass::GetResInt(idSystem[0]->ToString()) + "";
				String^ sqlLogin = "NULL";
				String^ sqlPassword = "NULL";
				String^ sqlDriver = "NULL";
				String^ sqlDb = "NULL";
				String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
				String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);

				String^ sqlName = OdbcClass::GetSqlString(tbName->Text->Trim());

				if (_systemTypeId == 1)
				{
					sqlLogin = OdbcClass::GetSqlString(tbLogin->Text->Trim());
					sqlPassword = OdbcClass::GetSqlString(tbPass->Text);
				} 
				else
				{
					if (cbConnType->SelectedIndex == 1)
					{
						sqlDriver = OdbcClass::GetSqlString(tbDriver->Text->Trim());
					}
					else
					{
						sqlLogin = OdbcClass::GetSqlString(tbLogin->Text->Trim());
						sqlPassword = OdbcClass::GetSqlString(tbPass->Text);
						sqlDb = OdbcClass::GetSqlString(tbDb->Text->Trim());
					}
				}
				String^ sExePath = OdbcClass::GetSqlString(tbExePath->Text);
				String^ sAnnulAction = OdbcClass::GetSqlString(_annulAction);
				String^ sAnnulValue = OdbcClass::GetSqlString(_annulValue);

				String^ query;
				query = String::Format("insert into {0}INTEGRATION_BOOK ({1}) values ({2},{3},{4},{5},{6},{7},{8},{9},{10},{11},{12},{13},{14},{15})", 
					_odbc->schema, columns, _intgrBookId, sqlIdSystem, sqlIdBook, sqlLogin, sqlPassword, sqlDb, sqlDriver, _systemTypeId, sqlUser, sqlDate, 
					sqlName, sExePath, sAnnulAction, sAnnulValue);
				_odbc->ExecuteNonQuery(query);
			}

			int WriteSingleAttr(Attribute^ col, int intgrId)
			{
				List<Object^>^ query = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "integration_attributes where full_code = \'" + col->FullTable + "\' and attr_name = \'" + col->Code + "\' and ID_INTGR_BOOK = " + intgrId);
				if (query != nullptr && query->Count > 0)
				{
					return OdbcClass::GetResInt(query[0]);
				}
				else
				{
					String^ columns = "ID,FULL_CODE,NAME,SCHEMA_NAME,TABLE_NAME,ATTR_NAME,ID_INTGR_BOOK,CREATE_USER,CREATE_DATE,DATA_TYPE,MAX_LENGTH";
					int id = _odbc->GetLastFreeId(_odbc->schema + "integration_attributes");
					String^ fullTable = OdbcClass::GetSqlString(col->FullTable);
					String^ name = OdbcClass::GetSqlString(col->Name);
					String^ schemaName = OdbcClass::GetSqlString(col->Schema);
					String^ tableName = OdbcClass::GetSqlString(col->Table);
					String^ attrName = OdbcClass::GetSqlString(col->Code);
					String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
					String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);
					String^ dataType = OdbcClass::GetSqlString(col->DataType);
					String^ maxLen = OdbcClass::GetSqlString(col->MaxLength);

					String^ squery = String::Format("insert into {0}integration_attributes ({1}) values ({2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12})",
						_odbc->schema, columns, id, fullTable, name, schemaName, tableName, attrName, intgrId,  sqlUser, sqlDate, dataType, maxLen);
					_odbc->ExecuteNonQuery(squery);
					return id;
				}
			}

			Attribute^ GetAttr(String^ fullCode)
			{
				for each (Attribute^ attr in _dbAttrs) 
				{
					if (attr->FullCode == fullCode)
					{
						return attr;
					}
				}
				return nullptr;
			}

			void WriteDbAttrs(Attribute^ idCol, Attribute^ titleCol, List<array<String^>^>^ dbAttrs, int intgrId)
			{
				for (int i = 0; i < dbAttrs->Count; i++)
				{
					int id = _odbc->GetLastFreeId("" + _odbc->schema + "integration_attributes");
					array<String^>^ attributeData = dbAttrs[i];
					String^ squery = String::Format("insert into " + _odbc->schema + "integration_attributes values ({0}, \'{1}\', \'{2}\', \'{3}\', \'{4}\', \'{5}\', {6})", 
						id, attributeData[0], attributeData[1], attributeData[2], attributeData[3], attributeData[4], intgrId);
					_odbc->ExecuteNonQuery(squery);
				}

				int id = WriteSingleAttr(idCol, intgrId);
				String^ squery = "update " + _odbc->schema + "INTEGRATION_BOOK set ATTR_ID = " + id + " where ID = " + intgrId;
				_odbc->ExecuteNonQuery(squery);

				int titleAttrId = WriteSingleAttr(titleCol, intgrId);
				squery = "update " + _odbc->schema + "INTEGRATION_BOOK set ATTR_TITLE = " + titleAttrId + " where ID = " + intgrId;
				_odbc->ExecuteNonQuery(squery);
			}

			void WriteUseAttrs(List<Attribute^>^ dbAttrs, int intgrId)
			{
				String^ columns = "ID,FULL_CODE,NAME,SCHEMA_NAME,TABLE_NAME,ATTR_NAME,ID_INTGR_BOOK,CREATE_USER,CREATE_DATE,DATA_TYPE,MAX_LENGTH";
				for (int i = 0; i < dbAttrs->Count; i++)
				{
					int id = _odbc->GetLastFreeId(_odbc->schema + "integration_attributes");
					dbAttrs[i]->Id = id;
					String^ fullTable = OdbcClass::GetSqlString(dbAttrs[i]->FullTable);
					String^ name = OdbcClass::GetSqlString(dbAttrs[i]->Name);
					String^ schemaName = OdbcClass::GetSqlString(dbAttrs[i]->Schema);
					String^ tableName = OdbcClass::GetSqlString(dbAttrs[i]->Table);
					String^ attrName = OdbcClass::GetSqlString(dbAttrs[i]->Code);
					String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
					String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);
					String^ dataType = OdbcClass::GetSqlString(dbAttrs[i]->DataType);
					String^ maxLen = OdbcClass::GetSqlString(dbAttrs[i]->MaxLength);

					String^ squery = String::Format("insert into {0}integration_attributes ({1}) values ({2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12})",
						_odbc->schema, columns, id, fullTable, name, schemaName, tableName, attrName, intgrId,  sqlUser, sqlDate,  dataType, maxLen);
					_odbc->ExecuteNonQuery(squery);
				}

			}

			void WriteSingleAttrs(Attribute^ idCol, Attribute^ titleCol, Attribute^ dateCol, Attribute^ roughCol, Attribute^ annulCol, int intgrId)
			{
				int id = WriteSingleAttr(idCol, intgrId);
				String^ squery = "update " + _odbc->schema + "INTEGRATION_BOOK set ATTR_ID = " + id + " where ID = " + intgrId;
				_odbc->ExecuteNonQuery(squery);

				int titleAttrId = WriteSingleAttr(titleCol, intgrId);
				squery = "update " + _odbc->schema + "INTEGRATION_BOOK set ATTR_TITLE = " + titleAttrId + " where ID = " + intgrId;
				_odbc->ExecuteNonQuery(squery);

				if (dateCol != nullptr)
				{
					int dateAttrId = WriteSingleAttr(dateCol, intgrId);
					squery = "update " + _odbc->schema + "INTEGRATION_BOOK set ATTR_DATE = " + dateAttrId + " where ID = " + intgrId;
					_odbc->ExecuteNonQuery(squery);
				}

				if (roughCol != nullptr)
				{
					int roughAttrId = WriteSingleAttr(roughCol, intgrId);
					squery = "update " + _odbc->schema + "INTEGRATION_BOOK set ATTR_ROUGH = " + roughAttrId + " where ID = " + intgrId;
					_odbc->ExecuteNonQuery(squery);
				}

				if (annulCol != nullptr)
				{
					int annulAttrId = WriteSingleAttr(annulCol, intgrId);
					squery = "update " + _odbc->schema + "INTEGRATION_BOOK set ATTR_ANNUL = " + annulAttrId + " where ID = " + intgrId;
					_odbc->ExecuteNonQuery(squery);
				}
			}

			void WriteRoughSymbols(String^ symbols, int intgrId)
			{
				if (!String::IsNullOrEmpty(symbols))
				{
					String^ squery = String::Format("update {0}INTEGRATION_BOOK set ROUGH_SYMBOLS = {1} where ID = {2}",
						 _odbc->schema, OdbcClass::GetSqlString(symbols), intgrId);
					_odbc->ExecuteNonQuery(squery);
				}
			}

			void WriteDbFilters()
			{
				for each (DbFilter^ filter in _dbFilters)
				{
					int attrId = GetAttr(filter->AttributeFullCode)->Id;
					filter->InsertToDb(_intgrBookId, attrId);
				}
			}

			void WriteDbLinks()
			{
				for each (DbLink^ link in _dbLinks)
				{
					int attr1Id = GetAttr(link->Attribute1->FullCode)->Id;
					int attr2Id = GetAttr(link->Attribute2->FullCode)->Id;
					link->InsertToDb(_odbc, _intgrBookId, attr1Id, attr2Id);
				}
			}

			void WritePosAttrs()
			{
				for each (PosGroupParam^ posParams in _posParamAttrs)
				{
					int attr1Id = GetAttr(posParams->Attribute1->FullCode)->Id;
					int attr2Id = GetAttr(posParams->Attribute2->FullCode)->Id;
					posParams->InsertToDb(_odbc, _intgrBookId, attr1Id, attr2Id);
				}
			}

			void WriteGroup(int intgrId)
			{
				int idId = WriteSingleAttr(_groupIdCol, intgrId);
				int idName = WriteSingleAttr(_groupNameCol, intgrId);
				int idGroupParams = _odbc->GetLastFreeId(_odbc->schema + "GROUP_PARAMS");
				String^ sFullTable = OdbcClass::GetSqlString(_groupSchtab);
				String^ columns = "ID,ID_ATTR,NAME_ATTR,FULL_TABLE,CREATE_USER,CREATE_DATE";
				String^ user = OdbcClass::GetSqlString(_odbc->Login);
				String^ sDate = _odbc->GetSqlDate(DateTime::Now);

				String^ squery = String::Format("insert into {0}GROUP_PARAMS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7})",
					_odbc->schema, columns, idGroupParams, idId, idName, sFullTable, user, sDate);
				_odbc->ExecuteNonQuery(squery);

				for each (KeyValuePair<Attribute^, Attribute^>^ pair in _groupAttrs)
				{
					int idAttrPair = _odbc->GetLastFreeId(_odbc->schema + "GROUP_ATTRIBUTE_PAIRS");
					int idTitleAttr = WriteSingleAttr(pair->Key, intgrId);
					int idNameAttr = WriteSingleAttr(pair->Value, intgrId);
					columns = "ID,ID_TITLE,ID_NAME,ID_GROUP_PARAMS,CREATE_USER,CREATE_DATE";
					squery = String::Format("insert into {0}GROUP_ATTRIBUTE_PAIRS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7})",
						_odbc->schema, columns, idAttrPair, idTitleAttr, idNameAttr, idGroupParams, user, sDate);
					_odbc->ExecuteNonQuery(squery);
				}

				squery = String::Format("update {0}INTEGRATION_BOOK set GROUP_ID = {1} where ID = {2}", _odbc->schema, idGroupParams, intgrId);
				_odbc->ExecuteNonQuery(squery);
			}

			void WriteUserAccess()
			{
				String^ columns = "ID,ID_USER_ROLE,ID_INT_BOOK,CREATE_USER,CREATE_DATE";
				String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
				String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);

				if (_users != nullptr && _users->Count > 0)
				{
					for each (KeyValuePair<int, String^>^ pair in _users)
					{
						int id = _odbc->GetLastFreeId(_odbc->schema + "USERS_BOOKS");
						String^ sQuery = String::Format("insert into {0}USERS_BOOKS ({1}) values ({2}, {3}, {4}, {5}, {6})",
							_odbc->schema, columns, id, pair->Key, _intgrBookId, sqlUser, sqlDate);
						_odbc->ExecuteNonQuery(sQuery);
					}
				}
			}

			Void WriteToDb()
			{
				WriteIntegrBook();

				if (!isDllExeBook)
				{
					WriteUseAttrs(_dbAttrs, _intgrBookId);
					WriteSingleAttrs(_idCol, _titleCol, _dateCol, _roughCol, _annulCol, _intgrBookId);
					if (_dbFilters != nullptr)
					{
						WriteDbFilters();
					}
					if (_dbLinks != nullptr)
					{
						WriteDbLinks();
					}
					WriteRoughSymbols(_roughSymbols, _intgrBookId);
					if (!String::IsNullOrEmpty(_groupSchtab))
					{
						WriteGroup(_intgrBookId);
					}
					if (_posParamAttrs != nullptr && _posParamAttrs->Count > 0)
					{
						WritePosAttrs();
					}
				}
				WriteUserAccess();
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

				 pExeFile->Visible = false;
				 bAddAttrs->Enabled = true;
			 }
			 else if (cbConnType->SelectedIndex == 1)
			 {
				 pExeFile->Visible = false;
				 bAddAttrs->Enabled = true;

				 tbDriver->Visible = true;
				 tbLogin->Visible = false;
				 tbPass->Visible = false;
				 tbDb->Visible = false;
			 }
			 else
			 {
				 pExeFile->Visible = true;
				 bAddAttrs->Enabled = false;

				 tbDriver->Visible = false;
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
			 isDllExeBook = false;

			 if (String::IsNullOrEmpty(tbName->Text))
			 {
				 MessageBox::Show("Не задано наименование справочника!");
				 return;
			 }
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
			 else if (_users == nullptr || _users->Count <= 0)
			 {
				 MessageBox::Show("Не задан доступ для пользователей!");
				 return;
			 }
			 else if (cbConnType->SelectedIndex == 1)
			 {
				 if (String::IsNullOrEmpty(tbDriver->Text))
				 {
					 MessageBox::Show("Не задан драйвер для системы!");
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
			 }
			 else if (cbConnType->SelectedIndex == 0)
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
			 }
			 else
			 {
				 if (String::IsNullOrEmpty(tbExePath->Text))
				 {
					 MessageBox::Show("Не задан путь к исполняемому файлу!");
					 return;
				 }
				 isDllExeBook = true;
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
					 _dateCol = addAttrForm->DateCol;
					 _dbAttrs = addAttrForm->Attributes;

					 _roughCol = addAttrForm->RoughCol;
					 _roughSymbols = addAttrForm->RoughSymbols;
					 
					 _dbFilters = addAttrForm->DbFilters;
					 _dbLinks = addAttrForm->DbLinks;

					 _groupSchtab = addAttrForm->GroupSchtab;
					 if (!String::IsNullOrEmpty(_groupSchtab))
					 {
						 _groupIdCol = addAttrForm->GroupIdCol;
						 _groupNameCol = addAttrForm->GroupNameCol;
						 _groupAttrs = addAttrForm->GroupAttrs;
					 }

					 _annulCol = addAttrForm->AnnulAttr;
					 if (_annulCol != nullptr)
					 {
						 _annulAction = addAttrForm->AnnulAction;
						 _annulValue = addAttrForm->AnnulValue;
					 }
					 
					 _posParamAttrs = addAttrForm->PosParamAttrs;
					 
				 }
				 
			 }
			 
		 }
private: System::Void bAddEditUsers_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 UserBookAccessForm^ form;
			 if (_users == nullptr)
			 {
				 form = gcnew UserBookAccessForm(0, _users);
			 }
			 else
			 {
				 form = gcnew UserBookAccessForm(1, _users);
			 }
			 form->ShowDialog();

			 if (form->IsOk)
			 {
				 _users = form->Users;
			 }
		 }

private: System::Void bAddExeFile_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 OpenFileDialog^ dialog = gcnew OpenFileDialog();
			 dialog->Title = "Выберите сторонний DLL/EXE файл";
			 dialog->Filter = "Исполняемые файлы (.dll, .exe)|*.dll;*.exe";
			 System::Windows::Forms::DialogResult res = dialog->ShowDialog();
			 if (res == Windows::Forms::DialogResult::Yes || res == Windows::Forms::DialogResult::OK)
			 {
				 tbExePath->Text = dialog->FileName;
			 }
			 else
			 {
				 return;
			 }
		 }
};
}
