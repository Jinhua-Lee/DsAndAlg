#pragma once
#include <stdio.h>
#include <stdlib.h>

// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define LinkedListElementType int

/* ���嵥������*/
typedef struct SL_Node
{
	// �洢��Ԫ��
	LinkedListElementType data;
	// ָ����һ������ָ��
	SL_Node* next;
}HNode, *SL;

// ���Ե�����ķ���
void testSingleLinkedList();

// ��ͷ���Ĳ��Է���
void testWithHead(LinkedListElementType* datas, int length);

// ����ͷ���Ĳ��Է���
void testWithoutHead(LinkedListElementType* datas, int length);

// ������������ϲ��ķ���
void testMerge();

// ������������������ϲ�Ϊһ���ݼ����е�����
SL mergeTwoList(SL headA, SL headB);

// 01_����������ʼ��_��ͷ���
Status initList_SLh(SL& head);

// 02_����������ʼ��_��ͷ���
Status initList_SL(SL& sL);

// 03_������������_��ͷ���
int listLength_SLh(SL head);

// 04_������������_��ͷ���
int listLength_SL(SL sL);

// 05_������������_��ͷ���
void destroy_SLh(SL& head);

// 06_������������_��ͷ���
void destroy_SL(SL& sL);

// 07_��������β�巨����_��ͷ���
Status tailInsert_SLh(SL& head, LinkedListElementType* datas, int length);

// 08_��������β�巨����_����ͷ���
Status tailInsert_SL(SL& sL, LinkedListElementType* datas, int length);

// 09_��������ͷ�巨����_��ͷ���
Status headInsert_SLh(SL& head, LinkedListElementType* datas, int length);

// 10_��������ͷ�巨����_����ͷ���
Status headInsert_SL(SL& sL, LinkedListElementType* datas, int length);

// 11_������������_��ͷ���
void traveseList_SLh(SL head);

// 12_������������_����ͷ���
void traverseList_SL(SL sL);

// 13_�����������ʷ���
void visit(HNode hnode);

// 14_��������ɾ�����_��ͷ���
void deleteElem_SLh(SL& head, LinkedListElementType data);

// 15_��������ɾ�����_����ͷ���
void deleteElem_SL(SL& sL, LinkedListElementType data);

// 16_��������ԭ������_��ͷ���
void invertList_SLh(SL& head);

// 17_��������ԭ������_����ͷ���
void invertList_SL(SL& sL);

// 18_����������ʼ��_��ͷ���2
Status initList_SLh2(HNode** hNode);