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
	printf("\n 测试镜像并还原\n");
	treeMirror_T(bt);
	traverseRecur(bt);
	treeMirror_T(bt);
	// 找最低公共祖先
	//BinaryTree lca = findLCA_T(bt, findKey_T(bt, 3), findKey_T(bt, 7));
	//printf("\n 最低公共祖先：%d\n", lca->data);
	int dist = nodeDistance_T(bt, findKey_T(bt, 3), findKey_T(bt, 6));
	printf("\n 两个结点距离：%-2d\n", dist);
	// 访问所有祖先
	allAncestors_T(bt, findKey_T(bt, 6));

	BinaryTree parent = parentBiNode_T(bt, findKey_T(bt, 6));
	if (parent)
	{
		printf("\n 父结点： %-2d\n", parent->data);
	}

	// 线索化及线索化遍历
	printf("\n 中序线索化及遍历：\n");
	// 存放前一个被访问结点
	BinaryTree pre = NULL;
	// 前序线索及遍历
	preThreading_T(bt, pre);
	preThreadTraverse_T(bt);
	// 中序线索及遍历
	inThreading_T(bt, pre);
	inThreadTraverse_T(bt);

}

/* 递归遍历*/ 
void traverseRecur(BinaryTree bt)
{
	printf("\n 先序遍历_递归：\n");
	preOrderTraverse_Recur(bt);

	printf("\n 中序遍历_递归：\n");
	inOrderTraverse_Recur(bt);

	printf("\n 后序遍历_递归：\n");
	postOrderTraverse_Recur(bt);
}

/* 非递归遍历*/
void traverseNonRecur(BinaryTree bt)
{
	printf("\n 先序遍历_非递归：\n");
	preOrderTraverse_NonRecur(bt);

	printf("\n 中序遍历_非递归：\n");
	inOrderTraverse_NonRecur(bt);

	printf("\n 后序遍历_非递归：\n");
	postOrderTraverse_Recur(bt);

	printf("\n 层次遍历：\n");
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

/* 06_二叉树——求父结点*/
BinaryTree parentBiNode_T(BinaryTree biTree, BinaryTree target)
{
	if (!biTree)
	{
		return NULL;
	}
	if (biTree->left == target || biTree->right == target)
	{
		return biTree;
	}
	// 若左子树未找到，则找右子树
	BinaryTree parent = parentBiNode_T(biTree->left, target);
	if (!parent)
	{
		parent = parentBiNode_T(biTree->right, target);
	}
	// 将结果回溯上去
	return parent;
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
	biTree->ltag = false;
	biTree->rtag = false;
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
	// 首先对当前根结点进行判断
	// 如果当前根结点为空，或是等于两个待判断结点中的任意一个，则当前根结点即是最低公共祖先
	if (!biTree)
	{
		// 这个空结果，影响下面递归的判断
		return NULL;
	}
	if (biTree == bt1 || biTree == bt2)
	{
		return biTree;
	}
	// 否则分别在根结点的左右子树进行查找，两边都有一个结果，可能为空
	BinaryTree left = findLCA_T(biTree->left, bt1, bt2);
	BinaryTree right = findLCA_T(biTree->right, bt1, bt2);
	// 分别在当前根结点结点两边
	if (left && right)
	{
		return biTree;
	}
	// 在其中一边，取非空的一边
	return left ? left : right;
}

/* 22_二叉树——结点距离*/
int nodeDistance_T(BinaryTree biTree, BinaryTree bt1, BinaryTree bt2)
{
	// 先找到最低公共父结点
	BinaryTree lca =  findLCA_T(biTree, bt1, bt2);

	// 再求出LCA结点到两个结点距离，求和
	int left = levelDist_T(lca, bt1);
	int right = levelDist_T(lca, bt2);

	return left + right;
}

/* 23_二叉树——结点相隔层数*/
int levelDist_T(BinaryTree biTree, BinaryTree bt)
{
	// 用 -1 标识没找到
	if (!biTree)
	{
		return -1;
	}
	// 找到了，当前层，层数不变
	if (biTree == bt)
	{
		return 0;
	}

	// LCA结点和目标结点是直系关系。从LCA结点往下找
	int levelDist = levelDist_T(biTree->left, bt);
	// 若左子树没有找到，则找右子树
	if (levelDist == -1)
	{
		levelDist = levelDist_T(biTree->right, bt);
	}
	// 找到了，则回溯
	if (levelDist != -1)
	{
		return levelDist + 1;
	}
	// 左右子树都没找到
	return -1;
}

/* 24_二叉树——结点所有祖先*/
bool allAncestors_T(BinaryTree biTree, BinaryTree bt)
{
	// 利用求两个直系结点距离的思路
	// 如果到最叶子结点都没有找到，则返回false，找到则返回true
	if (!biTree)
	{
		return false;
	}
	if (biTree == bt)
	{
		return true;
	}
	// 从左右子树找
	if (allAncestors_T(biTree->left, bt) || allAncestors_T(biTree->right, bt))
	{
		// 找到时候访问，并进行回溯
		visit(biTree);
		return true;
	}
	// 左右子树都每找到
	return false;
}

/* 25_二叉树——前序线索化*/
void preThreading_T(BinaryTree& bt, BinaryTree& pre)
{
	if (!bt)
	{
		return;
	}
	// 进行前序线索化
	if (!bt->left || bt->ltag)
	{
		bt->ltag = true;
		bt->left = pre;
	}
	if (pre && (!pre->right || pre->rtag))
	{
		pre->rtag = true;
		pre->right = bt;
	}
	pre = bt;

	preThreading_T(bt->left, pre);
	preThreading_T(bt->right, pre);
}

/* 26_二叉树——中序线索化*/
void inThreading_T(BinaryTree& bt, BinaryTree& pre)
{
	if (!bt)
	{
		return;
	}
	inThreading_T(bt->left, pre);

	// 进行中序的线索化操作
	// 遇到左孩子为空，即赋值为前置
	if (!bt->left || bt->ltag)
	{
		bt->ltag = true;
		bt->left = pre;
	}
	// 若前置结点非空，且没有右孩子
	if (pre && (!pre->right || pre->rtag))
	{
		pre->rtag = true;
		pre->right = bt;
	}
	// 当前结点 => 下一次迭代的前置结点
	pre = bt;

	inThreading_T(bt->right, pre);
}

/* 27_二叉树——后序线索化*/
void postThreading_T(BinaryTree& bt, BinaryTree& pre)
{
	if (!bt)
	{
		return;
	}
	postThreading_T(bt->left, pre);
	postThreading_T(bt->right, pre);

	// 后续线索化的操作
	if (!bt->left)
	{
		bt->ltag = true;
		bt->left = pre;
	}
	if (!pre->right)
	{
		pre->rtag = true;
		pre->right = bt;
	}
	pre = bt;
}

/* 28_二叉树——前序线索遍历*/
void preThreadTraverse_T(BinaryTree biTree)
{
	if (!biTree)
	{
		return;
	}
	// 迭代的变量
	BinaryTree cur = biTree;

	// 结点为空则代表结束
	while (cur)
	{
		// 优先访问当前结点
		while (cur->left && !cur->ltag)
		{
			visit(cur);
			cur = cur->left;
		}
		// 作为线索的后继结点
		while (cur->rtag)
		{
			visit(cur->right);
			cur = cur->right;
		}
		// 作为子树的后继结点，迭代到其子树
		cur = cur->right;
	}
}

/* 29_二叉树——中序线索遍历*/
void inThreadTraverse_T(BinaryTree biTree)
{
	if (!biTree)
	{
		return;
	}
	// 迭代的变量，保存当前及其上一次的结点
	BinaryTree cur = biTree;
	
	// 结点为空则迭代结束（线索作用）
	while (cur)
	{
		// 找到从根节点开始的左子树的叶子结点【中序第一个结点】
		while (cur->left && !cur->ltag)
		{
			cur = cur->left;
		}
		visit(cur);
		// 若结点没有右子树，只有后继，则直接输出它
		while (cur->rtag)
		{
			visit(cur->right);
			cur = cur->right;
		}
		// 有右子树，则按照中序遍历规则，必须先访问完成【右子树根结点的左子树 cur->right-> left】才能访问【右子树的根结点 cur->right】
		// 迭代其右子树，重新进入上面的逻辑
		cur = cur->right;
	}
}

/* 30_二叉树——后序线索遍历*/
void postThreadTraverse_T(BinaryTree biTree)
{

}


