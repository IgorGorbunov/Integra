#pragma once
#include "ODBCclass.h"
#include "Attribute.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для GroupParamsForm
	/// </summary>
	public ref class GroupParamsForm : public System::Windows::Forms::Form
	{
	public:
		String^ Schtab;
		Attribute^ IdAttr;
		Attribute^ NameAttr;
		Dictionary<Attribute^,Attribute^>^ Attrs;

	private:
		OdbcClass^ _odbc;
		bool _attrsColFilled;
		List<Attribute^>^ _fieldList;
		bool _init;

		String^ _schema;
		String^ _table;

		String^ _idCol;
		String^ _nameCol;
		Dictionary<String^,String^>^ _attrs;

	public:
		GroupParamsForm(OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GroupParamsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox1;


	private: System::Windows::Forms::Label^  label5;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  cbId;
	private: System::Windows::Forms::ComboBox^  cbName;
	private: System::Windows::Forms::ComboBox^  cbSchema;
	private: System::Windows::Forms::ComboBox^  cbTable;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column2;
	private: System::Windows::Forms::Button^  bOk;
	private: System::Windows::Forms::Button^  bCancel;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->cbTable = (gcnew System::Windows::Forms::ComboBox());
			this->cbSchema = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cbId = (gcnew System::Windows::Forms::ComboBox());
			this->cbName = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 169);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(193, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Обозначение наименования группы:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(266, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Обозначение ссылочного идентификатора группы:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->cbTable);
			this->groupBox1->Controls->Add(this->cbSchema);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(324, 84);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Таблица групп элементов";
			// 
			// cbTable
			// 
			this->cbTable->FormattingEnabled = true;
			this->cbTable->Location = System::Drawing::Point(170, 50);
			this->cbTable->Name = L"cbTable";
			this->cbTable->Size = System::Drawing::Size(121, 21);
			this->cbTable->TabIndex = 10;
			this->cbTable->SelectedIndexChanged += gcnew System::EventHandler(this, &GroupParamsForm::cbTable_SelectedIndexChanged);
			// 
			// cbSchema
			// 
			this->cbSchema->FormattingEnabled = true;
			this->cbSchema->Location = System::Drawing::Point(15, 50);
			this->cbSchema->Name = L"cbSchema";
			this->cbSchema->Size = System::Drawing::Size(121, 21);
			this->cbSchema->TabIndex = 9;
			this->cbSchema->SelectedIndexChanged += gcnew System::EventHandler(this, &GroupParamsForm::cbSchema_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(168, 28);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(123, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Обозначение таблицы:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 28);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(113, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Обозначение схемы:";
			// 
			// cbId
			// 
			this->cbId->FormattingEnabled = true;
			this->cbId->Location = System::Drawing::Point(32, 131);
			this->cbId->Name = L"cbId";
			this->cbId->Size = System::Drawing::Size(161, 21);
			this->cbId->TabIndex = 7;
			// 
			// cbName
			// 
			this->cbName->FormattingEnabled = true;
			this->cbName->Location = System::Drawing::Point(32, 185);
			this->cbName->Name = L"cbName";
			this->cbName->Size = System::Drawing::Size(161, 21);
			this->cbName->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 222);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(116, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Реквизитный состав:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Column1, 
				this->Column2});
			this->dataGridView1->Location = System::Drawing::Point(35, 238);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(286, 226);
			this->dataGridView1->TabIndex = 10;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Обозначение";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 120;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Наименование";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 120;
			// 
			// bOk
			// 
			this->bOk->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bOk->Location = System::Drawing::Point(165, 483);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 11;
			this->bOk->Text = L"OK";
			this->bOk->UseVisualStyleBackColor = false;
			this->bOk->Click += gcnew System::EventHandler(this, &GroupParamsForm::bOk_Click);
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(246, 483);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 12;
			this->bCancel->Text = L"Cancel";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &GroupParamsForm::bCancel_Click);
			// 
			// GroupParamsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(352, 524);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cbName);
			this->Controls->Add(this->cbId);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Name = L"GroupParamsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление/редактирование реквизитов групп";
			this->Load += gcnew System::EventHandler(this, &GroupParamsForm::GroupParamsForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:

			String^ GetSchtab()
			{
				if (cbTable->SelectedItem == nullptr ||
					String::IsNullOrEmpty(cbTable->SelectedItem->ToString()))
				{
					_schema = "";
					_table = "";
					return nullptr;
				}
				if (cbSchema->SelectedItem == nullptr ||
					String::IsNullOrEmpty(cbSchema->SelectedItem->ToString()))
				{
					_schema = "";
					_table = cbTable->SelectedItem->ToString()->Trim()->ToUpper();
					return _table;
				}
				else
				{
					_schema = cbSchema->SelectedItem->ToString()->Trim()->ToUpper();
					_table = cbTable->SelectedItem->ToString()->Trim()->ToUpper();
					return _schema + "." + _table;
				}
			}

			void SetSchemas()
			{
				if (_odbc->DataSource == "ACCESS")
				{
					cbSchema->Enabled = false;
					SetTables("");
				}
			}

			void SetTables(String^ schemaName)
			{
				cbTable->DataSource = _odbc->GetTables(schemaName);
				cbTable->SelectedItem = nullptr;
			}

			void SetComboBox(ComboBox^ cb)
			{
				cb->Items->Clear();
				for each (Attribute^ s in _fieldList)
				{
					cb->Items->Add(s->FullCode);
				}
				cb->SelectedItem = nullptr;
			}

private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Schtab = nullptr;
			 _idCol = nullptr;
			 _nameCol = nullptr;
			 _attrs = nullptr;
			 Close();
		 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Schtab = GetSchtab();
			 String^ idCode = cbId->SelectedItem->ToString()->ToUpper();
			 _idCol = Schtab + "." + idCode;
			 IdAttr = gcnew Attribute(_schema, _table, idCode, "");
			 //todo add length datatype

			 String^ nameCode = cbName->SelectedItem->ToString()->ToUpper();
			 _nameCol = Schtab + "." + nameCode;
			 NameAttr = gcnew Attribute(_schema, _table, nameCode, "");
			 //todo add length datatype

			 _attrs = gcnew Dictionary<String ^, String ^>();
			 Attrs = gcnew Dictionary<Attribute ^, Attribute ^>();
			 for (int i = 0; i < dataGridView1->Rows->Count; i++)
			 {
				 if ((dataGridView1[0, i]->Value == nullptr || String::IsNullOrEmpty(dataGridView1[0, i]->Value->ToString())) &&
					 (dataGridView1[1, i]->Value == nullptr || String::IsNullOrEmpty(dataGridView1[1, i]->Value->ToString())))
				 {
					 continue;
				 }
				 String^ title = dataGridView1[0, i]->Value->ToString()->Trim()->ToUpper();
				 String^ schTitle = String::Format("{0}.{1}", Schtab, title);
				 Attribute^ titleAttr = gcnew Attribute(_schema, _table, title, "");
				 //todo add length datatype

				 String^ name = dataGridView1[1, i]->Value->ToString()->Trim()->ToUpper();
				 String^ schName = String::Format("{0}.{1}", Schtab, name);
				 Attribute^ nameAttr = gcnew Attribute(_schema, _table, name, "");
				 //todo add length datatype

				 _attrs->Add(schTitle, schName);
				 Attrs->Add(titleAttr, nameAttr);
			 }
			 Close();
		 }

private: System::Void GroupParamsForm_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 _init = true;
			 SetSchemas();
			 _init = false;
		 }
private: System::Void cbSchema_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetTables(cbSchema->SelectedItem->ToString());
		 }

private: System::Void cbTable_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (_init)
			 {
				 return;
			 }

			 Schtab = GetSchtab();

			 List<Object^>^ cols = _odbc->GetTableInfo7("", cbTable->SelectedItem->ToString());
			 for (int i = 0; i < cols->Count; i+=7)
			 {
				 String^ code = OdbcClass::GetResString(cols[i+0]);
				 String^ name = OdbcClass::GetResString(cols[i+1]);
				 String^ dataType = OdbcClass::GetResString(cols[i+2]);
				 int dataLength = _odbc->GetResInt(cols[i+3]);
				 int dataPrescision = _odbc->GetResInt(cols[i+4]);
				 int dataScale = _odbc->GetResInt(cols[i+5]);
				 String^ sIsNull = _odbc->GetResString(cols[i+6]);
				 if (dataPrescision > 0)
				 {
					 dataLength = dataPrescision;
				 }
				 bool isNull = false;
				 if (sIsNull == "Y" || sIsNull == "1")
				 {
					 isNull = true;
				 }
				 Attribute^ attr = gcnew Attribute(_schema, _table, code, name, isNull);
				 attr->SetDataType(dataType, dataLength, dataScale);
			 }


			 SetComboBox(cbId);
			 SetComboBox(cbName);
			 Column1->DataSource = _fieldList;
			 Column2->DataSource = _fieldList;
		 }
};
}
