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
void SortAlgorithms<T>::Swap(T& A,T& B)					//�������ý�������Ԫ��
{
	T temp = A;
	A = B;
	B = temp;
}

//ѡ������ÿ��ѡ��ʣ�������е���СԪ�ط���Ԫ��ǰ����������Ӧָ�����
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
	if(pFirst > pLast)								//���õ�ָ�뷴�����Ƚ���ָ��ֵ
	{
		bIsReverse = true;
		pTemp = pFirst;
		pFirst = pLast;
		pLast = pTemp;
	}
	if(pFun != NULL)
	{
		SetCompareFunction(pFun);					//��pFun��ΪNULL��������Ĭ�ϱȽϺ���
	}
	//��ͷ��������
	for(pSwaped = pFirst,pTemp = pSwaped + 1;pSwaped < pLast;pSwaped++)
	{
		pKey = pSwaped;
		pTemp = pSwaped + 1;
		while(pTemp < pLast + 1)					//ÿ�α���ѡ����СԪ��
		{
			if(*pTemp < *pKey)
			{
				pKey = pTemp;
			}
			pTemp++;
		}
		Swap(*pKey,*pSwaped);						//������ǰ��СԪ��ָ��pKey��ָ��Ԫ���뽻��ָ��pSwaped��ֵ
	}
	if(bIsReverse)									//������ָ�뷴���򽻻������е�Ԫ��
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

//��������˳�����������̵��У�����ǰָ��������뵽����ǰ�������ź�������鵱��
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
	pTemp = pFirst + 1;										//�ӵڶ���Ԫ�ؿ�ʼ��������Ĭ�ϵ�һ��Ԫ���Ѿ��ź���
	for(pTemp = pFirst + 1;pTemp < (pLast + 1);pTemp++)
	{
		nKey = *pTemp;										//��ȡ��ǰԪ��
		pI = pTemp - 1;										//Ϊ��ǰҪ�����Ԫ�ز��Ҳ���λ��
		while((pI >= pFirst) && (m_pFun(*pI,nKey) > 0))
		{
			*(pI + 1) = *(pI);
			--pI;
		}
		*(pI + 1) = nKey;									//����ǰԪ�ز��뵽����ǰ����
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

//���������ӳ���Partition��Ҳ�ǿ��ŵ���������򣩣�
template <typename T>
T* SortAlgorithms<T>::Partition(T* pP,T* pR)
{
	T nX = *pR;								//pRָ��ǰ�����е�����Ԫ�أ���pivotԪ��
	T* pI = pP -1;							//pIָ������С��pivotԪ�ص���󣬼�pI֮ǰ��Ԫ�ؾ�С�ڵ���pivot
	T* pJ = pP;								//pJָ���һ������pivot��Ԫ�أ���pJ֮���Ԫ�ؾ�����pivot
	while(pJ < pR)							//��pJ��ʼ��������
	{
		if(m_pFun(nX,*pJ) >= 0)				//��pJ��ָԪ��С�ڵ���pR�����ƶ�ָ��pI������pI��pJ��Ԫ��
		{
			++pI;
			Swap(*pI,*pJ);
		}
		++pJ;								//��pJ��ָԪ�ش���pR�����ƶ�ָ��pI
	}
	Swap(*(pI+1),*pR);						//��󽻻�pI+1��pR����ָ��Ԫ�أ�����pivot�ŵ������е���ȷλ��
	return pI + 1;							//���ص�ǰpivot��ָ��
}

//����������ͨ��Partition�ӳ����������л��֣��õ���ǰpivotԪ��ָ�룬Ȼ��ݹ��pivotԪ��ǰ�����������п���
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
		int nRand = rand();						//���������
		int nNum = abs((pFirst - pLast));		//���㵱ǰ����Ԫ�ظ���
		if(nNum != 0)
		{
			int nSel = nRand % nNum;			//���ѡ��pivotԪ������
			Swap(*pLast,*(pFirst+nSel));		//��ѡ���pivotԪ��������Ԫ�ؽ���
		}
		pQ = Partition(pFirst,pLast);			//��Ԫ�ؽ���Partition
		QuickSort(pFirst,pQ - 1);				//��pivotǰ��Ԫ�ؿ�������
		QuickSort(pQ + 1,pLast);				//��pivot���Ԫ�ؿ�������
	}
	return true;
}

//�鲢�����ӳ���Merge���̣�����Ϊ�鲢�����������
template <typename T>
void SortAlgorithms<T>::Merge(T* pP,T* pQ,T* pR)//pPָ�������һ��Ԫ�أ�pQָ�������������һ��Ԫ�أ�pRָ����������Ԫ��
{
	int nWholeLength = abs(pR - pP) + 1;		//���㵱ǰ���鳤�ȣ��������������������������
	int nLeft = abs(pQ - pP) + 1;				//pQ���Ԫ�ظ���
	int nRight = abs(pR - pQ);					//pQ�ұ�Ԫ�ظ���
	T* pArrayLeft = new T[nLeft];				//��̬���븨������ռ�
	T* pArrayRight = new T[nRight];
	int nIndexLeft = 0;							//������鼰�ұ���������
	int nIndexRight = 0;
	for(int i=0;i<nLeft;i++)					//Ϊ�������鸳ֵ
	{
		pArrayLeft[i] = *(pP+i);
	}
	for(int i=0;i<nRight;i++)
	{
		pArrayRight[i] = *(pQ+i+1);
	}
	for(int i=0;i<nWholeLength;i++)				//��������
	{
		if((nIndexLeft < nLeft) && (nIndexRight < nRight))
		{	
			//�Ƚ�������������Ĵ�С�����������Ԫ�ؽ�С���򽫴�Ԫ�ط���ԭ�����У������������������ֵ�����Ҳ�����Ԫ�ؽ�С������ͬ����
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
			//��ֻʣһ�����飬��ʣ��Ԫ�ظ�ֵ��ԭ������
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

//�鲢���򣺵ݹ�ϲ����ź�����������鵽ԭ������ʵ������
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
		int nSel = nNum / 2;						//���㵱ǰ�����м�����ֵ
		MergeSort(pFirst,pFirst + nSel);			//�����������еݹ�鲢����
		MergeSort(pFirst + nSel + 1,pLast);			//���Ҳ�������еݹ�鲢����
		Merge(pFirst,pFirst + nSel,pLast);			//������������Ҳ�����Ż�ԭ������
	}
	return true;
}

//ð�����򣺱������飬��ÿ�α�����������У������������ǰѭ�������������飬ʹ����Ԫ����������ÿ�ν��������У���ǰ
//�������СԪ�ض�����ð��һ���ƶ����������ǰ��
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
	for(pI = pFirst;pI < pLast;pI++)			//��������
	{
		for(pJ = pLast;pJ > pI;pJ--)			//�����������ǰ����
		{
			if(m_pFun(*pJ,*(pJ-1))<0)			//����ǰԪ��pJ����ǰ������С���򽻻�������Ԫ��
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

//��󻯶ѹ��̣����ŵ���Ҫ�ӳ��򣬱����������ʣ������ڵ�Ԫ��ֵ���ڵ���������ڵ�Ԫ��
template <typename T>
void SortAlgorithms<T>::MaxHeapify(T* pFirst, const int nLength, const int nI)
{
	if((nI < 0) || (pFirst == NULL) || (nI > nLength))
	{
		cout<<"Parameters error"<<endl;
		return;
	}
	int nLeft = _HeapSort_Left(pFirst,pFirst+nI);								//��ȡ��ǰ�ڵ�����������
	int nRight = _HeapSort_Right(pFirst,pFirst+nI);								//��ȡ��ǰ�ڵ���Ҷ�������
	T* pLargest = NULL;															//��ʼ����¼���ֵ��ָ��
	if((nLeft < nLength) && (m_pFun(*(pFirst + nI), *(pFirst + nLeft)) < 0))	//����ǰԪ��С������ӣ�������ֵָ�븳ֵΪ�����ָ��
	{
		pLargest = pFirst + nLeft;
	}
	else
	{
		pLargest = pFirst + nI;
	}
	if((nRight < nLength) && (m_pFun(*(pLargest),*(pFirst + nRight)) < 0))		//���Ҷ���Ԫ�ش������ֵԪ�أ�������ֵָ�븳ֵ
	{
		pLargest = pFirst + nRight;
	}
	if(pLargest != (pFirst + nI))												//��ǰԪ��ָ�벻Ϊ���ֵ���򽻻����ֵ�뵱ǰԪ��ֵ
	{
		Swap(*pLargest,*(pFirst + nI));
		{
			MaxHeapify(pFirst, nLength, pLargest - pFirst);						//�Խ��������Ӷѵݹ���жѵ���󻯹���
		}
	}
}

template <typename T>
bool SortAlgorithms<T>::BuildMaxHeap(T* pFirst,T* pLast)						//�������Ѻ���
{
	if((pFirst == NULL) || (pLast == NULL))
	{
		cout<<"Parameters error"<<endl;
		return false;
	}
	int nLength = pLast - pFirst + 1;											//��ȡ��ǰ�����鳤��
	int nMid = nLength / 2;
	//�Զ������ǰ�����ݽ��ж���󻯹��̣���Ϊ��벿������ΪҶ�ӽڵ����ݣ��Ѿ���������������
	for(int i=nMid;i>=0;i--)
	{
		MaxHeapify(pFirst,nLength,i);
	}
	return true;
}

//���������
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
	BuildMaxHeap(pFirst,pLast);											//������������Ԫ�ؽ�������
	int nLength = pLast - pFirst + 1;									//��ȡ��ǰ���鳤��
	pTemp = pFirst;
	for(int i=nLength-1;i>0;i--)										//�Ӻ���ǰ��������
	{
		Swap(*(pTemp + i),*pFirst);										//��һ��Ԫ�أ��������ֵ���뵱ǰֵ����
		--nLength;														//��С���鳤��
		MaxHeapify(pFirst,nLength,0);									//�ӵ�һ��Ԫ�ؿ�ʼ�Զ����������󻯹��̣������ֶ���������
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

//��������ǰ������Ϊ����֪��Ҫ������������ֵ��Χ�����ȶ�������Ԫ�ؽ��м������������ֵǰ���Ԫ�صĸ�����������ֵ�����������е�λ�ã�
//Ȼ���ٸ��ݼ��������е�ֵ�Ը������鸳ֵ����󽫸��������е�ֵ���ƻ�ԭ������
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
	const int nLength = pLast - pFirst + 1;						//���㵱ǰ���鳤��
	int* pCountArray = new int[nMaxValue];						//�����뵱ǰ��ֵ��Χ��ͬ�ĸ�������
	T* pTempArray = new T[nLength];								//�����뵱ǰ���鳤����ͬ�ĸ�������
	pTemp = pFirst;
	for(int i=0;i<nMaxValue;i++)								//��ʼ����������
	{
		pCountArray[i] = 0;
	}
	for(int i=0;i<nLength;i++)									//���������Ԫ��ֵ�ĸ���
	{
		pCountArray[*pTemp] = pCountArray[*pTemp] + 1;
		++pTemp;
	}
	for(int i=1;i<nMaxValue;i++)								//���������Ԫ����ֵǰԪ�صĸ���
	{
		pCountArray[i] = pCountArray[i] + pCountArray[i-1];
	}
	for(int i=nLength-1;i>=0;i--)								//�Ӻ���ǰ���������ݼ��������еļ�¼ֵ��������븨������
	{
		pTempArray[pCountArray[(int)pFirst[i]]-1] = pFirst[i];
		--pCountArray[(int)pFirst[i]];
	}
	for(int i=0;i<nLength;i++)									//����ֵ��ֵ��ԭ����
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

//�˺���Ϊ��������LSD���ӹ���
//���ݻ���������м���������������������ͬ�����ڶԸ������鸳ֵʱ��ͨ�����������м�¼��Ԫ�ظ��������еģ�������ԭ����
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
	for(int i=0;i<nLength;i++)											//�Ի���������м���
	{
		pCountArray[*pTemp] = pCountArray[*pTemp] + 1;
		++pTemp;
	}
	for(int i=1;i<nMaxValue;i++)										//������������и���ֵԪ��ǰԪ�صĸ���
	{
		pCountArray[i] = pCountArray[i] + pCountArray[i-1];
	}
	for(int i=nLength-1;i>=0;i--)										//ͨ����������Լ������鸳ֵ
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

//��������LSD�����������������32λ�������ֱ𰴴Ӹ�λ���λ�������򣬱���������������λ�󣬴����鼴�������
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
	int nLength = pLast - pFirst + 1;									//�������鳤��
	int* pRadixArray = new T[nLength];									//���븨������
	T* pTempArray = new T[nLength];
	pTemp = pFirst;
	bool bIsOK = false;
	for(int i=0;i<nLength;i++)											//��ʼ����������
	{
		pRadixArray[i] = 0;
	}
	int nPos = 1;
	while(!bIsOK)
	{
		bIsOK = true;
		for(int i=0;i<nLength;i++)
		{
			int nPosNum = _RadixSort_GetNumInPos(pTemp[i],nPos);		//��ȡ��ǰλ����ֵ
			pRadixArray[i] = nPosNum;									//Ϊ�������鸳ֵ
			if(pRadixArray[i] > 0)										//����ǰ����������һ��������0�����´μ���ѭ������һ��λ����
				bIsOK = false;
		}
		++nPos;
		if(bIsOK)														//����ǰ�����и�λ��Ϊ0�����������
			break;
		CountingSortWithRadixArray(pFirst,pLast,pRadixArray,RADIX_NUM);	//��������ȶ��ļ�������������ÿλ��ֵ��������
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

//��������MSD���������е�Ԫ�أ�����ָ32λ�������Ӹ�λ���λ����������ÿ����������У������ϲ����������е�Ԫ��
//���Ƕ��ڵ�ǰλ���Ͼ�����ͬ��ֵ������Ӧ��������ݹ���л�������MSD��ֱ������������������ٽ�������ϲ�
template <typename T>
bool SortAlgorithms<T>::RadixSortMSD(T* pFirst,T* pLast,const int nPos)	//MSDʵ��ģ��
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
	int nLength = pLast - pFirst + 1;									//�������鳤��
	T*  pBucket = new T[nLength];										//Ϊ������Ͱ����ռ�
	int* pCount = new int[RADIX_NUM];
	for(int i=0;i<RADIX_NUM;i++)
	{
		pCount[i] = 0;
	}
	for(pTemp=pFirst;pTemp<=pLast;pTemp++)								//�����ȶ�����������ض�λ���ϵ�����Ӧ������Ԫ�ؽ�������
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
	for(int i=0;i<nLength;i++)											//��������ֵ�Ż�ԭ������
	{
		pFirst[i] = pBucket[i];
	}
	delete []pBucket;
	for(int i=0;i<RADIX_NUM;i++)
	{
		int nLeft = pCount[i];											//��ֵΪ��ǰ��Ͱ����߽�
		int nRight = pCount[i+1] - 1;									//��ֵΪ��ǰ��Ͱ���ұ߽�
		if(nLeft < nRight && nPos > 1)
		{
			RadixSortMSD(pFirst+nLeft,pFirst+nRight,nPos-1);			//��������ݹ����MSD����
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

//Shell����ʵ��Ϊָ�����ض���ֵѡ�����Ĳ�������ͨ��ָ��ѡ��������ÿ���˼���ĳ��ȵ������в�������
//ÿ�ζ��ض�����������������󣬾ͼ�С�˼�������һ������Ϊ��ͨ��������
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
	for(int nGap = nLength/2;nGap > 0;nGap/=2)										//ָ���������Ϊ��ǰ���鳤�ȵ�1/2
	{
		for(pTemp = pFirst + nGap;pTemp<=pLast;pTemp++)								//��ָ�������ͷ��������
		{
			nTemp = *pTemp;
			for(pI = pTemp - nGap;pI >= pFirst && m_pFun(*pI,nTemp) > 0;pI-=nGap)	//��ÿ������µ������в�������
			{
				*(pI+nGap) = *(pI);
			}
			*(pI+nGap) = nTemp;														//���ض����������������
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

//��β������Ҳ�н���������ð�������һ����΢���Σ���ͬ�ĵط���������ӵ͵���Ȼ���ٴӸߵ���ҡ�ڽ���
//��ð����������ӵ͵���ȥ�Ƚ��������ÿ��Ԫ�ء�
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
	while(pTempFirst < pTempLast)								//��ָ��С��βָ��ʱ����ѭ��
	{
		for(pTemp = pTempFirst;pTemp < pTempLast;pTemp++)		//��ǰ�������ð�ݣ�������Ԫ�ز��������򽻻���Ԫ��
		{
			if(m_pFun(*pTemp,*(pTemp+1)) > 0)
			{
				Swap(*pTemp,*(pTemp+1));
			}
		}
		pTempLast--;											//����ð�ݣ���ǰ���Ԫ���Ѿ�λ����βָ���1
		for(pTemp = pTempLast;pTemp > pTempFirst;pTemp--)		//�Ӻ���ǰ����ð�ݣ�������Ԫ�ز��ǽ����򽻻���Ԫ��
		{
			if(m_pFun(*pTemp,*(pTemp-1)) < 0)
			{
				Swap(*pTemp,*(pTemp-1));
			}
		}
		pTempFirst++;											//����ð�ݣ���ǰ��СԪ���Ѿ�λ����ͷָ���1
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

//Gnome����ų���򵥵�������������ֻ��һ��ѭ��������Ҫ˼���Ǳ�����������дӵڶ���Ԫ�ؿ�ʼ�Ƚ�
//����ǰһ��Ԫ�ص�ֵ�Ƿ������������򽻻�������ֵ����ѭ��������1��ֱ������Ԫ��������ѭ��������1
//������������������
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
	while(pTempFirst <= pTempLast)							//��ָ��С��βָ��ʱ����ѭ��
	{
		if(pTempFirst == pFirst)							//��ѭ������һ��ָ�룬��ѭ��ָ����ǰ�ƶ�
		{
			pTempFirst++;
			continue;
		}
		if(m_pFun(*pTempFirst,*(pTempFirst-1)) > 0)			//��ǰԪ������ǰһԪ��������ѭ��ָ����ǰ�ƶ�
		{
			pTempFirst++;
		}
		else
		{
			Swap(*pTempFirst,*(pTempFirst-1));				//��ǰָ������ǰһԪ��˳������򽻻�������Ԫ�أ�ѭ��ָ������ƶ�
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


//Bitonic����˫�����򣩣�������������(Sorting Network����һ�֣�����һ�ֿ��Բ��м���������㷨��
//���ȣ�˫��������ָ����Ҫô�ȵ�������Ȼ���ٵ����ݼ���Ҫô�ȵ����ݼ�Ȼ���ֵ���������
//ͨ����Ҫ��������鹹��˫�����У�Ȼ��ݹ����˫���鲢������ɶ����������
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

//��ż���򣺽���������е������к�ż���е�����Ԫ�ؽ��бȽϣ�ʹ�����򣬽�����д˹��̣�ֱ��������ȫ����Ϊֹ
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
	int nLength = pLast - pFirst + 1;					//�������鳤��
	pTemp = pFirst;
	while(!bSorted)										//����ֹͣ��־λ
	{
		bSorted = true;									//ѭ����ʼʱ�ñ�־λΪ���ź���
		for(int i=0;i<nLength - 1;i+=2)					//������������
		{
			if(m_pFun(*(pTemp+i),*(pTemp+i+1)) > 0)		//�����������򽻻�����Ԫ��
			{
				Swap(*(pTemp+i),*(pTemp+i+1));
				bSorted = false;
			}
		}
		for(int i=1;i<nLength-1;i+=2)					//��ż��������
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