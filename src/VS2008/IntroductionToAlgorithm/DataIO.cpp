#include "DataIO.h"

/**************************************************************
**	File:			DataIO.cpp
**	Description:	The implementation of the  Class DataIO,
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/


template <typename T>
T* DataIO<T>::GetRandomData(const int nNumber)
{
	try
	{
		m_pData = new T[nNumber];							//Allocate the memory of the data
	}
	catch(...)
	{
		TRACE("new failure!");
		return NULL;
	}
	SetDataByte(nNumber);
	for(int i=0;i<nNumber;i++)
	{
		m_pData[i] = (T)rand();
	}
	return m_pData;
}

template <typename T>
T* DataIO<T>::GetDataFromFile(const string strFileName,const int nEachRow)
{
	m_fInput.open(strFileName.c_str(),ios_base::in);				//Open the specified file
	int nLine = 0;
	m_fInput>>nLine;												//The first line in the file is the number of the data line in the file
	try
	{
		m_pData = new T[nLine*nEachRow];							//Allocate the memory of the data
	}
	catch(...)
	{
		TRACE("new failure!");
		return NULL;
	}
	SetDataByte(nLine*nEachRow);
	for(int i=0;i<nLine;i++)
	{
		for(int j=0;j<nEachRow;j++)
		{
			m_fInput>>(*(m_pData+i*nEachRow+j));					//Get data from file in each row
		}
	}
	m_fInput.close();
	return m_pData;
}

template <typename T>
T* DataIO<T>::GetDataFromStdIO(const int nEachRow)
{
	int nLine;
	while(1)														//Tell the user input the number to be input
	{
		cout<<"Please Input The Whole Line Number Of Your Data(1~65536)"<<endl;
		cin>>nLine;
		if(cin.fail())
		{
			cout<<"Input Error! Please Select Again!"<<endl;
			cin.clear();
			cin.sync();
			continue;
		}
		if(nLine<=0 || nLine > 65536)
		{
			cout<<"Input Error,Please Input Again!"<<endl;
			cin.clear();
			cin.sync();
			continue;
		}
		else
		{
			break;
		}
	}
	try
	{
		m_pData = new T[nLine*nEachRow];
	}
	catch(...)
	{
		TRACE("new failure!");
		return NULL;
	}
	SetDataByte(nLine*nEachRow);
	for(int i=0;i<nLine;i++)									//Input the data in each row
	{
		cout<<"Please Input The Line: "<<(i+1)<<" Data"<<endl;
		for(int j=0;j<nEachRow;j++)
		{
			cout<<"Please Input Number "<<(j+1)<<" Data Of Line "<<(i+1)<<endl;
			cin>>(*(m_pData+i*nEachRow+j));
			if(cin.fail())
			{
				cout<<"Input Error,Please Input Again!"<<endl;
				cin.clear();
				cin.sync();
				--j;
				continue;
			}
		}
	}
	return m_pData;
}

template <typename T>
unsigned int DataIO<T>::GetDataByte()
{
	return m_nDataByte;
}

template <typename T>
void DataIO<T>::SetDataByte(unsigned int nDataByte)
{
	m_nDataByte = nDataByte;
}