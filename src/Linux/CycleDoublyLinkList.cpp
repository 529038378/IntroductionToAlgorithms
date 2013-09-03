#include "CycleDoublyLinkList.h"

template <typename T>
CycleDoublyLinkList<T>::CycleDoublyLinkList()
{
	SetClassType(DATA_STRUCT);
	SetTitle("Data Struct: Stack Implemented By List");
	try
	{
		m_pSentinel = new CDListNode<T>[1];
	}
	catch(...)
	{
		TRACE("new failure!");
		m_pSentinel = NULL;
		return;
	}
	m_pSentinel->pNext = m_pSentinel;
	m_pSentinel->pPrev = m_pSentinel;
	m_nSize = 0;
}

template <typename T>
CycleDoublyLinkList<T>::~CycleDoublyLinkList()
{
	CDListNode<T> *pList = m_pSentinel;
	while(pList->pNext != m_pSentinel)
	{
		Delete(pList->pNext);
	}
	delete m_pSentinel;
	m_pSentinel = NULL;
	m_nSize = 0;
}

template <typename T>
void CycleDoublyLinkList<T>::Description(void) const
{
	cout<<STAR_STRING<<endl;
	cout<<"DESCRIPTION:"<<endl;
	cout<<"Referenced From:"<<endl;
	cout<<"http://en.wikipedia.org/wiki/Doubly_linked_list"<<endl;
	cout<<"In computer science, a doubly-linked list is a linked data structure"<<endl;
	cout<<"that consists of a set of sequentially linked records called nodes."<<endl;
	cout<<"Each node contains two fields, called links, that are references to"<<endl;
	cout<<"the previous and to the next node in the sequence of nodes."<<endl;
	cout<<"The beginning and ending nodes' previous and next links, respectively,"<<endl;
	cout<<"point to some kind of terminator, typically a sentinel node or null,"<<endl;
	cout<<"to facilitate traversal of the list. If there is only one sentinel node,"<<endl;
	cout<<"then the list is circularly linked via the sentinel node. It can be"<<endl;
	cout<<"items, but in opposite sequential orders."<<endl;
	cout<<"THE USEFUL CHINESE URL IS:"<<endl;
	cout<<"http://zh.wikipedia.org/wiki/%E5%8F%8C%E5%90%91%E9%93%BE%E8%A1%A8"<<endl;
	cout<<STAR_STRING<<endl;
	cout<<endl;
}

template <typename T>
void CycleDoublyLinkList<T>::Test()
{
	DataIO<T> dataIO;
	cout<<endl<<TEST_BEGIN_STRING<<endl;
	cout<<"Let's See The Test of Cycle Doubly Linked List"<<endl;
	T* pData = dataIO.GetDataFromStdIO(1);
	if(pData != NULL)
	{
		unsigned int nDataByte = dataIO.GetDataByte();
		for(unsigned int i=0;i<nDataByte;i++)
		{
			cout<<"Insert Data:"<<pData[i]<<endl;
			Insert(pData[i]);
		}
		cout<<"Traverse the list"<<endl;
		Traverse();
		cout<<"Traverse the list backward"<<endl;
		TraverseBackward();
		for(unsigned int i=0;i<nDataByte;i++)
		{
			Delete(pData[i]);
			cout<<"Delete Data:"<<pData[i]<<endl;
		}
		cout<<"Traverse the list"<<endl;
		Traverse();
		cout<<TEST_END_STRING<<endl<<endl;
	}
}

template <typename T>
int CycleDoublyLinkList<T>::GetStackSize() const
{
	return m_nSize;
}

template <typename T>
bool CycleDoublyLinkList<T>::IsEmpty()
{
	return (m_pSentinel->pNext == m_pSentinel);
}

template <typename T>
bool CycleDoublyLinkList<T>::Insert(T nData)
{
	try
	{
		CDListNode<T> *pNewNode = new CDListNode<T>[1];
		pNewNode->nData = nData;
		pNewNode->pNext = m_pSentinel->pNext;
		m_pSentinel->pNext->pPrev = pNewNode;
		m_pSentinel->pNext = pNewNode;
		pNewNode->pPrev = m_pSentinel;
		++m_nSize;
	}
	catch(...)
	{
		TRACE("new failure");
		return false;
	}
	return true;
}

template <typename T>
CDListNode<T>* CycleDoublyLinkList<T>::Search(T nData)
{
	CDListNode<T>* pTemp = m_pSentinel->pNext;
	while((pTemp != m_pSentinel) && (pTemp->nData != nData))
	{
		pTemp = pTemp->pNext;
	}
	if(pTemp == m_pSentinel)
	{
		TRACE("can not find");
		return NULL;
	}
	if(pTemp->nData == nData)
	{
		return pTemp;
	}
	return NULL;
}

template <typename T>
bool CycleDoublyLinkList<T>::Delete(T nData)
{
	CDListNode<T>*pNode = Search(nData);
	if(pNode == NULL)
	{
		TRACE("can not find");
		return false;
	}
	else
	{
		Delete(pNode);
		return true;
	}
}

template <typename T>
bool CycleDoublyLinkList<T>::Delete(CDListNode<T>* pNode)
{
	CDListNode<T>* pTemp = pNode;
	if(pTemp!=NULL)
	{
		pTemp->pPrev->pNext = pTemp->pNext;
		pTemp->pNext->pPrev = pTemp->pPrev;
		delete pTemp;
		pTemp = NULL;
		pNode = NULL;
		--m_nSize;
		return true;
	}
	else
	{
		TRACE("error pointer");
		return false;
	}
}

template <typename T>
void CycleDoublyLinkList<T>::Traverse() const
{
	CDListNode<T>* pTemp = m_pSentinel->pNext;
	int nPerRow = 5;
	int nCount = 1;
	if(pTemp == m_pSentinel)
	{
		TRACE("the list is empty");
		return;
	}
	while(pTemp != m_pSentinel)
	{
		cout<<pTemp->nData<<"  ";
		if(nCount%nPerRow==0)
		{
			cout<<endl;
		}
		++nCount;
		pTemp = pTemp->pNext;
	}
}

template <typename T>
void CycleDoublyLinkList<T>::TraverseBackward() const
{
	CDListNode<T>* pTemp = m_pSentinel->pPrev;
	int nPerRow = 5;
	int nCount = 1;
	if(pTemp == m_pSentinel)
	{
		TRACE("the list is empty");
		return;
	}
	while(pTemp != m_pSentinel)
	{
		cout<<pTemp->nData<<"  ";
		if(nCount%nPerRow==0)
		{
			cout<<endl;
		}
		++nCount;
		pTemp = pTemp->pPrev;
	}
}