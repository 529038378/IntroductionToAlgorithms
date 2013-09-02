#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "common.h"
#include "ArrayStack.h"
#include "ArrayStack.cpp"
#include "ListStack.h"
#include "ListStack.cpp"

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