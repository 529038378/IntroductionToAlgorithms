#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

/**************************************************************
**	File:			HashTable.h
**	Description:	The Definition of the  Class HashTable,
**					Array implementation of the HashTable.
**	Author:			Daiyl
**	Date:			2013.10
**************************************************************/
#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"

template <typename T>
class HashTable : public AbstractBase
{
public:
	HashTable();
	HashTable(int nSize);
	~HashTable();
	void Description(void) const;
	void Test();								//Design the test method of the hash table
	bool Insert(T nData);						//Insert data into hash table
	bool Delete(T nData);						//Delete data from hash table
	int Search(T nData);						//Search data in hash table
	int UniversalHashingFunction(int nKey,int a,int b,int p,int m);		//h(k) = ((ak+b)mod p)mod m
	int DualHashingFunction(int nKey,int nI);	//h(k,i) = (h1(k) + i*h2(k)) mod m
private:
	int GetTableSize() const;
	T** m_ppArray;								//Hash table array
	int m_nSize;								//Hash table size
	//int m_np;									//for universal hashing
	//int m_na;
	//int m_nb;
	int m_m1;									//for dual hashing
	int m_m2;
	int m_nCur;
};

#endif