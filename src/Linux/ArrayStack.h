#ifndef _ARRAY_STACK_H
#define _ARRAY_STACK_H


/**************************************************************
**	File:			ArrayStack.h
**	Description:	The Definition of the  Class ArrayStack,
**					Array implementation of the stack struct.
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/


#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"


template <typename T>
class ArrayStack : public AbstractBase
{
public:
	ArrayStack()
	{
		SetClassType(DATA_STRUCT);
		SetTitle("Data Struct: Stack Implemented By Array");
		m_nSize = 10;
		try
		{
			m_pArray = new int[10];
		}
		catch(...)
		{
			TRACE("new failure!");
		}
		m_nTop = -1;
	}
	ArrayStack(int nSize);
	~ArrayStack(void);
	int GetStackSize(void) const;
	void Description(void) const;
	bool Push(const T nData);					//Push data into stack
	T Pop();									//Pop data from stack
	bool IsEmpty();								//Judge if Stack is empty
	T Top();									//Return the top data of the stack
	void Test();
private:
	int m_nSize;								//Stack size
	T* m_pArray;								//Stack array pointer
	int m_nTop;									//Stack top data index
};

#endif