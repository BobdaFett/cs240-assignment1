#pragma once

#include "atm.h"
using namespace atm;

namespace CS240Assignment1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ATM Interface for manipulation of ATM objects.
	/// </summary>
	public ref class atmForm : public System::Windows::Forms::Form
	{
	public:
		atmForm(void) {
			InitializeComponent();
			current_atm.set_state(state::START);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~atmForm() {
			if (components) {
				delete components;
			}
		}
	private:
#pragma region WinForm Designer Generated Code
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Button^ button6;
		System::Windows::Forms::Button^ button7;
		System::Windows::Forms::Button^ button8;
		System::Windows::Forms::Button^ button9;
		System::Windows::Forms::Button^ button10;
		System::Windows::Forms::Button^ buttonDot;
		System::Windows::Forms::Button^ buttonClear;
		System::Windows::Forms::Button^ buttonA;
		System::Windows::Forms::Button^ buttonB;
		System::Windows::Forms::Button^ buttonC;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox2;
#pragma endregion

		// ATM object field.
		ATM current_atm{};  // ATM state will always be state::START

		void numButtonClick(System::Object^ o, System::EventArgs^ e);
		void buttonA_Event();
		void buttonB_Event();
		void buttonC_Event();
		void change_formState();

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->buttonDot = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->buttonA = (gcnew System::Windows::Forms::Button());
			this->buttonB = (gcnew System::Windows::Forms::Button());
			this->buttonC = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(56, 49);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(46, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(104, 49);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(46, 32);
			this->button2->TabIndex = 1;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(153, 49);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(46, 32);
			this->button3->TabIndex = 2;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(56, 84);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(46, 32);
			this->button4->TabIndex = 3;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(104, 84);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(46, 32);
			this->button5->TabIndex = 4;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(153, 84);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(46, 32);
			this->button6->TabIndex = 5;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(56, 120);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(46, 32);
			this->button7->TabIndex = 6;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(104, 120);
			this->button8->Margin = System::Windows::Forms::Padding(2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(46, 32);
			this->button8->TabIndex = 7;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(153, 120);
			this->button9->Margin = System::Windows::Forms::Padding(2);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(46, 32);
			this->button9->TabIndex = 8;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(56, 155);
			this->button10->Margin = System::Windows::Forms::Padding(2);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(46, 32);
			this->button10->TabIndex = 9;
			this->button10->Text = L"0";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// buttonDot
			// 
			this->buttonDot->Location = System::Drawing::Point(104, 155);
			this->buttonDot->Margin = System::Windows::Forms::Padding(2);
			this->buttonDot->Name = L"buttonDot";
			this->buttonDot->Size = System::Drawing::Size(46, 32);
			this->buttonDot->TabIndex = 10;
			this->buttonDot->Text = L".";
			this->buttonDot->UseVisualStyleBackColor = true;
			this->buttonDot->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(153, 155);
			this->buttonClear->Margin = System::Windows::Forms::Padding(2);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(46, 32);
			this->buttonClear->TabIndex = 11;
			this->buttonClear->Text = L"CE";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// textBox1
			// 
			this->textBox1->AcceptsReturn = true;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(56, 21);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->MaxLength = 15;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(142, 16);
			this->textBox1->TabIndex = 12;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(26, 205);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(212, 51);
			this->textBox2->TabIndex = 13;
			this->textBox2->Text = L"Enter customer number and press OK.";
			// 
			// buttonA
			// 
			this->buttonA->Location = System::Drawing::Point(95, 265);
			this->buttonA->Margin = System::Windows::Forms::Padding(2);
			this->buttonA->Name = L"buttonA";
			this->buttonA->Size = System::Drawing::Size(64, 34);
			this->buttonA->TabIndex = 14;
			this->buttonA->Text = L"OK";
			this->buttonA->UseVisualStyleBackColor = true;
			this->buttonA->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// buttonB
			// 
			this->buttonB->Location = System::Drawing::Point(95, 302);
			this->buttonB->Margin = System::Windows::Forms::Padding(2);
			this->buttonB->Name = L"buttonB";
			this->buttonB->Size = System::Drawing::Size(64, 34);
			this->buttonB->TabIndex = 15;
			this->buttonB->UseVisualStyleBackColor = true;
			this->buttonB->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// buttonC
			// 
			this->buttonC->Location = System::Drawing::Point(95, 339);
			this->buttonC->Margin = System::Windows::Forms::Padding(2);
			this->buttonC->Name = L"buttonC";
			this->buttonC->Size = System::Drawing::Size(64, 34);
			this->buttonC->TabIndex = 16;
			this->buttonC->Text = L"Exit";
			this->buttonC->UseVisualStyleBackColor = true;
			this->buttonC->Click += gcnew System::EventHandler(this, &atmForm::numButtonClick);
			// 
			// atmForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(263, 392);
			this->Controls->Add(this->buttonC);
			this->Controls->Add(this->buttonB);
			this->Controls->Add(this->buttonA);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->buttonDot);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"atmForm";
			this->Text = L"atmForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}
