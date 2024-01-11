#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> // Add this header for fixed-size integer types
#include <windows.h>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;

// Global header structure
typedef struct pcap_hdr_s {
    uint32_t magic_number;   /* magic number */
    uint16_t version_major;  /* major version number */
    uint16_t version_minor;  /* minor version number */
    int32_t  thiszone;       /* GMT to local correction */
    uint32_t sigfigs;        /* accuracy of timestamps */
    uint32_t snaplen;        /* max length of captured packets, in octets */
    uint32_t network;        /* data link type */
} pcap_hdr_t;

// Packet header structure
typedef struct pcaprec_hdr_s {
    uint32_t ts_sec;         /* timestamp seconds */
    uint32_t ts_usec;        /* timestamp microseconds */
    uint32_t incl_len;       /* number of octets of packet saved in file */
    uint32_t orig_len;       /* actual length of packet */
} pcaprec_hdr_t;

ref class WiresharkThread
{

public:
    WiresharkThread(void)
    {

    }
    void WiresharkOpen()
    {
        String^ cmd = "\"C:\\Program Files\\Wireshark\\wireshark\" -i \\\\.\\pipe\\wireshark";
        int ret;
        IntPtr ptrToNativeStringCmd = Marshal::StringToHGlobalAnsi(cmd);
        char* cmdChar = static_cast<char*>(ptrToNativeStringCmd.ToPointer());

        ret = system(cmdChar);
        Marshal::FreeHGlobal(ptrToNativeStringCmd);
        if (ret < 0)
            MessageBox::Show("Failed to open Wireshark.\r\n",
                "Wireshark Open Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
};

ref class WiresharkIf
{
    HANDLE hPipe = NULL; /* pipe handle */

public:
    WiresharkIf(void) {
        CreatePipe();
    }
    ~WiresharkIf(void) {
        if (hPipe) {
            FlushFileBuffers(hPipe);
            DisconnectNamedPipe(hPipe);
            CloseHandle(hPipe);
        }
    }
    void CreatePipe( void )
    {
        hPipe = CreateNamedPipe(
            L"\\\\.\\pipe\\wireshark",
            PIPE_ACCESS_OUTBOUND,
            PIPE_TYPE_MESSAGE | PIPE_WAIT,
            1, 65536, 65536,
            300,
            NULL);
        if (hPipe == INVALID_HANDLE_VALUE) {
            MessageBox::Show("Failed to connect to Wireshark.\r\n",
                "Wireshark Connection Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }        
    }

    int write( const void *ptr, size_t size )//
    {
        DWORD cbWritten = 0;
        /* TODO: Do the formatting of data and write to pipe */
        ::FILETIME ft;
        ::GetSystemTimeAsFileTime(&ft);

        ULARGE_INTEGER timestamp;
        timestamp.LowPart = ft.dwLowDateTime;
        timestamp.HighPart = ft.dwHighDateTime;
        // Convert the timestamp to seconds and microseconds since January 1, 1970 (Unix epoch)
        uint64_t unixTimestamp = (timestamp.QuadPart - 116444736000000000ull) / 10ull;
        uint32_t seconds = static_cast<uint32_t>(unixTimestamp / 1000000ull);
        uint32_t microseconds = static_cast<uint32_t>(unixTimestamp % 1000000ull);

        // Write packet header to Pipe
        pcaprec_hdr_t packetHeader;
        packetHeader.ts_sec = seconds; // Set the actual timestamp (seconds)
        packetHeader.ts_usec = microseconds; // Set the actual timestamp (microseconds)
        packetHeader.incl_len = size; // Replace with the actual size of the packet data being sent
        packetHeader.orig_len = size; // Replace with the actual size of the original packet data

        /* Write to Pipe the packet header */
        if (hPipe)
        {
            if (false == WriteFile(hPipe, &packetHeader, sizeof(pcaprec_hdr_t), &cbWritten, NULL))
                return 0;
            else if (false == WriteFile(hPipe, ptr, size * 1, &cbWritten, NULL))
                return 0;
        }        

        return cbWritten;
    }
    void open( void )
    {
        WiresharkThread^ wh = gcnew WiresharkThread();
        Thread^ wthread = gcnew Thread(gcnew ThreadStart(wh, &WiresharkThread::WiresharkOpen));
        wthread->Name = "wthread";
        wthread->Start();
    }
    void ConnectWe310Wireshrk()
    {
        ConnectNamedPipe(hPipe, NULL);
        MessageBox::Show("Connected to the pipe Now");
        DWORD cbWritten = 0;
        // Write global header to Pipe 
        pcap_hdr_t globalHeader;
        globalHeader.magic_number = 0xa1b2c3d4; // Replace with actual magic number
        globalHeader.version_major = 2; // Replace with actual version number
        globalHeader.version_minor = 4; // Replace with actual version number
        globalHeader.thiszone = 0;
        globalHeader.sigfigs = 0;
        globalHeader.snaplen = 65535; // Replace with desired snaplen
        globalHeader.network = 105; // Replace with actual data link type (e.g., 1 for Ethernet)

        if (hPipe) {
            if (false == WriteFile(hPipe, &globalHeader, sizeof(pcap_hdr_t), &cbWritten, NULL))
                MessageBox::Show("Unable to write Global Header to Wireshark");
        }
    }
};

