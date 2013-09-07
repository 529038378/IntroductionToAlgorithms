#ifndef _REDBLACKTREE_H
#define _REDBLACKTREE_H

/**************************************************************
**	File:			RedBlackTree.h
**	Description:	The Definition of the Class RedBlackTree
**	Author:			Daiyl
**	Date:			2013.8
**************************************************************/


#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"

template <typename T>
struct RBTNode									//Red black node
{
	RBTNode()
	{
		pLeft = NULL;
		pRight = NULL;
		pParent = NULL;
		eColor = BLACK;
	}
	RBTNode* pLeft;								//Left pointer of the node
	RBTNode* pRight;							//Right pointer of the node
	RBTNode* pParent;							//Parent pointer of the node
	T nData;									//Data of the node
	COLOR eColor;								//Color of the node
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
	bool Insert(T nData);								//Insert the specified data
	bool InsertFixUp(RBTNode<T>* pNode);				//Fixup the node's color of the tree
	bool Delete(T nData);								//Delete the specified data
	bool DeleteFixUp(RBTNode<T>* pNode);				//Fixup the node's color after delete the node
	RBTNode<T>* Minimum();
	RBTNode<T>* Maximum();
	RBTNode<T>* Predecessor(RBTNode<T>* pNode);
	RBTNode<T>* Successor(RBTNode<T>* pNode);
	void PreorderTraverse();
	void InorderTraverse();
	void PostorderTraverse();
	void LeftRotate(RBTNode<T>* pNode);					//LeftRotate the tree whose root is pNode
	void RightRotate(RBTNode<T>* pNode);				//RightRotate the tree whose root is pNode
private:
	void SetNodeInfo(RBTNode<T>* pNode,RBTNode<T>* pLeft,RBTNode<T>* pRight,RBTNode<T>* pParent,COLOR eColor);
	bool Delete(RBTNode<T>* pNode);
	RBTNode<T>* Minimum(RBTNode<T>* pNode);
	RBTNode<T>* Maximum(RBTNode<T>* pNode);
	RBTNode<T>* Search(RBTNode<T>* pNode,T nData);
	void PreorderTraverse(RBTNode<T>*pNode);
	void InorderTraverse(RBTNode<T>*pNode);
	void PostorderTraverse(RBTNode<T>*pNode);
	RBTNode<T>* m_pRoot;								//Root of the tree
	RBTNode<T>* m_pNil;									//All leaf node's children is linked to the nil node, the root's parent also is nil
	Compare m_pFun;										//Comparasion function of the node data
};

#endif