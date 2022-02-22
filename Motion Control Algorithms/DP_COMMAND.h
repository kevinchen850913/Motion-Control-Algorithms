#pragma once
#ifndef DP_COMMAND_h_
#define DP_COMMAND_h_

#include <stdlib.h>
#include <mutex>

class DP_COMMAND_DATA {
public:
	short cmd;
	short sub_cmd;
	short handle_id;
	short count;

	long data1;
	long data2;
	long data3;
	long data4;
	long data5;
	long data6;
	long data7;
	long data8;
	long data9;
	long data10;
	long data11;
	long data12;
	long data13;
	long data14;
	long data15;
	long data16;
	long data17;
	long data18;
	long data19;
	long data20;
	long data21;
	long data22;
	long data23;
	long data24;
	long data25;
	long data26;
	long data27;
	long data28;
	long data29;
	long data30;
	long data31;
	long data32;
	long data33;
	long data34;

	DP_COMMAND_DATA()
	{
		this->cmd = 0;
		this->sub_cmd = 0;
		this->count = 0;	
	}
};

class COMMAND_NODE {
public:
	DP_COMMAND_DATA data;
	COMMAND_NODE* next;
	COMMAND_NODE()
	{
		this->data = DP_COMMAND_DATA();
		this->next = NULL;
	}
};

class COMMAND_NODE_Queue{
public:
	COMMAND_NODE *COMMAND_NODE_head;
	COMMAND_NODE *COMMAND_NODE_tail;
	long _size;
	COMMAND_NODE_Queue()
	{
		COMMAND_NODE_head = NULL;
		COMMAND_NODE_tail = NULL;
		_size = 0;
	}
	long Size()
	{
		return _size;
	}
	void Enquene(COMMAND_NODE *node)
	{
		if (COMMAND_NODE_tail!=NULL)
		{
			COMMAND_NODE_tail->next = node;
		}
		COMMAND_NODE_tail = node;
		_size++;
	}
	void Dequene(COMMAND_NODE *node)
	{
		if (_size > 0)
		{
			node = COMMAND_NODE_head;
			COMMAND_NODE_head = COMMAND_NODE_head->next;
			_size--;
		}	
	}
};

static COMMAND_NODE_Queue QCOMMAND = COMMAND_NODE_Queue();
static COMMAND_NODE_Queue *QCOMMAND_p = &QCOMMAND;

#endif