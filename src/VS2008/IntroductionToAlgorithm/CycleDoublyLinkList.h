#ifndef _CYCLEDOUBLYLINKLIST_H
#define _CYCLEDOUBLYLINKLIST_H

#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"

template <typename T>
struct CDListNode
{
	CDListNode* pNext;
	CDListNode* pPrev;
	T nData;
};

template <typename T>
class CycleDoublyLinkList : public AbstractBase
{
public:
	CycleDoublyLinkList();
	~CycleDoublyLinkList();
	void Description(void) const;
	void Test();
	int GetStackSize(void) const;
	bool IsEmpty();
	bool Insert(T nData);
	CDListNode<T>* Search(T nData);
	bool Delete(T nData);
	void Traverse() const;
	void TraverseBackward() const;
private:
	bool Delete(CDListNode<T>* pNode);
	CDListNode<T>* m_pSentinel;
	int m_nSize;
};

#endif