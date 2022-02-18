// Motion Control Algorithms.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>;
#include <thread>;
#include "MySystemThread.h";
#include "DP_COMMAND.h";

using namespace std;
thread MySystemThread(MySystemThread_job);

int main()
{
    string CMD;
    cout << "Hello World!\n";
    MySystemThread.join();
    while (true)
    {
        cin >> CMD;
    }
}





