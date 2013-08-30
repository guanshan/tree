#ifndef BINARY_TREE_H_H_H___
#define BINARY_TREE_H_H_H___

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct binaryTreeNode
{
	int value;
	binaryTreeNode *pLeft;
	binaryTreeNode *pRight;
};

class binaryTree
{
public:
	binaryTreeNode * initBTree(int a[],int i,int n);
	//以下三个函数为递归版本
	void preOrderTraverse(binaryTreeNode * root);
	void inOrderTraverse(binaryTreeNode * root);
	void postOrderTraverse(binaryTreeNode * root);
	//以下三个版本为非递归版本,第二个参数为重载用，无意义
	void preOrderTraverse(binaryTreeNode * root,bool type);
	void inOrderTraverse(binaryTreeNode * root,bool type);
	void postOrderTraverse(binaryTreeNode * root,bool type);
	//层次遍历
	void levelOrderTraverse(binaryTreeNode * root);
};

#endif
