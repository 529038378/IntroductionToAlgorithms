#include "Display.h"

/**************************************************************
**	File:			Display.h
**	Description:	The implementation of the  Class Display
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/


void Display::Show()
{
	int nSelect;
Begin:
	Welcome();
	while(1)
	{
		cin>>nSelect;
		if(cin.fail())
		{
			ClearScreen();
			cout<<"Input Error! Please Select Again!"<<endl;
			cin.clear();
			cin.sync();
			goto Begin;
		}
		ClearScreen();
		switch(nSelect)
		{
		case 1:
			ShowDataStructItems();
			break;
		case 2:
			ShowAllSortsItems();
		case 3:
			ShowAlgorithmAndPracticalIssuesItems();
			break;
		case 99:
			exit(0);
			break;
		default:
			ClearScreen();
			cout<<"Select Error! Please Select Again!"<<endl;
			cin.clear();
			cin.sync();
			Welcome();
			break;
		}
	}
}

void Display::Welcome()							//Show welcome page strings
{
	cout<<WELCOME_STRING<<endl;
	cout<<"This is a Project about the Implement of Data Structs, Algorithms and Practical Issues."<<endl;
	cout<<"Please Select the Item you are Interest in:"<<endl;
	cout<<"1.	Data Structs;"<<endl;
	cout<<"2.	All kinds of sorts;"<<endl;
	cout<<"3.	Algorithms and Practical Issues;"<<endl;
	cout<<"99.	Quit."<<endl;
	cout<<STAR_STRING<<endl;
	cout<<endl<<endl;
}

void Display::ShowDataStructItems()
{
	ArrayStack<int> dsArrayStack;
	ListStack<int>	lsListStack;
	ArrayQueue<int> aqArrayQueue;
	CycleDoublyLinkList<int> dcllCycleDoublyLinkList;
	BinarySearchTree<int> bstBinarySearchTree;
	RedBlackTree<int> rbtRedBlackTree;
	MergeFindSet<int> mfsMergeFindSet;
	HashTable<int> htHashTable;
	cout<<WELCOME_STRING<<endl;
	cout<<"This is the Implement of Data Structs"<<endl;
	cout<<"Please Select the Item you are Interest in:"<<endl;
	cout<<"1.	Stack(Implement of Array);"<<endl;
	cout<<"2.	Stack(Implement of List);"<<endl;
	cout<<"3.	Queue(Implement of Array);"<<endl;
	cout<<"4.	Cycle Doubly Linked List"<<endl;
	cout<<"5.	Binary Search Tree"<<endl;
	cout<<"6.	Red Black Tree"<<endl;
	cout<<"7.	Merge Find Set"<<endl;
	cout<<"8.	Hash Table"<<endl;
	cout<<"98.	Up Layer;"<<endl;
	cout<<"99.	Quit."<<endl;
	cout<<STAR_STRING<<endl;
	cout<<endl;
	int nSelect;
	while(1)
	{
		cin>>nSelect;
		if(cin.fail())
		{
			ClearScreen();
			cout<<"Input Error! Please Select Again!"<<endl;
			cin.clear();
			cin.sync();
			ShowDataStructItems();
		}
		ClearScreen();
		switch(nSelect)
		{
		case 1:
			cout<<dsArrayStack.GetTitle().c_str()<<endl;
			dsArrayStack.Description();
			dsArrayStack.Test();
			ShowDataStructItems();
			break;
		case 2:
			cout<<lsListStack.GetTitle().c_str()<<endl;
			lsListStack.Description();
			lsListStack.Test();
			ShowDataStructItems();
			break;
		case 3:
			cout<<aqArrayQueue.GetTitle().c_str()<<endl;
			aqArrayQueue.Description();
			aqArrayQueue.Test();
			ShowDataStructItems();
			break;
		case 4:
			cout<<dcllCycleDoublyLinkList.GetTitle().c_str()<<endl;
			dcllCycleDoublyLinkList.Description();
			dcllCycleDoublyLinkList.Test();
			ShowDataStructItems();
			break;
		case 5:
			cout<<bstBinarySearchTree.GetTitle().c_str()<<endl;
			bstBinarySearchTree.Description();
			bstBinarySearchTree.Test();
			ShowDataStructItems();
			break;
		case 6:
			cout<<rbtRedBlackTree.GetTitle().c_str()<<endl;
			rbtRedBlackTree.Description();
			rbtRedBlackTree.Test();
			ShowDataStructItems();
			break;
		case 7:
			cout<<mfsMergeFindSet.GetTitle().c_str()<<endl;
			mfsMergeFindSet.Description();
			mfsMergeFindSet.Test();
			ShowDataStructItems();
			break;
		case 8:
			cout<<htHashTable.GetTitle().c_str()<<endl;
			htHashTable.Description();
			htHashTable.Test();
			ShowDataStructItems();
			break;
		case 98:
			goto ShowWelcome;
			break;
		case 99:
			exit(0);
			break;
		default:
			ClearScreen();
			cout<<"Select Error! Please Select Again!"<<endl;
			cin.clear();
			cin.sync();
			ShowDataStructItems();
			break;
		}
	}
ShowWelcome:
	Show();
	return;
}

void Display::ShowAlgorithmAndPracticalIssuesItems()
{
Begin:
	cout<<WELCOME_STRING<<endl;
	cout<<"This is the Implement of Algorithms and Practical Issues."<<endl;
	cout<<"Please Select the Item you are Interest in:"<<endl;
	cout<<"98.	Up Layer;"<<endl;
	cout<<"99.	Quit."<<endl;
	cout<<STAR_STRING<<endl;
	cout<<endl;
	int nSelect;
	while(1)
	{
		cin>>nSelect;
		if(cin.fail())
		{
			ClearScreen();
			cout<<"Input Error! Please Select Again!"<<endl;
			cin.clear();
			cin.sync();
			goto Begin;
		}
		ClearScreen();
		switch(nSelect)
		{
		case 98:
			goto ShowWelcome;
			break;
		case 99:
			exit(0);
			break;
		default:
			ClearScreen();
			cout<<"Select Error! Please Select Again!"<<endl;
			cin.clear();
			cin.sync();
			goto Begin;
			break;
		}
	}
ShowWelcome:
	Show();
	return;
}

void Display::ShowAllSortsItems()
{
	SortAlgorithms<int> saSortAlgorithms;
	Begin:
	cout<<WELCOME_STRING<<endl;
	cout<<"This is the Implement of Algorithms and Practical Issues."<<endl;
	cout<<"Please Select the Item you are Interest in:"<<endl;
	cout<<"1.	Selection Sort;"<<endl;
	cout<<"2.	Insertion Sort;"<<endl;
	cout<<"3.	Quick Sort;"<<endl;
	cout<<"4.	Merge Sort;"<<endl;
	cout<<"5.	Heap Sort;"<<endl;
	cout<<"6.	Radix Sort(LSD);"<<endl;
	cout<<"7.	Radix Sort(MSD);"<<endl;
	cout<<"8.	Shell Sort;"<<endl;
	cout<<"9.	Bubble Sort;"<<endl;
	cout<<"10.	Cocktail Shaker Sort;"<<endl;
	cout<<"11.	Gnome Sort;"<<endl;
	cout<<"12.	Bitonic Sort;"<<endl;
	cout<<"13.	Odd Even Sort;"<<endl;
	cout<<"14.	Counting Sort;"<<endl;
	cout<<"98.	Up Layer;"<<endl;
	cout<<"99.	Quit."<<endl;
	cout<<STAR_STRING<<endl;
	cout<<endl;
	int nSelect;
	while(1)
	{
		cin>>nSelect;
		if(cin.fail())
		{
			ClearScreen();
			cout<<"Input Error! Please Select Again!"<<endl;
			cin.clear();
			cin.sync();
			goto Begin;
		}
		ClearScreen();
		switch(nSelect)
		{
		case 1:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(SELECTION_SORT);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 2:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(INSERTION_SORT);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 3:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(QUICK_SORT);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 4:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(MERGE_SORT);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 5:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(HEAP_SORT);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 6:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(RADIX_SORT_LSD);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 7:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(RADIX_SORT_MSD);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 8:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(SHELL_SORT);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 9:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(BUBBLE_SORT);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 10:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(COCKTAIL_SHAKER_SORT);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 11:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(GNOME_SORT);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
		break;
		case 12:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(BITONIC_SORT);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 13:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(ODD_EVEN_SORT);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 14:
			cout<<saSortAlgorithms.GetTitle().c_str()<<endl;
			saSortAlgorithms.Description();
			saSortAlgorithms.SetSortType(COUNTING_SORT);
			saSortAlgorithms.Test();
			ShowAllSortsItems();
			break;
		case 98:
			goto ShowWelcome;
			break;
		case 99:
			exit(0);
			break;
		default:
			ClearScreen();
			cout<<"Select Not Available! Please Select Again!"<<endl;
			cin.clear();
			cin.sync();
			goto Begin;
			break;
		}
	}
ShowWelcome:
	Show();
	return;
}


void Display::ClearScreen()							//Clear screen by use of system()
{
#ifdef WIN32
	system("cls");
#else
	system("clear");
#endif
}