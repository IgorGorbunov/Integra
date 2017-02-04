#pragma once

#include"Semantic.h"
#include"ExcelClass.h"

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для NormIntegrForm
	/// </summary>
	public ref class NormIntegrForm : public System::Windows::Forms::Form
	{
	public:
		NormIntegrForm()
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
		~NormIntegrForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TreeView^  tvKarts;
	protected: 

	private: System::Windows::Forms::Button^  bAddLimiter;
	private: System::Windows::Forms::PictureBox^  pbLimiter;
	private: System::Windows::Forms::Button^  bIntegration;
	private: System::Windows::Forms::Button^  bDelLimiter;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(NormIntegrForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tvKarts = (gcnew System::Windows::Forms::TreeView());
			this->bAddLimiter = (gcnew System::Windows::Forms::Button());
			this->pbLimiter = (gcnew System::Windows::Forms::PictureBox());
			this->bIntegration = (gcnew System::Windows::Forms::Button());
			this->bDelLimiter = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbLimiter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(27, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Сборники нормативов времени:";
			// 
			// tvKarts
			// 
			this->tvKarts->CheckBoxes = true;
			this->tvKarts->Location = System::Drawing::Point(30, 50);
			this->tvKarts->Name = L"tvKarts";
			this->tvKarts->Size = System::Drawing::Size(475, 306);
			this->tvKarts->TabIndex = 1;
			this->tvKarts->BeforeExpand += gcnew System::Windows::Forms::TreeViewCancelEventHandler(this, &NormIntegrForm::tvKarts_BeforeExpand);
			// 
			// bAddLimiter
			// 
			this->bAddLimiter->Location = System::Drawing::Point(550, 248);
			this->bAddLimiter->Name = L"bAddLimiter";
			this->bAddLimiter->Size = System::Drawing::Size(95, 41);
			this->bAddLimiter->TabIndex = 2;
			this->bAddLimiter->Text = L"Добавить ограничитель";
			this->bAddLimiter->UseVisualStyleBackColor = true;
			this->bAddLimiter->Click += gcnew System::EventHandler(this, &NormIntegrForm::bAddLimiter_Click);
			// 
			// pbLimiter
			// 
			this->pbLimiter->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pbLimiter->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbLimiter.Image")));
			this->pbLimiter->Location = System::Drawing::Point(521, 257);
			this->pbLimiter->Name = L"pbLimiter";
			this->pbLimiter->Size = System::Drawing::Size(23, 23);
			this->pbLimiter->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pbLimiter->TabIndex = 3;
			this->pbLimiter->TabStop = false;
			this->pbLimiter->Visible = false;
			// 
			// bIntegration
			// 
			this->bIntegration->Location = System::Drawing::Point(584, 319);
			this->bIntegration->Name = L"bIntegration";
			this->bIntegration->Size = System::Drawing::Size(103, 37);
			this->bIntegration->TabIndex = 4;
			this->bIntegration->Text = L"Произвести интеграцию";
			this->bIntegration->UseVisualStyleBackColor = true;
			this->bIntegration->Click += gcnew System::EventHandler(this, &NormIntegrForm::bIntegration_Click);
			// 
			// bDelLimiter
			// 
			this->bDelLimiter->Enabled = false;
			this->bDelLimiter->Location = System::Drawing::Point(661, 248);
			this->bDelLimiter->Name = L"bDelLimiter";
			this->bDelLimiter->Size = System::Drawing::Size(91, 41);
			this->bDelLimiter->TabIndex = 5;
			this->bDelLimiter->Text = L"Убрать ограничитель";
			this->bDelLimiter->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(521, 257);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(23, 23);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// NormIntegrForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(764, 383);
			this->Controls->Add(this->bDelLimiter);
			this->Controls->Add(this->bIntegration);
			this->Controls->Add(this->pbLimiter);
			this->Controls->Add(this->bAddLimiter);
			this->Controls->Add(this->tvKarts);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"NormIntegrForm";
			this->Text = L"Интеграция справочников нормативов работ";
			this->Load += gcnew System::EventHandler(this, &NormIntegrForm::NormIntegrForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbLimiter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Semantic^ _sem;
		ExcelClass^ _xls;

		void SetKarts()
		{
			_sem = gcnew Semantic("SysAdmin", "111");
			Dictionary<String^, String^>^ dict = _sem->GetKarts();
            int i = 0;
            for each (KeyValuePair<String^, String^>^ pair in dict)
            {
                tvKarts->Nodes->Add(pair->Key, pair->Value);
                tvKarts->Nodes[i++]->Nodes->Add("");
            }
			
		}

	private: System::Void NormIntegrForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 SetKarts();
			 }


private: System::Void bAddLimiter_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 _xls = gcnew ExcelClass();
			OpenFileDialog^ dialog = gcnew OpenFileDialog();
			dialog->Multiselect = false;
			dialog->ShowDialog();

			if (dialog->FileName == nullptr)
			{
				return;
			}
			_xls->OpenDocument(dialog->FileName, false);
			String^ s = _xls->GetCellStringValue(0,0);
		 }

private: System::Void tvKarts_BeforeExpand(System::Object^  sender, System::Windows::Forms::TreeViewCancelEventArgs^  e) 
		 {
			 if (e->Node->Nodes[0]->Text == "")
            {
                e->Node->Nodes->Clear();
                Dictionary<String^, String^>^ dict = _sem->GetChilds(e->Node->Name);
                int i = 0;
                for each (KeyValuePair<String^, String^>^ pair in dict)
                {
                    e->Node->Nodes->Add(pair->Key, pair->Value);
                    if (e->Node->Level != 3)
                    {
                        e->Node->Nodes[i++]->Nodes->Add("");
                    }
                }
            }
		 }
private: System::Void bIntegration_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			String^ useType = _sem->GetAttr(tvKarts->SelectedNode->Name, "USE_TYPE");
            TreeNode^ cardNode = tvKarts->SelectedNode->Parent;
            String^ cardSNum = _sem->GetAttr(cardNode->Name, "NUM");
            String^ cardName = _sem->GetAttr(cardNode->Name, "NAME");
            if (String::IsNullOrEmpty(useType) || Int32::Parse(useType) != 1)
	        {
		        MessageBox::Show(cardSNum + cardName + " не соответствует условиям выгрузки!");
                return;
	        }
            String^ flexTableName = _sem->GetAttr(tvKarts->SelectedNode->Name, "VAR_NAME");
            String^ tableType = _sem->GetAttr(tvKarts->SelectedNode->Name, "TABLE_TYPE");
            String^ namePar1 = _sem->GetAttr(tvKarts->SelectedNode->Name, "NAME1");
            String^ namePar2 = _sem->GetAttr(tvKarts->SelectedNode->Name, "NAME2");
            String^ namePar3 = _sem->GetAttr(tvKarts->SelectedNode->Name, "NAME3");
            String^ namePar4 = _sem->GetAttr(tvKarts->SelectedNode->Name, "NAME4");
            String^ cordPar1 = _sem->GetAttr(tvKarts->SelectedNode->Name, "CORD1");
            String^ cordPar2 = _sem->GetAttr(tvKarts->SelectedNode->Name, "CORD2");
            String^ cordPar3 = _sem->GetAttr(tvKarts->SelectedNode->Name, "CORD3");
            String^ cordPar4 = _sem->GetAttr(tvKarts->SelectedNode->Name, "CORD4");

            TreeNode^ paramNode = cardNode->Parent;
            String^ numSborn = _sem->GetAttr(paramNode->Name, "VAR_NAME");

            array<String^>^ arr = cardSNum->Split(' ', '.');
            String^ cardCode = String::Format("{0}-{1}-{2}", numSborn, arr[1], flexTableName);
		 }
};
}
