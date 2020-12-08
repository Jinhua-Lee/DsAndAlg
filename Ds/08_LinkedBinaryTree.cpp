#include "08_LinkedBinaryTree.h"
#include "04_SequenceStack.h"

/* 测试二叉树的方法*/
void testBinaryTree()
{
	BinaryTree bt;
	initBiTree_L(bt);
	createByPreOrderTraverse_L(bt);

	printf("\n先序遍历_递归：\n");
	preOrderTraverse_Recur(bt);

	printf("\n中序遍历_递归：\n");
	inOrderTraverse_Recur(bt);

	printf("\n后序遍历_递归：\n");
	postOrderTraverse_Recur(bt);

	printf("\n先序遍历_非递归：\n");
	preOrderTraverse_NonRecur(bt);

	printf("\n中序遍历_非递归：\n");
	inOrderTraverse_NonRecur(bt);

	printf("\n后序遍历_非递归：\n");
	postOrderTraverse_Recur(bt);

}

/* 01_二叉树——初始化*/
Status initBiTree_L(BinaryTree& biTree)
{
	biTree = NULL;
	return OK;
}

/* 02_二叉树——销毁*/
Status destroyBiTree_L(BinaryTree& biTree)
{
	// 如果结点不为空
	if (biTree)
	{
		biTree->parent = NULL;
		// 先删除左右子树
		if (destroyBiTree_L(biTree->left) && destroyBiTree_L(biTree->right))
		{
			return OK;
		}
		// 再删除该结点
		delete biTree;
	}
	return OK;
}

/* 03_二叉树——判空*/
Status emptyBiTree_L(BinaryTree biTree)
{
	return biTree == NULL ? OK : ERROR;
}

/* 04_二叉树——深度*/
int treeDepth_L(BinaryTree biTree)
{
	// 该结点为空，则该层深度为0
	if (!biTree)
	{
		return 0;
	}
	// 否则，该层深度有1，要向上累加
	else
	{
		int leftDepth = treeDepth_L(biTree->left);
		int rightDepth = treeDepth_L(biTree->right);
		// 左右子树的深度，加上本层的深度1，即是该结点的深度
		return 1 + max(leftDepth, rightDepth);
	}
}

/*返回两个数较大的一个*/
int max(int a, int b)
{
	return a > b ? a : b;
}

/* 05_二叉树——是否是叶子结点*/
Status leafBiNode_L(BinaryTree biTree)
{
	// 左右孩子都不存在，即为叶子结点
	return (biTree->left == NULL && biTree->right == NULL) ? OK : ERROR;
}

/* 06_二叉树——是否根结点*/
Status rootBiNode_L(BinaryTree biTree)
{
	return biTree->parent == NULL ? OK : ERROR;
}

/* 06_二叉树——求父结点*/
Status parentBiNode_L(BinaryTree current, BinaryTree& parent)
{
	// 如果当前结点为空，或当前结点为根结点
	if (emptyBiTree_L(current) || rootBiNode_L(current))
	{
		parent = NULL;
		return ERROR;
	}
	parent = current->parent;
	return OK;
}

/* 访问二叉树结点的方法*/
void visit(BinaryTree biTree)
{
	if (biTree)
	{
		printf("%-4d", biTree->data);
	}
}

/* 08_二叉树——先序遍历_递归*/
void preOrderTraverse_Recur(BinaryTree biTree)
{
	if (!biTree)
	{
		return;
	}
	visit(biTree);
	preOrderTraverse_Recur(biTree->left);
	preOrderTraverse_Recur(biTree->right);
}

/* 09_二叉树——中序遍历_递归*/
void inOrderTraverse_Recur(BinaryTree biTree)
{
	if (!biTree)
	{
		return;
	}
	inOrderTraverse_Recur(biTree->left);
	visit(biTree);
	inOrderTraverse_Recur(biTree->right);
}

/* 10_二叉树——后序遍历_递归*/
void postOrderTraverse_Recur(BinaryTree biTree)
{
	if (!biTree)
	{
		return;
	}
	postOrderTraverse_Recur(biTree->left);
	postOrderTraverse_Recur(biTree->right);
	visit(biTree);
}

/* 11_二叉树——通过先序遍历方法创建*/
void createByPreOrderTraverse_L(BinaryTree& biTree)
{
	BiTreeNodeElementType elem;
	scanf_s("%d", &elem);
	// 规定将负值作为终止该子树的字符
	if (elem < 0)
	{
		// 此处必须置空，否则将是不可控的内存区域
		biTree = NULL;
		return;
	}
	biTree = (BinaryTree)malloc(sizeof(BinaryTreeNode));
	if (!biTree)
	{
		printf("结点创建失败");
		exit(-1);
	}
	biTree->data = elem;
	createByPreOrderTraverse_L(biTree->left);
	createByPreOrderTraverse_L(biTree->right);
}

/* 12_二叉树——先序遍历_非递归*/
void preOrderTraverse_NonRecur(BinaryTree biTree)
{
	if (!biTree)
	{
		return;
	}
	// 采用栈存放当前结点的引用，用于左子树遍历完成，找到其右子树
	SqStack nodeStack;
	initStack_Sq(nodeStack);
	BinaryTree popped = NULL;

	// 外层：每一次循环完成一次左分支
	while (!stackEmpty_Sq(nodeStack) || biTree)
	{
		
		// 对左分支的迭代，是一个访问和压栈的过程
		while (biTree)
		{
			// 先序遍历的关键，优先访问根结点
			visit(biTree);
			push_Sq(nodeStack, biTree);
			// 对左结点的迭代
			biTree = biTree->left;
		}
		// 一次左分支完成
		if (!stackEmpty_Sq(nodeStack))
		{
			// 左分支结束，则将其父结点出栈
			popped = (BinaryTree)malloc(sizeof(BinaryTreeNode));
			pop_Sq(nodeStack, popped);
			// 迭代到待访问的右孩子，下次循环执行访问
			biTree = popped->right;
		}
	}
	destroyStack_Sq(nodeStack);
}

/* 13_二叉树——中序遍历_非递归*/
void inOrderTraverse_NonRecur(BinaryTree biTree)
{
	if (!biTree)
	{
		return;
	}
	SqStack nodeStack;
	initStack_Sq(nodeStack);
	BinaryTree popped = NULL;

	while (!stackEmpty_Sq(nodeStack) || biTree)
	{
		// 遇到左孩子即压栈
		while (biTree)
		{
			push_Sq(nodeStack, biTree);
			biTree = biTree->left;
		}
		if (!stackEmpty_Sq(nodeStack))
		{
			// 左孩子完毕，则栈顶为最后一个左孩子，进行输出
			popped = (BinaryTree)malloc(sizeof(BinaryTreeNode));
			pop_Sq(nodeStack, popped);
			visit(popped);
			// 继续迭代右子树的左孩子
			biTree = popped->right;
		}
	}
	destroyStack_Sq(nodeStack);
}

/* 14_二叉树——后序遍历_非递归*/
void postOrderTraverse_NonRecur(BinaryTree biTree)
{
	if (!biTree)
	{
		return;
	}
	// 存任意非空结点的栈
	SqStack nodeStack;
	initStack_Sq(nodeStack);
	push_Sq(nodeStack, biTree);
	// 标记前一次访问的结点
	BinaryTree pre = NULL;

	while (!stackEmpty_Sq(nodeStack))
	{
		// 获取栈顶元素，不出栈，分两种情况讨论
		getTop_Sq(nodeStack, biTree);
		/**
		 * 第一大类：
		 * 1. 不存在左右结点；
		 * 2. 前一次访问的结点不为空，且前一次访问的结点【等于当前结点的左孩子】或【右孩子】
		 */
		if ((!biTree->left && !biTree->right)
			|| (pre != NULL
				&& (pre == biTree->left || biTree == biTree->right)
				))
		{
			visit(biTree);
			BinaryTree bt = NULL;
			pop_Sq(nodeStack, bt);
			pre = biTree;
		}
		// 第二大类情况，有孩子未被访问，先右后左的优先级入栈其孩子
		else
		{
			// 优先入栈右结点
			if (biTree->right)
			{
				push_Sq(nodeStack, biTree->right);
			}
			if (biTree->left)
			{
				push_Sq(nodeStack, biTree->left);
			}
		}
	}
}
