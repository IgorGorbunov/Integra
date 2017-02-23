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



	public: System::Windows::Forms::Label^  LblSourceCount;
	public: System::Windows::Forms::Label^  LblSourceStatus;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox2;



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
	private: System::Windows::Forms::Button^  bIntegNewSourceToTarget;
	private: System::Windows::Forms::Button^  bIntegNewTargetToSource;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  bDeleteFromTarget;
	private: System::Windows::Forms::Button^  bDeleteFromSource;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label13;
	public: System::Windows::Forms::Label^  lblMatchingStatus;
	private: System::Windows::Forms::Label^  label12;
	public: System::Windows::Forms::Label^  lblNequal;
	public: System::Windows::Forms::Label^  lblNmatching;
	public: 

			 IntegrationSettings^ _settings;

	public:
		Results3 (IntegrationSettings^ settings)
		{
			InitializeComponent();
			_settings = settings;
			if (_settings->Type == IntegrationSettings::IntegrationType::OneWay)
			{
				bDeleteFromSource->Enabled = false;
				bIntegNewTargetToSource->Enabled = false;
			}
			else
			{
				bDeleteFromSource->Enabled = true;
				bIntegNewTargetToSource->Enabled = true;
			}
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
			this->LblSourceStatus = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->LblSourceCount = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
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
			this->bIntegNewSourceToTarget = (gcnew System::Windows::Forms::Button());
			this->bIntegNewTargetToSource = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->bDeleteFromTarget = (gcnew System::Windows::Forms::Button());
			this->bDeleteFromSource = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->lblNequal = (gcnew System::Windows::Forms::Label());
			this->lblNmatching = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->lblMatchingStatus = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSourceNew))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTargetNew))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
			this->groupBox3->SuspendLayout();
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
			this->dgvSourceNew->Size = System::Drawing::Size(838, 242);
			this->dgvSourceNew->TabIndex = 0;
			// 
			// dgvTargetNew
			// 
			this->dgvTargetNew->AllowUserToAddRows = false;
			this->dgvTargetNew->AllowUserToDeleteRows = false;
			this->dgvTargetNew->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dgvTargetNew->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTargetNew->Location = System::Drawing::Point(31, 454);
			this->dgvTargetNew->Name = L"dgvTargetNew";
			this->dgvTargetNew->ReadOnly = true;
			this->dgvTargetNew->RowHeadersVisible = false;
			this->dgvTargetNew->Size = System::Drawing::Size(838, 180);
			this->dgvTargetNew->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(38, 126);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(215, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Новые записи в справочнике-источнике:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(38, 438);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(220, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Новые записи в справочнике-получателе:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(920, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(219, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Записи с различающимися реквизитами:";
			// 
			// lbDifferences
			// 
			this->lbDifferences->FormattingEnabled = true;
			this->lbDifferences->Location = System::Drawing::Point(908, 142);
			this->lbDifferences->Name = L"lbDifferences";
			this->lbDifferences->Size = System::Drawing::Size(247, 485);
			this->lbDifferences->TabIndex = 6;
			this->lbDifferences->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Results3::lbDifferences_MouseDoubleClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->LblSourceStatus);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->LblSourceCount);
			this->groupBox1->Location = System::Drawing::Point(31, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(250, 100);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Обработка данных справочника-источника";
			// 
			// LblSourceStatus
			// 
			this->LblSourceStatus->AutoSize = true;
			this->LblSourceStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->LblSourceStatus->ForeColor = System::Drawing::Color::Blue;
			this->LblSourceStatus->Location = System::Drawing::Point(71, 26);
			this->LblSourceStatus->Name = L"LblSourceStatus";
			this->LblSourceStatus->Size = System::Drawing::Size(32, 13);
			this->LblSourceStatus->TabIndex = 7;
			this->LblSourceStatus->Text = L"Идет";
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
			// LblSourceCount
			// 
			this->LblSourceCount->AutoSize = true;
			this->LblSourceCount->Location = System::Drawing::Point(150, 50);
			this->LblSourceCount->Name = L"LblSourceCount";
			this->LblSourceCount->Size = System::Drawing::Size(13, 13);
			this->LblSourceCount->TabIndex = 8;
			this->LblSourceCount->Text = L"0";
			this->LblSourceCount->Visible = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->LblTargetCount);
			this->groupBox2->Controls->Add(this->LblTargetStatus);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Location = System::Drawing::Point(310, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(260, 100);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Обработка данных справочника-получателя";
			// 
			// LblTargetCount
			// 
			this->LblTargetCount->AutoSize = true;
			this->LblTargetCount->Location = System::Drawing::Point(152, 50);
			this->LblTargetCount->Name = L"LblTargetCount";
			this->LblTargetCount->Size = System::Drawing::Size(13, 13);
			this->LblTargetCount->TabIndex = 11;
			this->LblTargetCount->Text = L"0";
			this->LblTargetCount->Visible = false;
			// 
			// LblTargetStatus
			// 
			this->LblTargetStatus->AutoSize = true;
			this->LblTargetStatus->ForeColor = System::Drawing::Color::Blue;
			this->LblTargetStatus->Location = System::Drawing::Point(76, 26);
			this->LblTargetStatus->Name = L"LblTargetStatus";
			this->LblTargetStatus->Size = System::Drawing::Size(32, 13);
			this->LblTargetStatus->TabIndex = 6;
			this->LblTargetStatus->Text = L"Идет";
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
			this->bCancel->Location = System::Drawing::Point(988, 645);
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
			this->button2->Location = System::Drawing::Point(1080, 645);
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
			this->label8->Location = System::Drawing::Point(755, 410);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(219, 13);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Удаленные записи в системе получателе";
			this->label8->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(755, 230);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(214, 13);
			this->label9->TabIndex = 13;
			this->label9->Text = L"Удаленные записи в системе источнике";
			this->label9->Visible = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(748, 426);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(262, 129);
			this->dataGridView1->TabIndex = 12;
			this->dataGridView1->Visible = false;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(748, 246);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->Size = System::Drawing::Size(262, 115);
			this->dataGridView2->TabIndex = 11;
			this->dataGridView2->Visible = false;
			// 
			// bIntegNewSourceToTarget
			// 
			this->bIntegNewSourceToTarget->Location = System::Drawing::Point(41, 390);
			this->bIntegNewSourceToTarget->Name = L"bIntegNewSourceToTarget";
			this->bIntegNewSourceToTarget->Size = System::Drawing::Size(250, 29);
			this->bIntegNewSourceToTarget->TabIndex = 15;
			this->bIntegNewSourceToTarget->Text = L"Интегрировать в справочник-получатель";
			this->bIntegNewSourceToTarget->UseVisualStyleBackColor = true;
			this->bIntegNewSourceToTarget->Click += gcnew System::EventHandler(this, &Results3::bIntegNewSource_Click);
			// 
			// bIntegNewTargetToSource
			// 
			this->bIntegNewTargetToSource->Enabled = false;
			this->bIntegNewTargetToSource->Location = System::Drawing::Point(41, 645);
			this->bIntegNewTargetToSource->Name = L"bIntegNewTargetToSource";
			this->bIntegNewTargetToSource->Size = System::Drawing::Size(250, 29);
			this->bIntegNewTargetToSource->TabIndex = 16;
			this->bIntegNewTargetToSource->Text = L"Интегрировать в справочник-источник";
			this->bIntegNewTargetToSource->UseVisualStyleBackColor = true;
			this->bIntegNewTargetToSource->Click += gcnew System::EventHandler(this, &Results3::bIntegNewTarget_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(820, 561);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(112, 29);
			this->button4->TabIndex = 18;
			this->button4->Text = L"Интегрировать";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(820, 367);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(112, 29);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Интегрировать";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(18, 50);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(135, 13);
			this->label10->TabIndex = 11;
			this->label10->Text = L"Произведено сравенний:";
			// 
			// bDeleteFromTarget
			// 
			this->bDeleteFromTarget->Location = System::Drawing::Point(310, 645);
			this->bDeleteFromTarget->Name = L"bDeleteFromTarget";
			this->bDeleteFromTarget->Size = System::Drawing::Size(410, 29);
			this->bDeleteFromTarget->TabIndex = 19;
			this->bDeleteFromTarget->Text = L"Сформировать извещение на удаление позиции из справочника-получателя";
			this->bDeleteFromTarget->UseVisualStyleBackColor = true;
			this->bDeleteFromTarget->Click += gcnew System::EventHandler(this, &Results3::bDeleteFromTarget_Click);
			// 
			// bDeleteFromSource
			// 
			this->bDeleteFromSource->Location = System::Drawing::Point(310, 390);
			this->bDeleteFromSource->Name = L"bDeleteFromSource";
			this->bDeleteFromSource->Size = System::Drawing::Size(410, 29);
			this->bDeleteFromSource->TabIndex = 20;
			this->bDeleteFromSource->Text = L"Сформировать извещение на удаление позиции из справочника-источника";
			this->bDeleteFromSource->UseVisualStyleBackColor = true;
			this->bDeleteFromSource->Click += gcnew System::EventHandler(this, &Results3::bDeleteFromSource_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->lblNequal);
			this->groupBox3->Controls->Add(this->lblNmatching);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->lblMatchingStatus);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Location = System::Drawing::Point(599, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(270, 100);
			this->groupBox3->TabIndex = 21;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Сравнение позиций";
			// 
			// lblNequal
			// 
			this->lblNequal->AutoSize = true;
			this->lblNequal->Location = System::Drawing::Point(186, 73);
			this->lblNequal->Name = L"lblNequal";
			this->lblNequal->Size = System::Drawing::Size(13, 13);
			this->lblNequal->TabIndex = 16;
			this->lblNequal->Text = L"0";
			this->lblNequal->Visible = false;
			// 
			// lblNmatching
			// 
			this->lblNmatching->AutoSize = true;
			this->lblNmatching->Location = System::Drawing::Point(186, 50);
			this->lblNmatching->Name = L"lblNmatching";
			this->lblNmatching->Size = System::Drawing::Size(13, 13);
			this->lblNmatching->TabIndex = 15;
			this->lblNmatching->Text = L"0";
			this->lblNmatching->Visible = false;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(18, 73);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(116, 13);
			this->label13->TabIndex = 14;
			this->label13->Text = L"Идентичных записей:";
			// 
			// lblMatchingStatus
			// 
			this->lblMatchingStatus->AutoSize = true;
			this->lblMatchingStatus->ForeColor = System::Drawing::Color::Blue;
			this->lblMatchingStatus->Location = System::Drawing::Point(68, 26);
			this->lblMatchingStatus->Name = L"lblMatchingStatus";
			this->lblMatchingStatus->Size = System::Drawing::Size(32, 13);
			this->lblMatchingStatus->TabIndex = 13;
			this->lblMatchingStatus->Text = L"Идет";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(18, 26);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(44, 13);
			this->label12->TabIndex = 12;
			this->label12->Text = L"Статус:";
			// 
			// Results3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(1199, 709);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->bDeleteFromSource);
			this->Controls->Add(this->bDeleteFromTarget);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->bIntegNewTargetToSource);
			this->Controls->Add(this->bIntegNewSourceToTarget);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->bCancel);
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
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Results3::Results3_FormClosed);
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
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
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
							Attribute^ attibute = pair->Key;
							col->Name = attibute->FullCode;
							if (String::IsNullOrEmpty(attibute->Name))
							{
								col->HeaderText = attibute->Code;
							}
							else
							{
								col->HeaderText = attibute->Name;
							}
							
							grid->Columns->Add(col);
							if (attibute->FullCode == position->AttrId->FullCode)
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

			void SetLablesReady()
			{
				LblSourceStatus->Text = "Окончено!";
				LblSourceStatus->ForeColor = Color::Green;
				LblSourceStatus->Font = gcnew System::Drawing::Font(LblSourceStatus->Font, FontStyle::Bold);

				LblSourceCount->Text = ProgramIntegration::NinSource + "";
				LblSourceCount->Visible = true;
				
				LblTargetStatus->Text = "Окончено!";
				LblTargetStatus->ForeColor = Color::Green;
				LblTargetStatus->Font = gcnew System::Drawing::Font(LblTargetStatus->Font, FontStyle::Bold);

				LblTargetCount->Text = ProgramIntegration::NinTarget + "";
				LblTargetCount->Visible = true;

				lblMatchingStatus->Text = "Окончено!";
				lblMatchingStatus->ForeColor = Color::Green;
				lblMatchingStatus->Font = gcnew System::Drawing::Font(lblMatchingStatus->Font, FontStyle::Bold);

				lblNequal->Text = ProgramIntegration::Nequal + "";
				lblNequal->Visible = true;

				lblNmatching->Text = ProgramIntegration::Nmatches + "";
				lblNmatching->Visible = true;
			}


private: System::Void Results_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 
		 }
private: System::Void lbDifferences_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 if (lbDifferences->SelectedItem != nullptr)
			 {
				 for each (DifferencePosition^ pos in Differences)
				 {
					 if (pos->UnicId == lbDifferences->SelectedItem->ToString())
					 {
						 DifferencesForm^ form = gcnew DifferencesForm(pos, _settings->Type);
						 form->ShowDialog();
						 if (form->NewAttrNames != nullptr)
						 {
							 if (form->InTarget)
							 {
								 ProgramIntegration::UpdatePosTarget(pos->TPos, form->NewAttrNames);
							 }
							 else
							 {
								 ProgramIntegration::UpdatePosSource(pos->SPos, form->NewAttrNames);
							 }
							 lbDifferences->Items->Remove(lbDifferences->SelectedItem);
							 MessageBox::Show("Позиция интегрирована");
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
			 ProgramIntegration::StopIntegration();
			 Close();
		 }
private: System::Void Results3_Shown(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Application::DoEvents();
			 ProgramIntegration::StartIntegrationTable(_settings, this, LblSourceCount);
			 SetLablesReady();

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
					 MessageBox::Show("Позиция интегрирована!");
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

private: System::Void bDeleteFromSource_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 for (int i = 0; i < _sourceNew->Count; i++)
			 {
				 int iRow =  dgvSourceNew->SelectedCells[0]->RowIndex;
				 String^ id = dgvSourceNew[iColIdNewS, iRow]->Value->ToString();
				 if (_sourceNew[i]->UnicId == id)
				 {
					 ProgramIntegration::NoticeRemoveFromSource(_sourceNew[i]);
					 dgvSourceNew->Rows->RemoveAt(iRow);
					 _sourceNew->RemoveAt(i);
					 MessageBox::Show("Извещение создано!");
					 break;
				 }
			 }
		 }
private: System::Void bDeleteFromTarget_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 for (int i = 0; i < _targetNew->Count; i++)
			 {
				 int iRow =  dgvTargetNew->SelectedCells[0]->RowIndex;
				 String^ id = dgvTargetNew[iColIdNewT, iRow]->Value->ToString();
				 if (_targetNew[i]->UnicId == id)
				 {
					 ProgramIntegration::NoticeRemoveFromTarget(_targetNew[i]);
					 dgvTargetNew->Rows->RemoveAt(iRow);
					 _targetNew->RemoveAt(i);
					 MessageBox::Show("Извещение создано!");
					 break;
				 }
			 }
		 }
private: System::Void Results3_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
		 {
			 ProgramIntegration::StopIntegration();
		 }
};
}
