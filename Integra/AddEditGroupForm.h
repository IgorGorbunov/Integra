#pragma once



namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� AddEditGroupForm
	/// </summary>
	public ref class AddEditGroupForm : public System::Windows::Forms::Form
	{
		public:
			String^ DoubleName;
			String^ GroupName;

	private:


	private: System::Windows::Forms::DataGridViewTextBoxColumn^  IdColT;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  IdColS;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;

	
	public:
		AddEditGroupForm()
		{
			InitializeComponent();


		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~AddEditGroupForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tbName;
	private: System::Windows::Forms::DataGridView^  dgvSource;

	private: System::Windows::Forms::TreeView^  tvSource;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataGridView^  dgvTarget;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Button^  bOk;



	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->tvSource = (gcnew System::Windows::Forms::TreeView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dgvTarget = (gcnew System::Windows::Forms::DataGridView());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->dgvSource = (gcnew System::Windows::Forms::DataGridView());
			this->IdColS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->IdColT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTarget))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSource))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"������������";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(24, 36);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(630, 20);
			this->tbName->TabIndex = 1;
			// 
			// tvSource
			// 
			this->tvSource->BackColor = System::Drawing::SystemColors::Window;
			this->tvSource->Location = System::Drawing::Point(24, 92);
			this->tvSource->Name = L"tvSource";
			this->tvSource->Size = System::Drawing::Size(313, 196);
			this->tvSource->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"�������-��������:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(360, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"�������-��������:";
			// 
			// dgvTarget
			// 
			this->dgvTarget->AllowUserToAddRows = false;
			this->dgvTarget->AllowUserToDeleteRows = false;
			this->dgvTarget->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgvTarget->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTarget->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->IdColT, this->Column1});
			this->dgvTarget->Location = System::Drawing::Point(363, 92);
			this->dgvTarget->Name = L"dgvTarget";
			this->dgvTarget->ReadOnly = true;
			this->dgvTarget->RowHeadersVisible = false;
			this->dgvTarget->Size = System::Drawing::Size(291, 196);
			this->dgvTarget->TabIndex = 5;
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(579, 304);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 6;
			this->bCancel->Text = L"������";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &AddEditGroupForm::bCancel_Click);
			// 
			// bOk
			// 
			this->bOk->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bOk->Location = System::Drawing::Point(485, 304);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 7;
			this->bOk->Text = L"��";
			this->bOk->UseVisualStyleBackColor = false;
			this->bOk->Click += gcnew System::EventHandler(this, &AddEditGroupForm::bOk_Click);
			// 
			// dgvSource
			// 
			this->dgvSource->AllowUserToAddRows = false;
			this->dgvSource->AllowUserToDeleteRows = false;
			this->dgvSource->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgvSource->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSource->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->IdColS, this->dataGridViewTextBoxColumn1});
			this->dgvSource->Location = System::Drawing::Point(24, 92);
			this->dgvSource->Name = L"dgvSource";
			this->dgvSource->ReadOnly = true;
			this->dgvSource->RowHeadersVisible = false;
			this->dgvSource->Size = System::Drawing::Size(313, 196);
			this->dgvSource->TabIndex = 8;
			// 
			// IdColS
			// 
			this->IdColS->HeaderText = L"Id";
			this->IdColS->Name = L"IdColS";
			this->IdColS->ReadOnly = true;
			this->IdColS->Visible = false;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"������������";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 200;
			// 
			// IdColT
			// 
			this->IdColT->HeaderText = L"Id";
			this->IdColT->Name = L"IdColT";
			this->IdColT->ReadOnly = true;
			this->IdColT->Visible = false;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"������������";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 200;
			// 
			// AddEditGroupForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(670, 347);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->dgvTarget);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tvSource);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dgvSource);
			this->Name = L"AddEditGroupForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"����������/�������������� �������������� ������";
			this->Load += gcnew System::EventHandler(this, &AddEditGroupForm::AddEditGroupForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTarget))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvSource))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 GroupName = tbName->Text;
				 DoubleName = tvSource->SelectedNode->Text + " - " + dgvTarget[0, dgvTarget->SelectedCells[0]->RowIndex]->Value->ToString();
				 Close();
			 }
private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 GroupName = nullptr;
			 DoubleName = nullptr;
			 Close();
		 }
private: System::Void AddEditGroupForm_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 /*tvSource->Nodes->Add("0", "��������������� ������������");
			 tvSource->Nodes[0]->Nodes->Add("1", "1 �������������� ������������");
			 tvSource->Nodes[0]->Nodes["1"]->Nodes->Add("2", "11 ������ �������� ������");
			 tvSource->Nodes[0]->Nodes["1"]->Nodes["2"]->Nodes->Add("3", "110 ������ �������� ������");
			 tvSource->Nodes[0]->Nodes["1"]->Nodes["2"]->Nodes["3"]->Nodes->Add("4", "1101 �������� �������������� ������");
			 tvSource->Nodes[0]->Nodes["1"]->Nodes["2"]->Nodes["3"]->Nodes["4"]->Nodes->Add("5", "11010600 MAZAK INTEGREX 200-IVST");
			 tvSource->Nodes[0]->Nodes["1"]->Nodes["2"]->Nodes->Add("6", "111 ������ �������� �������� � ������������");
			 tvSource->Nodes[0]->Nodes["1"]->Nodes["2"]->Nodes["6"]->Nodes->Add("7", "1110 �������� � ������������ ������");
			 tvSource->Nodes[0]->Nodes["1"]->Nodes["2"]->Nodes["6"]->Nodes["7"]->Nodes->Add("8", "11100370 ��-220�");

			 dgvTarget->Rows->Add("������ ���������-�����������");*/

		 }
};
}
