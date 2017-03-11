#pragma once

#include "AutoConfigsForm.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AutoSettingsForm
	/// </summary>
	public ref class AutoSettingsForm : public System::Windows::Forms::Form
	{
	private:
		OdbcClass^ _odbc;

	public:
		AutoSettingsForm(OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AutoSettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewButtonColumn^  Column11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;


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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {this->Column9, 
				this->Column1, this->Column2, this->Column7, this->Column8, this->Column3, this->Column4, this->Column5, this->Column6, this->Column11, 
				this->Column10});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(10, 10);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(1100, 409);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AutoSettingsForm::dataGridView1_CellContentClick);
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AutoSettingsForm::dataGridView1_CellValueChanged);
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"ID";
			this->Column9->Name = L"Column9";
			this->Column9->ReadOnly = true;
			this->Column9->Visible = false;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Включить";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 50;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Название";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 200;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Время начала";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Периодичность";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Наименование схемы";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Система-источник";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Система-приемник";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Тип интеграции";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"Настройки";
			this->Column11->Name = L"Column11";
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"Пользователь";
			this->Column10->Name = L"Column10";
			this->Column10->ReadOnly = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Padding = System::Windows::Forms::Padding(10);
			this->panel1->Size = System::Drawing::Size(1120, 429);
			this->panel1->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1120, 429);
			this->panel2->TabIndex = 2;
			// 
			// AutoSettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1120, 429);
			this->Controls->Add(this->panel2);
			this->Name = L"AutoSettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Настройки автоматической интеграции";
			this->Load += gcnew System::EventHandler(this, &AutoSettingsForm::AutoSettingsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		void SetAutoConfigs()
		{
			dataGridView1->Rows->Clear();

			String^ squery = "select AIC.ID, AIC.ON_OFF, AIC.INT_NAME, AIC.START_TIME, AIC.START_PERIOD, IP.INT_NAME, " + 
				"(select INTEGRATED_SYSTEMS.NAME from {0}INTEGRATED_SYSTEMS where INTEGRATED_SYSTEMS.ID = (select ID_SYSTEM from {0}INTEGRATION_BOOK where INTEGRATION_BOOK.ID = IP.ID_SOURCE_BOOK) ), " + 
				"(select INTEGRATED_SYSTEMS.NAME from {0}INTEGRATED_SYSTEMS where INTEGRATED_SYSTEMS.ID = (select ID_SYSTEM from {0}INTEGRATION_BOOK where INTEGRATION_BOOK.ID = IP.ID_TARGET_BOOK) ), " + 
				"IP.TYPE, AIC.CREATE_USER " +
				"from {0}AUTO_INT_CONFIGS AIC, {0}INTEGRATION_PARAMS IP where IP.ID = AIC.INT_SCHEMA_ID";
			squery = String::Format(squery, _odbc->schema);

			List<Object^>^ resList = _odbc->ExecuteQuery(squery);
			for (int i = 0; i < resList->Count; i+=10)
			{
				array<Object^, 1>^ row = gcnew array<Object ^, 1>(11);
				row[0] = OdbcClass::GetResInt(resList[i+0]);
				int onOff = OdbcClass::GetResInt(resList[i+1]);
				if (onOff == 1)
				{
					row[1] = true;
				}
				else
				{
					row[1] = false;
				}

				row[2] = OdbcClass::GetResString(resList[i+2]);
				DateTime^ time = OdbcClass::GetResDate(resList[i+3]);
				row[3] = time->ToShortTimeString();

				int period = OdbcClass::GetResInt(resList[i+4]);
				String^ sPeriod;
				if (period == 0)
				{
					sPeriod = "Ежедневно";
				}
				else if (period == 1)
				{
					sPeriod = "Еженедельно";
				}
				else if (period == 2)
				{
					sPeriod = "Ежемесячно";
				}
				else if (period == 3)
				{
					sPeriod = "Ежеквартально";
				}
				else
				{
					sPeriod = "Ежегодно";
				}
				row[4] = sPeriod;

				row[5] = OdbcClass::GetResString(resList[i+5]);
				row[6] = OdbcClass::GetResString(resList[i+6]);
				row[7] = OdbcClass::GetResString(resList[i+7]);

				int intType = OdbcClass::GetResInt(resList[i+8]);
				if (intType == 1)
				{
					row[8] = "Двусторонняя";
				}
				else
				{
					row[8] = "Односторонняя";
				}

				row[10] = OdbcClass::GetResString(resList[i+9]);
				dataGridView1->Rows->Add(row);
			}
		}

	private: System::Void AutoSettingsForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 SetAutoConfigs();
			 }
private: System::Void dataGridView1_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 
		 }
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (e->ColumnIndex < 0 || e->RowIndex < 0)
			 {
				 return;
			 }

			 if (e->ColumnIndex == 9)
			 {
				 if (e->RowIndex == dataGridView1->RowCount - 1)
				 {
					 AutoConfigsForm^ form = gcnew AutoConfigsForm(_odbc);
					 form->ShowDialog();
				 }
				 else
				 {
					 //todo
				 }
				 SetAutoConfigs();
			 }
		 }
};
}
