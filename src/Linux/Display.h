#ifndef _DISPLAY_H
#define _DISPLAY_H

/**************************************************************
**	File:			Display.h
**	Description:	The Definition of the  Class Display
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/



#include "common.h"
#include "ArrayStack.h"
#include "ArrayStack.cpp"
#include "ListStack.h"
#include "ListStack.cpp"
#include "ArrayQueue.h"
#include "ArrayQueue.cpp"
#include "CycleDoublyLinkList.h"
#include "CycleDoublyLinkList.cpp"
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "RedBlackTree.h"
#include "RedBlackTree.cpp"
#include "MergeFindSet.h"
#include "MergeFindSet.cpp"
#include "HashTable.h"
#include "HashTable.cpp"
#include "SortAlgorithms.h"
#include "SortAlgorithms.cpp"

class Display
{
public:
	Display(){};
	~Display(){};
	void Show();								//Show the related items
	void ClearScreen();							//Clear the screen in the terminal
private:
	void Welcome();								//Show the welcome page
	void ShowDataStructItems();
	void ShowAllSortsItems();
	void ShowAlgorithmAndPracticalIssuesItems();
};

#endif