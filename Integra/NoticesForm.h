#pragma once

#include "ODBCclass.h"
#include "Notice.h"
#include "BookSettings.h"
#include "IntegrationSettings.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для NoticesForm
	/// </summary>
	public ref class NoticesForm : public System::Windows::Forms::Form
	{
	private:
		OdbcClass^ _odbc;

	public:
		NoticesForm(OdbcClass^ odbc)
		{
			InitializeComponent();
			
			_odbc = odbc;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~NoticesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected: 







	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  bSoglas;

	private: System::Windows::Forms::Button^  bCancel;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  bClose;

	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;



















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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bSoglas = (gcnew System::Windows::Forms::Button());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->bClose = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {this->Column8, 
				this->Column1, this->Column2, this->Column3, this->Column11, this->Column4, this->Column5, this->Column6, this->Column7, this->Column9, 
				this->Column10});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(10, 10);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(854, 273);
			this->dataGridView1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(25, 80);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Просмотреть";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(16, 24);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(120, 20);
			this->dateTimePicker1->TabIndex = 2;
			this->dateTimePicker1->Visible = false;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(16, 68);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(120, 20);
			this->dateTimePicker2->TabIndex = 3;
			this->dateTimePicker2->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"с";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"по";
			this->label2->Visible = false;
			// 
			// bSoglas
			// 
			this->bSoglas->Location = System::Drawing::Point(25, 22);
			this->bSoglas->Name = L"bSoglas";
			this->bSoglas->Size = System::Drawing::Size(101, 23);
			this->bSoglas->TabIndex = 6;
			this->bSoglas->Text = L"Согласовать";
			this->bSoglas->UseVisualStyleBackColor = true;
			this->bSoglas->Click += gcnew System::EventHandler(this, &NoticesForm::bSoglas_Click);
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(25, 51);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(101, 23);
			this->bCancel->TabIndex = 7;
			this->bCancel->Text = L"Отменить";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &NoticesForm::bCancel_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->bCancel);
			this->panel1->Controls->Add(this->bSoglas);
			this->panel1->Controls->Add(this->dateTimePicker2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->dateTimePicker1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel1->Location = System::Drawing::Point(874, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(153, 293);
			this->panel1->TabIndex = 8;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->bClose);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 241);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(153, 52);
			this->panel2->TabIndex = 8;
			// 
			// bClose
			// 
			this->bClose->Location = System::Drawing::Point(25, 17);
			this->bClose->Name = L"bClose";
			this->bClose->Size = System::Drawing::Size(101, 23);
			this->bClose->TabIndex = 0;
			this->bClose->Text = L"Закрыть";
			this->bClose->UseVisualStyleBackColor = true;
			this->bClose->Click += gcnew System::EventHandler(this, &NoticesForm::bClose_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->dataGridView1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Padding = System::Windows::Forms::Padding(10);
			this->panel3->Size = System::Drawing::Size(874, 293);
			this->panel3->TabIndex = 9;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->panel3);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(874, 293);
			this->panel4->TabIndex = 10;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"ID";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Visible = false;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Дата проведения извещения";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Согласовано";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 50;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Тип извещения";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"Наименование позиции";
			this->Column11->Name = L"Column11";
			this->Column11->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Пользователь, создавший извещение";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Название интеграционной схемы";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Тип справочника";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Система";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Дата согласования";
			this->Column9->Name = L"Column9";
			this->Column9->ReadOnly = true;
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"Пользователь, согласовавший извещение";
			this->Column10->Name = L"Column10";
			this->Column10->ReadOnly = true;
			// 
			// NoticesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1027, 293);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel1);
			this->MinimumSize = System::Drawing::Size(904, 331);
			this->Name = L"NoticesForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Перечень извещений";
			this->Load += gcnew System::EventHandler(this, &NoticesForm::NoticesForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		void SetDgv()
		{
			List<Notice^>^ notices = Notice::GetAllNotices(_odbc);
			 if (notices == nullptr || notices->Count < 0)
				 return;

			 dataGridView1->Rows->Clear();
			 for each (Notice^ notice in notices)
			 {
				 array<Object^>^ row = gcnew array<Object ^>(11);
				 row[0] = notice->Id;
				 row[1] = notice->CreateDate;
				 if (notice->IsSoglas)
				 {
					 row[2] = true;
				 }
				 else
				 {
					 row[2] = false;
				 }
				 row[3] = notice->Type;


				 row[5] = notice->CreateUser;
				 row[6] = notice->IntSchemaName;
				 row[7] = notice->BookType;
				 row[8] = notice->System;
				 row[9] = notice->SoglasDate;
				 row[10] = notice->SoglasUser;
				 dataGridView1->Rows->Add(row);
			 }
		}


private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dataGridView1->SelectedCells != nullptr && dataGridView1->SelectedCells->Count > 0)
			 {
				 int iRow = dataGridView1->SelectedCells[0]->RowIndex;
				 int id = (int)dataGridView1[0, iRow]->Value;
				 Notice::Delete(_odbc, id);
				 dataGridView1->Rows->RemoveAt(iRow);
			 }
			 
		 }
private: System::Void NoticesForm_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetDgv();
		 }

private: System::Void bClose_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }

private: System::Void bSoglas_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dataGridView1->SelectedCells != nullptr && dataGridView1->SelectedCells->Count > 0)
			 {
				 int iRow = dataGridView1->SelectedCells[0]->RowIndex;
				 int id = (int)dataGridView1[0, iRow]->Value;
				 Notice::SoglasNotice(_odbc, id);

				 String^ squery = String::Format("select NN.ID_INTGR_BOOK, IRR.ID_INTGR " + 
					 "from {0}INTEGRATION_RESULTS IRR, {0}NOTICES NN " + 
					 "where NN.ID = {1} and NN.ID_INTGR = IRR.ID", _odbc->schema, id);
				 List<Object^>^ resList = _odbc->ExecuteQuery(squery);
				 int bSettingsId = OdbcClass::GetResInt(resList[0]);
				 int iSettingsId = OdbcClass::GetResInt(resList[1]);
				 BookSettings^ bSettings = gcnew BookSettings(bSettingsId, _odbc);
				 IntegrationSettings^ iSettings = gcnew IntegrationSettings(iSettingsId, _odbc);

				 Book^ book;
				if (bSettings->IsSemantic)
				{
					book = gcnew SemanticBook(bSettings, iSettings, _odbc, true);
				}
				else
				{
					book = gcnew DbBook(bSettings, iSettings, true, _odbc);
				}
				book->Remove();


				 SetDgv();
			 }
		 }
};
}
