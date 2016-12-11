#pragma once

#include "Position.h"
#include "DiffererncePosition.h"
#include "DifferencesForm.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Results
	/// </summary>
	public ref class Results : public System::Windows::Forms::Form
	{
	public:
		List<Position^>^ _sourceNew;
		List<Position^>^ _targetNew;
		List<DifferencePosition^>^ _differences;

	private:
		int selectId;

	public:
		Results (List<Position^>^ sourceNew, List<Position^>^ targetNew, List<DifferencePosition^>^ differences)
		{
			InitializeComponent();
			_sourceNew = sourceNew;
			_targetNew = targetNew;
			_differences = differences;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Results()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dgvSourceNew;
	private: System::Windows::Forms::DataGridView^  dgvTargetNew;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ListBox^  lbDifferences;



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
			this->dgvSourceNew = (gcnew System::Windows::Forms::DataGridView());
			this->dgvTargetNew = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lbDifferences = (gcnew System::Windows::Forms::ListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSourceNew))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTargetNew))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvSourceNew
			// 
			this->dgvSourceNew->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvSourceNew->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSourceNew->Location = System::Drawing::Point(26, 33);
			this->dgvSourceNew->Name = L"dgvSourceNew";
			this->dgvSourceNew->Size = System::Drawing::Size(556, 150);
			this->dgvSourceNew->TabIndex = 0;
			// 
			// dgvTargetNew
			// 
			this->dgvTargetNew->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvTargetNew->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTargetNew->Location = System::Drawing::Point(26, 213);
			this->dgvTargetNew->Name = L"dgvTargetNew";
			this->dgvTargetNew->Size = System::Drawing::Size(556, 150);
			this->dgvTargetNew->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(190, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Новые записи в системе источнике";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 197);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(195, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Новые записи в системе получателе";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(603, 17);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(208, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Записи с различающимися атрибутами";
			// 
			// lbDifferences
			// 
			this->lbDifferences->FormattingEnabled = true;
			this->lbDifferences->Location = System::Drawing::Point(606, 34);
			this->lbDifferences->Name = L"lbDifferences";
			this->lbDifferences->Size = System::Drawing::Size(232, 329);
			this->lbDifferences->TabIndex = 6;
			this->lbDifferences->SelectedIndexChanged += gcnew System::EventHandler(this, &Results::lbDifferences_SelectedIndexChanged);
			this->lbDifferences->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Results::lbDifferences_MouseDoubleClick);
			// 
			// Results
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(881, 399);
			this->Controls->Add(this->lbDifferences);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dgvTargetNew);
			this->Controls->Add(this->dgvSourceNew);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Results";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Результаты";
			this->Load += gcnew System::EventHandler(this, &Results::Results_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSourceNew))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTargetNew))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		void SetDgvNew(DataGridView^ grid, List<Position^>^ positions)
		{
			if (positions->Count > 0)
			{
				Dictionary<Attribute^, String^>^ attrs =  positions[0]->AttributesAndValues;
				for each (KeyValuePair<Attribute^, String^>^ pair in attrs)
				{
					DataGridViewTextBoxColumn^ col = gcnew DataGridViewTextBoxColumn();
					col->Name = pair->Key->Code;
					col->HeaderText = pair->Key->Code;
					grid->Columns->Add(col);
				}
				for each (Position^ pos in positions)
				{
					Dictionary<Attribute^, String^>^ attrs = pos->AttributesAndValues;
					array<String^>^ row = gcnew array<String ^>(attrs->Count);
					int i = 0;
					for each (KeyValuePair<Attribute^, String^>^ pair in attrs)
					{
						row[i] = pair->Value;
						i++;
					}
					grid->Rows->Add(row);
				}
			}
			
		}

		void SetListDiff()
		{
			if (_differences->Count > 0)
			{
				for each (DifferencePosition^ pos in _differences)
				{
					lbDifferences->Items->Add(pos->UnicId);
				}
			}

		}


private: System::Void Results_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetDgvNew(dgvSourceNew, _sourceNew);
			 SetDgvNew(dgvTargetNew, _targetNew);
			 SetListDiff();
		 }
private: System::Void lbDifferences_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 if (lbDifferences->SelectedItem != nullptr)
			 {
				 for each (DifferencePosition^ pos in _differences)
				 {
					 if (pos->UnicId == lbDifferences->SelectedItem->ToString())
					 {
						 DifferencesForm^ form = gcnew DifferencesForm(pos);
						 form->ShowDialog();
						 break;
					 }
				 }
			 }
		 }
private: System::Void lbDifferences_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 
		 }
};
}
