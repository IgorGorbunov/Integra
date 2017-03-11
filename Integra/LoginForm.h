#pragma once

#include "ODBCclass.h"
#include "MainForm.h"
#include "RoleStation.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	private:
		SystemSettings^ _settingsFile;
		String^ _driver;

	public:
		LoginForm(void)
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tbLogin;
	private: System::Windows::Forms::TextBox^  tbPass;
	private: System::Windows::Forms::ComboBox^  cbDb;
	protected: 

	protected: 


	private: System::Windows::Forms::Button^  bOk;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;


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
			this->tbLogin = (gcnew System::Windows::Forms::TextBox());
			this->tbPass = (gcnew System::Windows::Forms::TextBox());
			this->cbDb = (gcnew System::Windows::Forms::ComboBox());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// tbLogin
			// 
			this->tbLogin->Location = System::Drawing::Point(21, 39);
			this->tbLogin->Name = L"tbLogin";
			this->tbLogin->Size = System::Drawing::Size(156, 20);
			this->tbLogin->TabIndex = 0;
			// 
			// tbPass
			// 
			this->tbPass->Location = System::Drawing::Point(21, 81);
			this->tbPass->Name = L"tbPass";
			this->tbPass->Size = System::Drawing::Size(156, 20);
			this->tbPass->TabIndex = 1;
			this->tbPass->UseSystemPasswordChar = true;
			// 
			// cbDb
			// 
			this->cbDb->FormattingEnabled = true;
			this->cbDb->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"OTL.KTPP.AVIASTAR.LINK-UL.RU"});
			this->cbDb->Location = System::Drawing::Point(21, 127);
			this->cbDb->Name = L"cbDb";
			this->cbDb->Size = System::Drawing::Size(156, 21);
			this->cbDb->TabIndex = 2;
			this->cbDb->Text = L"OTL.KTPP.AVIASTAR.LINK-UL.RU";
			// 
			// bOk
			// 
			this->bOk->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bOk->Location = System::Drawing::Point(21, 154);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 32);
			this->bOk->TabIndex = 3;
			this->bOk->Text = L"Войти";
			this->bOk->UseVisualStyleBackColor = false;
			this->bOk->Click += gcnew System::EventHandler(this, &LoginForm::bOk_Click);
			// 
			// bCancel
			// 
			this->bCancel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->bCancel->Location = System::Drawing::Point(102, 154);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 32);
			this->bCancel->TabIndex = 4;
			this->bCancel->Text = L"Отмена";
			this->bCancel->UseVisualStyleBackColor = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &LoginForm::bCancel_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Логин";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Пароль";
			// 
			// LoginForm
			// 
			this->AcceptButton = this->bOk;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->CancelButton = this->bCancel;
			this->ClientSize = System::Drawing::Size(199, 202);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->cbDb);
			this->Controls->Add(this->tbPass);
			this->Controls->Add(this->tbLogin);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Аутентификация";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 this->Close();
			 }
	private: System::Void bOk_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String^ driver;
			 String^ login;

			 
			 if (String::IsNullOrEmpty(tbPass->Text->Trim()))
			 {
				 //release
				driver = _driver;
				//MessageBox::Show("Введите пароль!");return;
			 }
			 else
			 {
				 login = tbLogin->Text->Trim();
				 String^ pass = tbPass->Text;
				 String^ db = cbDb->Text->Trim();
				 driver = "Driver={Microsoft ODBC for Oracle};Server=" + db + ";Uid=" + login + ";Pwd=" + pass + ";";
			 }
			 

			 OdbcClass^ odbc = gcnew OdbcClass(driver);
			 ProgramIntegration^ pr;
			 bool logOn = false;
			 try
			 {
				 List<Object^>^ query = odbc->ExecuteQuery("select ID from " + odbc->schema + "BOOKS");
				 pr = gcnew ProgramIntegration(odbc);
				 logOn = true;
			 }
			 catch (TimeoutException^){}
			
		     if (logOn)
		     {
				 login = odbc->Login;
				 //todo
				 _settingsFile->SetValue("LOGIN", login);
				 _settingsFile->UpdateFile();
				 RoleStation::SetOdbc(odbc);
				 RoleStation::SetRole(login);
				 this->Visible = false;

				 

				 MainForm^ form = gcnew MainForm();
				 form->ShowDialog();
				 this->Close();
		     }
		 }
private: System::Void LoginForm_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String^ configPath = Path::Combine(Application::StartupPath, Settings::UserConfigs);
			 //configPath = Settings::UserConfigs;
			 //configPath = Application::StartupPath;
			 _settingsFile = gcnew SystemSettings(configPath);
			 if (_settingsFile->Driver != nullptr)
			 {
				 _driver = _settingsFile->Driver;
			 }
			 else if (_settingsFile->Login != nullptr)
			 {
				 tbLogin->Text = _settingsFile->Login;
				 tbPass->Select();
			 }
			 
			 
		 }
};
}
