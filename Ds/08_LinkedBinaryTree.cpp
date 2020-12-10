#include "08_LinkedBinaryTree.h"
#include "04_SequenceStack.h"
#include "06_CircularQueue.h"

/* 测试二叉树的方法*/
void testBinaryTree()
{
	BinaryTree bt;
	initBiTree_T(bt);
	createByPreOrderTraverse_T(bt);
	// 遍历
	traverseRecur(bt);
	traverseNonRecur(bt);
	
	//printf("\n 请输入层数（以根结点为第1层）：\n");
	//int level;
	//scanf_s("%d", &level);

	//printf("\n 第 %d 层结点数：%-2d\n", level, getKLevel_T(bt, level));

	//BinaryTree bt2;
	//initBiTree_T(bt2);
	//createByPreOrderTraverse_T(bt2);
	//traverseRecur(bt2);
	//traverseNonRecur(bt2);
	//printf("\n 比较两个二叉树结构：%d\n", structureCompare_T(bt, bt2));

	// 镜像
	treeMirror_T(bt);
	traverseRecur(bt);
	// 找最低公共祖先
	BinaryTree lca = findLCA_T(bt, findKey_T(bt, 3), findKey_T(bt, 7));
	printf("\n最低公共祖先：%d\n", lca->data);

}

/* 递归遍历*/ 
void traverseRecur(BinaryTree bt)
{
	printf("\n先序遍历_递归：\n");
	preOrderTraverse_Recur(bt);

	printf("\n中序遍历_递归：\n");
	inOrderTraverse_Recur(bt);

	printf("\n后序遍历_递归：\n");
	postOrderTraverse_Recur(bt);
}

/* 非递归遍历*/
void traverseNonRecur(BinaryTree bt)
{
	printf("\n先序遍历_非递归：\n");
	preOrderTraverse_NonRecur(bt);

	printf("\n中序遍历_非递归：\n");
	inOrderTraverse_NonRecur(bt);

	printf("\n后序遍历_非递归：\n");
	postOrderTraverse_Recur(bt);

	printf("\n层次遍历：\n");
	breadthTraverse(bt);
}

/* 01_二叉树——初始化*/
Status initBiTree_T(BinaryTree& biTree)
{
	biTree = NULL;
	return OK;
}

/* 02_二叉树——销毁*/
Status destroyBiTree_T(BinaryTree& biTree)
{
	// 如果结点不为空
	if (biTree)
	{
		biTree->parent = NULL;
		// 先删除左右子树
		if (destroyBiTree_T(biTree->left) && destroyBiTree_T(biTree->right))
		{
			return OK;
		}
		// 再删除该结点
		delete biTree;
	}
	return OK;
}

/* 03_二叉树——判空*/
Status emptyBiTree_T(BinaryTree biTree)
{
	return biTree == NULL ? OK : ERROR;
}

/* 04_二叉树——深度*/
int treeDepth_T(BinaryTree biTree)
{
	// 该结点为空，则该层深度为0
	if (!biTree)
	{
		return 0;
	}
	// 否则，该层深度有1，要向上累加
	else
	{
		int leftDepth = treeDepth_T(biTree->left);
		int rightDepth = treeDepth_T(biTree->right);
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
Status leafBiNode_T(BinaryTree biTree)
{
	// 左右孩子都不存在，即为叶子结点
	return (biTree->left == NULL && biTree->right == NULL) ? OK : ERROR;
}

/* 06_二叉树——是否根结点*/
Status rootBiNode_T(BinaryTree biTree)
{
	return biTree->parent == NULL ? OK : ERROR;
}

/* 06_二叉树——求父结点*/
Status parentBiNode_T(BinaryTree current, BinaryTree& parent)
{
	// 如果当前结点为空，或当前结点为根结点
	if (emptyBiTree_T(current) || rootBiNode_T(current))
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
void createByPreOrderTraverse_T(BinaryTree& biTree)
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
	createByPreOrderTraverse_T(biTree->left);
	createByPreOrderTraverse_T(biTree->right);
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

/* 15_二叉树——层次遍历*/
void breadthTraverse(BinaryTree biTree)
{
	if (!biTree)
	{
		return;
	}
	// 存放子树根结点的队列
	CircularQueue cq;
	initQueue_Cq(cq);
	enqueue_Cq(cq, biTree);
	// 保存出队列的元素
	BinaryTree deQueued = NULL;

	while (!queueEmpty_Cq(cq))
	{
		// 任何结点都在出队列时候进行访问。
		dequeue_Cq(cq, deQueued);
		visit(deQueued);
		if (deQueued->left)
		{
			enqueue_Cq(cq, deQueued->left);
		}
		if (deQueued->right)
		{
			enqueue_Cq(cq, deQueued->right);
		}
	}
}

/* 16_二叉树——叶子个数*/
int leafCount_T(BinaryTree biTree)
{
	// 遇到空结点，则个数不变
	if (!biTree)
	{
		return 0;
	}
	// 没有左右孩子，则它是叶子结点
	else if (!biTree->left && !biTree->right)
	{
		return 1;
	}
	// 否则，求它的子树的叶子结点个数
	else
	{
		return leafCount_T(biTree->left) + leafCount_T(biTree->right);
	}
}

/* 17_二叉树——第k层结点数目*/
int getKLevel_T(BinaryTree biTree, int k)
{
	// 以根结点开始的第 k 层 => 以根结点的子孩子开始的第 k-1 层
	if (!biTree)
	{
		return 0;
	}
	// 递归结束条件：1即为当前层级，以当前结点为开始的第一层，即当前根结点，只有1个
	if (k == 1)
	{
		return 1;
	}
	return getKLevel_T(biTree->left, k - 1) + getKLevel_T(biTree->right, k - 1);
}

/* 18_二叉树——结构是否相同*/
bool structureCompare_T(BinaryTree bt1, BinaryTree bt2)
{
	/**
	 * 总的思路是，遇到不同的即返回false，否则一直比较，比较完成返回true
	 */
	// 到最终两个一样为空
	if (!bt1 && !bt2)
	{
		return true;
	}
	// 当一个为空，另一个不为空的时候
	else if (
		(!bt1 && bt2) || (!bt2 && bt1)
		)
	{
		return false;
	}
	// 都不为空，则比较其孩子
	bool same = structureCompare_T(bt1->left, bt2->left);
	same = same && structureCompare_T(bt1->right, bt2->right);
	return same;
}

/* 19_二叉树——求镜像*/
void treeMirror_T(BinaryTree biTree)
{
	// 左右孩子互换，从上到下
	if (!biTree)
	{
		return;
	}
	// 先交换左右孩子根结点
	BinaryTree temp = biTree->left;
	biTree->left = biTree->right;
	biTree->right = temp;
	// 再对左右孩子分别进行互换
	treeMirror_T(biTree->left);
	treeMirror_T(biTree->right);
}

/* 20_二叉树——找到关键字所在结点*/
BinaryTree findKey_T(BinaryTree biTree, BiTreeNodeElementType btValue)
{

	if (!biTree)
	{
		return NULL;
	}
	// 存放子树根结点的队列
	CircularQueue cq;
	initQueue_Cq(cq);
	enqueue_Cq(cq, biTree);
	// 保存出队列的元素
	BinaryTree deQueued = NULL;

	while (!queueEmpty_Cq(cq))
	{
		// 任何结点都在出队列时候进行访问。
		dequeue_Cq(cq, deQueued);
		if (deQueued->data == btValue)
		{
			return deQueued;
		}
		if (deQueued->left)
		{
			enqueue_Cq(cq, deQueued->left);
		}
		if (deQueued->right)
		{
			enqueue_Cq(cq, deQueued->right);
		}
	}
	return NULL;
}

/* 21_二叉树——找最低公共祖先*/
BinaryTree findLCA_T(BinaryTree biTree, BinaryTree bt1, BinaryTree bt2)
{
	if (!biTree)
	{
		return NULL;
	}
	if (biTree == bt1 || biTree == bt2)
	{
		return biTree;
	}

	BinaryTree left = findLCA_T(biTree->left, bt1, bt2);
	BinaryTree right = findLCA_T(biTree->right, bt1, bt2);
	if (left && right)
	{
		return biTree;
	}
	return left ? left : right;
}
