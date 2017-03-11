#pragma once

#include "ODBCclass.h"
#include "IntegrationSettings.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AutoConfigsForm
	/// </summary>
	public ref class AutoConfigsForm : public System::Windows::Forms::Form
	{
	private:
		OdbcClass^ _odbc;
		int _autoSchemaId;

		// 0 - add, 1 - edit
		int _type;
	private: System::Windows::Forms::DateTimePicker^  dtpTime;

		Dictionary<int, String^>^ _intSchemas;

	public:
		void Init(OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
		}

		AutoConfigsForm(OdbcClass^ odbc)
		{
			Init(odbc);
			_type = 0;
		}

		AutoConfigsForm(OdbcClass^ odbc, int id)
		{
			Init(odbc);
			
			_type = 1;
			_autoSchemaId = id;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AutoConfigsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  cbSchema;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::ComboBox^  cbPeriod;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::CheckBox^  cbTurnOn;
	private: System::Windows::Forms::Button^  bCancel;


	private: System::Windows::Forms::Button^  bOk;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tbName;


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
			this->cbSchema = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cbPeriod = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cbTurnOn = (gcnew System::Windows::Forms::CheckBox());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->dtpTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// cbSchema
			// 
			this->cbSchema->FormattingEnabled = true;
			this->cbSchema->Location = System::Drawing::Point(26, 68);
			this->cbSchema->Name = L"cbSchema";
			this->cbSchema->Size = System::Drawing::Size(244, 21);
			this->cbSchema->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(27, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Интеграционная схема:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Время запуска:";
			// 
			// cbPeriod
			// 
			this->cbPeriod->FormattingEnabled = true;
			this->cbPeriod->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Ежедневно", L"Еженедельно", L"Ежемесячно", L"Ежеквартально", 
				L"Ежегодно"});
			this->cbPeriod->Location = System::Drawing::Point(132, 119);
			this->cbPeriod->Name = L"cbPeriod";
			this->cbPeriod->Size = System::Drawing::Size(138, 21);
			this->cbPeriod->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(138, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Периодичность запуска:";
			// 
			// cbTurnOn
			// 
			this->cbTurnOn->AutoSize = true;
			this->cbTurnOn->Location = System::Drawing::Point(39, 163);
			this->cbTurnOn->Name = L"cbTurnOn";
			this->cbTurnOn->Size = System::Drawing::Size(75, 17);
			this->cbTurnOn->TabIndex = 6;
			this->cbTurnOn->Text = L"Включить";
			this->cbTurnOn->UseVisualStyleBackColor = true;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(195, 195);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 7;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &AutoConfigsForm::bCancel_Click);
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(107, 195);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 8;
			this->bOk->Text = L"ОК";
			this->bOk->UseVisualStyleBackColor = true;
			this->bOk->Click += gcnew System::EventHandler(this, &AutoConfigsForm::bOk_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(27, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(233, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Наименование автоматической интеграции:";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(23, 29);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(247, 20);
			this->tbName->TabIndex = 10;
			// 
			// dtpTime
			// 
			this->dtpTime->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dtpTime->Location = System::Drawing::Point(26, 120);
			this->dtpTime->Name = L"dtpTime";
			this->dtpTime->ShowUpDown = true;
			this->dtpTime->Size = System::Drawing::Size(76, 20);
			this->dtpTime->TabIndex = 11;
			this->dtpTime->Value = System::DateTime(2017, 3, 10, 22, 0, 0, 0);
			// 
			// AutoConfigsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(286, 229);
			this->Controls->Add(this->dtpTime);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->cbTurnOn);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->cbPeriod);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cbSchema);
			this->Name = L"AutoConfigsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавить/редактировать автозапуск интеграционной схемы";
			this->Load += gcnew System::EventHandler(this, &AutoConfigsForm::AutoConfigsForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void SetSchemas()
		{
			_intSchemas = IntegrationSettings::GetIntSchemas(_odbc);
			for each (KeyValuePair<int, String^>^ pair in _intSchemas)
			{
				cbSchema->Items->Add(pair->Key + " - " + pair->Value);
			}
		}

		void AddAutoIntegration()
		{
			String^ columns = "ID,INT_SCHEMA_ID,START_TIME,ON_OFF,START_PERIOD,CREATE_USER,CREATE_DATE,INT_NAME";

			int id = _odbc->GetLastFreeId(_odbc->schema + "AUTO_INT_CONFIGS");
			String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
			String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);

			int schemaId = -1;
			for each (KeyValuePair<int, String^>^ pair in _intSchemas)
			{
				if (cbSchema->SelectedItem->ToString() == pair->Key + " - " + pair->Value)
				{
					schemaId = pair->Key;
					break;
				}
			}

			String^ sTime = _odbc->GetSqlDate(dtpTime->Value);
			int onOff = 0;
			if (cbTurnOn->Checked)
			{
				onOff = 1;
			}
			int period = cbPeriod->SelectedIndex;
			String^ name = OdbcClass::GetSqlString(tbName->Text);

			String^ sQuery = String::Format("insert into {0}AUTO_INT_CONFIGS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7}, {8}, {9})",
				_odbc->schema, columns, id, schemaId, sTime, onOff, period, sqlUser, sqlDate, name);
			_odbc->ExecuteNonQuery(sQuery);
		}

	private: System::Void AutoConfigsForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (_type == 0)
				 {
					 SetSchemas();
				 }
				 else
				 {
					 //todo
				 }
			 }
private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //todo check
			 if (_type == 0)
			 {
				 AddAutoIntegration();
			 }
			 else
			 {
				 //todo
			 }
			 Close();
		 }
};
}
