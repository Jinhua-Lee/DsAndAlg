#include "09_BlackRedTree.h"

/**********/
/*����ƽ��Ļ�������*/
/*********/

/* ���Ժ�����ķ���*/
void testBrTree()
{

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
	if (!root)
	{
		printf("�������ʧ�ܣ�\n");
		return ERROR;
	}
	// ��ɫ������
	root->black = black;
	root->data = data;
	// ����Null
	root->left = &nil;
	root->right = &nil;
	root->parent = &nil;

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
		}
		// �ݹ���������
		else
		{
			brSearchAddElem(brT->left, toAdd);
		}
	}
}

/* 04_�����_����Ԫ�أ�������ɣ��������ִ�б���ƽ��Ļ���������*/
Status insertElem_BrT(BrTree& root, BrTreeNodeElementType data)
{
	// 1. �����Ϊ�գ�ֱ�Ӳ��룬������
	if (!root)
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
	if (parent->black == false)
	{
		// 3.1 �����������Ϊ��ɫ

		// 3.2 �����㲻������Ϊ��ɫ�����Ҹ��׽�����游������
		// 3.2.1 �������Ǹ���������
		// 3.2.2 �������Ǹ������Һ���

		// 3.3 �����㲻������Ϊ��ɫ��㣬���Ҹ������游���Һ���
		// 3.3.1 �������Ǹ��׵��Һ���
		// 3.3.2 �������Ǹ��׵�����

		return OK;
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
	visitBrNode_BrT(brTree);
	preOrderTraverse_BrT(brTree->left);
	preOrderTraverse_BrT(brTree->right);
}

/* 07_�����_�������*/
void inOrderTraverse_BrT(BrTree brTree)
{
	inOrderTraverse_BrT(brTree->left);
	visitBrNode_BrT(brTree);
	inOrderTraverse_BrT(brTree->right);
}

/* 08_�����_�������*/
void postOrderTraverse_BrT(BrTree brTree)
{
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
