#pragma once

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddNewTable
	/// </summary>
	public ref class AddNewTableForm : public System::Windows::Forms::Form
	{
	public:
		String^ SchTab;
		String^ Schema;
		String^ Table;

		AddNewTableForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddNewTableForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  tbSchema;
	private: System::Windows::Forms::TextBox^  tbTable;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  bAdd;

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
			this->tbSchema = (gcnew System::Windows::Forms::TextBox());
			this->tbTable = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bAdd = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Схема";
			// 
			// tbSchema
			// 
			this->tbSchema->Location = System::Drawing::Point(25, 34);
			this->tbSchema->Name = L"tbSchema";
			this->tbSchema->Size = System::Drawing::Size(219, 20);
			this->tbSchema->TabIndex = 1;
			// 
			// tbTable
			// 
			this->tbTable->Location = System::Drawing::Point(25, 80);
			this->tbTable->Name = L"tbTable";
			this->tbTable->Size = System::Drawing::Size(219, 20);
			this->tbTable->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Таблица";
			// 
			// bAdd
			// 
			this->bAdd->Location = System::Drawing::Point(96, 118);
			this->bAdd->Name = L"bAdd";
			this->bAdd->Size = System::Drawing::Size(75, 23);
			this->bAdd->TabIndex = 4;
			this->bAdd->Text = L"Добавить";
			this->bAdd->UseVisualStyleBackColor = true;
			this->bAdd->Click += gcnew System::EventHandler(this, &AddNewTableForm::bAdd_Click);
			// 
			// AddNewTableForm
			// 
			this->AcceptButton = this->bAdd;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(280, 162);
			this->Controls->Add(this->bAdd);
			this->Controls->Add(this->tbTable);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbSchema);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"AddNewTableForm";
			this->Text = L"AddNewTable";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void bAdd_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (!String::IsNullOrEmpty(tbTable->Text->Trim()))
				 {
					 Schema =  tbSchema->Text->Trim()->ToUpper();
					 Table = tbTable->Text->Trim()->ToUpper();
					 SchTab = Schema + "." + Table;
					 Close();
				 }
				 else
				 {
					 MessageBox::Show("Не все поля заполнены!");
				 }
			 }
};
}
