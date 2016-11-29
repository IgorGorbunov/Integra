#pragma once

#include "Settings.h"
#include "AttrCompareForm.h"
#include "ODBCclass.h"
#include "AddDbAttrsForm.h"
#include "AddSemAttrForm.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddEditSchemaForm
	/// </summary>
	public ref class AddEditSchemaForm : public System::Windows::Forms::Form
	{
	private:
		Settings^ _settings;
		OdbcClass^ _odbc;

		array<String^, 2>^ _bookList;
		array<String^, 2>^ _systemList;

		int _bookSourceId;
		int _bookTargetId;
		int _systemSourceId;
		int _systemTargetId;
		int _systemSourceTypeId;
		int _systemTargetTypeId;

		List<array<String^>^>^ _attrs;
		List<array<String^>^>^ _sourceLinks;
		List<array<String^>^>^ _targetLinks;
		List<array<String^>^>^ _equivs;
		List<array<String^>^>^ _dbSourceAttrs;
		List<array<String^>^>^ _dbTargetAttrs;
		String^ _sourceIdCol;
		String^ _targetIdCol;
		String^ _sourceTitleCol;
		String^ _targetTitleCol;

		int _equivSourceId;
		int _equivTargetId;
		int _intgrSourceId;
		int _intgrTargetId;
		int _schemaId;

	private: System::Windows::Forms::Button^  bOk;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cbBook;
	private: System::Windows::Forms::ComboBox^  cbIntgrType;


	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Button^  bAddSourceAttrs;
	private: System::Windows::Forms::Button^  bAddTargetAttrs;
	private: System::Windows::Forms::Button^  bCancel;
			 

	public:
		AddEditSchemaForm(Settings^ settings, OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
			_settings = settings;
			_bookList = settings->Books;
			_systemList = settings->Systems;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddEditSchemaForm()
		{
			if (components)
			{
				delete components;
			}
		}


	protected: 

	private: System::Windows::Forms::ComboBox^  cbSystemSource;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbDbSource;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tbPassSource;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tbLoginSource;


	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;

	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tbDbTarget;


	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  tbPassTarget;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  tbLoginTarget;


	private: System::Windows::Forms::ComboBox^  cbSystemTarget;




	private: System::Windows::Forms::Label^  label10;


	private: System::Windows::Forms::Button^  bAttrCompare;

	private: System::Windows::Forms::ComboBox^  cbConnTypeSource;
	private: System::Windows::Forms::TextBox^  tbDriverSource;
	private: System::Windows::Forms::ComboBox^  cbConnTypeTarget;

	private: System::Windows::Forms::TextBox^  tbDriverTarget;

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
			this->cbSystemSource = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tbDriverSource = (gcnew System::Windows::Forms::TextBox());
			this->cbConnTypeSource = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbDbSource = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbPassSource = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbLoginSource = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tbDriverTarget = (gcnew System::Windows::Forms::TextBox());
			this->cbConnTypeTarget = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbDbTarget = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tbPassTarget = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tbLoginTarget = (gcnew System::Windows::Forms::TextBox());
			this->cbSystemTarget = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->bAttrCompare = (gcnew System::Windows::Forms::Button());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbBook = (gcnew System::Windows::Forms::ComboBox());
			this->cbIntgrType = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->bAddSourceAttrs = (gcnew System::Windows::Forms::Button());
			this->bAddTargetAttrs = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// cbSystemSource
			// 
			this->cbSystemSource->FormattingEnabled = true;
			this->cbSystemSource->Location = System::Drawing::Point(22, 32);
			this->cbSystemSource->Name = L"cbSystemSource";
			this->cbSystemSource->Size = System::Drawing::Size(216, 21);
			this->cbSystemSource->TabIndex = 3;
			this->cbSystemSource->SelectedIndexChanged += gcnew System::EventHandler(this, &AddEditSchemaForm::cbSystemSource_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Система";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tbDriverSource);
			this->groupBox1->Controls->Add(this->cbConnTypeSource);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->tbDbSource);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->tbPassSource);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->tbLoginSource);
			this->groupBox1->Location = System::Drawing::Point(22, 75);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(216, 202);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Соединение";
			// 
			// tbDriverSource
			// 
			this->tbDriverSource->Location = System::Drawing::Point(13, 56);
			this->tbDriverSource->Multiline = true;
			this->tbDriverSource->Name = L"tbDriverSource";
			this->tbDriverSource->Size = System::Drawing::Size(177, 129);
			this->tbDriverSource->TabIndex = 10;
			this->tbDriverSource->Visible = false;
			// 
			// cbConnTypeSource
			// 
			this->cbConnTypeSource->FormattingEnabled = true;
			this->cbConnTypeSource->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L" Логин, пароль, база данных", L"Драйвер"});
			this->cbConnTypeSource->Location = System::Drawing::Point(13, 30);
			this->cbConnTypeSource->Name = L"cbConnTypeSource";
			this->cbConnTypeSource->Size = System::Drawing::Size(177, 21);
			this->cbConnTypeSource->TabIndex = 8;
			this->cbConnTypeSource->Text = L" Логин, пароль, база данных";
			this->cbConnTypeSource->SelectedIndexChanged += gcnew System::EventHandler(this, &AddEditSchemaForm::cbConnTypeSource_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 149);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"База данных";
			// 
			// tbDbSource
			// 
			this->tbDbSource->Location = System::Drawing::Point(13, 165);
			this->tbDbSource->Name = L"tbDbSource";
			this->tbDbSource->Size = System::Drawing::Size(177, 20);
			this->tbDbSource->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 106);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Пароль";
			// 
			// tbPassSource
			// 
			this->tbPassSource->Location = System::Drawing::Point(13, 122);
			this->tbPassSource->Name = L"tbPassSource";
			this->tbPassSource->Size = System::Drawing::Size(177, 20);
			this->tbPassSource->TabIndex = 4;
			this->tbPassSource->UseSystemPasswordChar = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 64);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Логин";
			// 
			// tbLoginSource
			// 
			this->tbLoginSource->Location = System::Drawing::Point(13, 80);
			this->tbLoginSource->Name = L"tbLoginSource";
			this->tbLoginSource->Size = System::Drawing::Size(177, 20);
			this->tbLoginSource->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->bAddSourceAttrs);
			this->groupBox2->Controls->Add(this->groupBox1);
			this->groupBox2->Controls->Add(this->cbSystemSource);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(12, 55);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(273, 339);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Источник";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->bAddTargetAttrs);
			this->groupBox3->Controls->Add(this->groupBox4);
			this->groupBox3->Controls->Add(this->cbSystemTarget);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Location = System::Drawing::Point(321, 55);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(273, 339);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Получатель";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tbDriverTarget);
			this->groupBox4->Controls->Add(this->cbConnTypeTarget);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->tbDbTarget);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Controls->Add(this->tbPassTarget);
			this->groupBox4->Controls->Add(this->label9);
			this->groupBox4->Controls->Add(this->tbLoginTarget);
			this->groupBox4->Location = System::Drawing::Point(27, 75);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(216, 202);
			this->groupBox4->TabIndex = 4;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Соединение";
			// 
			// tbDriverTarget
			// 
			this->tbDriverTarget->Location = System::Drawing::Point(13, 56);
			this->tbDriverTarget->Multiline = true;
			this->tbDriverTarget->Name = L"tbDriverTarget";
			this->tbDriverTarget->Size = System::Drawing::Size(177, 129);
			this->tbDriverTarget->TabIndex = 12;
			this->tbDriverTarget->Visible = false;
			// 
			// cbConnTypeTarget
			// 
			this->cbConnTypeTarget->FormattingEnabled = true;
			this->cbConnTypeTarget->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L" Логин, пароль, база данных", L"Драйвер"});
			this->cbConnTypeTarget->Location = System::Drawing::Point(13, 30);
			this->cbConnTypeTarget->Name = L"cbConnTypeTarget";
			this->cbConnTypeTarget->Size = System::Drawing::Size(177, 21);
			this->cbConnTypeTarget->TabIndex = 11;
			this->cbConnTypeTarget->Text = L" Логин, пароль, база данных";
			this->cbConnTypeTarget->SelectedIndexChanged += gcnew System::EventHandler(this, &AddEditSchemaForm::cbConnTypeTarget_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(13, 149);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"База данных";
			// 
			// tbDbTarget
			// 
			this->tbDbTarget->Location = System::Drawing::Point(13, 165);
			this->tbDbTarget->Name = L"tbDbTarget";
			this->tbDbTarget->Size = System::Drawing::Size(177, 20);
			this->tbDbTarget->TabIndex = 6;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(10, 106);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(45, 13);
			this->label8->TabIndex = 5;
			this->label8->Text = L"Пароль";
			// 
			// tbPassTarget
			// 
			this->tbPassTarget->Location = System::Drawing::Point(13, 122);
			this->tbPassTarget->Name = L"tbPassTarget";
			this->tbPassTarget->Size = System::Drawing::Size(177, 20);
			this->tbPassTarget->TabIndex = 4;
			this->tbPassTarget->UseSystemPasswordChar = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(10, 64);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(38, 13);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Логин";
			// 
			// tbLoginTarget
			// 
			this->tbLoginTarget->Location = System::Drawing::Point(13, 80);
			this->tbLoginTarget->Name = L"tbLoginTarget";
			this->tbLoginTarget->Size = System::Drawing::Size(177, 20);
			this->tbLoginTarget->TabIndex = 0;
			// 
			// cbSystemTarget
			// 
			this->cbSystemTarget->FormattingEnabled = true;
			this->cbSystemTarget->Location = System::Drawing::Point(27, 32);
			this->cbSystemTarget->Name = L"cbSystemTarget";
			this->cbSystemTarget->Size = System::Drawing::Size(216, 21);
			this->cbSystemTarget->TabIndex = 3;
			this->cbSystemTarget->SelectedIndexChanged += gcnew System::EventHandler(this, &AddEditSchemaForm::cbSystemTarget_SelectedIndexChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(37, 16);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(51, 13);
			this->label10->TabIndex = 2;
			this->label10->Text = L"Система";
			// 
			// bAttrCompare
			// 
			this->bAttrCompare->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAttrCompare->Enabled = false;
			this->bAttrCompare->Location = System::Drawing::Point(236, 415);
			this->bAttrCompare->Name = L"bAttrCompare";
			this->bAttrCompare->Size = System::Drawing::Size(136, 37);
			this->bAttrCompare->TabIndex = 9;
			this->bAttrCompare->Text = L"Задать соответствие реквизитов";
			this->bAttrCompare->UseVisualStyleBackColor = false;
			this->bAttrCompare->Click += gcnew System::EventHandler(this, &AddEditSchemaForm::bAttrCompare_Click);
			// 
			// bOk
			// 
			this->bOk->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bOk->Location = System::Drawing::Point(445, 431);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 10;
			this->bOk->Text = L"OK";
			this->bOk->UseVisualStyleBackColor = false;
			this->bOk->Click += gcnew System::EventHandler(this, &AddEditSchemaForm::bOk_Click);
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(539, 431);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 11;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &AddEditSchemaForm::bCancel_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(44, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Справочник";
			// 
			// cbBook
			// 
			this->cbBook->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->cbBook->FormattingEnabled = true;
			this->cbBook->Location = System::Drawing::Point(34, 28);
			this->cbBook->Name = L"cbBook";
			this->cbBook->Size = System::Drawing::Size(216, 21);
			this->cbBook->TabIndex = 13;
			// 
			// cbIntgrType
			// 
			this->cbIntgrType->FormattingEnabled = true;
			this->cbIntgrType->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"В одну сторону", L"В обе стороны"});
			this->cbIntgrType->Location = System::Drawing::Point(348, 25);
			this->cbIntgrType->Name = L"cbIntgrType";
			this->cbIntgrType->Size = System::Drawing::Size(216, 21);
			this->cbIntgrType->TabIndex = 15;
			this->cbIntgrType->Text = L"В одну сторону";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(358, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(136, 13);
			this->label11->TabIndex = 14;
			this->label11->Text = L"Направление интеграции";
			// 
			// bAddSourceAttrs
			// 
			this->bAddSourceAttrs->Location = System::Drawing::Point(35, 283);
			this->bAddSourceAttrs->Name = L"bAddSourceAttrs";
			this->bAddSourceAttrs->Size = System::Drawing::Size(177, 23);
			this->bAddSourceAttrs->TabIndex = 5;
			this->bAddSourceAttrs->Text = L"Задать реквизиты";
			this->bAddSourceAttrs->UseVisualStyleBackColor = true;
			this->bAddSourceAttrs->Click += gcnew System::EventHandler(this, &AddEditSchemaForm::bAddSourceAttrs_Click);
			// 
			// bAddTargetAttrs
			// 
			this->bAddTargetAttrs->Location = System::Drawing::Point(40, 283);
			this->bAddTargetAttrs->Name = L"bAddTargetAttrs";
			this->bAddTargetAttrs->Size = System::Drawing::Size(177, 23);
			this->bAddTargetAttrs->TabIndex = 6;
			this->bAddTargetAttrs->Text = L"Задать реквизиты";
			this->bAddTargetAttrs->UseVisualStyleBackColor = true;
			// 
			// AddEditSchemaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(626, 466);
			this->Controls->Add(this->cbIntgrType);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cbBook);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->bAttrCompare);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddEditSchemaForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление/редактирование схем интеграции";
			this->Load += gcnew System::EventHandler(this, &AddEditSchemaForm::AddEditSchemaForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:
			Void SetComboBox(ComboBox^ comboBox, array<String^, 2>^ list)
			{
				for (int i = 0; i < list->GetLength(0); i++)
				{
					comboBox->Items->Add(list[i,1]);
				}
			}

			int GetListId(String^ name, array<String^, 2>^ list)
			{
				for (int i = 0; i < list->GetLength(0); i++)
				{
					if (name == list[i,1])
					{
						return Int32::Parse(list[i,0]);
					}
				}
				return 0;
			}

			int GetListId3(String^ name, array<String^, 2>^ list, int% typeId)
			{
				for (int i = 0; i < list->GetLength(0); i++)
				{
					if (name == list[i,1])
					{
						if (String::IsNullOrEmpty(list[i,2]))
						{
							typeId = 0;
						} 
						else
						{
							typeId = Int32::Parse(list[i,2]);
						}
						
						return Int32::Parse(list[i,0]);
					}
				}
				return 0;
			}

		Void SetAttrCompareButton()
		{
			if (!String::IsNullOrEmpty(cbSystemSource->Text) &&
				!String::IsNullOrEmpty(cbSystemTarget->Text))
			{
				bAttrCompare->Enabled = true;
			}
			else
			{
				bAttrCompare->Enabled = false;
			}
		}

		Void SetAttrCompare()
		{
			_attrs = gcnew List<array<String ^> ^>();
			_sourceLinks = gcnew List<array<String ^> ^>();
			_targetLinks = gcnew List<array<String ^> ^>();
			_equivs = gcnew List<array<String ^> ^>();
			AttrCompareForm^ form = gcnew AttrCompareForm(_systemSourceTypeId, _systemTargetTypeId, _attrs, _sourceLinks, _targetLinks, _equivs);
			form->ShowDialog();
		}

		Void WriteToDb()
		{
			WriteIntegrBook();
			//WriteEquivAttrs();
			WriteDbAttrs(_sourceIdCol, _sourceTitleCol, _dbSourceAttrs, _intgrSourceId);
			WriteSchema();
			//WriteAttrPairs();
		}

		Void WriteIntegrBook()
		{
			
			String^ query = "insert into " + _odbc->schema + "INTEGRATION_BOOK values (";
			_intgrSourceId = _odbc->GetMinFreeId(_odbc->schema + "INTEGRATION_BOOK");
			List<Object^>^ idBook = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "BOOKS where NAME = \'" + cbBook->Text + "\'");
			List<Object^>^ idSystem = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "INTEGRATED_SYSTEMS where NAME = \'" + cbSystemSource->Text + "\'");
			query += _intgrSourceId + ", " + Decimal::ToInt32((Decimal)idSystem[0]) + ", " + Decimal::ToInt32((Decimal)idBook[0]) + ", ";
			if (_systemSourceTypeId == 1)
			{
				query += "\'" + tbLoginSource->Text + "\', \'" + tbPassSource->Text + "\', NULL, NULL, NULL, NULL, NULL, NULL, " + _systemSourceTypeId + ", NULL, NULL)";
			} 
			else
			{
				if (cbConnTypeSource->SelectedIndex == 1)
				{
					query += "NULL, NULL, NULL, NULL, NULL, NULL, NULL, \'" + tbDriverSource->Text + "\', " + _systemSourceTypeId + ", NULL, NULL)";
				}
				else
				{
					query += "\'" + tbLoginSource->Text + "\', \'" + tbPassSource->Text + "\', \'" + tbDbSource->Text + 
						"\', NULL, NULL, NULL, NULL, NULL, " + _systemSourceTypeId + ", NULL, NULL)";
				}
			}
			_odbc->ExecuteNonQuery(query);
			
			query = "insert into " + _odbc->schema + "INTEGRATION_BOOK values (";
			_intgrTargetId = _odbc->GetMinFreeId("" + _odbc->schema + "INTEGRATION_BOOK");
			idSystem = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "INTEGRATED_SYSTEMS where NAME = \'" + cbSystemTarget->Text + "\'");
			query += _intgrTargetId + ", " + Decimal::ToInt32((Decimal)idSystem[0]) + ", " + Decimal::ToInt32((Decimal)idBook[0]) + ", ";
			if (_systemTargetTypeId == 1)
			{
				query += "\'" + tbLoginTarget->Text + "\', \'" + tbPassTarget->Text + "\', NULL, NULL, NULL, NULL, NULL, NULL, " + _systemTargetTypeId + ", NULL, NULL)";
			} 
			else
			{
				if (cbConnTypeTarget->SelectedIndex == 1)
				{
					query += "NULL, NULL, NULL, NULL, NULL, NULL, NULL, \'" + tbDriverTarget->Text + "\', " + _systemTargetTypeId + ", NULL, NULL)";
				}
				else
				{
					query += "\'" + tbLoginTarget->Text + "\', \'" + tbPassTarget->Text + "\', \'" + tbDbTarget->Text + 
						"\', NULL, NULL, NULL, NULL, NULL, " + _systemTargetTypeId + ", NULL, NULL)";
				}
			}
			_odbc->ExecuteNonQuery(query);
		}


		void WriteDbAttrs(String^ idCol, String^ titleCol, List<array<String^>^>^ dbAttrs, int intgrId)
		{
			for (int i = 0; i < dbAttrs->Count; i++)
			{
				int id = _odbc->GetMinFreeId("" + _odbc->schema + "integration_attributes");
				String^ squery = String::Format("insert into {7}integration_attributes values ({0}, \'{1}\', \'{2}\', \'{3}\', \'{4}\', \'{5}\', {6})", 
					id, dbAttrs[i][0], dbAttrs[i][1], dbAttrs[i][2], dbAttrs[i][3], dbAttrs[i][4], intgrId, _odbc->schema);
				_odbc->ExecuteNonQuery(squery);
			}

			int id = WriteIdTitleAttr(idCol, intgrId);
			String^ squery = "update INTEGRATION_BOOK set ATTR_ID = " + id + " where ID = " + intgrId;
			_odbc->ExecuteNonQuery(squery);
			
			int titleAttrId = WriteIdTitleAttr(titleCol, intgrId);
			squery = "update INTEGRATION_BOOK set ATTR_TITLE = " + titleAttrId + " where ID = " + intgrId;
			_odbc->ExecuteNonQuery(squery);
		}

		int WriteIdTitleAttr(String^ col, int intgrId)
		{
			array<String^>^ arr = col->Split('.');
			List<Object^>^ query = _odbc->ExecuteQuery("select ID from " + _odbc->schema + "integration_attributes where schema_name = \'" + arr[0] + "\' and table_name = \'" + arr[1] + "\' and attr_name = \'" + arr[2] + "\' and ID_INTGR_BOOK = " + intgrId);
			if (query != nullptr && query->Count > 0)
			{
				return Decimal::ToInt32((Decimal)query[0]);
			}
			else
			{
				int id = _odbc->GetMinFreeId("" + _odbc->schema + "integration_attributes");
				String^ squery = String::Format("insert into " + _odbc->schema + "integration_attributes values ({0}, \'{1}\', NULL, \'{2}\', \'{3}\', \'{4}\', {5})", 
					id, col, arr[0], arr[1], arr[2], intgrId);
				_odbc->ExecuteNonQuery(squery);
				return id;
			}
		}

		Void WriteEquivAttrs()
		{
			String^ query = "insert into " + _odbc->schema + "INTEGRATION_ATTRIBUTES values (";
			_equivSourceId = _odbc->GetMinFreeId("" + _odbc->schema + "INTEGRATION_ATTRIBUTES");
			query += _equivSourceId + ", ";
			array<String^>^ arr1 = _equivs[0];
			String^ schema = _odbc->GetSqlString(arr1[0]);
			String^ table = _odbc->GetSqlString(arr1[1]);
			String^ field = _odbc->GetSqlString(arr1[2]);
			String^ fullCode = arr1[0] + "." + arr1[1];
			fullCode = _odbc->GetSqlString(fullCode);

			query += fullCode + ", NULL, " + schema + ", " + table + ", " + field + ")";
			_odbc->ExecuteNonQuery(query);

			query = "insert into " + _odbc->schema + "INTEGRATION_ATTRIBUTES values (";
			_equivTargetId = _odbc->GetMinFreeId("" + _odbc->schema + "INTEGRATION_ATTRIBUTES");
			query += _equivTargetId + ", ";
			array<String^>^ arr2 = _equivs[0];
			schema = _odbc->GetSqlString(arr2[3]);
			table = _odbc->GetSqlString(arr2[4]);
			field = _odbc->GetSqlString(arr2[5]);
			fullCode = arr2[3] + "." + arr2[4];
			fullCode = _odbc->GetSqlString(fullCode);

			query += fullCode + ", NULL, " + schema + ", " + table + ", " + field + ")";
			_odbc->ExecuteNonQuery(query);
		}

		Void WriteSchema()
		{
			String^ query = "insert into " + _odbc->schema + "INTEGRATION_PARAMS values (";
			_schemaId = _odbc->GetMinFreeId("" + _odbc->schema + "INTEGRATION_PARAMS");
			int intgrType = cbIntgrType->SelectedIndex;
			String^ sEquivSourceId;
			String^ sEquivTargetId;
			if (_equivSourceId == 0)
			{
				sEquivSourceId = "NULL";
			}
			else
			{
				sEquivSourceId = _equivSourceId + "";
			}
			if (_equivTargetId == 0)
			{
				sEquivTargetId = "NULL";
			}
			else
			{
				sEquivTargetId = _equivTargetId + "";
			}
			query += _schemaId + ", " + _intgrSourceId + ", " + _intgrTargetId + ", " + intgrType + ", " + sEquivSourceId + ", " + sEquivTargetId + ")";
			_odbc->ExecuteNonQuery(query);
		}

		Void WriteAttrPairs()
		{
			String^ query;
			int id1, id2, id3;
			String^ schema;
			String^ table;
			String^ field;
			String^ fullCode;
			for each(array<String^>^ arr in _attrs)
			{
				query = "insert into " + _odbc->schema + "INTEGRATION_ATTRIBUTES values (";
				id1 = _odbc->GetMinFreeId("" + _odbc->schema + "INTEGRATION_ATTRIBUTES");
				query += id1 + ", ";
				schema = _odbc->GetSqlString(arr[0]);
				table = _odbc->GetSqlString(arr[1]);
				field = _odbc->GetSqlString(arr[2]);
				fullCode = arr[0] + "." + arr[1];
				fullCode = _odbc->GetSqlString(fullCode);

				query += fullCode + ", NULL, " + schema + ", " + table + ", " + field + ")";
				_odbc->ExecuteNonQuery(query);

				query = "insert into " + _odbc->schema + "INTEGRATION_ATTRIBUTES values (";
				id2 = _odbc->GetMinFreeId("" + _odbc->schema + "INTEGRATION_ATTRIBUTES");
				query += id2 + ", ";
				schema = _odbc->GetSqlString(arr[3]);
				table = _odbc->GetSqlString(arr[4]);
				field = _odbc->GetSqlString(arr[5]);
				fullCode = arr[3] + "." + arr[4];
				fullCode = _odbc->GetSqlString(fullCode);

				query += fullCode + ", NULL, " + schema + ", " + table + ", " + field + ")";
				_odbc->ExecuteNonQuery(query);

				query = "insert into " + _odbc->schema + "ATTRIBUTE_PAIRS values (";
				id3 = _odbc->GetMinFreeId("" + _odbc->schema + "ATTRIBUTE_PAIRS");
				query += id3 + ", " + id1 + ", " + id2 + ", " + _schemaId + ")";
				_odbc->ExecuteNonQuery(query);
			}
		}


	private: System::Void AddEditSchemaForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 SetComboBox(cbBook, _bookList);
				 SetComboBox(cbSystemSource, _systemList);
				 SetComboBox(cbSystemTarget, _systemList);
			 }
private: System::Void cbBookSource_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 _bookSourceId = GetListId(cbBook->Text, _bookList);
		 }

private: System::Void cbSystemSource_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 _systemSourceId = GetListId3(cbSystemSource->Text, _systemList, _systemSourceTypeId);
			 if (_systemSourceTypeId == 1)
			 {
				 cbConnTypeSource->SelectedIndex = 0;
				 cbConnTypeSource_SelectedIndexChanged(sender, e);
				 tbDbSource->Text = "";
				 tbDbSource->Enabled = false;
				 cbConnTypeSource->Enabled = false;
			 }
			 else
			 {
				 tbDbSource->Enabled = true;
				 cbConnTypeSource->Enabled = true;
			 }
			 SetAttrCompareButton();
		 }
private: System::Void cbSystemTarget_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 _systemTargetId = GetListId3(cbSystemTarget->Text, _systemList, _systemTargetTypeId);
			 if (_systemTargetTypeId == 1)
			 {
				 cbConnTypeTarget->SelectedIndex = 0;
				 cbConnTypeTarget_SelectedIndexChanged(sender, e);
				 tbDbTarget->Text = "";
				 tbDbTarget->Enabled = false;
				 cbConnTypeTarget->Enabled = false;
			 }
			 else
			 {
				 tbDbTarget->Enabled = true;
				 cbConnTypeTarget->Enabled = true;
			 }
			 SetAttrCompareButton();
		 }
private: System::Void cbConnTypeSource_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (cbConnTypeSource->SelectedIndex == 0)
			 {
				 tbDriverSource->Visible = false;
				 tbLoginSource->Visible = true;
				 tbPassSource->Visible = true;
				 tbDbSource->Enabled = true;
				 tbDbSource->Visible = true;
			 }
			 else
			 {
				 tbDriverSource->Visible = true;
				 tbLoginSource->Visible = false;
				 tbPassSource->Visible = false;
				 tbDbSource->Visible = false;
			 }
		 }
private: System::Void cbConnTypeTarget_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {

			 if (cbConnTypeTarget->SelectedIndex == 0)
			 {
				 tbDriverTarget->Visible = false;
				 tbLoginTarget->Visible = true;
				 tbPassTarget->Visible = true;
				 tbDbTarget->Enabled = true;
				 tbDbTarget->Visible = true;
			 }
			 else
			 {
				 tbDriverTarget->Visible = true;
				 tbLoginTarget->Visible = false;
				 tbPassTarget->Visible = false;
				 tbDbTarget->Visible = false;
			 }
		 }
private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void bAttrCompare_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetAttrCompare();
			 
		 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (String::IsNullOrEmpty(cbBook->Text))
			 {
				 MessageBox::Show("Не задан справочник!");
				 return;
			 }
			 else if (String::IsNullOrEmpty(cbSystemSource->Text))
			 {
				 MessageBox::Show("Не задана система-источник!");
				 return;
			 }
			 else if (String::IsNullOrEmpty(cbSystemTarget->Text))
			 {
				 MessageBox::Show("Не задана система-приемник!");
				 return;
			 }
			 else if (cbConnTypeSource->SelectedIndex == 1)
			 {
				 if (String::IsNullOrEmpty(tbDriverSource->Text))
				 {
					 MessageBox::Show("Не задан драйвер для системы-источника!");
					 return;
				 }
			 }
			 else
			 {
				 if (String::IsNullOrEmpty(tbLoginSource->Text))
				 {
					 MessageBox::Show("Не задан логин для соединения с системой-источником!");
					 return;
				 }
				 else if (String::IsNullOrEmpty(tbPassSource->Text))
				 {
					 MessageBox::Show("Не задан пароль для соединения с системой-источником!");
					 return;
				 }
				 if (_systemSourceTypeId != 1)
				 {
					 if (String::IsNullOrEmpty(tbDbSource->Text))
					 {
						 MessageBox::Show("Не задана база данных для соединения с системой-источником!");
						 return;
					 }
				 }
			 }
			 if (cbConnTypeTarget->SelectedIndex == 1)
			 {
				 if (String::IsNullOrEmpty(tbDriverTarget->Text))
				 {
					 MessageBox::Show("Не задан драйвер для системы-приемника!");
					 return;
				 }
			 }
			 else
			 {
				 if (String::IsNullOrEmpty(tbLoginTarget->Text))
				 {
					 MessageBox::Show("Не задан логин для соединения с системой-приемником!");
					 return;
				 }
				 else if (String::IsNullOrEmpty(tbPassTarget->Text))
				 {
					 MessageBox::Show("Не задан пароль для соединения с системой-приемником!");
					 return;
				 }
				 if (_systemTargetTypeId != 1)
				 {
					 if (String::IsNullOrEmpty(tbDbTarget->Text))
					 {
						 MessageBox::Show("Не задана база данных для соединения с системой-приемником!");
						 return;
					 }
				 }
			 }
			 if (_attrs == nullptr || _attrs->Count == 0)
			 /*{
				 System::Windows::Forms::DialogResult result = MessageBox::Show("Не заданы связи атрибутов. Задать?", "Предупреждение", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Warning);
				 if (result == Windows::Forms::DialogResult::Yes)
				 {
					 SetAttrCompare();
					 return;
				 }
				 return;
			 }*/
			 WriteToDb();
		 }
private: System::Void bAddSourceAttrs_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 
			 if (_systemSourceTypeId == 1)
			 {
				 AddSemAttrForm^ form = gcnew AddSemAttrForm("", "");
				 form->ShowDialog();
				 //_sourceIdCol = form->IdCol;
				 //_sourceTitleCol = form->TitleCol;
				 //_dbSourceAttrs = form->Attributes;
			 }
			 else
			 {
				 //AddBdAttrsForm^ form = gcnew AddBdAttrsForm();
				 //form->ShowDialog();
				 //_sourceIdCol = form->IdCol;
				 //_sourceTitleCol = form->TitleCol;
				 //_dbSourceAttrs = form->Attributes;
			 }
			 

			 /*array<String^>^ arr = idCol->Split('.');
			 List<Object^>^ query = OdbcClass::ExecuteNonQueryStatic("select ID from " + OdbcClass::schema + "INTEGRATION_ATTRIBUTES where ID_INTGR_BOOK = " + 
			 id + " and SCHEMA_NAME = \'" + arr[0] + "\' and TABLE_NAME = \'" + arr[1] + "\' and ATTR_NAME = \'" arr[2] + "\'");
			 int idId = Decimal::ToInt32((Decimal)query[0]);
			 arr = titleCol->Split('.');
			 query = OdbcClass::ExecuteNonQueryStatic("select ID from " + OdbcClass::schema + "INTEGRATION_ATTRIBUTES where ID_INTGR_BOOK = " + 
			 id + " and SCHEMA_NAME = \'" + arr[0] + "\' and TABLE_NAME = \'" + arr[1] + "\' and ATTR_NAME = \'" arr[2] + "\'");
			 int idTitle = Decimal::ToInt32((Decimal)query[0]);*/
		 } 
};
}
