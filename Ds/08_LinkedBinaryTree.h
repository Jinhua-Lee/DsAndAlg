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
	// ��ָ�빦�ܱ�ǣ�Ϊtrue��ָ��ǰ��
	bool ltag = false;
	// ָ���Һ��ӵ�ָ��
	BinaryTreeNode* right;
	// ��ָ�빦�ܱ�ǣ�Ϊtrue��ָ����
	bool rtag = false;
}BTNode, *BinaryTree;

// ���Զ������ķ���
void testBinaryTree();

// �ݹ����
void traverseRecur(BinaryTree bt);

// �ǵݹ����
void traverseNonRecur(BinaryTree bt);

// ��������������ʽ
void threadTraverse(BinaryTree bt);

// ���Ծ���
void testMirror(BinaryTree bt);

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

// 06_�����������󸸽��
BinaryTree parentBiNode_T(BinaryTree biTree, BinaryTree target);

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

// 16_����������Ҷ�Ӹ���
int leafCount_T(BinaryTree biTree);

// 17_������������k������Ŀ
int getKLevel_T(BinaryTree biTree, int k);

// 18_�����������ṹ�Ƿ���ͬ
bool structureCompare_T(BinaryTree bt1, BinaryTree bt2);

// 19_��������������
void treeMirror_T(BinaryTree biTree);

// 20_�����������ҵ��ؼ������ڽ��
BinaryTree findKey_T(BinaryTree biTree, BiTreeNodeElementType btValue);

// 21_��������������͹�������
BinaryTree findLCA_T(BinaryTree biTree, BinaryTree bt1, BinaryTree bt2);

// 22_����������������
int nodeDistance_T(BinaryTree biTree, BinaryTree bt1, BinaryTree bt2);

// 23_��������������������
int levelDist_T(BinaryTree biTree, BinaryTree bt);

// 24_���������������������
bool allAncestors_T(BinaryTree biTree, BinaryTree bt);

// 25_����������ǰ��������
void preThreading_T(BinaryTree& bt, BinaryTree& pre);

// 26_��������������������
void inThreading_T(BinaryTree& bt, BinaryTree& pre);

// 27_��������������������
void postThreading_T(BinaryTree& bt, BinaryTree& pre);

// 28_����������ǰ����������
void preThreadTraverse_T(BinaryTree biTree);

// 29_����������������������
void inThreadTraverse_T(BinaryTree biTree);

// 30_�����������Ƿ���ȫ������
bool isCompleteBinary_T(BinaryTree biTree);