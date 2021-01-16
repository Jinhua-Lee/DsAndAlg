#include "09_BlackRedTree.h"

// Null��㶨��
BrTreeNode nil = { NULL, &nil, &nil, &nil, true };

// ����㶨��
BrTree root = &nil;

/**********/
/*����ƽ��Ļ�������*/
/*********/

/* ���Ժ�����ķ���*/
void testBrTree()
{
	insertElem_BrT(root, 3);
	insertElem_BrT(root, 8);
	insertElem_BrT(root, 5);
	insertElem_BrT(root, 4);
	insertElem_BrT(root, 6);
	insertElem_BrT(root, 7);

	printf("\nǰ��\n");
	preOrderTraverse_BrT(root);
	printf("\n����\n");
	inOrderTraverse_BrT(root);
	printf("\n����\n");
	postOrderTraverse_BrT(root);

}

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
void leftRotate_BrT(BrTree& root, BrTree& x)
{
	// 1. �������Һ���
	BrTree y = x->right;
	BrTree �� = y->left;

	// 2. x -> y ���Ӹ��ģ���Ϊy������
	x->right = ��;
	if (�� != &nil)
	{
		��->parent = x;
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
	}
	// Ϊ���Һ���
	else
	{
		x->parent->right = y;
	}

	// 4. ����Ϊ y -> x �Ĺ�ϵ������
	y->left = x;
	x->parent = y;
}

/* 03_�����_��������ĳ����㼰�����ӵĲ�����*/
void rightRotate_BrT(BrTree& root, BrTree& y)
{
	// 1. ����������
	BrTree x = y->left;
	BrTree �� = x->right;

	// 2. y -> x�����Ӹ��ģ���Ϊx���Һ���
	y->left = ��;
	if (�� != &nil)
	{
		��->parent = y;
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
	}
	// yΪ������
	else
	{
		y->parent->right = x;
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
	BrTree parent = toAdd->parent;
	// ����Ϊ��ɫ��㣬����Ҫ������ƽ�����
	insertFixUp_BrT(root, toAdd);
	return OK;
}

// 10_�����_������ƽ�⴦��
void insertFixUp_BrT(BrTree& root, BrTree cur)
{
	BrTree parent = cur->parent;
	BrTree pp = parent->parent;
	// �˳�������1. ����Ϊ��ɫ��2. ��үү������
	if (parent->black || pp == &nil)
	{
		return;
	}
	BrTree uncle = parent == pp->left ? pp->right : pp->left;
	// 3.1 �����������Ϊ��ɫ
	if (!uncle->black)
	{
		parent->black = true;
		uncle->black = true;
		pp->black = false;
		insertFixUp_BrT(root, pp);
		return;
	}

	// 3.2 ������Ϊ��ɫ������Null�������Ҹ������游������
	if (parent == pp->left)
	{
		// 3.2.1 �������Ǹ���������
		if (cur == parent->left)
		{
			parent->black = true;
			pp->black = false;
			rightRotate_BrT(root, pp);
		}
		// 3.2.2 �������Ǹ������Һ���
		else
		{
			leftRotate_BrT(root, parent);
			cur->black = true;
			pp->black = false;
			rightRotate_BrT(root, pp);
			insertFixUp_BrT(root, cur);
		}
	}
	// 3.3 ������Ϊ��ɫ������Null�������Ҹ������游���Һ���
	else
	{
		// 3.3.1 �������Ǹ��׵��Һ���
		if (cur == parent->right)
		{
			parent->black = true;
			pp->black = false;
			leftRotate_BrT(root, pp);
		}
		// 3.3.2 �������Ǹ��׵�����
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

/* 05_�����_ɾ��Ԫ�أ�ɾ����ɣ��������ִ�б���ƽ��Ļ���������*/
Status deleteElem_BrT(BrTree& root, BrTreeNodeElementType key)
{
	
	return OK;
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
