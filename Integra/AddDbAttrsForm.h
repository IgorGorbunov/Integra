#pragma once
#include "AddNewTableForm.h"
#include "ODBCclass.h"
#include "Attribute.h"
#include "DbFiltersForm.h"
#include "TableLinksForm.h"
#include "GroupParamsForm.h"
#include "DbLink.h"
#include "PosGroupParamsForm.h"


namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddAttrsForm
	/// </summary>
	public ref class AddDbAttrsForm : public System::Windows::Forms::Form
	{
	public:
		bool WrongPass;
		Attribute^ IdCol;
		Attribute^ TitleCol;
		Attribute^ DateCol;
		Attribute^ RoughCol;
		String^ RoughSymbols;
		List<Attribute^>^ Attributes;

		String^ GroupSchtab;
		Attribute^ GroupIdCol;
		Attribute^ GroupNameCol;
		Dictionary<Attribute^,Attribute^>^ GroupAttrs;

	private:
		List<String^>^ _fieldNames;
		OdbcClass^ _odbc;
		String^ _filter;
		List<DbLink^>^ _links;

		Dictionary<String^, List<Attribute^>^>^ _allAttrs;
		bool _programCheck;

	private: System::Windows::Forms::Button^  bAddTableLinks;
	private: System::Windows::Forms::Button^  bAddFilter;
	private: System::Windows::Forms::Button^  bGroupParams;
	private: System::Windows::Forms::ComboBox^  cbRoughAttr;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tbRoughSymbols;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label6;








	private: System::Windows::Forms::Button^  bPosGroupParams;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column5;
	private: System::Windows::Forms::ComboBox^  cbDateAttr;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TreeView^  tv;

	public:
		void Init()
		{
			_programCheck = false;
			//todo неверно пишутся атрибуты без схемы
			_allAttrs = gcnew Dictionary<String^, List<Attribute^>^>();
			Attributes = gcnew List<Attribute^>();
			_fieldNames = gcnew List<String ^>();
		}

		AddDbAttrsForm(String^ login, String^ pass, String^ database)
		{
			InitializeComponent();
			Init();
			_odbc = gcnew OdbcClass(login, pass, database);
			TryConnect();
		}

		AddDbAttrsForm(String^ driver)
		{
			InitializeComponent();
			Init();
			_odbc = gcnew OdbcClass(driver);
			TryConnect();
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddDbAttrsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  lbTables;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  bAddNewTable;
	private: System::Windows::Forms::DataGridView^  dgvFields;

	private: System::Windows::Forms::Button^  bClose;
	private: System::Windows::Forms::Button^  bRecord;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cbId;
	private: System::Windows::Forms::ComboBox^  cbTitle;
	private: System::Windows::Forms::Label^  label3;



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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->lbTables = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bAddNewTable = (gcnew System::Windows::Forms::Button());
			this->dgvFields = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->bClose = (gcnew System::Windows::Forms::Button());
			this->bRecord = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbId = (gcnew System::Windows::Forms::ComboBox());
			this->cbTitle = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tv = (gcnew System::Windows::Forms::TreeView());
			this->bAddTableLinks = (gcnew System::Windows::Forms::Button());
			this->bAddFilter = (gcnew System::Windows::Forms::Button());
			this->bGroupParams = (gcnew System::Windows::Forms::Button());
			this->cbRoughAttr = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbRoughSymbols = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->bPosGroupParams = (gcnew System::Windows::Forms::Button());
			this->cbDateAttr = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvFields))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbTables
			// 
			this->lbTables->FormattingEnabled = true;
			this->lbTables->Location = System::Drawing::Point(12, 31);
			this->lbTables->Name = L"lbTables";
			this->lbTables->Size = System::Drawing::Size(429, 134);
			this->lbTables->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Таблицы БД:";
			// 
			// bAddNewTable
			// 
			this->bAddNewTable->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddNewTable->Location = System::Drawing::Point(146, 345);
			this->bAddNewTable->Name = L"bAddNewTable";
			this->bAddNewTable->Size = System::Drawing::Size(170, 30);
			this->bAddNewTable->TabIndex = 5;
			this->bAddNewTable->Text = L"Добавить новую таблицу";
			this->bAddNewTable->UseVisualStyleBackColor = false;
			this->bAddNewTable->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bAddNewTable_Click);
			// 
			// dgvFields
			// 
			this->dgvFields->AllowUserToAddRows = false;
			this->dgvFields->AllowUserToDeleteRows = false;
			this->dgvFields->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvFields->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvFields->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvFields->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->Column1, this->Column2, 
				this->Column3, this->Column4, this->Column8, this->Column5});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvFields->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvFields->Location = System::Drawing::Point(10, 414);
			this->dgvFields->Name = L"dgvFields";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvFields->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dgvFields->RowHeadersVisible = false;
			this->dgvFields->Size = System::Drawing::Size(756, 210);
			this->dgvFields->TabIndex = 6;
			this->dgvFields->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AddDbAttrsForm::dgvFields_CellValueChanged);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Используемость";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Код реквизита";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 80;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Наименование реквизита";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 300;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Тип данных";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 80;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Размерность";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Width = 80;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Может быть пустым";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// bClose
			// 
			this->bClose->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bClose->Location = System::Drawing::Point(666, 640);
			this->bClose->Name = L"bClose";
			this->bClose->Size = System::Drawing::Size(87, 30);
			this->bClose->TabIndex = 8;
			this->bClose->Text = L"Отмена";
			this->bClose->UseVisualStyleBackColor = false;
			this->bClose->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bClose_Click);
			// 
			// bRecord
			// 
			this->bRecord->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bRecord->Location = System::Drawing::Point(559, 640);
			this->bRecord->Name = L"bRecord";
			this->bRecord->Size = System::Drawing::Size(87, 30);
			this->bRecord->TabIndex = 7;
			this->bRecord->Text = L"Сохранить";
			this->bRecord->UseVisualStyleBackColor = false;
			this->bRecord->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bRecord_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(458, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Реквизит-идентификатор:";
			// 
			// cbId
			// 
			this->cbId->Enabled = false;
			this->cbId->FormattingEnabled = true;
			this->cbId->Location = System::Drawing::Point(459, 31);
			this->cbId->Name = L"cbId";
			this->cbId->Size = System::Drawing::Size(309, 21);
			this->cbId->TabIndex = 10;
			this->cbId->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::cbId_Click);
			// 
			// cbTitle
			// 
			this->cbTitle->Enabled = false;
			this->cbTitle->FormattingEnabled = true;
			this->cbTitle->Location = System::Drawing::Point(459, 81);
			this->cbTitle->Name = L"cbTitle";
			this->cbTitle->Size = System::Drawing::Size(307, 21);
			this->cbTitle->TabIndex = 12;
			this->cbTitle->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::cbTitle_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(456, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(110, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Основной реквизит:";
			// 
			// tv
			// 
			this->tv->CheckBoxes = true;
			this->tv->Location = System::Drawing::Point(12, 31);
			this->tv->Name = L"tv";
			this->tv->Size = System::Drawing::Size(429, 308);
			this->tv->TabIndex = 13;
			this->tv->AfterCheck += gcnew System::Windows::Forms::TreeViewEventHandler(this, &AddDbAttrsForm::tv_AfterCheck);
			this->tv->BeforeSelect += gcnew System::Windows::Forms::TreeViewCancelEventHandler(this, &AddDbAttrsForm::tv_BeforeSelect);
			this->tv->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &AddDbAttrsForm::tv_AfterSelect);
			// 
			// bAddTableLinks
			// 
			this->bAddTableLinks->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddTableLinks->Location = System::Drawing::Point(479, 278);
			this->bAddTableLinks->Name = L"bAddTableLinks";
			this->bAddTableLinks->Size = System::Drawing::Size(118, 45);
			this->bAddTableLinks->TabIndex = 14;
			this->bAddTableLinks->Text = L"Добавить связи между таблицами";
			this->bAddTableLinks->UseVisualStyleBackColor = false;
			this->bAddTableLinks->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bAddTableLinks_Click);
			// 
			// bAddFilter
			// 
			this->bAddFilter->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddFilter->Location = System::Drawing::Point(627, 278);
			this->bAddFilter->Name = L"bAddFilter";
			this->bAddFilter->Size = System::Drawing::Size(128, 45);
			this->bAddFilter->TabIndex = 15;
			this->bAddFilter->Text = L"Добавить фильтры";
			this->bAddFilter->UseVisualStyleBackColor = false;
			this->bAddFilter->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bAddFilter_Click);
			// 
			// bGroupParams
			// 
			this->bGroupParams->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bGroupParams->Location = System::Drawing::Point(479, 340);
			this->bGroupParams->Name = L"bGroupParams";
			this->bGroupParams->Size = System::Drawing::Size(118, 35);
			this->bGroupParams->TabIndex = 16;
			this->bGroupParams->Text = L"Добавить параметры групп";
			this->bGroupParams->UseVisualStyleBackColor = false;
			this->bGroupParams->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bGroupParams_Click);
			// 
			// cbRoughAttr
			// 
			this->cbRoughAttr->FormattingEnabled = true;
			this->cbRoughAttr->Location = System::Drawing::Point(14, 39);
			this->cbRoughAttr->Name = L"cbRoughAttr";
			this->cbRoughAttr->Size = System::Drawing::Size(149, 21);
			this->cbRoughAttr->TabIndex = 18;
			this->cbRoughAttr->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::cbRoughAttr_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(11, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(172, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Реквизит грубого соответствия:";
			// 
			// tbRoughSymbols
			// 
			this->tbRoughSymbols->Location = System::Drawing::Point(192, 40);
			this->tbRoughSymbols->Name = L"tbRoughSymbols";
			this->tbRoughSymbols->Size = System::Drawing::Size(131, 20);
			this->tbRoughSymbols->TabIndex = 19;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(192, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(136, 13);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Пропускаемые символы:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->cbRoughAttr);
			this->groupBox1->Controls->Add(this->tbRoughSymbols);
			this->groupBox1->Location = System::Drawing::Point(447, 171);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(333, 79);
			this->groupBox1->TabIndex = 21;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Параметры грубого соответствия";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(25, 388);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(105, 13);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Поля базы данных:";
			// 
			// bPosGroupParams
			// 
			this->bPosGroupParams->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bPosGroupParams->Location = System::Drawing::Point(627, 340);
			this->bPosGroupParams->Name = L"bPosGroupParams";
			this->bPosGroupParams->Size = System::Drawing::Size(128, 35);
			this->bPosGroupParams->TabIndex = 23;
			this->bPosGroupParams->Text = L"Добавить групповые параметры позиций";
			this->bPosGroupParams->UseVisualStyleBackColor = false;
			this->bPosGroupParams->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::bPosGroupParams_Click);
			// 
			// cbDateAttr
			// 
			this->cbDateAttr->Enabled = false;
			this->cbDateAttr->FormattingEnabled = true;
			this->cbDateAttr->Location = System::Drawing::Point(461, 134);
			this->cbDateAttr->Name = L"cbDateAttr";
			this->cbDateAttr->Size = System::Drawing::Size(307, 21);
			this->cbDateAttr->TabIndex = 25;
			this->cbDateAttr->Click += gcnew System::EventHandler(this, &AddDbAttrsForm::cbDateAttr_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(458, 118);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(95, 13);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Дата изменения:";
			// 
			// AddDbAttrsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(791, 684);
			this->Controls->Add(this->cbDateAttr);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->bPosGroupParams);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->bGroupParams);
			this->Controls->Add(this->bAddFilter);
			this->Controls->Add(this->bAddTableLinks);
			this->Controls->Add(this->tv);
			this->Controls->Add(this->cbTitle);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->cbId);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bClose);
			this->Controls->Add(this->bRecord);
			this->Controls->Add(this->dgvFields);
			this->Controls->Add(this->bAddNewTable);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lbTables);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"AddDbAttrsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление реквизитов справочника СУБД";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvFields))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:
			void SetTvChecked()
			{
				bool checked = false;
				for (int i = 0; i < dgvFields->Rows->Count; i++)
				{
					bool ch = (bool) dgvFields[0, i]->Value;
					if (ch)
					{
						checked = true;
						break;
					}
				}
				if (checked)
				{
					_programCheck = true;
					tv->SelectedNode->Checked = true;
					_programCheck = false;
				}
				else
				{
					_programCheck = true;
					tv->SelectedNode->Checked = false;
					_programCheck = false;
				}
			}

			void TryConnect()
			{
				try
				{
					List<Object^>^ query = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "BOOKS");
					WrongPass = false;
				}
				catch (TimeoutException^)
				{
					WrongPass = true;
				}
			}

			bool AllAttrsContains(Attribute^ attr)
			{
				for each (KeyValuePair<String^, List<Attribute^>^>^ pair in _allAttrs)
				{
					for each (Attribute^ ar in pair->Value)
					{
						if (ar->FullCode == attr->FullCode)
						{
							return true;
						}
					}
				}
				return false;
			}

			Attribute^ GetAttribute(String^ fullCode)
			{
				for each (KeyValuePair<String^, List<Attribute^>^>^ pair in _allAttrs)
				{
					for each (Attribute^ ar in pair->Value)
					{
						if (ar->FullCode == fullCode)
						{
							return ar;
						}
					}
				}
				return nullptr;
			}

			void AddFullCodesToComboBox(ComboBox^ cb)
			{
				cb->Items->Clear();
				for each (String^ s in _fieldNames)
				{
					cb->Items->Add(s);
				}
			}

			void SetDgvFromDict(String^ schtab)
			{
				for each (Attribute^ attr in _allAttrs[schtab])
				{
					array<Object^>^ row = gcnew array<Object ^>(8);
					row[0] = attr->UseChecked;
					row[1] = attr->Code;
					row[2] = attr->Name;
					row[3] = attr->DataType;
					row[4] = attr->MaxLength;
					row[5] = attr->CanBeNull;
					row[6] = "";
					row[7] = "";
					dgvFields->Rows->Add(row);
				}
			}

			void AddAttrInAllAttrs(String^ schtab, String^ code, Attribute^ attr)
			{
				if(_allAttrs->ContainsKey(schtab))
				{
					List<Attribute^>^ list = _allAttrs[schtab];
					bool find = false;
					for (int i = 0; i < _allAttrs[schtab]->Count; i++)
					{
						if (list[i]->Code == code)
						{
							list[i] = attr;
							find = true;
							break;
						}
					}
					if(!find)
					{
						list->Add(attr);
					}
					_allAttrs[schtab] = list;
				}
				else
				{
					List<Attribute^>^ list = gcnew List<Attribute^>();
					list->Add(attr);
					_allAttrs->Add(schtab, list);
				}
			}

			void SetDgvFromSql(System::Windows::Forms::TreeViewEventArgs^  e, String^ schtab)
			{
				List<Object^>^ fields = _odbc->GetTableInfo7(schtab);

				String^ sSchema = e->Node->Parent->Name;
				String^ table = e->Node->Name;
				String^ schema = sSchema;
				if (sSchema == "без схемы")
				{
					schema = "";
				}
				List<Attribute^>^ list = gcnew List<Attribute ^>();
				for (int i = 0; i < fields->Count; i += 7)
				{
					array<Object^>^ row = gcnew array<Object ^>(8);
					row[0] = false;
					row[1] = fields[i];
					row[2] = fields[i+1];
					row[3] = fields[i+2];
					row[4] = fields[i+3];
					String^ canBeNullLetter = fields[i+6]->ToString();
					if (canBeNullLetter == "N")
					{
						row[5] = false;
					}
					else
					{
						row[5] = true;
					}
					row[6] = fields[i+4];
					row[7] = fields[i+5];
					dgvFields->Rows->Add(row);

					/*Attribute^ attr = gcnew Attribute(schema, table, fields[i]->ToString(), fields[i+1]->ToString());
					attr->UseChecked = false;
					attr->DataType = fields[i+2]->ToString();
					attr->MaxLength = fields[i+3]->ToString();

						attr->CanBeNull = (bool) row[5];

					list->Add(attr);

					String^ fieldCode = String::Format("{0}.{1}", schtab, fields[i]->ToString());
					if (!_fieldNames->Contains(fieldCode))
					{
						_fieldNames->Add(fieldCode);
					}*/
				}
				//_allAttrs[schtab] = list;
			}

			void ReadAttrsFromDataGridView()
			{
				if(tv->SelectedNode == nullptr)
				{
					return;
				}
				if(tv->SelectedNode->Parent == nullptr)
				{
					return;
				}
				_fieldNames->Clear();

				String^ schema = tv->SelectedNode->Parent->Name;
				String^ table =  tv->SelectedNode->Name;
				String^ schtab = String::Format("{0}.{1}", schema, table);
				for (int i = 0; i < dgvFields->Rows->Count; i++)
				{
					bool ch = (bool) dgvFields[0, i]->Value;
					String^ fieldCode = dgvFields[1, i]->Value->ToString();
					String^ fieldName = dgvFields[2, i]->Value->ToString();

					Attribute^ attr;
					if (schema == "без схемы")
					{
						attr = gcnew Attribute("", table, fieldCode, fieldName);
					}
					else
					{
						attr = gcnew Attribute(schema, table, fieldCode, fieldName);
					}
					attr->UseChecked = ch;


					Object^ obj = dgvFields[3, i]->Value;
					if(obj != nullptr)
					{
						attr->DataType = obj->ToString();
					}
					attr->MaxLength = dgvFields[4, i]->Value->ToString();
					Object^ bcanBeNull = dgvFields[5, i]->Value;
					if ((bool)bcanBeNull)
					{
						attr->CanBeNull = true;
					}
					else
					{
						attr->CanBeNull = false;

					}
					_fieldNames->Add(attr->FullCode);
					AddAttrInAllAttrs(schtab, fieldCode, attr);
				}
			}


	private: System::Void bAddNewTable_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				AddNewTableForm^ form = gcnew AddNewTableForm(_odbc);
				form->ShowDialog();
				String^ schema = form->Schema;
				String^ table = form->Table;

				if (String::IsNullOrEmpty(schema))
				{
					schema = "без схемы";
				}
				if (tv->Nodes->ContainsKey(schema))
				{
					TreeNode^ schemaNode = tv->Nodes[schema];
					if (schemaNode->Nodes->ContainsKey(table))
					{
						MessageBox::Show("Данная таблица уже есть в дереве!");
					}
					else
					{
						schemaNode->Nodes->Add(table, table);
					}
				}
				else
				{
					if (String::IsNullOrEmpty(schema))
					{
						tv->Nodes->Add("без схемы", "без схемы");
						tv->Nodes["без схемы"]->Nodes->Add(table, table);
					}
					else
					{
						tv->Nodes->Add(schema, schema);
						tv->Nodes[schema]->Nodes->Add(table, table);
					}
						 
				}
				if (tv->Nodes->Count > 1)
				{
					//bAddTableLinks->Enabled = true;
				}
				else
				{
					if (tv->Nodes[0]->Nodes->Count > 1)
					{
						//bAddTableLinks->Enabled = true;
					}
					else
					{
						//bAddTableLinks->Enabled = false;
					}
				}

			 }

private: System::Void bClose_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 IdCol = nullptr;
			 TitleCol = nullptr;
			 Attributes = nullptr;
			 Close();
		 }
private: System::Void dgvFields_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (tv->SelectedNode != nullptr)
			 {
				 if (e->ColumnIndex == 0)
				 {
					 SetTvChecked();
					 /*int i = e->RowIndex;
						 bool ch = (bool) dgvFields[0, i]->Value;

							 String^ fieldCode = dgvFields[1, i]->Value->ToString();
							 String^ fieldName = dgvFields[2, i]->Value->ToString();
							 String^ schema = tv->SelectedNode->Parent->Name;
							 String^ table =  tv->SelectedNode->Name;
							 String^ schtab = String::Format("{0}.{1}", schema, table);


							 Attribute^ attr = gcnew Attribute(schema, table, fieldCode, fieldName);
							 attr->UseChecked = ch;
							 attr->DataType = dgvFields[3, i]->Value->ToString();
							 attr->MaxLength = dgvFields[4, i]->Value->ToString();
							 Object^ bcanBeNull = dgvFields[5, i]->Value;
							 if ((bool)bcanBeNull)
							 {
								 attr->CanBeNull = true;
							 }
							 else
							 {
								 attr->CanBeNull = false;

							 }

							 AddAttrInAllAttrs(schtab, fieldCode, attr);*/

				 }
				 else if (e->ColumnIndex == 2)
				 {
					 /*String^ schtab = String::Format("{0}.{1}", tv->SelectedNode->Parent->Name, tv->SelectedNode->Name);
					 String^ field = dgvFields[1, e->RowIndex]->Value->ToString();
					 String^ fullCode = String::Format("{0}.{1}", schtab, field);
					 _odbc->AddColumnComment(fullCode,  dgvFields[e->ColumnIndex, e->RowIndex]->Value->ToString());*/
					 
				 }
			 }
			 
		 }
private: System::Void bRecord_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (cbId->SelectedItem == nullptr)
			 {
				 MessageBox::Show("Не задан реквизит-идентификатор!");
				 return;
			 }
			 if (cbTitle->SelectedItem == nullptr)
			 {
				 MessageBox::Show("Не задан основной реквизит!");
				 return;
			 }
			 Attributes = gcnew List<Attribute ^>();
			 for each (KeyValuePair<String^, List<Attribute^>^>^ pair in _allAttrs)
			 {
				 for each (Attribute^ attr in pair->Value)
				 {
					 if (attr->UseChecked)
					 {
						 Attributes->Add(attr);
					 }
				 }
			 }
			 IdCol = GetAttribute(cbId->SelectedItem->ToString());
			 TitleCol = GetAttribute(cbTitle->SelectedItem->ToString());
			 DateCol = GetAttribute(cbDateAttr->SelectedItem->ToString());

			 RoughCol = nullptr;
			 RoughSymbols = nullptr;
			 if (cbRoughAttr->SelectedItem != nullptr)
			 {
				 RoughCol = GetAttribute(cbRoughAttr->SelectedItem->ToString());
			 }
			 if (!String::IsNullOrEmpty(tbRoughSymbols->Text->Trim()))
			 {
				 RoughSymbols = tbRoughSymbols->Text->Trim();
			 }
			 Close();
		 }
private: System::Void tv_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) 
		 {
			 if (e->Node->Level > 0)
			 {
				 dgvFields->Rows->Clear();

				 String^ schtab = String::Format("{0}.{1}", e->Node->Parent->Name, e->Node->Name);

				 if (_allAttrs->ContainsKey(schtab))
				 {
					 SetDgvFromDict(schtab);
				 }
				 else
				 {
					 SetDgvFromSql(e, schtab);
				 }
				 
				 cbId->Enabled = true;
				 cbTitle->Enabled = true;
				 cbDateAttr->Enabled = true;
			 }
			 else
			 {
				 dgvFields->Rows->Clear();
			 }
		 }
private: System::Void bAddFilter_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 List<String^>^ list = gcnew List<String ^>();
			 for each (KeyValuePair<String^, List<Attribute^>^>^ pair in _allAttrs)
			 {
				 for each (Attribute^ attr in pair->Value)
				 {
					 list->Add(String::Format("{0}.{1}", pair->Key, attr->Code));
				 }
			 }
			 DbFiltersForm^ form = gcnew DbFiltersForm(list);
			 form->ShowDialog();
			 if (!String::IsNullOrEmpty(form->Condition))
			 {
				 _filter = form->Condition;
			 }
		 }
private: System::Void bAddTableLinks_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Dictionary<String^, List<String^>^>^ dict = gcnew Dictionary<String ^, List<String ^> ^>();
			 for each (KeyValuePair<String^, List<Attribute^>^>^ pair in _allAttrs)
			 {
				 List<String^>^ list = gcnew List<String ^>();
				 for each (Attribute^ attr in pair->Value)
				 {
					 list->Add(attr->Code);
				 }
				 dict->Add(pair->Key, list);
			 }
			 TableLinksForm^ form = gcnew TableLinksForm(_allAttrs);
			 form->ShowDialog();
			 if (_links != nullptr)
			 {
				 _links = form->Links;
			 }
		 }

private: System::Void bGroupParams_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 GroupParamsForm^ form = gcnew GroupParamsForm(_odbc);
			 form->ShowDialog();
			 if (form->IdAttr != nullptr)
			 {
				 GroupSchtab = form->Schtab;
				 GroupIdCol = form->IdAttr;
				 GroupNameCol = form->NameAttr;
				 GroupAttrs = form->Attrs;
			 }
		 }
private: System::Void tv_AfterCheck(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) 
		 {
			 if (!_programCheck && e->Node->Checked)
			 {
				 e->Node->Checked = false;
			 }
		 }
private: System::Void cbId_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ReadAttrsFromDataGridView();
			 AddFullCodesToComboBox(cbId);
		 }
private: System::Void cbTitle_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
				ReadAttrsFromDataGridView();
			  AddFullCodesToComboBox(cbTitle);
		 }
private: System::Void cbRoughAttr_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 AddFullCodesToComboBox(cbRoughAttr);
		 }
private: System::Void tv_BeforeSelect(System::Object^  sender, System::Windows::Forms::TreeViewCancelEventArgs^  e) 
		 {
			 ReadAttrsFromDataGridView();
		 }
private: System::Void bPosGroupParams_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 PosGroupParamsForm^ form = gcnew PosGroupParamsForm(0, _allAttrs);
			 form->ShowDialog();
		 }
private: System::Void cbDateAttr_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ReadAttrsFromDataGridView();
			 AddFullCodesToComboBox(cbDateAttr);
		 }
};
}
