#include "BinarySearchTree.h"

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	SetClassType(DATA_STRUCT);
	SetTitle("Data Struct: Binary Search Tree");
	m_pRoot = NULL;
	m_pFun = DefaultCompare<T>;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(Compare pFun)
{
	SetClassType(DATA_STRUCT);
	SetTitle("Data Struct: Binary Search Tree");
	m_pRoot = NULL;
	m_pFun = pFun;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	if(m_pRoot != NULL)
	{
		if(m_pRoot->pLeft != NULL)
		{
			Delete(m_pRoot->pLeft);
		}
		if(m_pRoot->pRight != NULL)
		{
			Delete(m_pRoot->pRight);
		}
		delete m_pRoot;
		m_pRoot = NULL;
	}
	m_pFun = NULL;
}

template <typename T>
void BinarySearchTree<T>::SetNodeInfo(BSTNode<T>* pNode,BSTNode<T>* pLeft,BSTNode<T>* pRight,BSTNode<T>* pParent)
{
	pNode->pLeft = pLeft;
	pNode->pRight = pRight;
	pNode->pParent = pParent;
}

template <typename T>
void BinarySearchTree<T>::Description() const
{
	cout<<STAR_STRING<<endl;
	cout<<"DESCRIPTION:"<<endl;
	cout<<"Referenced From:"<<endl;
	cout<<"http://en.wikipedia.org/wiki/Binary_search_tree"<<endl;
	//There must be no duplicate nodes.
	cout<<"In computer science, a binary search tree (BST), sometimes also called an"<<endl;
	cout<<"ordered or sorted binary tree, is a node-based binary tree data structure"<<endl;
	cout<<"which has the following properties:"<<endl;
	cout<<"1.The left subtree of a node contains only nodes with keys less than the node's key."<<endl;
	cout<<"2.The right subtree of a node contains only nodes with keys greater than the node's key."<<endl;
	cout<<"3.The left and right subtree must each also be a binary search tree."<<endl;
	cout<<"Generally, the information represented by each node is a record rather than a "<<endl;
	cout<<"single data element. However, for sequencing purposes, nodes are compared"<<endl;
	cout<<"according to their keys rather than any part of their associated records."<<endl;
	cout<<"THE USEFUL CHINESE URL IS:"<<endl;
	cout<<"http://zh.wikipedia.org/wiki/%E4%BA%8C%E5%85%83%E6%90%9C%E5%B0%8B%E6%A8%B9"<<endl;
	cout<<STAR_STRING<<endl;
	cout<<endl;
}

template <typename T>
void BinarySearchTree<T>::Test()
{
	DataIO<T> dataIO;
	cout<<endl<<TEST_BEGIN_STRING<<endl;
	cout<<"Let's See The Test of Binary Search Tree"<<endl;
	T* pData = dataIO.GetDataFromStdIO(1);
	if(pData != NULL)
	{
		unsigned int nDataByte = dataIO.GetDataByte();
		for(unsigned int i=0;i<nDataByte;i++)
		{
			cout<<"Insert Data:"<<pData[i]<<endl;
			Insert(pData[i]);
		}
		cout<<"PreorderTraverse the Binary Search Tree"<<endl;
		PreorderTraverse();
		cout<<endl<<"InorderTraverse the Binary Search Tree"<<endl;
		InorderTraverse();
		cout<<endl<<"PostorderTraverse the Binary Search Tree"<<endl;
		PostorderTraverse();
		cout<<endl;
		for(unsigned int i=0;i<nDataByte;i++)
		{
			Delete(pData[i]);
			cout<<"Delete Data:"<<pData[i]<<endl;
			cout<<"PreorderTraverse the Binary Search Tree"<<endl;
			PreorderTraverse();
			cout<<endl;
		}
		cout<<TEST_END_STRING<<endl<<endl;
	}
}

template <typename T>
bool BinarySearchTree<T>::IsEmpty()
{
	return (m_pRoot == NULL);
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::Search(T nData)
{
	BSTNode<T>* pTemp = m_pRoot;
	if((pTemp == NULL) || (m_pFun(pTemp->nData,nData) == 0))
	{
		return pTemp;
	}
	if(m_pFun(pTemp->nData,nData)>0)
	{
		return Search(pTemp->pLeft,nData);
	}
	else
	{
		return Search(pTemp->pRight,nData);
	}
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::Search(BSTNode<T>* pNode,T nData)
{
	BSTNode<T>* pTemp = pNode;
	if((pTemp == NULL) || (m_pFun(pTemp->nData,nData) == 0))
	{
		return pTemp;
	}
	if(m_pFun(pTemp->nData,nData)>0)
	{
		return Search(pTemp->pLeft,nData);
	}
	else
	{
		return Search(pTemp->pRight,nData);
	}
}

template <typename T>
bool BinarySearchTree<T>::Insert(T nData)
{
	BSTNode<T>* pTemp = m_pRoot;
	BSTNode<T>* pParent = NULL;
	while(pTemp != NULL)
	{
		pParent = pTemp;
		if(m_pFun(pTemp->nData,nData)>0)
		{
			pTemp = pTemp->pLeft;
		}
		else
		{
			pTemp = pTemp->pRight;
		}
	}
	BSTNode<T>* pNewNode = new BSTNode<T>[1];
	pNewNode->pParent = pParent;
	if(pParent == NULL)
	{
		m_pRoot = pNewNode;
		pNewNode->nData = nData;
		SetNodeInfo(pNewNode,NULL,NULL,pParent);
	}
	else
	{
		if(m_pFun(pParent->nData,nData)>0)
		{
			pParent->pLeft = pNewNode;
			pNewNode->nData = nData;
			SetNodeInfo(pNewNode,NULL,NULL,pParent);
		}
		else
		{
			pParent->pRight = pNewNode;
			pNewNode->nData = nData;
			SetNodeInfo(pNewNode,NULL,NULL,pParent);
		}
	}
	return true;
}

template <typename T>
bool BinarySearchTree<T>::Delete(T nData)
{
	BSTNode<T>* pNode = Search(nData);
	if(pNode != NULL)
	{
		return Delete(pNode);
	}
	else
	{
		return false;
	}
}

template <typename T>
bool BinarySearchTree<T>::Delete(BSTNode<T>* pNode)
{
	BSTNode<T>* pTempY = NULL;
	BSTNode<T>* pTempX = NULL;
	if((pNode->pLeft == NULL) || (pNode->pRight == NULL))
	{
		pTempY = pNode;
	}
	else
	{
		pTempY = Successor(pNode);
	}
	if(pTempY->pLeft != NULL)
	{
		pTempX = pTempY->pLeft;
	}
	else
	{
		pTempX = pTempY->pRight;
	}
	if(pTempX != NULL)
	{
		pTempX->pParent = pTempY->pParent;
	}
	if(pTempY->pParent == NULL)
	{
		m_pRoot = pTempX;
	}
	else
	{
		if(pTempY->pParent->pLeft == pTempY)
		{
			pTempY->pParent->pLeft = pTempX;
		}
		else
		{
			pTempY->pParent->pRight = pTempX;
		}
	}
	if(pTempY != pNode)
	{
		pNode->nData = pTempY->nData;
	}
	if(pTempY != NULL)
	{
		delete pTempY;
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::Minimum()
{
	Minimum(m_pRoot);
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::Minimum(BSTNode<T>* pNode)
{
	BSTNode<T>* pTemp = pNode;
	while(pTemp->pLeft != NULL)
	{
		pTemp = pTemp->pLeft;
	}
	return pTemp;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::Maximum()
{
	Maximum(m_pRoot);
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::Maximum(BSTNode<T>* pNode)
{
	BSTNode<T>* pTemp = pNode;
	while(pTemp->pRight != NULL)
	{
		pTemp = pTemp->pRight;
	}
	return pTemp;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::Predecessor(BSTNode<T> *pNode)
{
	if(pNode->pLeft != NULL)
	{
		return Maximum(pNode->pLeft);
	}
	BSTNode<T>* pTempY = pNode->pParent;
	BSTNode<T>* pTempX = pNode;
	while((pTempY != NULL) && (pTempY->pLeft == pTempX))
	{
		pTempX = pTempY;
		pTempY = pTempY->pParent;
	}
	return pTempY;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::Successor(BSTNode<T> *pNode)
{
	if(pNode->pRight != NULL)
	{
		return Minimum(pNode->pRight);
	}
	BSTNode<T>* pTempY = pNode->pParent;
	BSTNode<T>* pTempX = pNode;
	while((pTempY != NULL) && (pTempY->pRight == pTempX))
	{
		pTempX = pTempY;
		pTempY = pTempY->pParent;
	}
	return pTempY;
}

template <typename T>
void BinarySearchTree<T>::PreorderTraverse()
{
	PreorderTraverse(m_pRoot);
}

template <typename T>
void BinarySearchTree<T>::InorderTraverse()
{
	InorderTraverse(m_pRoot);
}

template <typename T>
void BinarySearchTree<T>::PostorderTraverse()
{
	PostorderTraverse(m_pRoot);
}

template <typename T>
void BinarySearchTree<T>::PreorderTraverse(BSTNode<T>* pNode)
{
	if(pNode != NULL)
	{
		cout<<pNode->nData<<"  ";
		PreorderTraverse(pNode->pLeft);
		PreorderTraverse(pNode->pRight);
	}
}

template <typename T>
void BinarySearchTree<T>::InorderTraverse(BSTNode<T>* pNode)
{
	if(pNode != NULL)
	{
		InorderTraverse(pNode->pLeft);
		cout<<pNode->nData<<"  ";
		InorderTraverse(pNode->pRight);
	}
}

template <typename T>
void BinarySearchTree<T>::PostorderTraverse(BSTNode<T>* pNode)
{
	if(pNode != NULL)
	{
		PostorderTraverse(pNode->pLeft);
		PostorderTraverse(pNode->pRight);
		cout<<pNode->nData<<"  ";
	}
}