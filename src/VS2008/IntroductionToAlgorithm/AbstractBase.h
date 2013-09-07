#ifndef _ABSTRACT_BASE_H
#define _ABSTRACT_BASE_H

/**************************************************************
**	File:			AbstractBase.h
**	Description:	The Definition of the  Class AbstractBase,
**					Other classes should be derived from it.
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/

#include "common.h"

class AbstractBase
{
public:
	AbstractBase()
	{
		m_ctType = OTHER;
		m_strTitle = "";
	}
	string GetTitle(void)
	{
		return m_strTitle;
	}
	void SetTitle(string strTitle)
	{
		m_strTitle = strTitle;
	}
	CLASS_TYPE GetClassType()
	{
		return m_ctType;
	}
	void SetClassType(CLASS_TYPE ctType)
	{
		m_ctType = ctType;
	}
	virtual ~AbstractBase(){};
	virtual void Description(void) const = 0;			//Every sub class should implement the method
	virtual void Test() = 0;							//Every sub class should implement the method
private:
	CLASS_TYPE m_ctType;								//Stand for the class type
	string m_strTitle;									//Short description of the class
};

#endif