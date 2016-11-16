#pragma once

#include "StringFunctions.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AttrCompareForm
	/// </summary>
	public ref class AttrCompareForm : public System::Windows::Forms::Form
	{
	private:
		int _sourceTypeId;
		int _targetTypeId;

		int _colId;

		String^ _sourceSchTblColId;
		String^ _sourceSchemaColId;
		String^ _sourceTableColId;

		String^ _targetSchTblColId;
		String^ _targetSchemaColId;
		String^ _targetTableColId;

		List<String^>^ _sourceFields;
		List<String^>^ _targetFields;

		bool _sourceLinkHasCols;
		bool _targetLinkHasCols;

		List<array<String^>^>^ _attrs;
		List<array<String^>^>^ _sourceLinks;
		List<array<String^>^>^ _targetLinks;
		List<array<String^>^>^ _equivs;

	public:
		AttrCompareForm(int sourceTypeId, int targetTypeId, List<array<String^>^>^ attrs, List<array<String^>^>^ sourceLinks, List<array<String^>^>^ targetLinks, List<array<String^>^>^ equivs)
		{
			InitializeComponent();
			_sourceTypeId = sourceTypeId;
			_targetTypeId = targetTypeId;
			_sourceFields = gcnew List<String ^>();
			_targetFields = gcnew List<String ^>();

			_attrs = attrs;
			_sourceLinks = sourceLinks;
			_targetLinks = targetLinks;
			_equivs = equivs;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AttrCompareForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::DataGridView^  dgvAttrs;
	protected: 

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  gbTarget;

	private: System::Windows::Forms::DataGridView^  dgvLinkTarget;
	private: System::Windows::Forms::GroupBox^  gbSource;


	private: System::Windows::Forms::DataGridView^  dgvLinkSource;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::DataGridView^  dgvEquiv;

	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Button^  bOk;

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dgvAttrs = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->gbTarget = (gcnew System::Windows::Forms::GroupBox());
			this->dgvLinkTarget = (gcnew System::Windows::Forms::DataGridView());
			this->gbSource = (gcnew System::Windows::Forms::GroupBox());
			this->dgvLinkSource = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->dgvEquiv = (gcnew System::Windows::Forms::DataGridView());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvAttrs))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->gbTarget->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvLinkTarget))->BeginInit();
			this->gbSource->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvLinkSource))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvEquiv))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->dgvAttrs);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(748, 178);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Реквизиты";
			// 
			// dgvAttrs
			// 
			this->dgvAttrs->BackgroundColor = System::Drawing::Color::GhostWhite;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvAttrs->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvAttrs->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvAttrs->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvAttrs->Location = System::Drawing::Point(26, 19);
			this->dgvAttrs->Name = L"dgvAttrs";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvAttrs->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dgvAttrs->RowHeadersWidth = 25;
			this->dgvAttrs->Size = System::Drawing::Size(696, 150);
			this->dgvAttrs->TabIndex = 0;
			this->dgvAttrs->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AttrCompareForm::dgvAttrs_CellValueChanged);
			this->dgvAttrs->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &AttrCompareForm::dgvAttrs_EditingControlShowing);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->gbTarget);
			this->groupBox2->Controls->Add(this->gbSource);
			this->groupBox2->Location = System::Drawing::Point(12, 187);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(748, 274);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Связанные таблицы";
			// 
			// gbTarget
			// 
			this->gbTarget->Controls->Add(this->dgvLinkTarget);
			this->gbTarget->Enabled = false;
			this->gbTarget->Location = System::Drawing::Point(26, 133);
			this->gbTarget->Name = L"gbTarget";
			this->gbTarget->Size = System::Drawing::Size(696, 135);
			this->gbTarget->TabIndex = 3;
			this->gbTarget->TabStop = false;
			this->gbTarget->Text = L"Получатель";
			// 
			// dgvLinkTarget
			// 
			this->dgvLinkTarget->AllowUserToAddRows = false;
			this->dgvLinkTarget->AllowUserToDeleteRows = false;
			this->dgvLinkTarget->BackgroundColor = System::Drawing::Color::GhostWhite;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvLinkTarget->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dgvLinkTarget->ColumnHeadersHeight = 30;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvLinkTarget->DefaultCellStyle = dataGridViewCellStyle5;
			this->dgvLinkTarget->Location = System::Drawing::Point(20, 19);
			this->dgvLinkTarget->Name = L"dgvLinkTarget";
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvLinkTarget->RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->dgvLinkTarget->RowHeadersWidth = 25;
			this->dgvLinkTarget->Size = System::Drawing::Size(657, 109);
			this->dgvLinkTarget->TabIndex = 1;
			this->dgvLinkTarget->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AttrCompareForm::dgvLinkTarget_CellValueChanged);
			this->dgvLinkTarget->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &AttrCompareForm::dgvLinkTarget_EditingControlShowing);
			// 
			// gbSource
			// 
			this->gbSource->Controls->Add(this->dgvLinkSource);
			this->gbSource->Enabled = false;
			this->gbSource->Location = System::Drawing::Point(26, 13);
			this->gbSource->Name = L"gbSource";
			this->gbSource->Size = System::Drawing::Size(696, 123);
			this->gbSource->TabIndex = 2;
			this->gbSource->TabStop = false;
			this->gbSource->Text = L"Источник";
			// 
			// dgvLinkSource
			// 
			this->dgvLinkSource->AllowUserToAddRows = false;
			this->dgvLinkSource->AllowUserToDeleteRows = false;
			this->dgvLinkSource->BackgroundColor = System::Drawing::Color::GhostWhite;
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle7->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvLinkSource->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle7;
			this->dgvLinkSource->ColumnHeadersHeight = 30;
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle8->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle8->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvLinkSource->DefaultCellStyle = dataGridViewCellStyle8;
			this->dgvLinkSource->Location = System::Drawing::Point(20, 19);
			this->dgvLinkSource->Name = L"dgvLinkSource";
			dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle9->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvLinkSource->RowHeadersDefaultCellStyle = dataGridViewCellStyle9;
			this->dgvLinkSource->RowHeadersWidth = 25;
			this->dgvLinkSource->Size = System::Drawing::Size(657, 104);
			this->dgvLinkSource->TabIndex = 1;
			this->dgvLinkSource->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AttrCompareForm::dgvLinkSource_CellValueChanged);
			this->dgvLinkSource->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &AttrCompareForm::dgvLinkSource_EditingControlShowing);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->dgvEquiv);
			this->groupBox3->Location = System::Drawing::Point(12, 448);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(748, 118);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Эквивалентность записей";
			// 
			// dgvEquiv
			// 
			this->dgvEquiv->BackgroundColor = System::Drawing::Color::GhostWhite;
			dataGridViewCellStyle10->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle10->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle10->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle10->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle10->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle10->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvEquiv->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle10;
			this->dgvEquiv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle11->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle11->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle11->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle11->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle11->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle11->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvEquiv->DefaultCellStyle = dataGridViewCellStyle11;
			this->dgvEquiv->Location = System::Drawing::Point(26, 19);
			this->dgvEquiv->Name = L"dgvEquiv";
			dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle12->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle12->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle12->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle12->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle12->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvEquiv->RowHeadersDefaultCellStyle = dataGridViewCellStyle12;
			this->dgvEquiv->RowHeadersWidth = 25;
			this->dgvEquiv->Size = System::Drawing::Size(696, 93);
			this->dgvEquiv->TabIndex = 1;
			this->dgvEquiv->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &AttrCompareForm::dgvEquiv_EditingControlShowing);
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::GhostWhite;
			this->bCancel->Location = System::Drawing::Point(685, 572);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 3;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &AttrCompareForm::bCancel_Click);
			// 
			// bOk
			// 
			this->bOk->BackColor = System::Drawing::Color::GhostWhite;
			this->bOk->Location = System::Drawing::Point(592, 572);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 4;
			this->bOk->Text = L"ОК";
			this->bOk->UseVisualStyleBackColor = false;
			this->bOk->Click += gcnew System::EventHandler(this, &AttrCompareForm::bOk_Click);
			// 
			// AttrCompareForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::GhostWhite;
			this->ClientSize = System::Drawing::Size(772, 607);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AttrCompareForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление/редактирование связей реквизитов";
			this->Load += gcnew System::EventHandler(this, &AttrCompareForm::AttrCompareForm_Load);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvAttrs))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->gbTarget->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvLinkTarget))->EndInit();
			this->gbSource->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvLinkSource))->EndInit();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvEquiv))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		Void Init()
		{
			_colId = 0;
			SetDgv(dgvAttrs);
			_colId = 0;
			SetDgv(dgvEquiv);
		}

		Void SetDgv(DataGridView^ grid)
		{
			if (_sourceTypeId == 1)
			{
				SetDgvSemColls(grid, true);
			}
			else
			{
				SetDgvDbColls(grid, true, true);
			}

			if (_targetTypeId == 1)
			{
				SetDgvSemColls(grid, false);
			}
			else
			{
				SetDgvDbColls(grid, false, true);
			}
		}

		Void SetDgvSemColls(DataGridView^ grid, bool isSource)
		{
			DataGridViewComboBoxColumn^ col1 = gcnew DataGridViewComboBoxColumn();
			col1->Name = _colId++ + "c";
			col1->HeaderText = "Типа схема"; 
			col1->Visible = false;
			DataGridViewComboBoxColumn^ col2 = gcnew DataGridViewComboBoxColumn();
			col2->Name = _colId++ + "c";
			col2->HeaderText = "Код справочника"; 
			DataGridViewComboBoxColumn^ col3 = gcnew DataGridViewComboBoxColumn();
			col3->Name = _colId++ + "c";
			col3->HeaderText = "Код атрибута";
			DataGridViewComboBoxColumn^ col4 = gcnew DataGridViewComboBoxColumn();
			col4->Name = _colId++ + "c";
			col4->HeaderText = "Типа Schema+Table";
			col4->Visible = false;
			if (isSource)
			{
				col1->HeaderText += " (источник)";
				col2->HeaderText += " (источник)"; 
			}
			else
			{
				col1->HeaderText += " (получатель)";
				col2->HeaderText += " (получатель)"; 
			}
			grid->Columns->Add(col1);
			grid->Columns->Add(col2);
			grid->Columns->Add(col3);
			grid->Columns->Add(col4);
		}

		Void SetDgvDbColls(DataGridView^ grid, bool isSource, bool withRecord)
		{
			DataGridViewComboBoxColumn^ col1 = gcnew DataGridViewComboBoxColumn();
			col1->Name = _colId++ + "c";
			col1->HeaderText = "Схема БД";
			DataGridViewComboBoxColumn^ col2 = gcnew DataGridViewComboBoxColumn();
			col2->Name = _colId++ + "c";
			col2->HeaderText = "Таблица БД";
			DataGridViewComboBoxColumn^ col3 = gcnew DataGridViewComboBoxColumn();
			col3->Name = _colId++ + "c";
			col3->HeaderText = "Поле таблицы";
			DataGridViewComboBoxColumn^ col4 = gcnew DataGridViewComboBoxColumn();
			col4->Name = _colId++ + "c";
			col4->HeaderText = "Schema+Table";
			col4->Visible = false;
			if (isSource)
			{
				col1->HeaderText += " (источник)";
				col2->HeaderText += " (источник)";
				col3->HeaderText += " (источник)"; 
				if (withRecord)
				{
					_sourceSchemaColId = col1->Name;
					_sourceTableColId = col2->Name;
					_sourceSchTblColId = col4->Name;
				}
			}
			else
			{
				col1->HeaderText += " (получатель)";
				col2->HeaderText += " (получатель)"; 
				col3->HeaderText += " (получатель)";
				if (withRecord)
				{
					_targetSchemaColId = col1->Name;
					_targetTableColId = col2->Name;
					_targetSchTblColId = col4->Name;
				}
			}
			grid->Columns->Add(col1);
			grid->Columns->Add(col2);
			grid->Columns->Add(col3);
			grid->Columns->Add(col4);
		}

		Void SetList(List<String^>^ list, DataGridView^ grid, String^ schemaTableCol)
		{
			list->Clear();
			for(int i = 0; i < grid->Rows->Count; i++)
			{
				Object^ cell3 = grid[schemaTableCol, i]->Value;
				if (cell3 != nullptr && cell3->ToString() != "" && !list->Contains(cell3->ToString()))
				{
					list->Add(cell3->ToString());
				}
			}
		}

		Void SetCol4(int rowI, DataGridView^ grid,  String^ schemaCol, String^ tableCol, String^ schemaTableCol)
 		{
			Object^ cell1 = grid[schemaCol, rowI]->Value;
			Object^ cell2 = grid[tableCol, rowI]->Value;
			if (cell1 != nullptr && cell2 != nullptr)
			{
				String^ value = (cell1->ToString() + "." + cell2->ToString())->ToUpper();
				grid[schemaTableCol, rowI]->Value = value;
			}
			else
			{
				grid[schemaTableCol, rowI]->Value = nullptr;
			}
		}

		Void SetLinkTables(List<String^>^ list, DataGridView^ grid, bool isSource)
		{
			if (list->Count > 1)
			{
				if (isSource)
				{
					gbSource->Enabled = true;
				}
				else
				{
					gbTarget->Enabled = true;
				}
				grid->Rows->Clear();
				for each(String^ schTab in list)
				{
					AddRow(grid, schTab);
				}
			}
			else
			{
				grid->Rows->Clear();
				if (isSource)
				{
					gbSource->Enabled = false;
					dgvLinkSource->Enabled = false;
				}
				else
				{
					gbTarget->Enabled = false;
					dgvLinkTarget->Enabled = false;
				}
			}
		}

		Void SetLinkCols(DataGridView^ grid)
		{
			_colId = 0;
			SetDgvDbColls(grid, true, false);
			SetDgvDbColls(grid, true, false);
			grid->Columns[0]->ReadOnly = true;
			grid->Columns[1]->ReadOnly = true;
		}

		Void DeleteLinkRows(DataGridView^ grid, int colId1, int colId2)
		{
			bool toDelete;
			for(int i = 0; i < grid->Rows->Count; i++)
			{
				for(int j = 0; j < grid->Rows->Count; j++)
				{
					Object^ val1 = grid[colId1, i]->Value;
					Object^ val2 = grid[colId2, j]->Value;
					Object^ val3 = grid[colId2, i]->Value;
					if (val1 != nullptr && val2!= nullptr && val1->ToString() == val2->ToString() && (val3 == nullptr ||  val3->ToString() == ""))
					{
						toDelete = true;
						break;
					}
				}
				if (toDelete)
				{
					grid->Rows->RemoveAt(i);
					break;
				}
			}
		}

		Void AddLinkRows(List<String^>^ list, DataGridView^ grid, int colId1, int colId2)
		{
			for each(String^ s in list)
			{
				bool toAdd = true;
				int n = grid->Rows->Count;
				for(int i = 0; i < grid->Rows->Count; i++)
				{
					Object^ cell1 = grid[colId1, i]->Value;
					Object^ cell2 = grid[colId2, i]->Value;
					if (cell1 != nullptr && cell1->ToString() != "" && s == cell1->ToString())
					{
						toAdd = false;
						break;
					}
					if (cell2 != nullptr && cell2->ToString() != "" && s == cell2->ToString())
					{
						toAdd = false;
						break;
					}
				}
				if (toAdd)
				{
					AddRow(grid, s);
				}
			}
		}

		Void AddRow(DataGridView^ grid, String^ schTab)
		{
			array<String^>^ row = gcnew array<String ^>(8);
			array<String^>^ split = schTab->Split('.');
			row[0] = split[0];
			row[1] = split[1];
			row[3] = schTab;
			grid->Rows->Add(row);
		}

		Void SetOutLists(List<array<String^>^>^ list, DataGridView^ grid)
		{
			int n = grid->Rows->Count;
			for(int i = 0; i < grid->Rows->Count; i++)
			{
				array<String ^>^ arr = gcnew array<String ^>(6);
				if (grid[0, i]->Value != nullptr)
				{
					arr[0] = grid[0, i]->Value->ToString();
				}
				if (grid[1, i]->Value != nullptr)
				{
					arr[1] = grid[1, i]->Value->ToString();
				}
				if (grid[2, i]->Value != nullptr)
				{
					arr[2] = grid[2, i]->Value->ToString();
				}
				if (grid[4, i]->Value != nullptr)
				{
					arr[3] = grid[4, i]->Value->ToString();
				}
				if (grid[5, i]->Value != nullptr)
				{
					arr[4] = grid[5, i]->Value->ToString();
				}
				if (grid[6, i]->Value != nullptr)
				{
					arr[5] = grid[6, i]->Value->ToString();
				}
				bool isNull = true;
				for (int j = 0; j < arr->Length; j++)
				{
					if (arr[j] != nullptr)
					{
						isNull = false;
						break;
					}
				}
				if (!isNull)
				{
					list->Add(arr);
				}
			}
		}

		void Control_KeyPress(Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			//// Ё или ё или все остальные
			//if (e->KeyChar == 1025 ||
			//	e->KeyChar == 1105 ||
			//	e->KeyChar > 1039 && e->KeyChar < 1104)
			//{
			//	e->Handled = true;
			//}
			// Ё или ё
			if (e->KeyChar == 1025 || e->KeyChar == 1105)
			{
				e->Handled = true;
			}
			// русские
			else if (e->KeyChar > 1039 && e->KeyChar < 1104)
			{
				e->KeyChar = StringFunctions::GetEngString(e->KeyChar);
			}
			// английские малые
			else if (e->KeyChar > 96 && e->KeyChar < 123)
			{
				e->KeyChar = e->KeyChar - 32;
			}

		}

private: System::Void AttrCompareForm_Load(System::Object^  sender, System::EventArgs^  e) 
			{
				Init();
			}

private: System::Void dgvAttrs_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 /*SetCol4(e->RowIndex, dgvAttrs, _sourceSchemaColId, _sourceTableColId, _sourceSchTblColId);
			 SetList(_sourceFields, dgvAttrs, _sourceSchTblColId);
			 SetCol4(e->RowIndex, dgvAttrs, _targetSchemaColId, _targetTableColId, _targetSchTblColId);
			 SetList(_targetFields, dgvAttrs, _targetSchTblColId);*/

			 SetCol4(e->RowIndex, dgvAttrs, "0c", "1c", "3c");
			 SetList(_sourceFields, dgvAttrs, "3c");
			 SetCol4(e->RowIndex, dgvAttrs, "4c", "5c", "7c");
			 SetList(_targetFields, dgvAttrs, "7c");

			 if (!_sourceLinkHasCols && _sourceFields->Count > 1)
			 {
				 SetLinkCols(dgvLinkSource);
				 _sourceLinkHasCols = true;
			 }

			 if (!_targetLinkHasCols && _targetFields->Count > 1)
			 {
				 SetLinkCols(dgvLinkTarget);
				 _targetLinkHasCols = true;
			 }

			 SetLinkTables(_sourceFields, dgvLinkSource, true);
			 SetLinkTables(_targetFields, dgvLinkTarget, false);
		 }
private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }

private: System::Void dgvAttrs_EditingControlShowing(System::Object^  sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^  e) 
		 {
			 e->Control->KeyPress -= gcnew KeyPressEventHandler(this, &Integra::AttrCompareForm::Control_KeyPress);
			 e->Control->KeyPress += gcnew KeyPressEventHandler(this, &Integra::AttrCompareForm::Control_KeyPress);
		 }
private: System::Void dgvLinkSource_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 SetCol4(e->RowIndex, dgvLinkSource, "4c", "5c", "7c");
			 DeleteLinkRows(dgvLinkSource, 3, 7);
			 AddLinkRows(_sourceFields, dgvLinkSource, 3, 7);
		 }
private: System::Void dgvLinkSource_EditingControlShowing(System::Object^  sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^  e) 
		 {
			 e->Control->KeyPress -= gcnew KeyPressEventHandler(this, &Integra::AttrCompareForm::Control_KeyPress);
			 e->Control->KeyPress += gcnew KeyPressEventHandler(this, &Integra::AttrCompareForm::Control_KeyPress);
		 }
private: System::Void dgvLinkTarget_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 SetCol4(e->RowIndex, dgvLinkTarget, "4c", "5c", "7c");
			 DeleteLinkRows(dgvLinkTarget, 3, 7);
			 AddLinkRows(_targetFields, dgvLinkTarget, 3, 7);
		 }
private: System::Void dgvLinkTarget_EditingControlShowing(System::Object^  sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^  e) 
		 {
			 e->Control->KeyPress -= gcnew KeyPressEventHandler(this, &Integra::AttrCompareForm::Control_KeyPress);
			 e->Control->KeyPress += gcnew KeyPressEventHandler(this, &Integra::AttrCompareForm::Control_KeyPress);
		 }
private: System::Void dgvEquiv_EditingControlShowing(System::Object^  sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^  e) 
		 {
			 e->Control->KeyPress -= gcnew KeyPressEventHandler(this, &Integra::AttrCompareForm::Control_KeyPress);
			 e->Control->KeyPress += gcnew KeyPressEventHandler(this, &Integra::AttrCompareForm::Control_KeyPress);
		 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetOutLists(_attrs, dgvAttrs);
			 SetOutLists(_sourceLinks, dgvLinkSource);
			 SetOutLists(_targetLinks, dgvLinkTarget);
			 SetOutLists(_equivs, dgvEquiv);
			 this->Close();
		 }
};
}
