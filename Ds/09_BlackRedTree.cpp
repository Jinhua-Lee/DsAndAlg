#include "09_BlackRedTree.h"

/**********/
/*保持平衡的基本操作*/
/*********/

/* 测试红黑树的方法*/
void testBrTree()
{

}

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
void leftRotate_BrT(BrTree& root, BrTree& x)
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
	}
	// 为其左孩子
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	// 为其右孩子
	else
	{
		x->parent->right = y;
	}

	// 4. 调整为 y -> x 的关系，反向
	y->left = x;
	x->parent = y;
}

/* 03_红黑树_右旋（对某个结点及其左孩子的操作）*/
void rightRotate_BrT(BrTree& root, BrTree& y)
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
	}
	// y为父的左
	else if (y == y->parent->left)
	{
		y->parent->left = x;
	}
	// y为父的右
	else
	{
		y->parent->right = x;
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
	if (!root)
	{
		printf("构建结点失败！\n");
		return ERROR;
	}
	// 颜色、数据
	root->black = black;
	root->data = data;
	// 处理Null
	root->left = &nil;
	root->right = &nil;
	root->parent = &nil;

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
		}
		// 递归其右子树
		else
		{
			brSearchAddElem(brT->left, toAdd);
		}
	}
}

/* 04_红黑树_插入元素（插入完成，根据情况执行保持平衡的基本操作）*/
Status insertElem_BrT(BrTree& root, BrTreeNodeElementType data)
{
	// 1. 根结点为空，直接插入，并返回
	if (!root)
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
	if (parent->black == false)
	{
		// 3.1 叔叔结点存在且为红色

		// 3.2 叔叔结点不存在且为黑色，并且父亲结点是祖父的左孩子
		// 3.2.1 插入结点是父结点的左孩子
		// 3.2.2 插入结点是父结点的右孩子

		// 3.3 叔叔结点不存在且为黑色结点，并且父亲是祖父的右孩子
		// 3.3.1 插入结点是父亲的右孩子
		// 3.3.2 插入结点是父亲的左孩子

		return OK;
	}

}

/* 05_红黑树_删除元素（删除完成，根据情况执行保持平衡的基本操作）*/
Status deleteElem_BrT(BrTree& root, BrTreeNodeElementType key)
{
	
	return OK;
}

/****************************/
/*遍历操作（用于检查树的结构）*/
/***************************/

/* 06_红黑树_先序遍历*/
void preOrderTraverse_BrT(BrTree brTree)
{
	visitBrNode_BrT(brTree);
	preOrderTraverse_BrT(brTree->left);
	preOrderTraverse_BrT(brTree->right);
}

/* 07_红黑树_中序遍历*/
void inOrderTraverse_BrT(BrTree brTree)
{
	inOrderTraverse_BrT(brTree->left);
	visitBrNode_BrT(brTree);
	inOrderTraverse_BrT(brTree->right);
}

/* 08_红黑树_后序遍历*/
void postOrderTraverse_BrT(BrTree brTree)
{
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
