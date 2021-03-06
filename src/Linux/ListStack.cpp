#include "ListStack.h"

/**************************************************************
**	File:			ListStack.cpp
**	Description:	The implementation of the Class ListStack
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/

template <typename T>
ListStack<T>::ListStack()
{
	SetClassType(DATA_STRUCT);
	SetTitle("Data Struct: Stack Implemented By List");
	try
	{
		m_pHead = new ListNode<T>[1];
	}
	catch(...)
	{
		TRACE("new failure!");
		m_pHead = NULL;
		return;
	}
	m_pHead->pNext = NULL;
	m_pTop = m_pHead;
	m_nSize = 0;
}

template <typename T>
ListStack<T>::~ListStack()
{
	ListNode<T> *pList = m_pHead;
	ListNode<T> *pTemp = NULL;
	while(pList != NULL)
	{
		pTemp = pList->pNext;
		delete pList;
		pList = pTemp;
	}
	m_nSize = 0;
	m_pTop = NULL;
}

template <typename T>
bool ListStack<T>::Push(const T nData)
{
	ListNode<T> *pNewNode = new ListNode<T>[1];				//Allocate the new node memory and add it to the top of the list
	pNewNode->nData = nData;
	pNewNode->pNext = m_pHead->pNext;
	m_pHead->pNext = pNewNode;
	m_pTop = pNewNode;
	++m_nSize;
	return true;
}

template <typename T>
T ListStack<T>::Pop()
{
	if(!IsEmpty())											//If the list is not empty ,pop the top data
	{
		T nData;
		ListNode<T> *pTemp = m_pHead->pNext;
		nData = pTemp->nData;
		m_pHead->pNext = pTemp->pNext;
		m_pTop = m_pHead->pNext;
		pTemp->pNext = NULL;
		delete pTemp;
		return nData;
	}
	else
	{
		TRACE("the stack is empty!");
		return ERROR_EMPTY;
	}
}

template<typename T>
int ListStack<T>::GetStackSize() const
{
	return m_nSize;
}

template<typename T>
bool ListStack<T>::IsEmpty()
{
	return (m_pHead->pNext == NULL);
}

template<typename T>
T ListStack<T>::Top()
{
	if(!IsEmpty())
	{
		T nData;
		nData = m_pTop->nData;
		return nData;
	}
	else
	{
		TRACE("the stack is empty!");
		return ERROR_EMPTY;
	}
}

template<typename T>
void ListStack<T>::Description(void) const
{
	cout<<STAR_STRING<<endl;
	cout<<"DESCRIPTION:"<<endl;
	cout<<"Referenced From:"<<endl;
	cout<<"http://en.wikipedia.org/wiki/Stack_(abstract_data_type)#Abstract_definition"<<endl;
	cout<<"In computer science, a stack is a particular kind of abstract"<<endl;
	cout<<"data type or collection in which the principal operations"<<endl;
	cout<<"on the collection are the addition of an entity to the collection,"<<endl;
	cout<<"known as push and removal of an entity, known as pop.The relation"<<endl;
	cout<<"between the push and pop operations is such that the stack is a "<<endl;
	cout<<"Last-In-First-Out (LIFO) data structure. In a LIFO data structure,"<<endl;
	cout<<"the last element added to the structure must be the first one to be"<<endl;
	cout<<"removed. This is equivalent to the requirement that, considered as"<<endl;
	cout<<"a linear data structure, or more abstractly a sequential collection,"<<endl;
	cout<<"the push and pop operations occur only at one end of the structure,"<<endl;
	cout<<"referred to as the top of the stack. Often a peek or top operation is"<<endl;
	cout<<"also implemented, returning the value of the top element without"<<endl;
	cout<<" removing it."<<endl;
	cout<<"THE USEFUL CHINESE URL IS:http://zh.wikipedia.org/wiki/%E5%A0%86%E6%A0%88"<<endl;
	cout<<STAR_STRING<<endl;
	cout<<endl;
}

template<typename T>
void ListStack<T>::Test()
{
	DataIO<T> dataIO;
	cout<<endl<<TEST_BEGIN_STRING<<endl;
	cout<<"Let's See The Test of ListStack"<<endl;
	T* pData = dataIO.GetDataFromStdIO(1);
	if(pData != NULL)
	{
		unsigned int nDataByte = dataIO.GetDataByte();				//Get data from stdio and push it
		for(unsigned int i=0;i<nDataByte;i++)
		{
			cout<<"Push Data:"<<pData[i]<<endl;
			Push(pData[i]);
		}
		T nData = Top();
		cout<<"Return Top Data:"<<nData<<endl;						//Remove all data from the stack list
		for(unsigned int i=0;i<nDataByte;i++)
		{
			nData = Pop();
			cout<<"Pop Data:"<<nData<<endl;
		}
		Pop();
		cout<<TEST_END_STRING<<endl<<endl;
	}
}