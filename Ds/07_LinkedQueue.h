#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "02_SingleLinkedList.h"

// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define ElementType int

// ���õ������㣬һ��������һ��ָ����
typedef SL_Node QueueNode, *Queue;

// ����ά�������еĽṹ
typedef struct LinkedQueueNode
{
	// ���׽��ָ��
	QueueNode* front;
	// ��β���ָ��
	QueueNode* rear;
	// ����Ԫ�ظ�������
	int count;
}*LinkedQueue;

// ���������ջ�ķ���
void testLinkedQueue();

// ���Դ�ͷ���ķ���
void testQueueWithHead(LinkedQueue& lqh);

// ���Բ���ͷ���ķ���
void testQueueWithoutHead(LinkedQueue& lq);

// 01_�����С�����ʼ��_��ͷ���
Status initQueue_Lqh(LinkedQueue& linkedQH);

// 02_�����С�����ʼ��_����ͷ���
Status initQueue_Lq(LinkedQueue& linkedQ);

// 03_�����С������г���_ͷ���/����ͷ���
int queueLength_Lq(LinkedQueue linkedQ);

// 04_�����С����ӿ�_��ͷ���
Status queueEmpty_Lqh(LinkedQueue linkedQH);

// 05_�����С����ӿ�_����ͷ���
Status queueEmpty_Lq(LinkedQueue linkedQ);

// 06_�����С��������_��ͷ���
Status enqueue_Lqh(LinkedQueue& linkedQH, ElementType elem);

// 07_�����С��������_����ͷ���
Status enqueue_Lq(LinkedQueue& linkedQ, ElementType elem);

// 08_�����С��������С�����ͷ���
Status dequeue_Lqh(LinkedQueue& linkedQH, ElementType& elem);

// 09_�����С���������_����ͷ���
Status dequeue_Lq(LinkedQueue& linkedQ, ElementType& elem);