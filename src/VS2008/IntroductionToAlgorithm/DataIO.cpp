#include "DataIO.h"

void* DataIO::GetDataFromFile(const string strFileName,const int nEachRow)
{
	m_fInput.open(strFileName.c_str(),ios_base::in);
	int nLine = 0;
	m_fInput>>nLine;
	if(CHAR == m_dtType)
	{
		try
		{
			m_pData = new char[nLine*nEachRow];
		}
		catch(...)
		{
			TRACE("new failure!");
			return NULL;
		}
	}
	else
	{
		if(INT == m_dtType)
		{
			try
			{
				m_pData = new int[nLine*nEachRow];
			}
			catch(...)
			{
				TRACE("new failure!");
				return NULL;
			}
		}
	}
	SetDataByte(nLine*nEachRow);
	for(int i=0;i<nLine;i++)
	{
		for(int j=0;j<nEachRow;j++)
		{
			if(CHAR == m_dtType)
				m_fInput>>(*(((char*)m_pData+i*nEachRow+j)));
			else
			{
				if(INT == m_dtType)
					m_fInput>>(*((int*)m_pData+i*nEachRow+j));
			}
		}
	}
	m_fInput.close();
	return m_pData;
}

void* DataIO::GetDataFromStdIO(const int nEachRow)
{
	int nLine;
	while(1)
	{
		cout<<"Please Input The Whole Line Number Of Your Data(1~65536)"<<endl;
		cin>>nLine;
		if(nLine<=0)
		{
			cout<<"Input Error,Please Input Again!"<<endl;
			continue;
		}
		else
		{
			break;
		}
	}
	if(CHAR == m_dtType)
	{
		try
		{
			m_pData = new char[nLine*nEachRow];
		}
		catch(...)
		{
			TRACE("new failure!");
			return NULL;
		}
	}
	else
	{
		if(INT == m_dtType)
		{
			try
			{
				m_pData = new int[nLine*nEachRow];
			}
			catch(...)
			{
				TRACE("new failure!");
				return NULL;
			}
		}
	}
	SetDataByte(nLine*nEachRow);
	for(int i=0;i<nLine;i++)
	{
		cout<<"Please Input The Line: "<<(i+1)<<" Data"<<endl;
		for(int j=0;j<nEachRow;j++)
		{
			cout<<"Please Input Number "<<(j+1)<<" Data Of Line "<<(i+1)<<endl;
			if(CHAR == m_dtType)
				cin>>(*(((char*)m_pData+i*nEachRow+j)));
			else
			{
				if(INT == m_dtType)
					cin>>(*((int*)m_pData+i*nEachRow+j));
			}
		}
	}
	return m_pData;
}

unsigned int DataIO::GetDataByte()
{
	return m_nDataByte;
}

void DataIO::SetDataByte(unsigned int nDataByte)
{
	m_nDataByte = nDataByte;
}

void DataIO::SetDataType(DATA_TYPE dtType)
{
	m_dtType = dtType;
}