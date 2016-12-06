#pragma once

#include "Settings.h"
#include "ODBCclass.h"
#include "EditForm.h"
#include "IntegrationSettings.h"
#include "AddEditSchemaForm2.h"
#include "RoleStation.h"
#include "AddEditSystemBookForm.h"


namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	private:
		Settings^ _settings;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  BookIdCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  BookNameCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SystemIdCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SystemName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SchemaIdCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SchemaBookNameCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SchemaSourceCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SchemaTargetCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SchemaDirectionCol;
	private: System::Windows::Forms::TabPage^  tpIntegrBook;
	private: System::Windows::Forms::DataGridView^  dgvSystemBooks;
	private: System::Windows::Forms::ComboBox^  cbSystems;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  bEditSystemBook;
	private: System::Windows::Forms::Button^  bAddSystemBook;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;



			 OdbcClass^ _odbc;
			 array<String^, 2>^ _currentSystemBooks;
			 //List<IntegrationSettings^>^ _integrSettings;

	public:
		SettingsForm(OdbcClass^ odbc)
		{
			_odbc = odbc;
			InitializeComponent();
			//_integrSettings = integrSettings;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::Button^  bCancel;

	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tpBooks;

	private: System::Windows::Forms::Button^  bEditBook;



	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  bAddBook;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tbBookName;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridView^  dgvBooks;

	private: System::Windows::Forms::TabPage^  tpSystems;

	private: System::Windows::Forms::Button^  bEditSystem;



	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Button^  bAddSystem;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbSystemName;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::DataGridView^  dgvSystems;

	private: System::Windows::Forms::TabPage^  tpIntegrationSchemas;
	private: System::Windows::Forms::Button^  bAddSchema;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::DataGridView^  dgvSchemas;

	private: System::Windows::Forms::Button^  bEditSchema;


			 private: System::Windows::Forms::Label^ label4;
					  private: System::Windows::Forms::DataGridView^ dataGridView1;
					  private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
					  private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
					  private: System::Windows::Forms::Button^ button1;
					  private: System::Windows::Forms::Button^ button2;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tpBooks = (gcnew System::Windows::Forms::TabPage());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bEditBook = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->bAddBook = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbBookName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dgvBooks = (gcnew System::Windows::Forms::DataGridView());
			this->BookIdCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BookNameCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tpSystems = (gcnew System::Windows::Forms::TabPage());
			this->bEditSystem = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->bAddSystem = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbSystemName = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dgvSystems = (gcnew System::Windows::Forms::DataGridView());
			this->SystemIdCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SystemName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tpIntegrBook = (gcnew System::Windows::Forms::TabPage());
			this->bEditSystemBook = (gcnew System::Windows::Forms::Button());
			this->bAddSystemBook = (gcnew System::Windows::Forms::Button());
			this->dgvSystemBooks = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cbSystems = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tpIntegrationSchemas = (gcnew System::Windows::Forms::TabPage());
			this->bEditSchema = (gcnew System::Windows::Forms::Button());
			this->bAddSchema = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dgvSchemas = (gcnew System::Windows::Forms::DataGridView());
			this->SchemaIdCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SchemaBookNameCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SchemaSourceCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SchemaTargetCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SchemaDirectionCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tpBooks->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvBooks))->BeginInit();
			this->tpSystems->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSystems))->BeginInit();
			this->tpIntegrBook->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSystemBooks))->BeginInit();
			this->tpIntegrationSchemas->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSchemas))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel1->Controls->Add(this->bCancel);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 294);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(737, 57);
			this->panel1->TabIndex = 1;
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(650, 16);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 1;
			this->bCancel->Text = L"Закрыть";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &SettingsForm::bCancel_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tpBooks);
			this->tabControl1->Controls->Add(this->tpSystems);
			this->tabControl1->Controls->Add(this->tpIntegrBook);
			this->tabControl1->Controls->Add(this->tpIntegrationSchemas);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->Padding = System::Drawing::Point(10, 5);
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(737, 294);
			this->tabControl1->TabIndex = 2;
			// 
			// tpBooks
			// 
			this->tpBooks->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tpBooks->Controls->Add(this->button1);
			this->tpBooks->Controls->Add(this->label1);
			this->tpBooks->Controls->Add(this->dgvBooks);
			this->tpBooks->Controls->Add(this->button2);
			this->tpBooks->Controls->Add(this->label4);
			this->tpBooks->Controls->Add(this->dataGridView1);
			this->tpBooks->Controls->Add(this->bEditBook);
			this->tpBooks->Controls->Add(this->groupBox1);
			this->tpBooks->Location = System::Drawing::Point(4, 26);
			this->tpBooks->Name = L"tpBooks";
			this->tpBooks->Padding = System::Windows::Forms::Padding(3);
			this->tpBooks->Size = System::Drawing::Size(729, 264);
			this->tpBooks->TabIndex = 0;
			this->tpBooks->Text = L"Списки справочников и систем";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(223, 17);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 26);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Добавить/изменитьДобавить/изменить";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(567, 17);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 26);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Добавить/изменитьДобавить/изменить";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 24);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Созданные системы:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->dataGridViewTextBoxColumn1, 
				this->dataGridViewTextBoxColumn2});
			this->dataGridView1->Location = System::Drawing::Point(19, 56);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(324, 193);
			this->dataGridView1->TabIndex = 6;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Visible = false;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Наименование";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Width = 280;
			// 
			// bEditBook
			// 
			this->bEditBook->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bEditBook->Location = System::Drawing::Point(367, 151);
			this->bEditBook->Name = L"bEditBook";
			this->bEditBook->Size = System::Drawing::Size(186, 37);
			this->bEditBook->TabIndex = 2;
			this->bEditBook->Text = L"Изменить ";
			this->bEditBook->UseVisualStyleBackColor = false;
			this->bEditBook->Click += gcnew System::EventHandler(this, &SettingsForm::bEditBook_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->bAddBook);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->tbBookName);
			this->groupBox1->Location = System::Drawing::Point(457, 82);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(194, 53);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Добавить справочник";
			// 
			// bAddBook
			// 
			this->bAddBook->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddBook->Enabled = false;
			this->bAddBook->ForeColor = System::Drawing::Color::Black;
			this->bAddBook->Location = System::Drawing::Point(127, 61);
			this->bAddBook->Name = L"bAddBook";
			this->bAddBook->Size = System::Drawing::Size(103, 37);
			this->bAddBook->TabIndex = 2;
			this->bAddBook->Text = L"Добавить";
			this->bAddBook->UseVisualStyleBackColor = false;
			this->bAddBook->Click += gcnew System::EventHandler(this, &SettingsForm::bAddBook_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Наименование";
			// 
			// tbBookName
			// 
			this->tbBookName->Location = System::Drawing::Point(27, 35);
			this->tbBookName->Name = L"tbBookName";
			this->tbBookName->Size = System::Drawing::Size(300, 20);
			this->tbBookName->TabIndex = 0;
			this->tbBookName->TextChanged += gcnew System::EventHandler(this, &SettingsForm::tbBookName_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(363, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(135, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Созданные справочники:";
			// 
			// dgvBooks
			// 
			this->dgvBooks->AllowUserToAddRows = false;
			this->dgvBooks->AllowUserToDeleteRows = false;
			this->dgvBooks->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvBooks->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvBooks->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->BookIdCol, this->BookNameCol});
			this->dgvBooks->Location = System::Drawing::Point(363, 56);
			this->dgvBooks->Name = L"dgvBooks";
			this->dgvBooks->ReadOnly = true;
			this->dgvBooks->Size = System::Drawing::Size(324, 193);
			this->dgvBooks->TabIndex = 0;
			// 
			// BookIdCol
			// 
			this->BookIdCol->HeaderText = L"Id";
			this->BookIdCol->Name = L"BookIdCol";
			this->BookIdCol->ReadOnly = true;
			this->BookIdCol->Visible = false;
			// 
			// BookNameCol
			// 
			this->BookNameCol->HeaderText = L"Наименование";
			this->BookNameCol->Name = L"BookNameCol";
			this->BookNameCol->ReadOnly = true;
			this->BookNameCol->Width = 280;
			// 
			// tpSystems
			// 
			this->tpSystems->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tpSystems->Controls->Add(this->bEditSystem);
			this->tpSystems->Controls->Add(this->groupBox4);
			this->tpSystems->Controls->Add(this->label6);
			this->tpSystems->Controls->Add(this->dgvSystems);
			this->tpSystems->Location = System::Drawing::Point(4, 26);
			this->tpSystems->Name = L"tpSystems";
			this->tpSystems->Padding = System::Windows::Forms::Padding(3);
			this->tpSystems->Size = System::Drawing::Size(729, 264);
			this->tpSystems->TabIndex = 1;
			this->tpSystems->Text = L"Системы";
			// 
			// bEditSystem
			// 
			this->bEditSystem->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bEditSystem->Location = System::Drawing::Point(362, 153);
			this->bEditSystem->Name = L"bEditSystem";
			this->bEditSystem->Size = System::Drawing::Size(186, 37);
			this->bEditSystem->TabIndex = 2;
			this->bEditSystem->Text = L"Изменить";
			this->bEditSystem->UseVisualStyleBackColor = false;
			this->bEditSystem->Click += gcnew System::EventHandler(this, &SettingsForm::bEditSystem_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->bAddSystem);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Controls->Add(this->tbSystemName);
			this->groupBox4->Location = System::Drawing::Point(362, 22);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(349, 114);
			this->groupBox4->TabIndex = 6;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Добавить систему";
			// 
			// bAddSystem
			// 
			this->bAddSystem->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddSystem->Enabled = false;
			this->bAddSystem->Location = System::Drawing::Point(127, 61);
			this->bAddSystem->Name = L"bAddSystem";
			this->bAddSystem->Size = System::Drawing::Size(103, 37);
			this->bAddSystem->TabIndex = 2;
			this->bAddSystem->Text = L"Добавить";
			this->bAddSystem->UseVisualStyleBackColor = false;
			this->bAddSystem->Click += gcnew System::EventHandler(this, &SettingsForm::bAddSystem_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(24, 19);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(83, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Наименование";
			// 
			// tbSystemName
			// 
			this->tbSystemName->Location = System::Drawing::Point(27, 35);
			this->tbSystemName->Name = L"tbSystemName";
			this->tbSystemName->Size = System::Drawing::Size(300, 20);
			this->tbSystemName->TabIndex = 0;
			this->tbSystemName->TextChanged += gcnew System::EventHandler(this, &SettingsForm::tbSystemName_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(18, 22);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(115, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Созданные системы:";
			// 
			// dgvSystems
			// 
			this->dgvSystems->AllowUserToAddRows = false;
			this->dgvSystems->AllowUserToDeleteRows = false;
			this->dgvSystems->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvSystems->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSystems->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->SystemIdCol, 
				this->SystemName});
			this->dgvSystems->Location = System::Drawing::Point(18, 41);
			this->dgvSystems->Name = L"dgvSystems";
			this->dgvSystems->ReadOnly = true;
			this->dgvSystems->Size = System::Drawing::Size(324, 206);
			this->dgvSystems->TabIndex = 4;
			// 
			// SystemIdCol
			// 
			this->SystemIdCol->HeaderText = L"ID";
			this->SystemIdCol->Name = L"SystemIdCol";
			this->SystemIdCol->ReadOnly = true;
			this->SystemIdCol->Visible = false;
			// 
			// SystemName
			// 
			this->SystemName->HeaderText = L"Наименование";
			this->SystemName->Name = L"SystemName";
			this->SystemName->ReadOnly = true;
			this->SystemName->Width = 280;
			// 
			// tpIntegrBook
			// 
			this->tpIntegrBook->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tpIntegrBook->Controls->Add(this->bEditSystemBook);
			this->tpIntegrBook->Controls->Add(this->bAddSystemBook);
			this->tpIntegrBook->Controls->Add(this->dgvSystemBooks);
			this->tpIntegrBook->Controls->Add(this->cbSystems);
			this->tpIntegrBook->Controls->Add(this->label3);
			this->tpIntegrBook->Location = System::Drawing::Point(4, 26);
			this->tpIntegrBook->Name = L"tpIntegrBook";
			this->tpIntegrBook->Padding = System::Windows::Forms::Padding(3);
			this->tpIntegrBook->Size = System::Drawing::Size(729, 264);
			this->tpIntegrBook->TabIndex = 3;
			this->tpIntegrBook->Text = L"Системные справочники";
			// 
			// bEditSystemBook
			// 
			this->bEditSystemBook->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bEditSystemBook->Location = System::Drawing::Point(533, 36);
			this->bEditSystemBook->Name = L"bEditSystemBook";
			this->bEditSystemBook->Size = System::Drawing::Size(75, 23);
			this->bEditSystemBook->TabIndex = 5;
			this->bEditSystemBook->Text = L"Изменить";
			this->bEditSystemBook->UseVisualStyleBackColor = false;
			// 
			// bAddSystemBook
			// 
			this->bAddSystemBook->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddSystemBook->Location = System::Drawing::Point(625, 36);
			this->bAddSystemBook->Name = L"bAddSystemBook";
			this->bAddSystemBook->Size = System::Drawing::Size(75, 23);
			this->bAddSystemBook->TabIndex = 4;
			this->bAddSystemBook->Text = L"Добавить";
			this->bAddSystemBook->UseVisualStyleBackColor = false;
			this->bAddSystemBook->Click += gcnew System::EventHandler(this, &SettingsForm::bAddSystemBook_Click);
			// 
			// dgvSystemBooks
			// 
			this->dgvSystemBooks->AllowUserToAddRows = false;
			this->dgvSystemBooks->AllowUserToDeleteRows = false;
			this->dgvSystemBooks->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvSystemBooks->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSystemBooks->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Column1, 
				this->Column2, this->Column3});
			this->dgvSystemBooks->Location = System::Drawing::Point(26, 85);
			this->dgvSystemBooks->Name = L"dgvSystemBooks";
			this->dgvSystemBooks->ReadOnly = true;
			this->dgvSystemBooks->RowHeadersVisible = false;
			this->dgvSystemBooks->Size = System::Drawing::Size(675, 150);
			this->dgvSystemBooks->TabIndex = 2;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Наименование справочника";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 250;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Наименование атрибута идентификатора";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 200;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Наименование основоного атрибута";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 200;
			// 
			// cbSystems
			// 
			this->cbSystems->FormattingEnabled = true;
			this->cbSystems->Location = System::Drawing::Point(26, 36);
			this->cbSystems->Name = L"cbSystems";
			this->cbSystems->Size = System::Drawing::Size(166, 21);
			this->cbSystems->TabIndex = 1;
			this->cbSystems->SelectedIndexChanged += gcnew System::EventHandler(this, &SettingsForm::cbSystems_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Система:";
			// 
			// tpIntegrationSchemas
			// 
			this->tpIntegrationSchemas->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tpIntegrationSchemas->Controls->Add(this->bEditSchema);
			this->tpIntegrationSchemas->Controls->Add(this->bAddSchema);
			this->tpIntegrationSchemas->Controls->Add(this->label7);
			this->tpIntegrationSchemas->Controls->Add(this->dgvSchemas);
			this->tpIntegrationSchemas->Location = System::Drawing::Point(4, 26);
			this->tpIntegrationSchemas->Name = L"tpIntegrationSchemas";
			this->tpIntegrationSchemas->Padding = System::Windows::Forms::Padding(3);
			this->tpIntegrationSchemas->Size = System::Drawing::Size(729, 264);
			this->tpIntegrationSchemas->TabIndex = 2;
			this->tpIntegrationSchemas->Text = L"Интеграционные схемы";
			this->tpIntegrationSchemas->Enter += gcnew System::EventHandler(this, &SettingsForm::tpIntegrationSchemas_Enter);
			// 
			// bEditSchema
			// 
			this->bEditSchema->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bEditSchema->Location = System::Drawing::Point(533, 10);
			this->bEditSchema->Name = L"bEditSchema";
			this->bEditSchema->Size = System::Drawing::Size(75, 23);
			this->bEditSchema->TabIndex = 3;
			this->bEditSchema->Text = L"Изменить";
			this->bEditSchema->UseVisualStyleBackColor = false;
			this->bEditSchema->Click += gcnew System::EventHandler(this, &SettingsForm::bEditSchema_Click);
			// 
			// bAddSchema
			// 
			this->bAddSchema->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddSchema->Location = System::Drawing::Point(625, 10);
			this->bAddSchema->Name = L"bAddSchema";
			this->bAddSchema->Size = System::Drawing::Size(75, 23);
			this->bAddSchema->TabIndex = 2;
			this->bAddSchema->Text = L"Добавить";
			this->bAddSchema->UseVisualStyleBackColor = false;
			this->bAddSchema->Click += gcnew System::EventHandler(this, &SettingsForm::bAddSchema_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(22, 15);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(103, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Созданные схемы:";
			// 
			// dgvSchemas
			// 
			this->dgvSchemas->AllowUserToAddRows = false;
			this->dgvSchemas->AllowUserToDeleteRows = false;
			this->dgvSchemas->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvSchemas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSchemas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->SchemaIdCol, 
				this->SchemaBookNameCol, this->SchemaSourceCol, this->SchemaTargetCol, this->SchemaDirectionCol});
			this->dgvSchemas->Location = System::Drawing::Point(25, 42);
			this->dgvSchemas->Name = L"dgvSchemas";
			this->dgvSchemas->ReadOnly = true;
			this->dgvSchemas->RowHeadersWidth = 25;
			this->dgvSchemas->Size = System::Drawing::Size(675, 199);
			this->dgvSchemas->TabIndex = 0;
			// 
			// SchemaIdCol
			// 
			this->SchemaIdCol->HeaderText = L"ID";
			this->SchemaIdCol->Name = L"SchemaIdCol";
			this->SchemaIdCol->ReadOnly = true;
			this->SchemaIdCol->Visible = false;
			// 
			// SchemaBookNameCol
			// 
			this->SchemaBookNameCol->HeaderText = L"Справочник";
			this->SchemaBookNameCol->Name = L"SchemaBookNameCol";
			this->SchemaBookNameCol->ReadOnly = true;
			this->SchemaBookNameCol->Width = 260;
			// 
			// SchemaSourceCol
			// 
			this->SchemaSourceCol->HeaderText = L"Система-источник";
			this->SchemaSourceCol->Name = L"SchemaSourceCol";
			this->SchemaSourceCol->ReadOnly = true;
			this->SchemaSourceCol->Width = 140;
			// 
			// SchemaTargetCol
			// 
			this->SchemaTargetCol->HeaderText = L"Система-получатель";
			this->SchemaTargetCol->Name = L"SchemaTargetCol";
			this->SchemaTargetCol->ReadOnly = true;
			this->SchemaTargetCol->Width = 140;
			// 
			// SchemaDirectionCol
			// 
			this->SchemaDirectionCol->HeaderText = L"Направление интеграции";
			this->SchemaDirectionCol->Name = L"SchemaDirectionCol";
			this->SchemaDirectionCol->ReadOnly = true;
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::GhostWhite;
			this->ClientSize = System::Drawing::Size(737, 351);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Настройки";
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			this->panel1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tpBooks->ResumeLayout(false);
			this->tpBooks->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvBooks))->EndInit();
			this->tpSystems->ResumeLayout(false);
			this->tpSystems->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSystems))->EndInit();
			this->tpIntegrBook->ResumeLayout(false);
			this->tpIntegrBook->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSystemBooks))->EndInit();
			this->tpIntegrationSchemas->ResumeLayout(false);
			this->tpIntegrationSchemas->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSchemas))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		private:
			Void SetBooks(array<String^, 2>^ list)
			{
				SetList(list, dgvBooks);
			}

			Void SetSystems(array<String^, 2>^ list)
			{
				SetList(list, dataGridView1);
			}

			Void SetSystemsToSystemBooks(array<String^, 2>^ list)
			{
				cbSystems->Items->Clear();
				for(int i = 0; i < list->GetLength(0); i++)
				{
					cbSystems->Items->Add(list[i,1]);
				}
			}

			Void SetList(array<String^, 2>^ list, DataGridView^ grid)
			{
				grid->Rows->Clear();
				for (int i = 0; i < list->GetLength(0); i++)
				{
					array<String^>^ row = gcnew array<String ^>(2);
					row[0] = list[i,0];
					row[1] = list[i,1];
					grid->Rows->Add(row);
				}
			}

			Void SetShemas(List<IntegrationSettings^>^ settings)
			{
				dgvSchemas->Rows->Clear();
				for each (IntegrationSettings^ setting in settings)
				{
					array<String^>^ row = gcnew array<String ^>(5);
					row[0] = setting->Id + "";
					row[1] = setting->SourceBook->BookName;
					row[2] = setting->SourceBook->SystemName;
					row[3] = setting->TargetBook->SystemName;
					if (setting->Type == IntegrationSettings::IntegrationType::OneWay)
					{
						row[4] = "One";
					} 
					else
					{
						row[4] = "Dual";
					}
					dgvSchemas->Rows->Add(row);
				}
			}

			void SetRoles()
			{
				tabControl1->TabPages->Remove(tpSystems);
				if (RoleStation::AddEditBookHidden())
				{
					tabControl1->TabPages->Remove(tpBooks);
				}
				else
				{
					SetBooks(_settings->Books);
				}
				if (RoleStation::AddEditSystemHidden())
				{
					tabControl1->TabPages->Remove(tpSystems);
				}
				else
				{
					SetSystems(_settings->Systems);
				}
				if (RoleStation::AddNewIntegrSchemaHidden())
				{
					bAddSchema->Visible = false;
				}
				if (RoleStation::AddSystemBookHidden())
				{
					bAddSystemBook->Visible = false;
				}
			}

			void SetSystemBooks(String^ systemName)
			{
				dgvSystemBooks->Rows->Clear();
				_currentSystemBooks = _settings->GetSystemBooks(systemName);
				for(int i = 0; i < _currentSystemBooks->GetLength(0); i++)
				{
					array<String^>^ row = gcnew array<String ^>(3);
					row[0] = _currentSystemBooks[i, 0];
					row[1] = _currentSystemBooks[i, 1];
					row[2] = _currentSystemBooks[i, 2];
					dgvSystemBooks->Rows->Add(row);
				}
			}

private: System::Void SettingsForm_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 _settings = gcnew Settings(_odbc);
			 SetSystemsToSystemBooks(_settings->Systems);
			 SetRoles();
		 }
private: System::Void tbBookName_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (String::IsNullOrEmpty(tbBookName->Text))
			 {
				 bAddBook->Enabled = false;
			 }
			 else
			 {
				 bAddBook->Enabled = true;
			 }
		 }
private: System::Void bAddBook_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 bool result = _settings->AddBook(tbBookName->Text->Trim());
			 if (result)
			 {
				 SetBooks(_settings->Books);
				 tbBookName->Text = "";
				 MessageBox::Show("Справочник добавлен!");
			 }
			 else
			 {
				 MessageBox::Show("Справочник уже существует!");
			 }
		 }
private: System::Void bEditBook_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			  Object^ value = dgvBooks->Rows[dgvBooks->CurrentCell->RowIndex]->Cells[0]->Value;
			  Object^ name = dgvBooks->Rows[dgvBooks->CurrentCell->RowIndex]->Cells[1]->Value;
			  EditForm^ form = gcnew EditForm(value, name->ToString(), 0, _odbc);
			  form->ShowDialog();
			  SetBooks(_settings->Books);
		 }
private: System::Void tbSystemName_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (String::IsNullOrEmpty(tbSystemName->Text))
			 {
				 bAddSystem->Enabled = false;
			 }
			 else
			 {
				 bAddSystem->Enabled = true;
			 }
		 }
private: System::Void bAddSystem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 bool result = _settings->AddSystem(tbSystemName->Text->Trim());
			 if (result)
			 {
				 SetSystems(_settings->Systems);
				 tbSystemName->Text = "";
				 MessageBox::Show("Система добавлена!");
			 }
			 else
			 {
				 MessageBox::Show("Система уже существует!");
			 }
		 }
private: System::Void bEditSystem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Object^ value = dgvSystems->Rows[dgvSystems->CurrentCell->RowIndex]->Cells[0]->Value;
			 Object^ name = dgvSystems->Rows[dgvSystems->CurrentCell->RowIndex]->Cells[1]->Value;
			 EditForm^ form = gcnew EditForm(value, name->ToString(), 1, _odbc);
			 form->ShowDialog();
			 SetSystems(_settings->Systems);
		 }
private: System::Void tpIntegrationSchemas_Enter(System::Object^  sender, System::EventArgs^  e) 
		 {
			 List<Object^>^ integrationIds = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "INTEGRATION_PARAMS");
			 List<IntegrationSettings^>^ inegrationSettings = gcnew List<IntegrationSettings^>();
			 for each (Object^ id in integrationIds)
			 {
				 IntegrationSettings^ settings = gcnew IntegrationSettings(Decimal::ToInt32((Decimal)id), _odbc);
				 inegrationSettings->Add(settings);
			 }
			 SetShemas(inegrationSettings);
		 }
private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void bAddSchema_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //AddEditSchemaForm^ form = gcnew AddEditSchemaForm(_settings);
			 AddEditSchemaForm2^ form = gcnew AddEditSchemaForm2(_settings, _odbc);
			 form->ShowDialog();
		 }
private: System::Void bEditSchema_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

		 }
private: System::Void cbSystems_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetSystemBooks(cbSystems->SelectedItem->ToString());
		 }
private: System::Void bAddSystemBook_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 AddEditSystemBookForm^ form = gcnew AddEditSystemBookForm(_settings, _odbc);
			 form->ShowDialog();
			 if (cbSystems->SelectedItem != nullptr)
			 {
				 SetSystemBooks(cbSystems->SelectedItem->ToString());
			 }
		 }
};
}
