#include "MySystemThread.h";
#include "MotionMain.h";
#include <windows.h>

void MySystemThread_job()
{
    for (long i = 0; i < 100000; i++)
    {
        MotionMain();        
        Sleep(1);
    }
}