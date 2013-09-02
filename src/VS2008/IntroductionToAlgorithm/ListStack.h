#ifndef _LISTSTACK_H
#define _LISTSTACK_H

#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"
#include "DataIO.cpp"

template <typename T>

struct ListNode
{
	ListNode* pNext;
	T nData;
};

template <typename T>
class ListStack : public AbstractBase
{
public:
	ListStack();
	~ListStack();
	void Description(void) const;
	void Push(const T nData);
	T Pop();
	void Test();
	bool IsEmpty();
	T Top();
private:
	ListNode<T>* m_pHead;
	ListNode<T>* m_pTop;
	int m_nSize;
};

#endif