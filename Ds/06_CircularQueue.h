#include <stdio.h>
#include <stdlib.h>

// �����ʼ��С������
#define LIST_INIT_SIZE 150
#define LIST_INCREMENT 20
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
	int length;

	// ��ͷ������
	int front;

	// ��β����
	int rear;

	// ��������
	int queueSize;
}CQueue, *Q;

// 01_ѭ�����С�����ʼ��