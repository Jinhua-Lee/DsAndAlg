#include<stdio.h>
#include<stdlib.h>

// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define ElementType int

/* ���嵥������*/
typedef struct SL_Node
{
	// �洢��Ԫ��
	ElementType data;
	// ָ����һ������ָ��
	struct SL_Node* next;
}Hnode, *SL;

// ���Ե�����ķ���
void testSingleLinkedList();

// 01_����������ʼ��_��ͷ���
Status initList_SLh(SL& head);

// 02_����������ʼ��_��ͷ���
Status initList_SL(SL& sL);

// 03_������������_��ͷ���
int listLength_SLh(SL head);

// 04_������������_��ͷ���
int listLength_SL(SL sL);

// 05_������������_��ͷ�ڵ�
void destroy_SLh(SL& head);

// 06_������������_��ͷ�ڵ�
void destroy_SL(SL& sL);

// 07_��������β�巨����_��ͷ�ڵ�
Status tailInsert_SLh(SL& head, ElementType* datas, int length);

// 08_��������β�巨����_����ͷ�ڵ�
Status tailInsert_SL(SL& sL, ElementType* datas, int length);

// 09_��������ͷ�巨����_��ͷ���
Status headInsert_SLh(SL& head, ElementType* datas, int length);

// 10_��������ͷ�巨����_����ͷ���
Status headInsert_SL(SL& sL, ElementType* datas, int length);

// 11_������������_��ͷ���
void traveseList_SLh(SL head);

// 12_������������_����ͷ���
void traverseList_SL(SL sL);

// 13_�����������ʷ���
void visit(Hnode hnode);