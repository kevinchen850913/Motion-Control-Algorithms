// Motion Control Algorithms.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include "MySystemThread.h";
#include "DP_COMMAND.h";

using namespace std;

thread MySystemThread(MySystemThread_job);

vector<string> words{};
string delimiter = " ";
size_t pos;

COMMAND_NODE nextnode;

void DecodeCMD(string CMD)
{
    if (CMD != "")
    {
        words.clear();
        while ((pos = CMD.find(delimiter)) != string::npos) {
            words.push_back(CMD.substr(0, pos));
            CMD.erase(0, pos + delimiter.length());
        }
        nextnode = COMMAND_NODE();
        nextnode.data.cmd = stoi(words[0]);
        nextnode.data.sub_cmd = stoi(words[1]);
        nextnode.data.handle_id = stoi(words[2]);
        nextnode.data.data1 = stoi(words[3]);
        QCOMMAND.Enquene(&nextnode);
    }
}


int main()
{
    string CMD;
    cout << "Hello World!\n";
    MySystemThread.join();
    while (true)
    {
        getline(cin, CMD);
        DecodeCMD(CMD);
    }
}






