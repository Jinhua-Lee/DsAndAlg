#include "09_BlackRedTree.h"

// Null结点定义
BrTreeNode nil = { NULL, &nil, &nil, &nil, true };

// 根结点定义
BrTree root = &nil;

/* 测试红黑树的方法*/
void testBrTree()
{
	// 1. 插入元素测试
	insertElem_BrT(root, 2);
	insertElem_BrT(root, 10);
	insertElem_BrT(root, 5);
	insertElem_BrT(root, 4);
	insertElem_BrT(root, 6);
	insertElem_BrT(root, 8);
	insertElem_BrT(root, 7);
	insertElem_BrT(root, 3);

	// 2. 删除元素调试
	deleteElem_BrT(root, 5);

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

	// 2. x -> y 连接更改，改为y的左孩子
	x->right = y->left;
	if (y->left != &nil)
	{
		y->left->parent = x;
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
		y->parent = x->parent;
	}
	// 为其右孩子
	else
	{
		x->parent->right = y;
		y->parent = x->parent;
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

	// 2. y -> x的连接更改，改为x的右孩子
	y->left = x->right;
	if (x->right != &nil)
	{
		x->right->parent = y;
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
	insertFixUp_BrT(root, toAdd);
	return OK;
}

/* 10_红黑树_插入自平衡处理*/
void insertFixUp_BrT(BrTree& root, BrTree cur)
{
	// 父亲红色时候，才需要进行平衡
	while (!cur->parent->black)
	{
		// 叔叔结点
		BrTree uncle;
		// 父亲是祖父左孩子
		if (cur->parent == cur->parent->parent->left)
		{
			// 叔叔（祖父右孩子）
			uncle = cur->parent->parent->right;
			// 1. 父代均为红色，仅变色
			if (!uncle->black)
			{
				cur->parent->black = true;
				uncle->black = true;
				cur->parent->parent->black = false;
				cur = cur->parent->parent;
				// 为红色需重新进入判断
				continue;
			}
			// 2. 叔叔黑，父亲红
			// 2.1 当前为父亲的右孩子
			else if (cur == cur->parent->right)
			{
				cur = cur->parent;
				leftRotate_BrT(root, cur);
			}
			// 2.2 当前为父亲左孩子
			cur->parent->black = true;
			cur->parent->parent->black = false;
			rightRotate_BrT(root, cur->parent->parent);
		}
		// 父亲是祖父右孩子
		else
		{
			// 叔叔（祖父左孩子）
			uncle = cur->parent->parent->left;
			// 1. 父代均为红色，仅变色
			if (!uncle->black)
			{
				cur->parent->black = true;
				uncle->black = true;
				cur->parent->parent->black = false;
				cur = cur->parent->parent;
				continue;
			}
			// 2. 叔叔黑，父亲红
			// 2.1 当前为父亲的左孩子
			else if (cur == cur->parent->left)
			{
				cur = cur->parent;
				rightRotate_BrT(root, cur);
			}
			// 2.2 当前为父亲右孩子
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
		return ERROR;
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
		if (y->parent == toDel)
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
	delete toDel;
	toDel = NULL;
	if (originColor)
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
	// 迭代到根结点或当前结点是红色结点时候，结束
	while (cur != root && cur->black)
	{
		BrTree brother;
		// 当前为父的左孩子
		if (cur == cur->parent->left)
		{
			brother = cur->parent->right;
			// 兄弟为红色 ==> （父亲P，左侄子SL，右侄子SR一定为黑色）
			if (!brother->black)
			{
				// 互换父亲P，兄弟S的颜色
				brother->black = true;
				cur->parent->black = false;
				// 左旋父亲
				leftRotate_BrT(root, cur->parent);
				// 更新兄弟指针旋转后的指向
				brother = cur->parent->right;
			}
			// 左侄子和右侄子均为黑色
			if (brother->left->black && brother->right->black)
			{
				// 兄弟变红，自平衡当前结点向上迭代
				brother->black = false;
				cur = cur->parent;
			}
			// 左侄子红，右侄子黑
			else if (brother->right->black)
			{
				// 对兄弟变色右旋
				brother->left->black = true;
				brother->black = false;
				rightRotate_BrT(root, brother);
				// 更新兄弟指针旋转后的指向
				brother = cur->parent->right;
			}
			// 右侄子为红色，左侄子任意
			else
			{
				// 对父亲左旋，互换父亲，兄弟的颜色
				brother->black = cur->parent->black;
				cur->parent->black = true;
				brother->right->black = true;
				leftRotate_BrT(root, cur->parent);
				cur = root;
			}
		}
		// 当前为父的右孩子
		else
		{
			brother = cur->parent->left;
			if (!brother->black)
			{
				brother->black = true;
				cur->parent->black = false;
				rightRotate_BrT(root, cur->parent);
				brother = cur->parent->left;
			}
			if (brother->left->black && brother->right->black)
			{
				brother->black = false;
				cur = cur->parent;
			}
			else if (brother->left->black)
			{
				brother->right->black = true;
				brother->black = false;
				leftRotate_BrT(root, brother);
				brother = cur->parent->left;
			}
			else
			{
				brother->black = cur->parent->black;
				cur->parent->black = true;
				brother->left->black = true;
				rightRotate_BrT(root, cur->parent);
				cur = root;
			}
		}
	}
	// 终止情况，将当前结点置黑色即平衡
	cur->black = true;
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
	if (key < brTree->data)
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
