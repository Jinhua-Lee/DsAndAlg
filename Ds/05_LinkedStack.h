#include <stdio.h>
#include <stdlib.h>
#include "02_SingleLinkedList.h"

// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define LinkedStackElementType int

// ���õ�����Ľ�㶨�壬���ڲ����򵥣����Բ���ͷ��㼴��
// ����ָ��õ���ջ����ָ������
typedef SL_Node S_Node, *LS;

// ���Ե���ջ�ķ���
void testLinkedStack();

// 01_����ջ������ʼ��
Status initStack_LS(LS& Ls);

// 02_����ջ����ȡջ��
Status getTop_LS(LS& Ls, LinkedStackElementType& elem);

// 03_����ջ������ջ
Status push_LS(LS& Ls, LinkedStackElementType elem);

// 04_����ջ������ջ
Status pop_LS(LS& Ls, LinkedStackElementType& elem);

// 05_����ջ����ջ����
int stackLength_LS(LS Ls);

// 06_����ջ�����п�
Status stackEmpty_LS(LS Ls);

// 07_����ջ�������
Status clearStack_LS(LS& Ls);