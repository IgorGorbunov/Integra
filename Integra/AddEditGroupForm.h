#pragma once

#include "Book.h"
#include "DbBook.h"
#include "IntegrationGroupPair.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddEditGroupForm
	/// </summary>
	public ref class AddEditGroupForm : public System::Windows::Forms::Form
	{
		public:
			IntegrationGroupPair^ IntegrationGroup;

	private:
		BookSettings^ _sourceSettingsBook;
		BookSettings^ _targetSettingsBook;

		Book^ _sourceBook;
		Book^ _targetBook;
		OdbcClass^ _odbc;
	
	public:
		AddEditGroupForm(BookSettings^ sourceBook, BookSettings^ targetBook, OdbcClass^ odbc)
		{
			InitializeComponent();

			_odbc = odbc;
			_sourceSettingsBook = sourceBook;
			_targetSettingsBook = targetBook;
			if (_sourceSettingsBook->IsSemantic)
			{
				tvSource->Visible = true;
				dgvSource->Visible = false;
			}
			else
			{
				tvSource->Visible = false;
				dgvSource->Visible = true;
			}
			if (_targetSettingsBook->IsSemantic)
			{
				tvTarget->Visible = true;
				dgvTarget->Visible = false;
			}
			else
			{
				tvTarget->Visible = false;
				dgvTarget->Visible = true;
			}
			LoadSourceGroups();
			LoadTargetGroups();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddEditGroupForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tbName;
	private: System::Windows::Forms::DataGridView^  dgvSource;

	private: System::Windows::Forms::TreeView^  tvSource;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataGridView^  dgvTarget;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Button^  bOk;
			 System::Windows::Forms::DataGridViewTextBoxColumn^ IdColT;
			 System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
			 System::Windows::Forms::DataGridViewTextBoxColumn^ IdColS;
			 System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;

	private: System::Windows::Forms::TreeView^  tvTarget;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		void LoadSourceGroups()
		{
			
			if (_sourceSettingsBook->IsSemantic)
			{
				//todo
			}
			else
			{
				_sourceBook = gcnew DbBook(_sourceSettingsBook, nullptr, true, _odbc);
				Dictionary<String^, String^>^ grNames = _sourceBook->GetAllGroupNames();
				dgvSource->Rows->Clear();
				for each (KeyValuePair<String^, String^>^ s in grNames)
				{
					array<String^>^ row = gcnew array<String ^>(2);
					row[0] = s->Key;
					row[1] = s->Value;
					dgvSource->Rows->Add(row);
				}
			}
		}

		void LoadTargetGroups()
		{
			
			if (_targetSettingsBook->IsSemantic)
			{
				//todo
			}
			else
			{
				_targetBook = gcnew DbBook(_targetSettingsBook, nullptr, false, _odbc);
				Dictionary<String^, String^>^ grNames = _targetBook->GetAllGroupNames();
				dgvTarget->Rows->Clear();
				for each (KeyValuePair<String^, String^>^ s in grNames)
				{
					array<String^>^ row = gcnew array<String ^>(2);
					row[0] = s->Key;
					row[1] = s->Value;
					dgvTarget->Rows->Add(row);
				}
			}
		}


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->tvSource = (gcnew System::Windows::Forms::TreeView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dgvTarget = (gcnew System::Windows::Forms::DataGridView());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->dgvSource = (gcnew System::Windows::Forms::DataGridView());
			this->tvTarget = (gcnew System::Windows::Forms::TreeView());
			this->IdColT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->IdColS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTarget))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSource))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Наименование";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(24, 36);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(630, 20);
			this->tbName->TabIndex = 1;
			// 
			// tvSource
			// 
			this->tvSource->BackColor = System::Drawing::SystemColors::Window;
			this->tvSource->Location = System::Drawing::Point(24, 97);
			this->tvSource->Name = L"tvSource";
			this->tvSource->Size = System::Drawing::Size(291, 196);
			this->tvSource->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Система-источник:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(360, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Система-приемник:";
			// 
			// dgvTarget
			// 
			this->dgvTarget->AllowUserToAddRows = false;
			this->dgvTarget->AllowUserToDeleteRows = false;
			this->dgvTarget->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgvTarget->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTarget->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->IdColT, this->Column1});
			this->dgvTarget->Location = System::Drawing::Point(350, 92);
			this->dgvTarget->Name = L"dgvTarget";
			this->dgvTarget->ReadOnly = true;
			this->dgvTarget->RowHeadersVisible = false;
			this->dgvTarget->Size = System::Drawing::Size(291, 196);
			this->dgvTarget->TabIndex = 5;
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(579, 304);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 6;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &AddEditGroupForm::bCancel_Click);
			// 
			// bOk
			// 
			this->bOk->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bOk->Location = System::Drawing::Point(485, 304);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 7;
			this->bOk->Text = L"ОК";
			this->bOk->UseVisualStyleBackColor = false;
			this->bOk->Click += gcnew System::EventHandler(this, &AddEditGroupForm::bOk_Click);
			// 
			// dgvSource
			// 
			this->dgvSource->AllowUserToAddRows = false;
			this->dgvSource->AllowUserToDeleteRows = false;
			this->dgvSource->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgvSource->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSource->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->IdColS, this->dataGridViewTextBoxColumn1});
			this->dgvSource->Location = System::Drawing::Point(24, 92);
			this->dgvSource->Name = L"dgvSource";
			this->dgvSource->ReadOnly = true;
			this->dgvSource->RowHeadersVisible = false;
			this->dgvSource->Size = System::Drawing::Size(291, 196);
			this->dgvSource->TabIndex = 8;
			// 
			// tvTarget
			// 
			this->tvTarget->BackColor = System::Drawing::SystemColors::Window;
			this->tvTarget->Location = System::Drawing::Point(350, 97);
			this->tvTarget->Name = L"tvTarget";
			this->tvTarget->Size = System::Drawing::Size(291, 196);
			this->tvTarget->TabIndex = 9;
			// 
			// IdColT
			// 
			this->IdColT->HeaderText = L"Id";
			this->IdColT->Name = L"IdColT";
			this->IdColT->ReadOnly = true;
			this->IdColT->Visible = false;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Наименование";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 280;
			// 
			// IdColS
			// 
			this->IdColS->HeaderText = L"Id";
			this->IdColS->Name = L"IdColS";
			this->IdColS->ReadOnly = true;
			this->IdColS->Visible = false;
			this->IdColS->Width = 280;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Наименование";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 270;
			// 
			// AddEditGroupForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(670, 347);
			this->Controls->Add(this->tvTarget);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->dgvTarget);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tvSource);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dgvSource);
			this->Name = L"AddEditGroupForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление/редактирование интеграционной группы";
			this->Load += gcnew System::EventHandler(this, &AddEditGroupForm::AddEditGroupForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTarget))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSource))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 String^ groupName = tbName->Text;
				 String^ sourceId;
				 String^ sourceName;
				 String^ targetId;
				 String^ targetName;
				 if (_sourceSettingsBook->IsSemantic)
				 {
					 sourceId = tvSource->SelectedNode->Name;
					 sourceName = tvSource->SelectedNode->Text;
				 }
				 else
				 {
					 sourceId = dgvSource[0, dgvSource->SelectedCells[0]->RowIndex]->Value->ToString();
					 sourceName = dgvSource[1, dgvSource->SelectedCells[0]->RowIndex]->Value->ToString();
				 }
				 if (_targetSettingsBook->IsSemantic)
				 {
					 targetId = tvTarget->SelectedNode->Name;
					 targetName = tvTarget->SelectedNode->Text;
				 }
				 else
				 {
					 targetId = dgvTarget[0, dgvTarget->SelectedCells[0]->RowIndex]->Value->ToString();
					 targetName = dgvTarget[1, dgvTarget->SelectedCells[0]->RowIndex]->Value->ToString();
				 }
				 IntegrationGroup = gcnew IntegrationGroupPair(groupName, sourceId, sourceName, targetId, targetName);
				 Close();
			 }
private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void AddEditGroupForm_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 

		 }
};
}
