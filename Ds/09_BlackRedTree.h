#pragma once
#include <stdio.h>
#include <stdlib.h>

// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define BrTreeNodeElementType int

// ��������ṹ����
typedef struct BrTreeNode
{
	// ������
	BrTreeNodeElementType data;
	// ���ӵ�ָ��
	BrTreeNode* left;
	// �Һ��ӵ�ָ��
	BrTreeNode* right;
	// ��ָ��
	BrTreeNode* parent;
	// ���״̬��ǣ�Ĭ��Ϊ��ɫ
	bool black = false;
}BrNode, * BrTree;

/*�������NULL�Ľ��*/
extern BrTreeNode nil;

/*�����ָ��*/
extern BrTree root;

/**********/
/*���Է���*/
/*********/

// ���Ժ�����ķ���
void testBrTree();

/**********/
/*����ƽ��Ļ�������*/
/*********/

// 01_�����_��ɫ����->�죬��->�ڣ�
void changeColor_BrT(BrTree& brTree);

// 02_�����_��������ĳ����㼰���Һ��ӵĲ�����
void leftRotate_BrT(BrTree& root, BrTree& x);

// 03_�����_��������ĳ����㼰�����ӵĲ�����
void rightRotate_BrT(BrTree& root, BrTree& y);

/**********/
/*��ȡ����*/
/*********/

// ������ɫ�����ݣ��������
Status buildBrNode_BrT(BrTree& brT, bool black, BrTreeNodeElementType data);

// ���������������������(ע��parentָ��)
void brSearchAddElem(BrTree& brT, BrTree& toAdd);

// 04_�����_����Ԫ�أ�������ɣ��������ִ�б���ƽ��Ļ���������
Status insertElem_BrT(BrTree& root, BrTreeNodeElementType data);

// 10_�����_������ƽ�⴦��
void insertFixUp_BrT(BrTree& root, BrTree cur);

// 05_�����_ɾ��Ԫ�أ�ɾ����ɣ��������ִ�б���ƽ��Ļ���������
Status deleteElem_BrT(BrTree& root, BrTreeNodeElementType key);


/****************************/
/*�������������ڼ�����Ľṹ��*/
/***************************/

// 06_�����_�������
void preOrderTraverse_BrT(BrTree brTree);

// 07_�����_�������
void inOrderTraverse_BrT(BrTree brTree);

// 08_�����_�������
void postOrderTraverse_BrT(BrTree brTree);

// 09_�����_���ʷ���
void visitBrNode_BrT(BrTree brTree);