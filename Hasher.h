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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox1;


	private: System::ComponentModel::IContainer^ components;

	protected:

	private:


#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->AllowDrop = true;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"MD2", L"MD4", L"MD5", L"SHA1", L"SHA256", L"SHA384",
					L"SHA512"
			});
			this->comboBox1->Location = System::Drawing::Point(717, 88);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(92, 24);
			this->comboBox1->TabIndex = 23;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &HashMain::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(568, 136);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 31);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Generate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &HashMain::Generate_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(717, 136);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(92, 31);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Reset";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &HashMain::Reset_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(565, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 17);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Select Hash Type:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(356, 81);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(92, 24);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Choose File";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &HashMain::ChooseFile_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(76, 114);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(372, 70);
			this->textBox2->TabIndex = 15;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(73, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(241, 17);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Choose file to generate the Hash for:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(76, 287);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(788, 43);
			this->textBox1->TabIndex = 17;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(71, 243);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(432, 28);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Hash for the selected file :";
			// 
			// HashMain
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(964, 422);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"HashMain";
			this->Text = L"Hasher";
			this->Load += gcnew System::EventHandler(this, &HashMain::HashMain_Load);
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
		String^ GetStr(string input)
		{	
			String^ retval = gcnew String(input.c_str());
			return retval;
		}
	private: System::Void HashMain_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		this->comboBox1->SelectedIndex = -1;
		this->comboBox1->Text = "";
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
		this->comboBox1->SelectedIndex = -1;
		this->comboBox1->Text = "";
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
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		Strtostr(this->comboBox1->GetItemText(this->comboBox1->SelectedItem),hash); ishashchosen = true;
	}
};
}
