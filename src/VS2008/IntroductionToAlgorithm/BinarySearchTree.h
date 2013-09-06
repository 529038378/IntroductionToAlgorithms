#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"

template <typename T>
struct BSTNode
{
	BSTNode()
	{
		pLeft = NULL;
		pRight = NULL;
		pParent = NULL;
	}
	BSTNode* pLeft;
	BSTNode* pRight;
	BSTNode* pParent;
	T nData;
};

template <typename T>
class BinarySearchTree : public AbstractBase
{
public:
	typedef int (*Compare)(T x, T y);
	BinarySearchTree();
	BinarySearchTree(Compare pFun);
	~BinarySearchTree();
	void Description(void) const;
	void Test();
	bool IsEmpty();
	BSTNode<T>* Search(T nData);
	bool Insert(T nData);
	bool Delete(T nData);
	BSTNode<T>* Minimum();
	BSTNode<T>* Maximum();
	BSTNode<T>* Predecessor(BSTNode<T>* pNode);
	BSTNode<T>* Successor(BSTNode<T>* pNode);
	void PreorderTraverse();
	void InorderTraverse();
	void PostorderTraverse();
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
	BSTNode<T>* m_pRoot;
};
#endif