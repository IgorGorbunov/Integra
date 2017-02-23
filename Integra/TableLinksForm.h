#pragma once

#include "DbLink.h"
#include "Attribute.h"


namespace Integra {

	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для TableLinksForm
	/// </summary>
	public ref class TableLinksForm : public System::Windows::Forms::Form
	{
	public:
		List<DbLink^>^ Links;
		

	private:
		Dictionary<String^, List<Attribute^>^>^ _attrs;
		List<String^>^ _firstTables;
		List<String^>^ _freeCodes;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column4;


		bool isOk;

	public:
		TableLinksForm(Dictionary<String^, List<Attribute^>^>^ attrs, List<DbLink^>^ editLinks)
		{
			InitializeComponent();
			_attrs = attrs;
			Links = editLinks;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TableLinksForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(405, 130);
			this->panel1->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->Column1, 
				this->Column2, this->Column3, this->Column4});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(405, 130);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TableLinksForm::dataGridView1_CellValueChanged);
			this->dataGridView1->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &TableLinksForm::dataGridView1_DataError);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Таблица";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Поле";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Таблица";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Поле";
			this->Column4->Name = L"Column4";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 130);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(405, 45);
			this->panel2->TabIndex = 1;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->bOk);
			this->panel3->Controls->Add(this->bCancel);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel3->Location = System::Drawing::Point(199, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(206, 45);
			this->panel3->TabIndex = 0;
			// 
			// bOk
			// 
			this->bOk->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bOk->Location = System::Drawing::Point(20, 9);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 1;
			this->bOk->Text = L"ОК";
			this->bOk->UseVisualStyleBackColor = false;
			this->bOk->Click += gcnew System::EventHandler(this, &TableLinksForm::bOk_Click);
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(113, 9);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 0;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &TableLinksForm::bCancel_Click);
			// 
			// TableLinksForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(405, 175);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(341, 213);
			this->Name = L"TableLinksForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление/редактирование связей таблиц";
			this->Load += gcnew System::EventHandler(this, &TableLinksForm::TableLinksForm_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		Attribute^ GetAttr(String^ fullTable, String^ code)
		{
			if (_attrs->ContainsKey(fullTable))
			{
				for each (Attribute^ attr in _attrs[fullTable])
				{
					if (attr->Code == code)
					{
						return attr;
					}
				}
			}
			return nullptr;	
		}

		bool CheckVoidCells()
		{
			for (int i = 0; i < dataGridView1->Rows->Count; i++)
			{
				for (int j = 0; j < dataGridView1->Columns->Count; j++)
				{
					if (dataGridView1[j, i]->Value == nullptr || String::IsNullOrEmpty(dataGridView1[j, i]->Value->ToString()))
					{
						return true;
					}
				}
			}
			return false;
		}

	private: System::Void TableLinksForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 _firstTables = gcnew List<String ^>();

				 for each(KeyValuePair<String^, List<Attribute^>^>^ pair in _attrs)
				 {
					 _firstTables->Add(pair->Key);
				 }

				 Column1->DataSource = _firstTables;
				 Column3->DataSource = _firstTables;
			 }

private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Links = gcnew List<DbLink ^>();
			 for (int i = 0; i < dataGridView1->RowCount; i++)
			 {
				 if (dataGridView1[1, i]->Value != nullptr &&
					 dataGridView1[3, i]->Value != nullptr)
				 {
					 String^ fullTable1 = dataGridView1[0, i]->Value->ToString();
					 String^ fullTable2 = dataGridView1[2, i]->Value->ToString();
					 String^ code1 = dataGridView1[1, i]->Value->ToString();
					 String^ code2 = dataGridView1[3, i]->Value->ToString();
					 Attribute^ attr1 = GetAttr(fullTable1, code1);
					 Attribute^ attr2 = GetAttr(fullTable2, code2);
					 DbLink^ dbLink = gcnew DbLink(attr1, attr2);
					 Links->Add(dbLink);
				 }
			 }
			 isOk = true;
			 Close();
		 }
private: System::Void dataGridView1_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (e->RowIndex < 0)
			 {
				 return;
			 }

			 int iRow = e->RowIndex;
			 if (e->ColumnIndex == 0)
			 {
				 if (dataGridView1[0, iRow]->Value != nullptr)
				 {
					 String^ cellValue = dataGridView1[0, iRow]->Value->ToString();
					 DataGridViewComboBoxCell^ cbCell = (DataGridViewComboBoxCell^)dataGridView1[1, iRow];
					 if (_attrs->ContainsKey(cellValue))
					 {
						 for each (Attribute^ attr in _attrs[cellValue])
						 {

							 cbCell->Items->Add(attr->Code);
						 }
					 }
					 else
					 {
						 cbCell->Items->Clear();
					 }
				 }
			 }
			 if (e->ColumnIndex == 2)
			 {
				 if (dataGridView1[2, iRow]->Value != nullptr)
				 {
					 String^ cellValue = dataGridView1[2, iRow]->Value->ToString();
					 DataGridViewComboBoxCell^ cbCell = (DataGridViewComboBoxCell^)dataGridView1[3, iRow];
					 if (_attrs->ContainsKey(cellValue))
					 {
						 for each (Attribute^ attr in _attrs[cellValue])
						 {
							 cbCell->Items->Add(attr->Code);
						 }
					 }
					 else
					 {
						 cbCell->Items->Clear();
					 }
				 }
			 }
		 }

private: System::Void dataGridView1_DataError(System::Object^  sender, System::Windows::Forms::DataGridViewDataErrorEventArgs^  e) 
		 {
			 Object^ o = e;
		 }
};
}
