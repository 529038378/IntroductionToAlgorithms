#include "SortAlgorithms.h"

/**************************************************************
**	File:			SortAlgorithms.cpp
**	Description:	The implementation of the  Sort Algorithms,
**	Author:			Daiyl
**	Date:			2013.10
**************************************************************/

template <typename T>
SortAlgorithms<T>::SortAlgorithms()
{
	SetClassType(ALGORITHM);
	SetSortType(INSERTION_SORT);
	SetTitle("Sort Algorithms:	Insertion Sort");
	m_pFun = DefaultCompare<T>;
}

template <typename T>
SortAlgorithms<T>::SortAlgorithms(SORT eSort,Compare pFun)
{
	SetClassType(ALGORITHM);
	SetSortType(eSort);
	m_pFun = pFun;
	switch(eSort)
	{
	case INSERTION_SORT:
		SetTitle("Sort Algorithms:	Insertion Sort");
		break;
	case BITONIC_SORT:
		SetTitle("Sort Algorithms:	Bitonic Sort");
		break;
	case ODD_EVEN_SORT:
		SetTitle("Sort Algorithms:	Odd Even Sort");
		break;
	case BUBBLE_SORT:
		SetTitle("Sort Algorithms:	Bubble Sort");
		break;
	case COCKTAIL_SHAKER_SORT:
		SetTitle("Sort Algorithms:	Cocktail Shaker Sort");
		break;
	case GNOME_SORT:
		SetTitle("Sort Algorithms:	Gnome Sort");
		break;
	case HEAP_SORT:
		SetTitle("Sort Algorithms:	Heap Sort");
		break;
	case MERGE_SORT:
		SetTitle("Sort Algorithms:	Merge Sort");
		break;
	case QUICK_SORT:
		SetTitle("Sort Algorithms:	Quick Sort");
		break;
	case RADIX_SORT_LSD:
		SetTitle("Sort Algorithms:	Radix Sort(LSD)");
		break;
	case RADIX_SORT_MSD:
		SetTitle("Sort Algorithms:	Radix Sort(MSD)");
		break;
	case SELECTION_SORT:
		SetTitle("Sort Algorithms:	Selection Sort");
		break;
	case SHELL_SORT:
		SetTitle("Sort Algorithms:	Shell Sort");
		break;
	case COUNTING_SORT:
		SetTitle("Sort Algorithms:	Counting Sort");
		break;
	default:
		cout<<"Set Sort Type error,so the sort typpe is set to be Insertion Sort as default!"<<endl;
		SetTitle("Sort Algorithms:	Insertion Sort");
		SetSortType(INSERTION_SORT);
		break;
	}
}

template <typename T>
SortAlgorithms<T>::~SortAlgorithms()
{
}


template <typename T>
void SortAlgorithms<T>::Description() const
{
	     
	cout<<STAR_STRING<<endl;
	cout<<"DESCRIPTION:"<<endl;
	cout<<"Referenced From:"<<endl;
	cout<<"http://en.wikipedia.org/wiki/Sort_algorithm"<<endl;
	cout<<"A sorting algorithm is an algorithm that puts elements of"<<endl;
	cout<<"a list in a certain order. The most-used orders are numerical"<<endl;
	cout<<"order and lexicographical order. Efficient sorting is"<<endl;
	cout<<"important for optimizing the use of other algorithms "<<endl;
	cout<<"(such as search and merge algorithms) which require"<<endl;
	cout<<"input data to be in sorted lists; it is also often useful"<<endl;
	cout<<"for canonicalizing data and for producing human-readable"<<endl;
	cout<<"output."<<endl;
	cout<<"THE USEFUL CHINESE URL IShttp://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95"<<endl;
	cout<<STAR_STRING<<endl;
	cout<<endl;
}

template <typename T>
void SortAlgorithms<T>::Test()
{
#define LINE_NUMBER 10
	DataIO<T> dataIO;
	cout<<endl<<TEST_BEGIN_STRING<<endl;
	cout<<"Let's See The Test of Sort Algorithms"<<endl;
	T* pData = dataIO.GetRandomData(10);				//Get random data from DataIO class
	if(pData != NULL)
	{
		unsigned int nDataByte = dataIO.GetDataByte();	//Get the length of data
		cout<<"Before the sort, the data sequence is as follows:"<<endl;
		for(unsigned int i = 0;i < nDataByte;i++)
		{
			cout<<pData[i]<<"\t";
			if(((i+1)%LINE_NUMBER) == 0)
				cout<<endl;
		}
		//test here
		SORT eSort = GetSortType();
		switch(eSort)
		{
		case INSERTION_SORT:
			//InsertionSort(pData,pData + nDataByte -1,DefaultCompare);
			InsertionSort(pData + nDataByte -1,pData,DefaultCompare);
			break;
		case BITONIC_SORT:
			//BitonicSort(pData,pData + nDataByte - 1,true,DefaultCompare);
			BitonicSort(pData + nDataByte - 1,pData,true,DefaultCompare);
			break;
		case ODD_EVEN_SORT:
			OddEvenSort(pData,pData + nDataByte - 1,DefaultCompare);
			break;
		case BUBBLE_SORT:
			//BubbleSort(pData,pData + nDataByte - 1,DefaultCompare);
			BubbleSort(pData + nDataByte - 1,pData,DefaultCompare);
			break;
		case COCKTAIL_SHAKER_SORT:
			CocktailShakerSort(pData,pData + nDataByte - 1,DefaultCompare);
			//CocktailShakerSort(pData + nDataByte - 1,pData,DefaultCompare);
			break;
		case GNOME_SORT:
			GnomeSort(pData,pData + nDataByte - 1,DefaultCompare);
			//GnomeSort(pData + nDataByte - 1,pData,DefaultCompare);
			break;
		case HEAP_SORT:
			//HeapSort(pData,pData + nDataByte -1,DefaultCompare);
			HeapSort(pData + nDataByte -1,pData,DefaultCompare);
			break;
		case MERGE_SORT:
			MergeSort(pData,pData + nDataByte - 1,DefaultCompare);
			break;
		case QUICK_SORT:
			QuickSort(pData,pData + nDataByte - 1,DefaultCompare);
			break;
		case RADIX_SORT_LSD:
			//RadixSortLSD(pData,pData + nDataByte - 1);
			RadixSortLSD(pData + nDataByte - 1,pData);
			break;
		case RADIX_SORT_MSD:
			//RadixSortMSD(pData,pData + nDataByte -1,RADIX_MAX);
			RadixSortMSD(pData + nDataByte -1,pData,RADIX_MAX);
			break;
		case SELECTION_SORT:
			SelectionSort(pData,pData + nDataByte - 1,DefaultCompare);
			//SelectionSort(pData + nDataByte - 1,pData,DefaultCompare);
			break;
		case SHELL_SORT:
			ShellSort(pData,pData + nDataByte - 1,DefaultCompare);
			break;
		case COUNTING_SORT:
			//First, make the random values between 0 and COUNTING_SORT_MAX_VAL
			for(unsigned int i=0;i<nDataByte;i++)
			{
				pData[i] = pData[i] % COUNTINT_SORT_MAX_VAL;
			}
			cout<<"The real data is:"<<endl;
			for(unsigned int i = 0;i < nDataByte;i++)
			{
				cout<<pData[i]<<"\t";
				if(((i+1)%LINE_NUMBER) == 0)
					cout<<endl;
			}
			CountingSort(pData,pData + nDataByte - 1,COUNTINT_SORT_MAX_VAL);
			break;
		default:
			cout<<"Set Sort Type error,so the sort typpe is set to be Insertion Sort as default!"<<endl;
			SetTitle("Sort Algorithms:	Insertion Sort");
			SetSortType(INSERTION_SORT);
			break;
		}
		cout<<"After the sort, the data sequence is as follows:"<<endl;
		for(unsigned int i = 0;i < nDataByte;i++)
		{
			cout<<pData[i]<<"\t";
			if(((i+1)%LINE_NUMBER) == 0)
				cout<<endl;
		}
		cout<<TEST_END_STRING<<endl<<endl;
	}
}

template <typename T>
void SortAlgorithms<T>::SetSortType(SORT eSort)						//You must set sort type before use the class's member function
{
	m_eSort = eSort;
	switch(eSort)
	{
	case INSERTION_SORT:
		SetTitle("Sort Algorithms:	Insertion Sort");
		break;
	case BITONIC_SORT:
		SetTitle("Sort Algorithms:	Bitonic Sort");
		break;
	case ODD_EVEN_SORT:
		SetTitle("Sort Algorithms:	Odd Even Sort Sort");
		break;
	case BUBBLE_SORT:
		SetTitle("Sort Algorithms:	Bubble Sort");
		break;
	case COCKTAIL_SHAKER_SORT:
		SetTitle("Sort Algorithms:	Cocktail Shaker Sort");
		break;
	case GNOME_SORT:
		SetTitle("Sort Algorithms:	Gnome Sort");
		break;
	case HEAP_SORT:
		SetTitle("Sort Algorithms:	Heap Sort");
		break;
	case MERGE_SORT:
		SetTitle("Sort Algorithms:	Merge Sort");
		break;
	case QUICK_SORT:
		SetTitle("Sort Algorithms:	Quick Sort");
		break;
	case RADIX_SORT_LSD:
		SetTitle("Sort Algorithms:	Radix Sort(LSD)");
		break;
	case RADIX_SORT_MSD:
		SetTitle("Sort Algorithms:	Radix Sort(MSD)");
		break;
	case SELECTION_SORT:
		SetTitle("Sort Algorithms:	Selection Sort");
		break;
	case SHELL_SORT:
		SetTitle("Sort Algorithms:	Shell Sort");
		break;
	case COUNTING_SORT:
		SetTitle("Sort Algorithms:	Counting Sort");
		break;
	default:
		cout<<"Set Sort Type error,so the sort typpe is set to be Insertion Sort as default!"<<endl;
		SetTitle("Sort Algorithms:	Insertion Sort");
		SetSortType(INSERTION_SORT);
		break;
	}
}

template <typename T>
SORT SortAlgorithms<T>::GetSortType() const
{
	return m_eSort;
}

template <typename T>
void SortAlgorithms<T>::SetCompareFunction(Compare pFun)
{
	m_pFun = pFun;
}

template <typename T>
void SortAlgorithms<T>::Swap(T& A,T& B)					//利用引用交换两个元素
{
	T temp = A;
	A = B;
	B = temp;
}

//选择排序：每次选择剩余数组中的最小元素放入元素前部，并将相应指针后移
template <typename T>
bool SortAlgorithms<T>::SelectionSort(T* pFirst,T* pLast,Compare pFun)
{
	bool bIsReverse = false;
	T* pTemp = NULL;
	T* pSwaped = NULL;
	T* pKey;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)								//设置的指针反向，则先交换指针值
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	if(pFun != NULL)
	{
		SetCompareFunction(pFun);					//若pFun不为NULL，则设置默认比较函数
	}
	//从头遍历数组
	for(pSwaped = pFirst,pTemp = pSwaped + 1;pSwaped < pLast;pSwaped++)
	{
		pKey = pSwaped;
		pTemp = pSwaped + 1;
		while(pTemp < pLast + 1)					//每次遍历选择最小元素
		{
			if(*pTemp < *pKey)
			{
				pKey = pTemp;
			}
			pTemp++;
		}
		Swap(*pKey,*pSwaped);						//交换当前最小元素指针pKey所指的元素与交换指针pSwaped的值
	}
	if(bIsReverse)									//若输入指针反向，则交换数组中的元素
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	return true;
}

//插入排序：顺序遍历数组过程当中，将当前指针数组插入到数组前部的已排好序的数组当中
template <typename T>
bool SortAlgorithms<T>::InsertionSort(T* pFirst,T* pLast,Compare pFun)
{
	bool bIsReverse = false;
	T* pTemp = NULL; 
	T nKey;
	T* pI = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	if(pFun != NULL)
	{
		SetCompareFunction(pFun);
	}
	pTemp = pFirst + 1;										//从第二个元素开始遍历，即默认第一个元素已经排好序
	for(pTemp = pFirst + 1;pTemp < (pLast + 1);pTemp++)
	{
		nKey = *pTemp;										//获取当前元素
		pI = pTemp - 1;										//为当前要插入的元素查找插入位置
		while((pI >= pFirst) && (m_pFun(*pI,nKey) > 0))
		{
			*(pI + 1) = *(pI);
			--pI;
		}
		*(pI + 1) = nKey;									//将当前元素插入到数组前部中
	}
	if(bIsReverse)
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	return true;
}

//快速排序子程序Partition（也是快排的主排序程序）：
template <typename T>
T* SortAlgorithms<T>::Partition(T* pP,T* pR)
{
	T nX = *pR;								//pR指向当前数组中的最后的元素，即pivot元素
	T* pI = pP -1;							//pI指向所有小于pivot元素的最后，即pI之前的元素均小于等于pivot
	T* pJ = pP;								//pJ指向第一个大于pivot的元素，即pJ之后的元素均大于pivot
	while(pJ < pR)							//从pJ开始遍历数组
	{
		if(m_pFun(nX,*pJ) >= 0)				//若pJ所指元素小于等于pR，则移动指针pI并交换pI与pJ的元素
		{
			++pI;
			Swap(*pI,*pJ);
		}
		++pJ;								//若pJ所指元素大于pR，则移动指针pI
	}
	Swap(*(pI+1),*pR);						//最后交换pI+1和pR的所指的元素，即将pivot放到数组中的正确位置
	return pI + 1;							//返回当前pivot的指针
}

//快速排序：先通过Partition子程序对数组进行划分，得到当前pivot元素指针，然后递归对pivot元素前后的子数组进行快排
template <typename T>
bool SortAlgorithms<T>::QuickSort(T* pFirst,T* pLast,Compare pFun)
{
	T* pQ = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		return false;
	}
	if(pFun != NULL)
	{
		SetCompareFunction(pFun);
	}
	if(pFirst < pLast)
	{
		int nRand = rand();						//产生随机数
		int nNum = abs((pFirst - pLast));		//计算当前数组元素个数
		if(nNum != 0)
		{
			int nSel = nRand % nNum;			//随机选择pivot元素索引
			Swap(*pLast,*(pFirst+nSel));		//将选择的pivot元素与最后的元素交换
		}
		pQ = Partition(pFirst,pLast);			//对元素进行Partition
		QuickSort(pFirst,pQ - 1);				//对pivot前的元素快速排序
		QuickSort(pQ + 1,pLast);				//对pivot后的元素快速排序
	}
	return true;
}

//归并排序子程序（Merge过程），其为归并排序的主过程
template <typename T>
void SortAlgorithms<T>::Merge(T* pP,T* pQ,T* pR)//pP指向数组第一个元素，pQ指向左侧数组的最后一个元素，pR指向数组最后的元素
{
	int nWholeLength = abs(pR - pP) + 1;		//计算当前数组长度，数组左右两侧数组是已排序的
	int nLeft = abs(pQ - pP) + 1;				//pQ左边元素个数
	int nRight = abs(pR - pQ);					//pQ右边元素个数
	T* pArrayLeft = new T[nLeft];				//动态申请辅助数组空间
	T* pArrayRight = new T[nRight];
	int nIndexLeft = 0;							//左边数组及右边数组索引
	int nIndexRight = 0;
	for(int i=0;i<nLeft;i++)					//为辅助数组赋值
	{
		pArrayLeft[i] = *(pP+i);
	}
	for(int i=0;i<nRight;i++)
	{
		pArrayRight[i] = *(pQ+i+1);
	}
	for(int i=0;i<nWholeLength;i++)				//遍历数组
	{
		if((nIndexLeft < nLeft) && (nIndexRight < nRight))
		{	
			//比较左右两侧数组的大小，若左侧数组元素较小，则将次元素放入原数组中，并增加左侧数组索引值，若右侧数组元素较小，做相同操作
			if(m_pFun(pArrayLeft[nIndexLeft],pArrayRight[nIndexRight])<=0)
			{
				*(pP+i) = pArrayLeft[nIndexLeft];
				++nIndexLeft;
			}
			else
			{
				*(pP+i) = pArrayRight[nIndexRight];
				++nIndexRight;
			}
		}
		else
		{
			//若只剩一侧数组，则将剩余元素赋值回原数组中
			if(nIndexLeft < nLeft)
			{
				*(pP+i) = pArrayLeft[nIndexLeft];
				++nIndexLeft;
			}
			else
			{
				if(nIndexRight < nRight)
				{
					*(pP+i) = pArrayRight[nIndexRight];
					++nIndexRight;
				}
			}
		}
	}
	delete []pArrayLeft;
	delete []pArrayRight;
}

//归并排序：递归合并已排好序的左右数组到原数组中实现排序
template <typename T>
bool SortAlgorithms<T>::MergeSort(T* pFirst,T* pLast,Compare pFun)
{
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		return false;
	}
	if(pFun != NULL)
	{
		SetCompareFunction(pFun);
	}
	if(pFirst < pLast)
	{
		int nNum = abs((pLast - pFirst));
		int nSel = nNum / 2;						//计算当前数组中间索引值
		MergeSort(pFirst,pFirst + nSel);			//对左侧数组进行递归归并排序
		MergeSort(pFirst + nSel + 1,pLast);			//对右侧数组进行递归归并排序
		Merge(pFirst,pFirst + nSel,pLast);			//将已排序的左右侧数组放回原数组中
	}
	return true;
}

//冒泡排序：遍历数组，在每次遍历数组过程中，从数组最后向前循环交换相邻数组，使相邻元素有序，则在每次交换过程中，当前
//数组的最小元素都会向冒泡一样移动到数组的最前部
template <typename T>
bool SortAlgorithms<T>::BubbleSort(T* pFirst,T* pLast,Compare pFun)
{
	bool bIsReverse = false;
	T* pTemp = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	if(pFun != NULL)
	{
		SetCompareFunction(pFun);
	}
	T* pI = pFirst;
	T* pJ = pLast;
	for(pI = pFirst;pI < pLast;pI++)			//遍历数组
	{
		for(pJ = pLast;pJ > pI;pJ--)			//从数组最后向前遍历
		{
			if(m_pFun(*pJ,*(pJ-1))<0)			//若当前元素pJ比其前的数组小，则交换这两个元素
			{
				Swap(*pJ,*(pJ-1));
			}
		}
	}
	if(bIsReverse)
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	return true;
}

//最大化堆过程，堆排的重要子程序，保持最大堆性质，即父节点元素值大于等于其子孙节点元素
template <typename T>
void SortAlgorithms<T>::MaxHeapify(T* pFirst, const int nLength, const int nI)
{
	if((nI < 0) || (pFirst == NULL) || (nI > nLength))
	{
		cout<<"Parameters error"<<endl;
		return;
	}
	int nLeft = _HeapSort_Left(pFirst,pFirst+nI);								//获取当前节点的左儿子索引
	int nRight = _HeapSort_Right(pFirst,pFirst+nI);								//获取当前节点的右儿子索引
	T* pLargest = NULL;															//初始化记录最大值的指针
	if((nLeft < nLength) && (m_pFun(*(pFirst + nI), *(pFirst + nLeft)) < 0))	//若当前元素小于左儿子，则对最大值指针赋值为左儿子指针
	{
		pLargest = pFirst + nLeft;
	}
	else
	{
		pLargest = pFirst + nI;
	}
	if((nRight < nLength) && (m_pFun(*(pLargest),*(pFirst + nRight)) < 0))		//若右儿子元素大于最大值元素，则对最大值指针赋值
	{
		pLargest = pFirst + nRight;
	}
	if(pLargest != (pFirst + nI))												//当前元素指针不为最大值，则交换最大值与当前元素值
	{
		Swap(*pLargest,*(pFirst + nI));
		{
			MaxHeapify(pFirst, nLength, pLargest - pFirst);						//对交换后后的子堆递归进行堆的最大化过程
		}
	}
}

template <typename T>
bool SortAlgorithms<T>::BuildMaxHeap(T* pFirst,T* pLast)						//建立最大堆函数
{
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Parameters error"<<endl;
		return false;
	}
	int nLength = pLast - pFirst + 1;											//获取当前堆数组长度
	int nMid = nLength / 2;
	//对对数组的前半数据进行堆最大化过程，因为后半部分数据为叶子节点数据，已经保持了最大堆性质
	for(int i=nMid;i>=0;i--)
	{
		MaxHeapify(pFirst,nLength,i);
	}
	return true;
}

//堆排序过程
template <typename T>
bool SortAlgorithms<T>::HeapSort(T* pFirst,T* pLast,Compare pFun)
{
	bool bIsReverse = false;
	T* pTemp = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	if(pFun != NULL)
	{
		SetCompareFunction(pFun);
	}
	BuildMaxHeap(pFirst,pLast);											//利用输入数组元素建立最大堆
	int nLength = pLast - pFirst + 1;									//获取当前数组长度
	pTemp = pFirst;
	for(int i=nLength-1;i>0;i--)										//从后向前遍历数组
	{
		Swap(*(pTemp + i),*pFirst);										//第一个元素（数组最大值）与当前值交换
		--nLength;														//减小数组长度
		MaxHeapify(pFirst,nLength,0);									//从第一个元素开始对对数组进行最大化过程，即保持堆数组性质
	}
	if(bIsReverse)
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	return true;
}

//计数排序，前置条件为事先知道要排序的数组的数值范围，首先对数组中元素进行计数，计算各数值前面的元素的个数（即此数值在排序数组中的位置）
//然后再根据计数数组中的值对辅助数组赋值，最后将辅助数组中的值复制回原数组中
template <typename T>
bool SortAlgorithms<T>::CountingSort(T* pFirst,T* pLast,const int nMaxValue)
{
	bool bIsReverse = false;
	T* pTemp = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	const int nLength = pLast - pFirst + 1;						//计算当前数组长度
	int* pCountArray = new int[nMaxValue];						//申请与当前数值范围相同的辅助数组
	T* pTempArray = new T[nLength];								//申请与当前数组长度相同的辅助数组
	pTemp = pFirst;
	for(int i=0;i<nMaxValue;i++)								//初始化计数数组
	{
		pCountArray[i] = 0;
	}
	for(int i=0;i<nLength;i++)									//计算各数组元素值的个数
	{
		pCountArray[*pTemp] = pCountArray[*pTemp] + 1;
		++pTemp;
	}
	for(int i=1;i<nMaxValue;i++)								//计算各数组元素数值前元素的个数
	{
		pCountArray[i] = pCountArray[i] + pCountArray[i-1];
	}
	for(int i=nLength-1;i>=0;i--)								//从后向前遍历，根据计数数组中的记录值将数组放入辅助数组
	{
		pTempArray[pCountArray[(int)pFirst[i]]-1] = pFirst[i];
		--pCountArray[(int)pFirst[i]];
	}
	for(int i=0;i<nLength;i++)									//将数值赋值回原数组
	{
		pFirst[i] = pTempArray[i];
	}
	if(bIsReverse)
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	delete []pCountArray;
	delete []pTempArray;
	return true;
}

//此函数为基数排序LSD的子过程
//根据基数数组进行计数排序，其过程与计数排序不同的是在对辅助数组赋值时是通过基数数组中记录的元素个数来进行的，而不是原数组
template <typename T>
bool SortAlgorithms<T>::CountingSortWithRadixArray(T* pFirst,T* pLast,int* pRadixFirst,const int nMaxValue)
{
	bool bIsReverse = false;
	T* pTemp = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	const int nLength = pLast - pFirst + 1;
	int* pCountArray = new int[nMaxValue];
	T* pTempArray = new T[nLength];
	pTemp = pRadixFirst;
	for(int i=0;i<nMaxValue;i++)
	{
		pCountArray[i] = 0;
	}
	for(int i=0;i<nLength;i++)											//对基数数组进行计数
	{
		pCountArray[*pTemp] = pCountArray[*pTemp] + 1;
		++pTemp;
	}
	for(int i=1;i<nMaxValue;i++)										//计算计数数组中各数值元素前元素的个数
	{
		pCountArray[i] = pCountArray[i] + pCountArray[i-1];
	}
	for(int i=nLength-1;i>=0;i--)										//通过基数数组对计数数组赋值
	{
		pTempArray[pCountArray[pRadixFirst[i]]-1] = pFirst[i];
		--pCountArray[pRadixFirst[i]];
	}
	for(int i=0;i<nLength;i++)
	{
		pFirst[i] = pTempArray[i];
	}
	if(bIsReverse)
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	delete []pCountArray;
	delete []pTempArray;
	return true;
}

//基数排序LSD：对整数（这里针对32位整数）分别按从个位向高位进行排序，遍历完整数的所有位后，此数组即完成排序
template <typename T>
bool SortAlgorithms<T>::RadixSortLSD(T* pFirst,T* pLast)
{
	bool bIsReverse = false;
	T* pTemp = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	int nLength = pLast - pFirst + 1;									//计算数组长度
	int* pRadixArray = new T[nLength];									//申请辅助数组
	T* pTempArray = new T[nLength];
	pTemp = pFirst;
	bool bIsOK = false;
	for(int i=0;i<nLength;i++)											//初始化辅助数组
	{
		pRadixArray[i] = 0;
	}
	int nPos = 1;
	while(!bIsOK)
	{
		bIsOK = true;
		for(int i=0;i<nLength;i++)
		{
			int nPosNum = _RadixSort_GetNumInPos(pTemp[i],nPos);		//获取当前位的数值
			pRadixArray[i] = nPosNum;									//为辅助数组赋值
			if(pRadixArray[i] > 0)										//若当前辅助数组有一个数大于0，则下次继续循环向下一高位排序
				bIsOK = false;
		}
		++nPos;
		if(bIsOK)														//若当前数组中高位均为0，则完成排序
			break;
		CountingSortWithRadixArray(pFirst,pLast,pRadixArray,RADIX_NUM);	//这里采用稳定的计数排序按数组中每位数值进行排序
	}
	if(bIsReverse)
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	delete []pRadixArray;
	delete []pTempArray;
	return true;
}

//基数排序MSD：对数组中的元素（这里指32位整数）从高位向低位进行排序，在每次排序过程中，并不合并整个数组中的元素
//而是对于当前位置上具有相同数值的数对应的子数组递归进行基数排序MSD，直到所有数组完成排序再将子数组合并
template <typename T>
bool SortAlgorithms<T>::RadixSortMSD(T* pFirst,T* pLast,const int nPos)	//MSD实现模板
{
	bool bIsReverse = false;
	T* pTemp = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	int nLength = pLast - pFirst + 1;									//计算数组长度
	T*  pBucket = new T[nLength];										//为数组子桶申请空间
	int* pCount = new int[RADIX_NUM];
	for(int i=0;i<RADIX_NUM;i++)
	{
		pCount[i] = 0;
	}
	for(pTemp=pFirst;pTemp<=pLast;pTemp++)								//利用稳定计数排序对特定位置上的数对应的数组元素进行排序
	{
		pCount[_RadixSort_GetNumInPos(*pTemp,nPos)]++;
	}
	for(int i=1;i<RADIX_NUM;i++)
	{
		pCount[i] = pCount[i] + pCount[i-1];
	}
	for(pTemp = pLast;pTemp>=pFirst;pTemp--)
	{
		int j = _RadixSort_GetNumInPos(*pTemp,nPos);
		pBucket[pCount[j]-1] = *pTemp;
		--pCount[j];
	}
	for(int i=0;i<nLength;i++)											//将排序后的值放回原数组中
	{
		pFirst[i] = pBucket[i];
	}
	delete []pBucket;
	for(int i=0;i<RADIX_NUM;i++)
	{
		int nLeft = pCount[i];											//此值为当前子桶的左边界
		int nRight = pCount[i+1] - 1;									//此值为当前子桶的右边界
		if(nLeft < nRight && nPos > 1)
		{
			RadixSortMSD(pFirst+nLeft,pFirst+nRight,nPos-1);			//对子数组递归进行MSD排序
		}
	}
	delete []pCount;
	if(bIsReverse)
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	return true;
}

//Shell排序实际为指定了特定数值选择间隔的插入排序，通过指定选择间隔，对每隔此间隔的长度的数进行插入排序
//每次对特定间隔下数组完成排序后，就减小此间隔，最后一次排序即为普通插入排序
template <typename T>
bool SortAlgorithms<T>::ShellSort(T* pFirst,T* pLast,Compare pFun)
{
	bool bIsReverse = false;
	T* pTemp = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	if(pFun != NULL)
	{
		SetCompareFunction(pFun);
	}
	int nLength = pLast - pFirst + 1;
	T nTemp;
	T* pI = NULL;
	for(int nGap = nLength/2;nGap > 0;nGap/=2)										//指定步长间隔为当前数组长度的1/2
	{
		for(pTemp = pFirst + nGap;pTemp<=pLast;pTemp++)								//按指定间隔从头遍历数组
		{
			nTemp = *pTemp;
			for(pI = pTemp - nGap;pI >= pFirst && m_pFun(*pI,nTemp) > 0;pI-=nGap)	//对每个间隔下的数进行插入排序
			{
				*(pI+nGap) = *(pI);
			}
			*(pI+nGap) = nTemp;														//将特定数组插入子数组中
		}
	}
	if(bIsReverse)
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	return true;
}

//鸡尾酒排序，也叫搅拌排序，是冒泡排序的一种轻微变形，不同的地方在于排序从低到高然后再从高到低摇摆进行
//而冒泡排序则仅从低到高去比较序列里的每个元素。
template <typename T>
bool SortAlgorithms<T>::CocktailShakerSort(T* pFirst,T* pLast,Compare pFun)
{
	bool bIsReverse = false;
	T* pTemp = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	if(pFun != NULL)
	{
		SetCompareFunction(pFun);
	}
	T* pTempFirst = pFirst;
	T* pTempLast = pLast;
	while(pTempFirst < pTempLast)								//首指针小于尾指针时进行循环
	{
		for(pTemp = pTempFirst;pTemp < pTempLast;pTemp++)		//从前往后进行冒泡，当相邻元素不是升序则交换两元素
		{
			if(m_pFun(*pTemp,*(pTemp+1)) > 0)
			{
				Swap(*pTemp,*(pTemp+1));
			}
		}
		pTempLast--;											//经过冒泡，当前最大元素已就位，故尾指针减1
		for(pTemp = pTempLast;pTemp > pTempFirst;pTemp--)		//从后往前进行冒泡，当相邻元素不是降序则交换两元素
		{
			if(m_pFun(*pTemp,*(pTemp-1)) < 0)
			{
				Swap(*pTemp,*(pTemp-1));
			}
		}
		pTempFirst++;											//经过冒泡，当前最小元素已就位，故头指针加1
	}
	if(bIsReverse)
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	return true;
}

//Gnome排序号称最简单的排序，整个排序只有一层循环，其主要思想是遍历数组过程中从第二个元素开始比较
//其余前一个元素的值是否有序，若无序则交换这两个值，且循环索引减1，直到相邻元素有序则循环索引加1
//遍历完数组后，完成排序
template <typename T>
bool SortAlgorithms<T>::GnomeSort(T* pFirst,T* pLast,Compare pFun)
{
	bool bIsReverse = false;
	T* pTemp = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	if(pFun != NULL)
	{
		SetCompareFunction(pFun);
	}
	T* pTempFirst = pFirst;
	T* pTempLast = pLast;
	while(pTempFirst <= pTempLast)							//首指针小于尾指针时进行循环
	{
		if(pTempFirst == pFirst)							//当循环到第一个指针，则循环指针向前移动
		{
			pTempFirst++;
			continue;
		}
		if(m_pFun(*pTempFirst,*(pTempFirst-1)) > 0)			//当前元素与其前一元素有序，则循环指针向前移动
		{
			pTempFirst++;
		}
		else
		{
			Swap(*pTempFirst,*(pTempFirst-1));				//当前指针与其前一元素顺序错误，则交换这两个元素，循环指针向后移动
			pTempFirst--;
		}
	}
	if(bIsReverse)
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	return true;
}

template <typename T>
void SortAlgorithms<T>::BitonicMerge(T* pFirst,T* pLast,bool bDirection)
{
	T* pTemp = pFirst;
	if(pFirst < pLast)
	{
		int nLength = pLast - pFirst + 1;
		int nMid = 1;
		while(nMid < nLength)
			nMid = nMid << 1;
		nMid = nMid >> 1;
		for(int i=0;i< nLength - nMid;i++)
		{
			if((m_pFun(*(pTemp+i),*(pTemp+i+nMid)) > 0 ) == bDirection)
			{
				Swap(*(pTemp+i),*(pTemp+i+nMid));
			}
		}
		BitonicMerge(pFirst,pFirst+nMid-1,bDirection);
		BitonicMerge(pFirst+nMid,pLast,bDirection);
	}
}


//Bitonic排序（双调排序）：属于排序网络(Sorting Network）的一种，它是一种可以并行计算的排序算法。
//首先，双调序列是指序列要么先单调递增然后再单调递减，要么先单调递减然后又单调递增。
//通过对要排序的数组构造双调序列，然后递归进行双调归并即可完成对数组的排序
template <typename T>
bool SortAlgorithms<T>::BitonicSort(T* pFirst,T* pLast,bool bDirection,Compare pFun)
{
	bool bIsReverse = false;
	T* pTemp = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	if(pFun != NULL)
	{
		SetCompareFunction(pFun);
	}
	if(pFirst < pLast)
	{
		int nNum = pLast - pFirst + 1;
		int nMid = nNum / 2;
		BitonicSort(pFirst,pFirst+nMid-1,!bDirection);
		BitonicSort(pFirst+nMid,pLast,bDirection);
		BitonicMerge(pFirst,pLast,bDirection);
	}
	if(bIsReverse)
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	return true;
}

//奇偶排序：交替对数组中的奇数列和偶数列的相邻元素进行比较，使其有序，交替进行此过程，直到数组完全有序为止
template <typename T>
bool SortAlgorithms<T>::OddEvenSort(T* pFirst,T* pLast,Compare pFun)
{
	bool bIsReverse = false;
	T* pTemp = NULL;
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Input parameters error!"<<endl;
		return false;
	}
	if(pFirst > pLast)
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	if(pFun != NULL)
	{
		SetCompareFunction(pFun);
	}
	bool bSorted = false;
	int nLength = pLast - pFirst + 1;					//计算数组长度
	pTemp = pFirst;
	while(!bSorted)										//排序停止标志位
	{
		bSorted = true;									//循环开始时置标志位为已排好序
		for(int i=0;i<nLength - 1;i+=2)					//对奇数列排序
		{
			if(m_pFun(*(pTemp+i),*(pTemp+i+1)) > 0)		//不满足有序则交换相邻元素
			{
				Swap(*(pTemp+i),*(pTemp+i+1));
				bSorted = false;
			}
		}
		for(int i=1;i<nLength-1;i+=2)					//对偶数列排序
		{
			if(m_pFun(*(pTemp+i),*(pTemp+i+1)) > 0)
			{
				Swap(*(pTemp+i),*(pTemp+i+1));
				bSorted = false;
			}
		}
	}
	if(bIsReverse)
	{
		while(pFirst < pLast)
		{
			Swap(*pFirst,*pLast);
			++pFirst;
			--pLast;
		}
	}
	return true;
}