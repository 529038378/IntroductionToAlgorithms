#include "MergeFindSet.h"

/**************************************************************
**	File:			MergeFindSet.cpp
**	Description:	The Definition of the  Class MergeFindSet,
**	Author:			Daiyl
**	Date:			2013.9
**************************************************************/

template <typename T>
MergeFindSet<T>::MergeFindSet()
{
	SetClassType(DATA_STRUCT);
	SetTitle("Data Struct: MergeFindSet Implemented By List");
	try
	{
		m_pSetNodes = new MFSet<T>[DEFAULT_MERGESET_SIZE];
	}
	catch(...)
	{
		TRACE("new failure");
	}
	m_pFun = DefaultCompare;
	m_nSize = DEFAULT_MERGESET_SIZE;
	InitialMakeSet(m_nSize);
}

template <typename T>
MergeFindSet<T>::MergeFindSet(Compare pFun,int nSize)
{
	SetClassType(DATA_STRUCT);
	SetTitle("Data Struct: MergeFindSet Implemented By List");
	try
	{
		m_pSetNodes = new MFSet<T>[nSize];
	}
	catch(...)
	{
		TRACE("new failure");
	}
	m_pFun = pFun;
	m_nSize = nSize;
	InitialMakeSet(nSize);
}

template <typename T>
MergeFindSet<T>::~MergeFindSet()
{
	if(m_pSetNodes)
	{
		delete[] m_pSetNodes;
		m_pSetNodes = NULL;
	}
	m_nSize = 0;
}

template <typename T>
int MergeFindSet<T>::GetSize()
{
	return m_nSize;
}

template <typename T>
void MergeFindSet<T>::Description() const
{
	cout<<STAR_STRING<<endl;
	cout<<"DESCRIPTION:"<<endl;
	cout<<"Referenced From:"<<endl;
	cout<<"http://en.wikipedia.org/wiki/Disjoint-set_data_structure"<<endl;
	cout<<"In computing, a disjoint-set data structure is a data structure that"<<endl;
	cout<<"keeps track of a set of elements partitioned into a number of disjoint"<<endl;
	cout<<"(nonoverlapping) subsets. A union-find algorithm is an algorithm that"<<endl;
	cout<<"performs two useful operations on such a data structure:"<<endl;
	cout<<"1. Find: Determine which subset a particular element is in."<<endl;
	cout<<"2. Union: Join two subsets into a single subset."<<endl;
	cout<<"Because it supports these two operations, a disjoint-set data structure"<<endl;
	cout<<"is sometimes called a union-find data structure or merge-find set. The"<<endl;
	cout<<"other important operation, MakeSet, which makes a set containing only a"<<endl;
	cout<<"operations, many practical partitioning problems can be solved."<<endl;
	cout<<"THE USEFUL CHINESE URL IS:http://zh.wikipedia.org/zh-cn/%E5%B9%B6%E6%9F%A5%E9%9B%86"<<endl;
	cout<<STAR_STRING<<endl;
	cout<<endl;
}

template <typename T>
void MergeFindSet<T>::Test()
{
	DataIO<T> dataIO;
	cout<<endl<<TEST_BEGIN_STRING<<endl;
	cout<<"Let's See The Test of Merge Find Set"<<endl;
	cout<<"PS:The First Line of the input data is represent for the Set Member Size(<99) and the Example Data Number respectively!"<<endl;
	T* pData = dataIO.GetDataFromStdIO(2);				//Get data from DataIO class,2 data per row
	if(pData != NULL)
	{
		//int nSetMemberNumber = (int)pData[0];
		int nDataLine = (int)pData[1];
		for(int i=0;i<nDataLine*2;i+=2)
		{
			cout<<"Union Data:"<<pData[i+2]<<" and "<<pData[i+3]<<endl;
			if(pData[i+2] > 99 || pData[i+3] > 99)
			{
				TRACE("input data is too large");
				return;
			}
			m_pSetNodes[pData[i+2]].nData = pData[i+2];
			m_pSetNodes[pData[i+3]].nData = pData[i+3];
			Union(&m_pSetNodes[pData[i+2]],&m_pSetNodes[pData[i+3]]);
		}
		cout<<"Test the data pair is or not in the same set"<<endl;
		cout<<"Data Pair: 3 and 4"<<endl;
		if(Find(&m_pSetNodes[3]) == Find(&m_pSetNodes[4]))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
		cout<<"Data Pair: 7 and 10"<<endl;
		if(Find(&m_pSetNodes[7]) == Find(&m_pSetNodes[10]))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
		cout<<"Data Pair: 8 and 9"<<endl;
		if(Find(&m_pSetNodes[8]) == Find(&m_pSetNodes[9]))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
		cout<<TEST_END_STRING<<endl<<endl;
	}
}

template <typename T>
void MergeFindSet<T>::Union(MFSet<T>* pNodeX,MFSet<T>* pNodeY)
{
	SubLink(Find(pNodeX),Find(pNodeY));
}

template <typename T>
void MergeFindSet<T>::SubLink(MFSet<T>* pNodeX,MFSet<T>* pNodeY)
{
	if(pNodeX == pNodeY)
		return;
	if(pNodeX->nRank > pNodeY->nRank)
	{
		pNodeY->pParent = pNodeX;
	}
	else
	{
		if(pNodeX->nRank == pNodeY->nRank)
		{
			++(pNodeY->nRank);
		}
		pNodeX->pParent = pNodeY;
	}
}

template <typename T>
MFSet<T>* MergeFindSet<T>::Find(MFSet<T>* pNode)
{
	if(pNode != pNode->pParent)
	{
		pNode->pParent = Find(pNode->pParent);
	}
	return pNode->pParent;
}

template <typename T>
void MergeFindSet<T>::InitialMakeSet(int nSize)
{
	for(int i=0;i<nSize;i++)
	{
		m_pSetNodes[i].pParent = &m_pSetNodes[i];
		m_pSetNodes[i].nRank = 1;
	}
}