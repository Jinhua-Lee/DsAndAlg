#pragma once
#include <stdio.h>
#include <stdlib.h>

// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define ElementType int

/* ˫����ѭ����洢���*/
typedef struct DuL_Node
{
	// ָ��ǰ���ڵ�ָ��
	DuL_Node* prior;
	// �洢Ԫ��
	ElementType data;
	// ָ���̽ڵ�ָ��
	DuL_Node* next;
}DuNode, *DuL;

// ����˫��ѭ������ķ���
void testDoublyLinkedList();

// 01_˫��ѭ����������ʼ��_��ͷ���
Status initList_DuL(DuL& duL);

// 02_˫��ѭ����������ָ������λ��ǰ����Ԫ��
Status insertByIndex_DuL(DuL& duL, int index, ElementType data);

// 03_˫��ѭ���������������
void traverseList_DuL(DuL duL);

// 04_˫��ѭ���������������
void backTraverseList_DuL(DuL duL);

// 05_˫��ѭ������������
void visit(DuNode duNode);

// 06_˫��ѭ�������������������ݵ���β
Status batchInsertToTail_DuL(DuL& duL, ElementType* datas, int length);

// 07_˫��ѭ��������ɾ��ָ��������Ԫ��
ElementType deleteByIndex_DuL(DuL& duL, int index);