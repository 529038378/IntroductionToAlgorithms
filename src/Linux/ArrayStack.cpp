#include "ArrayStack.h"

/**************************************************************
**	File:			ArrayStack.cpp
**	Description:	The Definition of the  Class ArrayStack,
**					Array implementation of the stack struct.
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/


template <typename T>
ArrayStack<T>::ArrayStack(int nSize)
{
	SetClassType(DATA_STRUCT);
	SetTitle("Data Struct: Stack Implemented By Array");
	m_nSize = nSize;
	m_nTop = 0;
	try
	{
		m_pArray = new int[nSize];
	}
	catch(...)
	{
		TRACE("new failure!");
	}
}

template <typename T>
ArrayStack<T>::~ArrayStack(void)
{
	if(m_pArray)
	{
		delete[] m_pArray;
		m_pArray = NULL;
	}
	m_nSize = 0;
	m_nTop = -1;
}

template <typename T>
void ArrayStack<T>::Description(void) const
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

template <typename T>
bool ArrayStack<T>::Push(const T nData)
{
	if(m_nTop == m_nSize - 1)							//Judge if the stack is full
	{
		TRACE("the stack is full!");
		return false;
	}
	else
	{
		++m_nTop;
		m_pArray[m_nTop] = nData;						//Push data to stack and update the top value
		return true;
	}
}

template <typename T>
T ArrayStack<T>::Pop()
{
	if(m_nTop == -1)
	{
		TRACE("the stack is empty!");
		return ERROR_EMPTY;
	}
	else
	{
		--m_nTop;										//Pop data from stack and update the to value
		return m_pArray[m_nTop+1];
	}
}

template <typename T>
bool ArrayStack<T>::IsEmpty()
{
	return (m_nTop == -1);
}

template <typename T>
T ArrayStack<T>::Top()
{
	if(m_nTop == -1)
	{
		TRACE("the stack is empty!");
		return ERROR_EMPTY;
	}
	else
	{
		return m_pArray[m_nTop];
	}
}

template <typename T>
int ArrayStack<T>::GetStackSize(void) const
{
	return m_nSize;
}

template <typename T>
void ArrayStack<T>::Test()
{
	DataIO<T> dataIO;
	cout<<endl<<TEST_BEGIN_STRING<<endl;
	cout<<"Let's See The Test of ArrayStack"<<endl;
	T* pData = dataIO.GetDataFromStdIO(1);
	if(pData != NULL)
	{
		unsigned int nDataByte = dataIO.GetDataByte();
		for(unsigned int i=0;i<nDataByte;i++)
		{
			cout<<"Push Data:"<<pData[i]<<endl;
			Push(pData[i]);									//Push data into stack which is got from DataIO
		}
		T nData = Top();									//Return the top data value of the stack
		cout<<"Return Top Data:"<<nData<<endl;
		for(unsigned int i=0;i<nDataByte;i++)
		{
			nData = Pop();									//Pop the data from the stack top
			cout<<"Pop Data:"<<nData<<endl;
		}
		Pop();												//Pop data judge if the stack is empty
		cout<<TEST_END_STRING<<endl<<endl;
	}
}