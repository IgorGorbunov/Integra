#pragma once

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� AddNewUser
	/// </summary>
	public ref class AddNewUser : public System::Windows::Forms::Form
	{
	public:
		AddNewUser(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~AddNewUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  tbName;
	private: System::Windows::Forms::ComboBox^  cbRole;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  lRoleDescription;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Button^  bSave;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TreeView^  treeView2;
	private: System::Windows::Forms::TreeView^  treeView1;

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
			System::Windows::Forms::TreeNode^  treeNode10 = (gcnew System::Windows::Forms::TreeNode(L"���������� ����������"));
			System::Windows::Forms::TreeNode^  treeNode11 = (gcnew System::Windows::Forms::TreeNode(L"���������� ������������"));
			System::Windows::Forms::TreeNode^  treeNode12 = (gcnew System::Windows::Forms::TreeNode(L"���������� ��������� �����������"));
			System::Windows::Forms::TreeNode^  treeNode13 = (gcnew System::Windows::Forms::TreeNode(L"���������� ��������������� ��������"));
			System::Windows::Forms::TreeNode^  treeNode14 = (gcnew System::Windows::Forms::TreeNode(L"���������� ��������������� �������� � ���������"));
			System::Windows::Forms::TreeNode^  treeNode15 = (gcnew System::Windows::Forms::TreeNode(L"���������� ����������� ����������"));
			System::Windows::Forms::TreeNode^  treeNode16 = (gcnew System::Windows::Forms::TreeNode(L"��� ��� \"Semantic\""));
			System::Windows::Forms::TreeNode^  treeNode17 = (gcnew System::Windows::Forms::TreeNode(L"���� �� ����2"));
			System::Windows::Forms::TreeNode^  treeNode18 = (gcnew System::Windows::Forms::TreeNode(L"�� ���� �� ���"));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->cbRole = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lRoleDescription = (gcnew System::Windows::Forms::Label());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bSave = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->treeView2 = (gcnew System::Windows::Forms::TreeView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"��� ������������:";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(19, 40);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(132, 20);
			this->tbName->TabIndex = 1;
			// 
			// cbRole
			// 
			this->cbRole->FormattingEnabled = true;
			this->cbRole->Location = System::Drawing::Point(168, 40);
			this->cbRole->Name = L"cbRole";
			this->cbRole->Size = System::Drawing::Size(121, 21);
			this->cbRole->TabIndex = 2;
			this->cbRole->Text = L"�������������";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(182, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"����:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(310, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(161, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"�������� ���� ������������:";
			// 
			// lRoleDescription
			// 
			this->lRoleDescription->Location = System::Drawing::Point(303, 47);
			this->lRoleDescription->Name = L"lRoleDescription";
			this->lRoleDescription->Size = System::Drawing::Size(204, 24);
			this->lRoleDescription->TabIndex = 5;
			this->lRoleDescription->Text = L"���� ��� �����������.";
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(404, 319);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 6;
			this->bCancel->Text = L"������";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &AddNewUser::bCancel_Click);
			// 
			// bSave
			// 
			this->bSave->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bSave->Location = System::Drawing::Point(313, 319);
			this->bSave->Name = L"bSave";
			this->bSave->Size = System::Drawing::Size(75, 23);
			this->bSave->TabIndex = 7;
			this->bSave->Text = L"���������";
			this->bSave->UseVisualStyleBackColor = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->treeView2);
			this->groupBox1->Controls->Add(this->treeView1);
			this->groupBox1->Location = System::Drawing::Point(19, 86);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(467, 227);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"������ � ������:";
			// 
			// treeView1
			// 
			this->treeView1->CheckBoxes = true;
			this->treeView1->Location = System::Drawing::Point(11, 43);
			this->treeView1->Name = L"treeView1";
			treeNode10->Name = L"����0";
			treeNode10->Text = L"���������� ����������";
			treeNode11->Name = L"����1";
			treeNode11->Text = L"���������� ������������";
			treeNode12->Name = L"����2";
			treeNode12->Text = L"���������� ��������� �����������";
			treeNode13->Name = L"����3";
			treeNode13->Text = L"���������� ��������������� ��������";
			treeNode14->Name = L"����4";
			treeNode14->Text = L"���������� ��������������� �������� � ���������";
			treeNode15->Name = L"����5";
			treeNode15->Text = L"���������� ����������� ����������";
			this->treeView1->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(6) {treeNode10, treeNode11, treeNode12, 
				treeNode13, treeNode14, treeNode15});
			this->treeView1->Size = System::Drawing::Size(217, 167);
			this->treeView1->TabIndex = 1;
			// 
			// treeView2
			// 
			this->treeView2->CheckBoxes = true;
			this->treeView2->Location = System::Drawing::Point(244, 43);
			this->treeView2->Name = L"treeView2";
			treeNode16->Name = L"����0";
			treeNode16->Text = L"��� ��� \"Semantic\"";
			treeNode17->Name = L"����1";
			treeNode17->Text = L"���� �� ����2";
			treeNode18->Name = L"����2";
			treeNode18->Text = L"�� ���� �� ���";
			this->treeView2->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(3) {treeNode16, treeNode17, treeNode18});
			this->treeView2->Size = System::Drawing::Size(217, 167);
			this->treeView2->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(27, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(92, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"� ������������:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(256, 27);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"� ��������:";
			// 
			// AddNewUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(498, 354);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->bSave);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->lRoleDescription);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cbRole);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddNewUser";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"�������� ������ ������������";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Close();
			 }
};
}
