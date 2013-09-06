#include "RedBlackTree.h"

template <typename T>
RedBlackTree<T>::RedBlackTree()
{
	SetClassType(DATA_STRUCT);
	SetTitle("Data Struct: Red Black Tree");
	m_pFun = DefaultCompare<T>;
	try
	{
		m_pNil = new RBTNode<T>[1];
		SetNodeInfo(m_pNil,m_pNil,m_pNil,NULL,BLACK);
	}
	catch(...)
	{
		TRACE("new failure");
	}
	m_pRoot = m_pNil;
	m_pRoot->pParent = m_pNil;
}

template <typename T>
RedBlackTree<T>::RedBlackTree(Compare pFun)
{
	SetClassType(DATA_STRUCT);
	SetTitle("Data Struct: Red Black Tree");
	m_pFun = pFun;
	try
	{
		m_pNil = new RBTNode<T>[1];
		SetNodeInfo(m_pNil,m_pNil,m_pNil,NULL,BLACK);
	}
	catch(...)
	{
		TRACE("new failure");
	}
	m_pRoot = m_pNil;
	m_pRoot->pParent = m_pNil;
}

template <typename T>
RedBlackTree<T>::~RedBlackTree()
{
	if(m_pRoot != NULL)
	{
		if(m_pRoot->pLeft != m_pNil)
		{
			Delete(m_pRoot->pLeft);
		}
		if(m_pRoot->pRight != m_pNil)
		{
			Delete(m_pRoot->pRight);
		}
		delete m_pRoot;
		m_pRoot = NULL;
	}
	delete m_pNil;
	m_pNil = NULL;
	m_pFun = NULL;
}

template <typename T>
void RedBlackTree<T>::Description() const 
{
	cout<<STAR_STRING<<endl;
	cout<<"DESCRIPTION:"<<endl;
	cout<<"Referenced From:"<<endl;
	cout<<"http://en.wikipedia.org/wiki/Red_black_tree"<<endl;
	cout<<"A red¨Cblack tree is a type of self-balancing binary search tree,"<<endl;
	cout<<"a data structure used in computer science. The self-balancing is"<<endl;
	cout<<"provided by painting. each node with one of two colors (these are"<<endl;
	cout<<"typically called 'red'and 'black', hence the name of the trees) in"<<endl;
	cout<<"such a way that the resulting painted tree satisfies certain"<<endl;
	cout<<"properties that don't allow it to become significantly unbalanced."<<endl;
	cout<<"When the tree is modified, the new tree is subsequently rearranged"<<endl;
	cout<<"and repainted to restore the coloring properties. The properties are"<<endl;
	cout<<"designed in such a way that this rearranging and recoloring can be"<<endl;
	cout<<"performed efficiently."<<endl;
	cout<<"THE USEFUL CHINESE URL IS:"<<endl;
	cout<<"http://zh.wikipedia.org/wiki/%E7%BA%A2%E9%BB%91%E6%A0%91"<<endl;
	cout<<STAR_STRING<<endl;
	cout<<endl;
}

template <typename T>
void RedBlackTree<T>::Test()
{
	DataIO<T> dataIO;
	cout<<endl<<TEST_BEGIN_STRING<<endl;
	cout<<"Let's See The Test of Red Black Tree"<<endl;
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
			cout<<"PostorderTraverse the Binary Search Tree"<<endl;
			PostorderTraverse();
			cout<<endl;
		}
		cout<<TEST_END_STRING<<endl<<endl;
	}
}

template <typename T>
bool RedBlackTree<T>::IsEmpty()
{
	return (m_pRoot == NULL);
}

template <typename T>
RBTNode<T>* RedBlackTree<T>::Search(T nData)
{
	RBTNode<T>* pTemp = m_pRoot;
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
RBTNode<T>* RedBlackTree<T>::Search(RBTNode<T> *pNode,T nData)
{
	RBTNode<T>* pTemp = pNode;
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
bool RedBlackTree<T>::Insert(T nData)
{
	RBTNode<T>* pTempY = m_pNil;
	RBTNode<T>* pTempX = m_pRoot;
	RBTNode<T>* pNewNode = NULL;
	try
	{ 
		pNewNode = new RBTNode<T>[1];
		pNewNode->nData = nData;
		pNewNode->pLeft = m_pNil;
		pNewNode->pRight = m_pNil;
	}
	catch(...)
	{
		TRACE("new failure");
	}
	while(pTempX != m_pNil)
	{
		pTempY = pTempX;
		if(m_pFun(pTempX->nData,nData)>0)
		{
			pTempX = pTempX->pLeft;
		}
		else
		{
			pTempX = pTempX->pRight;
		}
	}
	pNewNode->pParent = pTempY;
	if(pTempY == m_pNil)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		if(m_pFun(pNewNode->nData,pTempY->nData)<0)
		{
			pTempY->pLeft = pNewNode;
		}
		else
		{
			pTempY->pRight = pNewNode;
		}
	}
	pNewNode->pLeft = m_pNil;
	pNewNode->pRight = m_pNil;
	pNewNode->eColor = RED;
	bool bRet = InsertFixUp(pNewNode);
	return bRet;
}

template <typename T>
bool RedBlackTree<T>::InsertFixUp(RBTNode<T>* pNode)
{
	RBTNode<T>* pTempZ = pNode;
	while(pTempZ->pParent->eColor == RED)
	{
		if(pTempZ->pParent->pParent->pLeft == pTempZ->pParent)
		{
			RBTNode<T>* pTempY = pTempZ->pParent->pParent->pRight;
			if(pTempY->eColor == RED)
			{
				pTempZ->pParent->eColor = BLACK;
				pTempY->eColor = BLACK;
				pTempZ->pParent->pParent->eColor = RED;
				pTempZ = pTempZ->pParent->pParent;
			}
			else
			{
				if(pTempZ->pParent->pRight == pTempZ)
				{
					pTempZ = pTempZ->pParent;
					LeftRotate(pTempZ);
				}
				pTempZ->pParent->eColor = BLACK;
				pTempZ->pParent->pParent->eColor = RED;
				RightRotate(pTempZ->pParent->pParent);
			}
		}
		else
		{
			RBTNode<T>* pTempY = pTempZ->pParent->pParent->pLeft;
			if(pTempY->eColor == RED)
			{
				pTempZ->pParent->eColor = BLACK;
				pTempY->eColor = BLACK;
				pTempZ->pParent->pParent->eColor = RED;
				pTempZ = pTempZ->pParent->pParent;
			}
			else
			{
				if(pTempZ->pParent->pLeft == pTempZ)
				{
					pTempZ = pTempZ->pParent;
					RightRotate(pTempZ);
				}
				pTempZ->pParent->eColor = BLACK;
				pTempZ->pParent->pParent->eColor = RED;
				LeftRotate(pTempZ->pParent->pParent);
			}
		}
	}
	m_pRoot->eColor = BLACK;
	return true;
}

template <typename T>
bool RedBlackTree<T>::Delete(T nData)
{
	RBTNode<T>* pNode = Search(nData);
	if(pNode != m_pNil)
	{
		return Delete(pNode);
	}
	else
	{
		return false;
	}
}

template <typename T>
bool RedBlackTree<T>::Delete(RBTNode<T> *pNode)
{
	RBTNode<T>* pTempZ = pNode;
	RBTNode<T>* pTempY = NULL;
	RBTNode<T>* pTempX = NULL;
	if((pTempZ->pLeft == m_pNil) || (pTempZ->pRight == m_pNil))
	{
		pTempY = pTempZ;
	}
	else
	{
		pTempY = Successor(pTempZ);
	}
	if(pTempY->pLeft != m_pNil)
	{
		pTempX = pTempY->pLeft;
	}
	else
	{
		pTempX = pTempY->pRight;
	}
	pTempX->pParent = pTempY->pParent;
	if(pTempY->pParent == m_pNil)
	{
		m_pRoot = pTempX;
		m_pRoot->pParent = m_pNil;
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
	if(pTempY != pTempZ)
	{
		pTempZ->nData = pTempY->nData;
	}
	if(pTempY->eColor == BLACK)
	{
		DeleteFixUp(pTempX);
	}
	if(pTempY != NULL)
	{
		delete pTempY;
		pTempY = NULL;
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
bool RedBlackTree<T>::DeleteFixUp(RBTNode<T>* pNode)
{
	RBTNode<T>* pTempX = pNode;
	RBTNode<T>* pTempW = NULL;
	while((pTempX != m_pRoot) && (pTempX->eColor == BLACK))
	{
		if(pTempX == pTempX->pParent->pLeft)
		{
			pTempW = pTempX->pParent->pRight;
			if(pTempW->eColor == RED)
			{
				pTempW->eColor = BLACK;
				pTempX->pParent->eColor = RED;
				LeftRotate(pTempX->pParent);
				pTempW = pTempX->pParent->pRight;
			}
				if((pTempW->pLeft->eColor == BLACK) && (pTempW->pRight->eColor == BLACK))
				{
					pTempW->eColor = RED;
					pTempX = pTempX->pParent;
				}
				else
				{
					if(pTempW->pRight->eColor == BLACK)
					{
						pTempW->pLeft->eColor = BLACK;
						pTempW->eColor = RED;
						RightRotate(pTempW);
						pTempW = pTempX->pParent->pRight;
					}
					pTempW->eColor = pTempX->pParent->eColor;
					pTempX->pParent->eColor = BLACK;
					pTempW->pRight->eColor = BLACK;
					LeftRotate(pTempX->pParent);
					pTempX = m_pRoot;
				}
			//}
		}
		else
		{
			pTempW = pTempX->pParent->pLeft;
			if(pTempW->eColor == RED)
			{
				pTempW->eColor = BLACK;
				pTempX->pParent->eColor = RED;
				//LeftRotate(pTempX->pParent);
				RightRotate(pTempX->pParent);
				pTempW = pTempX->pParent->pLeft;
			}
				if((pTempW->pLeft->eColor == BLACK) && (pTempW->pRight->eColor == BLACK))
				{
					pTempW->eColor = RED;
					pTempX = pTempX->pParent;
				}
				else
				{
					if(pTempW->pLeft->eColor == BLACK)
					{
						pTempW->pRight->eColor = BLACK;
						pTempW->eColor = RED;
						//RightRotate(pTempW);
						LeftRotate(pTempW);
						pTempW = pTempX->pParent->pLeft;
					}
					pTempW->eColor = pTempX->pParent->eColor;
					pTempX->pParent->eColor = BLACK;
					pTempW->pLeft->eColor = BLACK;
					//LeftRotate(pTempX->pParent);
					RightRotate(pTempX->pParent);
					pTempX = m_pRoot;
				}
			//}
		}
	}
	pTempX->eColor = BLACK;
	return true;
}

template <typename T>
RBTNode<T>* RedBlackTree<T>::Maximum()
{
	Maximum(m_pRoot);
}

template <typename T>
RBTNode<T>* RedBlackTree<T>::Maximum(RBTNode<T> *pNode)
{
	RBTNode<T>* pTemp = pNode;
	while(pTemp->pRight != m_pNil)
	{
		pTemp = pTemp->pRight;
	}
	return pTemp;
}

template <typename T>
RBTNode<T>* RedBlackTree<T>::Minimum()
{
	Minimum(m_pRoot);
}

template <typename T>
RBTNode<T>* RedBlackTree<T>::Minimum(RBTNode<T>* pNode)
{
	RBTNode<T>* pTemp = pNode;
	while(pTemp->pLeft != m_pNil)
	{
		pTemp = pTemp->pLeft;
	}
	return pTemp;
}

template <typename T>
RBTNode<T>* RedBlackTree<T>::Predecessor(RBTNode<T> *pNode)
{
	if(pNode->pLeft != NULL)
	{
		return Maximum(pNode->pLeft);
	}
	RBTNode<T>* pTempY = pNode->pParent;
	RBTNode<T>* pTempX = pNode;
	while((pTempY != NULL) && (pTempY->pLeft == pTempX))
	{
		pTempX = pTempY;
		pTempY = pTempY->pParent;
	}
	return pTempY;
}

template <typename T>
RBTNode<T>* RedBlackTree<T>::Successor(RBTNode<T>* pNode)
{
	if(pNode->pRight != NULL)
	{
		return Minimum(pNode->pRight);
	}
	RBTNode<T>* pTempY = pNode->pParent;
	RBTNode<T>* pTempX = pNode;
	while((pTempY != NULL) && (pTempY->pRight == pTempX))
	{
		pTempX = pTempY;
		pTempY = pTempY->pParent;
	}
	return pTempY;
}

template <typename T>
void RedBlackTree<T>::PreorderTraverse(RBTNode<T>* pNode)
{
	if(pNode != m_pNil)
	{
		cout<<pNode->nData<<"("<<gStrColor[pNode->eColor].c_str()<<")"<<"  ";
		PreorderTraverse(pNode->pLeft);
		PreorderTraverse(pNode->pRight);
	}
}

template <typename T>
void RedBlackTree<T>::PreorderTraverse()
{
	PreorderTraverse(m_pRoot);
}

template <typename T>
void RedBlackTree<T>::InorderTraverse(RBTNode<T>* pNode)
{
	if(pNode != m_pNil)
	{
		InorderTraverse(pNode->pLeft);
		cout<<pNode->nData<<"("<<gStrColor[pNode->eColor].c_str()<<")"<<"  ";
		InorderTraverse(pNode->pRight);
	}
}

template <typename T>
void RedBlackTree<T>::InorderTraverse()
{
	InorderTraverse(m_pRoot);
}

template <typename T>
void RedBlackTree<T>::PostorderTraverse(RBTNode<T>* pNode)
{
	if(pNode != m_pNil)
	{
		PostorderTraverse(pNode->pLeft);
		PostorderTraverse(pNode->pRight);
		cout<<pNode->nData<<"("<<gStrColor[pNode->eColor].c_str()<<")"<<"  ";
	}
}

template <typename T>
void RedBlackTree<T>::PostorderTraverse()
{
	PostorderTraverse(m_pRoot);
}

template <typename T>
void RedBlackTree<T>::SetNodeInfo(RBTNode<T>* pNode,RBTNode<T>* pLeft,RBTNode<T>* pRight,RBTNode<T>* pParent,COLOR eColor)
{
	pNode->pLeft = pLeft;
	pNode->pRight = pRight;
	pNode->pParent = pParent;
	pNode->eColor = eColor;
}

template <typename T>
void RedBlackTree<T>::LeftRotate(RBTNode<T>* pNode)
{
	if(pNode->pRight != m_pNil)
	{
		RBTNode<T>* pTempX = pNode;
		RBTNode<T>* pTempY = pNode->pRight;
		pTempX->pRight = pTempY->pLeft;
		//if(pTempY->pLeft !=m_pNil)
			pTempY->pLeft->pParent = pTempX;
		pTempY->pParent = pTempX->pParent;
		if(pTempX->pParent == m_pNil)
		{
			m_pRoot = pTempY;
			m_pRoot->pParent = m_pNil;
		}
		else
		{
			if(pTempX == pTempX->pParent->pLeft)
			{
				pTempX->pParent->pLeft = pTempY;
			}
			else
			{
				pTempX->pParent->pRight = pTempY;
			}
		}
		pTempY->pLeft = pTempX;
		pTempX->pParent = pTempY;
	}

}


template <typename T>
void RedBlackTree<T>::RightRotate(RBTNode<T>* pNode)
{
	if(pNode->pLeft != m_pNil)
	{
		RBTNode<T>* pTempX = pNode;
		RBTNode<T>* pTempY = pNode->pLeft;
		pTempX->pLeft = pTempY->pRight;
		//if(pTempY->pRight != m_pNil)
			pTempY->pRight->pParent = pTempX;
		pTempY->pParent = pTempX->pParent;
		if(pTempX->pParent == m_pNil)
		{
			m_pRoot = pTempY;
			m_pRoot->pParent = m_pNil;
		}
		else
		{
			if(pTempX->pParent->pLeft == pTempX)
			{
				pTempX->pParent->pLeft = pTempY;
			}
			else
			{
				pTempX->pParent->pRight = pTempY;
			}
		}
		pTempY->pRight = pTempX;
		pTempX->pParent = pTempY;
	}
}