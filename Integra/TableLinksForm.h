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

	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column4;






			 


	public:
		TableLinksForm(Dictionary<String^, List<Attribute^>^>^ attrs)
		{
			InitializeComponent();
			_attrs = attrs;
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
	private: System::Windows::Forms::DataGridView^  dataGridView1;
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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
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
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->Column1, 
				this->Column2, this->Column3, this->Column4});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(405, 130);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TableLinksForm::dataGridView1_CellClick);
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TableLinksForm::dataGridView1_CellValueChanged);
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
			// Column1
			// 
			this->Column1->HeaderText = L"Таблица";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
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
					 array<String^>^ arr = gcnew array<String ^>(4);
					 Integra::Attribute^ attr = pair->Value[0];
					 arr[0] = attr->FullTable;
					 arr[1] = nullptr;
					 arr[2] = nullptr;
					 arr[3] = nullptr;
					 dataGridView1->Rows->Add(arr);
					 _firstTables->Add(pair->Key);
				 }
				 Column1->DataSource = _firstTables;
				 Column3->DataSource = _firstTables;
			 }
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (e->RowIndex < 0)
			 {
				 return;
			 }
			 int iCol = e->ColumnIndex;

		 }
private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Links = nullptr;
			 Close();
		 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 int i = Int32::Parse("sdf");
			 /*bool hasVoid = CheckVoidCells();
			 if (hasVoid)
			 {
				 MessageBox::Show("Не все поля заполнены!");
				 return;
			 }
			 Links = gcnew Dictionary<String ^, String ^>();
			 for (int i = 0; i < dataGridView1->Rows->Count; i++)
			 {
				 String^ firstFullCode = String::Format("{0}.{1}", dataGridView1[0, i]->Value, dataGridView1[1, i]->Value);
				 String^ secondFullCode = String::Format("{0}.{1}", dataGridView1[2, i]->Value, dataGridView1[3, i]->Value);
				 Links->Add(firstFullCode, secondFullCode);
			 }*/
			 Close();
		 }
private: System::Void dataGridView1_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (e->RowIndex < 0)
			 {
				 return;
			 }
			 if (e->ColumnIndex == 2)
			 {
				 String^ secondTableName = dataGridView1[e->ColumnIndex, e->RowIndex]->Value->ToString();
				 for (int i = 0; i < dataGridView1->Rows->Count; i++)
				 {
					 if (dataGridView1[0, i]->Value->ToString() == secondTableName &&
						 (dataGridView1[2, i]->Value == nullptr || dataGridView1[2, i]->Value->ToString() == ""))
					 {
						 dataGridView1->Rows->RemoveAt(i);
						 i--;
					 }
				 }
			 }
		 }
};
}
