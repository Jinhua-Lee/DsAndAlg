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
		y->parent = &nil;
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
		x->parent = &nil;
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
void insertFixUp_BrT(BrTree& root, BrTree cur)
{
	BrTree parent = cur->parent;
	BrTree pp = parent->parent;
	// 退出条件：1. 父亲为黑色；2. 或爷爷不存在
	if (parent->black || pp == &nil)
	{
		return;
	}
	BrTree uncle = parent == pp->left ? pp->right : pp->left;
	// 3.1 叔叔结点存在且为红色
	if (!uncle->black)
	{
		parent->black = true;
		uncle->black = true;
		pp->black = false;
		insertFixUp_BrT(root, pp);
		return;
	}

	// 3.2 叔叔结点为黑色（包括Null），并且父亲是祖父的左孩子
	if (parent == pp->left)
	{
		// 3.2.1 插入结点是父结点的左孩子
		if (cur == parent->left)
		{
			parent->black = true;
			pp->black = false;
			rightRotate_BrT(root, pp);
		}
		// 3.2.2 插入结点是父结点的右孩子
		else
		{
			leftRotate_BrT(root, parent);
			cur->black = true;
			pp->black = false;
			rightRotate_BrT(root, pp);
			insertFixUp_BrT(root, cur);
		}
	}
	// 3.3 叔叔结点为黑色（包括Null），并且父亲是祖父的右孩子
	else
	{
		// 3.3.1 插入结点是父亲的右孩子
		if (cur == parent->right)
		{
			parent->black = true;
			pp->black = false;
			leftRotate_BrT(root, pp);
		}
		// 3.3.2 插入结点是父亲的左孩子
		else
		{
			rightRotate_BrT(root, parent);
			pp->black = false;
			cur->black = true;
			leftRotate_BrT(root, pp);
			insertFixUp_BrT(root, cur);
		}
	}
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
	BrTree parent = toDel->parent;
	
	// 2. 确定待删除结点与父结点的关系：0—自己为根结点；1-为左孩子；2-为右孩子
	int withParent = relateParent_BrT(toDel);

	// 3.1 无左右孩子
	if (toDel->left == &nil && toDel->right == &nil)
	{
		switch (withParent)
		{
			// 删除的是根结点，则删除后变为空树
			case 0:
			{
				root = &nil;
				delete toDel;
				toDel = NULL;
				// 直接返回，不需要自平衡
				return OK;
			}
			// 否则将该结点与父亲关系置空
			case 1:
			{
				parent->left = &nil;
				delete toDel;
				toDel = NULL;
				break;
			}
			case 2:
			{
				parent->right = &nil;
				delete toDel;
				toDel = NULL;
				break;
			}
			default:
				break;
		}
	}
	// 3.2 有两个孩子，中序后继的值替换自己，删除中序后继
	else if (toDel->left != &nil && toDel->right != &nil)
	{
		// 中序后继不可能为空，替换当前结点的值
		BrTree post = inOrderPost_BrT(root, toDel);
		toDel->data = post->data;
		// 处理中序后继


	}
	// 3.3 有单个孩子，孩子替换自己的位置
	else
	{
		// 3.3.1 有左孩子
		if (toDel->left != &nil)
		{
			switch (withParent)
			{
				// 待删除的父结点为空
				case 0:
				{
					toDel->left->parent = parent;
					delete toDel;
					toDel = NULL;
					break;
				}
				case 1:
				{
					parent->left = toDel->left;
					toDel->left->parent = parent;
					delete toDel;
					toDel = NULL;
					break;
				}
				case 2:
				{
					parent->right = toDel->left;
					toDel->left->parent = parent;
					delete toDel;
					toDel = NULL;
					break;
				}
				default:
					break;
			}
		}
		// 3.3.2 有右孩子
		else if (toDel->right != &nil)
		{
			switch (withParent)
			{
				// 待删除的父结点为空
				case 0:
				{
					toDel->right->parent = parent;
					delete toDel;
					toDel = NULL;
					break;
				}
				case 1:
				{
					parent->left = toDel->left;
					toDel->right->parent = parent;
					delete toDel;
					toDel = NULL;
					break;
				}
				case 2:
				{
					parent->right = toDel->left;
					toDel->right->parent = parent;
					delete toDel;
					toDel = NULL;
					break;
				}
				default:
					break;
			}
		}
	}

	// 4. 自平衡

	return OK;
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
