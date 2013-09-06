#ifndef _REDBLACKTREE_H
#define _REDBLACKTREE_H

#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"

template <typename T>
struct RBTNode
{
	RBTNode()
	{
		pLeft = NULL;
		pRight = NULL;
		pParent = NULL;
		eColor = BLACK;
	}
	RBTNode* pLeft;
	RBTNode* pRight;
	RBTNode* pParent;
	T nData;
	COLOR eColor;
};

static string gStrColor[2] = {"Red","Black"};


template <typename T>
class RedBlackTree : public AbstractBase
{
public:
	typedef int (*Compare)(T x, T y);
	RedBlackTree();
	RedBlackTree(Compare pFun);
	~RedBlackTree();
	void Description(void) const;
	void Test();
	bool IsEmpty();
	RBTNode<T>* Search(T nData);
	bool Insert(T nData);
	bool InsertFixUp(RBTNode<T>* pNode);
	bool Delete(T nData);
	bool DeleteFixUp(RBTNode<T>* pNode);
	RBTNode<T>* Minimum();
	RBTNode<T>* Maximum();
	RBTNode<T>* Predecessor(RBTNode<T>* pNode);
	RBTNode<T>* Successor(RBTNode<T>* pNode);
	void PreorderTraverse();
	void InorderTraverse();
	void PostorderTraverse();
	void LeftRotate(RBTNode<T>* pNode);
	void RightRotate(RBTNode<T>* pNode);
private:
	void SetNodeInfo(RBTNode<T>* pNode,RBTNode<T>* pLeft,RBTNode<T>* pRight,RBTNode<T>* pParent,COLOR eColor);
	bool Delete(RBTNode<T>* pNode);
	RBTNode<T>* Minimum(RBTNode<T>* pNode);
	RBTNode<T>* Maximum(RBTNode<T>* pNode);
	RBTNode<T>* Search(RBTNode<T>* pNode,T nData);
	void PreorderTraverse(RBTNode<T>*pNode);
	void InorderTraverse(RBTNode<T>*pNode);
	void PostorderTraverse(RBTNode<T>*pNode);
	RBTNode<T>* m_pRoot;
	RBTNode<T>* m_pNil;
	Compare m_pFun;
};

#endif