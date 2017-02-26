#include "AddEditGroupForm.h"
#include "BookSettings.h"
#include "AddComplexAttrForm.h"
#include "ComplexAttribute.h"
#include "ODBCclass.h"
#include "IntegrationGroupPair.h"


namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddGroupLinksForm
	/// </summary>
	public ref class AddGroupLinksForm : public System::Windows::Forms::Form
	{
	public:
		Dictionary<Attribute^,Attribute^>^ AttrPairs;
		List<ComplexAttribute^>^ ComplexAttrs;

	private:
		OdbcClass^ _odbc;
		// 0 - oneWay, 1 - twoWay
		int _typeDir;

		BookSettings^ _sourceBook;
		BookSettings^ _targetBook;
		List<Attribute^>^ _sourceAttrs;
		List<Attribute^>^ _targetAttrs;
		List<Attribute^>^ _sourceAttrsFree;
		List<Attribute^>^ _targetAttrsFree;

		

		List<IntegrationGroupPair^>^ _integrationGroups;
		Object^ _prevSelectGroupItem;

		Dictionary<String^, String^>^ _currentSourceList;
		Dictionary<String^, String^>^ _currentTargetList;


		bool _sAttrIsSet, _tAttrIsSet;

	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  pListBox;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Button^  bDelComplexAttr;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  ColumnSourceNamee;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnSourceCode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  ColumnTargetNamee;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnTargetCode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::Button^  bAddComplexAttr;


	public:
		AddGroupLinksForm(Dictionary<Attribute^,Attribute^>^ attrPairs, List<ComplexAttribute^>^ complexAttrs, BookSettings^ sourceBook, BookSettings^ targetBook, int type, OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
			_typeDir = type;

			ComplexAttrs = gcnew List<ComplexAttribute ^>();
			_sourceBook = sourceBook;
			_targetBook = targetBook;
			if (_sourceBook->HasGroup && _targetBook->HasGroup)
			{
				_integrationGroups = gcnew List<IntegrationGroupPair ^>();
			}
			else
			{
				pGroup->Visible = false;
				SetDgvSources();
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddGroupLinksForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  lbGroups;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  bAddGroup;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::DataGridView^  dgv;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Button^  bOk;
	private: System::Windows::Forms::Panel^  pGroup;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  pDgv;

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
			this->lbGroups = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bAddGroup = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dgv = (gcnew System::Windows::Forms::DataGridView());
			this->ColumnSourceNamee = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->ColumnSourceCode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnTargetNamee = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->ColumnTargetCode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->pGroup = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pListBox = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->bDelComplexAttr = (gcnew System::Windows::Forms::Button());
			this->bAddComplexAttr = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pDgv = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgv))->BeginInit();
			this->pGroup->SuspendLayout();
			this->panel4->SuspendLayout();
			this->pListBox->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel1->SuspendLayout();
			this->pDgv->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbGroups
			// 
			this->lbGroups->BackColor = System::Drawing::SystemColors::Window;
			this->lbGroups->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lbGroups->FormattingEnabled = true;
			this->lbGroups->Location = System::Drawing::Point(10, 10);
			this->lbGroups->Name = L"lbGroups";
			this->lbGroups->Size = System::Drawing::Size(863, 166);
			this->lbGroups->TabIndex = 0;
			this->lbGroups->SelectedIndexChanged += gcnew System::EventHandler(this, &AddGroupLinksForm::lbGroups_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Padding = System::Windows::Forms::Padding(20, 10, 10, 0);
			this->label1->Size = System::Drawing::Size(77, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Группы:";
			// 
			// bAddGroup
			// 
			this->bAddGroup->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddGroup->Location = System::Drawing::Point(15, 39);
			this->bAddGroup->Name = L"bAddGroup";
			this->bAddGroup->Size = System::Drawing::Size(75, 23);
			this->bAddGroup->TabIndex = 2;
			this->bAddGroup->Text = L"Добавить группу";
			this->bAddGroup->UseVisualStyleBackColor = false;
			this->bAddGroup->Click += gcnew System::EventHandler(this, &AddGroupLinksForm::bAddGroup_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button2->Location = System::Drawing::Point(15, 68);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Изменить";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Visible = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button3->Location = System::Drawing::Point(15, 97);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Удалить";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Visible = false;
			// 
			// dgv
			// 
			this->dgv->AllowUserToDeleteRows = false;
			this->dgv->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgv->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->ColumnSourceNamee, 
				this->ColumnSourceCode, this->Column5, this->Column7, this->ColumnTargetNamee, this->ColumnTargetCode, this->Column6, this->Column8});
			this->dgv->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgv->Location = System::Drawing::Point(13, 13);
			this->dgv->Name = L"dgv";
			this->dgv->RowHeadersVisible = false;
			this->dgv->Size = System::Drawing::Size(964, 234);
			this->dgv->TabIndex = 5;
			this->dgv->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &AddGroupLinksForm::dgv_CellBeginEdit);
			this->dgv->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AddGroupLinksForm::dgv_CellValueChanged);
			this->dgv->CurrentCellDirtyStateChanged += gcnew System::EventHandler(this, &AddGroupLinksForm::dgv_CurrentCellDirtyStateChanged);
			// 
			// ColumnSourceNamee
			// 
			this->ColumnSourceNamee->HeaderText = L"Наименование реквизита системы-источника";
			this->ColumnSourceNamee->Name = L"ColumnSourceNamee";
			// 
			// ColumnSourceCode
			// 
			this->ColumnSourceCode->HeaderText = L"Обозначение реквизита системы-источника";
			this->ColumnSourceCode->Name = L"ColumnSourceCode";
			this->ColumnSourceCode->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Тип данных";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Размер";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			// 
			// ColumnTargetNamee
			// 
			this->ColumnTargetNamee->HeaderText = L"Наименование реквизита системы-получателя";
			this->ColumnTargetNamee->Name = L"ColumnTargetNamee";
			// 
			// ColumnTargetCode
			// 
			this->ColumnTargetCode->HeaderText = L"Обозначение реквизита системы-получателя";
			this->ColumnTargetCode->Name = L"ColumnTargetCode";
			this->ColumnTargetCode->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Тип данных";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Размер";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(108, 16);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 6;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &AddGroupLinksForm::bCancel_Click);
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(17, 16);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 7;
			this->bOk->Text = L"Сохранить";
			this->bOk->UseVisualStyleBackColor = true;
			this->bOk->Click += gcnew System::EventHandler(this, &AddGroupLinksForm::bOk_Click);
			// 
			// pGroup
			// 
			this->pGroup->Controls->Add(this->panel4);
			this->pGroup->Controls->Add(this->panel3);
			this->pGroup->Dock = System::Windows::Forms::DockStyle::Top;
			this->pGroup->Location = System::Drawing::Point(0, 0);
			this->pGroup->Name = L"pGroup";
			this->pGroup->Size = System::Drawing::Size(990, 209);
			this->pGroup->TabIndex = 8;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->pListBox);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(883, 209);
			this->panel4->TabIndex = 6;
			// 
			// pListBox
			// 
			this->pListBox->Controls->Add(this->lbGroups);
			this->pListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pListBox->Location = System::Drawing::Point(0, 23);
			this->pListBox->Name = L"pListBox";
			this->pListBox->Padding = System::Windows::Forms::Padding(10);
			this->pListBox->Size = System::Drawing::Size(883, 186);
			this->pListBox->TabIndex = 3;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->bAddGroup);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Controls->Add(this->button2);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel3->Location = System::Drawing::Point(883, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(107, 209);
			this->panel3->TabIndex = 5;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->bDelComplexAttr);
			this->panel2->Controls->Add(this->bAddComplexAttr);
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 469);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(990, 51);
			this->panel2->TabIndex = 9;
			// 
			// bDelComplexAttr
			// 
			this->bDelComplexAttr->Location = System::Drawing::Point(256, 16);
			this->bDelComplexAttr->Name = L"bDelComplexAttr";
			this->bDelComplexAttr->Size = System::Drawing::Size(217, 23);
			this->bDelComplexAttr->TabIndex = 10;
			this->bDelComplexAttr->Text = L"Удалить комплексный реквизит";
			this->bDelComplexAttr->UseVisualStyleBackColor = true;
			this->bDelComplexAttr->Click += gcnew System::EventHandler(this, &AddGroupLinksForm::bDelComplexAttr_Click);
			// 
			// bAddComplexAttr
			// 
			this->bAddComplexAttr->Location = System::Drawing::Point(22, 16);
			this->bAddComplexAttr->Name = L"bAddComplexAttr";
			this->bAddComplexAttr->Size = System::Drawing::Size(217, 23);
			this->bAddComplexAttr->TabIndex = 9;
			this->bAddComplexAttr->Text = L"Добавить комплексный реквизит";
			this->bAddComplexAttr->UseVisualStyleBackColor = true;
			this->bAddComplexAttr->Click += gcnew System::EventHandler(this, &AddGroupLinksForm::bAddComplexAttr_Click);
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->bCancel);
			this->panel5->Controls->Add(this->bOk);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel5->Location = System::Drawing::Point(790, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(200, 51);
			this->panel5->TabIndex = 8;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pDgv);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 209);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(990, 260);
			this->panel1->TabIndex = 10;
			// 
			// pDgv
			// 
			this->pDgv->Controls->Add(this->dgv);
			this->pDgv->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pDgv->Location = System::Drawing::Point(0, 0);
			this->pDgv->Name = L"pDgv";
			this->pDgv->Padding = System::Windows::Forms::Padding(13);
			this->pDgv->Size = System::Drawing::Size(990, 260);
			this->pDgv->TabIndex = 6;
			// 
			// AddGroupLinksForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(990, 520);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->pGroup);
			this->MinimumSize = System::Drawing::Size(16, 535);
			this->Name = L"AddGroupLinksForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление связей";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgv))->EndInit();
			this->pGroup->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->pListBox->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->pDgv->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		void SetDgvSources()
		{
			_sourceAttrs = _sourceBook->GetUseAttrs();
			_targetAttrs = _targetBook->GetUseAttrs();
			_sourceAttrsFree = gcnew List<Attribute ^>();
			_sourceAttrsFree->AddRange(_sourceAttrs);
			_targetAttrsFree = gcnew List<Attribute ^>();
			_targetAttrsFree->AddRange(_targetAttrs);

			//SetColumnCode(ColumnSourceCode,  _sourceAttrsFree);
			//SetColumnCode(ColumnTargetCode,  _targetAttrsFree);
		}

		void SetColumnCode(DataGridViewComboBoxColumn^ column, List<Attribute^>^ list)
		{
			column->Items->Clear();
			for each (Attribute^ attr in list)
			{
				if (String::IsNullOrEmpty(attr->Name))
				{
					column->Items->Add(attr->FullCode);
				}
				else
				{
					column->Items->Add(attr->Name);
				}
			}
			column->Items->Add("<-- Добавить комплексный атрибут -->");
		}

		void RemoveFromList(List<Attribute^>^ list, String^ code)
		{
			for each (Attribute^ attr in list)
			{
				if (String::IsNullOrEmpty(attr->Name))
				{
					if (attr->FullCode == code)
					{
						list->Remove(attr);
						return;
					}
				}
				else
				{
					if (attr->Name == code)
					{
						list->Remove(attr);
						return;
					}
				}
				
			}
		}

		void RemoveOnColumn(int iCol, List<Attribute^>^ list)
		{
			for (int i = 0; i < dgv->RowCount; i++)
			{
				Object^ cell = dgv[iCol, i]->Value;
				if (cell == nullptr || String::IsNullOrEmpty(cell->ToString()))
				{
					continue;
				}
				RemoveFromList(list, cell->ToString());
			}
		}

		Attribute^ GetAttr(List<Attribute^>^ list, String^ name)
		{
			for each (Attribute^ attr in list)
			{
				if (String::IsNullOrEmpty(attr->Name))
				{
					if (attr->FullCode == name)
					{
						return attr;
					}
				}
				else
				{
					if (attr->Name == name)
					{
						return attr;
					}
				}

				if (attr->Name == name)
				{
					return attr;
				}
			}
			return nullptr;
		}

		bool ContainsInComplex(String^ name)
		{
			for each (ComplexAttribute^ attr in ComplexAttrs)
			{
				if (attr->Name == name)
				{
					return true;
				}
			}
			return false;
		}

		bool IntegrationGroupsContains(String^ groupFullname)
		{
			for each (IntegrationGroupPair^ integrationGroup in _integrationGroups)
			{
				if (integrationGroup->FullName == groupFullname)
				{
					return true;
				}
			}
			return false;
		}

		void SetDgvGroupParamSources(IntegrationGroupPair^ integrationGroup)
		{
			Dictionary<Attribute^, Attribute^>^ sourceAttrs = _sourceBook->GetGroupAttrs();
			Book^ sourceBook = gcnew DbBook(_sourceBook, nullptr, true, _odbc);
			Dictionary<String^, String^>^ sourceList = gcnew Dictionary<String^, String^>();
			for each (KeyValuePair<Attribute^, Attribute^>^ pair in sourceAttrs)
			{
				Attribute^ nameAttr = pair->Value;
				String^ valueName = sourceBook->GetGroupAttrValue(nameAttr, integrationGroup->SourceGroupId)->ToString();
				Attribute^ codeAttr = pair->Key;
				String^ valueCode = sourceBook->GetGroupAttrValue(codeAttr, integrationGroup->SourceGroupId)->ToString();
				sourceList->Add(valueName, valueCode);
			}
			_currentSourceList = sourceList;
			List<String^>^ list1 = gcnew List<String ^>(_currentSourceList->Keys);
			ColumnSourceNamee->DataSource = list1;
			

			Dictionary<Attribute^, Attribute^>^ targetAttrs = _targetBook->GetGroupAttrs();
			Book^ targetBook = gcnew DbBook(_targetBook, nullptr, false, _odbc);
			Dictionary<String^, String^>^ targetList = gcnew Dictionary<String^, String^>();
			for each (KeyValuePair<Attribute^, Attribute^>^ pair in targetAttrs)
			{
				Attribute^ nameAttr = pair->Value;
				String^ valueName = targetBook->GetGroupAttrValue(nameAttr, integrationGroup->TargetGroupId)->ToString();
				Attribute^ codeAttr = pair->Key;
				String^ valueCode = targetBook->GetGroupAttrValue(codeAttr, integrationGroup->TargetGroupId)->ToString();
				targetList->Add(valueName, valueCode);
			}
			_currentTargetList = targetList;
			List<String^>^ list2 = gcnew List<String ^>(_currentTargetList->Keys);
			ColumnTargetNamee->DataSource = list2;
			
		}

		IntegrationGroupPair^ GetIntegrationGroupPair(String^ fullCode)
		{
			for each (IntegrationGroupPair^ integrationGroup in _integrationGroups)
			{
				if (integrationGroup->FullName == fullCode)
				{
					return integrationGroup;
				}
			}
			return nullptr;
		}

		void SaveCurrentDgv()
		{
			for (int ig = 0; ig < _integrationGroups->Count; ig++)
			{
				if (_integrationGroups[ig]->FullName == _prevSelectGroupItem->ToString())
				{
					_integrationGroups[ig]->SourceNamesDataSource = gcnew List<String ^>(_currentSourceList->Keys);
					_integrationGroups[ig]->TargetNamesDataSource = gcnew List<String ^>(_currentTargetList->Keys);

					List<array<String^>^>^ attrDataList = gcnew List<array<String ^> ^>();
					for (int i = 0; i < dgv->RowCount; i++)
					{
						bool allOk = true;
						array<String^>^ row = gcnew array<String ^>(8);
						for (int j = 0; j < 8; j++)
						{
							if (dgv[j,i]->Value == nullptr || String::IsNullOrEmpty(dgv[j,i]->Value->ToString()))
							{
								allOk = false;
								break;
							}
							row[j] = dgv[j,i]->Value->ToString();
						}
						if (allOk)
						{
							attrDataList->Add(row);
						}
					}
					_integrationGroups[ig]->AttributesDataDgv = attrDataList;
					break;
				}
			}
		}

		void GetDgvParams(IntegrationGroupPair^ integrationGroup)
		{
			ColumnSourceNamee->DataSource = integrationGroup->SourceNamesDataSource;
			ColumnTargetNamee->DataSource = integrationGroup->TargetNamesDataSource;
			
			List<array<String^>^>^ attrDataList = integrationGroup->AttributesDataDgv;
			for each (array<String^>^ row in attrDataList)
			{
				dgv->Rows->Add(row);
			}
		}

		void CheckAttrDataLinks(String^ dataTypeSource, String^ dataTypeTarget)
		{
			if ((dataTypeSource == "СТРОКА" && dataTypeTarget == "ЛОГИЧЕСКИЙ") ||
				(_typeDir == 1 && dataTypeSource == "ЛОГИЧЕСКИЙ" && dataTypeTarget == "СТРОКА"))
			{
				MessageBox::Show("Символьный реквизит может не содержать логического значения!\nПри интеграции значения \"1\", \"TRUE\", \"ДА\" переводятся в TRUE, \"0\", \"FALSE\", \"НЕТ\" - в FALSE.\nПри неудачной попытке перевода корректировка реквизита не будет произведена!");
				return;
			}
			else if ((dataTypeSource == "СТРОКА" && dataTypeTarget == "ЦЕЛОЕ ЧИСЛО") ||
				(_typeDir == 1 && dataTypeSource == "ЦЕЛОЕ ЧИСЛО" && dataTypeTarget == "СТРОКА"))
			{
				MessageBox::Show("Символьный реквизит может не содержать целочисленного значения!\nПри интеграции будет произведена попытка перевода с учетом символа дробной части (\".\"\",\").\nПри неудачной попытке перевода корректировка реквизита не будет произведена!");
				return;
			}
			else if ((dataTypeSource == "СТРОКА" && dataTypeTarget == "ЧИСЛО С ПЛАВАЮЩЕЙ ТОЧКОЙ") ||
				(_typeDir == 1 && dataTypeSource == "ЧИСЛО С ПЛАВАЮЩЕЙ ТОЧКОЙ" && dataTypeTarget == "СТРОКА"))
			{
				MessageBox::Show("Символьный реквизит может не содержать числового значения!\nПри неудачной попытке перевода корректировка реквизита не будет произведена!");
				return;
			}
			else if ((dataTypeSource == "ЛОГИЧЕСКИЙ" && dataTypeTarget == "ЦЕЛОЕ ЧИСЛО") ||
				(_typeDir == 1 && dataTypeSource == "ЦЕЛОЕ ЧИСЛО" && dataTypeTarget == "ЛОГИЧЕСКИЙ"))
			{
				MessageBox::Show("При интеграции будет произведен перевод значений TRUE в \"1\", а FALSE в \"0\".\nПри неудачной попытке перевода корректировка реквизита не будет произведена!");
				return;
			}
			else if ((dataTypeSource == "ЛОГИЧЕСКИЙ" && dataTypeTarget == "ЧИСЛО С ПЛАВАЮЩЕЙ ТОЧКОЙ") ||
				(_typeDir == 1 && dataTypeSource == "ЧИСЛО С ПЛАВАЮЩЕЙ ТОЧКОЙ" && dataTypeTarget == "ЛОГИЧЕСКИЙ"))
			{
				MessageBox::Show("При интеграции будет произведен перевод значений TRUE в \"1,00\", а FALSE в \"0,00\".\nПри неудачной попытке перевода корректировка реквизита не будет произведена!");
				return;
			}
			else if ((dataTypeSource == "ЦЕЛОЕ ЧИСЛО" && dataTypeTarget == "ЛОГИЧЕСКИЙ") ||
				(_typeDir == 1 && dataTypeSource == "ЛОГИЧЕСКИЙ" && dataTypeTarget == "ЦЕЛОЕ ЧИСЛО"))
			{
				MessageBox::Show("Целочисленный реквизит может не содержать логического значения!\nПри интеграции будет произведена попытка перевода значений \"1\" в TRUE, а \"0\" в FALSE.\nПри неудачной попытке перевода корректировка реквизита не будет произведена!");
				return;
			}
			else if ((dataTypeSource == "ЦЕЛОЕ ЧИСЛО" && dataTypeTarget == "ЧИСЛО С ПЛАВАЮЩЕЙ ТОЧКОЙ") ||
				(_typeDir == 1 && dataTypeSource == "ЧИСЛО С ПЛАВАЮЩЕЙ ТОЧКОЙ" && dataTypeTarget == "ЦЕЛОЕ ЧИСЛО"))
			{
				MessageBox::Show("При интеграции будет произведен перевод целочисленных значений с добавлением нулевой дробной части.");
				return;
			}
			else if ((dataTypeSource == "ЧИСЛО С ПЛАВАЮЩЕЙ ТОЧКОЙ" && dataTypeTarget == "ЛОГИЧЕСКИЙ") ||
				(_typeDir == 1 && dataTypeSource == "ЛОГИЧЕСКИЙ" && dataTypeTarget == "ЧИСЛО С ПЛАВАЮЩЕЙ ТОЧКОЙ"))
			{
				MessageBox::Show("Числовой реквизит может не содержать логического значения!\nПри интеграции будет произведена попытка перевода значений \"1,00\" в TRUE, а \"0,00\" в FALSE.\nПри неудачной попытке перевода корректировка реквизита не будет произведена!");
				return;
			}
			else if ((dataTypeSource == "ЧИСЛО С ПЛАВАЮЩЕЙ ТОЧКОЙ" && dataTypeTarget == "ЦЕЛОЕ ЧИСЛО") ||
				(_typeDir == 1 && dataTypeSource == "ЦЕЛОЕ ЧИСЛО" && dataTypeTarget == "ЧИСЛО С ПЛАВАЮЩЕЙ ТОЧКОЙ"))
			{
				MessageBox::Show("При интеграции будет произведен перевод  значений с учетом только целой части.\nВозможна частичная потеря данных!");
				return;
			}
		}


	private: System::Void bAddGroup_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 AddEditGroupForm^ form = gcnew AddEditGroupForm(_sourceBook, _targetBook, _odbc);
				 form->ShowDialog();
				 IntegrationGroupPair^ integrationGroup = form->IntegrationGroup;
				 if (integrationGroup != nullptr)
				 {
					 lbGroups->Items->Add(integrationGroup->FullName);
					 _integrationGroups->Add(integrationGroup);
				 }
			 }
	private: System::Void dgv_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (e->RowIndex < 0 || e->ColumnIndex < 0)
			 {
				 return;
			 }
			 if (dgv[e->ColumnIndex, e->RowIndex]->Value == nullptr ||
				String::IsNullOrEmpty(dgv[e->ColumnIndex, e->RowIndex]->Value->ToString()))
			 {
				return;
			 }

			 if (e->ColumnIndex == 0)
			 {
				 _sAttrIsSet = false;
				 if (_sourceBook->HasGroup)
				 {
					 String^ nameAttr = dgv[0, e->RowIndex]->Value->ToString();
					 if (_currentSourceList->ContainsKey(nameAttr))
					 {
						 dgv[1, e->RowIndex]->Value = _currentSourceList[nameAttr];
						 //todo add from pos?
						 dgv[2, e->RowIndex]->Value = "СТРОКА";
						 dgv[3, e->RowIndex]->Value = 8;
					 }
					 else
					 {
						 dgv[1, e->RowIndex]->Value = nullptr;
						 dgv[2, e->RowIndex]->Value = nullptr;
						 dgv[3, e->RowIndex]->Value = nullptr;
					 }
				 }
				 else
				 {
					String^ cell = dgv[e->ColumnIndex, e->RowIndex]->Value->ToString();
					 Attribute^ attr = GetAttr(_sourceAttrs, cell);
					 dgv[1, e->RowIndex]->Value = attr->FullCode;
					 dgv[2, e->RowIndex]->Value = attr->DataType;
					 dgv[3, e->RowIndex]->Value = attr->MaxLength;
					 _sourceAttrsFree->Clear();
					 _sourceAttrsFree->AddRange(_sourceAttrs);
					 RemoveOnColumn(0, _sourceAttrsFree);
				 }
				 _sAttrIsSet = true;
			 }
			 if (e->ColumnIndex == 4)
			 {
				 //DataGridViewComboBoxCell^ cb = (DataGridViewComboBoxCell^)dgv->Rows[e->RowIndex]->Cells[e->ColumnIndex];
				 //if (cb->Value != nullptr)
				 //{
					// // do stuff
					// dgv->Invalidate();
				 //}
				 _tAttrIsSet = false;
				 if (_targetBook->HasGroup)
				 {
					 String^ nameAttr = dgv[4, e->RowIndex]->Value->ToString();
					 if (_currentTargetList->ContainsKey(nameAttr))
					 {
						 dgv[5, e->RowIndex]->Value = _currentTargetList[nameAttr];
						 //todo add from pos?
						 dgv[6, e->RowIndex]->Value = "СТРОКА";
						 dgv[7, e->RowIndex]->Value = 8;
					 }
					 else
					 {
						 dgv[5, e->RowIndex]->Value = nullptr;
						 dgv[6, e->RowIndex]->Value = nullptr;
						 dgv[7, e->RowIndex]->Value = nullptr;
					 }
				 }
				 else
				 {
					String^ cell = dgv[e->ColumnIndex, e->RowIndex]->Value->ToString();

					 Attribute^ attr = GetAttr(_targetAttrs, cell);
					 dgv[5, e->RowIndex]->Value = attr->FullCode;
					 dgv[6, e->RowIndex]->Value = attr->DataType;
					 dgv[7, e->RowIndex]->Value = attr->MaxLength;
					 _targetAttrsFree->Clear();
					 _targetAttrsFree->AddRange(_targetAttrs);
					 RemoveOnColumn(4, _targetAttrsFree);
				 }
				 _tAttrIsSet = true;
			 }

			 Object^ sourceAttrData = dgv[2, e->RowIndex]->Value;
			 Object^ sourceAttrLen = dgv[3, e->RowIndex]->Value;
			 Object^ targetAttrData = dgv[6, e->RowIndex]->Value;
			 Object^ targetAttrLen = dgv[7, e->RowIndex]->Value;

			 if (_sAttrIsSet && _tAttrIsSet)
			 {
				 if (sourceAttrData != nullptr && targetAttrData != nullptr)
				 {
					 CheckAttrDataLinks(sourceAttrData->ToString(), targetAttrData->ToString());
				 }
			 }
			 

		 }
	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
	private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 AttrPairs = gcnew Dictionary<Attribute ^, Attribute ^>();
			 for (int i = 0; i < dgv->Rows->Count; i++)
			 {
				 Object^ o1 = dgv[0, i]->Value;
				 Object^ o2 = dgv[4, i]->Value;
				 if (o1 != nullptr  &&  o2 != nullptr)
				 {
					 Attribute^ aS = GetAttr(_sourceAttrs, o1->ToString());
					 Attribute^ aT = GetAttr(_targetAttrs, o2->ToString());
					 AttrPairs->Add(aS, aT);
				 }
			 }
			 
			 Close();
		 }

private: System::Void dgv_CurrentCellDirtyStateChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //if (dgv->IsCurrentCellDirty)
			 //{
				// // This fires the cell value changed handler below
				// dgv->CommitEdit(DataGridViewDataErrorContexts::Commit);
			 //}
		 }
private: System::Void dgv_CellBeginEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^  e) 
		 {
			 if (e->RowIndex < 0 || e->ColumnIndex < 0)
			 {
				 return;
			 }


			 if (e->ColumnIndex == 0)
			 {
				 if (_sourceBook->HasGroup)
				 {

				 }
				 else
				 {
					 DataGridViewComboBoxCell^ cb = (DataGridViewComboBoxCell^)dgv->Rows[e->RowIndex]->Cells[e->ColumnIndex];
					 Object^ currCell = cb->Value;
					 cb->Items->Clear();
					 Object^ complexAttrName = dgv->Rows[e->RowIndex]->Cells[1]->Value;
					 if (complexAttrName == nullptr || 
						 String::IsNullOrEmpty(complexAttrName->ToString()) || 
						 !ContainsInComplex(complexAttrName->ToString()))
					 {
						 if (currCell != nullptr)
						 {
							 Attribute^ attr = GetAttr(_sourceAttrs, currCell->ToString());
							 _sourceAttrsFree->Add(attr);

						 }
						 for each (Attribute^ attr in _sourceAttrsFree)
						 {
							 if (String::IsNullOrEmpty(attr->Name))
							 {
								 cb->Items->Add(attr->FullCode);
							 }
							 else
							 {
								 cb->Items->Add(attr->Name);
							 }
						 }
					 }
				 }
				 
			 }
			 if (e->ColumnIndex == 4)
			 {
				 if (_sourceBook->HasGroup)
				 {

				 }
				 else
				 {
					 DataGridViewComboBoxCell^ cb = (DataGridViewComboBoxCell^)dgv->Rows[e->RowIndex]->Cells[e->ColumnIndex];
					 cb->Items->Clear();
					 for each (Attribute^ attr in _targetAttrsFree)
					 {
						 if (String::IsNullOrEmpty(attr->Name))
						 {
							 cb->Items->Add(attr->FullCode);
						 }
						 else
						 {
							 cb->Items->Add(attr->Name);
						 }
					 }
				 }
			 }
		 }
private: System::Void bAddComplexAttr_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dgv->SelectedCells == nullptr)
			 {
				 return;
			 }
			 if (dgv->SelectedCells->Count <= 0)
			 {
				 return;
			 }
			 if (
				 dgv->SelectedCells[0] == nullptr)
			 {
				 return;
			 }
			 if (
				 dgv->SelectedCells[0]->RowIndex < 0)
			 {
				 return;
			 }

			 AddComplexAttrForm^ complexAttrForm;
			 int iCol = dgv->SelectedCells[0]->ColumnIndex;
			 if (iCol < 4)
			 {
				 complexAttrForm = gcnew AddComplexAttrForm(_sourceAttrs, _targetAttrs, _odbc, true);
			 }
			 else
			 {
				 complexAttrForm = gcnew AddComplexAttrForm(_targetAttrs, _sourceAttrs, _odbc, false);
			 }
			 
			 complexAttrForm->ShowDialog();
			 if (complexAttrForm->complexAttr != nullptr)
			 {
				 array<Object^>^ row = gcnew array<Object ^>(8);
				 row[0] = nullptr;
				 row[1] = complexAttrForm->complexAttr->Name;
				 row[2] = "";
				 row[3] = "";
				 row[4] = nullptr;
				 row[5] = complexAttrForm->complexAttr->Name;
				 row[6] = "";
				 row[7] = "";
				 dgv->Rows->Add(row);

				 int r = dgv->RowCount - 2;
				 dgv[0, r]->ReadOnly = true;
				 dgv[4, r]->ReadOnly = true;
				 ComplexAttrs->Add(complexAttrForm->complexAttr);
			 }

		 }
private: System::Void bDelComplexAttr_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 int iRow = dgv->SelectedCells[0]->RowIndex;
			 Object^ cell = dgv->Rows[iRow]->Cells[1]->Value;
			 if (cell != nullptr && 
				 !String::IsNullOrEmpty(cell->ToString()) && 
				 ContainsInComplex(cell->ToString()))
			 {
				 dgv->Rows->RemoveAt(iRow);
			 }
		 }
private: System::Void lbGroups_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (_prevSelectGroupItem != nullptr && !String::IsNullOrEmpty(_prevSelectGroupItem->ToString()))
			 {
				 SaveCurrentDgv();
			 }
			 
			 dgv->Rows->Clear();
			 if (lbGroups->SelectedItem != nullptr && !String::IsNullOrEmpty(lbGroups->SelectedItem->ToString()))
			 {
				 IntegrationGroupPair^ integrationGroup = GetIntegrationGroupPair(lbGroups->SelectedItem->ToString());
				 //если dgv еще не заполнялся
				 if (integrationGroup->SourceNamesDataSource == nullptr)
				 {
					 SetDgvGroupParamSources(integrationGroup);
				 }
				 else
				 {
					 GetDgvParams(integrationGroup);
				 }
				 
			 }
			 _prevSelectGroupItem = lbGroups->SelectedItem;
		 }
};
}
