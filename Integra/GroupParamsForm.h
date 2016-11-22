#pragma once
#include "ODBCclass.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для GroupParamsForm
	/// </summary>
	public ref class GroupParamsForm : public System::Windows::Forms::Form
	{
	public:
		String^ Schtab;
		String^ IdCol;
		String^ NameCol;
		Dictionary<String^,String^>^ Attrs;

	private:
		OdbcClass^ _odbc;
		bool _attrsColFilled;

	public:
		GroupParamsForm(OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GroupParamsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  tbTable;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbSchema;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  cbId;
	private: System::Windows::Forms::ComboBox^  cbName;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column2;
	private: System::Windows::Forms::Button^  bOk;
	private: System::Windows::Forms::Button^  bCancel;

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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tbTable = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbSchema = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cbId = (gcnew System::Windows::Forms::ComboBox());
			this->cbName = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 169);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(193, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Обозначение наименования группы:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(266, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Обозначение ссылочного идентификатора группы:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tbTable);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->tbSchema);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(324, 84);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Таблица групп элементов";
			// 
			// tbTable
			// 
			this->tbTable->Location = System::Drawing::Point(171, 44);
			this->tbTable->Name = L"tbTable";
			this->tbTable->Size = System::Drawing::Size(138, 20);
			this->tbTable->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(168, 28);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(123, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Обозначение таблицы:";
			// 
			// tbSchema
			// 
			this->tbSchema->Location = System::Drawing::Point(20, 44);
			this->tbSchema->Name = L"tbSchema";
			this->tbSchema->Size = System::Drawing::Size(127, 20);
			this->tbSchema->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 28);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(113, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Обозначение схемы:";
			// 
			// cbId
			// 
			this->cbId->FormattingEnabled = true;
			this->cbId->Location = System::Drawing::Point(32, 131);
			this->cbId->Name = L"cbId";
			this->cbId->Size = System::Drawing::Size(161, 21);
			this->cbId->TabIndex = 7;
			this->cbId->DropDown += gcnew System::EventHandler(this, &GroupParamsForm::cbId_DropDown);
			this->cbId->Click += gcnew System::EventHandler(this, &GroupParamsForm::cbId_Click);
			// 
			// cbName
			// 
			this->cbName->FormattingEnabled = true;
			this->cbName->Location = System::Drawing::Point(32, 185);
			this->cbName->Name = L"cbName";
			this->cbName->Size = System::Drawing::Size(161, 21);
			this->cbName->TabIndex = 8;
			this->cbName->Click += gcnew System::EventHandler(this, &GroupParamsForm::cbName_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 222);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(116, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Реквизитный состав:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Column1, 
				this->Column2});
			this->dataGridView1->Location = System::Drawing::Point(35, 238);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(286, 226);
			this->dataGridView1->TabIndex = 10;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &GroupParamsForm::dataGridView1_CellClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Обозначение";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 120;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Наименование";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 120;
			// 
			// bOk
			// 
			this->bOk->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bOk->Location = System::Drawing::Point(165, 483);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 11;
			this->bOk->Text = L"OK";
			this->bOk->UseVisualStyleBackColor = false;
			this->bOk->Click += gcnew System::EventHandler(this, &GroupParamsForm::bOk_Click);
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(246, 483);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 12;
			this->bCancel->Text = L"Cancel";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &GroupParamsForm::bCancel_Click);
			// 
			// GroupParamsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(352, 524);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cbName);
			this->Controls->Add(this->cbId);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Name = L"GroupParamsForm";
			this->Text = L"Добавление/редактирование реквизитов групп";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:

			String^ GetSchtab()
			{
				if (String::IsNullOrEmpty(tbTable->Text->Trim()))
				{
					return nullptr;
				}
				if (String::IsNullOrEmpty(tbSchema->Text->Trim()))
				{
					return tbTable->Text->Trim()->ToUpper();
				}
				else
				{
					return tbSchema->Text->Trim()->ToUpper() + "." + tbTable->Text->Trim()->ToUpper();
				}
			}

			List<String^>^ GetCols()
			{
				String^ schtab = GetSchtab();
				if (String::IsNullOrEmpty(schtab))
				{
					MessageBox::Show("Не задано обозначение таблицы!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return nullptr;
				}
				try
				{
					List<Object^>^ qList = _odbc->GetTableCols(schtab);
					List<String^>^ sList = gcnew List<String ^>();
					for each (Object^ o in qList)
					{
						sList->Add(o->ToString());
					}
					return sList;
				}
				catch (TimeoutException^)
				{
					MessageBox::Show("Ошибка соединения с БД! Неверно задана таблица!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				return nullptr;
			}

private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Schtab = nullptr;
			 IdCol = nullptr;
			 NameCol = nullptr;
			 Attrs = nullptr;
			 Close();
		 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Schtab = GetSchtab();
			 IdCol = Schtab + "." + cbId->SelectedItem->ToString();
			 NameCol = Schtab + "." + cbName->SelectedItem->ToString();
			 Attrs = gcnew Dictionary<String ^, String ^>();
			 for (int i = 0; i < dataGridView1->Rows->Count; i++)
			 {
				 Attrs->Add(dataGridView1[0, i]->Value->ToString()->Trim()->ToUpper(), dataGridView1[1, i]->Value->ToString()->Trim()->ToUpper());
			 }
			 Close();
		 }
private: System::Void cbId_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 
		 }
private: System::Void cbName_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 List<String^>^ list = GetCols();
			 if (list == nullptr)
			 {
				 return;
			 }
			 cbName->DataSource = list;
		 }
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 List<String^>^ list = GetCols();
			 if (list == nullptr)
			 {
				 return;
			 }
			 Column1->DataSource = list;
			 Column2->DataSource = list;
		 }
private: System::Void cbId_DropDown(System::Object^  sender, System::EventArgs^  e) 
		 {
			 List<String^>^ list = GetCols();
			 if (list == nullptr)
			 {
				 return;
			 }
			 cbId->DataSource = list;
		 }
};
}
