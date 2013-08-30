#ifndef BINARY_TREE_H_H_H___
#define BINARY_TREE_H_H_H___

#include <iostream>
#include <string>

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
	//针对完全二叉树实现
	binaryTreeNode * initBTree(int a[],int i,int n);
	void preOrderTraverse(binaryTreeNode * root);
	void inOrderTraverse(binaryTreeNode * root);
	void postOrderTraverse(binaryTreeNode * root);
};

#endif
