#pragma once

#include "Position.h"
#include "DiffererncePosition.h"
#include "DifferencesForm.h"
#include "Book.h"

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
	public ref class Results2 : public System::Windows::Forms::Form
	{
	public:
		List<Position^>^ _sourceNew;
		List<Position^>^ _targetNew;
		List<Position^>^ TargetPositions;
		List<DifferencePosition^>^ Differences;
		bool IsBusy;


		System::ComponentModel::BackgroundWorker^ Worker;
		System::ComponentModel::DoWorkEventArgs ^ eWorker;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	public: System::Windows::Forms::Label^  LblSourceAllCount;

	private: System::Windows::Forms::Label^  label12;
	public: System::Windows::Forms::Label^  LblSourceCount;
	public: System::Windows::Forms::Label^  LblSourceStatus;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	public: System::Windows::Forms::Label^  LblTargetAllCount;

	private: System::Windows::Forms::Label^  label14;
	public: System::Windows::Forms::Label^  LblTargetCount;
	public: System::Windows::Forms::Label^  LblTargetStatus;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	public: System::Windows::Forms::Button^  bCancel;
	private: 


	private: System::Windows::Forms::Button^  button2;

	private:
		int selectId;

	public:
		Results2 (Book^ book)
		{
			IsBusy = true;
			Differences = gcnew List<DifferencePosition ^>();
			_sourceNew = gcnew List<Position ^>();
			_targetNew = gcnew List<Position ^>();

			InitializeComponent();
			LblTargetStatus->Text = "В процессе";
			LblTargetStatus->ForeColor = Color::Yellow;

			int n;
			TargetPositions = book->GetAllPositions22(n);
			LblTargetStatus->Text = "Завершено";
			LblTargetStatus->ForeColor = Color::Green;
			LblTargetCount->Text = n + "";
			IsBusy = false;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Results2()
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->LblSourceAllCount = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->LblSourceCount = (gcnew System::Windows::Forms::Label());
			this->LblSourceStatus = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->LblTargetAllCount = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->LblTargetCount = (gcnew System::Windows::Forms::Label());
			this->LblTargetStatus = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSourceNew))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTargetNew))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// dgvSourceNew
			// 
			this->dgvSourceNew->AllowUserToAddRows = false;
			this->dgvSourceNew->AllowUserToDeleteRows = false;
			this->dgvSourceNew->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvSourceNew->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSourceNew->Location = System::Drawing::Point(31, 142);
			this->dgvSourceNew->Name = L"dgvSourceNew";
			this->dgvSourceNew->ReadOnly = true;
			this->dgvSourceNew->Size = System::Drawing::Size(556, 150);
			this->dgvSourceNew->TabIndex = 0;
			// 
			// dgvTargetNew
			// 
			this->dgvTargetNew->AllowUserToAddRows = false;
			this->dgvTargetNew->AllowUserToDeleteRows = false;
			this->dgvTargetNew->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvTargetNew->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTargetNew->Location = System::Drawing::Point(31, 322);
			this->dgvTargetNew->Name = L"dgvTargetNew";
			this->dgvTargetNew->ReadOnly = true;
			this->dgvTargetNew->Size = System::Drawing::Size(556, 150);
			this->dgvTargetNew->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(38, 126);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(190, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Новые записи в системе источнике";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(38, 306);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(195, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Новые записи в системе получателе";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(608, 126);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(208, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Записи с различающимися атрибутами";
			// 
			// lbDifferences
			// 
			this->lbDifferences->FormattingEnabled = true;
			this->lbDifferences->Location = System::Drawing::Point(611, 143);
			this->lbDifferences->Name = L"lbDifferences";
			this->lbDifferences->Size = System::Drawing::Size(232, 329);
			this->lbDifferences->TabIndex = 6;
			this->lbDifferences->SelectedIndexChanged += gcnew System::EventHandler(this, &Results2::lbDifferences_SelectedIndexChanged);
			this->lbDifferences->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Results2::lbDifferences_MouseDoubleClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->LblSourceAllCount);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->LblSourceCount);
			this->groupBox1->Controls->Add(this->LblSourceStatus);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(31, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(393, 100);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Обработка данных системы-источника";
			// 
			// LblSourceAllCount
			// 
			this->LblSourceAllCount->AutoSize = true;
			this->LblSourceAllCount->Location = System::Drawing::Point(194, 50);
			this->LblSourceAllCount->Name = L"LblSourceAllCount";
			this->LblSourceAllCount->Size = System::Drawing::Size(37, 13);
			this->LblSourceAllCount->TabIndex = 10;
			this->LblSourceAllCount->Text = L"50000";
			this->LblSourceAllCount->Visible = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(173, 50);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(19, 13);
			this->label12->TabIndex = 9;
			this->label12->Text = L"из";
			this->label12->Visible = false;
			// 
			// LblSourceCount
			// 
			this->LblSourceCount->AutoSize = true;
			this->LblSourceCount->Location = System::Drawing::Point(130, 50);
			this->LblSourceCount->Name = L"LblSourceCount";
			this->LblSourceCount->Size = System::Drawing::Size(13, 13);
			this->LblSourceCount->TabIndex = 8;
			this->LblSourceCount->Text = L"0";
			// 
			// LblSourceStatus
			// 
			this->LblSourceStatus->AutoSize = true;
			this->LblSourceStatus->ForeColor = System::Drawing::Color::Red;
			this->LblSourceStatus->Location = System::Drawing::Point(71, 26);
			this->LblSourceStatus->Name = L"LblSourceStatus";
			this->LblSourceStatus->Size = System::Drawing::Size(74, 13);
			this->LblSourceStatus->TabIndex = 7;
			this->LblSourceStatus->Text = L"Остановлено";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(21, 26);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 13);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Статус:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 50);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(111, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Обработано данных:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->LblTargetAllCount);
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->LblTargetCount);
			this->groupBox2->Controls->Add(this->LblTargetStatus);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Location = System::Drawing::Point(450, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(393, 100);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Обработка данных системы-приемника";
			// 
			// LblTargetAllCount
			// 
			this->LblTargetAllCount->AutoSize = true;
			this->LblTargetAllCount->Location = System::Drawing::Point(207, 50);
			this->LblTargetAllCount->Name = L"LblTargetAllCount";
			this->LblTargetAllCount->Size = System::Drawing::Size(37, 13);
			this->LblTargetAllCount->TabIndex = 13;
			this->LblTargetAllCount->Text = L"50000";
			this->LblTargetAllCount->Visible = false;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(186, 50);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(19, 13);
			this->label14->TabIndex = 12;
			this->label14->Text = L"из";
			this->label14->Visible = false;
			// 
			// LblTargetCount
			// 
			this->LblTargetCount->AutoSize = true;
			this->LblTargetCount->Location = System::Drawing::Point(143, 50);
			this->LblTargetCount->Name = L"LblTargetCount";
			this->LblTargetCount->Size = System::Drawing::Size(13, 13);
			this->LblTargetCount->TabIndex = 11;
			this->LblTargetCount->Text = L"0";
			// 
			// LblTargetStatus
			// 
			this->LblTargetStatus->AutoSize = true;
			this->LblTargetStatus->ForeColor = System::Drawing::Color::Red;
			this->LblTargetStatus->Location = System::Drawing::Point(76, 26);
			this->LblTargetStatus->Name = L"LblTargetStatus";
			this->LblTargetStatus->Size = System::Drawing::Size(74, 13);
			this->LblTargetStatus->TabIndex = 6;
			this->LblTargetStatus->Text = L"Остановлено";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(26, 26);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 13);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Статус:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(26, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(111, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Обработано данных:";
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(691, 495);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 9;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &Results2::bCancel_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(783, 495);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Закрыть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Results2::button2_Click);
			// 
			// Results2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(883, 530);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->lbDifferences);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dgvTargetNew);
			this->Controls->Add(this->dgvSourceNew);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Results2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Результаты";
			this->Load += gcnew System::EventHandler(this, &Results2::Results_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSourceNew))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTargetNew))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public:
			void SetNewSource(Position^ position)
			{
				SetNew(dgvSourceNew, position);
			}

			void SetNewTarget(Position^ position)
			{
				SetNew(dgvTargetNew, position);
			}

			void SetNewDiff(DifferencePosition^ pos)
			{
				lbDifferences->Items->Add(pos->UnicId);
			}

			private:

			void SetNew(DataGridView^ grid, Position^ position)
			{
				if (position != nullptr)
				{
					if (grid->Columns->Count ==0)
					{
						Dictionary<Attribute^, String^>^ attrs =  position->Attributes;
						for each (KeyValuePair<Attribute^, String^>^ pair in attrs)
						{
							DataGridViewTextBoxColumn^ col = gcnew DataGridViewTextBoxColumn();
							col->Name = pair->Key->Code;
							col->HeaderText = pair->Key->Code;
							grid->Columns->Add(col);
						}
					}
					Dictionary<Attribute^, String^>^ attrs = position->Attributes;
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
	
			void SetDgvNew(DataGridView^ grid, List<Position^>^ positions)
			{
				if (positions->Count > 0)
				{
					for each (Position^ pos in positions)
					{
						SetNew(grid, pos);
					}
				}

			}

			void SetListDiff()
			{
				if (Differences->Count > 0)
				{
					for each (DifferencePosition^ pos in Differences)
					{
						SetNewDiff(pos);
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
				 for each (DifferencePosition^ pos in Differences)
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
private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Worker->CancelAsync();
			 bCancel->Enabled = false;
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
};
}
