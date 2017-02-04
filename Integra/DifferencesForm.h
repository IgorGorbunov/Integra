#pragma once

#include "DiffererncePosition.h"


namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для DifferencesForm
	/// </summary>
	public ref class DifferencesForm : public System::Windows::Forms::Form
	{
	public:
		DifferencePosition^ _pos;
		Dictionary<Attribute^, String^>^ NewAttrNames;


	private: System::Windows::Forms::DataGridViewTextBoxColumn^  codeSourceCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  codeTargetCol;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  valueCol;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  valueTargetCol;
			 

	public:
		DifferencesForm(DifferencePosition^ pos)
		{
			InitializeComponent();
			_pos = pos;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DifferencesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dgvDifferent;
	protected: 




	private: System::Windows::Forms::DataGridView^  dgvEqual;



	private: System::Windows::Forms::Button^  bClose;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  bIntegInSource;













	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::Button^  bIntegInTarget;


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
			this->dgvDifferent = (gcnew System::Windows::Forms::DataGridView());
			this->dgvEqual = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bClose = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bIntegInSource = (gcnew System::Windows::Forms::Button());
			this->bIntegInTarget = (gcnew System::Windows::Forms::Button());
			this->codeSourceCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->codeTargetCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->valueCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->valueTargetCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvDifferent))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvEqual))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvDifferent
			// 
			this->dgvDifferent->AllowUserToAddRows = false;
			this->dgvDifferent->AllowUserToDeleteRows = false;
			this->dgvDifferent->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvDifferent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDifferent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->codeSourceCol, 
				this->codeTargetCol, this->Column1, this->valueCol, this->Column2, this->valueTargetCol});
			this->dgvDifferent->Location = System::Drawing::Point(25, 258);
			this->dgvDifferent->Name = L"dgvDifferent";
			this->dgvDifferent->RowHeadersVisible = false;
			this->dgvDifferent->Size = System::Drawing::Size(606, 202);
			this->dgvDifferent->TabIndex = 0;
			this->dgvDifferent->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DifferencesForm::dgvDifferent_CellValueChanged);
			// 
			// dgvEqual
			// 
			this->dgvEqual->AllowUserToAddRows = false;
			this->dgvEqual->AllowUserToDeleteRows = false;
			this->dgvEqual->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvEqual->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvEqual->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->dataGridViewTextBoxColumn1, 
				this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3});
			this->dgvEqual->Location = System::Drawing::Point(25, 29);
			this->dgvEqual->Name = L"dgvEqual";
			this->dgvEqual->ReadOnly = true;
			this->dgvEqual->RowHeadersVisible = false;
			this->dgvEqual->Size = System::Drawing::Size(606, 202);
			this->dgvEqual->TabIndex = 1;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Наименование из системы источника";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Наименование из системы получателя";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Значение";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->Width = 400;
			// 
			// bClose
			// 
			this->bClose->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bClose->Location = System::Drawing::Point(556, 473);
			this->bClose->Name = L"bClose";
			this->bClose->Size = System::Drawing::Size(75, 47);
			this->bClose->TabIndex = 2;
			this->bClose->Text = L"Отмена";
			this->bClose->UseVisualStyleBackColor = false;
			this->bClose->Click += gcnew System::EventHandler(this, &DifferencesForm::bClose_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Одинаковые атрибуты";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 242);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Различные атрибуты";
			// 
			// bIntegInSource
			// 
			this->bIntegInSource->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bIntegInSource->Enabled = false;
			this->bIntegInSource->Location = System::Drawing::Point(281, 473);
			this->bIntegInSource->Name = L"bIntegInSource";
			this->bIntegInSource->Size = System::Drawing::Size(117, 47);
			this->bIntegInSource->TabIndex = 5;
			this->bIntegInSource->Text = L"Интегрировать в систему источник";
			this->bIntegInSource->UseVisualStyleBackColor = false;
			this->bIntegInSource->Visible = false;
			// 
			// bIntegInTarget
			// 
			this->bIntegInTarget->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bIntegInTarget->Enabled = false;
			this->bIntegInTarget->Location = System::Drawing::Point(420, 473);
			this->bIntegInTarget->Name = L"bIntegInTarget";
			this->bIntegInTarget->Size = System::Drawing::Size(117, 47);
			this->bIntegInTarget->TabIndex = 6;
			this->bIntegInTarget->Text = L"Интегрировать в систему приемник";
			this->bIntegInTarget->UseVisualStyleBackColor = false;
			this->bIntegInTarget->Click += gcnew System::EventHandler(this, &DifferencesForm::bIntegInTarget_Click);
			// 
			// codeSourceCol
			// 
			this->codeSourceCol->HeaderText = L"Наименование из системы источника";
			this->codeSourceCol->Name = L"codeSourceCol";
			this->codeSourceCol->Width = 76;
			// 
			// codeTargetCol
			// 
			this->codeTargetCol->HeaderText = L"Наименование из системы получателя";
			this->codeTargetCol->Name = L"codeTargetCol";
			this->codeTargetCol->Width = 76;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 25;
			// 
			// valueCol
			// 
			this->valueCol->HeaderText = L"Значение из системы-источника";
			this->valueCol->Name = L"valueCol";
			this->valueCol->Width = 200;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 25;
			// 
			// valueTargetCol
			// 
			this->valueTargetCol->HeaderText = L"Значение из системы-получателя";
			this->valueTargetCol->Name = L"valueTargetCol";
			this->valueTargetCol->Width = 200;
			// 
			// DifferencesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(654, 532);
			this->Controls->Add(this->bIntegInTarget);
			this->Controls->Add(this->bIntegInSource);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bClose);
			this->Controls->Add(this->dgvEqual);
			this->Controls->Add(this->dgvDifferent);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"DifferencesForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Различия реквизитов";
			this->Load += gcnew System::EventHandler(this, &DifferencesForm::DifferencesForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvDifferent))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvEqual))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void DifferencesForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 dgvDifferent->Columns[0]->ReadOnly = false;
				 dgvDifferent->Columns[1]->ReadOnly = false;
				 dgvDifferent->Columns[3]->ReadOnly = false;
				 dgvDifferent->Columns[5]->ReadOnly = false;
				 for each(array<Object^>^ arr in _pos->Equals)
				 {
					 array<String^>^ arrS = gcnew array<String ^>(3);
					 arrS[0] = ((Attribute^)arr[0])->Name;
					 arrS[1] = ((Attribute^)arr[1])->Name;
					 arrS[2] = arr[2]->ToString();
					 dgvEqual->Rows->Add(arrS);
				 }

				 for each(array<Object^, 2>^ arr in _pos->Differences)
				 {
					 array<String^>^ arrS = gcnew array<String ^>(6);
					 arrS[0] = ((Attribute^)arr[0, 0])->Name;
					 arrS[1] = ((Attribute^)arr[1, 0])->Name;
					 arrS[3] = arr[0, 1]->ToString();
					 arrS[5] = arr[1, 1]->ToString();
					 dgvDifferent->Rows->Add(arrS);
				 }
			 }
private: System::Void bClose_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 NewAttrNames = nullptr;
			 Close();
		 }
private: System::Void dgvDifferent_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (e->ColumnIndex == 2 || e->ColumnIndex == 4)
			 {
				 bool isTwoFalse = false;
				 bool value = (bool)dgvDifferent[e->ColumnIndex, e->RowIndex]->Value;
				 if (e->ColumnIndex == 2)
				 {
					 dgvDifferent[4, e->RowIndex]->Value = !value;
				 }
				 else
				 {
					 dgvDifferent[2, e->RowIndex]->Value = !value;
				 }
				 for (int i = 0; i < dgvDifferent->Rows->Count; i++)
				 {
					 Object^ cell1 = dgvDifferent[2, i]->Value;
					 Object^ cell2 = dgvDifferent[4, i]->Value;
					 if ((cell1 == nullptr || (bool)(cell1) == false) && 
						 (cell2 == nullptr || (bool)(cell2) == false))
					 {
						 isTwoFalse = true;
						 break;
					 }
				 }
				 if (isTwoFalse)
				 {
					 bIntegInTarget->Enabled = false;
				 }
				 else
				 {
					 bIntegInTarget->Enabled = true;
				 }
			 }
		 }
private: System::Void bIntegInTarget_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Dictionary<Attribute^, String^>^ newAttrVals = gcnew Dictionary<Attribute ^, String ^>();
			 for (int i = 0; i < dgvDifferent->Rows->Count; i++)
			 {
				 bool fromSource =  (bool)dgvDifferent[2, i]->Value;
				 if (fromSource)
				 {
					 array<Object^, 2>^ arr = _pos->Differences[i];
					 Attribute^ tAttr = (Attribute^) arr[1,0];
					 String^ value = dgvDifferent[3, i]->Value->ToString();
					 newAttrVals->Add(tAttr, value);
				 }
			 }
			 NewAttrNames = newAttrVals;
			 MessageBox::Show("Позиция интегрирована");
			 Close();
		 }
};
}
