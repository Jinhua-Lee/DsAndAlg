#pragma once
#include <stdio.h>
#include <stdlib.h>

// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define DuLinkedListElementType int

/* ˫����ѭ����洢���*/
typedef struct DuL_Node
{
	// ָ��ǰ�����ָ��
	DuL_Node* prior;
	// �洢Ԫ��
	DuLinkedListElementType data;
	// ָ���̽��ָ��
	DuL_Node* next;
}DuNode, *DuL;

// ����˫��ѭ������ķ���
void testDoublyLinkedList();

// 01_˫��ѭ����������ʼ��_��ͷ���
Status initList_DuL(DuL& duL);

// 02_˫��ѭ����������ָ������λ��ǰ����Ԫ��
Status insertByIndex_DuL(DuL& duL, int index, DuLinkedListElementType data);

// 03_˫��ѭ���������������
void traverseList_DuL(DuL duL);

// 04_˫��ѭ���������������
void backTraverseList_DuL(DuL duL);

// 05_˫��ѭ������������
void visit(DuNode duNode);

// 06_˫��ѭ�������������������ݵ���β
Status batchInsertToTail_DuL(DuL& duL, DuLinkedListElementType* datas, int length);

// 07_˫��ѭ��������ɾ��ָ��������Ԫ��
DuLinkedListElementType deleteByIndex_DuL(DuL& duL, int index);