#ifndef _SORT_ALGORITHMS_H
#define _SORT_ALGORITHMS_H

/**************************************************************
**	File:			SortAlgorithms.h
**	Description:	The Implementation of all kinds of  Sort Algorithms
**	Author:			Daiyl
**	Date:			2013.10
**************************************************************/
#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"

#define RADIX_NUM		10			//整形每位最大上界
#define RADIX_MAX		32			//整形最大位数
#define COUNTINT_SORT_MAX_VAL	100

template <typename T>
class SortAlgorithms : public AbstractBase
{
public:
	typedef int (*Compare)(T x, T y);
	SortAlgorithms();
	SortAlgorithms(SORT eSort,Compare pFun);
	~SortAlgorithms();
	void Description(void) const;
	void Test();								//Design the test method of the sort algorithms
	void SetSortType(SORT eSort);
	SORT GetSortType() const;
	void SetCompareFunction(Compare pFun);
	void Swap(T& A,T& B);
	bool SelectionSort(T* pFirst,T* pLast,Compare pFun = NULL);
	bool InsertionSort(T* pFirst,T* pLast,Compare pFun = NULL);
	T*	 Partition(T* pP,T* pR);
	bool QuickSort(T* pFirst,T* pLast,Compare pFun = NULL);
	void Merge(T* pP,T* pQ,T* pR);
	bool MergeSort(T* pFirst,T* pLast,Compare pFun = NULL);
	bool BubbleSort(T* pFirst,T* pLast,Compare pFun = NULL);
	bool BuildMaxHeap(T* pFirst,T* pLast);
	void MaxHeapify(T* pFirst,const int nLength,const int nI);
	bool HeapSort(T* pFirst,T* pLast,Compare pFun = NULL);
	bool CountingSort(T* pFirst,T* pLast,const int nMaxValue);
	bool CountingSortWithRadixArray(T* pFirst,T* pLast,int* pRadixFirst,const int nMaxValue);
	bool RadixSortLSD(T* pFirst,T* pLast);
	bool RadixSortMSD(T* pFirst,T* pLast,const int nPos);
	bool ShellSort(T* pFirst,T* pLast,Compare pFun = NULL);
	bool CocktailShakerSort(T* pFirst,T* pLast,Compare pFun = NULL);
	bool GnomeSort(T* pFirst,T* pLast,Compare pFun = NULL);
	void BitonicMerge(T* pFirst,T* pLast,bool bDirection);
	bool BitonicSort(T* pFirst,T* pLast,bool bDirection,Compare pFun = NULL);
	bool OddEvenSort(T* pFirst,T* pLast,Compare pFun = NULL);
private:
	inline int _RadixSort_GetNumInPos(T nData,const int pos)
	{
		unsigned int* pData = (unsigned int*)&nData;
		int nTemp = 1;
		for(int i = 0;i < (pos - 1);i++)
		{
			nTemp *= 10;
		}
		return ((*pData) / nTemp) % 10;
	}
	inline int _HeapSort_Parent(T* pFirst,T* pCur)
	{
		if(pCur >= pFirst)
			return (pCur - pFirst + 1)/2 - 1;
		else
			return -1;
	}
	inline int _HeapSort_Left(T* pFirst,T* pCur)
	{
		if(pCur >= pFirst)
			return (pCur - pFirst + 1)*2 - 1;
		else
			return -1;
	}
	inline int _HeapSort_Right(T* pFirst,T* pCur)
	{
		if(pCur >= pFirst)
			return (pCur - pFirst + 1)*2;
		else
			return -1;
	}
	Compare m_pFun;								//Comparasion function pointer of the specified data
	SORT	m_eSort;
};

#endif