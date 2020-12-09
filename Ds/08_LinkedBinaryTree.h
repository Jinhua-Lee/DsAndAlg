#pragma once
#include <stdio.h>
#include <stdlib.h>

// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define BiTreeNodeElementType int

// ���������ṹ����
typedef struct BinaryTreeNode
{
	// ������
	BiTreeNodeElementType data;
	// ָ�����ӵ�ָ��
	BinaryTreeNode* left;
	// ָ���Һ��ӵ�ָ��
	BinaryTreeNode* right;
	// ָ�򸸽���ָ��
	BinaryTreeNode* parent;
}BTNode, *BinaryTree;

// ���Զ������ķ���
void testBinaryTree();

/*=====================================*/
/*һ��ָ�������ָ�룬����ȷ��һ��������*/
/*=====================================*/

// 01_������������ʼ�����õ�һ��ָ�������ָ�룬��ȷ��һ��������
Status initBiTree_T(BinaryTree& biTree);

// 02_��������������
Status destroyBiTree_T(BinaryTree& biTree);

// 03_�����������п�
Status emptyBiTree_T(BinaryTree biTree);

// 04_�������������
int treeDepth_T(BinaryTree biTree);

// �����������ϴ��һ��
int max(int a, int b);

// 05_�����������Ƿ���Ҷ�ӽ��
Status leafBiNode_T(BinaryTree biTree);

// 06_�����������Ƿ�����
Status rootBiNode_T(BinaryTree biTree);

// 07_�����������󸸽��
Status parentBiNode_T(BinaryTree current, BinaryTree& parent);

// ���ʶ��������ķ���
void visit(BinaryTree biTree);

// 08_�����������������_�ݹ�
void preOrderTraverse_Recur(BinaryTree biTree);

// 09_�����������������_�ݹ�
void inOrderTraverse_Recur(BinaryTree biTree);

// 10_�����������������_�ݹ�
void postOrderTraverse_Recur(BinaryTree biTree);

// 11_����������ͨ�����������������
void createByPreOrderTraverse_T(BinaryTree& biTree);

// 12_�����������������_�ǵݹ�
void preOrderTraverse_NonRecur(BinaryTree biTree);

// 13_�����������������_�ǵݹ�
void inOrderTraverse_NonRecur(BinaryTree biTree);

// 14_�����������������_�ǵݹ�
void postOrderTraverse_NonRecur(BinaryTree biTree);

// 15_������������α���
void breadthTraverse(BinaryTree biTree);