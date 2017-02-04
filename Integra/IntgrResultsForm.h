#pragma once

#include "IntegrationResult.h"

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
	protected: 

	protected: 








	private: System::Windows::Forms::Button^  button1;
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
			String^ squery = String::Format("select IRR.INTEG_DATE, BB.NAME, IRR.STATE, " + 
				"(select INTEGRATED_SYSTEMS.NAME from {0}INTEGRATED_SYSTEMS where INTEGRATED_SYSTEMS.ID = (select ID_SYSTEM from {0}INTEGRATION_BOOK where INTEGRATION_BOOK.ID = IPP.ID_SOURCE_BOOK) )," + 
				"(select INTEGRATED_SYSTEMS.NAME from {0}INTEGRATED_SYSTEMS where INTEGRATED_SYSTEMS.ID = (select ID_SYSTEM from {0}INTEGRATION_BOOK where INTEGRATION_BOOK.ID = IPP.ID_TARGET_BOOK) )," + 
				"IRR.INT_TYPE, IPP.TYPE, IRR.INTEG_USER from " + 
				"{0}INTEGRATION_RESULTS IRR, {0}INTEGRATION_PARAMS IPP, {0}BOOKS BB where "+
				"IRR.ID_INTGR = IPP.ID and IPP.BOOK_TYPE_ID = BB.ID", _odbc->schema);
			List<Object^>^ qList = _odbc->ExecuteQuery(squery);

			dgv->Rows->Clear();
			for (int i = 0; i < qList->Count; i+=8)
			{
				array<String^>^ row = gcnew array<String ^>(8);
				row[0] = qList[i+0]->ToString();
				row[1] = qList[i+1]->ToString();
				row[2] = qList[i+2]->ToString();
				row[3] = qList[i+3]->ToString();
				row[4] = qList[i+4]->ToString();
				int intType = OdbcClass::GetInt(qList[i+5]);
				switch (intType)
				{
				case 0:
					row[5] = "Автоматическая";
					break;
				case 1:
					row[5] = "Ручная (точный)";
					break;
				case 2:
					row[5] = "Ручная (грубый)";
					break;
				}

				row[6] = qList[i+6]->ToString();
				row[7] = qList[i+7]->ToString();
				dgv->Rows->Add(row);
			}

		}



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgv = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgv))->BeginInit();
			this->SuspendLayout();
			// 
			// dgv
			// 
			this->dgv->AllowUserToAddRows = false;
			this->dgv->AllowUserToDeleteRows = false;
			this->dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->Column1, this->Column7, 
				this->Column8, this->Column5, this->Column6, this->Column3, this->Column4, this->Column2});
			this->dgv->Location = System::Drawing::Point(20, 134);
			this->dgv->Name = L"dgv";
			this->dgv->ReadOnly = true;
			this->dgv->Size = System::Drawing::Size(847, 150);
			this->dgv->TabIndex = 0;
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(699, 71);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(168, 48);
			this->button1->TabIndex = 24;
			this->button1->Text = L"Просмотр результатов интеграции";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(255, 71);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(22, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"по:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(36, 71);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(150, 13);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Дата запуска интеграции с:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(314, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Система-приемник:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(186, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 13);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Система-источник:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 13);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Тип справочника:";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(235, 95);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker2->TabIndex = 18;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(20, 94);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 17;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(317, 38);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 16;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(180, 38);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 15;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(20, 38);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 14;
			// 
			// bClose
			// 
			this->bClose->Location = System::Drawing::Point(792, 307);
			this->bClose->Name = L"bClose";
			this->bClose->Size = System::Drawing::Size(75, 23);
			this->bClose->TabIndex = 25;
			this->bClose->Text = L"Закрыть";
			this->bClose->UseVisualStyleBackColor = true;
			this->bClose->Click += gcnew System::EventHandler(this, &IntgrResultsForm::bClose_Click);
			// 
			// IntgrResultsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(886, 342);
			this->Controls->Add(this->bClose);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dgv);
			this->Name = L"IntgrResultsForm";
			this->Text = L"Результаты интеграций";
			this->Load += gcnew System::EventHandler(this, &IntgrResultsForm::IntgrResultsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgv))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

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
};
}
