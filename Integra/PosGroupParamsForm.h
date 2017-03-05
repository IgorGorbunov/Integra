#pragma once

#include "Attribute.h"
#include "PosGroupParams.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PosGroupParamsForm
	/// </summary>
	public ref class PosGroupParamsForm : public System::Windows::Forms::Form
	{
	public:
		List<PosGroupParam^>^ PosParamAttrs;

	private:
		int _addEditType;
		Dictionary<String^, List<Attribute^>^>^ _allAttrs;
		

	public:
		PosGroupParamsForm(int addEditType, Dictionary<String^, List<Attribute^>^>^ allAttrs)
		{
			InitializeComponent();
			_addEditType = addEditType;
			_allAttrs = allAttrs;

			if (_addEditType == 0)
			{
				Text = "Добавить " + Text;
			}
			else
			{
				Text = "Изменить " + Text;
			}
			SetColumnValues();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PosGroupParamsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Button^  bCancel;

	private: System::Windows::Forms::Button^  bOk;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column2;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		void SetColumnValues()
		{
			List<String^>^ list = gcnew List<String ^>();
			for each (KeyValuePair<String^, List<Attribute^>^>^ pair in _allAttrs)
			{
				List<Attribute^>^ attrList = pair->Value;
				for each (Attribute^ attr in attrList)
				{
					list->Add(attr->FullCode);
				}
			}

			Column1->DataSource = list;
			Column2->DataSource = list;

		}

		Attribute^ GetAttr(String^ fullCode)
		{
			for each (KeyValuePair<String^, List<Attribute^>^>^ pair in _allAttrs)
			{
				List<Attribute^>^ attrList = pair->Value;
				for each (Attribute^ attr in attrList)
				{
					if (attr->FullCode == fullCode)
					{
						return attr;
					}
				}
			}
			return nullptr;
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 219);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(426, 49);
			this->panel1->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->bCancel);
			this->panel4->Controls->Add(this->bOk);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel4->Location = System::Drawing::Point(247, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(179, 49);
			this->panel4->TabIndex = 2;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(94, 11);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 0;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &PosGroupParamsForm::bCancel_Click);
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(13, 11);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 1;
			this->bOk->Text = L"ОК";
			this->bOk->UseVisualStyleBackColor = true;
			this->bOk->Click += gcnew System::EventHandler(this, &PosGroupParamsForm::bOk_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(426, 219);
			this->panel2->TabIndex = 1;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->dataGridView1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Padding = System::Windows::Forms::Padding(10);
			this->panel3->Size = System::Drawing::Size(426, 219);
			this->panel3->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Column1, 
				this->Column2});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(10, 10);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(406, 199);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Обозначение";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 200;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Значение";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 200;
			// 
			// PosGroupParamsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 268);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->MinimumSize = System::Drawing::Size(300, 306);
			this->Name = L"PosGroupParamsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"групповые параметры позиций";
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (_addEditType == 0)
				 {
					 PosParamAttrs = nullptr;
					 Close();
				 }
				 else
				 {
					 Close();
				 }
			 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 List<PosGroupParam^>^ PosParamAttrs = gcnew List<PosGroupParam^>();
			 for (int i = 0; i < dataGridView1->RowCount; i++)
			 {
				 if (dataGridView1[0,i]->Value != nullptr && dataGridView1[1,i]->Value != nullptr)
				 {
					 String^ fullCode1 = dataGridView1[0,i]->Value->ToString();
					 String^ fullCode2 = dataGridView1[1,i]->Value->ToString();
					 PosGroupParam^ posParam = gcnew PosGroupParam(GetAttr(fullCode1), GetAttr(fullCode2));
					 PosParamAttrs->Add(posParam);
				 }
			 }
			 Close();
		 }
};
}
