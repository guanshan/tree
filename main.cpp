#include "binaryTree.h"

using namespace std;

int main()
{
//	int a[]={8,6,10,5,7,9,11};
	//以-1标示空节点
	int a[]={8,8,7,9,2,-1,-1,-1,-1,4,7};
	binaryTree test;
	binaryTreeNode * root;
	root = test.initBTree(a,0,11);
//	test.preOrderTraverse(root);//递归版本
	test.preOrderTraverse(root,true);//非递归版本
	cout << "===========" << endl;
//	test.inOrderTraverse(root);//递归版本
	test.inOrderTraverse(root,true);//非递归版本
	cout << "===========" << endl;
//	test.postOrderTraverse(root);//递归版本
	test.postOrderTraverse(root,true);//非递归版本
	cout << "===========" << endl;
	test.levelOrderTraverse(root);
	return 0;
}
