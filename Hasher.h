#include "CommandOps.h"
#pragma once


namespace HASHER 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Security;
	using namespace System::IO;
	using namespace std;
	bool filechosen ,ishashchosen;
	string hash, filename;
	public ref class HashMain : public System::Windows::Forms::Form
	{
	public:
		HashMain(void)
		{
			InitializeComponent();
		}

	protected:
		~HashMain()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::RadioButton^ radioButton6;
	private: System::Windows::Forms::RadioButton^ radioButton7;


	private: System::ComponentModel::IContainer^ components;

	protected:

	private:


#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(629, 262);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 39);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Generate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &HashMain::Generate_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(796, 262);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(104, 39);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Reset";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &HashMain::Reset_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(606, 206);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(68, 24);
			this->radioButton1->TabIndex = 8;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"MD5";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &HashMain::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(726, 176);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(95, 24);
			this->radioButton2->TabIndex = 9;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"SHA256";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &HashMain::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(726, 143);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(77, 24);
			this->radioButton3->TabIndex = 10;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"SHA1";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &HashMain::radioButton3_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(707, 111);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(138, 20);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Select Hash Type:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(400, 101);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(104, 30);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Choose File";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &HashMain::ChooseFile_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(86, 143);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(418, 87);
			this->textBox2->TabIndex = 15;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(82, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(270, 20);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Choose file to generate the Hash for:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(86, 359);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(886, 53);
			this->textBox1->TabIndex = 17;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(80, 304);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(486, 35);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Hash for the selected file :";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(726, 206);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(95, 24);
			this->radioButton4->TabIndex = 19;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"SHA384";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &HashMain::radioButton4_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(606, 144);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(68, 24);
			this->radioButton5->TabIndex = 20;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"MD2";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &HashMain::radioButton5_CheckedChanged);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(606, 176);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(68, 24);
			this->radioButton6->TabIndex = 21;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"MD4";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &HashMain::radioButton6_CheckedChanged);
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Location = System::Drawing::Point(846, 144);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(95, 24);
			this->radioButton7->TabIndex = 22;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"SHA512";
			this->radioButton7->UseVisualStyleBackColor = true;
			this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &HashMain::radioButton7_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1085, 528);
			this->Controls->Add(this->radioButton7);
			this->Controls->Add(this->radioButton6);
			this->Controls->Add(this->radioButton5);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Hasher";
			this->Text = L"Hasher";
			this->Load += gcnew System::EventHandler(this, &HashMain::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void Strtostr(String^ s, string& os)
		{
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
	private: String^ GetStr(string input)
	{
		String^ retval = gcnew String(input.c_str());
		return retval;
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		this->radioButton1->Checked = false;
		this->radioButton2->Checked = false;
		this->radioButton3->Checked = false;
		this->radioButton4->Checked = false;
		this->radioButton5->Checked = false;
		this->radioButton6->Checked = false;
		this->radioButton7->Checked = false;
		filechosen = ishashchosen = false;
	}
	private: System::Void Generate_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (ishashchosen && filechosen)
		{
			this->textBox1->Text = GetStr(GetHashofFile('\"'+filename+"\" "+hash));
		}
		else if(!ishashchosen && !filechosen)
			this->textBox1->Text = "Please choose Hashtype and the file to generate hash for.";
		else if(!filechosen)
			this->textBox1->Text = "Please choose the file to generate hash for.";
		else if(!ishashchosen)
			this->textBox1->Text = "Please choose HashType.";
	}
	private: System::Void Reset_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->radioButton1->Checked = false;
		this->radioButton2->Checked = false;
		this->radioButton3->Checked = false;
		this->radioButton4->Checked = false;
		this->radioButton5->Checked = false;
		this->radioButton6->Checked = false;
		this->radioButton7->Checked = false;
		ishashchosen = false;
		filechosen = false;
		this->textBox1->Text = L"";
		this->textBox2->Text = L"";
	}
	private: System::Void ChooseFile_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->textBox1->Text = L"";
		openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->ShowDialog();
		if (openFileDialog1->FileName != "")
		{
			String^ temp = openFileDialog1->FileName;
			filechosen = true;
			for (int i = 0; i < temp->Length; i++)
			{
				if (temp[i] == '\\')
					temp = temp->Insert(i++,"\\");
			}
			this->textBox2->Text = temp;
			Strtostr(temp, filename);
		}
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{		
		hash = "MD5"; this->textBox1->Text = L""; ishashchosen = true;
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{ 
		hash = "SHA256";this->textBox1->Text = L"";	ishashchosen = true;
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		hash = "SHA1";this->textBox1->Text = L"";	ishashchosen = true;
	}
	private: System::Void radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		hash = "MD2"; this->textBox1->Text = L"";	ishashchosen = true;
	}
	private: System::Void radioButton6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		hash = "MD4";this->textBox1->Text = L"";	ishashchosen = true;
	}
	private: System::Void radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		hash = "SHA384"; this->textBox1->Text = L"";	ishashchosen = true;
	}
	private: System::Void radioButton7_CheckedChanged(System::Object^ sender, System::EventArgs^ e)		
	{
		hash = "SHA512"; this->textBox1->Text = L"";	ishashchosen = true;
	}
};
}
