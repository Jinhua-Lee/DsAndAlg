#include "09_BlackRedTree.h"

// Null��㶨��
BrTreeNode nil = { NULL, &nil, &nil, &nil, true };

// ����㶨��
BrTree root = &nil;

/* ���Ժ�����ķ���*/
void testBrTree()
{
	// 1. ����Ԫ�ز���
	insertElem_BrT(root, 2);
	insertElem_BrT(root, 10);
	insertElem_BrT(root, 5);
	insertElem_BrT(root, 4);
	insertElem_BrT(root, 6);
	insertElem_BrT(root, 8);
	insertElem_BrT(root, 7);
	insertElem_BrT(root, 3);

	// 2. ɾ��Ԫ�ص���
	deleteElem_BrT(root, 5);

	printf("\nǰ��\n");
	preOrderTraverse_BrT(root);
	printf("\n����\n");
	inOrderTraverse_BrT(root);
	printf("\n����\n");
	postOrderTraverse_BrT(root);

}

/**********/
/*����ƽ��Ļ�������*/
/*********/

// 01_�����_��ɫ����->�죬��->�ڣ�
void changeColor_BrT(BrTree& brTree)
{
	// ��ֵΪ������ȡ��
	if (brTree && brTree->black != NULL)
	{
		brTree->black = !brTree->black;
	}
}

/* 02_�����_��������ĳ����㼰���Һ��ӵĲ�����*/
void leftRotate_BrT(BrTree& root, BrTree x)
{
	// 1. �������Һ���
	BrTree y = x->right;

	// 2. x -> y ���Ӹ��ģ���Ϊy������
	x->right = y->left;
	if (y->left != &nil)
	{
		y->left->parent = x;
	}

	// 3. x���丸����ϵ
	// �޸���㣬x��Ϊroot
	if (x->parent == &nil)
	{
		root = y;
		y->parent = &nil;
	}
	// Ϊ������
	else if (x == x->parent->left)
	{
		x->parent->left = y;
		y->parent = x->parent;
	}
	// Ϊ���Һ���
	else
	{
		x->parent->right = y;
		y->parent = x->parent;
	}
	
	// 4. ����Ϊ y -> x �Ĺ�ϵ������
	y->left = x;
	x->parent = y;
}

/* 03_�����_��������ĳ����㼰�����ӵĲ�����*/
void rightRotate_BrT(BrTree& root, BrTree y)
{
	// 1. ����������
	BrTree x = y->left;

	// 2. y -> x�����Ӹ��ģ���Ϊx���Һ���
	y->left = x->right;
	if (x->right != &nil)
	{
		x->right->parent = y;
	}

	// 3. y���ϼ�ָ��Ĺ�ϵ
	// �޸�ָ�룬��yΪ�����
	if (y->parent == &nil)
	{
		root = x;
		x->parent = &nil;
	}
	// yΪ������
	else if (y == y->parent->left)
	{
		y->parent->left = x;
		x->parent = y->parent;
	}
	// yΪ������
	else
	{
		y->parent->right = x;
		x->parent = y->parent;
	}
	
	// 4. ����Ϊ x -> y �Ĺ�ϵ������
	x->right = y;
	y->parent = x;
}

/**********/
/*��ȡ����*/
/*********/

/* ������ɫ�����ݣ��������*/
Status buildBrNode_BrT(BrTree& brT, bool black, BrTreeNodeElementType data)
{
	brT = (BrTree)malloc(sizeof(BrTreeNode));
	if (!brT)
	{
		printf("�������ʧ�ܣ�\n");
		return ERROR;
	}
	// ��ɫ������
	brT->black = black;
	brT->data = data;
	// ����Null
	brT->left = &nil;
	brT->right = &nil;
	brT->parent = &nil;

	return OK;
}

/* ���������������������(ע��parentָ��)*/ 
void brSearchAddElem(BrTree& brT, BrTree& toAdd)
{
	// �ؼ��ִ�С��С�� ==> ������
	if (toAdd->data < brT->data)
	{
		// Ϊ�գ������ϣ����ø��ӹ�ϵ
		if (brT->left == &nil)
		{
			brT->left = toAdd;
			toAdd->parent = brT;
			return;
		}
		// �ݹ���������
		else
		{
			brSearchAddElem(brT->left, toAdd);
		}
	}
	// ���ڵ��� ==> ������
	else
	{
		if (brT->right == &nil)
		{
			brT->right = toAdd;
			toAdd->parent = brT;
			return;
		}
		// �ݹ���������
		else
		{
			brSearchAddElem(brT->right, toAdd);
		}
	}
}

/* 04_�����_����Ԫ�أ�������ɣ��������ִ�б���ƽ��Ļ���������*/
Status insertElem_BrT(BrTree& root, BrTreeNodeElementType data)
{
	// 1. �����Ϊ�գ�ֱ�Ӳ��룬������
	if (root == &nil)
	{
		return buildBrNode_BrT(root, true, data) ? OK : ERROR;
	}
	// 2. ���򹹽���ɫ��㣬��ִ�ж�����������
	BrTree toAdd = NULL;
	if (!buildBrNode_BrT(toAdd, false, data))
	{
		return ERROR;
	}
	brSearchAddElem(root, toAdd);
	// 3. �жϺ�����ԣ�������ƽ�����
	insertFixUp_BrT(root, toAdd);
	return OK;
}

/* 10_�����_������ƽ�⴦��*/
void insertFixUp_BrT(BrTree& root, BrTree cur)
{
	// ���׺�ɫʱ�򣬲���Ҫ����ƽ��
	while (!cur->parent->black)
	{
		// ������
		BrTree uncle;
		// �������游����
		if (cur->parent == cur->parent->parent->left)
		{
			// ���壨�游�Һ��ӣ�
			uncle = cur->parent->parent->right;
			// 1. ������Ϊ��ɫ������ɫ
			if (!uncle->black)
			{
				cur->parent->black = true;
				uncle->black = true;
				cur->parent->parent->black = false;
				cur = cur->parent->parent;
				// Ϊ��ɫ�����½����ж�
				continue;
			}
			// 2. ����ڣ����׺�
			// 2.1 ��ǰΪ���׵��Һ���
			else if (cur == cur->parent->right)
			{
				cur = cur->parent;
				leftRotate_BrT(root, cur);
			}
			// 2.2 ��ǰΪ��������
			cur->parent->black = true;
			cur->parent->parent->black = false;
			rightRotate_BrT(root, cur->parent->parent);
		}
		// �������游�Һ���
		else
		{
			// ���壨�游���ӣ�
			uncle = cur->parent->parent->left;
			// 1. ������Ϊ��ɫ������ɫ
			if (!uncle->black)
			{
				cur->parent->black = true;
				uncle->black = true;
				cur->parent->parent->black = false;
				cur = cur->parent->parent;
				continue;
			}
			// 2. ����ڣ����׺�
			// 2.1 ��ǰΪ���׵�����
			else if (cur == cur->parent->left)
			{
				cur = cur->parent;
				rightRotate_BrT(root, cur);
			}
			// 2.2 ��ǰΪ�����Һ���
			cur->parent->black = true;
			cur->parent->parent->black = false;
			leftRotate_BrT(root, cur->parent->parent);
		}
	}
	root->black = true;
}

/* 05_�����_ɾ��Ԫ�أ�ɾ����ɣ��������ִ�б���ƽ��Ļ���������*/
Status deleteElem_BrT(BrTree& root, BrTreeNodeElementType key)
{
	// 1. ���ҵ���㣬�Ҳ������˳�
	BrTree toDel = findKey_BrT(root, key);
	if (!toDel || toDel == &nil)
	{
		return ERROR;
	}
	// ����ʵ��ɾ���Ľ�����ɫ
	BrTree y = toDel;
	bool originColor = y->black;
	// ��̽�㣬��ƽ����޸���������
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
	// �������ӣ���Ҫ����
	else {
		y = inOrderPost_BrT(root, toDel);
		originColor = y->black;
		x = y->right;
		// ��ɾ���Һ�����������
		if (y->parent == toDel)
		{
			x->parent = y;
		}
		// ��ɾ���ĺ�����Һ��ӵ�����������
		else
		{
			transparent(root, y, y->right);
			// �滻��㸸�ӹ�ϵ����
			y->right = toDel->right;
			y->right->parent = y;
		}
		// ��ɾ��(�滻Ϊy)���丸��
		transparent(root, toDel, y);
		// ��ɾ������������
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

/*��ֲ����һ�������븸�׵Ĺ�ϵ��ֲ����һ�����*/
void transparent(BrTree& root, BrTree& src, BrTree& target)
{
	// ��Դ��㡿�գ����ֱ�Ӹ�Ŀ����
	if (src->parent == &nil)
	{
		root = target;
	}
	// ��Դ��㡿�Ǹ��׵���ָ�룬���� -> Ŀ����
	else if (src == src->parent->left)
	{
		src->parent->left = target;
	}
	// ���� -> Ŀ����
	else
	{
		src->parent->right = target;
	}
	// Ŀ�� -> ��
	target->parent = src->parent;
}

/* 14_�����_ɾ����ƽ��*/
void deleteFixUp_BrT(BrTree& root, BrTree cur)
{
	// ������������ǰ����Ǻ�ɫ���ʱ�򣬽���
	while (cur != root && cur->black)
	{
		BrTree brother;
		// ��ǰΪ��������
		if (cur == cur->parent->left)
		{
			brother = cur->parent->right;
			if (!brother->black)
			{
				brother->black = true;
				cur->parent->black = false;
				leftRotate_BrT(root, cur->parent);
				brother = cur->parent->right;
			}
			if (brother->left->black && brother->right->black)
			{
				brother->black = false;
				cur = cur->parent;
			}
			else if (brother->right->black)
			{
				brother->left->black = true;
				brother->black = false;
				rightRotate_BrT(root, brother);
				brother = cur->parent->right;
			}
			else
			{
				brother->black = cur->parent->black;
				cur->parent->black = true;
				brother->right->black = true;
				leftRotate_BrT(root, cur->parent);
				cur = root;
			}
		}
		// ��ǰΪ�����Һ���
		else
		{
			brother = cur->parent->left;
			// �ֵܽ��Ϊ��ɫ ==> ��1.����Ϊ��ɫ����
			if (!brother->black)
			{
				brother->black = true;
				cur->parent->black = false;
				rightRotate_BrT(root, cur->parent);
				brother = cur->parent->left;
			}
			// �ֵܵ����Ӻ��Һ���ͬ�ڣ����ֵ�����Ϊ��ɫ
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
	// ��ֹ���������ǰ����ú�ɫ��ƽ��
	cur->black = true;
}

/* 10_�����_�ҵ���ֵ�Ľ��*/
BrTree findKey_BrT(BrTree brTree, BrTreeNodeElementType key)
{
	// Ϊ�գ�ֱ�ӷ����Զ���ս��
	if (brTree == &nil)
	{
		return &nil;
	}
	// �ҵ����򷵻ص�ǰ���
	if (brTree->data == key)
	{
		return brTree;
	}
	// С�ڣ���ݹ���������
	if (key < brTree->data)
	{
		return findKey_BrT(brTree->left, key);
	}
	// ���ڣ���ݹ���������
	else
	{
		return findKey_BrT(brTree->right, key);
	}
}

// 13_�����_����ǰ��
BrTree inOrderPre_BrT(BrTree root, BrTree cur)
{
	// 1. Ϊ�գ������Զ���Null���
	if (!root || !cur || root == &nil || cur == &nil)
	{
		return &nil;
	}
	// 2. ��������������ǰ��������������
	BrTree pre = cur->left;
	if (pre && pre != &nil)
	{
		while (pre->right && pre->right != &nil)
		{
			pre = pre->right;
		}
		return pre;
	}
	// 3. �����������ҵ��Ե�ǰ���Ϊ�Һ��ӵĽ�㣬������ǰ��
	BrTree parent = cur->parent;
	while (parent && parent != &nil && parent->right != cur)
	{
		cur = cur->parent;
	}
	return parent;
}

/* 11_�����_������*/
BrTree inOrderPost_BrT(BrTree root, BrTree cur)
{
	// 1. Ϊ�գ������Զ���Null���
	if (!root || !cur || root == &nil || cur == &nil)
	{
		return &nil;
	}
	// 2. ����������������������������
	BrTree post = cur->right;
	if (post && post != &nil)
	{
		while (post->left && post->left != &nil)
		{
			post = post->left;
		}
		return post;
	}

	// 3. �����������ҵ��Ե�ǰ���Ϊ���ӵĽ�㣬�������̽��
	BrTree parent = cur->parent;
	while (parent && parent != &nil && parent->left != cur)
	{
		cur = cur->parent;
	}
	return parent;
}

/****************************/
/*�������������ڼ�����Ľṹ��*/
/***************************/

/* 06_�����_�������*/
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

/* 12_�����_ȷ���븸���Ĺ�ϵ*/
int relateParent_BrT(BrTree brTree)
{
	BrTree parent = brTree->parent;
	// 2.1 ��ɾ��Ϊ�����
	if (parent == &nil)
	{
		return 0;
	}
	// 2.2 ��ɾ�����Ǹ��׵�����
	else if (parent->left == brTree)
	{
		return 1;
	}
	// 2.3 ��ɾ�����Ǹ��׵��Һ���
	else
	{
		return 2;
	}
}

/* 07_�����_�������*/
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

/* 08_�����_�������*/
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

/* 09_�����_���ʷ���*/
void visitBrNode_BrT(BrTree brTree)
{
	// ע��յ��ж�
	if (brTree != &nil && brTree->data)
	{
		printf("%-2d ", brTree->data);
	}
}
