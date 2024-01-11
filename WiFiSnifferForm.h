#pragma once
#include "CfgForm.h"
#include "WiresharkIf.h"
#include "WE310If.h"

namespace WiFiSniffer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for WiFiSnifferForm
	/// </summary>
	public ref class WiFiSnifferForm : public System::Windows::Forms::Form
	{
	public:
        WiresharkIf^ wif;
    
    public:
    
        WE310If^ we310;
		WiFiSnifferForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
            StopButton->Enabled = false;
            StartButton->Enabled = false;
            CfgButton->Enabled = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WiFiSnifferForm()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Label^  COMPortLabel;
    protected:
    private: System::Windows::Forms::ComboBox^  COMPortComboBox;
    private: System::Windows::Forms::Button^  ConnectButton;
    private: System::Windows::Forms::Button^  StopButton;
    private: System::Windows::Forms::Button^  StartButton;
    private: System::Windows::Forms::Button^  CfgButton;
    private: System::ComponentModel::IContainer^  components;
    private: System::Windows::Forms::ContextMenuStrip^  HelpMenuStrip;

    private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(WiFiSnifferForm::typeid));
            this->COMPortLabel = (gcnew System::Windows::Forms::Label());
            this->COMPortComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->ConnectButton = (gcnew System::Windows::Forms::Button());
            this->StopButton = (gcnew System::Windows::Forms::Button());
            this->StartButton = (gcnew System::Windows::Forms::Button());
            this->CfgButton = (gcnew System::Windows::Forms::Button());
            this->HelpMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
            this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->HelpMenuStrip->SuspendLayout();
            this->SuspendLayout();
            // 
            // COMPortLabel
            // 
            this->COMPortLabel->AutoSize = true;
            this->COMPortLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->COMPortLabel->Location = System::Drawing::Point(13, 24);
            this->COMPortLabel->Name = L"COMPortLabel";
            this->COMPortLabel->Size = System::Drawing::Size(145, 23);
            this->COMPortLabel->TabIndex = 0;
            this->COMPortLabel->Text = L"Select COM Port";
            // 
            // COMPortComboBox
            // 
            this->COMPortComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->COMPortComboBox->FormattingEnabled = true;
            this->COMPortComboBox->Location = System::Drawing::Point(188, 20);
            this->COMPortComboBox->Name = L"COMPortComboBox";
            this->COMPortComboBox->Size = System::Drawing::Size(121, 31);
            this->COMPortComboBox->TabIndex = 1;
            this->COMPortComboBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &WiFiSnifferForm::COMPortComboBox_MouseClicked);
            // 
            // ConnectButton
            // 
            this->ConnectButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->ConnectButton->Location = System::Drawing::Point(339, 17);
            this->ConnectButton->Name = L"ConnectButton";
            this->ConnectButton->Size = System::Drawing::Size(97, 39);
            this->ConnectButton->TabIndex = 2;
            this->ConnectButton->Text = L"Connect";
            this->ConnectButton->UseVisualStyleBackColor = true;
            this->ConnectButton->Click += gcnew System::EventHandler(this, &WiFiSnifferForm::ConnectButton_Click);
            // 
            // StopButton
            // 
            this->StopButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->StopButton->Location = System::Drawing::Point(217, 112);
            this->StopButton->Name = L"StopButton";
            this->StopButton->Size = System::Drawing::Size(92, 43);
            this->StopButton->TabIndex = 3;
            this->StopButton->Text = L"Stop";
            this->StopButton->UseVisualStyleBackColor = true;
            this->StopButton->Click += gcnew System::EventHandler(this, &WiFiSnifferForm::StopButton_Click);
            // 
            // StartButton
            // 
            this->StartButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->StartButton->Location = System::Drawing::Point(339, 112);
            this->StartButton->Name = L"StartButton";
            this->StartButton->Size = System::Drawing::Size(97, 43);
            this->StartButton->TabIndex = 4;
            this->StartButton->Text = L"Start";
            this->StartButton->UseVisualStyleBackColor = true;
            this->StartButton->Click += gcnew System::EventHandler(this, &WiFiSnifferForm::StartButton_Click);
            // 
            // CfgButton
            // 
            this->CfgButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->CfgButton->Location = System::Drawing::Point(17, 112);
            this->CfgButton->Name = L"CfgButton";
            this->CfgButton->Size = System::Drawing::Size(141, 43);
            this->CfgButton->TabIndex = 5;
            this->CfgButton->Text = L"Configure";
            this->CfgButton->UseVisualStyleBackColor = true;
            this->CfgButton->Click += gcnew System::EventHandler(this, &WiFiSnifferForm::CfgButton_Click);
            // 
            // HelpMenuStrip
            // 
            this->HelpMenuStrip->ImageScalingSize = System::Drawing::Size(20, 20);
            this->HelpMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                this->helpToolStripMenuItem,
                    this->aboutToolStripMenuItem
            });
            this->HelpMenuStrip->Name = L"ContextMenuStrip";
            this->HelpMenuStrip->Size = System::Drawing::Size(120, 52);
            // 
            // helpToolStripMenuItem
            // 
            this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
            this->helpToolStripMenuItem->Size = System::Drawing::Size(119, 24);
            this->helpToolStripMenuItem->Text = L"Help";
            this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &WiFiSnifferForm::helpToolStripMenuItem_Click);
            // 
            // aboutToolStripMenuItem
            // 
            this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
            this->aboutToolStripMenuItem->Size = System::Drawing::Size(119, 24);
            this->aboutToolStripMenuItem->Text = L"About";
            this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &WiFiSnifferForm::aboutToolStripMenuItem_Click);
            // 
            // WiFiSnifferForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(467, 167);
            this->ContextMenuStrip = this->HelpMenuStrip;
            this->Controls->Add(this->CfgButton);
            this->Controls->Add(this->StartButton);
            this->Controls->Add(this->StopButton);
            this->Controls->Add(this->ConnectButton);
            this->Controls->Add(this->COMPortComboBox);
            this->Controls->Add(this->COMPortLabel);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->Name = L"WiFiSnifferForm";
            this->Text = L"WiFi Sniffer";
            this->HelpMenuStrip->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void COMPortComboBox_MouseClicked(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
        array<Object^>^ objectArray;
        this->COMPortComboBox->Items->Clear();
        objectArray = IO::Ports::SerialPort::GetPortNames();
        this->COMPortComboBox->Items->AddRange(objectArray);
        if (this->COMPortComboBox->Items->Count > 0)
            this->COMPortComboBox->SelectedIndex = 0;
    }
    private: System::Void ConnectButton_Click(System::Object^  sender, System::EventArgs^  e) {
        wif = gcnew WiresharkIf();
        we310 = gcnew WE310If(this->COMPortComboBox->Text, wif);
        if (we310->status == 0)
        {
            ConnectButton->Enabled = false; 
            StopButton->Enabled = false;
            StartButton->Enabled = false;
            CfgButton->Enabled = true;
        }
        else
        {
            wif = nullptr;
            we310 = nullptr;
        }
    }
    private: System::Void StartButton_Click(System::Object^  sender, System::EventArgs^  e) {
        wif->open();
        we310->Start();
        wif->ConnectWe310Wireshrk();
        wif = nullptr;
        we310 = nullptr;
    }
    private: System::Void StopButton_Click(System::Object^  sender, System::EventArgs^  e) {
        ConnectButton->Enabled = true;
        CfgButton->Enabled = false;
        StopButton->Enabled = false;
        StartButton->Enabled = false;
    }
    private: System::Void CfgButton_Click(System::Object^  sender, System::EventArgs^  e) {
        CfgForm^ Cfg = gcnew CfgForm(we310);
        Cfg->ShowDialog();
        if (Cfg->status)
        {
            we310->Config(Cfg->channel, Cfg->SrcAddr, Cfg->DstAddr, Cfg->frmType, Cfg->frmSubType);
            StopButton->Enabled = true;
            StartButton->Enabled = true;
            CfgButton->Enabled = false;
        }
    }
    private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
    }
    private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
        MessageBox::Show("Wi-Fi Sniffer Version 0.1-B001\r\nCopywrite @ Telit Cinterion");
    }
};
}
