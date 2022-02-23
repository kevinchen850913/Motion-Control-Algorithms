// Motion Control Algorithms.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include "DP_COMMAND.h";
#include "MotionMain.h";
#include <windows.h>

using namespace std;

vector<string> words{};
string delimiter = " ";
size_t pos;

void MySystemThread_job()
{
    for (long i = 0; i < 100000; i++)
    {
        MuMotionDataRecord(&QCOMMAND);
        MotionMain();
        Sleep(1);
    }
}
thread MySystemThread(MySystemThread_job);

void DecodeCMD(string CMD)
{
    if (CMD != "")
    {
        words.clear();
        while ((pos = CMD.find(delimiter)) != string::npos) {
            words.push_back(CMD.substr(0, pos));
            CMD.erase(0, pos + delimiter.length());
        }
        CMD_DATA = DP_COMMAND_DATA();
        CMD_DATA.cmd = stoi(words[0]);
        CMD_DATA.sub_cmd = stoi(words[1]);
        CMD_DATA.handle_id = stoi(words[2]);
        CMD_DATA.data1 = stoi(words[3]);
        QCOMMAND.Enquene(CMD_DATA);
    }
}

int main()
{
    string CMD;
    cout << "Hello World!\n";
    MySystemThread.detach();
    while (true)
    {
        getline(cin, CMD);
        DecodeCMD(CMD);
    }
}






