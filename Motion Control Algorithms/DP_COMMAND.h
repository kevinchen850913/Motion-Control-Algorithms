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
	COMMAND_NODE *node;
	DP_COMMAND_DATA data;
	long _size;
	COMMAND_NODE_Queue()
	{
		_size = 0;
	}
	long Size()
	{
		return _size;
	}
	void Enquene(DP_COMMAND_DATA data)
	{
		node = new COMMAND_NODE();
		node->data = data;
		if (_size > 0)
		{
			COMMAND_NODE_tail->next = node;
		}
		else
		{
			COMMAND_NODE_head = node;
		}
		COMMAND_NODE_tail = node;
		_size++;
	}
	DP_COMMAND_DATA Dequene()
	{
		data = DP_COMMAND_DATA();
		if (_size > 0)
		{
			data = COMMAND_NODE_head->data;
			node = COMMAND_NODE_head;
			COMMAND_NODE_head = COMMAND_NODE_head->next;
			delete node;
			_size--;
		}
		return data;
	}
};

static DP_COMMAND_DATA CMD_DATA;
static COMMAND_NODE_Queue QCOMMAND = COMMAND_NODE_Queue();

#endif