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
	ElementType elem;
	// ָ����һ������ָ��
	SL_Node* next;
}hNode, *SL;

// ���Ե�����ķ���
void testSingleLinkedList();

// 01_����������ʼ��������_��ͷ���
SL_Node* initList_SLh();
// 02_����������ʼ��������_��ͷ���
SL_Node* initList_SL();
// 03_����������������_��ͷ���
int listLength_SLh(hNode hNode);
// 04_����������������_��ͷ���
int listLength_SL(SL sL);
// 05_�����������ٵ�����_��ͷ�ڵ�
void destroy_SLh(hNode& hNode);
// 06_�����������ٵ�����_��ͷ�ڵ�
void destroy_SL(SL& sL);
// 07_��������β�巨����������_��ͷ�ڵ�
SL_Node* tailInsert_SLh(hNode& hNode);
// 08_��������β�巨����������_����ͷ�ڵ�
SL_Node* tailInsert_SL(SL& sL);
// 09_��������ͷ�巨����������_��ͷ���
SL_Node* headInsert_SLh(hNode& hNode);
// 10_��������ͷ�巨����������_����ͷ���
SL_Node* headInsert_SL(SL& sL);