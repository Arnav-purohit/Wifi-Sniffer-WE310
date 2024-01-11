#pragma once
#include "WE310If.h"
namespace WiFiSniffer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CfgForm
	/// </summary>
	public ref class CfgForm : public System::Windows::Forms::Form
	{
	public:
        String^ channel;
        String^ SrcAddr;
        String^ DstAddr;
        String^ frmType;
        String^ frmSubType;
        WE310If^ we310;
        int status;
		CfgForm(WE310If^ we)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
            we310 = we;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CfgForm()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Label^  ChannelLabel;
    protected:
    private: System::Windows::Forms::ComboBox^  ChannelComboBox;
    private: System::Windows::Forms::Label^  SrcAddrLabel;
    private: System::Windows::Forms::TextBox^  SrcAddrTextBox;
    private: System::Windows::Forms::TextBox^  DstAddrTextBox;
    private: System::Windows::Forms::Label^  DstAddrLabel;
    private: System::Windows::Forms::ComboBox^  FrmTypeComboBox;
    private: System::Windows::Forms::Label^  FrmTypeLabel;
    private: System::Windows::Forms::ComboBox^  FrmSubTypeComboBox;
    private: System::Windows::Forms::Label^  FrmSubTypeLabel;
    private: System::Windows::Forms::Button^  OkButton;
    private: System::Windows::Forms::Button^  CancelLutton;

	private:
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
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CfgForm::typeid));
            this->ChannelLabel = (gcnew System::Windows::Forms::Label());
            this->ChannelComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->SrcAddrLabel = (gcnew System::Windows::Forms::Label());
            this->SrcAddrTextBox = (gcnew System::Windows::Forms::TextBox());
            this->DstAddrTextBox = (gcnew System::Windows::Forms::TextBox());
            this->DstAddrLabel = (gcnew System::Windows::Forms::Label());
            this->FrmTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->FrmTypeLabel = (gcnew System::Windows::Forms::Label());
            this->FrmSubTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->FrmSubTypeLabel = (gcnew System::Windows::Forms::Label());
            this->OkButton = (gcnew System::Windows::Forms::Button());
            this->CancelLutton = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // ChannelLabel
            // 
            this->ChannelLabel->AutoSize = true;
            this->ChannelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->ChannelLabel->Location = System::Drawing::Point(40, 43);
            this->ChannelLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->ChannelLabel->Name = L"ChannelLabel";
            this->ChannelLabel->Size = System::Drawing::Size(75, 23);
            this->ChannelLabel->TabIndex = 0;
            this->ChannelLabel->Text = L"Channel";
            // 
            // ChannelComboBox
            // 
            this->ChannelComboBox->FormattingEnabled = true;
            this->ChannelComboBox->Location = System::Drawing::Point(284, 43);
            this->ChannelComboBox->Margin = System::Windows::Forms::Padding(4);
            this->ChannelComboBox->Name = L"ChannelComboBox";
            this->ChannelComboBox->Size = System::Drawing::Size(265, 24);
            this->ChannelComboBox->TabIndex = 1;            
            // 
            // SrcAddrLabel
            // 
            this->SrcAddrLabel->AutoSize = true;
            this->SrcAddrLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->SrcAddrLabel->Location = System::Drawing::Point(40, 90);
            this->SrcAddrLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->SrcAddrLabel->Name = L"SrcAddrLabel";
            this->SrcAddrLabel->Size = System::Drawing::Size(182, 23);
            this->SrcAddrLabel->TabIndex = 2;
            this->SrcAddrLabel->Text = L"Source MAC Address";
            // 
            // SrcAddrTextBox
            // 
            this->SrcAddrTextBox->Location = System::Drawing::Point(284, 90);
            this->SrcAddrTextBox->Margin = System::Windows::Forms::Padding(4);
            this->SrcAddrTextBox->Name = L"SrcAddrTextBox";
            this->SrcAddrTextBox->Size = System::Drawing::Size(265, 22);
            this->SrcAddrTextBox->TabIndex = 3;
            // 
            // DstAddrTextBox
            // 
            this->DstAddrTextBox->Location = System::Drawing::Point(284, 137);
            this->DstAddrTextBox->Margin = System::Windows::Forms::Padding(4);
            this->DstAddrTextBox->Name = L"DstAddrTextBox";
            this->DstAddrTextBox->Size = System::Drawing::Size(265, 22);
            this->DstAddrTextBox->TabIndex = 5;
            // 
            // DstAddrLabel
            // 
            this->DstAddrLabel->AutoSize = true;
            this->DstAddrLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->DstAddrLabel->Location = System::Drawing::Point(40, 137);
            this->DstAddrLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->DstAddrLabel->Name = L"DstAddrLabel";
            this->DstAddrLabel->Size = System::Drawing::Size(219, 23);
            this->DstAddrLabel->TabIndex = 4;
            this->DstAddrLabel->Text = L"Destination MAC Address";
            // 
            // FrmTypeComboBox
            // 
            this->FrmTypeComboBox->FormattingEnabled = true;
            this->FrmTypeComboBox->Location = System::Drawing::Point(284, 188);
            this->FrmTypeComboBox->Margin = System::Windows::Forms::Padding(4);
            this->FrmTypeComboBox->Name = L"FrmTypeComboBox";
            this->FrmTypeComboBox->Size = System::Drawing::Size(265, 24);
            this->FrmTypeComboBox->TabIndex = 7;
            // 
            // FrmTypeLabel
            // 
            this->FrmTypeLabel->AutoSize = true;
            this->FrmTypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->FrmTypeLabel->Location = System::Drawing::Point(40, 188);
            this->FrmTypeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->FrmTypeLabel->Name = L"FrmTypeLabel";
            this->FrmTypeLabel->Size = System::Drawing::Size(105, 23);
            this->FrmTypeLabel->TabIndex = 6;
            this->FrmTypeLabel->Text = L"Frame Type";
            // 
            // FrmSubTypeComboBox
            // 
            this->FrmSubTypeComboBox->FormattingEnabled = true;
            this->FrmSubTypeComboBox->Location = System::Drawing::Point(284, 238);
            this->FrmSubTypeComboBox->Margin = System::Windows::Forms::Padding(4);
            this->FrmSubTypeComboBox->Name = L"FrmSubTypeComboBox";
            this->FrmSubTypeComboBox->Size = System::Drawing::Size(265, 24);
            this->FrmSubTypeComboBox->TabIndex = 9;
            // 
            // FrmSubTypeLabel
            // 
            this->FrmSubTypeLabel->AutoSize = true;
            this->FrmSubTypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->FrmSubTypeLabel->Location = System::Drawing::Point(40, 238);
            this->FrmSubTypeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->FrmSubTypeLabel->Name = L"FrmSubTypeLabel";
            this->FrmSubTypeLabel->Size = System::Drawing::Size(141, 23);
            this->FrmSubTypeLabel->TabIndex = 8;
            this->FrmSubTypeLabel->Text = L"Frame Sub Type";
            // 
            // OkButton
            // 
            this->OkButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->OkButton->Location = System::Drawing::Point(436, 294);
            this->OkButton->Margin = System::Windows::Forms::Padding(4);
            this->OkButton->Name = L"OkButton";
            this->OkButton->Size = System::Drawing::Size(115, 41);
            this->OkButton->TabIndex = 10;
            this->OkButton->Text = L"OK";
            this->OkButton->UseVisualStyleBackColor = true;
            this->OkButton->Click += gcnew System::EventHandler(this, &CfgForm::OkButton_Click);
            // 
            // CancelLutton
            // 
            this->CancelLutton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->CancelLutton->Location = System::Drawing::Point(284, 294);
            this->CancelLutton->Margin = System::Windows::Forms::Padding(4);
            this->CancelLutton->Name = L"CancelLutton";
            this->CancelLutton->Size = System::Drawing::Size(115, 41);
            this->CancelLutton->TabIndex = 11;
            this->CancelLutton->Text = L"Cancel";
            this->CancelLutton->UseVisualStyleBackColor = true;
            this->CancelLutton->Click += gcnew System::EventHandler(this, &CfgForm::CancelLutton_Click);
            // 
            // CfgForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(601, 350);
            this->Controls->Add(this->CancelLutton);
            this->Controls->Add(this->OkButton);
            this->Controls->Add(this->FrmSubTypeComboBox);
            this->Controls->Add(this->FrmSubTypeLabel);
            this->Controls->Add(this->FrmTypeComboBox);
            this->Controls->Add(this->FrmTypeLabel);
            this->Controls->Add(this->DstAddrTextBox);
            this->Controls->Add(this->DstAddrLabel);
            this->Controls->Add(this->SrcAddrTextBox);
            this->Controls->Add(this->SrcAddrLabel);
            this->Controls->Add(this->ChannelComboBox);
            this->Controls->Add(this->ChannelLabel);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(4);
            this->MaximizeBox = false;
            this->Name = L"CfgForm";
            this->Text = L"Sniffer Configuration";
            this->Load += gcnew System::EventHandler(this, &CfgForm::CfgForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void CancelLutton_Click(System::Object^  sender, System::EventArgs^  e) {
        this->status = 0;
        this->Close();
    }
    private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {
        this->status = 1;
        we310->Config(ChannelComboBox->Text,//SelectedItem->ToString(),
            SrcAddrTextBox->Text, DstAddrTextBox->Text, 
            ( FrmTypeComboBox->SelectedItem == nullptr ) ? nullptr : FrmTypeComboBox->SelectedItem->ToString(),
            ( FrmSubTypeComboBox->SelectedItem == nullptr ) ? nullptr : FrmSubTypeComboBox->SelectedItem->ToString());
        this->Close();
    }
    private: System::Void CfgForm_Load(System::Object^  sender, System::EventArgs^  e) {
        this->status = 0;
        ChannelComboBox->Items->AddRange(we310->channelList);
    }
};
}
