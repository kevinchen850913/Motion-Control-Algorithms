#include "MotionMain.h";

int i;

void MotionDataRecord(COMMAND_NODE_Queue* QCOMMAND)
{
	if (QCOMMAND->Dequene().cmd == 0)
	{
		i = 0;
	}	
	else
	{
		i = 1;
	}
}

void MotionMain()
{
}