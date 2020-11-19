#include <stdio.h>
#include <stdlib.h>

// �����ʼ��С������
#define Queue_INIT_SIZE 150
#define Queue_INCREMENT 20
// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define ElementType int

// ѭ�����еĴ洢�ṹ
typedef struct CircularQueue
{
	// �洢���ݵ�����
	ElementType* elem;

	// ���еĵ�ǰԪ�ظ���
	int count;

	// ��ͷ������
	int front;

	// ��β����
	int rear;

	// ��������
	int queueSize;

	// ѭ���������ݵ�����
	int incrementSize;
}CQueue;

// 01_ѭ�����С�����ʼ��
Status initQueue_Cq(CQueue& cQ);

// 02_ѭ�����С������г���
int queueLength_Cq(CQueue cQ);

// 03_ѭ�����С��������
Status enqueue_Cq(CQueue& cQ, ElementType elem);

// 04_ѭ�����С���������
Status dequeue_Cq(CQueue& cQ, ElementType& elem);

// 05_ѭ�����С�������
Status incrementQueue_Cq(CQueue& cQ);

// 06_ѭ�����С�������
Status queueFull_Cq(CQueue cQ);

// 07_ѭ�����С����ӿ�
Status queueEmpty_Cq(CQueue cQ);