﻿// Motion Control Algorithms.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>;
#include <string>
#include <thread>;
#include <queue>
#include "MySystemThread.h";
#include "DP_COMMAND.h";

using namespace std;

thread MySystemThread(MySystemThread_job);
string CMD;
string delimiter = " ";
vector<string> words{};
size_t pos;
DP_COMMAND_DATA COMMAND_DATA;
COMMAND_NODE node;

int main()
{
    cout << "Hello World!\n";
    MySystemThread.join();
    while (true)
    {
        getline(cin, CMD);
        if (CMD != "")
        {
            words.clear();
            while ((pos = CMD.find(delimiter)) != string::npos) {
                words.push_back(CMD.substr(0, pos));
                CMD.erase(0, pos + delimiter.length());
            }
            COMMAND_DATA.cmd = stoi(words[0]);
            COMMAND_DATA.sub_cmd = stoi(words[1]);
            COMMAND_DATA.handle_id = stoi(words[2]);
            COMMAND_DATA.data1 = stoi(words[3]);
            COMMAND_NODE nextnode;
            nextnode.data = COMMAND_DATA;
            nextnode.next = NULL;
            node.next = &nextnode;
            node = nextnode; 
        }        
    }
}






