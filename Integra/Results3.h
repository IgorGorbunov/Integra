#pragma once

#include "Position.h"
#include "DiffererncePosition.h"
#include "DifferencesForm.h"
#include "Book.h"
#include "IntegrationSettings.h"
#include "ProgramIntegration.h"

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
	public ref class Results3 : public System::Windows::Forms::Form
	{
	public:
		List<Position^>^ _sourceNew;
		List<Position^>^ _targetNew;

		List<List<Object^>^>^ _sourceTabNew;
		List<List<Object^>^>^ _targetTabNew;

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
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridView^  dataGridView2;

	private:
		int selectId;
	private: System::Windows::Forms::Button^  bIntegNewSource;
	private: System::Windows::Forms::Button^  bIntegNewTarget;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
			 IntegrationSettings^ _settings;

	public:
		Results3 (IntegrationSettings^ settings)
		{
			_settings = settings;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Results3()
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
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->bIntegNewSource = (gcnew System::Windows::Forms::Button());
			this->bIntegNewTarget = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSourceNew))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTargetNew))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
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
			this->dgvSourceNew->RowHeadersVisible = false;
			this->dgvSourceNew->Size = System::Drawing::Size(258, 115);
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
			this->dgvTargetNew->RowHeadersVisible = false;
			this->dgvTargetNew->Size = System::Drawing::Size(258, 129);
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
			this->lbDifferences->Location = System::Drawing::Point(596, 143);
			this->lbDifferences->Name = L"lbDifferences";
			this->lbDifferences->Size = System::Drawing::Size(247, 329);
			this->lbDifferences->TabIndex = 6;
			this->lbDifferences->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Results3::lbDifferences_MouseDoubleClick);
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
			this->LblSourceAllCount->Size = System::Drawing::Size(13, 13);
			this->LblSourceAllCount->TabIndex = 10;
			this->LblSourceAllCount->Text = L"0";
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
			this->LblSourceCount->Visible = false;
			// 
			// LblSourceStatus
			// 
			this->LblSourceStatus->AutoSize = true;
			this->LblSourceStatus->ForeColor = System::Drawing::Color::Black;
			this->LblSourceStatus->Location = System::Drawing::Point(71, 26);
			this->LblSourceStatus->Name = L"LblSourceStatus";
			this->LblSourceStatus->Size = System::Drawing::Size(68, 13);
			this->LblSourceStatus->TabIndex = 7;
			this->LblSourceStatus->Text = L"В процессе:";
			this->LblSourceStatus->Visible = false;
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
			this->LblTargetCount->Visible = false;
			// 
			// LblTargetStatus
			// 
			this->LblTargetStatus->AutoSize = true;
			this->LblTargetStatus->ForeColor = System::Drawing::Color::Black;
			this->LblTargetStatus->Location = System::Drawing::Point(76, 26);
			this->LblTargetStatus->Name = L"LblTargetStatus";
			this->LblTargetStatus->Size = System::Drawing::Size(68, 13);
			this->LblTargetStatus->TabIndex = 6;
			this->LblTargetStatus->Text = L"В процессе:";
			this->LblTargetStatus->Visible = false;
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
			this->bCancel->Visible = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &Results3::bCancel_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(783, 495);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Закрыть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Results3::button2_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(312, 306);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(219, 13);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Удаленные записи в системе получателе";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(312, 126);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(214, 13);
			this->label9->TabIndex = 13;
			this->label9->Text = L"Удаленные записи в системе источнике";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(305, 322);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(262, 129);
			this->dataGridView1->TabIndex = 12;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(305, 142);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->Size = System::Drawing::Size(262, 115);
			this->dataGridView2->TabIndex = 11;
			// 
			// bIntegNewSource
			// 
			this->bIntegNewSource->Location = System::Drawing::Point(92, 263);
			this->bIntegNewSource->Name = L"bIntegNewSource";
			this->bIntegNewSource->Size = System::Drawing::Size(112, 29);
			this->bIntegNewSource->TabIndex = 15;
			this->bIntegNewSource->Text = L"Интегрировать";
			this->bIntegNewSource->UseVisualStyleBackColor = true;
			this->bIntegNewSource->Click += gcnew System::EventHandler(this, &Results3::bIntegNewSource_Click);
			// 
			// bIntegNewTarget
			// 
			this->bIntegNewTarget->Location = System::Drawing::Point(92, 457);
			this->bIntegNewTarget->Name = L"bIntegNewTarget";
			this->bIntegNewTarget->Size = System::Drawing::Size(112, 29);
			this->bIntegNewTarget->TabIndex = 16;
			this->bIntegNewTarget->Text = L"Интегрировать";
			this->bIntegNewTarget->UseVisualStyleBackColor = true;
			this->bIntegNewTarget->Click += gcnew System::EventHandler(this, &Results3::bIntegNewTarget_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(377, 457);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(112, 29);
			this->button4->TabIndex = 18;
			this->button4->Text = L"Интегрировать";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(377, 263);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(112, 29);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Интегрировать";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// Results3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(883, 530);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->bIntegNewTarget);
			this->Controls->Add(this->bIntegNewSource);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->dataGridView2);
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
			this->Name = L"Results3";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Обработка данных";
			this->Load += gcnew System::EventHandler(this, &Results3::Results_Load);
			this->Shown += gcnew System::EventHandler(this, &Results3::Results3_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSourceNew))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTargetNew))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		int iColIdNewS, iColIdNewT, iColIdDelS, iColIdDelT;


		public:
			void SetNewSource(Position^ position)
			{
				SetNew(dgvSourceNew, position, iColIdNewS);
			}

			void SetNewTarget(Position^ position)
			{
				SetNew(dgvTargetNew, position, iColIdNewT);
			}

			


			void SetNewDiff(DifferencePosition^ pos)
			{
				lbDifferences->Items->Add(pos->UnicId);
			}

			private:

			void SetNew(DataGridView^ grid, Position^ position, int% iColId)
			{
				if (position != nullptr)
				{
					if (grid->Columns->Count ==0)
					{
						Dictionary<Attribute^, String^>^ attrs =  position->AttributesAndValues;
						int i = 0;
						for each (KeyValuePair<Attribute^, String^>^ pair in attrs)
						{
							DataGridViewTextBoxColumn^ col = gcnew DataGridViewTextBoxColumn();
							col->Name = pair->Key->FullCode;
							col->HeaderText = pair->Key->Name;
							grid->Columns->Add(col);
							if (pair->Key->FullCode == position->AttrIdCode)
							{
								iColId = i;
							}
							i++;
						}
					}
					Dictionary<Attribute^, String^>^ attrs = position->AttributesAndValues;
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
	
			void SetDgvNew(DataGridView^ grid, List<Position^>^ positions, int% iColId)
			{
				if (positions->Count > 0)
				{
					for each (Position^ pos in positions)
					{
						SetNew(grid, pos, iColId);
					}
				}

			}

			void SetVisibleStartLabels()
			{
				label12->Visible = true;
				//label14->Visible = true;
				LblSourceStatus->Visible = true;
				LblSourceCount->Visible = true;
				LblSourceAllCount->Visible = true;

				/*LblTargetStatus->Visible = true;
				LblTargetCount->Visible = true;
				LblTargetAllCount->Visible = true;*/
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
			 SetVisibleStartLabels();
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
						 if (form->NewAttrNames != nullptr)
						 {
							 ProgramIntegration::UpdatePosTarget(pos->TPos, form->NewAttrNames);
							 lbDifferences->Items->Remove(lbDifferences->SelectedItem);
						 }
						 break;
					 }
				 }
			 }
			 
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
private: System::Void Results3_Shown(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Application::DoEvents();
			 ProgramIntegration::StartIntegrationTable(_settings, this, LblSourceCount);
			 LblSourceStatus->Text = "Окончено";
			 LblTargetStatus->Text = "Окончено";

			 _sourceNew = ProgramIntegration::SourceNew;
			 _targetNew = ProgramIntegration::TargetNew;
			 Differences = ProgramIntegration::Differences;
			 SetDgvNew(dgvSourceNew, _sourceNew, iColIdNewS);
			 SetDgvNew(dgvTargetNew, _targetNew, iColIdNewT);
			 SetListDiff();
		 }
private: System::Void bIntegNewSource_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 for (int i = 0; i < _sourceNew->Count; i++)
			 {
				 int iRow =  dgvSourceNew->SelectedCells[0]->RowIndex;
				 String^ id = dgvSourceNew[iColIdNewS, iRow]->Value->ToString();
				 if (_sourceNew[i]->UnicId == id)
				 {
					 ProgramIntegration::AddPosToTarget(_sourceNew[i]);
					 dgvSourceNew->Rows->RemoveAt(iRow);
					 _sourceNew->RemoveAt(i);
					 break;
				 }
			 }
		 }
private: System::Void bIntegNewTarget_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 for (int i = 0; i < _targetNew->Count; i++)
			 {
				 int iRow =  dgvTargetNew->SelectedCells[0]->RowIndex;
				 String^ id = dgvTargetNew[iColIdNewT, iRow]->Value->ToString();
				 if (_targetNew[i]->UnicId == id)
				 {
					 ProgramIntegration::AddPosToSource(_targetNew[i]);
 					 dgvTargetNew->Rows->RemoveAt(iRow);
 					 _targetNew->RemoveAt(i);
					 break;
				 }
			 }
		 }

};
}
