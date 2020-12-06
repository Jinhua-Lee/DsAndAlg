#pragma once
#include <stdio.h>
#include <stdlib.h>

// �����ʼ��С������
#define Queue_INIT_SIZE 7
#define Queue_INCREMENT 3
// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define CQueueElementType int

// ѭ�����еĴ洢�ṹ
typedef struct CircularQueue
{
	// �洢���ݵ�����
	CQueueElementType* elem;

	// ���еĵ�ǰԪ�ظ���
	int count;

	// ��ͷ������
	int front;

	// ��β��������Ҫע��rearʼ��ָ���βԪ�ص���һ��λ��
	int rear;

	// ��������,��Ҫע�⡾ʵ���������Ǳ����ֵС1�ģ�Ϊ����������Ͷӿյ����
	int queueSize;

	// ѭ���������ݵ�����
	int incrementSize;
}CQueue;

// ����ѭ�����еķ���
void testCircularQueue();

// ������ķ�ʽ�����������ڲ���
void testTraverse(CQueue cQ);

// 01_ѭ�����С�����ʼ��
Status initQueue_Cq(CQueue& cQ);

// 02_ѭ�����С������г���
int queueLength_Cq(CQueue cQ);

// 03_ѭ�����С��������
Status enqueue_Cq(CQueue& cQ, CQueueElementType elem);

// 04_ѭ�����С���������
Status dequeue_Cq(CQueue& cQ, CQueueElementType& elem);

// 05_ѭ�����С�������
Status incrementQueue_Cq(CQueue& cQ);

// 06_ѭ�����С�������
Status queueFull_Cq(CQueue cQ);

// 07_ѭ�����С����ӿ�
Status queueEmpty_Cq(CQueue cQ);

// 08_ѭ�����С�����ȡ����Ԫ��
Status getFront_Cq(CQueue cQ, CQueueElementType& elem);