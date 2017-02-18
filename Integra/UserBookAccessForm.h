#pragma once

#include "RoleStation.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для UserBookAccessForm
	/// </summary>
	public ref class UserBookAccessForm : public System::Windows::Forms::Form
	{
	public:
		Dictionary<int, String^>^ Users;
		bool IsOk;

	private:
		int _actionType;
		Dictionary<int, String^>^ _allUsers;

	public:
		UserBookAccessForm(int actionType, Dictionary<int, String^>^ users)
		{
			InitializeComponent();
			
			Users = gcnew Dictionary<int, String^>();
			_actionType = actionType;
			_allUsers = RoleStation::GetAllUsers();
			Dictionary<int, String^>^ allUsers = gcnew Dictionary<int, String ^>(_allUsers);
			if (_actionType == 0)
			{
				lbAllUsers->Items->AddRange(GetValueList(allUsers));
			}
			if (_actionType == 1 && users != nullptr)
			{
				for each (KeyValuePair<int, String^>^ pair in users)
				{
					if (allUsers->ContainsKey(pair->Key))
					{
						allUsers->Remove(pair->Key);
					}
				}
				lbAllUsers->Items->AddRange(GetValueList(allUsers));
				lbAddedUsers->Items->AddRange(GetValueList(users));
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~UserBookAccessForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  lbAllUsers;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ListBox^  lbAddedUsers;
	private: System::Windows::Forms::Button^  bOk;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Button^  bRemove;
	private: System::Windows::Forms::Button^  bAdd;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		array<String^>^ GetValueList(Dictionary<int, String^>^ dict)
		{
			List<String^>^ list = gcnew List<String ^>();
			for each (KeyValuePair<int, String^>^ pair in dict)
			{
				list->Add(pair->Value);
			}
			return list->ToArray();
		}

		int GetId(Dictionary<int, String^>^ dict, String^ value)
		{
			for each (KeyValuePair<int, String^>^ pair in dict)
			{
				if (pair->Value == value)
				{
					return pair->Key;
				}
			}
			return -1;
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbAllUsers = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbAddedUsers = (gcnew System::Windows::Forms::ListBox());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bRemove = (gcnew System::Windows::Forms::Button());
			this->bAdd = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbAllUsers
			// 
			this->lbAllUsers->FormattingEnabled = true;
			this->lbAllUsers->Location = System::Drawing::Point(29, 56);
			this->lbAllUsers->Name = L"lbAllUsers";
			this->lbAllUsers->Size = System::Drawing::Size(152, 186);
			this->lbAllUsers->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(26, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 30);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Все определённые пользователи в системе:";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(291, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(183, 30);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Пользователи с доступом к справочнику:";
			// 
			// lbAddedUsers
			// 
			this->lbAddedUsers->FormattingEnabled = true;
			this->lbAddedUsers->Location = System::Drawing::Point(294, 56);
			this->lbAddedUsers->Name = L"lbAddedUsers";
			this->lbAddedUsers->Size = System::Drawing::Size(152, 186);
			this->lbAddedUsers->TabIndex = 4;
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(290, 264);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 5;
			this->bOk->Text = L"ОК";
			this->bOk->UseVisualStyleBackColor = true;
			this->bOk->Click += gcnew System::EventHandler(this, &UserBookAccessForm::bOk_Click);
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(371, 264);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 7;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &UserBookAccessForm::bCancel_Click);
			// 
			// bRemove
			// 
			this->bRemove->Location = System::Drawing::Point(199, 99);
			this->bRemove->Name = L"bRemove";
			this->bRemove->Size = System::Drawing::Size(75, 23);
			this->bRemove->TabIndex = 8;
			this->bRemove->Text = L"<";
			this->bRemove->UseVisualStyleBackColor = true;
			this->bRemove->Click += gcnew System::EventHandler(this, &UserBookAccessForm::bRemove_Click);
			// 
			// bAdd
			// 
			this->bAdd->Location = System::Drawing::Point(199, 70);
			this->bAdd->Name = L"bAdd";
			this->bAdd->Size = System::Drawing::Size(75, 23);
			this->bAdd->TabIndex = 9;
			this->bAdd->Text = L">";
			this->bAdd->UseVisualStyleBackColor = true;
			this->bAdd->Click += gcnew System::EventHandler(this, &UserBookAccessForm::bAdd_Click);
			// 
			// UserBookAccessForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(471, 299);
			this->Controls->Add(this->bAdd);
			this->Controls->Add(this->bRemove);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->lbAddedUsers);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbAllUsers);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"UserBookAccessForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Доступ пользователей к справочнику";
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (_actionType == 0)
			 {
				 Users = nullptr;
			 }
			 IsOk = false;
			 Close();
		 }
private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 for (int i = 0; i < lbAddedUsers->Items->Count; i++)
			 {
				 String^ code = lbAddedUsers->Items[i]->ToString();
				 int id = GetId(_allUsers, code);
				 Users->Add(id, code);
			 }
			 IsOk = true;
			 Close();
		 }
private: System::Void bAdd_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (lbAllUsers->SelectedItem != nullptr && !String::IsNullOrEmpty(lbAllUsers->SelectedItem->ToString()))
			 {
				 lbAddedUsers->Items->Add(lbAllUsers->SelectedItem);
				 lbAllUsers->Items->Remove(lbAllUsers->SelectedItem);
			 }
		 }
private: System::Void bRemove_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (lbAddedUsers->SelectedItem != nullptr && !String::IsNullOrEmpty(lbAddedUsers->SelectedItem->ToString()))
			 {
				 lbAllUsers->Items->Add(lbAddedUsers->SelectedItem);
				 lbAddedUsers->Items->Remove(lbAddedUsers->SelectedItem);
			 }
		 }
};
}
