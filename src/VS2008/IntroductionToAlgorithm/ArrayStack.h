#ifndef _ARRAY_STACK_H
#define _ARRAY_STACK_H

#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"

class ArrayStack : public AbstractBase
{
public:
	ArrayStack()
	{
		SetClassType(DATA_STRUCT);
		SetTitle("Data Struct: Stack Implemented By Array");
		m_nSize = 10;
		m_pArray = new int[10];
		m_nTop = -1;
	}
	ArrayStack(int nSize);
	~ArrayStack(void);
	int GetStackSize(void) const;
	void Description(void) const;
	void Push(const int nData);
	int Pop();
	bool IsEmpty();
	int Top();
	void Test();
private:
	int m_nSize;
	int* m_pArray;
	int m_nTop;
};

#endif