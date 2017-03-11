#pragma once

#include"ProgramIntegration.h"
#include"ODBCclass.h"
#include"IntegrationSettings.h"
#include"Integration.h"
#include "Results3.h"
#include "IntegrationResult.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ManualIntegrationForm1
	/// </summary>
	public ref class ManualIntegrationForm1 : public System::Windows::Forms::Form
	{
	private:
		OdbcClass^ _odbc;

	public:
		ManualIntegrationForm1(OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ManualIntegrationForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  bStartAccurate;
	private: System::Windows::Forms::Button^  bStartRough;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column13;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::Button^  bStartExe;



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
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->bStartExe = (gcnew System::Windows::Forms::Button());
			this->bStartAccurate = (gcnew System::Windows::Forms::Button());
			this->bStartRough = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 346);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1158, 58);
			this->panel1->TabIndex = 0;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->bCancel);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel5->Location = System::Drawing::Point(1035, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(123, 58);
			this->panel5->TabIndex = 2;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(23, 16);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 1;
			this->bCancel->Text = L"Закрыть";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &ManualIntegrationForm1::bCancel_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->bStartExe);
			this->panel2->Controls->Add(this->bStartAccurate);
			this->panel2->Controls->Add(this->bStartRough);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1158, 52);
			this->panel2->TabIndex = 1;
			// 
			// bStartExe
			// 
			this->bStartExe->Location = System::Drawing::Point(564, 13);
			this->bStartExe->Name = L"bStartExe";
			this->bStartExe->Size = System::Drawing::Size(316, 23);
			this->bStartExe->TabIndex = 2;
			this->bStartExe->Text = L"Запустить интеграцию через EXE файл";
			this->bStartExe->UseVisualStyleBackColor = true;
			this->bStartExe->Click += gcnew System::EventHandler(this, &ManualIntegrationForm1::bStartExe_Click);
			// 
			// bStartAccurate
			// 
			this->bStartAccurate->Location = System::Drawing::Point(290, 13);
			this->bStartAccurate->Name = L"bStartAccurate";
			this->bStartAccurate->Size = System::Drawing::Size(257, 23);
			this->bStartAccurate->TabIndex = 1;
			this->bStartAccurate->Text = L"Запустить интеграцию в \"точном\" режиме";
			this->bStartAccurate->UseVisualStyleBackColor = true;
			this->bStartAccurate->Click += gcnew System::EventHandler(this, &ManualIntegrationForm1::bStartAccurate_Click);
			// 
			// bStartRough
			// 
			this->bStartRough->Location = System::Drawing::Point(28, 13);
			this->bStartRough->Name = L"bStartRough";
			this->bStartRough->Size = System::Drawing::Size(245, 23);
			this->bStartRough->TabIndex = 0;
			this->bStartRough->Text = L"Запустить интеграцию в \"грубом\" режиме";
			this->bStartRough->UseVisualStyleBackColor = true;
			this->bStartRough->Click += gcnew System::EventHandler(this, &ManualIntegrationForm1::bStartRough_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(0, 52);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1158, 294);
			this->panel3->TabIndex = 2;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->dataGridView1);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Padding = System::Windows::Forms::Padding(10);
			this->panel4->Size = System::Drawing::Size(1158, 294);
			this->panel4->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(13) {this->Column1, 
				this->Column8, this->Column9, this->Column2, this->Column10, this->Column12, this->Column3, this->Column11, this->Column13, this->Column4, 
				this->Column5, this->Column6, this->Column7});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(10, 10);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(1138, 274);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"lD";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Visible = false;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Наименование схемы";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"ID_BOOK";
			this->Column9->Name = L"Column9";
			this->Column9->ReadOnly = true;
			this->Column9->Visible = false;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Тип справочника";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"ID_SOURCE_BOOK";
			this->Column10->Name = L"Column10";
			this->Column10->ReadOnly = true;
			this->Column10->Visible = false;
			// 
			// Column12
			// 
			this->Column12->HeaderText = L"Наименование справочника-источника";
			this->Column12->Name = L"Column12";
			this->Column12->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Система-источник";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"ID_TARGET_BOOK";
			this->Column11->Name = L"Column11";
			this->Column11->ReadOnly = true;
			this->Column11->Visible = false;
			// 
			// Column13
			// 
			this->Column13->HeaderText = L"Наименование справочника-получателя";
			this->Column13->Name = L"Column13";
			this->Column13->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Система-получатель";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Тип интеграции";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Дата создания интеграционный схемы";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Владелец";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			// 
			// ManualIntegrationForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1158, 404);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"ManualIntegrationForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Интеграция в ручном режиме";
			this->Load += gcnew System::EventHandler(this, &ManualIntegrationForm1::ManualIntegrationForm1_Load);
			this->panel1->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Close();
			 }
private: System::Void ManualIntegrationForm1_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			String^ squery = String::Format("select IP.ID, IP.INT_NAME, BB.ID, BB.NAME, " + 
				"IP.ID_SOURCE_BOOK, (select NAME from {0}INTEGRATION_BOOK IBS where IBS.ID = IP.ID_SOURCE_BOOK), (select INTEGRATED_SYSTEMS.NAME from {0}INTEGRATED_SYSTEMS where INTEGRATED_SYSTEMS.ID = (select ID_SYSTEM from {0}INTEGRATION_BOOK where INTEGRATION_BOOK.ID = IP.ID_SOURCE_BOOK) ), " + 
				"IP.ID_TARGET_BOOK, (select NAME from {0}INTEGRATION_BOOK IBT where IBT.ID = IP.ID_TARGET_BOOK), (select INTEGRATED_SYSTEMS.NAME from {0}INTEGRATED_SYSTEMS where INTEGRATED_SYSTEMS.ID = (select ID_SYSTEM from {0}INTEGRATION_BOOK where INTEGRATION_BOOK.ID = IP.ID_TARGET_BOOK) ), " + 
				"IP.TYPE, IP.CREATE_DATE, IP.CREATE_USER " +
				"from {0}INTEGRATION_PARAMS IP, {0}BOOKS BB where IP.BOOK_TYPE_ID = BB.ID", _odbc->schema);
			List<Object^>^ list = _odbc->ExecuteQuery(squery);

			for (int i = 0; i < list->Count; i+=13)
			{
				array<Object^>^ row = gcnew array<Object^>(13);
				row[0] = list[i];
				row[1] = list[i+1];
				row[2] = list[i+2];
				row[3] = list[i+3];
				row[4] = list[i+4];
				row[5] = list[i+5];
				row[6] = list[i+6];
				row[7] = list[i+7];
				row[8] = list[i+8];
				row[9] = list[i+9];
				int io = OdbcClass::GetResInt(list[i+10]);
				if (io == 0)
				{
					row[10] = "Односторонняя";
				}
				else
				{
					row[10] = "Двусторонняя";
				}
				row[11] = list[i+11];
				row[12] = list[i+12];
				dataGridView1->Rows->Add(row);
			}
		 }
private: System::Void bStartRough_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dataGridView1->RowCount <= 0 || dataGridView1->ColumnCount <= 0)
			 {
				 return;
			 }

			 int paramId = OdbcClass::GetResInt(dataGridView1[0, dataGridView1->SelectedCells[0]->RowIndex]->Value);

			 IntegrationSettings^ settings = gcnew IntegrationSettings(paramId, _odbc);

			 Results3^ resForm	= gcnew Results3(settings, 0);
			 resForm->ShowDialog();
		 }
private: System::Void bStartAccurate_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dataGridView1->RowCount <= 0 || dataGridView1->ColumnCount <= 0)
			 {
				 return;
			 }

			 int paramId = OdbcClass::GetResInt(dataGridView1[0, dataGridView1->SelectedCells[0]->RowIndex]->Value);

			 IntegrationSettings^ settings = gcnew IntegrationSettings(paramId, _odbc);

			 Results3^ resForm	= gcnew Results3(settings, 1);
			 resForm->ShowDialog();
		 }

private: System::Void bStartExe_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dataGridView1->RowCount <= 0 || dataGridView1->ColumnCount <= 0)
			 {
				 return;
			 }

			 int paramId = OdbcClass::GetResInt(dataGridView1[0, dataGridView1->SelectedCells[0]->RowIndex]->Value);

			 IntegrationSettings^ settings = gcnew IntegrationSettings(paramId, _odbc);
			 ProgramIntegration::StartExeIntegration(settings);
		 }
};
}
