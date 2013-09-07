#pragma once
#ifndef _DATAIO_H
#define _DATAIO_H
#include "common.h"


/**************************************************************
**	File:			DataIO.h
**	Description:	The Definition of the  Class DataIO,
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/


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
	T* GetDataFromFile(string strFileName,const int nEachRow);			//Get data from specified file(you must set the parameter nEachRow which is stand for the number of the data in each row)
	T* GetDataFromStdIO(const int nEachRow);							//Get data from standard IO
private:
	void SetDataByte(unsigned int nDataByte);
	ifstream m_fInput;
	T* m_pData;															//Data array pointer
	unsigned int m_nDataByte;											//Data size
};

#endif