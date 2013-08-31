#ifndef _ABSTRACT_BASE_H
#define _ABSTRACT_BASE_H

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
	virtual void Description(void) const = 0;
private:
	CLASS_TYPE m_ctType;
	string m_strTitle;
};

#endif