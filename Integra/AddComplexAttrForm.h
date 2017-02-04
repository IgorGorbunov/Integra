#pragma once

#include "Attribute.h"
#include "ComplexAttribute.h"
#include "ODBCclass.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddComplexAttr
	/// </summary>
	public ref class AddComplexAttrForm : public System::Windows::Forms::Form
	{
	public:
		ComplexAttribute^ complexAttr;


	private:
		OdbcClass^ _odbc;
		List<Attribute^>^ _recAttrs;
		List<Attribute^>^ _selectAttrs;

		


	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataGridView^  dgvCompose;

	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Panel^  pSplitter;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  cbSelectPart;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Panel^  pFirstSymbol;

	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rbSplitter;

	private: System::Windows::Forms::RadioButton^  rbFirstSymbol;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TextBox^  tbName;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  DataTypeColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  _ValueColumn;
	private: System::Windows::Forms::ComboBox^  cbRecAttr;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  cbSelectAttr;
	private: System::Windows::Forms::Button^  bOk;
	private: System::Windows::Forms::Button^  bCancel;
			 System::ComponentModel::Container ^components;


	public:
		AddComplexAttrForm(List<Attribute^>^ recAttrs, List<Attribute^>^ selectAttrs, OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
			_recAttrs = recAttrs;
			_selectAttrs = selectAttrs;
			SetRecAttr();
			SetComposeSelectAttrs();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddComplexAttrForm()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cbSelectAttr = (gcnew System::Windows::Forms::ComboBox());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dgvCompose = (gcnew System::Windows::Forms::DataGridView());
			this->DataTypeColumn = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->_ValueColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->pSplitter = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cbSelectPart = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->pFirstSymbol = (gcnew System::Windows::Forms::Panel());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rbSplitter = (gcnew System::Windows::Forms::RadioButton());
			this->rbFirstSymbol = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->cbRecAttr = (gcnew System::Windows::Forms::ComboBox());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvCompose))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->pSplitter->SuspendLayout();
			this->pFirstSymbol->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Реквизит для выборки:";
			// 
			// cbSelectAttr
			// 
			this->cbSelectAttr->FormattingEnabled = true;
			this->cbSelectAttr->Location = System::Drawing::Point(19, 30);
			this->cbSelectAttr->Name = L"cbSelectAttr";
			this->cbSelectAttr->Size = System::Drawing::Size(214, 21);
			this->cbSelectAttr->TabIndex = 3;
			this->cbSelectAttr->SelectedIndexChanged += gcnew System::EventHandler(this, &AddComplexAttrForm::cbAttr_SelectedIndexChanged);
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(397, 16);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 4;
			this->bOk->Text = L"ОК";
			this->bOk->UseVisualStyleBackColor = true;
			this->bOk->Click += gcnew System::EventHandler(this, &AddComplexAttrForm::bOk_Click);
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(489, 16);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 5;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &AddComplexAttrForm::bCancel_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(10, 10);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(541, 267);
			this->tabControl1->TabIndex = 6;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->dgvCompose);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(533, 241);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Композиция";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 11);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(137, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Данные для композиции:";
			// 
			// dgvCompose
			// 
			this->dgvCompose->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCompose->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->DataTypeColumn, 
				this->_ValueColumn});
			this->dgvCompose->Location = System::Drawing::Point(18, 23);
			this->dgvCompose->Name = L"dgvCompose";
			this->dgvCompose->Size = System::Drawing::Size(498, 198);
			this->dgvCompose->TabIndex = 0;
			// 
			// _DataTypeColumn
			// 
			this->DataTypeColumn->HeaderText = L"Вид данных";
			this->DataTypeColumn->Name = L"_DataTypeColumn";
			this->DataTypeColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->DataTypeColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->DataTypeColumn->Width = 200;
			// 
			// _ValueColumn
			// 
			this->_ValueColumn->HeaderText = L"Значение";
			this->_ValueColumn->Name = L"_ValueColumn";
			this->_ValueColumn->Width = 200;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton4);
			this->groupBox2->Controls->Add(this->radioButton3);
			this->groupBox2->Location = System::Drawing::Point(18, 20);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(244, 79);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Принцип композиции";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(16, 44);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(129, 17);
			this->radioButton4->TabIndex = 1;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"В виде целого числа";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(16, 20);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(97, 17);
			this->radioButton3->TabIndex = 0;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"В виде строки";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->pSplitter);
			this->tabPage2->Controls->Add(this->pFirstSymbol);
			this->tabPage2->Controls->Add(this->panel1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(533, 241);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Выборка";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// pSplitter
			// 
			this->pSplitter->Controls->Add(this->label6);
			this->pSplitter->Controls->Add(this->cbSelectPart);
			this->pSplitter->Controls->Add(this->label5);
			this->pSplitter->Controls->Add(this->textBox3);
			this->pSplitter->Dock = System::Windows::Forms::DockStyle::Top;
			this->pSplitter->Location = System::Drawing::Point(3, 231);
			this->pSplitter->Name = L"pSplitter";
			this->pSplitter->Size = System::Drawing::Size(527, 79);
			this->pSplitter->TabIndex = 9;
			this->pSplitter->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(169, 18);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(116, 13);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Используемая часть:";
			// 
			// cbSelectPart
			// 
			this->cbSelectPart->FormattingEnabled = true;
			this->cbSelectPart->Location = System::Drawing::Point(172, 34);
			this->cbSelectPart->Name = L"cbSelectPart";
			this->cbSelectPart->Size = System::Drawing::Size(120, 21);
			this->cbSelectPart->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 18);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(120, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Символы разделения:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(19, 34);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(120, 20);
			this->textBox3->TabIndex = 0;
			// 
			// pFirstSymbol
			// 
			this->pFirstSymbol->Controls->Add(this->numericUpDown2);
			this->pFirstSymbol->Controls->Add(this->numericUpDown1);
			this->pFirstSymbol->Controls->Add(this->label4);
			this->pFirstSymbol->Controls->Add(this->label1);
			this->pFirstSymbol->Dock = System::Windows::Forms::DockStyle::Top;
			this->pFirstSymbol->Location = System::Drawing::Point(3, 155);
			this->pFirstSymbol->Name = L"pFirstSymbol";
			this->pFirstSymbol->Size = System::Drawing::Size(527, 76);
			this->pFirstSymbol->TabIndex = 8;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(172, 34);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 20);
			this->numericUpDown2->TabIndex = 5;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(19, 34);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 4;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(169, 14);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(122, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Количество символов:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(135, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Номер первого символа:";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->cbSelectAttr);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(527, 152);
			this->panel1->TabIndex = 7;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rbSplitter);
			this->groupBox1->Controls->Add(this->rbFirstSymbol);
			this->groupBox1->Location = System::Drawing::Point(19, 68);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(286, 74);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Принцип выборки:";
			// 
			// rbSplitter
			// 
			this->rbSplitter->AutoSize = true;
			this->rbSplitter->Location = System::Drawing::Point(16, 50);
			this->rbSplitter->Name = L"rbSplitter";
			this->rbSplitter->Size = System::Drawing::Size(181, 17);
			this->rbSplitter->TabIndex = 5;
			this->rbSplitter->Text = L"Через разделение символами";
			this->rbSplitter->UseVisualStyleBackColor = true;
			this->rbSplitter->CheckedChanged += gcnew System::EventHandler(this, &AddComplexAttrForm::rbSplitter_CheckedChanged);
			// 
			// rbFirstSymbol
			// 
			this->rbFirstSymbol->AutoSize = true;
			this->rbFirstSymbol->Checked = true;
			this->rbFirstSymbol->Location = System::Drawing::Point(16, 26);
			this->rbFirstSymbol->Name = L"rbFirstSymbol";
			this->rbFirstSymbol->Size = System::Drawing::Size(253, 17);
			this->rbFirstSymbol->TabIndex = 4;
			this->rbFirstSymbol->TabStop = true;
			this->rbFirstSymbol->Text = L"Через номер первого символа и количество";
			this->rbFirstSymbol->UseVisualStyleBackColor = true;
			this->rbFirstSymbol->CheckedChanged += gcnew System::EventHandler(this, &AddComplexAttrForm::rbFirstSymbol_CheckedChanged);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->cbRecAttr);
			this->panel2->Controls->Add(this->tbName);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(581, 66);
			this->panel2->TabIndex = 7;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(287, 17);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(118, 13);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Реквизит для записи:";
			// 
			// cbRecAttr
			// 
			this->cbRecAttr->FormattingEnabled = true;
			this->cbRecAttr->Location = System::Drawing::Point(290, 33);
			this->cbRecAttr->Name = L"cbRecAttr";
			this->cbRecAttr->Size = System::Drawing::Size(214, 21);
			this->cbRecAttr->TabIndex = 5;
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(24, 34);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(250, 20);
			this->tbName->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(21, 18);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(218, 13);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Наименование комплексного реквизита:";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->bOk);
			this->panel3->Controls->Add(this->bCancel);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 373);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(581, 56);
			this->panel3->TabIndex = 8;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(0, 66);
			this->panel4->Name = L"panel4";
			this->panel4->Padding = System::Windows::Forms::Padding(10);
			this->panel4->Size = System::Drawing::Size(581, 307);
			this->panel4->TabIndex = 9;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->tabControl1);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(10, 10);
			this->panel5->Name = L"panel5";
			this->panel5->Padding = System::Windows::Forms::Padding(10);
			this->panel5->Size = System::Drawing::Size(561, 287);
			this->panel5->TabIndex = 7;
			// 
			// AddComplexAttrForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(581, 429);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"AddComplexAttrForm";
			this->Text = L"Добавление комплексного реквизита";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvCompose))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->pSplitter->ResumeLayout(false);
			this->pSplitter->PerformLayout();
			this->pFirstSymbol->ResumeLayout(false);
			this->pFirstSymbol->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		private:
			void SetRecAttr()
			{
				cbRecAttr->Items->Clear();
				for each (Attribute^ attr in _recAttrs)
				{
					if (String::IsNullOrEmpty(attr->Name))
					{
						cbRecAttr->Items->Add(attr->FullCode);
					}
					else
					{
						cbRecAttr->Items->Add(attr->Name);
					}
				}
			}

			void SetComposeSelectAttrs()
			{
				cbSelectAttr->Items->Clear();
				for each (Attribute^ attr in _selectAttrs)
				{
					if (String::IsNullOrEmpty(attr->Name))
					{
						cbSelectAttr->Items->Add(attr->FullCode);
					}
					else
					{
						cbSelectAttr->Items->Add(attr->Name);
					}
				}

				DataTypeColumn->Items->Clear();
				DataTypeColumn->Items->Add("^Символьное значение");
				for each (Attribute^ attr in _selectAttrs)
				{
					if (String::IsNullOrEmpty(attr->Name))
					{
						DataTypeColumn->Items->Add(attr->FullCode);
					}
					else
					{
						DataTypeColumn->Items->Add(attr->Name);
					}
				}

				cbSelectPart->Items->Clear();
				cbSelectPart->Items->Add("1-ая часть");
				cbSelectPart->Items->Add("2-ая часть");
				cbSelectPart->Items->Add("3-ая часть");
				cbSelectPart->Items->Add("4-ая часть");
				cbSelectPart->Items->Add("5-ая часть");
				cbSelectPart->Items->Add("6-ая часть");
				cbSelectPart->Items->Add("7-ая часть");
				cbSelectPart->Items->Add("8-ая часть");
				cbSelectPart->Items->Add("9-ая часть");
				cbSelectPart->Items->Add("10-ая часть");
			}

			void SetDgv()
			{

			}

	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 complexAttr = nullptr;
				 Close();
			 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 complexAttr = gcnew ComplexAttribute(_odbc, nullptr, tbName->Text->Trim());
			 Close();
		 }
private: System::Void cbAttr_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {

		 }
private: System::Void rbFirstSymbol_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (rbFirstSymbol->Checked == true)
			 {
				 pFirstSymbol->Visible = true;
				 pSplitter->Visible = false;
			 }
		 }
private: System::Void rbSplitter_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (rbSplitter->Checked == true)
			 {
				 pFirstSymbol->Visible = false;
				 pSplitter->Visible = true;
			 }
		 }
};
}
