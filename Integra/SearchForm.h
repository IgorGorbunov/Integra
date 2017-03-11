#pragma once

#include "Position.h"
#include "Book.h"
#include "DbBook.h"


namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SearchForm
	/// </summary>
	public ref class SearchForm : public System::Windows::Forms::Form
	{
	public:
		bool IsOk;
		bool IsCancel;

		Position^ selectPos;

	private:
		OdbcClass^ _odbc;
		List<Position^>^ _positions;
		List<DataGridViewColumn^>^ _cols;
		List<String^>^ _columnNames;
		BookSettings^ _targetBook;
		List<array<Object^>^>^ _allPositions;





	private: System::Windows::Forms::DataGridView^  dgvFilter;
	private: System::Windows::Forms::DataGridView^  dgvPoses;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::Button^  bSetFilter;
			 


	

	public:
		SearchForm(OdbcClass^ odbc, List<Position^>^ positions, List<DataGridViewColumn^>^ cols, BookSettings^ targetBook)
		{
			InitializeComponent();

			_odbc = odbc;
			_positions = positions;
			_cols = cols;
			_targetBook = targetBook;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SearchForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Button^  bOk;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Splitter^  splitter1;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel5;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->bSetFilter = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->dgvFilter = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->dgvPoses = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvFilter))->BeginInit();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvPoses))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->bSetFilter);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 230);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(665, 52);
			this->panel1->TabIndex = 0;
			// 
			// bSetFilter
			// 
			this->bSetFilter->Location = System::Drawing::Point(38, 15);
			this->bSetFilter->Name = L"bSetFilter";
			this->bSetFilter->Size = System::Drawing::Size(132, 23);
			this->bSetFilter->TabIndex = 1;
			this->bSetFilter->Text = L"Применить фильтр";
			this->bSetFilter->UseVisualStyleBackColor = true;
			this->bSetFilter->Click += gcnew System::EventHandler(this, &SearchForm::bSetFilter_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->bCancel);
			this->panel2->Controls->Add(this->bOk);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel2->Location = System::Drawing::Point(465, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 52);
			this->panel2->TabIndex = 0;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(104, 13);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 1;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &SearchForm::bCancel_Click);
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(23, 13);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 0;
			this->bOk->Text = L"OK";
			this->bOk->UseVisualStyleBackColor = true;
			this->bOk->Click += gcnew System::EventHandler(this, &SearchForm::bOk_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->panel6);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(200, 230);
			this->panel3->TabIndex = 1;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->dgvFilter);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->Location = System::Drawing::Point(0, 0);
			this->panel6->Name = L"panel6";
			this->panel6->Padding = System::Windows::Forms::Padding(10);
			this->panel6->Size = System::Drawing::Size(200, 230);
			this->panel6->TabIndex = 0;
			// 
			// dgvFilter
			// 
			this->dgvFilter->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvFilter->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Column1, this->Column2, 
				this->Column3});
			this->dgvFilter->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvFilter->Location = System::Drawing::Point(10, 10);
			this->dgvFilter->Name = L"dgvFilter";
			this->dgvFilter->RowHeadersVisible = false;
			this->dgvFilter->Size = System::Drawing::Size(180, 210);
			this->dgvFilter->TabIndex = 0;
			this->dgvFilter->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SearchForm::dgvFilter_CellValueChanged);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Реквизит";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Операция";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 50;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Значение";
			this->Column3->Name = L"Column3";
			// 
			// splitter1
			// 
			this->splitter1->BackColor = System::Drawing::Color::Silver;
			this->splitter1->Location = System::Drawing::Point(200, 0);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(3, 230);
			this->splitter1->TabIndex = 2;
			this->splitter1->TabStop = false;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(203, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(462, 230);
			this->panel4->TabIndex = 3;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->dgvPoses);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Padding = System::Windows::Forms::Padding(10);
			this->panel5->Size = System::Drawing::Size(462, 230);
			this->panel5->TabIndex = 0;
			// 
			// dgvPoses
			// 
			this->dgvPoses->AllowUserToAddRows = false;
			this->dgvPoses->AllowUserToDeleteRows = false;
			this->dgvPoses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvPoses->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvPoses->Location = System::Drawing::Point(10, 10);
			this->dgvPoses->Name = L"dgvPoses";
			this->dgvPoses->ReadOnly = true;
			this->dgvPoses->Size = System::Drawing::Size(442, 210);
			this->dgvPoses->TabIndex = 0;
			// 
			// SearchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(665, 282);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->MinimumSize = System::Drawing::Size(400, 220);
			this->Name = L"SearchForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Фильтр позиции";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SearchForm::SearchForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &SearchForm::SearchForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvFilter))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvPoses))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		void SetColumns()
		{
			dgvPoses->ColumnHeadersVisible = true;

			_columnNames = gcnew List<String ^>();
			DataGridViewCell^ cell = gcnew DataGridViewTextBoxCell();
			cell->Style->BackColor = Color::White;
			for each (DataGridViewColumn^ col in _cols)
			{
				col->CellTemplate = cell;
				dgvPoses->Columns->Add(col);
				_columnNames->Add(col->HeaderText);
			}
		}

		void SetFilterCols()
		{
			List<String^>^ operations = gcnew List<String ^>();
			operations->Add("=");
			operations->Add("<>");
			operations->Add("IS NULL");
			operations->Add("IS NOT NULL");
			Column2->DataSource = operations;

			_columnNames->Add("");
			Column1->DataSource = _columnNames;
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
			_allPositions->Add(row);
		}

		void SetPoses()
		{
			_allPositions = gcnew List<array<Object ^> ^>();
			for each (Position^ tPos in _positions)
			{
				SetRow(dgvPoses, tPos, _targetBook->AttrCaption, GetPosingAtrrs(tPos));
			}
		}

		void SetAllPoses()
		{
			dgvPoses->Rows->Clear();
			for each (array<Object^>^ row in _allPositions)
			{
				dgvPoses->Rows->Add(row);
			}
		}

		Dictionary<String^, String^>^ GetPosingAtrrs(Position^ pos)
		{
			Dictionary<String^, String^>^ resDict = gcnew Dictionary<String ^, String ^>();

			Dictionary<Attribute^, Attribute^>^ posAttrs = _targetBook->GetPosGroupAttrs();
			Book^ book = gcnew DbBook(_targetBook, nullptr, true, _odbc);
			for each (KeyValuePair<Attribute^, Attribute^>^ pair in posAttrs)
			{
				Attribute^ nameAttr = pair->Value;
				String^ valueName = book->GetPosAttrValue(nameAttr, pos->UnicId)->ToString();
				Attribute^ codeAttr = pair->Key;
				String^ valueCode = book->GetPosAttrValue(codeAttr, pos->UnicId)->ToString();

				if (!String::IsNullOrEmpty(valueName))
				{
					resDict->Add(valueCode, valueName);
				}
			}
			return resDict;
		}

		void CheckFilters()
		{
			for (int j = 0; j < dgvFilter->RowCount - 1; j++)
			{
				Object^ oConditColumn = dgvFilter[0, j]->Value;
				if (oConditColumn == nullptr || String::IsNullOrEmpty(oConditColumn->ToString()))
				{
					dgvFilter->Rows->RemoveAt(j);
					j--;
					continue;
				}
				Object^ oCondit = dgvFilter[1, j]->Value;
				if (oCondit == nullptr || String::IsNullOrEmpty(oCondit->ToString()))
				{
					dgvFilter->Rows->RemoveAt(j);
					j--;
					continue;
				}
				Object^ oVal = dgvFilter[2, j]->Value;
				if (oVal == nullptr || String::IsNullOrEmpty(oVal->ToString()))
				{
					dgvFilter[2, j]->Value = String::Empty;
				}
			}
		}

		void SetFilters()
		{
			for (int i = 0; i < dgvPoses->RowCount; i++)
			{
				bool isGood = true;
				for (int j = 0; j < dgvFilter->RowCount - 1; j++)
				{
					Object^ oConditColumn = dgvFilter[0, j]->Value;
					if (oConditColumn != nullptr && !String::IsNullOrEmpty(oConditColumn->ToString()))
					{
						String^ sCoditColumn = oConditColumn->ToString();
						String^ condition = dgvFilter[1, j]->Value->ToString();
						String^ conditonValue = dgvFilter[2, j]->Value->ToString();
						
						for (int k = 0; k < dgvPoses->ColumnCount; k++)
						{
							if (dgvPoses->Columns[k]->HeaderText == sCoditColumn)
							{
								Object^ value = dgvPoses[k, i]->Value;
								isGood = CheckValue(condition, conditonValue, value);
								break;
							}
						}
						if (!isGood)
						{
							break;
						}
					}
				}
				if (!isGood)
				{
					dgvPoses->Rows->RemoveAt(i);
					i--;
				}
			}
		}

		bool CheckValue(String^ condition, String^ conditionValue, Object^ value)
		{
			if (condition == "=")
			{
				if (value != nullptr && conditionValue->Trim()->ToUpper() == value->ToString()->Trim()->ToUpper())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(condition == "<>")
			{
				if (value == nullptr)
					return true;

				if (conditionValue->Trim()->ToUpper() != value->ToString()->Trim()->ToUpper())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(condition == ">")
			{
				
			}
			else if(condition == ">=")
			{

			}
			else if(condition == "<")
			{

			}
			else if(condition == "<=")
			{

			}
			else if(condition == "IS NULL")
			{
				if (value == nullptr || String::IsNullOrEmpty(value->ToString()))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(condition == "IS NOT NULL")
			{
				if (value != nullptr && !String::IsNullOrEmpty(value->ToString()))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			return true;
		}

private: System::Void SearchForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
		 {
			 if (!IsOk)
			 {
				 IsCancel = true;
				 IsOk = false;
			 }
			 
		 }

private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 IsCancel = true;
			 IsOk = false;
			 Close();
		 }
private: System::Void SearchForm_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetColumns();
			 SetFilterCols();
			 SetPoses();
		 }
private: System::Void dgvFilter_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
		 {
			 int i1 = dgvFilter->RowCount;
			 int i2 = dgvFilter->ColumnCount;
			 if (dgvFilter->RowCount <= 0 || dgvFilter->ColumnCount <= 0)
				return;

			 for (int i = 0; i < dgvFilter->RowCount - 1; i++)
			 {
				 Object^ cell1 = dgvFilter[0, i]->Value;
				 if (cell1 == nullptr || String::IsNullOrEmpty(cell1->ToString()))
				 {
					 dgvFilter->Rows->RemoveAt(i);
					 i--;
				 }
			 }
		 }
private: System::Void bSetFilter_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CheckFilters();
			 SetAllPoses();
			 SetFilters();
		 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dgvPoses->SelectedCells == nullptr || dgvPoses->SelectedCells->Count <= 0 || dgvPoses->SelectedCells[0] == nullptr)
			 {
				 MessageBox::Show("Выберите позицию!");
				 return;
			 }

			 int iRow = dgvPoses->SelectedCells[0]->RowIndex;

			 String^ unicPosId = dgvPoses[0, iRow]->Value->ToString();
			 IsOk = true;
			 IsCancel = false;
			 for each (Position^ pos in _positions)
			 {
				 if (pos->UnicId == unicPosId)
				 {
					 selectPos = pos;
					 break;
				 }
			 }
			 Close();
		 }
};
}
