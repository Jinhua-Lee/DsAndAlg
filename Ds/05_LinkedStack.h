#include <stdio.h>
#include <stdlib.h>

// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define ElementType int

// ���õ�����Ľ�㶨�壬���ڲ����򵥣����Բ���ͷ��㼴��
// ����ָ��õ���ջ����ָ������
typedef struct S_Node
{
	// �洢��Ԫ��
	ElementType data;
	// ָ����һ������ָ��
	struct S_Node* next;
}*LS;

// ���Ե���ջ�ķ���
void testLinkedStack();

// 01_����ջ������ʼ��
Status initStack_LS(LS& Ls);

// 02_����ջ����ȡջ��
Status getTop_LS(LS& Ls, ElementType& elem);

// 03_����ջ������ջ
Status push_LS(LS& Ls, ElementType elem);

// 04_����ջ������ջ
Status pop_LS(LS& Ls, ElementType& elem);

// 05_����ջ����ջ����
int stackLength_LS(LS Ls);

// 06_����ջ�����п�
Status stackEmpty_LS(LS Ls);

// 07_����ջ�������
Status clearStack_LS(LS& Ls);