#pragma once
#include<stdio.h>
#include<stdlib.h>

// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define ElementType int

/* ���嵥����ڵ�*/
typedef struct SL_Node
{
	// �洢��Ԫ��
	ElementType elem;
	// ָ����һ���ڵ��ָ��
	SL_Node* next;
}hNode, *pNode;

// ���Ե�����ķ���
void testSingleLinkedList();

// 01_����������ʼ��������_��ͷ�ڵ�
SL_Node* initList_SL(SL_Node& hNode);
// 02_����������ʼ��������_��ͷ�ڵ�
SL_Node* initList_SL2(SL_Node* pNode);
// 03_��������ͷ�巨����������
SL_Node* headInsert_SL(SL_Node* pNode);
// 04_��������β�巨����������
SL_Node* tailInsert_SL(SL_Node* pNode);
// 05_��������������ĳ���
int length_SL(SL_Node* pNode);