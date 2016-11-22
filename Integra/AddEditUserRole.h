#pragma once
#include "AddNewUser.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddEditUserRole
	/// </summary>
	public ref class AddEditUserRole : public System::Windows::Forms::Form
	{
	public:
		AddEditUserRole(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
			this->lbUsers->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"ULGU1", L"ULGU2", L"ULGU3", L"ULGU4"});
			this->lbUsers->Location = System::Drawing::Point(29, 42);
			this->lbUsers->Name = L"lbUsers";
			this->lbUsers->Size = System::Drawing::Size(153, 186);
			this->lbUsers->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(37, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Пользователи:";
			// 
			// cbRoles
			// 
			this->cbRoles->FormattingEnabled = true;
			this->cbRoles->Location = System::Drawing::Point(207, 42);
			this->cbRoles->Name = L"cbRoles";
			this->cbRoles->Size = System::Drawing::Size(256, 21);
			this->cbRoles->TabIndex = 2;
			this->cbRoles->Text = L"Гость";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(219, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Роль:";
			// 
			// lRoleDescription
			// 
			this->lRoleDescription->Location = System::Drawing::Point(204, 93);
			this->lRoleDescription->Name = L"lRoleDescription";
			this->lRoleDescription->Size = System::Drawing::Size(259, 135);
			this->lRoleDescription->TabIndex = 4;
			this->lRoleDescription->Text = L"Выбранная роль предназначена только для просмотра некоторых данных.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(218, 72);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Описание:";
			// 
			// bSaveEdit
			// 
			this->bSaveEdit->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bSaveEdit->Enabled = false;
			this->bSaveEdit->Location = System::Drawing::Point(246, 234);
			this->bSaveEdit->Name = L"bSaveEdit";
			this->bSaveEdit->Size = System::Drawing::Size(172, 28);
			this->bSaveEdit->TabIndex = 6;
			this->bSaveEdit->Text = L"Сохранить изменения";
			this->bSaveEdit->UseVisualStyleBackColor = false;
			// 
			// bAddNewUser
			// 
			this->bAddNewUser->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bAddNewUser->Location = System::Drawing::Point(29, 234);
			this->bAddNewUser->Name = L"bAddNewUser";
			this->bAddNewUser->Size = System::Drawing::Size(153, 49);
			this->bAddNewUser->TabIndex = 7;
			this->bAddNewUser->Text = L"Добавить нового пользователя";
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
			this->bDelUser->Text = L"Удалить пользователя";
			this->bDelUser->UseVisualStyleBackColor = false;
			// 
			// bClose
			// 
			this->bClose->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bClose->Location = System::Drawing::Point(402, 304);
			this->bClose->Name = L"bClose";
			this->bClose->Size = System::Drawing::Size(75, 23);
			this->bClose->TabIndex = 9;
			this->bClose->Text = L"Закрыть";
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
			this->Text = L"Редактирование прав пользователей";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bClose_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Close();
			 }
private: System::Void bAddNewUser_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 AddNewUser^ form = gcnew AddNewUser();
			 form->ShowDialog();
		 }
};
}
