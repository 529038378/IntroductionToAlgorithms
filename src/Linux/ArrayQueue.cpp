#include "ArrayQueue.h"

template <typename T>
ArrayQueue<T>::ArrayQueue()
{
	SetClassType(DATA_STRUCT);
	SetTitle("Data Struct: Queue Implemented By Array");
	m_nSize = 10;
	try
	{
		m_pArray = new int[10];
	}
	catch(...)
	{
		TRACE("new failure!");
	}
	m_nHead = 0;
	m_nTail = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(int nSize)
{
	SetClassType(DATA_STRUCT);
	SetTitle("Data Struct: Queue Implemented By Array");
	m_nSize = nSize;
	try
	{
		m_pArray = new int[nSize];
	}
	catch(...)
	{
		TRACE("new failure!");
	}
	m_nHead = 0;
	m_nTail = 0;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
	if(m_pArray)
	{
		delete[] m_pArray;
		m_pArray = NULL;
	}
	m_nSize = 0;
	m_nHead = 0;
	m_nTail = 0;
}

template <typename T>
int ArrayQueue<T>::GetQueueSize() const
{
	return m_nSize-1;
}

template <typename T>
void ArrayQueue<T>::Description() const
{
	cout<<STAR_STRING<<endl;
	cout<<"DESCRIPTION:"<<endl;
	cout<<"Referenced From:"<<endl;
	cout<<"http://en.wikipedia.org/wiki/Queue_(abstract_data_type)"<<endl;
	cout<<"In computer science, a queue is a particular kind of abstract data type"<<endl;
	cout<<"or collection in which the entities in the collection are kept in order"<<endl;
	cout<<"and the principal (or only) operations on the collection are the addition"<<endl;
	cout<<"of entities to the rear terminal position, known as enqueue, and removal"<<endl;
	cout<<"of entities from the front terminal position, known as dequeue."<<endl;
	cout<<"This makes the queue a First-In-First-Out (FIFO) data structure."<<endl;
	cout<<"In a FIFO data structure, the first element added to the queue will be the"<<endl;
	cout<<"first one to be removed. This is equivalent to the requirement that once"<<endl;
	cout<<"a new element is added, all elements that were added before have to be"<<endl;
	cout<<"removed before the new element can be removed. Often a peek or front"<<endl;
	cout<<"operation is also implemented, returning the value of the front element"<<endl;
	cout<<"without dequeuing it. A queue is an example of a linear data structure,"<<endl;
	cout<<"or more abstractly a sequential collection."<<endl;
	cout<<"THE USEFUL CHINESE URL IS:http://zh.wikipedia.org/wiki/%E9%98%9F%E5%88%97"<<endl;
	cout<<STAR_STRING<<endl;
	cout<<endl;
}

template <typename T>
bool ArrayQueue<T>::IsEmpty()
{
	return (m_nHead == m_nTail);
}

template <typename T>
bool ArrayQueue<T>::Enqueue(T nData)
{
	if(m_nHead == ((m_nTail+1)%(m_nSize)))
	{
		TRACE("the queue is full");
		return false;
	}
	else
	{
		m_pArray[m_nTail] = nData;
		m_nTail = (m_nTail + 1)%(m_nSize);
		return true;
	}
}

template <typename T>
T ArrayQueue<T>::Dequeue()
{
	if(IsEmpty())
	{
		TRACE("the queue is empty");
		return ERROR_EMPTY;
	}
	else
	{
		T nData;
		nData = m_pArray[m_nHead];
		m_nHead = (m_nHead + 1)%(m_nSize);
		return nData;
	}
}

template <typename T>
T ArrayQueue<T>::Front()
{
	return m_pArray[m_nHead];
}

template <typename T>
void ArrayQueue<T>::Test()
{
	DataIO<T> dataIO;
	cout<<endl<<TEST_BEGIN_STRING<<endl;
	cout<<"Let's See The Test of ArrayQueue"<<endl;
	T* pData = dataIO.GetDataFromStdIO(1);
	if(pData != NULL)
	{
		unsigned int nDataByte = dataIO.GetDataByte();
		for(unsigned int i=0;i<nDataByte;i++)
		{
			cout<<"Enqueue Data:"<<pData[i]<<endl;
			Enqueue(pData[i]);
		}
		T nData = Front();
		cout<<"Return Front Data:"<<nData<<endl;
		for(unsigned int i=0;i<nDataByte;i++)
		{
			nData = Dequeue();
			cout<<"Dequeue Data:"<<nData<<endl;
		}
		cout<<TEST_END_STRING<<endl<<endl;
	}
}
