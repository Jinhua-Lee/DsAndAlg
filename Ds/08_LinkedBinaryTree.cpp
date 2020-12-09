#include "08_LinkedBinaryTree.h"
#include "04_SequenceStack.h"
#include "06_CircularQueue.h"

/* ���Զ������ķ���*/
void testBinaryTree()
{
	BinaryTree bt;
	initBiTree_T(bt);
	createByPreOrderTraverse_T(bt);

	printf("\n�������_�ݹ飺\n");
	preOrderTraverse_Recur(bt);

	printf("\n�������_�ݹ飺\n");
	inOrderTraverse_Recur(bt);

	printf("\n�������_�ݹ飺\n");
	postOrderTraverse_Recur(bt);

	printf("\n�������_�ǵݹ飺\n");
	preOrderTraverse_NonRecur(bt);

	printf("\n�������_�ǵݹ飺\n");
	inOrderTraverse_NonRecur(bt);

	printf("\n�������_�ǵݹ飺\n");
	postOrderTraverse_Recur(bt);

	printf("\n��α�����\n");
	breadthTraverse(bt);

}

/* 01_������������ʼ��*/
Status initBiTree_T(BinaryTree& biTree)
{
	biTree = NULL;
	return OK;
}

/* 02_��������������*/
Status destroyBiTree_T(BinaryTree& biTree)
{
	// �����㲻Ϊ��
	if (biTree)
	{
		biTree->parent = NULL;
		// ��ɾ����������
		if (destroyBiTree_T(biTree->left) && destroyBiTree_T(biTree->right))
		{
			return OK;
		}
		// ��ɾ���ý��
		delete biTree;
	}
	return OK;
}

/* 03_�����������п�*/
Status emptyBiTree_T(BinaryTree biTree)
{
	return biTree == NULL ? OK : ERROR;
}

/* 04_�������������*/
int treeDepth_T(BinaryTree biTree)
{
	// �ý��Ϊ�գ���ò����Ϊ0
	if (!biTree)
	{
		return 0;
	}
	// ���򣬸ò������1��Ҫ�����ۼ�
	else
	{
		int leftDepth = treeDepth_T(biTree->left);
		int rightDepth = treeDepth_T(biTree->right);
		// ������������ȣ����ϱ�������1�����Ǹý������
		return 1 + max(leftDepth, rightDepth);
	}
}

/*�����������ϴ��һ��*/
int max(int a, int b)
{
	return a > b ? a : b;
}

/* 05_�����������Ƿ���Ҷ�ӽ��*/
Status leafBiNode_T(BinaryTree biTree)
{
	// ���Һ��Ӷ������ڣ���ΪҶ�ӽ��
	return (biTree->left == NULL && biTree->right == NULL) ? OK : ERROR;
}

/* 06_�����������Ƿ�����*/
Status rootBiNode_T(BinaryTree biTree)
{
	return biTree->parent == NULL ? OK : ERROR;
}

/* 06_�����������󸸽��*/
Status parentBiNode_T(BinaryTree current, BinaryTree& parent)
{
	// �����ǰ���Ϊ�գ���ǰ���Ϊ�����
	if (emptyBiTree_T(current) || rootBiNode_T(current))
	{
		parent = NULL;
		return ERROR;
	}
	parent = current->parent;
	return OK;
}

/* ���ʶ��������ķ���*/
void visit(BinaryTree biTree)
{
	if (biTree)
	{
		printf("%-4d", biTree->data);
	}
}

/* 08_�����������������_�ݹ�*/
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

/* 09_�����������������_�ݹ�*/
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

/* 10_�����������������_�ݹ�*/
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

/* 11_����������ͨ�����������������*/
void createByPreOrderTraverse_T(BinaryTree& biTree)
{
	BiTreeNodeElementType elem;
	scanf_s("%d", &elem);
	// �涨����ֵ��Ϊ��ֹ���������ַ�
	if (elem < 0)
	{
		// �˴������ÿգ������ǲ��ɿص��ڴ�����
		biTree = NULL;
		return;
	}
	biTree = (BinaryTree)malloc(sizeof(BinaryTreeNode));
	if (!biTree)
	{
		printf("��㴴��ʧ��");
		exit(-1);
	}
	biTree->data = elem;
	createByPreOrderTraverse_T(biTree->left);
	createByPreOrderTraverse_T(biTree->right);
}

/* 12_�����������������_�ǵݹ�*/
void preOrderTraverse_NonRecur(BinaryTree biTree)
{
	if (!biTree)
	{
		return;
	}
	// ����ջ��ŵ�ǰ�������ã�����������������ɣ��ҵ���������
	SqStack nodeStack;
	initStack_Sq(nodeStack);
	BinaryTree popped = NULL;

	// ��㣺ÿһ��ѭ�����һ�����֧
	while (!stackEmpty_Sq(nodeStack) || biTree)
	{
		
		// �����֧�ĵ�������һ�����ʺ�ѹջ�Ĺ���
		while (biTree)
		{
			// ��������Ĺؼ������ȷ��ʸ����
			visit(biTree);
			push_Sq(nodeStack, biTree);
			// ������ĵ���
			biTree = biTree->left;
		}
		// һ�����֧���
		if (!stackEmpty_Sq(nodeStack))
		{
			// ���֧���������丸����ջ
			popped = (BinaryTree)malloc(sizeof(BinaryTreeNode));
			pop_Sq(nodeStack, popped);
			// �����������ʵ��Һ��ӣ��´�ѭ��ִ�з���
			biTree = popped->right;
		}
	}
	destroyStack_Sq(nodeStack);
}

/* 13_�����������������_�ǵݹ�*/
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
		// �������Ӽ�ѹջ
		while (biTree)
		{
			push_Sq(nodeStack, biTree);
			biTree = biTree->left;
		}
		if (!stackEmpty_Sq(nodeStack))
		{
			// ������ϣ���ջ��Ϊ���һ�����ӣ��������
			popped = (BinaryTree)malloc(sizeof(BinaryTreeNode));
			pop_Sq(nodeStack, popped);
			visit(popped);
			// ��������������������
			biTree = popped->right;
		}
	}
	destroyStack_Sq(nodeStack);
}

/* 14_�����������������_�ǵݹ�*/
void postOrderTraverse_NonRecur(BinaryTree biTree)
{
	if (!biTree)
	{
		return;
	}
	// ������ǿս���ջ
	SqStack nodeStack;
	initStack_Sq(nodeStack);
	push_Sq(nodeStack, biTree);
	// ���ǰһ�η��ʵĽ��
	BinaryTree pre = NULL;

	while (!stackEmpty_Sq(nodeStack))
	{
		// ��ȡջ��Ԫ�أ�����ջ���������������
		getTop_Sq(nodeStack, biTree);
		/**
		 * ��һ���ࣺ
		 * 1. ���������ҽ�㣻
		 * 2. ǰһ�η��ʵĽ�㲻Ϊ�գ���ǰһ�η��ʵĽ�㡾���ڵ�ǰ�������ӡ����Һ��ӡ�
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
		// �ڶ�����������к���δ�����ʣ����Һ�������ȼ���ջ�亢��
		else
		{
			// ������ջ�ҽ��
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

/* 15_������������α���*/
void breadthTraverse(BinaryTree biTree)
{
	if (!biTree)
	{
		return;
	}
	// ������������Ķ���
	CircularQueue cq;
	initQueue_Cq(cq);
	enqueue_Cq(cq, biTree);
	// ��������е�Ԫ��
	BinaryTree deQueued = NULL;

	while (!queueEmpty_Cq(cq))
	{
		// �κν�㶼�ڳ�����ʱ����з��ʡ�
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
