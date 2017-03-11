#pragma once
#include "AddGroupLinksForm.h"
#include "Settings.h"
#include "IntegrationSettings.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddEditSchemaForm2
	/// </summary>
	public ref class AddEditSchemaForm2 : public System::Windows::Forms::Form
	{
	private:
		Settings^ _settings;
		array<String^, 2>^ _books;
		OdbcClass^ _odbc;

		Dictionary<int, String^>^ _systemBooksIdExe;

		Dictionary<Attribute^, Attribute^>^ _attrPairs;
		Dictionary<Attribute^, Attribute^>^ _attrEquivs;
		List<ComplexAttribute^>^ _complexAttrs;

		bool _isGroup;
		List<IntegrationGroupPair^>^ _groupPairs;

		BookSettings^ _sourceBook;
		BookSettings^ _targetBook;

		bool _isSourceExe;
		bool _isTargetExe;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tbName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;

	public:
		AddEditSchemaForm2(Settings^ settings, OdbcClass^ odbc)
		{
			InitializeComponent();
			_settings = settings;
			_books = _settings->Books;
			_odbc = odbc;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddEditSchemaForm2()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataGridView^  dgvSource;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  cbIntgr;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::DataGridView^  dgvTarget;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Button^  bSave;
	private: System::Windows::Forms::Button^  bLinks;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cbBook;
	private: System::Windows::Forms::GroupBox^  groupBox1;

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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dgvSource = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cbIntgr = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dgvTarget = (gcnew System::Windows::Forms::DataGridView());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bSave = (gcnew System::Windows::Forms::Button());
			this->bLinks = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbBook = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTarget))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(42, 72);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(216, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Декларированный справочник-источник:";
			// 
			// dgvSource
			// 
			this->dgvSource->AllowUserToAddRows = false;
			this->dgvSource->AllowUserToDeleteRows = false;
			this->dgvSource->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvSource->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvSource->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSource->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->Column4, this->Column1, 
				this->Column2, this->Column3});
			this->dgvSource->Location = System::Drawing::Point(26, 101);
			this->dgvSource->Name = L"dgvSource";
			this->dgvSource->ReadOnly = true;
			this->dgvSource->RowHeadersVisible = false;
			this->dgvSource->Size = System::Drawing::Size(432, 262);
			this->dgvSource->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(499, 72);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(227, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Декларированный справочник-получатель:";
			// 
			// cbIntgr
			// 
			this->cbIntgr->FormattingEnabled = true;
			this->cbIntgr->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Односторонняя", L"Двусторонняя"});
			this->cbIntgr->Location = System::Drawing::Point(390, 37);
			this->cbIntgr->Name = L"cbIntgr";
			this->cbIntgr->Size = System::Drawing::Size(231, 21);
			this->cbIntgr->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(387, 21);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(159, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Тип направления интеграции:";
			// 
			// dgvTarget
			// 
			this->dgvTarget->AllowUserToAddRows = false;
			this->dgvTarget->AllowUserToDeleteRows = false;
			this->dgvTarget->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvTarget->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvTarget->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTarget->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->Column5, this->dataGridViewTextBoxColumn1, 
				this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3});
			this->dgvTarget->Location = System::Drawing::Point(490, 101);
			this->dgvTarget->Name = L"dgvTarget";
			this->dgvTarget->ReadOnly = true;
			this->dgvTarget->RowHeadersVisible = false;
			this->dgvTarget->Size = System::Drawing::Size(431, 262);
			this->dgvTarget->TabIndex = 6;
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(846, 382);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 7;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &AddEditSchemaForm2::bCancel_Click);
			// 
			// bSave
			// 
			this->bSave->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bSave->Location = System::Drawing::Point(749, 382);
			this->bSave->Name = L"bSave";
			this->bSave->Size = System::Drawing::Size(75, 23);
			this->bSave->TabIndex = 8;
			this->bSave->Text = L"Сохранить";
			this->bSave->UseVisualStyleBackColor = false;
			this->bSave->Click += gcnew System::EventHandler(this, &AddEditSchemaForm2::bSave_Click);
			// 
			// bLinks
			// 
			this->bLinks->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bLinks->Location = System::Drawing::Point(674, 21);
			this->bLinks->Name = L"bLinks";
			this->bLinks->Size = System::Drawing::Size(223, 39);
			this->bLinks->TabIndex = 9;
			this->bLinks->Text = L"Задать соответствия реквизитов";
			this->bLinks->UseVisualStyleBackColor = false;
			this->bLinks->Click += gcnew System::EventHandler(this, &AddEditSchemaForm2::bLinks_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Справочник:";
			// 
			// cbBook
			// 
			this->cbBook->FormattingEnabled = true;
			this->cbBook->Location = System::Drawing::Point(20, 39);
			this->cbBook->Name = L"cbBook";
			this->cbBook->Size = System::Drawing::Size(231, 21);
			this->cbBook->TabIndex = 1;
			this->cbBook->SelectedIndexChanged += gcnew System::EventHandler(this, &AddEditSchemaForm2::cbBook_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->cbBook);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(182, 117);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(277, 77);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Фильтр справочников:";
			this->groupBox1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(42, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(183, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Наименование схемы интеграции:";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(26, 37);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(311, 20);
			this->tbName->TabIndex = 11;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"ID";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Visible = false;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Наименование";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Тип справочника";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Система";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"ID";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Visible = false;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Наименование";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Тип справочника";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Система";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// AddEditSchemaForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(933, 419);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->bLinks);
			this->Controls->Add(this->bSave);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->dgvTarget);
			this->Controls->Add(this->cbIntgr);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dgvSource);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox1);
			this->Name = L"AddEditSchemaForm2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление/редактирование схем интеграции";
			this->Load += gcnew System::EventHandler(this, &AddEditSchemaForm2::AddEditSchemaForm2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTarget))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:
			void SetDgv(DataGridView^ dgv, array<String^, 2>^ books)
			{
				dgv->Rows->Clear();
				
				for (int i = 0; i < books->GetLength(0); i++)
				{
					array<String^>^ row = gcnew array<String ^>(books->GetLength(1));
					for (int j = 0; j < books->GetLength(1); j++)
					{
						row[j] = books[i,j];
					}
					dgv->Rows->Add(row);
				}
			}

			void SetComboBox()
			{
				cbBook->Items->Clear();
				for (int i = 0; i < _books->GetLength(0); i++)
				{
					cbBook->Items->Add(_books[i,1]);
				}
			}

			bool LinkCheck()
			{
				if (cbIntgr->SelectedItem == nullptr)
				{
					MessageBox::Show("Не задан тип интеграции!");
					return false;
				}
				if (dgvSource->SelectedCells == nullptr || dgvSource->SelectedCells->Count <= 0)
				{
					MessageBox::Show("Не выбран декларированный справочник-источник!");
					return false;
				}
				int idSourceBook = OdbcClass::GetResInt(dgvSource[0, dgvSource->SelectedCells[0]->RowIndex]->Value->ToString());
				_isSourceExe = false;
				for each (KeyValuePair<int, String^>^ pair in _systemBooksIdExe)
				{
					if (pair->Key == idSourceBook)
					{
						if (!String::IsNullOrEmpty(pair->Value))
						{
							_isSourceExe = true;
							break;
						}
					}
				}
				if (_isSourceExe)
				{
					MessageBox::Show("Справочник на основе стороннего EXE файла не может быть источником!");
					return false;
				}

				if (dgvTarget->SelectedCells == nullptr || dgvTarget->SelectedCells->Count <= 0)
				{
					MessageBox::Show("Не выбран декларированный справочник-получатель!");
					return false;
				}
				int idTargetBook = OdbcClass::GetResInt(dgvTarget[0, dgvTarget->SelectedCells[0]->RowIndex]->Value->ToString());
				_isTargetExe = false;
				for each (KeyValuePair<int, String^>^ pair in _systemBooksIdExe)
				{
					if (pair->Key == idTargetBook)
					{
						if (!String::IsNullOrEmpty(pair->Value))
						{
							_isTargetExe = true;
							break;
						}
					}
				}
				if (_isTargetExe)
				{
					MessageBox::Show("Для передачи данных в справочник на основе стороннего EXE файла задание соответствия реквизитов не требуется!");
					return false;
				}
				return true;
			}

			bool SaveSchemaCheck()
			{
				if (String::IsNullOrEmpty(tbName->Text))
				{
					MessageBox::Show("Не задано наименование схемы интеграции!");
					return false;
				}
				else if (cbIntgr->SelectedItem == nullptr)
				{
					MessageBox::Show("Не задан тип интеграции!");
					return false;
				}

				int idTargetBook = OdbcClass::GetResInt(dgvTarget[0, dgvTarget->SelectedCells[0]->RowIndex]->Value->ToString());
				_isTargetExe = false;
				for each (KeyValuePair<int, String^>^ pair in _systemBooksIdExe)
				{
					if (pair->Key == idTargetBook)
					{
						if (!String::IsNullOrEmpty(pair->Value))
						{
							_isTargetExe = true;
							break;
						}
					}
				}
				if (_isTargetExe)
				{
					int intgrType = cbIntgr->SelectedIndex;
					if (intgrType == 1)
					{
						MessageBox::Show("Интеграция через сторонний EXE/DLL файл может быть только односторонняя!");
						return false;
					}
				}
				else
				{
					if (_isGroup)
					{
						if (_groupPairs == nullptr || _groupPairs->Count <= 0)
						{
							MessageBox::Show("Не заданы связи между реквизитами!");
							return false;
						}
					}
					else
					{
						if (_attrPairs == nullptr)
						{
							MessageBox::Show("Не заданы связи между реквизитами!");
							return false;
						}
					}
				}
				return true;
			}

private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void bSave_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (!SaveSchemaCheck())
			 {
				 return;
			 }

			 int intgrType = cbIntgr->SelectedIndex;
			 String^ name = tbName->Text->Trim();

			 if (_sourceBook == nullptr)
			 {
				 String^ oS = dgvSource[0, dgvSource->SelectedCells[0]->RowIndex]->Value->ToString();
				 _sourceBook = gcnew BookSettings(OdbcClass::GetResInt(oS), _odbc);
			 }
			 if (_targetBook == nullptr)
			 {
				 String^ oT = dgvTarget[0, dgvTarget->SelectedCells[0]->RowIndex]->Value->ToString();
				 _targetBook = gcnew BookSettings(OdbcClass::GetResInt(oT), _odbc);
			 }


			 IntegrationSettings^ intSettings;
			 if (_isTargetExe)
			 {
				 intSettings = gcnew IntegrationSettings(_odbc, name, _sourceBook, _targetBook, intgrType);
			 }
			 else
			 {
				 if (_isGroup)
				 {
					 intSettings = gcnew IntegrationSettings(_odbc, name, _sourceBook, _targetBook, intgrType,_groupPairs); 
				 }
				 else
				 {
					 intSettings = gcnew IntegrationSettings(_odbc, name, _sourceBook, _targetBook, intgrType, _attrPairs, _attrEquivs, _complexAttrs); 
				 }
			 }

			 Close();
		 }
private: System::Void bLinks_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (!LinkCheck())
			 {
				 return;
			 }


			 String^ oS = dgvSource[0, dgvSource->SelectedCells[0]->RowIndex]->Value->ToString();
			 String^ oT = dgvTarget[0, dgvTarget->SelectedCells[0]->RowIndex]->Value->ToString();
			 _sourceBook = gcnew BookSettings(OdbcClass::GetResInt(oS), _odbc);
			 _targetBook = gcnew BookSettings(OdbcClass::GetResInt(oT), _odbc);
			 AddGroupLinksForm^ form = gcnew AddGroupLinksForm(_attrPairs, _complexAttrs, _sourceBook, _targetBook, cbIntgr->SelectedIndex, _odbc);
			 form->ShowDialog();
			 if (form->IsGroup)
			 {
				 _groupPairs = form->IntegrationGroups;
				 _isGroup = true;
			 }
			 else
			 {
				 _attrPairs = form->AttrPairs;
				 _complexAttrs = form->ComplexAttrs;
				 _attrEquivs = form->AttrEquivs;
				 _isGroup = false;
			 }

		 }
private: System::Void AddEditSchemaForm2_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 array<String^, 2>^ systemBooks = _settings->GetSystemBooks();
			 _systemBooksIdExe = _settings->GetSystemBooksIdExe();
			 SetDgv(dgvSource, systemBooks);
			 SetDgv(dgvTarget, systemBooks);
			 SetComboBox();
		 }

private: System::Void cbBook_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (cbBook->SelectedItem == nullptr || cbBook->SelectedItem->ToString() == "")
			 {
				 array<String^, 2>^ systemBooks = _settings->GetSystemBooks();
				 SetDgv(dgvSource, systemBooks);
				 SetDgv(dgvTarget, systemBooks);
				 return;
			 }
			 String^ name = cbBook->SelectedItem->ToString();
			 int id = 0;
			 for (int i = 0; i < _books->GetLength(0); i++)
			 {
				 if (name == _books[i,1])
				 {
					 id = Int32::Parse(_books[i,0]);
					 break;
				 }
			 }
			 array<String^, 2>^ systemBooks = _settings->GetSystemBooks(id);
			 SetDgv(dgvSource, systemBooks);
			 SetDgv(dgvTarget, systemBooks);
		 }

};
}
