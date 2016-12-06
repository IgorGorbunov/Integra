#pragma once
#include "AddEditGroupForm.h"
#include "BookSettings.h"

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
		Dictionary<Attribute^,Attribute^>^ attrPairs;

	private:
		BookSettings^ _sourceBook;
		BookSettings^ _targetBook;
		List<Attribute^>^ _sourceAttrs;
		List<Attribute^>^ _targetAttrs;
		List<Attribute^>^ _sourceAttrsFree;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  ColumnSourceCode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  ColumnTargetCode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  pListBox;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel5;
			 List<Attribute^>^ _targetAttrsFree;


	public:
		AddGroupLinksForm(BookSettings^ sourceBook, BookSettings^ targetBook)
		{
			InitializeComponent();
			_sourceBook = sourceBook;
			_targetBook = targetBook;
			if (!_sourceBook->HasGroup || !_targetBook->HasGroup)
			{
				pGroup->Visible = false;
			}
			SetDgvSources();
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
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Button^  bOk;





	private: System::Windows::Forms::Panel^  pGroup;
	private: System::Windows::Forms::Panel^  panel2;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  pDgv;



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
			this->ColumnSourceCode = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnTargetCode = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->pGroup = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pListBox = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pDgv = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgv))->BeginInit();
			this->pGroup->SuspendLayout();
			this->panel4->SuspendLayout();
			this->pListBox->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel1->SuspendLayout();
			this->pDgv->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbGroups
			// 
			this->lbGroups->BackColor = System::Drawing::SystemColors::Window;
			this->lbGroups->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lbGroups->FormattingEnabled = true;
			this->lbGroups->Location = System::Drawing::Point(10, 10);
			this->lbGroups->Name = L"lbGroups";
			this->lbGroups->Size = System::Drawing::Size(766, 166);
			this->lbGroups->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Padding = System::Windows::Forms::Padding(20, 10, 10, 0);
			this->label1->Size = System::Drawing::Size(77, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Группы:";
			// 
			// bAddGroup
			// 
			this->bAddGroup->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddGroup->Location = System::Drawing::Point(15, 13);
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
			this->button2->Location = System::Drawing::Point(15, 42);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Изменить";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button3->Location = System::Drawing::Point(15, 71);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Удалить";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// dgv
			// 
			this->dgv->AllowUserToDeleteRows = false;
			this->dgv->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dgv->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->ColumnSourceCode, 
				this->Column1, this->Column5, this->Column7, this->ColumnTargetCode, this->Column4, this->Column6, this->Column8});
			this->dgv->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgv->Location = System::Drawing::Point(13, 13);
			this->dgv->Name = L"dgv";
			this->dgv->RowHeadersVisible = false;
			this->dgv->Size = System::Drawing::Size(867, 223);
			this->dgv->TabIndex = 5;
			this->dgv->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AddGroupLinksForm::dgv_CellValueChanged);
			// 
			// ColumnSourceCode
			// 
			this->ColumnSourceCode->HeaderText = L"Обозначение реквизита системы-источника";
			this->ColumnSourceCode->Name = L"ColumnSourceCode";
			this->ColumnSourceCode->Width = 215;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Наименование реквизита системы-источника";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 242;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Тип данных";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 84;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Размер";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Width = 71;
			// 
			// ColumnTargetCode
			// 
			this->ColumnTargetCode->HeaderText = L"Обозначение реквизита системы-получателя";
			this->ColumnTargetCode->Name = L"ColumnTargetCode";
			this->ColumnTargetCode->Width = 220;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Наименование реквизита системы-получателя";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 247;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Тип данных";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 84;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Размер";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Width = 71;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(108, 16);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 6;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &AddGroupLinksForm::bCancel_Click);
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(17, 16);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 7;
			this->bOk->Text = L"Сохранить";
			this->bOk->UseVisualStyleBackColor = true;
			this->bOk->Click += gcnew System::EventHandler(this, &AddGroupLinksForm::bOk_Click);
			// 
			// pGroup
			// 
			this->pGroup->Controls->Add(this->panel4);
			this->pGroup->Controls->Add(this->panel3);
			this->pGroup->Dock = System::Windows::Forms::DockStyle::Top;
			this->pGroup->Location = System::Drawing::Point(0, 0);
			this->pGroup->Name = L"pGroup";
			this->pGroup->Size = System::Drawing::Size(893, 209);
			this->pGroup->TabIndex = 8;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->pListBox);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(786, 209);
			this->panel4->TabIndex = 6;
			// 
			// pListBox
			// 
			this->pListBox->Controls->Add(this->lbGroups);
			this->pListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pListBox->Location = System::Drawing::Point(0, 23);
			this->pListBox->Name = L"pListBox";
			this->pListBox->Padding = System::Windows::Forms::Padding(10);
			this->pListBox->Size = System::Drawing::Size(786, 186);
			this->pListBox->TabIndex = 3;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->bAddGroup);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Controls->Add(this->button2);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel3->Location = System::Drawing::Point(786, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(107, 209);
			this->panel3->TabIndex = 5;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 458);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(893, 51);
			this->panel2->TabIndex = 9;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->bCancel);
			this->panel5->Controls->Add(this->bOk);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel5->Location = System::Drawing::Point(693, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(200, 51);
			this->panel5->TabIndex = 8;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pDgv);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 209);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(893, 249);
			this->panel1->TabIndex = 10;
			// 
			// pDgv
			// 
			this->pDgv->Controls->Add(this->dgv);
			this->pDgv->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pDgv->Location = System::Drawing::Point(0, 0);
			this->pDgv->Name = L"pDgv";
			this->pDgv->Padding = System::Windows::Forms::Padding(13);
			this->pDgv->Size = System::Drawing::Size(893, 249);
			this->pDgv->TabIndex = 6;
			// 
			// AddGroupLinksForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(893, 509);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->pGroup);
			this->MinimumSize = System::Drawing::Size(16, 535);
			this->Name = L"AddGroupLinksForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление/редактирование групповых связей";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgv))->EndInit();
			this->pGroup->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->pListBox->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->pDgv->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		private:
			void SetDgvSources()
			{
				_sourceAttrs = _sourceBook->GetUseAttrs();
				_targetAttrs = _targetBook->GetUseAttrs();
				_sourceAttrsFree = _sourceAttrs;
				_targetAttrsFree = _targetAttrs;

				SetColumnCode(ColumnSourceCode,  _sourceAttrsFree);
				SetColumnCode(ColumnTargetCode,  _targetAttrsFree);
			}

			void SetColumnCode(DataGridViewComboBoxColumn^ column, List<Attribute^>^ list)
			{
				column->Items->Clear();
				for each (Attribute^ attr in list)
				{
					column->Items->Add(attr->FullCode);
				}
				/*DataGridViewComboBoxCell^ comboBoxCell = (DataGridViewComboBoxCell^)dgv[iCol, iRow];
				comboBoxCell->Items->Clear();
				for each (Attribute^ attr in list)
				{
				comboBoxCell->Items->Add(attr->FullCode);
				}*/
			}

			void RemoveFromList(List<Attribute^>^ list, String^ code)
			{
				for each (Attribute^ attr in list)
				{
					if (attr->FullCode == code)
					{
						list->Remove(attr);
						return;
					}
				}
			}

			Attribute^ GetAttr(List<Attribute^>^ list, String^ code)
			{
				for each (Attribute^ attr in list)
				{
					if (attr->FullCode == code)
					{
						return attr;
					}
				}
			}

	private: System::Void bAddGroup_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 AddEditGroupForm^ form = gcnew AddEditGroupForm();
				 form->ShowDialog();
				 if (form->GroupName != nullptr)
				 {
					 lbGroups->Items->Add(form->GroupName + " " + form->DoubleName);
				 }


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

			 if (e->ColumnIndex == 0)
			 {

			 }
			 if (e->ColumnIndex == 4)
			 {

			 }
		 }
private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 attrPairs = nullptr;
			 Close();
		 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 attrPairs = gcnew Dictionary<Attribute ^, Attribute ^>();
			 for (int i = 0; i < dgv->Rows->Count; i++)
			 {
				 Object^ o1 = dgv[0, i]->Value;
				 Object^ o2 = dgv[4, i]->Value;
				 if (o1 != nullptr  &&  o2 != nullptr)
				 {
					 Attribute^ aS = GetAttr(_sourceAttrs, o1->ToString());
					 Attribute^ aT = GetAttr(_targetAttrs, o2->ToString());
					 attrPairs->Add(aS, aT);
				 }
			 }
			 
			 Close();
		 }
};
}
