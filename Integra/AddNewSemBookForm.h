#pragma once

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ AddNewSemBookForm
	/// </summary>
	public ref class AddNewSemBookForm : public System::Windows::Forms::Form
	{
	public:
		AddNewSemBookForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~AddNewSemBookForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  cbSemBook;
	protected: 
	private: System::Windows::Forms::Button^  bOk;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  bCancel;

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cbSemBook = (gcnew System::Windows::Forms::ComboBox());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cbSemBook
			// 
			this->cbSemBook->FormattingEnabled = true;
			this->cbSemBook->Location = System::Drawing::Point(23, 33);
			this->cbSemBook->Name = L"cbSemBook";
			this->cbSemBook->Size = System::Drawing::Size(292, 21);
			this->cbSemBook->TabIndex = 0;
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(139, 81);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 1;
			this->bOk->Text = L"button1";
			this->bOk->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// bCancel
			// 
			this->bCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->bCancel->Location = System::Drawing::Point(229, 81);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 3;
			this->bCancel->Text = L"button2";
			this->bCancel->UseVisualStyleBackColor = true;
			// 
			// AddNewSemBookForm
			// 
			this->AcceptButton = this->bOk;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->bCancel;
			this->ClientSize = System::Drawing::Size(349, 130);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->cbSemBook);
			this->Name = L"AddNewSemBookForm";
			this->Text = L"AddNewSemBookForm";
			this->Load += gcnew System::EventHandler(this, &AddNewSemBookForm::AddNewSemBookForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddNewSemBookForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {

			 }
	};
}
