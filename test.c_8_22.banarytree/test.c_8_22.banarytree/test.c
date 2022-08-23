#include<stdio.h>
#include<stdlib.h>

typedef char datatype;
typedef struct BianryTreeNode
{
	struct BianryTreeNode* left;
	struct BianryTreeNode* right;
	datatype data;
}BTnode;
BTnode* Create(char x)
{
	BTnode* node = (BTnode*)malloc(sizeof(BTnode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	node->left = NULL;
	node->right = NULL;
	node->data = x;
	return node;
}
void PrevOrder(BTnode* root)//先序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BTnode* root)//中序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
void PostOrder(BTnode* root)//后序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}
int Treesize(BTnode* A)//节点个数
{
	return A == NULL ? 0 : Treesize(A->left) + Treesize(A->right) + 1;
}
int TreeLeavessize(BTnode* A)//叶子个数
{
	if (A == NULL)
	{
		return 0;
	}
	if (A->left == NULL && A->right == NULL)
	{
		return 1;
	}
	else
	{
		return TreeLeavessize(A->left) + TreeLeavessize(A->right);
	}
}
int TreeKLeavelSize(BTnode* root, int k)//求k层的节点个数
{
	//求k层就是k-1层相加
	if (root == 0)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLeavelSize(root->left,k-1) + 
		TreeKLeavelSize(root->right,k-1);
}
BTnode* TreeFind(BTnode* root, datatype x)//找一个节点
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
		BTnode*lret=TreeFind(root->left, x);
		if (lret)
			return lret;
		BTnode* rret=TreeFind(root->right, x);
		if (rret)
			return rret;
	return NULL;
}
void DistoryTree(BTnode* root)//二叉树的销毁
{
	if (root == NULL)
	{
		return;
	}
	DistoryTree(root->left);
	DistoryTree(root->right);
	free(root);
}
int main()
{
	BTnode* A = Create('A');
	BTnode* B = Create('B');
	BTnode* C = Create('C');
	BTnode* D = Create('D');
	BTnode* E = Create('E');
	BTnode* F = Create('F');
	A->left = B;
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;
	PrevOrder(A);//先序遍历
	printf("\n");
	int size = Treesize(A);
	printf("%d\n", size);
	size = TreeLeavessize(A);
	printf("%d\n", size);
	DistoryTree(A);//一级指针自己置空
	A = NULL;
	return 0;
}