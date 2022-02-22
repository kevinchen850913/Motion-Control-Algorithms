#include <stdlib.h>
#include "MotionMain.h";
#include "DP_COMMAND.h"

COMMAND_NODE node;
int i;

void MuMotionDataRecord()
{
	QCOMMAND_p->Dequene(&node);
	if (node.data.cmd == 0)
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
	MuMotionDataRecord();
}