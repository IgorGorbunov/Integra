#pragma once

#include "ODBCclass.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для DetailResults
	/// </summary>
	public ref class DetailResults : public System::Windows::Forms::Form
	{
	private:
		int _idIntgr;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
			 OdbcClass^ _odbc;

	public:
		DetailResults(int idIntgr, OdbcClass^ odbc)
		{
			InitializeComponent();
			_idIntgr = idIntgr;
			_odbc = odbc;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DetailResults()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  bClose;

	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::DataGridView^  dgv;









	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		void SetEdittings()
		{
			int colCount = 8;
			String^ squery = String::Format("select IEE.ID, IEE.EDIT_DATE, IEE.EDIT_TYPE, ISS.NAME, IAA.ATTR_NAME, IAA.NAME, IEE.OLD_VAL, IEE.NEW_VAL " + 
				"from {0}INTEGRATION_EDITINGS IEE, {0}INTEGRATION_ATTRIBUTES IAA, {0}INTEGRATION_BOOK IBB, {0}INTEGRATED_SYSTEMS ISS "+
				"where IAA.ID = IEE.ID_ATTR and IAA.ID_INTGR_BOOK = IBB.ID and IBB.ID_SYSTEM = ISS.ID and IEE.ID_INTGR = {1}", _odbc->schema, _idIntgr);
			List<Object^>^ qList = _odbc->ExecuteQuery(squery);

			dgv->Rows->Clear();
			for (int i = 0; i < qList->Count; i+=colCount)
			{
				array<String^>^ row = gcnew array<String ^>(colCount);
				int id = OdbcClass::GetInt(qList[i+0]);
				row[0] = id + "";
				row[1] = qList[i+1]->ToString();
				int intType = OdbcClass::GetInt(qList[i+2]);
				switch (intType)
				{
				case 0:
					row[2] = "Добавление новой позиции";
					break;
				case 1:
					row[2] = "Измененеие позиции";
					break;
				case 2:
					row[2] = "Исключение позиции";
					break;
				}
				row[3] = qList[i+3]->ToString();
				row[4] = qList[i+4]->ToString();
				row[5] = qList[i+5]->ToString();
				row[6] = qList[i+6]->ToString();
				row[7] = qList[i+7]->ToString();
				dgv->Rows->Add(row);
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->bClose = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->dgv = (gcnew System::Windows::Forms::DataGridView());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgv))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(964, 47);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Корректировки:";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 311);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(964, 58);
			this->panel2->TabIndex = 1;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->bClose);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel3->Location = System::Drawing::Point(857, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(107, 58);
			this->panel3->TabIndex = 0;
			// 
			// bClose
			// 
			this->bClose->Location = System::Drawing::Point(12, 16);
			this->bClose->Name = L"bClose";
			this->bClose->Size = System::Drawing::Size(75, 23);
			this->bClose->TabIndex = 0;
			this->bClose->Text = L"Закрыть";
			this->bClose->UseVisualStyleBackColor = true;
			this->bClose->Click += gcnew System::EventHandler(this, &DetailResults::bClose_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(0, 47);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(964, 264);
			this->panel4->TabIndex = 2;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->dgv);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Padding = System::Windows::Forms::Padding(10);
			this->panel5->Size = System::Drawing::Size(964, 264);
			this->panel5->TabIndex = 0;
			// 
			// dgv
			// 
			this->dgv->AllowUserToAddRows = false;
			this->dgv->AllowUserToDeleteRows = false;
			this->dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->Column8, this->Column1, 
				this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7});
			this->dgv->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgv->Location = System::Drawing::Point(10, 10);
			this->dgv->Name = L"dgv";
			this->dgv->ReadOnly = true;
			this->dgv->Size = System::Drawing::Size(944, 244);
			this->dgv->TabIndex = 0;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"ID";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Visible = false;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Время корректировки";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 150;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Тип";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Система";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 150;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Код атрибута";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Наименование атрибута";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 200;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Старое значение";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Новое значение";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			// 
			// DetailResults
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(964, 369);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->MinimumSize = System::Drawing::Size(980, 407);
			this->Name = L"DetailResults";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Подробные результаты интеграции";
			this->Load += gcnew System::EventHandler(this, &DetailResults::DetailResults_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgv))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bClose_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Close();
			 }
private: System::Void DetailResults_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetEdittings();
		 }
};
}
