#pragma once

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;


	/// <summary>
	/// Сводка для DbFiltersForm
	/// </summary>
	public ref class DbFiltersForm : public System::Windows::Forms::Form
	{
	public:
		String^ Condition;

	private:
		List<String^>^ _conditions;
		List<String^>^ _codes;
		List<String^>^ _comparators;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Button^  bOk;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column4;
			 

	public:
		DbFiltersForm(List<String^>^ codes)
		{
			InitializeComponent();
			_codes = codes;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DbFiltersForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::DataGridView^  dataGridView1;




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
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bOk = (gcnew System::Windows::Forms::Button());
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
			this->panel1->Size = System::Drawing::Size(347, 120);
			this->panel1->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->Column1, 
				this->Column2, this->Column3, this->Column4});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(347, 120);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DbFiltersForm::dataGridView1_CellValueChanged);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Поле";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 39;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Условие";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 57;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Значение";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 80;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Сочетание";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 66;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 120);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(347, 42);
			this->panel2->TabIndex = 1;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->bCancel);
			this->panel3->Controls->Add(this->bOk);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel3->Location = System::Drawing::Point(147, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(200, 42);
			this->panel3->TabIndex = 2;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(113, 8);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 0;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &DbFiltersForm::bCancel_Click);
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(21, 8);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 1;
			this->bOk->Text = L"ОК";
			this->bOk->UseVisualStyleBackColor = true;
			this->bOk->Click += gcnew System::EventHandler(this, &DbFiltersForm::bOk_Click);
			// 
			// DbFiltersForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(347, 162);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(236, 147);
			this->Name = L"DbFiltersForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление/изменение фильтров";
			this->Load += gcnew System::EventHandler(this, &DbFiltersForm::DbFiltersForm_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		private:
			void SetConditionList()
			{
				_conditions = gcnew List<String ^>();
				_conditions->Add("=");
				_conditions->Add(">");
				_conditions->Add("<");
				_conditions->Add(">=");
				_conditions->Add("<=");
				_conditions->Add("<>");
				_conditions->Add("LIKE");
				_conditions->Add("BETWEEN");
				_conditions->Add("IS NOT NULL");
				_conditions->Add("IS NULL");
				_conditions->Add("IN");
				_conditions->Add("NOT IN");

				_comparators = gcnew List<String ^>();
				_comparators->Add("AND");
				_comparators->Add("OR");
			}

			void SetDgvComboBoxes()
			{
				Column2->DataSource = _conditions;
				Column1->DataSource = _codes;
			}


	private: System::Void DbFiltersForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 SetConditionList();
				 SetDgvComboBoxes();
			 }
	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Condition = nullptr;
				 Close();
			 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Condition = "";
			 for (int i = 0; i < dataGridView1->Rows->Count; i++)
			 {
				 Condition += String::Format("{0} {1} {2}", dataGridView1[0, i]->Value, dataGridView1[1, i]->Value, dataGridView1[2, i]->Value);
				 if (i < dataGridView1->Rows->Count - 1)
				 {
					 Condition += String::Format(" {0} ", dataGridView1[3, i]->Value);
				 }
			 }
			 Close();
		 }
private: System::Void dataGridView1_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (e->ColumnIndex == 1)
			 {
				 String^ cellValue = dataGridView1[1, e->RowIndex]->Value->ToString();
				 if (!String::IsNullOrEmpty(cellValue) &&
					 (cellValue == "IS NOT NULL" ||
					 cellValue == "IS NULL"))
				 {
					 dataGridView1[2, e->RowIndex]->Value = "";
					 dataGridView1[2, e->RowIndex]->ReadOnly = true;
				 }
			 }
		 }
};
}
