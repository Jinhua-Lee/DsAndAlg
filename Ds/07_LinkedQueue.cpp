#include "07_LinkedQueue.h"

/* ������ջ�ķ���*/
void testLinkedQueue()
{
	LinkedQueue lq;
	
	// ���Դ�ͷ���
	testQueueWithHead(lq);

	// ���Բ���ͷ���
	testQueueWithoutHead(lq);

}

/* ���Դ�ͷ���ķ���*/
void testQueueWithHead(LinkedQueue& lqh)
{
	// ��ʼ��
	printf("Linked Queue with head initializing...\n");
	initQueue_Lqh(lqh);
	printf("Linked Queue with head initialized.\n");

	// �����
	printf("enQueue...\n");
	enqueue_Lqh(lqh, 5);
	enqueue_Lqh(lqh, 6);
	enqueue_Lqh(lqh, 7);
	printf("enqueued.\n");

	// ������
	ElementType deq;
	while (dequeue_Lqh(lqh, deq))
	{
		printf("dequeued elem: %-2d\n", deq);
	}
}

/* ���Բ���ͷ���ķ���*/
void testQueueWithoutHead(LinkedQueue& lq)
{
	// ��ʼ��
	printf("Linked Queue without head initializing...\n");
	initQueue_Lqh(lq);
	printf("Linked Queue without head initialized.\n");

	// �����
	printf("enQueue...\n");
	enqueue_Lqh(lq, 5);
	enqueue_Lqh(lq, 6);
	enqueue_Lqh(lq, 7);
	printf("enqueued.\n");

	// ������
	ElementType deq;
	while (dequeue_Lqh(lq, deq))
	{
		printf("dequeued elem: %-2d\n", deq);
	}
}

/* 01_�����С�����ʼ��_��ͷ���*/
Status initQueue_Lqh(LinkedQueue& linkedQH)
{
	// ������нṹά�����Ŀռ�
	linkedQH = (LinkedQueue)malloc(sizeof(LinkedQueueNode));
	// ����ʧ�ܷ��ش���
	if (!linkedQH)
	{
		return ERROR;
	}
	// ����ͷ�ڵ�
	Queue head = (Queue)malloc(sizeof(QueueNode));
	// ����ʧ�ܷ��ش���
	if (!head)
	{
		return ERROR;
	}
	// ��ͷ�ڵ����õ�����ά�������
	linkedQH->front = head;
	linkedQH->rear = head;
	linkedQH->count = 0;
	return OK;
}

/* 02_�����С�����ʼ��_����ͷ���*/
Status initQueue_Lq(LinkedQueue& linkedQ)
{
	// �������ά�����ռ�
	linkedQ = (LinkedQueue)malloc(sizeof(QueueNode));
	if (!linkedQ)
	{
		return ERROR;
	}
	// ��ͷ�ڵ㣬������ָ��ΪNULL
	linkedQ->front = NULL;
	linkedQ->rear = NULL;
	linkedQ->count = 0;
	return OK;
}

/* 03_�����С������г���_ͷ���/����ͷ���*/
int queueLength_Lq(LinkedQueue linkedQ)
{
	// ���������е�ͳ����Ϣ��Ҫ���������Խ����ȵ���Ϣ��¼�����е�ά�������
	return linkedQ->count;
}

/* 04_�����С����ӿ�_��ͷ���*/
Status queueEmpty_Lqh(LinkedQueue linkedQH)
{
	// ͬʱָ��ͷ��㣬��Ϊ��
	return (linkedQH->front == linkedQH->rear) ? OK : ERROR;
}

/* 05_�����С����ӿ�_����ͷ���*/
Status queueEmpty_Lq(LinkedQueue linkedQ)
{
	// ��Ϊ�գ������Ϊ��
	return (linkedQ->front == NULL && linkedQ->rear == NULL) ? OK : ERROR;
}

/* 06_�����С��������_��ͷ���*/
Status enqueue_Lqh(LinkedQueue& linkedQH, ElementType elem)
{
	// ��rear���޸���Ҫȡ����
	Queue& rear = linkedQH->rear;
	// �������
	Queue newRear = (Queue)malloc(sizeof(QueueNode));
	if (!newRear)
	{
		return ERROR;
	}
	newRear->data = elem;
	newRear->next = NULL;

	// ���ö�β���
	rear->next = newRear;
	rear = rear->next;
	// �����Ƕ���Ԫ�ظ���
	linkedQH->count++;
	return OK;
}

/* 07_�����С��������_����ͷ���*/
Status enqueue_Lq(LinkedQueue& linkedQ, ElementType elem)
{
	// �Ƚ������
	Queue enQueue = (Queue)malloc(sizeof(QueueNode));
	if (!enQueue)
	{
		return ERROR;
	}
	// ����ͷ���������У��ӿյ�ʱ����׺Ͷ�β��ΪNULL
	if (queueEmpty_Lq(linkedQ))
	{
		// ͬʱָ������ӽ��
		linkedQ->front = enQueue;
		linkedQ->rear = enQueue;
	}
	else
	{
		// �����Ӷ�β�����޸�ά�����Ķ�βָ��
		linkedQ->rear->next = enQueue;
		linkedQ->rear = linkedQ->rear->next;
	}
	// �����Ƕ���Ԫ�ظ���
	linkedQ->count++;
	return OK;
}

/* 08_�����С��������С�����ͷ���*/
Status dequeue_Lqh(LinkedQueue& linkedQH, ElementType& elem)
{
	// ����Ϊ�գ�����
	if (queueEmpty_Lqh(linkedQH))
	{
		return ERROR;
	}
	// ����������еĽ������
	Queue& head = linkedQH->front;
	elem = head->next->data;
	head->next = head->next->next;
	// ���ֻ��һ��Ԫ�أ����漰�޸Ķ�βָ��
	if (linkedQH->count == 1)
	{
		linkedQH->rear = head;
	}
	// �����˶���Ԫ�ظ���
	linkedQH->count--;
	return OK;
}

/* 09_�����С���������_����ͷ���*/
Status dequeue_Lq(LinkedQueue& linkedQ, ElementType& elem)
{
	// ����Ϊ�գ�����
	if (queueEmpty_Lqh(linkedQ))
	{
		return ERROR;
	}
	// ����������еĽ������
	elem = linkedQ->front->data;
	// �����У�front������
	linkedQ->front = linkedQ->front->next;
	// ���ֻ��һ��Ԫ�أ����漰�޸Ķ�βָ��
	if (linkedQ->count == 1)
	{
		linkedQ->rear = NULL;
	}
	// �����˶���Ԫ�ظ���
	linkedQ->count--;
	return OK;
}
