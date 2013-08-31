#ifndef _ITA_COMMON_H
#define _ITA_COMMON_H

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

enum CLASS_TYPE {OTHER = -1,DATA_STRUCT,ALGORITHM,PRACTICAL_ISSUE,INTERVIEW_ISSUE};
enum DATA_TYPE {CHAR = 1,INT};

#define DEFAULT_STACK_SIZE	10
#define ERROR_EMPTY			255
#define ERROR_FULL			254

#define ERROR_REPORT_STRING			"*************************Error Report**************************"
#define ERROR_REPORT_END_STRING		"***********************Error Report End*************************"
#define STAR_STRING					"***************************************************************"
#define WELCOME_STRING				"****************************Welcome****************************"
#define TEST_BEGIN_STRING			"*************************Test Begin****************************"
#define TEST_END_STRING				"**************************Test End*****************************"

#define TRACE(fmt) \
	cerr<<ERROR_REPORT_STRING<<endl;	\
	cerr<<"Error Message:	"<<##fmt<<endl<<"In File->"<<__FILE__<<endl<<"Line->"<<__LINE__<<endl<<"Function->"<<__FUNCTION__<<endl; \
	cerr<<ERROR_REPORT_END_STRING<<endl<<endl

#endif