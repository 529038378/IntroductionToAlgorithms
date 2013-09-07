#ifndef _CYCLEDOUBLYLINKLIST_H
#define _CYCLEDOUBLYLINKLIST_H

/**************************************************************
**	File:			CycleDoublyLinkList.h
**	Description:	The Definition of the  Class CycleDoublyLinkList
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/


#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"

template <typename T>
struct CDListNode
{
	CDListNode* pNext;								//Pointer to the next node
	CDListNode* pPrev;								//Pointer to the previous node
	T nData;										//Node data
};

template <typename T>
class CycleDoublyLinkList : public AbstractBase
{
public:
	CycleDoublyLinkList();
	~CycleDoublyLinkList();
	void Description(void) const;
	void Test();
	int GetListSize(void) const;					//Get the list size
	bool IsEmpty();									//Judge if the list is empty
	bool Insert(T nData);							//Insert the data to the node after Sentinel node
	CDListNode<T>* Search(T nData);					//Search data in the list
	bool Delete(T nData);							//Delete specified data in the list
	void Traverse() const;							//Traverse the data in the list back and forth
	void TraverseBackward() const;
private:
	bool Delete(CDListNode<T>* pNode);
	CDListNode<T>* m_pSentinel;
	int m_nSize;
};

#endif