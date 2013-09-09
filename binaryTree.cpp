#include "binaryTree.h"

using namespace std;
//初始化二叉树
binaryTreeNode * binaryTree::initBTree(int a[],int i,int n)
{
	//以-1标示空节点
	if (i>=n || a[i]==-1)
		return NULL;
	binaryTreeNode * root = new binaryTreeNode();
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
	stack<binaryTreeNode *> treeStack;
	treeStack.push(root);
	while(!treeStack.empty())
	{
		binaryTreeNode * node = treeStack.top();
		treeStack.pop();
		cout << node->value << endl;
		if (node->pRight!=NULL)
			treeStack.push(node->pRight);
		if (node->pLeft!=NULL)
			treeStack.push(node->pLeft);
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

//中序遍历，非递归版本,这个有错误，回头再改！
void binaryTree::inOrderTraverse(binaryTreeNode * root,bool type)
{
	if (root==NULL)
		return ;
	stack<binaryTreeNode *> treeStack;
	treeStack.push(root);
	binaryTreeNode * node = root;
	while(!treeStack.empty())
	{
		while(node->pLeft!=NULL)
		{
			treeStack.push(node->pLeft);
			node = node->pLeft;
		}
		node=treeStack.top();
		treeStack.pop();
		cout << node->value << endl;
		if(node->pRight!=NULL)
		{
			treeStack.push(node->pRight);
			node = node->pRight;
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
	if (root==NULL)
		return;
	stack<binaryTreeNode *> treeStack;
	stack<binaryTreeNode *> output;
	treeStack.push(root);	
	binaryTreeNode *node = NULL;
	while(!treeStack.empty())
	{
		node=treeStack.top();
		treeStack.pop();
		output.push(node);
		if(node->pLeft)
			treeStack.push(node->pLeft);
		if(node->pRight)
			treeStack.push(node->pRight);
	}
	while(!output.empty())
	{
		node = output.top();
		output.pop();
		cout << node->value  << endl;
	}
}

//层次遍历
void binaryTree::levelOrderTraverse(binaryTreeNode *root)
{
	if(root==NULL)
		return;
	queue<binaryTreeNode *> treeQueue;
	treeQueue.push(root);
	binaryTreeNode * node;
	while(!treeQueue.empty())
	{
		node = treeQueue.front();
		treeQueue.pop();
		cout << node->value << endl;
		if (node->pLeft)
			treeQueue.push(node->pLeft);
		if (node->pRight)
			treeQueue.push(node->pRight);
	}
}
