#pragma once

#include "IntegrationResult.h"
#include "DetailResults.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для IntgrResults
	/// </summary>
	public ref class IntgrResultsForm : public System::Windows::Forms::Form
	{
	private:
		OdbcClass^ _odbc;

	public:
		IntgrResultsForm(OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~IntgrResultsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dgv;
	private: System::Windows::Forms::Button^  bDetails;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  bClose;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;


	private:
		void SetDgv()
		{
			int colColumns = 9;
			String^ squery = String::Format("select IRR.ID, IRR.INTEG_DATE, BB.NAME, IRR.STATE, " + 
				"(select ISS.NAME from {0}INTEGRATED_SYSTEMS ISS where ISS.ID = (select IBS.ID_SYSTEM from {0}INTEGRATION_BOOK IBS where IBS.ID = IPP.ID_SOURCE_BOOK) )," + 
				"(select IST.NAME from {0}INTEGRATED_SYSTEMS IST where IST.ID = (select IBT.ID_SYSTEM from {0}INTEGRATION_BOOK IBT where IBT.ID = IPP.ID_TARGET_BOOK) )," + 
				"IRR.INT_TYPE, IPP.TYPE, IRR.INTEG_USER from " + 
				"{0}INTEGRATION_RESULTS IRR, {0}INTEGRATION_PARAMS IPP, {0}BOOKS BB where "+
				"IRR.ID_INTGR = IPP.ID and IPP.BOOK_TYPE_ID = BB.ID", _odbc->schema);
			List<Object^>^ qList = _odbc->ExecuteQuery(squery);

			dgv->Rows->Clear();
			for (int i = 0; i < qList->Count; i+=colColumns)
			{
				array<String^>^ row = gcnew array<String ^>(colColumns);
				int id = OdbcClass::GetResInt(qList[i+0]);
				row[0] = id + "";
				row[1] = qList[i+1]->ToString();
				row[2] = qList[i+2]->ToString();
				row[3] = qList[i+3]->ToString();
				row[4] = qList[i+4]->ToString();
				row[5] = qList[i+5]->ToString();
				int intType = OdbcClass::GetResInt(qList[i+6]);
				switch (intType)
				{
				case 0:
					row[6] = "Автоматическая";
					break;
				case 1:
					row[6] = "Ручная (точный)";
					break;
				case 2:
					row[6] = "Ручная (грубый)";
					break;
				case 3:
					row[6] = "Ручная (сторонний EXE файл)";
					break;
				case 4:
					row[6] = "Ручная (карты норм времени)";
					break;
				}

				row[7] = qList[i+7]->ToString();
				row[8] = qList[i+8]->ToString();
				dgv->Rows->Add(row);
			}

		}

		void StartDetails()
		{
			if (dgv->RowCount <= 0 || dgv->ColumnCount <= 0)
			{
				return;
			}
			if (dgv->SelectedCells == nullptr)
			{
				return;
			}

			String^ sval = dgv[0, dgv->SelectedCells[0]->RowIndex]->Value->ToString();
			int val = int::Parse(sval);
			DetailResults^ form = gcnew DetailResults(val, _odbc);
			form->ShowDialog();
		}



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgv = (gcnew System::Windows::Forms::DataGridView());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bDetails = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->bClose = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgv))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// dgv
			// 
			this->dgv->AllowUserToAddRows = false;
			this->dgv->AllowUserToDeleteRows = false;
			this->dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {this->Column9, this->Column1, 
				this->Column7, this->Column8, this->Column5, this->Column6, this->Column3, this->Column4, this->Column2});
			this->dgv->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgv->Location = System::Drawing::Point(10, 10);
			this->dgv->Name = L"dgv";
			this->dgv->ReadOnly = true;
			this->dgv->Size = System::Drawing::Size(845, 323);
			this->dgv->TabIndex = 0;
			this->dgv->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &IntgrResultsForm::dgv_CellDoubleClick);
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
			this->Column1->HeaderText = L"Дата проведения интеграции";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Справочник";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Состояние";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Система-источник";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Система-приемник";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Тип интеграции";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Направление интеграции";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Пользователь, проводивший интеграцию";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// bDetails
			// 
			this->bDetails->Location = System::Drawing::Point(21, 13);
			this->bDetails->Name = L"bDetails";
			this->bDetails->Size = System::Drawing::Size(249, 23);
			this->bDetails->TabIndex = 24;
			this->bDetails->Text = L"Просмотр результатов интеграции";
			this->bDetails->UseVisualStyleBackColor = true;
			this->bDetails->Click += gcnew System::EventHandler(this, &IntgrResultsForm::bDetails_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(248, 71);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(22, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"по:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(29, 71);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(150, 13);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Дата запуска интеграции с:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(307, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Система-приемник:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(179, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 13);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Система-источник:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 13);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Тип справочника:";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(228, 95);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker2->TabIndex = 18;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(13, 94);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 17;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(310, 38);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 16;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(173, 38);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 15;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(13, 38);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 14;
			// 
			// bClose
			// 
			this->bClose->Location = System::Drawing::Point(20, 13);
			this->bClose->Name = L"bClose";
			this->bClose->Size = System::Drawing::Size(75, 23);
			this->bClose->TabIndex = 25;
			this->bClose->Text = L"Закрыть";
			this->bClose->UseVisualStyleBackColor = true;
			this->bClose->Click += gcnew System::EventHandler(this, &IntgrResultsForm::bClose_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->comboBox2);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->comboBox3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->dateTimePicker1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->dateTimePicker2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(865, 10);
			this->panel1->TabIndex = 26;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->bDetails);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 353);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(865, 51);
			this->panel2->TabIndex = 27;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->bClose);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel3->Location = System::Drawing::Point(751, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(114, 51);
			this->panel3->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(0, 10);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(865, 343);
			this->panel4->TabIndex = 28;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->dgv);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Padding = System::Windows::Forms::Padding(10);
			this->panel5->Size = System::Drawing::Size(865, 343);
			this->panel5->TabIndex = 0;
			// 
			// IntgrResultsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(865, 404);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->MinimumSize = System::Drawing::Size(670, 383);
			this->Name = L"IntgrResultsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Результаты интеграций";
			this->Load += gcnew System::EventHandler(this, &IntgrResultsForm::IntgrResultsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgv))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bClose_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Close();
			 }
private: System::Void IntgrResultsForm_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetDgv();
		 }
private: System::Void dgv_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 StartDetails();
		 }
private: System::Void bDetails_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 StartDetails();
		 }
};
}
