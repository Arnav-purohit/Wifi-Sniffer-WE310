#pragma once
#include <iostream>
#include <algorithm>
#include <string.h>
#include <windows.h>
#include "WiresharkIf.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::IO::Ports;
using namespace System::Threading;
//using namespace std;

ref class DrvRecvThread
{
  
public:
    SerialPort^ io_handle;
    WiresharkIf^ wif;
    array<unsigned char>^ io_buffer;
    int offset;
    array<String^>^ channelList;
    DrvRecvThread(SerialPort^ drv, WiresharkIf^ wireshark)
    {
        io_handle = drv;
        wif = wireshark;
        io_buffer = gcnew array<unsigned char>(4096);
    }
    char AsciiToBin(char s)
    {
        char r;
        if (s >= '0' && s <= '9')
        {
            r = s - '0';
        }
        else if (s >= 'A' && s <= 'F')
        {
            r = s - 'A' + 10;
        }
        else if (s >= 'a' && s <= 'f')
        {
            r = s - 'a' + 10;
        }
        return r;
    }
    void DrvRead()
    {   
        wif->ConnectWe310Wireshrk();
        while (1)
        {            
            int len = io_handle->Read( io_buffer, offset, 4096 - offset - 1 );
            if (len)
            {
                io_buffer[len + offset] = '\0';
                
                String^ data = System::Text::Encoding::Default->GetString(io_buffer);
                int s = data->IndexOf("+WPROMISCCMD:"); 
                
                if (s >= 0)// strlen("+WPROMISCCMD:");
                {
                    s += 13;
                    int e = data->IndexOf("\r\n", s);

                    if (e > 0)
                    {//Convert the char to bin and send to wireshark
                        char widata[1600];
                        int i = 0;
                        for (int j = 0; j < (e - s); j++)
                        {
                            widata[i] = AsciiToBin(io_buffer[s + j]);
                            widata[i] <<= 4; j++;
                            widata[i] |= AsciiToBin(io_buffer[s + j]);
                            i++;
                        }
                        wif->write(widata, (e - s) / 2);

                        /* Check how much data is left, copy that to begining and
                        update the offset */
                        if (len > ( e ))
                        { // Move the data to tbe begining
                            int l = len - e;
                            i = (l > 2) ? i - 2 : 0;
                            System::Array::Copy(io_buffer, e + 2, io_buffer, 0, l);
                            offset = l;
                        }
                        else offset = 0;
                    }
                    else offset += len;
                }
                else offset += len;
                
            }
        }
    }
};

ref class WE310If
{
public:
    array <String^>^ channelList;
    WiresharkIf^ wif;
    SerialPort^ DrvHandle;
    int status = 0;
public:
    WE310If(String^ port, WiresharkIf^ wireshark )
    {
        wif = wireshark;
        DrvHandle = gcnew SerialPort();
        DrvHandle->PortName = port;
        DrvHandle->BaudRate = 115200;
        DrvHandle->Parity = Parity::None;
        DrvHandle->DataBits = 8;
        DrvHandle->StopBits = StopBits::One;
        DrvHandle->Handshake = Handshake::None;
        try
        {
            DrvHandle->Open();
        }
        catch (...)
        {
            MessageBox::Show("Cannot Open selected COM port");
            status = -1;
            return;
        };
        
        WE310Init(port);
    }
    ~WE310If(void)
    {
        DrvHandle->Close();
    }
private:
    int WE310Init(String^ port)
    {   
        String^ connectMsg;
        String^ receivedData;
        /*
        Reset the module to start it fresh
        */
        String^ command;
#if 0        
        command = "AT+YSR";
        DrvHandle->WriteLine(command);
        Thread::Sleep(500);
        receivedData = DrvHandle->ReadExisting();
        if (receivedData->IndexOf("OK") < 0)
        {
            DrvHandle->Close();
            MessageBox::Show("Issue in connecting to module");
            status = -1;
            return -1;
        }
#endif
        /*
        Disable echo by giving ATE0 command
        */
        command = "ATE0";
        DrvHandle->WriteLine(command);
        Thread::Sleep(2500);
        receivedData = DrvHandle->ReadExisting();
        if (receivedData->IndexOf("OK") < 0)
        {
            DrvHandle->Close();
            MessageBox::Show("Issue in connecting to module");
            status = -2;
            return -1;
        }
        /** Check the device type G4 or F5 
        **
        - Issue AT+CGMM
        - If the response is "WE310G4" or "WE310F5"
        - if "WE310F5" then channel list will be 1 to 14
        - if "WE310G4" then channel list will be 
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 36, 40, 44, 48, 52, 56, 60,
            64, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 144, 149, 153, 157,
            161, 165
        */
        command = "AT+CGMM";
        DrvHandle->WriteLine(command);
        Thread::Sleep(500);
        receivedData = DrvHandle->ReadExisting();
        int i;
        int prefixLength = 7;
        if( receivedData->IndexOf( "WE310G4") >= 0 )
        {
            channelList = gcnew array<String^>{ "1","2","3","4","5","6","7","8","9","10","11","12","13","14","36","40", "44", "48", "52", "56", "60",
                "64", "100", "104", "108", "112", "116", "120", "124", "128", "132", "136", "140", "144", "149", "153", "157", "161", "165" };;

            connectMsg = "WE310G4 Module used as Sniffer";
        }
        else if( receivedData->IndexOf("WE310F5"))
        {
            channelList = gcnew array<String^>{ "1","2","3","4","5","6","7","8","9","10","11","12","13","14" };                
            connectMsg = "WE310F5 Module used as Sniffer";
        }
        else
        {
            DrvHandle->Close();
            MessageBox::Show("Issue in connecting to module");
            status = -3;
            return -1;
        }
        
        /* Issue command AT+WNI command
        */
        command = "AT+WNI=0";
        DrvHandle->WriteLine(command);
        Thread::Sleep(500);
        receivedData = DrvHandle->ReadExisting();
        if (receivedData->IndexOf("OK") < 0)
        {
            DrvHandle->Close();
            MessageBox::Show("Issue in connecting to module");
            status = -4;
            return -1;
        }
        else
        {
            connectMsg += "\r\nDevice is ready to act as Sniffer";
            MessageBox::Show(connectMsg);
        }
        return 0;
    }
public:
    int Config(String^ channel, String^ SrcAddr, String^ DstAddr, String^ frmType, String^ frmSubType)
    {

        /* Issue command AT+WPROMISCSETFILTER         
        */
        String^ command = "AT+WPROMISCSETFILTER=1,1," + channel;
        DrvHandle->WriteLine(command);
        Thread::Sleep(500);
        String^ receivedData = DrvHandle->ReadExisting();
        return 0;
    }
    int Start(void)
    {
        DrvRecvThread^ th = gcnew DrvRecvThread(DrvHandle, wif);
        Thread^ iothread = gcnew Thread(gcnew ThreadStart(th, &DrvRecvThread::DrvRead));
        iothread->Name = "iothread";
        iothread->Start();
        /*
        Issue command AT+WPROMISCCMD
        */
        String^ command = "AT+WPROMISCCMD=1,1,1";
        DrvHandle->WriteLine(command);
        return 0;
    }
};

