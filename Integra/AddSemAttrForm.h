#pragma once

#include "Semantic.h"
#include "Attribute.h"


namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddSemAttrForm
	/// </summary>
	public ref class AddSemAttrForm : public System::Windows::Forms::Form
	{
	public:
		Attribute^ IdCol;
		Attribute^ TitleCol;
		List<array<String^>^>^ Attributes;

	private:
		Semantic^ _sem;
		String^ _semLogin;
		String^ _semPass;
		Dictionary<String^, List<array<Object^>^>^>^ _attrDict;
		int _nEdits;
		int _nChecked;
		String^ _prevNodeFullCode;
		bool _programChecked;
		bool _overflowCheck;

		List<String^>^ _nameCols;
		Dictionary<String^, String^>^ _attrCodeNames;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
			 

	public:
		AddSemAttrForm(String^ login, String^ password)
		{
			InitializeComponent();
			_semLogin = login;
			_semPass = password;
			_nEdits = 0;
			_nChecked = 0;
			_attrDict = gcnew Dictionary<String ^, List<array<Object ^> ^> ^>();
			Attributes = gcnew List<array<String ^> ^>();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddSemAttrForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  cbTitle;
	protected: 
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  cbId;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  bClose;
	private: System::Windows::Forms::Button^  bRecord;
	private: System::Windows::Forms::DataGridView^  dgvFields;






	private: System::Windows::Forms::TreeView^  tvBooks;


	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  lIdBook;


	private: System::Windows::Forms::Label^  lNameBook;


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
			this->cbTitle = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cbId = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bClose = (gcnew System::Windows::Forms::Button());
			this->bRecord = (gcnew System::Windows::Forms::Button());
			this->dgvFields = (gcnew System::Windows::Forms::DataGridView());
			this->tvBooks = (gcnew System::Windows::Forms::TreeView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lIdBook = (gcnew System::Windows::Forms::Label());
			this->lNameBook = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvFields))->BeginInit();
			this->SuspendLayout();
			// 
			// cbTitle
			// 
			this->cbTitle->Enabled = false;
			this->cbTitle->FormattingEnabled = true;
			this->cbTitle->Location = System::Drawing::Point(471, 208);
			this->cbTitle->Name = L"cbTitle";
			this->cbTitle->Size = System::Drawing::Size(432, 21);
			this->cbTitle->TabIndex = 20;
			this->cbTitle->SelectedIndexChanged += gcnew System::EventHandler(this, &AddSemAttrForm::cbTitle_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(481, 192);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Основной реквизит";
			// 
			// cbId
			// 
			this->cbId->Enabled = false;
			this->cbId->FormattingEnabled = true;
			this->cbId->Location = System::Drawing::Point(471, 93);
			this->cbId->Name = L"cbId";
			this->cbId->Size = System::Drawing::Size(432, 21);
			this->cbId->TabIndex = 18;
			this->cbId->SelectedIndexChanged += gcnew System::EventHandler(this, &AddSemAttrForm::cbId_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(481, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 13);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Реквизит-идентификатор";
			// 
			// bClose
			// 
			this->bClose->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->bClose->Location = System::Drawing::Point(816, 472);
			this->bClose->Name = L"bClose";
			this->bClose->Size = System::Drawing::Size(87, 30);
			this->bClose->TabIndex = 16;
			this->bClose->Text = L"Отмена";
			this->bClose->UseVisualStyleBackColor = true;
			this->bClose->Click += gcnew System::EventHandler(this, &AddSemAttrForm::bClose_Click);
			// 
			// bRecord
			// 
			this->bRecord->Location = System::Drawing::Point(709, 472);
			this->bRecord->Name = L"bRecord";
			this->bRecord->Size = System::Drawing::Size(87, 30);
			this->bRecord->TabIndex = 15;
			this->bRecord->Text = L"Записать";
			this->bRecord->UseVisualStyleBackColor = true;
			this->bRecord->Click += gcnew System::EventHandler(this, &AddSemAttrForm::bRecord_Click);
			// 
			// dgvFields
			// 
			this->dgvFields->AllowUserToAddRows = false;
			this->dgvFields->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvFields->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvFields->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvFields->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->Column1, this->Column2, 
				this->Column3, this->Column4, this->Column8});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvFields->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvFields->Location = System::Drawing::Point(34, 252);
			this->dgvFields->Name = L"dgvFields";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvFields->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dgvFields->RowHeadersVisible = false;
			this->dgvFields->Size = System::Drawing::Size(869, 210);
			this->dgvFields->TabIndex = 14;
			this->dgvFields->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AddSemAttrForm::dgvFields_CellValueChanged);
			// 
			// tvBooks
			// 
			this->tvBooks->CheckBoxes = true;
			this->tvBooks->FullRowSelect = true;
			this->tvBooks->Location = System::Drawing::Point(34, 42);
			this->tvBooks->Name = L"tvBooks";
			this->tvBooks->Size = System::Drawing::Size(420, 178);
			this->tvBooks->TabIndex = 21;
			this->tvBooks->AfterCheck += gcnew System::Windows::Forms::TreeViewEventHandler(this, &AddSemAttrForm::tvBooks_AfterCheck);
			this->tvBooks->BeforeExpand += gcnew System::Windows::Forms::TreeViewCancelEventHandler(this, &AddSemAttrForm::tvBooks_BeforeExpand);
			this->tvBooks->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &AddSemAttrForm::tvBooks_AfterSelect);
			this->tvBooks->DoubleClick += gcnew System::EventHandler(this, &AddSemAttrForm::tvBooks_DoubleClick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(46, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 13);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Справочники и группы:";
			// 
			// lIdBook
			// 
			this->lIdBook->Location = System::Drawing::Point(481, 28);
			this->lIdBook->Name = L"lIdBook";
			this->lIdBook->Size = System::Drawing::Size(422, 49);
			this->lIdBook->TabIndex = 23;
			this->lIdBook->Text = L"Не задан";
			// 
			// lNameBook
			// 
			this->lNameBook->Location = System::Drawing::Point(481, 139);
			this->lNameBook->Name = L"lNameBook";
			this->lNameBook->Size = System::Drawing::Size(422, 53);
			this->lNameBook->TabIndex = 25;
			this->lNameBook->Text = L"Не задано";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(468, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(197, 13);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Элемент реквизита-идентификатора:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(46, 236);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 13);
			this->label5->TabIndex = 28;
			this->label5->Text = L"Реквизиты:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(468, 126);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(166, 13);
			this->label6->TabIndex = 29;
			this->label6->Text = L"Элемент основного реквизита:";
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Используемость";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Код рекзвизита";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 150;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Наименование реквизита";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 400;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Тип данных";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Максимальный объем данных";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			// 
			// AddSemAttrForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->bClose;
			this->ClientSize = System::Drawing::Size(915, 514);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lNameBook);
			this->Controls->Add(this->lIdBook);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tvBooks);
			this->Controls->Add(this->cbTitle);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->cbId);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bClose);
			this->Controls->Add(this->bRecord);
			this->Controls->Add(this->dgvFields);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddSemAttrForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"AddSemAttrForm";
			this->Load += gcnew System::EventHandler(this, &AddSemAttrForm::AddSemAttrForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvFields))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:
			void SetAttrs(TreeNode^ keyNode)
			{
				_nChecked = 0;
				String^ fullCode = GetFullNodeCodeS(keyNode);
				if (_attrDict->ContainsKey(fullCode))
				{
					SetDgvAttrs(_attrDict[fullCode]);
				}
				else
				{
					SetDgvAttrs(_sem->GetClassAttrs(GetFullNodeCode(keyNode)));
				}
				SetComboBoxItems();
				_prevNodeFullCode = fullCode;

				_nEdits = 0;
			}

			void SetComboBoxItems()
			{
				cbId->Items->Clear();
				cbTitle->Items->Clear();
				for each(KeyValuePair<String^,String^>^ p in _attrCodeNames)
				{
					cbId->Items->Add(p->Key);
					cbTitle->Items->Add(p->Key);
				}
			}

			void SetDgvAttrs(List<array<Object^>^>^ attrs)
			{
				dgvFields->Rows->Clear();
				_attrCodeNames = gcnew Dictionary<String ^, String ^>();
				for each(array<Object^>^ arr in attrs)
				{
					if (((bool)arr[0]) == true)
					{
						_nChecked++;
					}
					_attrCodeNames->Add(arr[1]->ToString(), arr[2]->ToString());
					dgvFields->Rows->Add(arr);
				}
			}

			void WritePrevClassAttrs()
			{
				String^ fullCode = _prevNodeFullCode;

				if (_attrDict->ContainsKey(fullCode) && _nEdits <= 0)
				{
					return;
				}

				if (_attrDict->ContainsKey(fullCode))
				{
					_attrDict->Remove(fullCode);
				}

				List<array<Object^>^>^ list = gcnew List<array<Object ^> ^>();

				int nRows = dgvFields->Rows->Count;
				for (int i =0; i < nRows; i++)
				{
					array<Object^>^ arr = gcnew array<Object ^>(5);
					if (((bool)dgvFields[0, i]->Value) == true)
					{
						arr[0] = true;
					}
					else
					{
						arr[0] = false;
					}
					arr[1] = dgvFields[1, i]->Value;
					arr[2] = dgvFields[2, i]->Value;
					arr[3] = dgvFields[3, i]->Value;
					arr[4] = dgvFields[4, i]->Value;
					list->Add(arr);
				}
				_attrDict->Add(fullCode, list);
			}

			List<String^>^ GetFullNodeCode(TreeNode^ node)
			{
				List<String^>^ list = gcnew List<String ^>();
				int level = node->Level;
				while (level > -1)
				{
					list->Add(node->Name);
					if (node->Parent == nullptr)
					{
						break;
					}
					node = node->Parent;
					level = node->Level;
				}
				list->Reverse();
				return list;
			}

			String^ GetFullNodeCodeS(TreeNode^ node)
			{
				List<String^>^ fullList = GetFullNodeCode(node);
				String^ s = "";
				for each(String^ ss in fullList)
				{
					s += ss + ".";
				}
				return s;
			}

	private: System::Void AddSemAttrForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 int i = 0;
				 try
				 {
					 _sem = gcnew Semantic(_semLogin, _semPass);
					 List<String^>^ folderList = _sem->GetAllFolderBooks();
					 for each(String^ folder in folderList)
					 {
						 tvBooks->Nodes->Add(i + "", folder);
						 tvBooks->Nodes[i]->Nodes->Add("");
						 i++;
					 }
				 }
				 catch (WrongPassSemanticException^ e)
				 {
					 MessageBox::Show(e->Message);
					 Close();
				 }
				 
			 }
private: System::Void tvBooks_BeforeExpand(System::Object^  sender, System::Windows::Forms::TreeViewCancelEventArgs^  e) 
		 {
			 TreeNode^ node = e->Node;
			 if (node->Nodes->Count < 2 && node->Nodes[0]->Text == "")
			 {
				 String^ name = e->Node->Text;

				 node->Nodes->Clear();
				 if (node->Level == 0)
				 {
					 Dictionary<String^, String^>^ dict = _sem->GetAllBooks(name);
					 for each (KeyValuePair<String^, String^>^ pair in dict)
					 {
						 node->Nodes->Add(pair->Key, pair->Value);
						 node->Nodes[pair->Key]->Nodes->Add("");
					 }
				 }
				 if (node->Level == 1)
				 {
					 String^ code = e->Node->Name;
					 Dictionary<String^, String^>^ dict = _sem->GetAllGroups(code);
					 TreeNode^ knode = node;
					 for each (KeyValuePair<String^, String^>^ pair in dict)
					 {
						 node->Nodes->Add(pair->Key, pair->Value);
						 node = node->Nodes[pair->Key];
					 }
					 knode->ExpandAll();
				 }
			 }
		 }
private: System::Void tvBooks_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) 
		 {
			 if (dgvFields->Rows->Count > 0)
			 {
				 WritePrevClassAttrs();
			 }
			 dgvFields->Rows->Clear();

			 if (e->Node->Level > 1)
			 {
				 SetAttrs(e->Node);
				 cbId->Enabled = true;
				 cbTitle->Enabled = true;
			 }
			 else
			 {
				 cbId->Enabled = false;
				 cbTitle->Enabled = false;
			 }
			 
		 }
private: System::Void dgvFields_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 if (e->ColumnIndex == 0 && e->RowIndex >= 0)
			 {
				 if (((bool)dgvFields[e->ColumnIndex, e->RowIndex]->Value) == true)
				 {
					 _nChecked++;
				 }
				 else
				 {
					 _nChecked--;
				 }

				 _programChecked = true;
				 if (_nChecked > 0)
				 {
					 tvBooks->SelectedNode->Checked = true;
				 }
				 else
				 {
					 tvBooks->SelectedNode->Checked = false;
				 }
				 _programChecked = false;
			 }
		 }

private: System::Void tvBooks_AfterCheck(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) 
		 {
			 if (!_programChecked && !_overflowCheck)
			 {
				 _overflowCheck = true;
				 e->Node->Checked = false;
			 }
			 _overflowCheck = false;
		 }
private: System::Void tvBooks_DoubleClick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 auto localPosition = tvBooks->PointToClient(Cursor->Position);
			 auto hitTestInfo = tvBooks->HitTest(localPosition);
			 if (hitTestInfo->Location == TreeViewHitTestLocations::StateImage)
				 return;
		 }
private: System::Void cbId_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //lIdBook->Text = GetFullNodeCodeS(tvBooks->SelectedNode.FullPath);
			 String^ code = cbId->SelectedItem->ToString();
			 lIdBook->Text = tvBooks->SelectedNode->FullPath;
			 IdCol = gcnew Attribute(GetFullNodeCodeS(tvBooks->SelectedNode) + "." + code, _attrCodeNames[code]);
		 }


private: System::Void cbTitle_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String^ code = cbTitle->SelectedItem->ToString();
			 lNameBook->Text = tvBooks->SelectedNode->FullPath;
			 TitleCol = gcnew Attribute(GetFullNodeCodeS(tvBooks->SelectedNode) + "." + code, _attrCodeNames[code]);
		 }

private: System::Void bRecord_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (cbId->SelectedItem == nullptr)
			 {
				 MessageBox::Show("Не задан реквизит-идентификатор!");
				 return;
			 }
			 if (cbTitle->SelectedItem == nullptr)
			 {
				 MessageBox::Show("Не задан основной реквизит!");
				 return;
			 }
			 WritePrevClassAttrs();

			 for each(KeyValuePair<String^, List<array<Object^>^>^>^ pair in _attrDict)
			 {
				 String^ schtab = pair->Key;
				 for each(array<Object^>^ ar in pair->Value)
				 {
					 bool isUseAttr = (bool)ar[0];
					 if (isUseAttr)
					 {
						 array<String^>^ arrr = gcnew array<String ^>(5);
						 arrr[0] = schtab;
						 arrr[1] = ar[2]->ToString();
						 arrr[2] = "";
						 arrr[3] = schtab;
						 arrr[4] = ar[1]->ToString();

						 Attributes->Add(arrr);
					 }
				 }
			 }
			 Close();
		 }
private: System::Void bClose_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 IdCol = nullptr;
			 TitleCol = nullptr;
			 Close();
		 }

};
}
