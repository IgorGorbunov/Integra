#pragma once

#include "DiffererncePosition.h"
#include "IntegrationSettings.h"


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
		Dictionary<Attribute^, String^>^ NewAttrNames;
		bool InTarget;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;	 
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  codeSourceCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  codeTargetCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  valueCol;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  valueTargetCol;

			 DifferencePosition^ _pos;
			 IntegrationSettings::IntegrationType _intType;
	public:
		DifferencesForm(DifferencePosition^ pos, IntegrationSettings::IntegrationType integrationType)
		{
			InitializeComponent();
			_pos = pos;
			_intType = integrationType;
			if (_intType == IntegrationSettings::IntegrationType::OneWay)
			{
				bIntegInSource->Enabled = false;
			}
			else
			{
				bIntegInSource->Enabled = true;
			}
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
	private: System::Windows::Forms::DataGridView^  dgvEqual;
	private: System::Windows::Forms::Button^  bClose;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  bIntegInSource;
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
			this->codeSourceCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->codeTargetCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->valueCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->valueTargetCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgvEqual = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bClose = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bIntegInSource = (gcnew System::Windows::Forms::Button());
			this->bIntegInTarget = (gcnew System::Windows::Forms::Button());
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
			this->dgvDifferent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->codeSourceCol, 
				this->Column5, this->codeTargetCol, this->Column6, this->Column1, this->valueCol, this->Column2, this->valueTargetCol});
			this->dgvDifferent->Location = System::Drawing::Point(25, 258);
			this->dgvDifferent->Name = L"dgvDifferent";
			this->dgvDifferent->RowHeadersVisible = false;
			this->dgvDifferent->Size = System::Drawing::Size(805, 202);
			this->dgvDifferent->TabIndex = 0;
			this->dgvDifferent->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DifferencesForm::dgvDifferent_CellValueChanged);
			// 
			// codeSourceCol
			// 
			this->codeSourceCol->HeaderText = L"Наименование из справочника источника";
			this->codeSourceCol->Name = L"codeSourceCol";
			this->codeSourceCol->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Код из справочника источника";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 75;
			// 
			// codeTargetCol
			// 
			this->codeTargetCol->HeaderText = L"Наименование из справочника получателя";
			this->codeTargetCol->Name = L"codeTargetCol";
			this->codeTargetCol->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Код из справочника получателя";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 75;
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
			this->valueCol->ReadOnly = true;
			this->valueCol->Width = 200;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 25;
			// 
			// valueTargetCol
			// 
			this->valueTargetCol->HeaderText = L"Значение из системы-получателя";
			this->valueTargetCol->Name = L"valueTargetCol";
			this->valueTargetCol->ReadOnly = true;
			this->valueTargetCol->Width = 200;
			// 
			// dgvEqual
			// 
			this->dgvEqual->AllowUserToAddRows = false;
			this->dgvEqual->AllowUserToDeleteRows = false;
			this->dgvEqual->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvEqual->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvEqual->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->dataGridViewTextBoxColumn1, 
				this->Column3, this->Column4, this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3});
			this->dgvEqual->Location = System::Drawing::Point(25, 29);
			this->dgvEqual->Name = L"dgvEqual";
			this->dgvEqual->ReadOnly = true;
			this->dgvEqual->RowHeadersVisible = false;
			this->dgvEqual->Size = System::Drawing::Size(805, 202);
			this->dgvEqual->TabIndex = 1;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Наименование из справочника источника";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Код из справочника источника";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Код из справочника получателя";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Наименование из справочника получателя";
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
			this->bClose->Location = System::Drawing::Point(748, 482);
			this->bClose->Name = L"bClose";
			this->bClose->Size = System::Drawing::Size(82, 29);
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
			this->label1->Size = System::Drawing::Size(132, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Одинаковые реквизиты:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 242);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Различные реквизиты:";
			// 
			// bIntegInSource
			// 
			this->bIntegInSource->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bIntegInSource->Enabled = false;
			this->bIntegInSource->Location = System::Drawing::Point(189, 482);
			this->bIntegInSource->Name = L"bIntegInSource";
			this->bIntegInSource->Size = System::Drawing::Size(257, 29);
			this->bIntegInSource->TabIndex = 5;
			this->bIntegInSource->Text = L"Интегрировать в систему источник";
			this->bIntegInSource->UseVisualStyleBackColor = false;
			this->bIntegInSource->Click += gcnew System::EventHandler(this, &DifferencesForm::bIntegInSource_Click);
			// 
			// bIntegInTarget
			// 
			this->bIntegInTarget->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bIntegInTarget->Location = System::Drawing::Point(452, 482);
			this->bIntegInTarget->Name = L"bIntegInTarget";
			this->bIntegInTarget->Size = System::Drawing::Size(272, 29);
			this->bIntegInTarget->TabIndex = 6;
			this->bIntegInTarget->Text = L"Интегрировать в систему приемник";
			this->bIntegInTarget->UseVisualStyleBackColor = false;
			this->bIntegInTarget->Click += gcnew System::EventHandler(this, &DifferencesForm::bIntegInTarget_Click);
			// 
			// DifferencesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(852, 539);
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

		bool SetNewAttrVals(bool toSource)
		{
			bool success = true;
			Dictionary<Attribute^, String^>^ newAttrVals = gcnew Dictionary<Attribute ^, String ^>();
			for (int i = 0; i < dgvDifferent->Rows->Count; i++)
			{
				bool fromSource = (bool)dgvDifferent[4, i]->Value;
				bool fromTarget = (bool)dgvDifferent[6, i]->Value;

				String^ value;
				Attribute^ attr;
				if (fromSource)
				{
					//значение источника
					value = dgvDifferent[5, i]->Value->ToString();
				}
				else if (fromTarget)
				{
					//значение получателя
					value = dgvDifferent[7, i]->Value->ToString();
				}
				else
				{
					//реквизит не интегрируется
					continue;
				}

				if (toSource)
				{
					//array<Object^, 2>^ arr = _pos->Differences[i];
					//// атрибут источника
					//attr = (Attribute^) arr[0,0];
					AttributePair^ attrPair = _pos->DifferencesAttrPair[i];
					if (attrPair->SimpleSourceAttribute == nullptr)
					{
						success = false;
						MessageBox::Show("Нельзя внести значение комплексного атрибута " + attrPair->SourceComplexName + " в справочник источник!");
						return success;
					}
					attr = attrPair->SimpleSourceAttribute;
				}
				else
				{
					//array<Object^, 2>^ arr = _pos->Differences[i];
					//// атрибут получателя
					//attr = (Attribute^) arr[1,0];
					AttributePair^ attrPair = _pos->DifferencesAttrPair[i];
					if (attrPair->SimpleTargetAttribute == nullptr)
					{
						success = false;
						MessageBox::Show("Нельзя внести значение комплексного атрибута " + attrPair->TargetComplexName + " в справочник получатель!");
						return success;
					}
					attr = attrPair->SimpleTargetAttribute;

				}
				newAttrVals->Add(attr, value);
			}
			if (newAttrVals->Count <= 0)
			{
				MessageBox::Show("Не выбран ни один реквизит для интеграции!");
				return false;
			}
			NewAttrNames = newAttrVals;
			return success;
		}

		void SetDgvs1()
		{
			for each(array<Object^>^ arr in _pos->Equals)
			{
				array<String^>^ arrS = gcnew array<String ^>(5);
				arrS[0] = ((Attribute^)arr[0])->Name;
				arrS[1] = ((Attribute^)arr[0])->FullCode;
				arrS[2] = ((Attribute^)arr[1])->Name;
				arrS[3] = ((Attribute^)arr[1])->FullCode;
				arrS[4] = arr[2]->ToString();
				dgvEqual->Rows->Add(arrS);
			}

			for each(array<Object^, 2>^ arr in _pos->Differences)
			{
				array<Object^>^ arrS = gcnew array<Object ^>(8);
				arrS[0] = ((Attribute^)arr[0, 0])->Name;
				arrS[1] = ((Attribute^)arr[0, 0])->FullCode;
				arrS[2] = ((Attribute^)arr[1, 0])->Name;
				arrS[3] = ((Attribute^)arr[1, 0])->FullCode;
				arrS[4] = true;
				arrS[5] = arr[0, 1]->ToString();
				arrS[6] = false;
				arrS[7] = arr[1, 1]->ToString();
				dgvDifferent->Rows->Add(arrS);
			}
		}

		void SetDgvs()
		{
			for each(AttributePair^ attrPair in _pos->EqualsAttrPair)
			{
				array<String^>^ arrS = gcnew array<String ^>(5);
				if (attrPair->SimpleSourceAttribute != nullptr)
				{
					arrS[0] = attrPair->SimpleSourceAttribute->Name;
					arrS[1] = attrPair->SimpleSourceAttribute->FullCode;
				}
				else
				{
					arrS[0] = attrPair->SourceComplexName;
					arrS[1] = attrPair->SourceComplexType;
				}

				if (attrPair->SimpleTargetAttribute != nullptr)
				{
					arrS[2] = attrPair->SimpleTargetAttribute->Name;
					arrS[3] = attrPair->SimpleTargetAttribute->FullCode;
				}
				else
				{
					arrS[2] = attrPair->TargetComplexName;
					arrS[3] = attrPair->TargetComplexType;
				}
				arrS[4] = attrPair->SourceValue;
				dgvEqual->Rows->Add(arrS);
			}

			List<AttributePair^>^ attrPairs = _pos->DifferencesAttrPair;
			for (int i = 0; i < attrPairs->Count; i++)
			{
				array<Object^>^ arrS = gcnew array<Object ^>(9);
				if (attrPairs[i]->SimpleSourceAttribute != nullptr)
				{
					arrS[0] = attrPairs[i]->SimpleSourceAttribute->Name;
					arrS[1] = attrPairs[i]->SimpleSourceAttribute->FullCode;
				}
				else
				{
					arrS[0] = attrPairs[i]->SourceComplexName;
					arrS[1] = attrPairs[i]->SourceComplexType;
				}

				if (attrPairs[i]->SimpleTargetAttribute != nullptr)
				{
					arrS[2] = attrPairs[i]->SimpleTargetAttribute->Name;
					arrS[3] = attrPairs[i]->SimpleTargetAttribute->FullCode;
				}
				else
				{
					arrS[2] = attrPairs[i]->TargetComplexName;
					arrS[3] = attrPairs[i]->TargetComplexType;
				}
				arrS[4] = true;
				arrS[5] = attrPairs[i]->SourceValue;
				arrS[6] = false;
				arrS[7] = attrPairs[i]->TargetValue;
				dgvDifferent->Rows->Add(arrS);
			}
		}

	private: System::Void DifferencesForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 SetDgvs();
			 }
private: System::Void bClose_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 NewAttrNames = nullptr;
			 Close();
		 }
private: System::Void dgvDifferent_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (e->RowIndex < 0)
			 {
				 return;
			 }

			 if (e->ColumnIndex == 4 || e->ColumnIndex == 6)
			 {
				 bool isTwoFalse = false;
				 bool value = (bool)dgvDifferent[e->ColumnIndex, e->RowIndex]->Value;
				 if (e->ColumnIndex == 4)
				 {
					 bool bVal = (bool) dgvDifferent[4, e->RowIndex]->Value;
					 if (bVal == true)
					 {
						 dgvDifferent[6, e->RowIndex]->Value = !value;
					 }
				 }
				 else
				 {
					 bool bVal = (bool) dgvDifferent[6, e->RowIndex]->Value;
					 if (bVal == true)
					 {
						 dgvDifferent[4, e->RowIndex]->Value = !value;
					 }
				 }
				 for (int i = 0; i < dgvDifferent->Rows->Count; i++)
				 {
					 /*Object^ cell1 = dgvDifferent[4, i]->Value;
					 Object^ cell2 = dgvDifferent[6, i]->Value;
					 if ((cell1 == nullptr || (bool)(cell1) == false) && 
						 (cell2 == nullptr || (bool)(cell2) == false))
					 {
						 isTwoFalse = true;
						 break;
					 }*/
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
			 if (SetNewAttrVals(false))
			 {
				 InTarget = true;
				 Close();
			 }
		 }
private: System::Void bIntegInSource_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (SetNewAttrVals(true))
			 {
				 InTarget = false;
				 Close();
			 }

		 }
};
}
