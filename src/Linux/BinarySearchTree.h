#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

/**************************************************************
**	File:			BinarySearchTree.h
**	Description:	The Definition of the  Class BinarySearchTree,
**					Implementation of the BinarySearchTree struct.
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/


#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"

template <typename T>
struct BSTNode
{
	BSTNode()												//Constructor of the node
	{
		pLeft = NULL;
		pRight = NULL;
		pParent = NULL;
	}
	BSTNode* pLeft;											//The left child of the node
	BSTNode* pRight;										//The right child of the node
	BSTNode* pParent;										//The parent child of the node
	T nData;												//The data of the node
};

template <typename T>
class BinarySearchTree : public AbstractBase
{
public:
	typedef int (*Compare)(T x, T y);						//Compare method which is used for the key data comparasion
	BinarySearchTree();
	BinarySearchTree(Compare pFun);							//Constructor specify the Used defined Compare method
	~BinarySearchTree();
	void Description(void) const;
	void Test();
	bool IsEmpty();
	BSTNode<T>* Search(T nData);							//Search specified data
	bool Insert(T nData);									//Insert data
	bool Delete(T nData);									//Delete data
	BSTNode<T>* Minimum();									//Return Mininum data pointer in the tree
	BSTNode<T>* Maximum();									//Return Maximum data pointer in the tree
	BSTNode<T>* Predecessor(BSTNode<T>* pNode);				//Return the predecessor pointer of the pNode
	BSTNode<T>* Successor(BSTNode<T>* pNode);				//Return the successor pointer of the pNode
	void PreorderTraverse();								//PreorderTraverse the tree and print the data
	void InorderTraverse();									//InorderTraverse the tree and print the data
	void PostorderTraverse();								//PostorderTraverse the tree and print the data
private:
	void SetNodeInfo(BSTNode<T>* pNode,BSTNode<T>* pLeft,BSTNode<T>* pRight,BSTNode<T>* pParent);
	bool Delete(BSTNode<T>* pNode);
	BSTNode<T>* Minimum(BSTNode<T>* pNode);
	BSTNode<T>* Maximum(BSTNode<T>* pNode);
	BSTNode<T>* Search(BSTNode<T>* pNode,T nData);
	void PreorderTraverse(BSTNode<T>*pNode);
	void InorderTraverse(BSTNode<T>*pNode);
	void PostorderTraverse(BSTNode<T>*pNode);
	Compare m_pFun;
	BSTNode<T>* m_pRoot;									//Root pointer of the tree
};
#endif