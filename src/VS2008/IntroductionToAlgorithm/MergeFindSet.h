#ifndef _MERGEFINDSET_H
#define _MERGEFINDSET_H

/**************************************************************
**	File:			MergeFindSet.h
**	Description:	The Definition of the Class MergeFindSet
**	Author:			Daiyl
**	Date:			2013.9
**************************************************************/


#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"

template <typename T>
struct MFSet									//Merge Find Set Node
{
	MFSet()
	{
		pParent = NULL;
		nRank = 1;
	}
	T nData;
	MFSet* pParent;
	int nRank;
};

template <typename T>
class MergeFindSet : public AbstractBase
{
public:
	typedef int (*Compare)(T x, T y);
	MergeFindSet();
	MergeFindSet(Compare pFun,int nSize);
	~MergeFindSet();
	void Description(void) const;
	void Test();
	void Union(MFSet<T>* pNodeX,MFSet<T>* pNodeY);
	MFSet<T>* Find(MFSet<T>* pNode);
	int GetSize();
private:
	void SubLink(MFSet<T>* pNodeX,MFSet<T>* pNodeY);
	void InitialMakeSet(int nSize);
	MFSet<T>* m_pSetNodes;
	Compare m_pFun;										//Comparasion function of the node data
	int m_nSize;
};

#endif