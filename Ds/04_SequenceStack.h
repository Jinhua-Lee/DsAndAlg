#pragma once
#include <stdio.h>
#include <stdlib.h>

// �����ʼ��С������
#define STACK_INIT_SIZE 150
#define STACK_INCREMENT 20
// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define ElementType int

// ˳��ջ�Ľṹ����
typedef struct SqStack
{
	// �洢Ԫ�ص�����
	ElementType* elem;
	// ջ��Ԫ�ص������������Ϊջ��ָ�룩
	int top;
	// ջ����
	int stackSize;
	// ÿ�����ݵĴ�С
	int incrementSize;
}SqStack;

// ����˳��ջ�ķ���
void testSequenceStack();

// 01_˳��ջ������ʼ��
Status initStack_Sq(SqStack& sS);

// 02_˳��ջ����ȡջ��Ԫ��
Status getTop_Sq(SqStack sS, ElementType& e);

// 03_˳��ջ������ջ
Status push_Sq(SqStack& sS, ElementType e);

// 04_˳��ջ������ջ
Status pop_Sq(SqStack& sS, ElementType& e);

// 05_˳��ջ��������
Status destroyStack_Sq(SqStack& sS);

// 06_˳��ջ�����ж�ջ��
Status stackEmpty_Sq(SqStack sS);

// 07_˳��ջ�������ջ
Status clearStack_Sq(SqStack& sS);

// 08_˳��ջ��������
Status incrementStack_Sq(SqStack& sS);

// 09_˳��ջ����ջ����
int stackLength_Sq(SqStack sS);