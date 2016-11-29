#pragma once
#include "AddGroupLinksForm.h"

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
	public:
		AddEditSchemaForm2(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataGridView^  dgvSource;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::DataGridView^  dgvTarget;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Button^  bSave;
	private: System::Windows::Forms::Button^  bLinks;

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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dgvSource = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dgvTarget = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bSave = (gcnew System::Windows::Forms::Button());
			this->bLinks = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTarget))->BeginInit();
			this->SuspendLayout();
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
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Технологических операций", L"Оборудования"});
			this->comboBox1->Location = System::Drawing::Point(20, 39);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(231, 21);
			this->comboBox1->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(22, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(588, 77);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Фильтр справочников и систем";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"САПР ТП ТЕМП2", L"Semantic"});
			this->comboBox2->Location = System::Drawing::Point(330, 39);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(231, 21);
			this->comboBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(327, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Система:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(42, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(103, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Система-источник:";
			// 
			// dgvSource
			// 
			this->dgvSource->AllowUserToAddRows = false;
			this->dgvSource->AllowUserToDeleteRows = false;
			this->dgvSource->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvSource->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSource->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Column1, this->Column2, 
				this->Column3});
			this->dgvSource->Location = System::Drawing::Point(22, 135);
			this->dgvSource->Name = L"dgvSource";
			this->dgvSource->ReadOnly = true;
			this->dgvSource->RowHeadersVisible = false;
			this->dgvSource->Size = System::Drawing::Size(432, 176);
			this->dgvSource->TabIndex = 4;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Наименование";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Справочник";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Система";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(499, 119);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(114, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Система-получатель:";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Одностороннее", L"Двустороннее"});
			this->comboBox3->Location = System::Drawing::Point(634, 63);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(231, 21);
			this->comboBox3->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(631, 47);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(90, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Тип интеграции:";
			// 
			// dgvTarget
			// 
			this->dgvTarget->AllowUserToAddRows = false;
			this->dgvTarget->AllowUserToDeleteRows = false;
			this->dgvTarget->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvTarget->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTarget->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->dataGridViewTextBoxColumn1, 
				this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3});
			this->dgvTarget->Location = System::Drawing::Point(486, 135);
			this->dgvTarget->Name = L"dgvTarget";
			this->dgvTarget->ReadOnly = true;
			this->dgvTarget->RowHeadersVisible = false;
			this->dgvTarget->Size = System::Drawing::Size(431, 176);
			this->dgvTarget->TabIndex = 6;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Наименование";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Справочник";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Система";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(842, 344);
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
			this->bSave->Location = System::Drawing::Point(745, 344);
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
			this->bLinks->Location = System::Drawing::Point(419, 317);
			this->bLinks->Name = L"bLinks";
			this->bLinks->Size = System::Drawing::Size(109, 39);
			this->bLinks->TabIndex = 9;
			this->bLinks->Text = L"Связи";
			this->bLinks->UseVisualStyleBackColor = false;
			this->bLinks->Click += gcnew System::EventHandler(this, &AddEditSchemaForm2::bLinks_Click);
			// 
			// AddEditSchemaForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(945, 379);
			this->Controls->Add(this->bLinks);
			this->Controls->Add(this->bSave);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->dgvTarget);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dgvSource);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox1);
			this->Name = L"AddEditSchemaForm2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление/редактирование схем интеграции";
			this->Load += gcnew System::EventHandler(this, &AddEditSchemaForm2::AddEditSchemaForm2_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTarget))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void bSave_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void bLinks_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 AddGroupLinksForm^ form = gcnew AddGroupLinksForm();
			 form->ShowDialog();

		 }
private: System::Void AddEditSchemaForm2_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 array<String^>^ row = gcnew array<String ^>(3);
			 row[0] = "Тестовый справочник оборудования ТЕМП"; 
			 row[1] = "Справочник оборудования"; 
			 row[2] = "САПР ТП \"ТеМП2\""; 
			 dgvSource->Rows->Add(row);

			 row[0] = "Тестовый справочник оборудования Semantic"; 
			 row[1] = "Справочник оборудования"; 
			 row[2] = "АСУ НСИ \"Semantic\"";
			 dgvTarget->Rows->Add(row);
		 }
};
}
