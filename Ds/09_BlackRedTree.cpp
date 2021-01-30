#include "09_BlackRedTree.h"

// Null结点定义
BrTreeNode nil = { NULL, &nil, &nil, &nil, true };

// 根结点定义
BrTree root = &nil;

/* 测试红黑树的方法*/
void testBrTree()
{
	insertElem_BrT(root, 3);
	insertElem_BrT(root, 8);
	insertElem_BrT(root, 5);
	insertElem_BrT(root, 4);
	insertElem_BrT(root, 6);
	insertElem_BrT(root, 7);

	printf("\n前序：\n");
	preOrderTraverse_BrT(root);
	printf("\n中序：\n");
	inOrderTraverse_BrT(root);
	printf("\n后序：\n");
	postOrderTraverse_BrT(root);

}

/**********/
/*保持平衡的基本操作*/
/*********/

// 01_红黑树_变色（黑->红，红->黑）
void changeColor_BrT(BrTree& brTree)
{
	// 赋值为其自身取非
	if (brTree && brTree->black != NULL)
	{
		brTree->black = !brTree->black;
	}
}

/* 02_红黑树_左旋（对某个结点及其右孩子的操作）*/
void leftRotate_BrT(BrTree& root, BrTree x)
{
	// 1. 保存其右孩子
	BrTree y = x->right;
	BrTree β = y->left;

	// 2. x -> y 连接更改，改为y的左孩子
	x->right = β;
	if (β != &nil)
	{
		β->parent = x;
	}

	// 3. x与其父结点关系
	// 无父结点，x即为root
	if (x->parent == &nil)
	{
		root = y;
		y->parent = &nil;
	}
	// 为其左孩子
	else if (x == x->parent->left)
	{
		x->parent->left = y;
		y->parent = x;
	}
	// 为其右孩子
	else
	{
		x->parent->right = y;
		y->parent = x;
	}
	
	// 4. 调整为 y -> x 的关系，反向
	y->left = x;
	x->parent = y;
}

/* 03_红黑树_右旋（对某个结点及其左孩子的操作）*/
void rightRotate_BrT(BrTree& root, BrTree y)
{
	// 1. 保存其左孩子
	BrTree x = y->left;
	BrTree β = x->right;

	// 2. y -> x的连接更改，改为x的右孩子
	y->left = β;
	if (β != &nil)
	{
		β->parent = y;
	}

	// 3. y与上级指针的关系
	// 无父指针，则y为根结点
	if (y->parent == &nil)
	{
		root = x;
		x->parent = &nil;
	}
	// y为父的左
	else if (y == y->parent->left)
	{
		y->parent->left = x;
		x->parent = y->parent;
	}
	// y为父的右
	else
	{
		y->parent->right = x;
		x->parent = y->parent;
	}
	
	// 4. 调整为 x -> y 的关系，反向
	x->right = y;
	y->parent = x;
}

/**********/
/*存取操作*/
/*********/

/* 根据颜色和数据，构建结点*/
Status buildBrNode_BrT(BrTree& brT, bool black, BrTreeNodeElementType data)
{
	brT = (BrTree)malloc(sizeof(BrTreeNode));
	if (!brT)
	{
		printf("构建结点失败！\n");
		return ERROR;
	}
	// 颜色、数据
	brT->black = black;
	brT->data = data;
	// 处理Null
	brT->left = &nil;
	brT->right = &nil;
	brT->parent = &nil;

	return OK;
}

/* 红黑树基础二叉搜索插入(注意parent指针)*/ 
void brSearchAddElem(BrTree& brT, BrTree& toAdd)
{
	// 关键字大小，小于 ==> 左子树
	if (toAdd->data < brT->data)
	{
		// 为空，连接上，设置父子关系
		if (brT->left == &nil)
		{
			brT->left = toAdd;
			toAdd->parent = brT;
			return;
		}
		// 递归其左子树
		else
		{
			brSearchAddElem(brT->left, toAdd);
		}
	}
	// 大于等于 ==> 右子树
	else
	{
		if (brT->right == &nil)
		{
			brT->right = toAdd;
			toAdd->parent = brT;
			return;
		}
		// 递归其右子树
		else
		{
			brSearchAddElem(brT->right, toAdd);
		}
	}
}

/* 04_红黑树_插入元素（插入完成，根据情况执行保持平衡的基本操作）*/
Status insertElem_BrT(BrTree& root, BrTreeNodeElementType data)
{
	// 1. 根结点为空，直接插入，并返回
	if (root == &nil)
	{
		return buildBrNode_BrT(root, true, data) ? OK : ERROR;
	}
	// 2. 否则构建红色结点，并执行二叉搜索插入
	BrTree toAdd = NULL;
	if (!buildBrNode_BrT(toAdd, false, data))
	{
		return ERROR;
	}
	brSearchAddElem(root, toAdd);
	// 3. 判断红黑特性，决定自平衡操作
	BrTree parent = toAdd->parent;
	// 父亲为红色结点，则需要进行自平衡操作
	insertFixUp_BrT(root, toAdd);
	return OK;
}

// 10_红黑树_插入自平衡处理
void insertFixUp_BrT(BrTree& root, BrTree& cur)
{
	while (!cur->parent->black)
	{
		// 叔叔结点
		BrTree uncle;
		// 插入结点 -> 为父亲的左孩子
		if (cur->parent == cur->parent->parent->left)
		{
			// 叔叔（祖父右孩子）
			uncle = cur->parent->parent->right;
			// 父代红，祖父黑，变色
			if (!uncle->black)
			{
				cur->parent->black = true;
				uncle->black = true;
				cur->parent->parent->black = false;
				cur = cur->parent->parent;
				// 为红色需重新进入判断
				continue;
			}
			else if (cur == cur->parent->right)
			{
				cur = cur->parent;
				leftRotate_BrT(root, cur);
			}
			cur->parent->black = true;
			cur->parent->parent->black = false;
			rightRotate_BrT(root, cur->parent->parent);
		}
		// 插入结点 -> 为父亲的左孩子
		else
		{
			// 叔叔（祖父左孩子）
			uncle = cur->parent->parent->left;
			if (!uncle->black)
			{
				cur->parent->black = true;
				uncle->black = true;
				cur->parent->parent->black = false;
				cur = cur->parent->parent;
				continue;
			}
			else if (cur == cur->parent->left)
			{
				cur = cur->parent;
				rightRotate_BrT(root, cur);
			}
			cur->parent->black = true;
			cur->parent->parent->black = false;
			leftRotate_BrT(root, cur->parent->parent);
		}
	}
	root->black = true;
}

/* 05_红黑树_删除元素（删除完成，根据情况执行保持平衡的基本操作）*/
Status deleteElem_BrT(BrTree& root, BrTreeNodeElementType key)
{
	// 1. 先找到结点，找不到则退出
	BrTree toDel = findKey_BrT(root, key);
	if (!toDel || toDel == &nil)
	{
		return OK;
	}
	// 保存实际删除的结点和颜色
	BrTree y = toDel;
	bool originColor = y->black;
	// 后继结点，自平衡的修复从它向上
	BrTree x;
	if (toDel->left == &nil)
	{
		x = toDel->right;
		transparent(root, toDel, toDel->right);
	}
	else if (toDel->right == &nil)
	{
		x = toDel->left;
		transparent(root, toDel, toDel->left);
	}
	// 两个孩子，需要求后继
	else {
		y = inOrderPost_BrT(root, toDel);
		originColor = y->black;
		x = y->right;
		// 待删除右孩子无左子树
		if (x->parent == toDel)
		{
			x->parent = y;
		}
		// 待删除的后继在右孩子的左子树最左
		else
		{
			transparent(root, y, y->right);
			// 替换结点父子关系设置
			y->right = toDel->right;
			y->right->parent = y;
		}
		// 待删除(替换为y)及其父亲
		transparent(root, toDel, y);
		// 待删除及其左子树
		y->left = toDel->left;
		y->left->parent = y;
		y->black = toDel->black;
	}
	if (y->black)
	{
		deleteFixUp_BrT(root, x);
	}
	return OK;
}

/*移植，将一个结点的与父亲的关系移植给另一个结点*/
void transparent(BrTree& root, BrTree& src, BrTree& target)
{
	// 【源结点】空，则根直接给目标结点
	if (src->parent == &nil)
	{
		root = target;
	}
	// 【源结点】是父亲的左指针，则父左 -> 目标结点
	else if (src == src->parent->left)
	{
		src->parent->left = target;
	}
	// 父右 -> 目标结点
	else
	{
		src->parent->right = target;
	}
	// 目标 -> 父
	target->parent = src->parent;
}

/* 14_红黑树_删除自平衡*/ 
void deleteFixUp_BrT(BrTree& root, BrTree cur)
{

}

/* 10_红黑树_找到等值的结点*/
BrTree findKey_BrT(BrTree brTree, BrTreeNodeElementType key)
{
	// 为空，直接返回自定义空结点
	if (brTree == &nil)
	{
		return &nil;
	}
	// 找到，则返回当前结点
	if (brTree->data == key)
	{
		return brTree;
	}
	// 小于，则递归其左子树
	if (brTree->data < key)
	{
		return findKey_BrT(brTree->left, key);
	}
	// 大于，则递归其右子树
	else
	{
		return findKey_BrT(brTree->right, key);
	}
}

// 13_红黑树_中序前驱
BrTree inOrderPre_BrT(BrTree root, BrTree cur)
{
	// 1. 为空，返回自定义Null结点
	if (!root || !cur || root == &nil || cur == &nil)
	{
		return &nil;
	}
	// 2. 有左子树，中序前驱在其左子树中
	BrTree pre = cur->left;
	if (pre && pre != &nil)
	{
		while (pre->right && pre->right != &nil)
		{
			pre = pre->right;
		}
		return pre;
	}
	// 3. 无左子树，找到以当前结点为右孩子的结点，即是其前驱
	BrTree parent = cur->parent;
	while (parent && parent != &nil && parent->right != cur)
	{
		cur = cur->parent;
	}
	return parent;
}

/* 11_红黑树_中序后继*/
BrTree inOrderPost_BrT(BrTree root, BrTree cur)
{
	// 1. 为空，返回自定义Null结点
	if (!root || !cur || root == &nil || cur == &nil)
	{
		return &nil;
	}
	// 2. 有右子树，中序后继在其右子树中
	BrTree post = cur->right;
	if (post && post != &nil)
	{
		while (post->left && post->left != &nil)
		{
			post = post->left;
		}
		return post;
	}

	// 3. 无右子树，找到以当前结点为左孩子的结点，即是其后继结点
	BrTree parent = cur->parent;
	while (parent && parent != &nil && parent->left != cur)
	{
		cur = cur->parent;
	}
	return parent;
}

/****************************/
/*遍历操作（用于检查树的结构）*/
/***************************/

/* 06_红黑树_先序遍历*/
void preOrderTraverse_BrT(BrTree brTree)
{
	if (!brTree || brTree == &nil)
	{
		return;
	}
	visitBrNode_BrT(brTree);
	preOrderTraverse_BrT(brTree->left);
	preOrderTraverse_BrT(brTree->right);
}

/* 12_红黑树_确定与父结点的关系*/
int relateParent_BrT(BrTree brTree)
{
	BrTree parent = brTree->parent;
	// 2.1 待删除为根结点
	if (parent == &nil)
	{
		return 0;
	}
	// 2.2 待删除的是父亲的左孩子
	else if (parent->left == brTree)
	{
		return 1;
	}
	// 2.3 待删除的是父亲的右孩子
	else
	{
		return 2;
	}
}

/* 07_红黑树_中序遍历*/
void inOrderTraverse_BrT(BrTree brTree)
{
	if (!brTree || brTree == &nil)
	{
		return;
	}
	inOrderTraverse_BrT(brTree->left);
	visitBrNode_BrT(brTree);
	inOrderTraverse_BrT(brTree->right);
}

/* 08_红黑树_后序遍历*/
void postOrderTraverse_BrT(BrTree brTree)
{
	if (!brTree || brTree == &nil)
	{
		return;
	}
	postOrderTraverse_BrT(brTree->left);
	postOrderTraverse_BrT(brTree->right);
	visitBrNode_BrT(brTree);
}

/* 09_红黑树_访问方法*/
void visitBrNode_BrT(BrTree brTree)
{
	// 注意空的判断
	if (brTree != &nil && brTree->data)
	{
		printf("%-2d ", brTree->data);
	}
}
