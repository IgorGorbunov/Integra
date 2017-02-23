#pragma once


#include "Semantic.h"
#include "SemanticBook.h"
#include "Position.h"
#include "ProgramIntegration.h"
#include "Integration.h"
#include "SettingsForm.h"
#include "Results.h"
#include "RoleStation.h"
#include "AddEditUserRole.h"
#include "ManualIntegrationForm1.h"
#include "NormIntegrForm.h"
#include "JournalChangesForm.h"
#include "NoticesForm.h"
#include "IntgrResultsForm.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{






	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  SettingsToolStripMenuItem;





	private: System::Windows::Forms::ToolStripMenuItem^  настройкиПользователейToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  настройкиСправочниковToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  справкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  руководствоToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;

	private: System::Windows::Forms::ToolStripMenuItem^  интеграцияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ручнойРежимToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  автоматическийРежимToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  журналИзмененийToolStripMenuItem;




	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Book;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Source;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Target;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Direction;
	private: System::Windows::Forms::ToolStripMenuItem^  журналРезультатовToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  извещенияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  normsToolStripMenuItem;

			 List <IntegrationSettings^>^ _itegrationSettings;

	public:
		MainForm()
		{
			InitializeComponent();
			if (RoleStation::BookSettingsHidden())
			{
				SettingsToolStripMenuItem->Visible = false;
			}
			if (RoleStation::IntegrationHidden())
			{
				интеграцияToolStripMenuItem->Visible = false;
			}
			if (RoleStation::IzveHidden())
			{
				извещенияToolStripMenuItem->Visible = false;
			}
			if (RoleStation::IzmeHidden())
			{
				журналИзмененийToolStripMenuItem->Visible = false;
			}
			if (RoleStation::UsersHidden())
			{
				настройкиПользователейToolStripMenuItem->Visible = false;
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::DataGridView^  dgvIntParams;






	protected: 

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dgvIntParams = (gcnew System::Windows::Forms::DataGridView());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Book = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Source = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Target = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Direction = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->интеграцияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ручнойРежимToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->автоматическийРежимToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->normsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->журналРезультатовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->извещенияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->журналИзмененийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->настройкиПользователейToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->настройкиСправочниковToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->руководствоToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvIntParams))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dgvIntParams
			// 
			this->dgvIntParams->AllowUserToAddRows = false;
			this->dgvIntParams->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvIntParams->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvIntParams->ColumnHeadersHeight = 45;
			this->dgvIntParams->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->Id, this->Column1, 
				this->Column2, this->Column3, this->Book, this->Source, this->Target, this->Direction});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvIntParams->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvIntParams->Location = System::Drawing::Point(12, 27);
			this->dgvIntParams->Name = L"dgvIntParams";
			this->dgvIntParams->ReadOnly = true;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvIntParams->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dgvIntParams->Size = System::Drawing::Size(1017, 378);
			this->dgvIntParams->TabIndex = 2;
			this->dgvIntParams->Visible = false;
			this->dgvIntParams->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dgvIntParams_CellDoubleClick);
			// 
			// Id
			// 
			this->Id->HeaderText = L"№";
			this->Id->Name = L"Id";
			this->Id->ReadOnly = true;
			this->Id->Width = 25;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Название схемы";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Режим интеграции";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Дата последнего запуска";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Book
			// 
			this->Book->HeaderText = L"Справочник";
			this->Book->Name = L"Book";
			this->Book->ReadOnly = true;
			this->Book->Width = 300;
			// 
			// Source
			// 
			this->Source->HeaderText = L"Система-источник";
			this->Source->Name = L"Source";
			this->Source->ReadOnly = true;
			this->Source->Width = 200;
			// 
			// Target
			// 
			this->Target->HeaderText = L"Система-получатель";
			this->Target->Name = L"Target";
			this->Target->ReadOnly = true;
			this->Target->Width = 200;
			// 
			// Direction
			// 
			this->Direction->HeaderText = L"Направление интеграции";
			this->Direction->Name = L"Direction";
			this->Direction->ReadOnly = true;
			this->Direction->Width = 200;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->интеграцияToolStripMenuItem, 
				this->журналРезультатовToolStripMenuItem, this->извещенияToolStripMenuItem, this->журналИзмененийToolStripMenuItem, this->SettingsToolStripMenuItem, 
				this->справкаToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1041, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// интеграцияToolStripMenuItem
			// 
			this->интеграцияToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->ручнойРежимToolStripMenuItem, 
				this->автоматическийРежимToolStripMenuItem, this->normsToolStripMenuItem});
			this->интеграцияToolStripMenuItem->Name = L"интеграцияToolStripMenuItem";
			this->интеграцияToolStripMenuItem->Size = System::Drawing::Size(84, 20);
			this->интеграцияToolStripMenuItem->Text = L"Интеграция";
			this->интеграцияToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::интеграцияToolStripMenuItem_Click);
			// 
			// ручнойРежимToolStripMenuItem
			// 
			this->ручнойРежимToolStripMenuItem->Name = L"ручнойРежимToolStripMenuItem";
			this->ручнойРежимToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->ручнойРежимToolStripMenuItem->Text = L"Ручной режим";
			this->ручнойРежимToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ручнойРежимToolStripMenuItem_Click);
			// 
			// автоматическийРежимToolStripMenuItem
			// 
			this->автоматическийРежимToolStripMenuItem->Name = L"автоматическийРежимToolStripMenuItem";
			this->автоматическийРежимToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->автоматическийРежимToolStripMenuItem->Text = L"Автоматический режим";
			this->автоматическийРежимToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::автоматическийРежимToolStripMenuItem_Click);
			// 
			// normsToolStripMenuItem
			// 
			this->normsToolStripMenuItem->Name = L"normsToolStripMenuItem";
			this->normsToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->normsToolStripMenuItem->Text = L"Сборников нормативов работ";
			this->normsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::normsToolStripMenuItem_Click);
			// 
			// журналРезультатовToolStripMenuItem
			// 
			this->журналРезультатовToolStripMenuItem->Name = L"журналРезультатовToolStripMenuItem";
			this->журналРезультатовToolStripMenuItem->Size = System::Drawing::Size(132, 20);
			this->журналРезультатовToolStripMenuItem->Text = L"Журнал результатов";
			this->журналРезультатовToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::журналРезультатовToolStripMenuItem_Click);
			// 
			// извещенияToolStripMenuItem
			// 
			this->извещенияToolStripMenuItem->Name = L"извещенияToolStripMenuItem";
			this->извещенияToolStripMenuItem->Size = System::Drawing::Size(128, 20);
			this->извещенияToolStripMenuItem->Text = L"Журнал извещений";
			this->извещенияToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::извещенияToolStripMenuItem_Click);
			// 
			// журналИзмененийToolStripMenuItem
			// 
			this->журналИзмененийToolStripMenuItem->Name = L"журналИзмененийToolStripMenuItem";
			this->журналИзмененийToolStripMenuItem->Size = System::Drawing::Size(150, 20);
			this->журналИзмененийToolStripMenuItem->Text = L"Журнал корректировок";
			this->журналИзмененийToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::журналИзмененийToolStripMenuItem_Click);
			// 
			// SettingsToolStripMenuItem
			// 
			this->SettingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->настройкиПользователейToolStripMenuItem, 
				this->настройкиСправочниковToolStripMenuItem});
			this->SettingsToolStripMenuItem->Name = L"SettingsToolStripMenuItem";
			this->SettingsToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->SettingsToolStripMenuItem->Text = L"Настройки";
			// 
			// настройкиПользователейToolStripMenuItem
			// 
			this->настройкиПользователейToolStripMenuItem->Name = L"настройкиПользователейToolStripMenuItem";
			this->настройкиПользователейToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->настройкиПользователейToolStripMenuItem->Text = L"Настройки пользователей";
			this->настройкиПользователейToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::настройкиПользователейToolStripMenuItem_Click);
			// 
			// настройкиСправочниковToolStripMenuItem
			// 
			this->настройкиСправочниковToolStripMenuItem->Name = L"настройкиСправочниковToolStripMenuItem";
			this->настройкиСправочниковToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->настройкиСправочниковToolStripMenuItem->Text = L"Настройки справочников";
			this->настройкиСправочниковToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::настройкиСправочниковToolStripMenuItem_Click);
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->руководствоToolStripMenuItem, 
				this->toolStripSeparator1});
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->справкаToolStripMenuItem->Text = L"Справка";
			// 
			// руководствоToolStripMenuItem
			// 
			this->руководствоToolStripMenuItem->Name = L"руководствоToolStripMenuItem";
			this->руководствоToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->руководствоToolStripMenuItem->Text = L"Руководство";
			this->руководствоToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::руководствоToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(140, 6);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1041, 427);
			this->Controls->Add(this->dgvIntParams);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Интеграция нормативно-справочной информации \"Авиастар-СП\"";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvIntParams))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {

			 }

			Void SetDgv(List<IntegrationSettings^>^ settings)
			{
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
					dgvIntParams->Rows->Add(row);
				}
			}

private: System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
		 {
			 Hide();
			 ProgramIntegration::SaveLogs();
		 }


private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 _itegrationSettings = ProgramIntegration::GetIntegrationParams();
			 SetDgv(_itegrationSettings);
		 }
private: System::Void dgvIntParams_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 Object^ value = dgvIntParams->Rows[dgvIntParams->CurrentCell->RowIndex]->Cells[0]->Value;
			 int settingsId = Int32::Parse(value->ToString());
			 IntegrationSettings^ intSet;
			 for each(IntegrationSettings^ settings in _itegrationSettings)
			 {
				 if (settings->Id == settingsId)
				 {
					 intSet = settings;
					 break;
				 }
			 }
			 ProgramIntegration::StartIntegration(intSet);
			 /*List<Position^>^ sNewPoss = ProgramIntegration::SourceNew;
			 List<Position^>^ tNewPoss = ProgramIntegration::TargetNew;
			 Results^ results = gcnew Results(sNewPoss, tNewPoss, ProgramIntegration::Differences);
			 results->ShowDialog();*/
		 }
private: System::Void настройкиПользователейToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 AddEditUserRole^ form = gcnew AddEditUserRole();
			 form->ShowDialog();
		 }
private: System::Void настройкиСправочниковToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SettingsForm^ settingsForm = gcnew SettingsForm(ProgramIntegration::Odbc);
			 settingsForm->ShowDialog();
		 }

private: System::Void грубоеСоответсвиеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

		 }
private: System::Void ручнойРежимToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ManualIntegrationForm1^ form = gcnew ManualIntegrationForm1(ProgramIntegration::Odbc);
			 form->ShowDialog();
		 }
private: System::Void интеграцияToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void извещенияToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 NoticesForm^ form = gcnew NoticesForm(ProgramIntegration::Odbc);
			 form->ShowDialog();
		 }
private: System::Void журналИзмененийToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 JournalChangesForm^ form = gcnew JournalChangesForm();
			 form->ShowDialog();
		 }
private: System::Void журналРезультатовToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 IntgrResultsForm^ form = gcnew IntgrResultsForm(ProgramIntegration::Odbc);
			 form->ShowDialog();
		 }
private: System::Void руководствоToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String^ docFile = RoleStation::GetRoleDoc();
			 String^ fullPath = Path::Combine(Application::StartupPath, docFile);
			 //todo а если путь уже абсолютный
			 Process::Start(fullPath);
		 }
private: System::Void автоматическийРежимToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 int i = Int32::Parse("s");
		 }
private: System::Void normsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //NormIntegrForm^ form = gcnew NormIntegrForm();
			 //form->ShowDialog();
			 String^ path = Path::Combine(Application::StartupPath, "NormTime.exe");
			 System::Diagnostics::Process::Start(path);
		 }

};
}

