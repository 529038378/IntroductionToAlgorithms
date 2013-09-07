#ifndef _LISTSTACK_H
#define _LISTSTACK_H

/**************************************************************
**	File:			ListStack.h
**	Description:	The Definition of the  Class ListStack
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/


#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"
#include "DataIO.cpp"

template <typename T>

struct ListNode
{
	ListNode* pNext;							//The node pointer to the next node
	T nData;									//Node data
};

template <typename T>
class ListStack : public AbstractBase
{
public:
	ListStack();
	~ListStack();
	void Description(void) const;
	bool Push(const T nData);					//Push data to the top
	T Pop();									//Poo data from the top
	void Test();
	bool IsEmpty();
	T Top();									//Return data from top
	int GetStackSize(void) const;				//Get the top data without remove it
private:
	ListNode<T>* m_pHead;						//The head of the stack list
	ListNode<T>* m_pTop;						//The top of the stack list
	int m_nSize;								//The size of the stack list
};

#endif