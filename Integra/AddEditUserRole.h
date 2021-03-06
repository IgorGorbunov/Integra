#pragma once
#include "AddNewUser.h"
#include "ODBCclass.h"
#include "Role.h"
#include "User.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� AddEditUserRole
	/// </summary>
	public ref class AddEditUserRole : public System::Windows::Forms::Form
	{
	private:
		OdbcClass^ _odbc;

		List<Role^>^ _roles;
		List<User^>^ _users;

		int _selectedRoleI;

	public:
		AddEditUserRole(OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~AddEditUserRole()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  lbUsers;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cbRoles;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lRoleDescription;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  bSaveEdit;
	private: System::Windows::Forms::Button^  bAddNewUser;
	private: System::Windows::Forms::Button^  bDelUser;
	private: System::Windows::Forms::Button^  bClose;

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
			this->lbUsers = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbRoles = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lRoleDescription = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->bSaveEdit = (gcnew System::Windows::Forms::Button());
			this->bAddNewUser = (gcnew System::Windows::Forms::Button());
			this->bDelUser = (gcnew System::Windows::Forms::Button());
			this->bClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbUsers
			// 
			this->lbUsers->FormattingEnabled = true;
			this->lbUsers->Location = System::Drawing::Point(29, 42);
			this->lbUsers->Name = L"lbUsers";
			this->lbUsers->Size = System::Drawing::Size(153, 186);
			this->lbUsers->TabIndex = 0;
			this->lbUsers->SelectedIndexChanged += gcnew System::EventHandler(this, &AddEditUserRole::lbUsers_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(37, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"������������:";
			// 
			// cbRoles
			// 
			this->cbRoles->FormattingEnabled = true;
			this->cbRoles->Location = System::Drawing::Point(207, 42);
			this->cbRoles->Name = L"cbRoles";
			this->cbRoles->Size = System::Drawing::Size(256, 21);
			this->cbRoles->TabIndex = 2;
			this->cbRoles->SelectedIndexChanged += gcnew System::EventHandler(this, &AddEditUserRole::cbRoles_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(219, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"����:";
			// 
			// lRoleDescription
			// 
			this->lRoleDescription->Location = System::Drawing::Point(204, 93);
			this->lRoleDescription->Name = L"lRoleDescription";
			this->lRoleDescription->Size = System::Drawing::Size(259, 135);
			this->lRoleDescription->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(218, 72);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(87, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"�������� ����:";
			// 
			// bSaveEdit
			// 
			this->bSaveEdit->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bSaveEdit->Enabled = false;
			this->bSaveEdit->Location = System::Drawing::Point(246, 234);
			this->bSaveEdit->Name = L"bSaveEdit";
			this->bSaveEdit->Size = System::Drawing::Size(172, 28);
			this->bSaveEdit->TabIndex = 6;
			this->bSaveEdit->Text = L"��������� ���������";
			this->bSaveEdit->UseVisualStyleBackColor = false;
			this->bSaveEdit->Click += gcnew System::EventHandler(this, &AddEditUserRole::bSaveEdit_Click);
			// 
			// bAddNewUser
			// 
			this->bAddNewUser->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddNewUser->Location = System::Drawing::Point(29, 234);
			this->bAddNewUser->Name = L"bAddNewUser";
			this->bAddNewUser->Size = System::Drawing::Size(153, 49);
			this->bAddNewUser->TabIndex = 7;
			this->bAddNewUser->Text = L"�������� ������ ������������";
			this->bAddNewUser->UseVisualStyleBackColor = false;
			this->bAddNewUser->Click += gcnew System::EventHandler(this, &AddEditUserRole::bAddNewUser_Click);
			// 
			// bDelUser
			// 
			this->bDelUser->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bDelUser->Location = System::Drawing::Point(29, 288);
			this->bDelUser->Name = L"bDelUser";
			this->bDelUser->Size = System::Drawing::Size(153, 30);
			this->bDelUser->TabIndex = 8;
			this->bDelUser->Text = L"������� ������������";
			this->bDelUser->UseVisualStyleBackColor = false;
			this->bDelUser->Visible = false;
			// 
			// bClose
			// 
			this->bClose->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bClose->Location = System::Drawing::Point(402, 304);
			this->bClose->Name = L"bClose";
			this->bClose->Size = System::Drawing::Size(75, 23);
			this->bClose->TabIndex = 9;
			this->bClose->Text = L"�������";
			this->bClose->UseVisualStyleBackColor = false;
			this->bClose->Click += gcnew System::EventHandler(this, &AddEditUserRole::bClose_Click);
			// 
			// AddEditUserRole
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(500, 339);
			this->Controls->Add(this->bClose);
			this->Controls->Add(this->bDelUser);
			this->Controls->Add(this->bAddNewUser);
			this->Controls->Add(this->bSaveEdit);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lRoleDescription);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cbRoles);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbUsers);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"AddEditUserRole";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"�������������� ���� �������������";
			this->Load += gcnew System::EventHandler(this, &AddEditUserRole::AddEditUserRole_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		void SetRoles()
		{
			_roles = Role::GetAllRoles(_odbc);
			cbRoles->Items->Clear();
			for each (Role^ r in _roles)
			{
				cbRoles->Items->Add(r->RoleName);
			}
		}

		void SetUsers()
		{
			_users = User::GetAllUsers(_odbc);
			lbUsers->Items->Clear();
			for each (User^ u in _users)
			{
				lbUsers->Items->Add(u->Code);
			}
		}


	private: System::Void bClose_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Close();
			 }
private: System::Void bAddNewUser_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 AddNewUser^ form = gcnew AddNewUser(_odbc);
			 form->ShowDialog();
			 SetUsers();

		 }
private: System::Void AddEditUserRole_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetRoles();
			 SetUsers();
		 }
private: System::Void cbRoles_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (cbRoles->SelectedItem != nullptr)
			 {
				 lRoleDescription->Text = _roles[cbRoles->SelectedIndex]->RoleDescription;
				 if (_selectedRoleI != cbRoles->SelectedIndex && lbUsers->SelectedItem != nullptr)
				 {
					 bSaveEdit->Enabled = true;
				 }
				 else
				 {
					 bSaveEdit->Enabled = false;
				 }
			 }
		 }
private: System::Void lbUsers_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (lbUsers->SelectedItem != nullptr)
			 {
				 for each (String^ sRole in cbRoles->Items)
				 {
					 if (sRole == _users[lbUsers->SelectedIndex]->RoleName)
					 {
						 _selectedRoleI = _users[lbUsers->SelectedIndex]->RoleId - 1;
						 cbRoles->SelectedIndex = 0;
						 cbRoles->SelectedIndex = _users[lbUsers->SelectedIndex]->RoleId - 1;
						 break;
					 }
				 }
			 }
		 }
private: System::Void bSaveEdit_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (lbUsers->SelectedItem != nullptr)
			 {
				 _users[lbUsers->SelectedIndex]->SetNewRole(cbRoles->SelectedIndex + 1);
				 SetUsers();
				 bSaveEdit->Enabled = false;
				 MessageBox::Show("���� ������������ ��������!");
			 }
		 }
};
}
