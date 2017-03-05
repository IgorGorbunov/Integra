#pragma once

#include "ODBCclass.h"
#include "User.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddNewUser
	/// </summary>
	public ref class AddNewUser : public System::Windows::Forms::Form
	{
	private:
		OdbcClass^ _odbc;

		List<Role^>^ _roles;

	public:
		AddNewUser(OdbcClass^ odbc)
		{
			InitializeComponent();
			_odbc = odbc;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->cbRole = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lRoleDescription = (gcnew System::Windows::Forms::Label());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bSave = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Логин:";
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
			this->cbRole->SelectedIndexChanged += gcnew System::EventHandler(this, &AddNewUser::cbRole_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(175, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Роль:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(161, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Описание прав пользователя:";
			// 
			// lRoleDescription
			// 
			this->lRoleDescription->Location = System::Drawing::Point(19, 100);
			this->lRoleDescription->Name = L"lRoleDescription";
			this->lRoleDescription->Size = System::Drawing::Size(270, 121);
			this->lRoleDescription->TabIndex = 5;
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->Location = System::Drawing::Point(214, 235);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 6;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &AddNewUser::bCancel_Click);
			// 
			// bSave
			// 
			this->bSave->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bSave->Location = System::Drawing::Point(124, 235);
			this->bSave->Name = L"bSave";
			this->bSave->Size = System::Drawing::Size(75, 23);
			this->bSave->TabIndex = 7;
			this->bSave->Text = L"Сохранить";
			this->bSave->UseVisualStyleBackColor = false;
			this->bSave->Click += gcnew System::EventHandler(this, &AddNewUser::bSave_Click);
			// 
			// AddNewUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(311, 280);
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
			this->Text = L"Добавить нового пользователя";
			this->Load += gcnew System::EventHandler(this, &AddNewUser::AddNewUser_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Close();
			 }

private: System::Void bSave_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (String::IsNullOrEmpty(tbName->Text))
			 {
				 MessageBox::Show("Заполните логин!");
				 return;
			 }
			 else if (cbRole->SelectedItem == nullptr)
			 {
				 MessageBox::Show("Выберите роль!");
				 return;
			 }
			 User::AddNewUser(tbName->Text->Trim(), cbRole->SelectedIndex + 1, _odbc);
			 Close();
		 }
private: System::Void AddNewUser_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 _roles = Role::GetAllRoles(_odbc);
			 cbRole->Items->Clear();
			 for each (Role^ r in _roles)
			 {
				 cbRole->Items->Add(r->RoleName);
			 }
		 }
		 
private: System::Void cbRole_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (cbRole->SelectedItem != nullptr)
			 {
				 lRoleDescription->Text = _roles[cbRole->SelectedIndex]->RoleDescription;
			 }
		 }
};
}
