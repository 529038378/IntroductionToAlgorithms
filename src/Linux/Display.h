#ifndef _DISPLAY_H
#define _DISPLAY_H

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

class Display
{
public:
	Display(){};
	~Display(){};
	void Show();
	void ClearScreen();
private:
	void Welcome();
	void ShowDataStructItems();
	void ShowAlgorithmAndPracticalIssuesItems();
};

#endif