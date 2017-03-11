#pragma once

#include "Position.h"
#include "IntegrationGroupPair.h"
#include "IntegrationSettings.h"
#include "Book.h"
#include "DbBook.h"
#include "SearchForm.h"


namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Сводка для RoughInterg
	/// </summary>
	public ref class RoughInterg : public System::Windows::Forms::Form
	{
	public:
		bool IsSkip;
		bool NotFound;
		bool IsSelect;

		Position^ Spos;
		Position^ SelectPosition;
		
		private:
			OdbcClass^ _odbc;
			IntegrationGroupPair^ _integrationGroup;
			IntegrationSettings^ _settings;

			
			List<Position^>^ _tPoses;

			BookSettings^ _sourceBook;
			BookSettings^ _targetBook;

			bool _isGroup;

			Dictionary<String^, String^>^ _sourceGroupingFullAttrs;
			Dictionary<String^, String^>^ _targetGroupingFullAttrs;
			List<Position^>^ _allTposes;

	public:
		RoughInterg(OdbcClass^ odbc, IntegrationGroupPair^ integrationGroup, IntegrationSettings^ settings, Position^ sPos, List<Position^>^ tPoses, bool isGroup, List<Position^>^ allTposes)
		{
			InitializeComponent();
			_odbc = odbc;
			_integrationGroup = integrationGroup;
			_settings = settings;
			_allTposes = allTposes;
			
			Spos = sPos;
			_tPoses = tPoses;
			_sourceBook = _settings->SourceBook;
			_targetBook = _settings->TargetBook;

			_isGroup = isGroup;

			IsSelect = false;
			IsSkip = false;
			NotFound = false;
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~RoughInterg()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dgvSource;
	private: System::Windows::Forms::Button^  bSkip;
	private: System::Windows::Forms::Button^  bNotFound;
	private: System::Windows::Forms::Button^  bSelect;
	private: System::Windows::Forms::Button^  bSearch;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::DataGridView^  dgvTarget;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Label^  label1;


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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dgvSource = (gcnew System::Windows::Forms::DataGridView());
			this->bSkip = (gcnew System::Windows::Forms::Button());
			this->bNotFound = (gcnew System::Windows::Forms::Button());
			this->bSelect = (gcnew System::Windows::Forms::Button());
			this->bSearch = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->dgvTarget = (gcnew System::Windows::Forms::DataGridView());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSource))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTarget))->BeginInit();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(30, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(233, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Искомая позиция в справочнике-источнике:";
			// 
			// dgvSource
			// 
			this->dgvSource->AllowUserToAddRows = false;
			this->dgvSource->AllowUserToDeleteRows = false;
			this->dgvSource->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSource->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvSource->Location = System::Drawing::Point(20, 10);
			this->dgvSource->Name = L"dgvSource";
			this->dgvSource->ReadOnly = true;
			this->dgvSource->Size = System::Drawing::Size(674, 85);
			this->dgvSource->TabIndex = 3;
			// 
			// bSkip
			// 
			this->bSkip->Location = System::Drawing::Point(177, 12);
			this->bSkip->Name = L"bSkip";
			this->bSkip->Size = System::Drawing::Size(75, 23);
			this->bSkip->TabIndex = 4;
			this->bSkip->Text = L"Пропустить";
			this->bSkip->UseVisualStyleBackColor = true;
			this->bSkip->Click += gcnew System::EventHandler(this, &RoughInterg::bSkip_Click);
			// 
			// bNotFound
			// 
			this->bNotFound->Location = System::Drawing::Point(96, 12);
			this->bNotFound->Name = L"bNotFound";
			this->bNotFound->Size = System::Drawing::Size(75, 23);
			this->bNotFound->TabIndex = 5;
			this->bNotFound->Text = L"Не найдено";
			this->bNotFound->UseVisualStyleBackColor = true;
			this->bNotFound->Click += gcnew System::EventHandler(this, &RoughInterg::bNotFound_Click);
			// 
			// bSelect
			// 
			this->bSelect->Location = System::Drawing::Point(15, 12);
			this->bSelect->Name = L"bSelect";
			this->bSelect->Size = System::Drawing::Size(75, 23);
			this->bSelect->TabIndex = 6;
			this->bSelect->Text = L"Выбрать";
			this->bSelect->UseVisualStyleBackColor = true;
			this->bSelect->Click += gcnew System::EventHandler(this, &RoughInterg::bSelect_Click);
			// 
			// bSearch
			// 
			this->bSearch->Location = System::Drawing::Point(33, 12);
			this->bSearch->Name = L"bSearch";
			this->bSearch->Size = System::Drawing::Size(75, 23);
			this->bSearch->TabIndex = 7;
			this->bSearch->Text = L"Найти";
			this->bSearch->UseVisualStyleBackColor = true;
			this->bSearch->Click += gcnew System::EventHandler(this, &RoughInterg::bSearch_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel8);
			this->panel1->Controls->Add(this->panel7);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(714, 129);
			this->panel1->TabIndex = 8;
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->dgvSource);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(0, 24);
			this->panel8->Name = L"panel8";
			this->panel8->Padding = System::Windows::Forms::Padding(20, 10, 20, 10);
			this->panel8->Size = System::Drawing::Size(714, 105);
			this->panel8->TabIndex = 5;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->label2);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel7->Location = System::Drawing::Point(0, 0);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(714, 24);
			this->panel7->TabIndex = 4;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->bSearch);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 287);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(714, 50);
			this->panel2->TabIndex = 9;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->bSkip);
			this->panel3->Controls->Add(this->bNotFound);
			this->panel3->Controls->Add(this->bSelect);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel3->Location = System::Drawing::Point(439, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(275, 50);
			this->panel3->TabIndex = 8;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->panel6);
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(0, 129);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(714, 158);
			this->panel4->TabIndex = 10;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->dgvTarget);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->Location = System::Drawing::Point(0, 17);
			this->panel6->Name = L"panel6";
			this->panel6->Padding = System::Windows::Forms::Padding(20, 10, 20, 10);
			this->panel6->Size = System::Drawing::Size(714, 141);
			this->panel6->TabIndex = 1;
			// 
			// dgvTarget
			// 
			this->dgvTarget->AllowUserToAddRows = false;
			this->dgvTarget->AllowUserToDeleteRows = false;
			this->dgvTarget->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTarget->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvTarget->Location = System::Drawing::Point(20, 10);
			this->dgvTarget->Name = L"dgvTarget";
			this->dgvTarget->ReadOnly = true;
			this->dgvTarget->Size = System::Drawing::Size(674, 121);
			this->dgvTarget->TabIndex = 0;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->label1);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(714, 17);
			this->panel5->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 1);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(250, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Найденные позиции в справочнике-получателе:";
			// 
			// RoughInterg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 337);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->MinimumSize = System::Drawing::Size(411, 291);
			this->Name = L"RoughInterg";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Режим \"грубой\" интеграции";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &RoughInterg::RoughInterg_FormClosed);
			this->Load += gcnew System::EventHandler(this, &RoughInterg::RoughInterg_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSource))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTarget))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		void SetColumns(DataGridView^  dgv, Dictionary<Attribute^, String^>^ attrsAndValues, Attribute^ attrId, Attribute^ attrName, Dictionary<String^, String^>^ groupingAttrs)
		{
			dgv->ColumnCount = attrsAndValues->Count + groupingAttrs->Count;
			dgv->ColumnHeadersVisible = true;

			dgv->Columns[0]->Name = attrId->FullCode;
			dgv->Columns[0]->HeaderText = String::Format("{0}({1})", attrId->Name, attrId->Code);
			dgv->Columns[1]->Name = attrName->FullCode;
			dgv->Columns[1]->HeaderText = String::Format("{0}({1})", attrName->Name, attrName->Code);

			int i = 2;
			for each (KeyValuePair<String^, String^>^ pair in groupingAttrs)
			{
				dgv->Columns[i]->Name = pair->Value;
				dgv->Columns[i]->HeaderText = pair->Key;
				i++;
			}

			for each (KeyValuePair<Attribute^, String^>^ pair in attrsAndValues)
			{
				Attribute^ attr = pair->Key;
				String^ val = pair->Value;
				if (attr == attrId || attr == attrName)
				{
					continue;
				}
				else
				{
					dgv->Columns[i]->Name = attr->FullCode;
					dgv->Columns[i]->HeaderText = String::Format("{0}({1})", attr->Name, attr->Code);
					i++;
				}
			}
		}

		void SetRow(DataGridView^  dgv, Position^ pos, Attribute^ attrName, Dictionary<String^, String^>^ posingAttrs)
		{
			array<Object^>^ row = gcnew array<Object ^>(pos->AttributesAndValues->Count);
			row[0] = pos->AttributesAndValues[pos->AttrId];
			row[1] = pos->AttributesAndValues[attrName];
			int i = 2;

			for (int i = 2; i < dgv->ColumnCount; i++)
			{
				bool posingIsSet = false;
				for each (KeyValuePair<String^, String^>^ pair in posingAttrs)
				{
					if (dgv->Columns[i]->Name == pair->Key)
					{
						row[i] = pair->Value;
						posingAttrs->Remove(pair->Key);
						posingIsSet = true;
						break;
					}
				}
				if (posingIsSet)
					continue;

				for each (KeyValuePair<Attribute^, String^>^ pair in pos->AttributesAndValues)
				{
					Attribute^ attr = pair->Key;
					
					if (dgv->Columns[i]->Name == attr->FullCode)
					{
						row[i] = pair->Value;
						break;
					}
				}
			}
			dgv->Rows->Add(row);

		}

		bool HasPos(Position^ pos)
		{
			for (int i = 0; i < dgvTarget->RowCount; i++)
			{
				String^ id = dgvTarget[0, i]->Value->ToString();
				if (id == pos->UnicId)
				{
					return true;
				}
			}
			return false;
		}

		List<DataGridViewColumn^>^ GetColumns()
		{
			List<DataGridViewColumn^>^ cols = gcnew List<DataGridViewColumn ^>();
			for each (DataGridViewColumn^ col in dgvTarget->Columns)
			{
				DataGridViewColumn^ col1 = gcnew DataGridViewColumn();
				col1->Name = col->Name;
				col1->HeaderText = col->HeaderText;
				cols->Add(col1);
			}
			return cols;
		}

		Dictionary<String^, String^>^ GetSourceGroupingAtrrs(IntegrationGroupPair^ grPair, Position^ sPos)
		{
			grPair->SourceGroupingAttrs = gcnew List<Attribute ^>();
			if (_sourceGroupingFullAttrs == nullptr || _sourceGroupingFullAttrs->Count <= 0)
			{
				_sourceGroupingFullAttrs = GetGroupingAtrrs(_sourceBook, grPair->SourceGroupId, grPair->SourceGroupingAttrs, sPos);
			}
			return _sourceGroupingFullAttrs;
		}

		Dictionary<String^, String^>^ GetTargetGroupingAtrrs(IntegrationGroupPair^ grPair, Position^ tPos)
		{
			grPair->TargetGroupingAttrs = gcnew List<Attribute ^>();
			if (_targetGroupingFullAttrs == nullptr || _targetGroupingFullAttrs->Count <= 0)
			{
				_targetGroupingFullAttrs = GetGroupingAtrrs(_targetBook, grPair->TargetGroupId, grPair->TargetGroupingAttrs, tPos);
			}
			return _targetGroupingFullAttrs;
		}

		Dictionary<String^, String^>^ GetGroupingAtrrs(BookSettings^ bookSettings, String^ groupId, List<Attribute^>^ groupingAttrs, Position^ pos)
		{
			Dictionary<String^, String^>^ resDict = gcnew Dictionary<String ^, String ^>();

			Dictionary<Attribute^, Attribute^>^ grAttrs = bookSettings->GetGroupAttrs();
			Book^ book = gcnew DbBook(bookSettings, nullptr, true, _odbc);
			for each (KeyValuePair<Attribute^, Attribute^>^ pair in grAttrs)
			{
				Attribute^ nameAttr = pair->Value;
				String^ valueName = book->GetGroupAttrValue(nameAttr, groupId)->ToString();
				Attribute^ codeAttr = pair->Key;
				String^ valueCode = book->GetGroupAttrValue(codeAttr, groupId)->ToString();

				GroupingAttr^ groupingAttr = gcnew GroupingAttr(codeAttr, nameAttr, valueCode, valueName);
				pos->AddGroupingAttr(groupingAttr);

				if (!String::IsNullOrEmpty(valueName))
				{
					resDict->Add(valueName, valueCode);
					codeAttr->GroupAttrCodeValue = valueCode;
					codeAttr->GroupAttrNameValue = valueName;
					groupingAttrs->Add(codeAttr);
				}
			}
			return resDict;
		}

		Dictionary<String^, String^>^ GetSourcePosingAtrrs()
		{
			Dictionary<String^, String^>^ sourcePosingAttrs;
			if (_sourceGroupingFullAttrs != nullptr && _sourceGroupingFullAttrs->Count > 0)
			{
				sourcePosingAttrs = GetPosingAtrrs(_sourceBook, Spos);
			}
			return sourcePosingAttrs;
		}

		Dictionary<String^, String^>^ GetTargetPosingAtrrs(Position^ pos)
		{
			Dictionary<String^, String^>^ targetPosingAttrs;
			if (_targetGroupingFullAttrs != nullptr && _targetGroupingFullAttrs->Count > 0)
			{
				targetPosingAttrs = GetPosingAtrrs(_targetBook, pos);
			}
			return targetPosingAttrs;
		}

		Dictionary<String^, String^>^ GetPosingAtrrs(BookSettings^ bookSettings, Position^ pos)
		{
			Dictionary<String^, String^>^ resDict = gcnew Dictionary<String ^, String ^>();

			Dictionary<Attribute^, Attribute^>^ posAttrs = bookSettings->GetPosGroupAttrs();
			Book^ book = gcnew DbBook(bookSettings, nullptr, true, _odbc);
			for each (KeyValuePair<Attribute^, Attribute^>^ pair in posAttrs)
			{
				Attribute^ nameAttr = pair->Value;
				String^ valueName = book->GetPosAttrValue(nameAttr, pos->UnicId)->ToString();
				Attribute^ codeAttr = pair->Key;
				String^ valueCode = book->GetPosAttrValue(codeAttr, pos->UnicId)->ToString();

				pos->AddValueToGroupingAttr(codeAttr, nameAttr, valueCode, valueName);

				if (!String::IsNullOrEmpty(valueName))
				{
					resDict->Add(valueCode, valueName);
				}
			}
			return resDict;
		}

	private: System::Void RoughInterg_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Dictionary<Attribute^, String^>^ sourceAttrAndVals;
				 Dictionary<Attribute^, String^>^ targetAttrAndVals;

				 if (_isGroup)
				 {
					 sourceAttrAndVals = Spos->GetRemakingAttrsAndVals(_odbc);
					 targetAttrAndVals = _tPoses[0]->GetRemakingAttrsAndVals(_odbc);
				 }
				 else
				 {
					 sourceAttrAndVals = Spos->AttributesAndValues;
					 targetAttrAndVals = _tPoses[0]->AttributesAndValues;
				 }

				 SetColumns(dgvSource, sourceAttrAndVals, Spos->AttrId, _sourceBook->AttrCaption, GetSourceGroupingAtrrs(_integrationGroup, Spos));
				 if (_tPoses != nullptr && _tPoses->Count > 0)
				 {
					 SetColumns(dgvTarget, targetAttrAndVals, _tPoses[0]->AttrId, _targetBook->AttrCaption, GetTargetGroupingAtrrs(_integrationGroup, _tPoses[0]));
				 }

				 for (int i = 1; i < _tPoses->Count; i++)
				 {
					 _tPoses[i]->SetGroupingAttrs(_tPoses[0]->GetGroupAttrsCopy());
				 }
				 
				 SetRow(dgvSource, Spos, _sourceBook->AttrCaption, GetSourcePosingAtrrs());
				 for each (Position^ tPos in _tPoses)
				 {
					 SetRow(dgvTarget, tPos, _targetBook->AttrCaption, GetTargetPosingAtrrs(tPos));
				 }
			 }

private: System::Void bSearch_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SearchForm^ form = gcnew SearchForm(_odbc, _allTposes, GetColumns(), _targetBook);
			 form->ShowDialog();
			 if (form->IsOk)
			 {
				 Position^ newPos = form->selectPos;
				 if (!HasPos(newPos))
				 {
					 SetRow(dgvTarget, newPos, _targetBook->AttrCaption, GetTargetPosingAtrrs(newPos));
				 }
			 }
		 }

private: System::Void bSkip_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 IsSkip = true;
			 NotFound = false;
			 IsSelect = false;
			 Close();
		 }

private: System::Void bNotFound_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 IsSkip = false;
			 NotFound = true;
			 IsSelect = false;
			 Close();
		 }

private: System::Void bSelect_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dgvTarget->SelectedCells == nullptr || dgvTarget->SelectedCells->Count <= 0 || dgvTarget->SelectedCells[0] == nullptr)
			 {
				 MessageBox::Show("Выберите позицию!");
				 return;
			 }

			 int iRow = dgvTarget->SelectedCells[0]->RowIndex;

			 String^ unicPosId = dgvTarget[0, iRow]->Value->ToString();
			 for each (Position^ pos in _tPoses)
			 {
				 if (pos->UnicId == unicPosId)
				 {
					 SelectPosition = pos;
					 break;
				 }
			 }

			 IsSkip = false;
			 NotFound = false;
			 IsSelect = true;
			 Close();
		 }

private: System::Void RoughInterg_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
		 {
			 if (!NotFound && !IsSelect)
			 {
				 IsSkip = true;
				 NotFound = false;
				 IsSelect = false;
			 }
			 Close();
		 }
};
}
