#ifndef _ITA_COMMON_H
#define _ITA_COMMON_H

/**************************************************************
**	File:			common.h
**	Description:	Global Definition of the Macros ,other
**					default method and parameters
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

//Class type enum: data struct/algorithm/practical issue/interview issue
enum CLASS_TYPE {OTHER = -1,DATA_STRUCT,ALGORITHM,PRACTICAL_ISSUE,INTERVIEW_ISSUE};

#define DEFAULT_STACK_SIZE				10
#define ERROR_EMPTY						255
#define ERROR_FULL						254
#define DEFAULT_MERGESET_SIZE			100

//Specification star strings
#define ERROR_REPORT_STRING			"*************************Error Report**************************"
#define ERROR_REPORT_END_STRING		"***********************Error Report End*************************"
#define STAR_STRING					"***************************************************************"
#define WELCOME_STRING				"****************************Welcome****************************"
#define TEST_BEGIN_STRING			"*************************Test Begin****************************"
#define TEST_END_STRING				"**************************Test End*****************************"

//Error report
#define TRACE(fmt) \
	cerr<<endl<<ERROR_REPORT_STRING<<endl;	\
	cerr<<"Error Message:	"<<fmt<<endl<<"In File->"<<__FILE__<<endl<<"Line->"<<__LINE__<<endl<<"Function->"<<__FUNCTION__<<endl; \
	cerr<<ERROR_REPORT_END_STRING<<endl<<endl

template <typename T>
int DefaultCompare(T x,T y)
{
	if(x-y>0)
	{
		return 1;
	}
	else
	{
		if(x-y==0)
			return 0;
		else
			return -1;
	}
}

//Color enum used in the implementation of red black tree
enum COLOR {RED = 0,BLACK = 1};

#endif