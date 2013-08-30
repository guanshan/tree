#include "binaryTree.h"

using namespace std;

binaryTreeNode * binaryTree::initBTree(int a[],int i,int n)
{
	if (i>=n)
		return NULL;
	binaryTreeNode * root = new binaryTreeNode();
	//以-1标示空节点
	if(a[i]==-1)
	{
		return NULL;
	}
	root->value = a[i];
	root->pLeft = initBTree(a,2*i+1,n);
	root->pRight = initBTree(a,2*i+2,n);
	return root;
}

void binaryTree::preOrderTraverse(binaryTreeNode * root)
{
	if (root==NULL)
		return ;
	cout << root->value << endl;
	preOrderTraverse(root->pLeft);
	preOrderTraverse(root->pRight);
}

void binaryTree::inOrderTraverse(binaryTreeNode *root)
{
	if (root==NULL)
		return ;
	if(root->pLeft!=NULL)
	{
		inOrderTraverse(root->pLeft);
	}
	cout << root->value << endl;
	if(root->pRight!=NULL)
	{
		inOrderTraverse(root->pRight);
	}
}

void binaryTree::postOrderTraverse(binaryTreeNode *root)
{
	if (root==NULL)
		return ;
	if(root->pLeft!=NULL)
	{
		postOrderTraverse(root->pLeft);
	}
	if(root->pRight!=NULL)
	{
		postOrderTraverse(root->pRight);
	}
	cout << root->value << endl;
}
