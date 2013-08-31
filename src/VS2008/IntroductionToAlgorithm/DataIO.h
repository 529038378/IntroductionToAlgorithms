#ifndef _DATAIO_H
#define _DATAIO_H
#include "common.h"

class DataIO
{
public:
	DataIO()
	{
		m_pData = NULL;
		m_dtType = CHAR;
		m_nDataByte = 0;
	}
	DataIO(DATA_TYPE dtType)
	{
		m_pData = NULL;
		m_dtType = dtType;
		m_nDataByte = 0;
	}
	~DataIO()
	{
		if(m_pData)
			delete[] m_pData;
		m_nDataByte = 0;
	}
	void SetDataType(DATA_TYPE dtType);
	unsigned int GetDataByte(void);
	void* GetDataFromFile(string strFileName,const int nEachRow);
	void* GetDataFromStdIO(const int nEachRow);
private:
	void SetDataByte(unsigned int nDataByte);
	ifstream m_fInput;
	void* m_pData;
	DATA_TYPE m_dtType;
	unsigned int m_nDataByte;
};

#endif