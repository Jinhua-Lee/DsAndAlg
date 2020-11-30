#pragma once
#include <stdio.h>
#include <stdlib.h>

// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define ElementType int

// ���������ṹ����
typedef struct BinaryTreeNode
{
	// ������
	ElementType data;
	// ָ�����ӵ�ָ��
	BinaryTreeNode* left;
	// ָ���Һ��ӵ�ָ��
	BinaryTreeNode* right;
	// ָ�򸸽ڵ��ָ��
	BinaryTreeNode* parent;
}BTNode, *BinaryTree;

// ���Զ������ķ���
void testBinaryTree();

/*=====================================*/
/*һ��ָ����ڵ��ָ�룬����ȷ��һ��������*/
/*=====================================*/

// 01_������������ʼ�����õ�һ��ָ����ڵ��ָ�룬��ȷ��һ��������
Status initBiTree_L(BinaryTree& biTree);

// 02_��������������
Status destroyBiTree_L(BinaryTree& biTree);

// 03_�����������п�
Status emptyBiTree_L(BinaryTree biTree);

// 04_�������������
int treeDepth_L(BinaryTree biTree);

// �����������ϴ��һ��
int max(int a, int b);

// 05_�����������Ƿ���Ҷ�ӽ��
Status leafBiNode_L(BinaryTree biTree);

// 06_�����������Ƿ���ڵ�
Status rootBiNode_L(BinaryTree biTree);

// 07_�����������󸸽ڵ�
Status parentBiNode_L(BinaryTree current, BinaryTree& parent);

// ���ʶ��������ķ���
void visit(BinaryTree biTree);

// 08_�����������������
void preOrderTraverse(BinaryTree biTree);

// 09_�����������������
void inOrderTraverse(BinaryTree biTree);

// 10_�����������������
void postOrderTraverse(BinaryTree biTree);