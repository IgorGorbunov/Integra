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
#include "AutoSettingsForm.h"


namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{






	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  SettingsToolStripMenuItem;





	private: System::Windows::Forms::ToolStripMenuItem^  ����������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;

	private: System::Windows::Forms::ToolStripMenuItem^  ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������������ToolStripMenuItem;




	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Book;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Source;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Target;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Direction;
	private: System::Windows::Forms::ToolStripMenuItem^  �����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
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
				����������ToolStripMenuItem->Visible = false;
			}
			if (RoleStation::IzveHidden())
			{
				���������ToolStripMenuItem->Visible = false;
			}
			if (RoleStation::IzmeHidden())
			{
				���������������ToolStripMenuItem->Visible = false;
			}
			if (RoleStation::UsersHidden())
			{
				����������������������ToolStripMenuItem->Visible = false;
			}
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
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
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->normsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->Id->HeaderText = L"�";
			this->Id->Name = L"Id";
			this->Id->ReadOnly = true;
			this->Id->Width = 25;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"�������� �����";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"����� ����������";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"���� ���������� �������";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Book
			// 
			this->Book->HeaderText = L"����������";
			this->Book->Name = L"Book";
			this->Book->ReadOnly = true;
			this->Book->Width = 300;
			// 
			// Source
			// 
			this->Source->HeaderText = L"�������-��������";
			this->Source->Name = L"Source";
			this->Source->ReadOnly = true;
			this->Source->Width = 200;
			// 
			// Target
			// 
			this->Target->HeaderText = L"�������-����������";
			this->Target->Name = L"Target";
			this->Target->ReadOnly = true;
			this->Target->Width = 200;
			// 
			// Direction
			// 
			this->Direction->HeaderText = L"����������� ����������";
			this->Direction->Name = L"Direction";
			this->Direction->ReadOnly = true;
			this->Direction->Width = 200;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->����������ToolStripMenuItem, 
				this->�����������������ToolStripMenuItem, this->���������ToolStripMenuItem, this->���������������ToolStripMenuItem, this->SettingsToolStripMenuItem, 
				this->�������ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1041, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->�����������ToolStripMenuItem, 
				this->�������������������ToolStripMenuItem, this->normsToolStripMenuItem});
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(84, 20);
			this->����������ToolStripMenuItem->Text = L"����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::����������ToolStripMenuItem_Click);
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->�����������ToolStripMenuItem->Text = L"������ �����";
			this->�����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�����������ToolStripMenuItem_Click);
			// 
			// �������������������ToolStripMenuItem
			// 
			this->�������������������ToolStripMenuItem->Name = L"�������������������ToolStripMenuItem";
			this->�������������������ToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->�������������������ToolStripMenuItem->Text = L"�������������� �����";
			this->�������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�������������������ToolStripMenuItem_Click);
			// 
			// normsToolStripMenuItem
			// 
			this->normsToolStripMenuItem->Name = L"normsToolStripMenuItem";
			this->normsToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->normsToolStripMenuItem->Text = L"��������� ���������� �����";
			this->normsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::normsToolStripMenuItem_Click);
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(132, 20);
			this->�����������������ToolStripMenuItem->Text = L"������ �����������";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�����������������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(128, 20);
			this->���������ToolStripMenuItem->Text = L"������ ���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::���������ToolStripMenuItem_Click);
			// 
			// ���������������ToolStripMenuItem
			// 
			this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			this->���������������ToolStripMenuItem->Size = System::Drawing::Size(150, 20);
			this->���������������ToolStripMenuItem->Text = L"������ �������������";
			this->���������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::���������������ToolStripMenuItem_Click);
			// 
			// SettingsToolStripMenuItem
			// 
			this->SettingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->����������������������ToolStripMenuItem, 
				this->���������������������ToolStripMenuItem});
			this->SettingsToolStripMenuItem->Name = L"SettingsToolStripMenuItem";
			this->SettingsToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->SettingsToolStripMenuItem->Text = L"���������";
			// 
			// ����������������������ToolStripMenuItem
			// 
			this->����������������������ToolStripMenuItem->Name = L"����������������������ToolStripMenuItem";
			this->����������������������ToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->����������������������ToolStripMenuItem->Text = L"��������� �������������";
			this->����������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::����������������������ToolStripMenuItem_Click);
			// 
			// ���������������������ToolStripMenuItem
			// 
			this->���������������������ToolStripMenuItem->Name = L"���������������������ToolStripMenuItem";
			this->���������������������ToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->���������������������ToolStripMenuItem->Text = L"��������� ������������";
			this->���������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::���������������������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�����������ToolStripMenuItem, 
				this->toolStripSeparator1});
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->�����������ToolStripMenuItem->Text = L"�����������";
			this->�����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�����������ToolStripMenuItem_Click);
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
			this->Text = L"���������� ����������-���������� ���������� \"��������-��\"";
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
			 //_itegrationSettings = ProgramIntegration::GetIntegrationParams();
			 //SetDgv(_itegrationSettings);
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
private: System::Void ����������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 AddEditUserRole^ form = gcnew AddEditUserRole(ProgramIntegration::Odbc);
			 form->ShowDialog();
		 }
private: System::Void ���������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SettingsForm^ settingsForm = gcnew SettingsForm(ProgramIntegration::Odbc);
			 settingsForm->ShowDialog();
		 }

private: System::Void �����������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

		 }
private: System::Void �����������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ManualIntegrationForm1^ form = gcnew ManualIntegrationForm1(ProgramIntegration::Odbc);
			 form->ShowDialog();
		 }
private: System::Void ����������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void ���������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 NoticesForm^ form = gcnew NoticesForm(ProgramIntegration::Odbc);
			 form->ShowDialog();
		 }
private: System::Void ���������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 JournalChangesForm^ form = gcnew JournalChangesForm();
			 form->ShowDialog();
		 }
private: System::Void �����������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 IntgrResultsForm^ form = gcnew IntgrResultsForm(ProgramIntegration::Odbc);
			 form->ShowDialog();
		 }
private: System::Void �����������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String^ docFile = RoleStation::GetRoleDoc();
			 String^ fullPath = Path::Combine(Application::StartupPath, docFile);
			 //todo � ���� ���� ��� ����������
			 Process::Start(fullPath);
		 }
private: System::Void �������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 AutoSettingsForm^ form = gcnew AutoSettingsForm(ProgramIntegration::Odbc);
			 form->ShowDialog();
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

