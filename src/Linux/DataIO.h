#pragma once
#ifndef _DATAIO_H
#define _DATAIO_H
#include "common.h"

template <typename T>

class DataIO
{
public:
	DataIO()
	{
		m_pData = NULL;
		m_nDataByte = 0;
	}
	~DataIO()
	{
		if(m_pData)
			delete[] m_pData;
		m_nDataByte = 0;
	}
	unsigned int GetDataByte(void);
	T* GetDataFromFile(string strFileName,const int nEachRow);
	T* GetDataFromStdIO(const int nEachRow);
private:
	void SetDataByte(unsigned int nDataByte);
	ifstream m_fInput;
	T* m_pData;
	unsigned int m_nDataByte;
};

#endif