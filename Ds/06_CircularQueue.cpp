#include "06_CircularQueue.h"

/* 01_ѭ�����С�����ʼ��*/
Status initQueue_Cq(CQueue& cQ)
{
    // ���ݲ��ֵĴ洢�ռ�����
    cQ.elem = (ElementType*)malloc(Queue_INIT_SIZE * sizeof(ElementType));
    // �ռ����ʧ�ܣ����ش���
    if (!cQ.elem)
    {
        return ERROR;
    }
    // ��ʼ״̬�����׺Ͷ�β�غ�
    // ��Ԫ��ʱ����Ҫע��rearʼ��ָ���βԪ�ص���һ��λ��
    cQ.front = 0;
    cQ.rear = 0;
    // ������������ʼ��
    cQ.queueSize = Queue_INIT_SIZE;
    cQ.incrementSize = Queue_INCREMENT;
    return OK;
}

/* 02_ѭ�����С������г���*/
int queueLength_Cq(CQueue cQ)
{
    // 1. ����1��ͨ��front��rear
    int length = cQ.front > cQ.rear ? cQ.front - cQ.rear + cQ.queueSize : cQ.front - cQ.rear;

    // 2. ����2��ֱ��ͨ����Ԫ�ظ�����������
    int length = cQ.count;

    return length;
}

/* 03_ѭ�����С��������*/
Status enqueue_Cq(CQueue& cQ, ElementType elem)
{
    // TODO:
    return OK;
}

/* 04_ѭ�����С���������*/
Status dequeue_Cq(CQueue& cQ, ElementType& elem)
{
    // TODO
    return OK;
}

/* 05_ѭ�����С�������*/
Status incrementQueue_Cq(CQueue& cQ)
{
    return OK;
}

/* 06_ѭ�����С�������*/
Status queueFull_Cq(CQueue cQ)
{
    return OK;
}

/* 07_ѭ�����С����ӿ�*/
Status queueEmpty_Cq(CQueue cQ)
{
    return OK;
}


