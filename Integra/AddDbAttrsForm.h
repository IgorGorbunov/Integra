#pragma once
#include "AddNewTableForm.h"
#include "ODBCclass.h"
#include "Attribute.h"
#include "DbFiltersForm.h"
#include "TableLinksForm.h"


namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddAttrsForm
	/// </summary>
	public ref class AddDbAttrsForm : public System::Windows::Forms::Form
	{
	public:
		bool WrongPass;
		Attribute^ IdCol;
		Attribute^ TitleCol;
		List<array<String^>^>^ Attributes;

	private:
		List<String^>^ _fields;
		OdbcClass^ _odbc;
		String^ _filter;
		Dictionary<String^, String^>^ _links;

	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::Button^  bAddTableLinks;
	private: System::Windows::Forms::Button^  bAddFilter;
	private: System::Windows::Forms::Button^  bGroupParams;


	private: System::Windows::Forms::TreeView^  tv;
			 
		

	public:
		AddDbAttrsForm(String^ login, String^ pass, String^ database)
		{
			InitializeComponent();
			Attributes = gcnew List<array<String ^> ^>();
			_odbc = gcnew OdbcClass(login, pass, database);
			TryConnect();
		}

		AddDbAttrsForm(String^ driver)
		{
			InitializeComponent();
			Attributes = gcnew List<array<String ^> ^>();
			_odbc = gcnew OdbcClass(driver);
			TryConnect();
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddDbAttrsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  lbTables;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  bAddNewTable;
	private: System::Windows::Forms::DataGridView^  dgvFields;

	private: System::Windows::Forms::Button^  bClose;
	private: System::Windows::Forms::Button^  bRecord;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cbId;
	private: System::Windows::Forms::ComboBox^  cbTitle;
	private: System::Windows::Forms::Label^  label3;



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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->lbTables = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bAddNewTable = (gcnew System::Windows::Forms::Button());
			this->dgvFields = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bClose = (gcnew System::Windows::Forms::Button());
			this->bRecord = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbId = (gcnew System::Windows::Forms::ComboBox());
			this->cbTitle = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tv = (gcnew System::Windows::Forms::TreeView());
			this->bAddTableLinks = (gcnew System::Windows::Forms::Button());
			this->bAddFilter = (gcnew System::Windows::Forms::Button());
			this->bGroupParams = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvFields))->BeginInit();
			this->SuspendLayout();
			// 
			// lbTables
			// 
			this->lbTables->FormattingEnabled = true;
			this->lbTables->Location = System::Drawing::Point(12, 31);
			this->lbTables->Name = L"lbTables";
			this->lbTables->Size = System::Drawing::Size(429, 134);
			this->lbTables->TabIndex = 0;
			this->lbTables->SelectedIndexChanged += gcnew System::EventHandler(this, &AddDbAttrsForm::lbTables_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Таблица БД";
			// 
			// bAddNewTable
			// 
			this->bAddNewTable->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddNewTable->Location = System::Drawing::Point(146, 177);
			this->bAddNewTable->Name = L"bAddNewTable";
			this->bAddNewTable->Size = System::Drawing::Size(170, 30);
			this->bAddNewTable->TabIndex = 5;
			this->bAddNewTable->Text = L"Добавить новую таблицу";
			this->bAddNewTable->UseVisualStyleBackColor = false;
			this->bAddNewTable->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bAddNewTable_Click);
			// 
			// dgvFields
			// 
			this->dgvFields->AllowUserToAddRows = false;
			this->dgvFields->AllowUserToDeleteRows = false;
			this->dgvFields->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvFields->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dgvFields->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvFields->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->Column1, this->Column2, 
				this->Column3, this->Column4, this->Column8});
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvFields->DefaultCellStyle = dataGridViewCellStyle5;
			this->dgvFields->Location = System::Drawing::Point(12, 225);
			this->dgvFields->Name = L"dgvFields";
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvFields->RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->dgvFields->RowHeadersVisible = false;
			this->dgvFields->Size = System::Drawing::Size(699, 210);
			this->dgvFields->TabIndex = 6;
			this->dgvFields->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AddDbAttrsForm::dgvFields_CellValueChanged);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Используемость";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Код реквизита";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 80;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Наименование реквизита";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 300;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Тип данных";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 80;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Размерность";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Width = 80;
			// 
			// bClose
			// 
			this->bClose->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bClose->Location = System::Drawing::Point(624, 453);
			this->bClose->Name = L"bClose";
			this->bClose->Size = System::Drawing::Size(87, 30);
			this->bClose->TabIndex = 8;
			this->bClose->Text = L"Отмена";
			this->bClose->UseVisualStyleBackColor = false;
			this->bClose->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bClose_Click);
			// 
			// bRecord
			// 
			this->bRecord->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bRecord->Enabled = false;
			this->bRecord->Location = System::Drawing::Point(517, 453);
			this->bRecord->Name = L"bRecord";
			this->bRecord->Size = System::Drawing::Size(87, 30);
			this->bRecord->TabIndex = 7;
			this->bRecord->Text = L"Записать";
			this->bRecord->UseVisualStyleBackColor = false;
			this->bRecord->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bRecord_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(469, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Реквизит-идентификатор:";
			// 
			// cbId
			// 
			this->cbId->Enabled = false;
			this->cbId->FormattingEnabled = true;
			this->cbId->Location = System::Drawing::Point(459, 31);
			this->cbId->Name = L"cbId";
			this->cbId->Size = System::Drawing::Size(202, 21);
			this->cbId->TabIndex = 10;
			// 
			// cbTitle
			// 
			this->cbTitle->Enabled = false;
			this->cbTitle->FormattingEnabled = true;
			this->cbTitle->Location = System::Drawing::Point(459, 85);
			this->cbTitle->Name = L"cbTitle";
			this->cbTitle->Size = System::Drawing::Size(202, 21);
			this->cbTitle->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(469, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(110, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Основной реквизит:";
			// 
			// tv
			// 
			this->tv->CheckBoxes = true;
			this->tv->Location = System::Drawing::Point(114, 31);
			this->tv->Name = L"tv";
			this->tv->Size = System::Drawing::Size(327, 134);
			this->tv->TabIndex = 13;
			this->tv->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &AddDbAttrsForm::tv_AfterSelect);
			// 
			// bAddTableLinks
			// 
			this->bAddTableLinks->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddTableLinks->Location = System::Drawing::Point(459, 120);
			this->bAddTableLinks->Name = L"bAddTableLinks";
			this->bAddTableLinks->Size = System::Drawing::Size(118, 45);
			this->bAddTableLinks->TabIndex = 14;
			this->bAddTableLinks->Text = L"Добавить связи между таблицами";
			this->bAddTableLinks->UseVisualStyleBackColor = false;
			this->bAddTableLinks->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bAddTableLinks_Click);
			// 
			// bAddFilter
			// 
			this->bAddFilter->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddFilter->Location = System::Drawing::Point(591, 120);
			this->bAddFilter->Name = L"bAddFilter";
			this->bAddFilter->Size = System::Drawing::Size(118, 45);
			this->bAddFilter->TabIndex = 15;
			this->bAddFilter->Text = L"Добавить фильтры";
			this->bAddFilter->UseVisualStyleBackColor = false;
			this->bAddFilter->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bAddFilter_Click);
			// 
			// bGroupParams
			// 
			this->bGroupParams->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bGroupParams->Location = System::Drawing::Point(459, 175);
			this->bGroupParams->Name = L"bGroupParams";
			this->bGroupParams->Size = System::Drawing::Size(252, 35);
			this->bGroupParams->TabIndex = 16;
			this->bGroupParams->Text = L"Добавить параметры групп";
			this->bGroupParams->UseVisualStyleBackColor = false;
			this->bGroupParams->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bGroupParams_Click);
			// 
			// AddDbAttrsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(739, 495);
			this->Controls->Add(this->bGroupParams);
			this->Controls->Add(this->bAddFilter);
			this->Controls->Add(this->bAddTableLinks);
			this->Controls->Add(this->tv);
			this->Controls->Add(this->cbTitle);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->cbId);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bClose);
			this->Controls->Add(this->bRecord);
			this->Controls->Add(this->dgvFields);
			this->Controls->Add(this->bAddNewTable);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lbTables);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"AddDbAttrsForm";
			this->Text = L"AddAttrsForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvFields))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:
			void SetButtonRec()
			{
				bool checked = false;
				for (int i = 0; i < dgvFields->Rows->Count; i++)
				{
					bool ch = (bool) dgvFields[0, i]->Value;
					if (ch)
					{
						checked = true;
						break;
					}
				}
				if (checked)
				{
					tv->SelectedNode->Checked = true;
				}
				else
				{
					tv->SelectedNode->Checked = false;
				}
			}

			void TryConnect()
			{
				try
				{
					List<Object^>^ query = _odbc->ExecuteQuery("select ID from " + OdbcClass::schema + "BOOKS");
					WrongPass = false;
				}
				catch (TimeoutException^)
				{
					WrongPass = true;
				}
			}


	private: System::Void bAddNewTable_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 bool isOk = true;
				 /*if (dgvFields->Rows->Count > 0)
				 {
					 System::Windows::Forms::DialogResult result = MessageBox::Show("tst", "sts", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Warning);
					 if (result != Windows::Forms::DialogResult::Yes)
					 {
						 isOk = false;
					 }
				 }*/
				 if (isOk)
				 {
					 AddNewTableForm^ form = gcnew AddNewTableForm();
					 form->ShowDialog();
					 String^ schema = form->Schema;
					 String^ table = form->Table;
					 /*if (lbTables->Items->Contains(newSchtab))
					 {
					 MessageBox::Show("Uze est");
					 bAddNewTable_Click(sender, e);
					 }
					 else
					 {
					 lbTables->Items->Add(newSchtab);
					 }*/
					 if (tv->Nodes->ContainsKey(schema))
					 {
						 TreeNode^ schemaNode = tv->Nodes[schema];
						 if (schemaNode->Nodes->ContainsKey(table))
						 {
							 MessageBox::Show("Данная таблица уже есть в дереве!");
						 }
						 else
						 {
							 schemaNode->Nodes->Add(table, table);
						 }
					 }
					 else
					 {
						 if (String::IsNullOrEmpty(schema))
						 {
							 tv->Nodes->Add("без схемы", "без схемы");
							 tv->Nodes["без схемы"]->Nodes->Add(table, table);
						 }
						 else
						 {
							 tv->Nodes->Add(schema, schema);
							 tv->Nodes[schema]->Nodes->Add(table, table);
						 }
						 
					 }
				 }
				 
			 }
private: System::Void lbTables_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 /*if (lbTables->SelectedItem != nullptr)
			 {
				 dgvFields->Rows->Clear();
				 _fields = gcnew List<String ^>();
				 List<Object^>^ fields = _odbc->GetTableInfo7(lbTables->SelectedItem->ToString());
				 for (int i = 0; i < fields->Count; i += 7)
				 {
					 array<Object^>^ row = gcnew array<Object ^>(8);
					 row[0] = false;
					 row[1] = fields[i];
					 row[2] = fields[i+1];
					 row[3] = fields[i+2];
					 row[4] = fields[i+3];
					 row[5] = fields[i+4];
					 row[6] = fields[i+5];
					 row[7] = fields[i+6];
					 dgvFields->Rows->Add(row);

					 String^ fieldCode = lbTables->SelectedItem->ToString() + "." + fields[i]->ToString();
					 if (!_fields->Contains(fieldCode))
					 {
						 _fields->Add(fieldCode);
						 cbId->Items->Add(fieldCode);
						 cbTitle->Items->Add(fieldCode);
					 }
					 
				 }
				 cbId->Enabled = true;
				 cbTitle->Enabled = true;
			 }*/
			 
		 }
private: System::Void bClose_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 IdCol = nullptr;
			 TitleCol = nullptr;
			 Close();
		 }
private: System::Void dgvFields_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (tv->SelectedNode != nullptr)
			 {
				 if (e->ColumnIndex == 0)
				 {
					 SetButtonRec();
					 for (int i = 0; i < dgvFields->Rows->Count; i++)
					 {
						 bool ch = (bool) dgvFields[0, i]->Value;
						 if (ch)
						 {
							 String^ fieldCode = dgvFields[1, i]->Value->ToString();
							 String^ fieldName = dgvFields[2, i]->Value->ToString();
							 String^ schema = tv->SelectedNode->Parent->Name;
							 String^ table =  tv->SelectedNode->Name;
							 String^ schtab = String::Format("{0}.{1}", schema, table);

							 array<String^>^ arrr = gcnew array<String ^>(5);
							 arrr[0] = schtab;
							 arrr[1] = fieldName;
							 arrr[2] = schema;
							 arrr[3] = table;
							 arrr[4] = fieldCode;

							 Attributes->Add(arrr);
							 /*String^ squery = String::Format("insert into " + OdbcClass::schema + "integration_attributes values ({0}, \'{1}\', \'{2}\', \'{3}\', \'{4}\', \'{5}\', {6})", 
							 id, schtab, fieldName, arr[0], arr[1], fieldCode, _idIntgrBook);
							 OdbcClass::ExecuteNonQueryStatic(squery);*/
						 }
					 }
				 }
				 else if (e->ColumnIndex == 2)
				 {
					 String^ schtab = String::Format("{0}.{1}", tv->SelectedNode->Parent->Name, tv->SelectedNode->Name);
					 String^ field = dgvFields[1, e->RowIndex]->Value->ToString();
					 String^ fullCode = String::Format("{0}.{1}", schtab, field);
					 OdbcClass::AddColumnComment(fullCode,  dgvFields[e->ColumnIndex, e->RowIndex]->Value->ToString());
				 }
			 }
			 
		 }
private: System::Void bRecord_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (cbId->SelectedItem == nullptr)
			 {
				 MessageBox::Show("Не задан реквизит-идентификатор!");
				 return;
			 }
			 if (cbTitle->SelectedItem == nullptr)
			 {
				 MessageBox::Show("Не задан основной реквизит!");
				 return;
			 }
			 String^ schtab = lbTables->SelectedItem->ToString();
			 array<String^>^ arr = schtab->Split('.');
			 for (int i = 0; i < dgvFields->Rows->Count; i++)
			 {
				 bool ch = (bool) dgvFields[0, i]->Value;
				 if (ch)
				 {
					 String^ fieldCode = dgvFields[1, i]->Value->ToString();
					 String^ fieldName = dgvFields[2, i]->Value->ToString();

					 array<String^>^ arrr = gcnew array<String ^>(5);
					 arrr[0] = schtab;
					 arrr[1] = fieldName;
					 arrr[2] = arr[0];
					 arrr[3] = arr[1];
					 arrr[4] = fieldCode;

					 Attributes->Add(arrr);
					 /*String^ squery = String::Format("insert into " + OdbcClass::schema + "integration_attributes values ({0}, \'{1}\', \'{2}\', \'{3}\', \'{4}\', \'{5}\', {6})", 
					 id, schtab, fieldName, arr[0], arr[1], fieldCode, _idIntgrBook);
					 OdbcClass::ExecuteNonQueryStatic(squery);*/
				 }
			 }
			 dgvFields->Rows->Clear();
			 bRecord->Enabled = false;
		 }
private: System::Void tv_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) 
		 {
			 if (e->Node->Level > 0)
			 {
				 dgvFields->Rows->Clear();
				 cbId->Items->Clear();
				 cbTitle->Items->Clear();

				 _fields = gcnew List<String ^>();
				 String^ schtab = String::Format("{0}.{1}", e->Node->Parent->Name, e->Node->Name);
				 List<Object^>^ fields = _odbc->GetTableInfo7(schtab);
				 for (int i = 0; i < fields->Count; i += 7)
				 {
					 array<Object^>^ row = gcnew array<Object ^>(8);
					 row[0] = false;
					 row[1] = fields[i];
					 row[2] = fields[i+1];
					 row[3] = fields[i+2];
					 row[4] = fields[i+3];
					 row[5] = fields[i+4];
					 row[6] = fields[i+5];
					 row[7] = fields[i+6];
					 dgvFields->Rows->Add(row);

					 String^ fieldCode = String::Format("{0}.{1}", schtab, fields[i]->ToString());
					 if (!_fields->Contains(fieldCode))
					 {
						 _fields->Add(fieldCode);
					 }
					 cbId->Items->Add(fieldCode);
					 cbTitle->Items->Add(fieldCode);

				 }
				 cbId->Enabled = true;
				 cbTitle->Enabled = true;
			 }
			 else
			 {
				 dgvFields->Rows->Clear();
			 }
		 }
private: System::Void bAddFilter_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 DbFiltersForm^ form = gcnew DbFiltersForm(nullptr);
			 form->ShowDialog();
			 if (!String::IsNullOrEmpty(form->Condition))
			 {
				 _filter = form->Condition;
			 }
		 }
private: System::Void bAddTableLinks_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 TableLinksForm^ form = gcnew TableLinksForm(nullptr);
			 form->ShowDialog();
			 if (_links != nullptr)
			 {
				 _links = form->Links;
			 }
		 }

private: System::Void bGroupParams_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

		 }
};
}
