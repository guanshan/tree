#include "binaryTree.h"

using namespace std;
//初始化二叉树
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

//先序遍历，递归版本
void binaryTree::preOrderTraverse(binaryTreeNode * root)
{
	if (root==NULL)
		return ;
	cout << root->value << endl;
	preOrderTraverse(root->pLeft);
	preOrderTraverse(root->pRight);
}

//先序遍历，非递归版本
void binaryTree::preOrderTraverse(binaryTreeNode * root,bool type)
{
	if (root==NULL)
		return ;
	stack<binaryTreeNode *> iTreeStack;
	iTreeStack.push(root);
	while(!iTreeStack.empty())
	{
		binaryTreeNode * node = iTreeStack.top();
		iTreeStack.pop();
		cout << node->value << endl;
		if (node->pRight!=NULL)
			iTreeStack.push(node->pRight);
		if (node->pLeft!=NULL)
			iTreeStack.push(node->pLeft);
	}
}

//中序遍历，递归版本
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

//中序遍历，非递归版本
void binaryTree::inOrderTraverse(binaryTreeNode * root,bool type)
{
	if (root==NULL)
		return ;
	stack<binaryTreeNode *> iTreeStack;
	iTreeStack.push(root);
	binaryTreeNode * node = root;
	while(!iTreeStack.empty())
	{
		while(node->pLeft!=NULL)
		{
			iTreeStack.push(node->pLeft);
			node = node->pLeft;
		}
		if(!iTreeStack.empty())//若是空怎么办？
		{
			node=iTreeStack.top();
			iTreeStack.pop();
			cout << node->value << endl;
			if(node->pRight!=NULL)
			{
				iTreeStack.push(node->pRight);
				node = node->pRight;
			}
		}
	}
}

//后序遍历，递归版本
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

//后序遍历，非递归版本
void binaryTree::postOrderTraverse(binaryTreeNode * root,bool type)
{

}
