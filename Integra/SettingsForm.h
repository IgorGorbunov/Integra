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
	private: System::Windows::Forms::TabPage^  tpIntegrBook;
	private: System::Windows::Forms::DataGridView^  dgvSystemBooks;
	private: System::Windows::Forms::ComboBox^  cbSystems;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  bDeleteSystemBook;
	private: System::Windows::Forms::Button^  bAddSystemBook;
	private: System::Windows::Forms::Button^  bEditSystem2;
	private: System::Windows::Forms::Button^  bDeleteSystem2;
	private: System::Windows::Forms::Button^  bEditBook2;
	private: System::Windows::Forms::Button^  bDeleteBook2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SchemaIdCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SchemaBookNameCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SchemaSourceCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SchemaTargetCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SchemaDirectionCol;
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
	private: System::Windows::Forms::Button^  bDelSchema;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::Button^  bAddNewBook;
	private: System::Windows::Forms::Button^  bAddNewSystem;



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
			this->bEditBook2 = (gcnew System::Windows::Forms::Button());
			this->bDeleteBook2 = (gcnew System::Windows::Forms::Button());
			this->bEditSystem2 = (gcnew System::Windows::Forms::Button());
			this->bDeleteSystem2 = (gcnew System::Windows::Forms::Button());
			this->bAddNewBook = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dgvBooks = (gcnew System::Windows::Forms::DataGridView());
			this->BookIdCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BookNameCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bAddNewSystem = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bEditBook = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->bAddBook = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbBookName = (gcnew System::Windows::Forms::TextBox());
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
			this->bDeleteSystemBook = (gcnew System::Windows::Forms::Button());
			this->bAddSystemBook = (gcnew System::Windows::Forms::Button());
			this->dgvSystemBooks = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cbSystems = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tpIntegrationSchemas = (gcnew System::Windows::Forms::TabPage());
			this->bDelSchema = (gcnew System::Windows::Forms::Button());
			this->bAddSchema = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dgvSchemas = (gcnew System::Windows::Forms::DataGridView());
			this->SchemaIdCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SchemaBookNameCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SchemaSourceCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SchemaTargetCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SchemaDirectionCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tpBooks->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvBooks))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
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
			this->panel1->Location = System::Drawing::Point(0, 332);
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
			this->tabControl1->Size = System::Drawing::Size(737, 332);
			this->tabControl1->TabIndex = 2;
			this->tabControl1->Enter += gcnew System::EventHandler(this, &SettingsForm::tabControl1_Enter);
			// 
			// tpBooks
			// 
			this->tpBooks->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tpBooks->Controls->Add(this->bEditBook2);
			this->tpBooks->Controls->Add(this->bDeleteBook2);
			this->tpBooks->Controls->Add(this->bEditSystem2);
			this->tpBooks->Controls->Add(this->bDeleteSystem2);
			this->tpBooks->Controls->Add(this->bAddNewBook);
			this->tpBooks->Controls->Add(this->label1);
			this->tpBooks->Controls->Add(this->dgvBooks);
			this->tpBooks->Controls->Add(this->bAddNewSystem);
			this->tpBooks->Controls->Add(this->label4);
			this->tpBooks->Controls->Add(this->dataGridView1);
			this->tpBooks->Controls->Add(this->bEditBook);
			this->tpBooks->Controls->Add(this->groupBox1);
			this->tpBooks->Location = System::Drawing::Point(4, 26);
			this->tpBooks->Name = L"tpBooks";
			this->tpBooks->Padding = System::Windows::Forms::Padding(3);
			this->tpBooks->Size = System::Drawing::Size(729, 302);
			this->tpBooks->TabIndex = 0;
			this->tpBooks->Text = L"Списки справочников и систем";
			// 
			// bEditBook2
			// 
			this->bEditBook2->Location = System::Drawing::Point(476, 255);
			this->bEditBook2->Name = L"bEditBook2";
			this->bEditBook2->Size = System::Drawing::Size(98, 26);
			this->bEditBook2->TabIndex = 13;
			this->bEditBook2->Text = L"Изменить";
			this->bEditBook2->UseVisualStyleBackColor = true;
			this->bEditBook2->Click += gcnew System::EventHandler(this, &SettingsForm::bEditBook2_Click);
			// 
			// bDeleteBook2
			// 
			this->bDeleteBook2->Location = System::Drawing::Point(589, 255);
			this->bDeleteBook2->Name = L"bDeleteBook2";
			this->bDeleteBook2->Size = System::Drawing::Size(98, 26);
			this->bDeleteBook2->TabIndex = 12;
			this->bDeleteBook2->Text = L"Удалить";
			this->bDeleteBook2->UseVisualStyleBackColor = true;
			this->bDeleteBook2->Click += gcnew System::EventHandler(this, &SettingsForm::bDeleteBook2_Click);
			// 
			// bEditSystem2
			// 
			this->bEditSystem2->Location = System::Drawing::Point(132, 255);
			this->bEditSystem2->Name = L"bEditSystem2";
			this->bEditSystem2->Size = System::Drawing::Size(98, 26);
			this->bEditSystem2->TabIndex = 11;
			this->bEditSystem2->Text = L"Изменить";
			this->bEditSystem2->UseVisualStyleBackColor = true;
			this->bEditSystem2->Click += gcnew System::EventHandler(this, &SettingsForm::bEditSystem2_Click);
			// 
			// bDeleteSystem2
			// 
			this->bDeleteSystem2->Location = System::Drawing::Point(245, 255);
			this->bDeleteSystem2->Name = L"bDeleteSystem2";
			this->bDeleteSystem2->Size = System::Drawing::Size(98, 26);
			this->bDeleteSystem2->TabIndex = 10;
			this->bDeleteSystem2->Text = L"Удалить";
			this->bDeleteSystem2->UseVisualStyleBackColor = true;
			this->bDeleteSystem2->Click += gcnew System::EventHandler(this, &SettingsForm::bDeleteSystem2_Click);
			// 
			// bAddNewBook
			// 
			this->bAddNewBook->Location = System::Drawing::Point(363, 255);
			this->bAddNewBook->Name = L"bAddNewBook";
			this->bAddNewBook->Size = System::Drawing::Size(95, 26);
			this->bAddNewBook->TabIndex = 8;
			this->bAddNewBook->Text = L"Добавить";
			this->bAddNewBook->UseVisualStyleBackColor = true;
			this->bAddNewBook->Click += gcnew System::EventHandler(this, &SettingsForm::bAddNewBook_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(363, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(183, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Добавленные типы справочников:";
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
			this->dgvBooks->RowHeadersVisible = false;
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
			// bAddNewSystem
			// 
			this->bAddNewSystem->Location = System::Drawing::Point(19, 255);
			this->bAddNewSystem->Name = L"bAddNewSystem";
			this->bAddNewSystem->Size = System::Drawing::Size(98, 26);
			this->bAddNewSystem->TabIndex = 9;
			this->bAddNewSystem->Text = L"Добавить";
			this->bAddNewSystem->UseVisualStyleBackColor = true;
			this->bAddNewSystem->Click += gcnew System::EventHandler(this, &SettingsForm::bAddNewSystem_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 24);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(129, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Добавленные системы:";
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
			this->dataGridView1->RowHeadersVisible = false;
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
			this->tpSystems->Size = System::Drawing::Size(729, 302);
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
			this->tpIntegrBook->Controls->Add(this->bDeleteSystemBook);
			this->tpIntegrBook->Controls->Add(this->bAddSystemBook);
			this->tpIntegrBook->Controls->Add(this->dgvSystemBooks);
			this->tpIntegrBook->Controls->Add(this->cbSystems);
			this->tpIntegrBook->Controls->Add(this->label3);
			this->tpIntegrBook->Location = System::Drawing::Point(4, 26);
			this->tpIntegrBook->Name = L"tpIntegrBook";
			this->tpIntegrBook->Padding = System::Windows::Forms::Padding(3);
			this->tpIntegrBook->Size = System::Drawing::Size(729, 302);
			this->tpIntegrBook->TabIndex = 3;
			this->tpIntegrBook->Text = L"Декларированные справочники";
			this->tpIntegrBook->Enter += gcnew System::EventHandler(this, &SettingsForm::tpIntegrBook_Enter);
			// 
			// bDeleteSystemBook
			// 
			this->bDeleteSystemBook->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bDeleteSystemBook->Location = System::Drawing::Point(626, 20);
			this->bDeleteSystemBook->Name = L"bDeleteSystemBook";
			this->bDeleteSystemBook->Size = System::Drawing::Size(75, 23);
			this->bDeleteSystemBook->TabIndex = 5;
			this->bDeleteSystemBook->Text = L"Удалить";
			this->bDeleteSystemBook->UseVisualStyleBackColor = false;
			this->bDeleteSystemBook->Click += gcnew System::EventHandler(this, &SettingsForm::bDeleteSystemBook_Click);
			// 
			// bAddSystemBook
			// 
			this->bAddSystemBook->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddSystemBook->Location = System::Drawing::Point(545, 20);
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
			this->dgvSystemBooks->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->Column1, 
				this->Column2, this->Column4, this->Column3});
			this->dgvSystemBooks->Location = System::Drawing::Point(26, 49);
			this->dgvSystemBooks->Name = L"dgvSystemBooks";
			this->dgvSystemBooks->ReadOnly = true;
			this->dgvSystemBooks->RowHeadersVisible = false;
			this->dgvSystemBooks->Size = System::Drawing::Size(675, 229);
			this->dgvSystemBooks->TabIndex = 2;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Номер справочника";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Visible = false;
			this->Column1->Width = 250;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Наименование справочника";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 260;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Тип справочника";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 230;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Система";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 150;
			// 
			// cbSystems
			// 
			this->cbSystems->FormattingEnabled = true;
			this->cbSystems->Location = System::Drawing::Point(26, 36);
			this->cbSystems->Name = L"cbSystems";
			this->cbSystems->Size = System::Drawing::Size(166, 21);
			this->cbSystems->TabIndex = 1;
			this->cbSystems->Visible = false;
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
			this->label3->Visible = false;
			// 
			// tpIntegrationSchemas
			// 
			this->tpIntegrationSchemas->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tpIntegrationSchemas->Controls->Add(this->bDelSchema);
			this->tpIntegrationSchemas->Controls->Add(this->bAddSchema);
			this->tpIntegrationSchemas->Controls->Add(this->label7);
			this->tpIntegrationSchemas->Controls->Add(this->dgvSchemas);
			this->tpIntegrationSchemas->Location = System::Drawing::Point(4, 26);
			this->tpIntegrationSchemas->Name = L"tpIntegrationSchemas";
			this->tpIntegrationSchemas->Padding = System::Windows::Forms::Padding(3);
			this->tpIntegrationSchemas->Size = System::Drawing::Size(729, 302);
			this->tpIntegrationSchemas->TabIndex = 2;
			this->tpIntegrationSchemas->Text = L"Интеграционные схемы";
			this->tpIntegrationSchemas->Enter += gcnew System::EventHandler(this, &SettingsForm::tpIntegrationSchemas_Enter);
			// 
			// bDelSchema
			// 
			this->bDelSchema->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bDelSchema->Location = System::Drawing::Point(625, 10);
			this->bDelSchema->Name = L"bDelSchema";
			this->bDelSchema->Size = System::Drawing::Size(75, 23);
			this->bDelSchema->TabIndex = 3;
			this->bDelSchema->Text = L"Удалить";
			this->bDelSchema->UseVisualStyleBackColor = false;
			this->bDelSchema->Click += gcnew System::EventHandler(this, &SettingsForm::bDelSchema_Click);
			// 
			// bAddSchema
			// 
			this->bAddSchema->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddSchema->Location = System::Drawing::Point(544, 10);
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
			this->dgvSchemas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->SchemaIdCol, 
				this->Column5, this->SchemaBookNameCol, this->Column6, this->SchemaSourceCol, this->Column7, this->SchemaTargetCol, this->SchemaDirectionCol});
			this->dgvSchemas->Location = System::Drawing::Point(8, 42);
			this->dgvSchemas->Name = L"dgvSchemas";
			this->dgvSchemas->ReadOnly = true;
			this->dgvSchemas->RowHeadersVisible = false;
			this->dgvSchemas->RowHeadersWidth = 25;
			this->dgvSchemas->Size = System::Drawing::Size(713, 243);
			this->dgvSchemas->TabIndex = 0;
			// 
			// SchemaIdCol
			// 
			this->SchemaIdCol->HeaderText = L"ID";
			this->SchemaIdCol->Name = L"SchemaIdCol";
			this->SchemaIdCol->ReadOnly = true;
			this->SchemaIdCol->Visible = false;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Наименование";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 200;
			// 
			// SchemaBookNameCol
			// 
			this->SchemaBookNameCol->HeaderText = L"Тип справочника";
			this->SchemaBookNameCol->Name = L"SchemaBookNameCol";
			this->SchemaBookNameCol->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Справочник-источник";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 120;
			// 
			// SchemaSourceCol
			// 
			this->SchemaSourceCol->HeaderText = L"Система-источник";
			this->SchemaSourceCol->Name = L"SchemaSourceCol";
			this->SchemaSourceCol->ReadOnly = true;
			this->SchemaSourceCol->Width = 120;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Справочник-получатель";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Width = 120;
			// 
			// SchemaTargetCol
			// 
			this->SchemaTargetCol->HeaderText = L"Система-получатель";
			this->SchemaTargetCol->Name = L"SchemaTargetCol";
			this->SchemaTargetCol->ReadOnly = true;
			this->SchemaTargetCol->Width = 120;
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
			this->ClientSize = System::Drawing::Size(737, 389);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Настройки справочников";
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			this->panel1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tpBooks->ResumeLayout(false);
			this->tpBooks->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvBooks))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
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

			Void SetShemaDgv(List<IntegrationSettings^>^ settings)
			{
				dgvSchemas->Rows->Clear();
				for each (IntegrationSettings^ setting in settings)
				{
					array<Object^>^ row = gcnew array<Object ^>(8);
					row[0] = setting->Id;
					row[1] = setting->Name;
					row[2] = setting->SourceBook->BookName;
					row[3] = setting->SourceBook->Name;
					row[4] = setting->SourceBook->SystemName;
					row[5] = setting->TargetBook->Name;
					row[6] = setting->TargetBook->SystemName;
					if (setting->Type == IntegrationSettings::IntegrationType::OneWay)
					{
						row[7] = "Односторонняя";
					} 
					else
					{
						row[7] = "Двусторонняя";
					}
					dgvSchemas->Rows->Add(row);
				}
			}

			void SetShemas()
			{
				List<Object^>^ integrationIds = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "INTEGRATION_PARAMS");
				List<IntegrationSettings^>^ inegrationSettings = gcnew List<IntegrationSettings^>();
				for each (Object^ id in integrationIds)
				{
					IntegrationSettings^ settings = gcnew IntegrationSettings(_odbc->GetResInt(id), _odbc);
					inegrationSettings->Add(settings);
				}
				SetShemaDgv(inegrationSettings);
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
				if (String::IsNullOrEmpty(systemName))
				{
					_currentSystemBooks = _settings->GetSystemBooks();
				}
				else
				{
					_currentSystemBooks = _settings->GetSystemBooks(systemName);
				}
				
				for(int i = 0; i < _currentSystemBooks->GetLength(0); i++)
				{
					array<String^>^ row = gcnew array<String ^>(4);
					row[0] = _currentSystemBooks[i, 0];
					row[1] = _currentSystemBooks[i, 1];
					row[2] = _currentSystemBooks[i, 2];
					row[3] = _currentSystemBooks[i, 3];
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
			  EditForm^ form = gcnew EditForm(value, name->ToString(), 0, 1, _odbc);
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
			 EditForm^ form = gcnew EditForm(value, name->ToString(), 1, 1, _odbc);
			 form->ShowDialog();
			 SetSystems(_settings->Systems);
		 }
private: System::Void tpIntegrationSchemas_Enter(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetShemas();
		 }
private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void bAddSchema_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 AddEditSchemaForm2^ form = gcnew AddEditSchemaForm2(_settings, _odbc);
			 form->ShowDialog();
			 SetShemas();

		 }
private: System::Void bDelSchema_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dgvSchemas->CurrentCell != nullptr && dgvSchemas->CurrentCell->RowIndex >= 0)
			 {
				 System::Windows::Forms::DialogResult result = 
					 MessageBox::Show("Вы действительно хотите удалить интеграционную схему?", "Предупреждение", 
					 MessageBoxButtons::YesNoCancel, MessageBoxIcon::Warning);

				 if (result == System::Windows::Forms::DialogResult::Yes)
				 {
					 int idSchema = (int)dgvSchemas->Rows[dgvSchemas->CurrentCell->RowIndex]->Cells[0]->Value;

					 //todo update del attr, not delete
					 IntegrationGroupPair::Delete(_odbc, idSchema);
					 AttributePair::Delete(_odbc, idSchema);

					 String^ squery = String::Format("delete from {0}INTEGRATION_PARAMS IBB where IBB.ID = {1}", _odbc->schema, idSchema);
					 _odbc->ExecuteNonQuery(squery);
					 SetShemas();

				 }

			 }
		 }
private: System::Void cbSystems_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Object^ ob = cbSystems->SelectedItem;
			 if (ob == nullptr)
			 {
				 SetSystemBooks("");
			 }
			 else
			 {
				 SetSystemBooks(ob->ToString());
			 }
		 }
private: System::Void bAddSystemBook_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 AddEditSystemBookForm^ form = gcnew AddEditSystemBookForm(_settings, _odbc);
			 form->ShowDialog();
			 if (cbSystems->SelectedItem != nullptr)
			 {
				 SetSystemBooks(cbSystems->SelectedItem->ToString());
			 }
			 else
			 {
				 SetSystemBooks("");
			 }
		 }
private: System::Void tabControl1_Enter(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetSystemBooks("");
		 }

private: System::Void bAddNewBook_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 EditForm^ form = gcnew EditForm(1, _odbc);
			 form->ShowDialog();
			 SetBooks(_settings->Books);
		 }
private: System::Void bAddNewSystem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 EditForm^ form = gcnew EditForm(0, _odbc);
			 form->ShowDialog();
			 SetSystems(_settings->Systems);
		 }
private: System::Void tpIntegrBook_Enter(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetSystemBooks("");
		 }

private: System::Void bEditSystem2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dataGridView1->CurrentCell != nullptr && dataGridView1->CurrentCell->RowIndex >= 0)
			 {
				 Object^ value = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value;
				 Object^ name = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[1]->Value;
				 EditForm^ form = gcnew EditForm(value, name->ToString(), 0, 1, _odbc);
				 form->ShowDialog();
				 SetSystems(_settings->Systems);
			 }
		 }
private: System::Void bDeleteSystem2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dataGridView1->CurrentCell != nullptr && dataGridView1->CurrentCell->RowIndex >= 0)
			 {
				 Object^ value = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value;

				 String^ squery = String::Format("select NAME from {0}INTEGRATION_BOOK where ID_SYSTEM = {1}", _odbc->schema, value);
				 List<Object^>^ resList = _odbc->ExecuteQuery(squery);

				 if (resList != nullptr && resList->Count > 0)
				 {
					 String^ name = OdbcClass::GetResString(resList[0]);
					 MessageBox::Show("Выбранная система используется в декларированном справочнике \"" + name + "\". Удаление невозможно.");
					 return;
				 }
				 else
				 {
				 EditForm^ form = gcnew EditForm(value, String::Empty, 0, 2, _odbc);
				 //form->ShowDialog();
				 SetSystems(_settings->Systems);
				 }
			 }
		 }
private: System::Void bEditBook2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dgvBooks->CurrentCell != nullptr && dgvBooks->CurrentCell->RowIndex >= 0)
			 {
				 Object^ value = dgvBooks->Rows[dgvBooks->CurrentCell->RowIndex]->Cells[0]->Value;
				  Object^ name = dgvBooks->Rows[dgvBooks->CurrentCell->RowIndex]->Cells[1]->Value;
				  EditForm^ form = gcnew EditForm(value, name->ToString(), 1, 1, _odbc);
				  form->ShowDialog();
				  SetBooks(_settings->Books);
			 }
		 }
private: System::Void bDeleteBook2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dgvBooks->CurrentCell != nullptr && dgvBooks->CurrentCell->RowIndex >= 0)
			 {
				 Object^ value = dgvBooks->Rows[dgvBooks->CurrentCell->RowIndex]->Cells[0]->Value;

				 String^ squery = String::Format("select NAME from {0}INTEGRATION_BOOK where ID_BOOK = {1}", _odbc->schema, value);
				 List<Object^>^ resList = _odbc->ExecuteQuery(squery);

				 if (resList != nullptr && resList->Count > 0)
				 {
					 String^ name = OdbcClass::GetResString(resList[0]);
					 MessageBox::Show("Выбранный тип справочника используется в декларированном справочнике \"" + name + "\". Удаление невозможно.");
					 return;
				 }
				 else
				 {
				  EditForm^ form = gcnew EditForm(value, String::Empty, 1, 2, _odbc);
				  //form->ShowDialog();
				  SetBooks(_settings->Books);
				 }
			 }
		 }
private: System::Void bDeleteSystemBook_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dgvSystemBooks->CurrentCell != nullptr && dgvSystemBooks->CurrentCell->RowIndex >= 0)
			 {
				 System::Windows::Forms::DialogResult result = 
					 MessageBox::Show("Вы действительно хотите удалить декларированный справочник?", "Предупреждение", 
					 MessageBoxButtons::YesNoCancel, MessageBoxIcon::Warning);

				 if (result == System::Windows::Forms::DialogResult::Yes)
				 {
					 Object^ idBook = dgvSystemBooks->Rows[dgvSystemBooks->CurrentCell->RowIndex]->Cells[0]->Value;
					 String^ squery = String::Format("select INT_NAME from {0}INTEGRATION_PARAMS where ID_SOURCE_BOOK = {1} or ID_TARGET_BOOK = {1}", _odbc->schema, idBook);
					 List<Object^>^ resList = _odbc->ExecuteQuery(squery);

					 if (resList != nullptr && resList->Count > 0)
					 {
						 String^ intSchemaName = OdbcClass::GetResString(resList[0]);
						 MessageBox::Show("Справочник используется в интеграционной схеме \"" + intSchemaName + "\". Удаление невозможно.");
						 return;
					 }
					 else
					 {
						 squery = String::Format("delete from {0}DB_FILTERS IBB where IBB.ID_INTGR_BOOK = {1}", _odbc->schema, idBook);
						 _odbc->ExecuteNonQuery(squery);
						 squery = String::Format("delete from {0}DB_LINKS IBB where IBB.ID_INTGR_BOOK = {1}", _odbc->schema, idBook);
						 _odbc->ExecuteNonQuery(squery);
						 squery = String::Format("delete from {0}POSITION_GROUP_ATTRIBUTE_PAIRS IBB where IBB.ID_INTEGRATION_BOOK = {1}", _odbc->schema, idBook);
						 _odbc->ExecuteNonQuery(squery);
						 squery = String::Format("delete from {0}USERS_BOOKS IBB where IBB.ID_INT_BOOK = {1}", _odbc->schema, idBook);
						 _odbc->ExecuteNonQuery(squery);
						 squery = String::Format("delete from {0}INTEGRATION_ATTRIBUTES IBB where IBB.ID_INTGR_BOOK = {1}", _odbc->schema, idBook);
						 _odbc->ExecuteNonQuery(squery);
						 squery = String::Format("delete from {0}INTEGRATION_BOOK IBB where IBB.ID = {1}", _odbc->schema, idBook);
						 _odbc->ExecuteNonQuery(squery);
						 SetSystemBooks("");
					 }

				 }
			 
			 }
			 
		 }
};
}
