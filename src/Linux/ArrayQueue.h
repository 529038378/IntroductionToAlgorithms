#ifndef _ARRAY_QUEUE_H
#define _ARRAY_QUEUE_H

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
	int GetQueueSize(void) const;
	void Description(void) const;
	bool IsEmpty();
	void Test();
	bool Enqueue(T nData);
	T Dequeue();
	T Front();
private:
	T* m_pArray;
	int m_nSize;
	int m_nHead;
	int m_nTail;
};

#endif