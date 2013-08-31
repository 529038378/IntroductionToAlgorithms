#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "common.h"
#include "ArrayStack.h"

class Display
{
public:
	Display(){};
	~Display(){};
	void Show();
private:
	void Welcome();
	void ShowDataStructItems();
	void ShowAlgorithmAndPracticalIssuesItems();
};

#endif