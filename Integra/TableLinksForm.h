#pragma once

namespace Integra {

	using namespace System;
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
		Dictionary<String^, String^>^ Links;

	private:
		List<String^>^ _codes;
		List<String^>^ _freeCodes;


	public:
		TableLinksForm(List<String^>^ codes)
		{
			InitializeComponent();
			_codes = codes;
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column2;





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
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
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
			this->panel1->Size = System::Drawing::Size(325, 130);
			this->panel1->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Column1, 
				this->Column2});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(325, 130);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TableLinksForm::dataGridView1_CellClick);
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TableLinksForm::dataGridView1_CellValueChanged);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Поле одно таблицы";
			this->Column1->Name = L"Column1";
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Поле другой таблицы";
			this->Column2->Name = L"Column2";
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 130);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(325, 45);
			this->panel2->TabIndex = 1;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->bOk);
			this->panel3->Controls->Add(this->bCancel);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel3->Location = System::Drawing::Point(119, 0);
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
			this->ClientSize = System::Drawing::Size(325, 175);
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
	private: System::Void TableLinksForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 for (int i = 0; i < _codes->Count; i++)
				 {
					 array<String^>^ arr = gcnew array<String ^>(2);
					 arr[0] = _codes[i];
					 arr[1] = "";
					 dataGridView1->Rows->Add(arr);
				 }
				 _freeCodes = _codes;
			 }
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (e->ColumnIndex == 1)
			 {
				 List<String^>^ freeCurrentCodes = _freeCodes;
				 String^ firstCode = dataGridView1[0, e->RowIndex]->Value->ToString();
				 freeCurrentCodes->Remove(firstCode);
				 Column2->DataSource = freeCurrentCodes;
			 }
		 }
private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Links = nullptr;
			 Close();
		 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Links = gcnew Dictionary<String ^, String ^>();
			 for (int i = 0; i < dataGridView1->Rows->Count; i++)
			 {
				 Links->Add(dataGridView1[0, i]->Value->ToString(), dataGridView1[1, i]->Value->ToString());
			 }
			 Close();
		 }
private: System::Void dataGridView1_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (e->RowIndex < 0)
			 {
				 return;
			 }
			 if (e->ColumnIndex == 1)
			 {
				 String^ addVal = dataGridView1[1, e->RowIndex]->Value->ToString();
				 for (int i = 0; i < dataGridView1->Rows->Count; i++)
				 {
					 String^ val = dataGridView1[0, i]->Value->ToString();
					 if (val == addVal)
					 {
						 dataGridView1->Rows->RemoveAt(i);
						 break;
					 }
				 }
			 }
		 }
};
}
