#pragma once
#include "AddEditGroupForm.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddGroupLinksForm
	/// </summary>
	public ref class AddGroupLinksForm : public System::Windows::Forms::Form
	{
	public:
		AddGroupLinksForm(void)
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
		~AddGroupLinksForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  lbGroups;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  bAddGroup;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::DataGridView^  dgv;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;





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
			this->lbGroups = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bAddGroup = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dgv = (gcnew System::Windows::Forms::DataGridView());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgv))->BeginInit();
			this->SuspendLayout();
			// 
			// lbGroups
			// 
			this->lbGroups->BackColor = System::Drawing::SystemColors::Window;
			this->lbGroups->FormattingEnabled = true;
			this->lbGroups->Location = System::Drawing::Point(23, 25);
			this->lbGroups->Name = L"lbGroups";
			this->lbGroups->Size = System::Drawing::Size(650, 173);
			this->lbGroups->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Группы:";
			// 
			// bAddGroup
			// 
			this->bAddGroup->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddGroup->Location = System::Drawing::Point(692, 25);
			this->bAddGroup->Name = L"bAddGroup";
			this->bAddGroup->Size = System::Drawing::Size(75, 23);
			this->bAddGroup->TabIndex = 2;
			this->bAddGroup->Text = L"Добавить группу";
			this->bAddGroup->UseVisualStyleBackColor = false;
			this->bAddGroup->Click += gcnew System::EventHandler(this, &AddGroupLinksForm::bAddGroup_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button2->Location = System::Drawing::Point(692, 54);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Изменить";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button3->Location = System::Drawing::Point(692, 83);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Удалить";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// dgv
			// 
			this->dgv->AllowUserToDeleteRows = false;
			this->dgv->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->Column2, this->Column1, 
				this->Column5, this->Column7, this->Column3, this->Column4, this->Column6, this->Column8});
			this->dgv->Location = System::Drawing::Point(23, 223);
			this->dgv->Name = L"dgv";
			this->dgv->RowHeadersVisible = false;
			this->dgv->Size = System::Drawing::Size(744, 217);
			this->dgv->TabIndex = 5;
			this->dgv->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AddGroupLinksForm::dgv_CellValueChanged);
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Обозначение реквизита системы-источника";
			this->Column2->Name = L"Column2";
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Наименование реквизита системы-источника";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 160;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Тип данных";
			this->Column5->Name = L"Column5";
			this->Column5->Width = 70;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Размер";
			this->Column7->Name = L"Column7";
			this->Column7->Width = 40;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Обозначение реквизита системы-получателя";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Наименование реквизита системы-получателя";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 160;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Тип данных";
			this->Column6->Name = L"Column6";
			this->Column6->Width = 70;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Размер";
			this->Column8->Name = L"Column8";
			this->Column8->Width = 40;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(375, 458);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Отмена";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(284, 458);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Сохранить";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// AddGroupLinksForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(796, 493);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->dgv);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->bAddGroup);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbGroups);
			this->Name = L"AddGroupLinksForm";
			this->Text = L"Добавление/редактирование групповых связей";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgv))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void bAddGroup_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 AddEditGroupForm^ form = gcnew AddEditGroupForm();
				 form->ShowDialog();
				 if (form->GroupName != nullptr)
				 {
					 lbGroups->Items->Add(form->GroupName + " " + form->DoubleName);
				 }

				 List<String^>^ cols1 = gcnew List<String ^>();
				 cols1->Add("ATTR01");
				 cols1->Add("ATTR02");
				 cols1->Add("ATTR03");
				 cols1->Add("ATTR04");
				 Column2->DataSource = cols1;

				 List<String^>^ cols2 = gcnew List<String ^>();
				 cols2->Add("T1_P1");
				 cols2->Add("T1_P2");
				 cols2->Add("T1_P3");
				 cols2->Add("T1_P4");
				 Column3->DataSource = cols2;
			 }
private: System::Void dgv_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (e->RowIndex < 0 || e->ColumnIndex < 0)
			 {
				 return;
			 }
			 if (dgv[e->ColumnIndex, e->RowIndex]->Value == nullptr &&
				 String::IsNullOrEmpty(dgv[e->ColumnIndex, e->RowIndex]->Value->ToString()))
			 {
				 return;
			 }
			 if (dgv[e->ColumnIndex, e->RowIndex]->Value->ToString() == "ATTR01")
			 {
				 dgv[1, e->RowIndex]->Value = "Код";
				 dgv[2, e->RowIndex]->Value = "Целое число";
				 dgv[3, e->RowIndex]->Value = "20";
			 }
			 if (dgv[e->ColumnIndex, e->RowIndex]->Value->ToString() == "ATTR02")
			 {
				 dgv[1, e->RowIndex]->Value = "Наименование";
				 dgv[2, e->RowIndex]->Value = "Строка";
				 dgv[3, e->RowIndex]->Value = "200";
			 }
			 if (dgv[e->ColumnIndex, e->RowIndex]->Value->ToString() == "ATTR03")
			 {
				 dgv[1, e->RowIndex]->Value = "Марка";
				 dgv[2, e->RowIndex]->Value = "Строка";
				 dgv[3, e->RowIndex]->Value = "200";
			 }
			 if (dgv[e->ColumnIndex, e->RowIndex]->Value->ToString() == "ATTR04")
			 {
				 dgv[1, e->RowIndex]->Value = "Цех-получатель";
				 dgv[2, e->RowIndex]->Value = "Varchar2";
				 dgv[3, e->RowIndex]->Value = "200";
			 }

			 if (dgv[e->ColumnIndex, e->RowIndex]->Value->ToString() == "T1_P1")
			 {
				 dgv[5, e->RowIndex]->Value = "Код";
				 dgv[6, e->RowIndex]->Value = "Целое число";
				 dgv[7, e->RowIndex]->Value = "20";
			 }
			 if (dgv[e->ColumnIndex, e->RowIndex]->Value->ToString() == "T1_P2")
			 {
				 dgv[5, e->RowIndex]->Value = "Наименование";
				 dgv[6, e->RowIndex]->Value = "Строка";
				 dgv[7, e->RowIndex]->Value = "200";
			 }
			 if (dgv[e->ColumnIndex, e->RowIndex]->Value->ToString() == "T1_P3")
			 {
				 dgv[5, e->RowIndex]->Value = "Марка";
				 dgv[6, e->RowIndex]->Value = "Строка";
				 dgv[7, e->RowIndex]->Value = "200";
			 }
			 if (dgv[e->ColumnIndex, e->RowIndex]->Value->ToString() == "T1_P4")
			 {
				 dgv[5, e->RowIndex]->Value = "Цех-получатель";
				 dgv[6, e->RowIndex]->Value = "Varchar2";
				 dgv[7, e->RowIndex]->Value = "200";
			 }
		 }
};
}
