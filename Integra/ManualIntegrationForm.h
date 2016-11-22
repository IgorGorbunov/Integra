#pragma once

namespace Integra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ManualIntegrationForm
	/// </summary>
	public ref class ManualIntegrationForm : public System::Windows::Forms::Form
	{
	public:
		ManualIntegrationForm(void)
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
		~ManualIntegrationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dgvPositions;
	protected: 

	protected: 

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
			this->dgvPositions = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvPositions))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvPositions
			// 
			this->dgvPositions->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvPositions->Location = System::Drawing::Point(12, 12);
			this->dgvPositions->Name = L"dgvPositions";
			this->dgvPositions->Size = System::Drawing::Size(581, 257);
			this->dgvPositions->TabIndex = 0;
			// 
			// ManualIntegrationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(605, 281);
			this->Controls->Add(this->dgvPositions);
			this->Name = L"ManualIntegrationForm";
			this->Text = L"Ручная интеграция";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvPositions))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
