#include "Display.h"

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

void Display::Welcome()
{
	cout<<WELCOME_STRING<<endl;
	cout<<"This is a Project about the Implement of Data Structs, Algorithms and Practical Issues."<<endl;
	cout<<"Please Select the Item you are Interest in:"<<endl;
	cout<<"1.	Data Structs;"<<endl;
	cout<<"2.	Algorithms and Practical Issues;"<<endl;
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
Begin:
	cout<<WELCOME_STRING<<endl;
	cout<<"This is the Implement of Data Structs"<<endl;
	cout<<"Please Select the Item you are Interest in:"<<endl;
	cout<<"1.	Stack(Implement of Array);"<<endl;
	cout<<"2.	Stack(Implement of List);"<<endl;
	cout<<"3.	Queue(Implement of Array);"<<endl;
	cout<<"4.	Cycle Doubly Linked List"<<endl;
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
			cout<<dsArrayStack.GetTitle().c_str()<<endl;
			dsArrayStack.Description();
			dsArrayStack.Test();
			goto Begin;
			break;
		case 2:
			cout<<lsListStack.GetTitle().c_str()<<endl;
			lsListStack.Description();
			lsListStack.Test();
			goto Begin;
			break;
		case 3:
			cout<<aqArrayQueue.GetTitle().c_str()<<endl;
			aqArrayQueue.Description();
			aqArrayQueue.Test();
			goto Begin;
			break;
		case 4:
			cout<<dcllCycleDoublyLinkList.GetTitle().c_str()<<endl;
			dcllCycleDoublyLinkList.Description();
			dcllCycleDoublyLinkList.Test();
			goto Begin;
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
			goto Begin;
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

void Display::ClearScreen()
{
#ifdef WIN32
	system("cls");
#else
	system("clear");
#endif
}