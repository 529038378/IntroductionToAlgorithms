#ifndef _ARRAY_QUEUE_H
#define _ARRAY_QUEUE_H

/**************************************************************
**	File:			ArrayQueue.h
**	Description:	The Definition of the  Class ArrayQueue,
**					Array implementation of the queue struct.
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/

#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"

template <typename T>
class ArrayQueue : public AbstractBase
{
public:
	ArrayQueue();
	ArrayQueue(int nSize);
	~ArrayQueue();
	int GetQueueSize(void) const;				//Return the size of the queue
	void Description(void) const;
	bool IsEmpty();								//Judge if the queue is empty
	void Test();								//Design the test method of the queue
	bool Enqueue(T nData);						//Put data into queue
	T Dequeue();								//Remove data from queue
	T Front();									//Return the front data of the queue
private:
	T* m_pArray;								//Queue array pointer
	int m_nSize;								//Queue size
	int m_nHead;								//Queue head
	int m_nTail;								//Queue tail
};

#endif