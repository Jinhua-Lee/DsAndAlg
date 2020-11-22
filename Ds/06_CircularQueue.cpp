#include "06_CircularQueue.h"

/* ����ѭ�����еķ���*/
void testCircularQueue()
{
    CQueue cQ;

    // ��ʼ��
    int initStatus = initQueue_Cq(cQ);
    printf("CQ init Status: %d\n", initStatus);

    // ������ݵĲ���������size = 7��6��Ԫ��Ϊ��
    ElementType front;
    enqueue_Cq(cQ, 1);
	enqueue_Cq(cQ, 2);
	enqueue_Cq(cQ, 3);
	enqueue_Cq(cQ, 4);
	enqueue_Cq(cQ, 5);
	enqueue_Cq(cQ, 6);

    getFront_Cq(cQ, front);
    printf("��ȡ����Ԫ�أ�%-4d\n", front);
    printf("count: %-4d\n", cQ.count);

    printf("������֮ǰ��\n");
    testTraverse(cQ);

    ElementType elem = NULL;
    // ����4���������
    for (int i = 0; i < cQ.incrementSize + 1; i++)
    {
        dequeue_Cq(cQ, elem);
        printf("\n�����Ԫ�أ� %-2d", elem);
        enqueue_Cq(cQ, elem);
    }

	printf("\n������Ӻ�\n");
	testTraverse(cQ);

    // ��ʱ�������ݣ����ƶ���Ԫ��
    enqueue_Cq(cQ, 11);
    printf("\n�������ݺ�\n");
    testTraverse(cQ);

}

/* ������ķ�ʽ�����������ڲ���*/
void testTraverse(CQueue cQ)
{
	for (int i = 0; i < cQ.queueSize; i++)
	{
		printf("%-4d  ", *(cQ.elem + i));
	}
}

/* 01_ѭ�����С�����ʼ��*/
Status initQueue_Cq(CQueue& cQ)
{
    // ���ݲ��ֵĴ洢�ռ�����
    cQ.elem = (ElementType*)malloc((Queue_INIT_SIZE) * sizeof(ElementType));
    // �ռ����ʧ�ܣ����ش���
    if (!cQ.elem)
    {
        return ERROR;
    }
    // ��ʼ״̬�����׺Ͷ�β�غ�
    // ��Ԫ��ʱ����Ҫע��rearʼ��ָ���βԪ�ص���һ��λ��
    cQ.front = 0;
    cQ.rear = 0;
    cQ.count = 0;
    // ������������ʼ��
    cQ.queueSize = Queue_INIT_SIZE;
    cQ.incrementSize = Queue_INCREMENT;
    return OK;
}

/* 02_ѭ�����С������г���*/
int queueLength_Cq(CQueue cQ)
{
    int length;
    // 1. ����1��ͨ��front��rear
    length = cQ.front > cQ.rear ? cQ.rear - cQ.front + cQ.queueSize : cQ.rear - cQ.front;

    // 2. ����2��ֱ��ͨ����Ԫ�ظ�����������
    length = cQ.count;

    return length;
}

/* 03_ѭ�����С��������*/
Status enqueue_Cq(CQueue& cQ, ElementType elem)
{
    // ����������˽�������
    if (queueFull_Cq(cQ))
    {
        // �������ʧ�ܣ�����
        if (!incrementQueue_Cq(cQ)) {
            return ERROR;
        }
    }
    // ����в���
    *(cQ.elem + cQ.rear) = elem;
    cQ.rear = (cQ.rear + 1) % cQ.queueSize;
    // �����Ƕ��г���
    cQ.count++;
    return OK;
}

/* 04_ѭ�����С���������*/
Status dequeue_Cq(CQueue& cQ, ElementType& elem)
{
    // �������Ϊ�գ�����ʧ��
    if (queueEmpty_Cq(cQ))
    {
        elem = NULL;
        return ERROR;
    }
    // ���г����в���
    elem = *(cQ.elem + cQ.front);
    *(cQ.elem + cQ.front) = NULL;
    cQ.front = (cQ.front + 1) % cQ.queueSize;
    // �����Ƕ��г���
    cQ.count--;
    return OK;
}

/* 05_ѭ�����С�������*/
/**
 * ѭ���������ݳ���������
 * 1. ���������ʱ�� rear > front��������״̬û�н���ѭ������realloc����ֱ��ʹ�á�
 * 2. ���������ʱ�� rear < front��������״̬��Ԫ��Խ�� size - 1����������0�ٴ棬
 *      ��ô��ʱֱ��ʹ��realloc�ᵼ�»�ȡ����Ԫ�أ������л��кܶ�յ�λ�á�
 *      �����������Ҫ����ġ�
 *      a. �Ƚ���realloc���·��䣬�ٽ���Ԫ���ƶ������������ø÷���ʵ��
 *      b. ���������飬���γ����У���ӵ������飬��ԭ���顣
 */
Status incrementQueue_Cq(CQueue& cQ)
{
    ElementType* newElem;
    newElem = (ElementType*)realloc(cQ.elem, (cQ.queueSize + (size_t)cQ.incrementSize) * sizeof(ElementType));
    // ����ʧ�ܷ��ش���
	if (!newElem)
	{
		return ERROR;
	}
    cQ.elem = newElem;
    cQ.queueSize += cQ.incrementSize;
    printf("\n���ݺ��ƶ�ǰ\n");
    testTraverse(cQ);
    // �����õ�ѭ����������0�������ʱ����Ҫ��Ԫ�ص�λ�ý��в���������rear����
    if (cQ.rear < cQ.front)
    {
        // ���������� rear ֮ǰԪ�ظ���С�ڵ������ݵĴ�С
        if (cQ.rear <= cQ.incrementSize)
        {
            // ��ͷ��Ԫ���ƶ����ֻ�ȫ������β
            for (int i = 0; i < cQ.rear; i++)
            {
                *(cQ.elem + cQ.queueSize - cQ.incrementSize + i) = *(cQ.elem + i);
            }
            // ����rear����
            cQ.rear += cQ.queueSize - cQ.incrementSize;
        }
        else
        {
			for (int i = 0; i < cQ.rear; i++)
			{
				// ǰincrement��Ԫ��ȫ���Ƶ�����
				if (i < cQ.incrementSize)
				{
                    *(cQ.elem + cQ.queueSize - cQ.incrementSize + i) = *(cQ.elem + i);
				}
				// ����ķŶ��������ײ�
				else
				{
					*(cQ.elem + i - cQ.incrementSize) = *(cQ.elem + i);
				}
			}
            // ����rear����
            cQ.rear -= cQ.incrementSize;
        }
    }
    
    return OK;
}

/* 06_ѭ�����С�������*/
Status queueFull_Cq(CQueue cQ)
{
    // �ж϶���������ѭ��������Ԫ�ء��͡���β���м��һ��������rearָ���β����һ��������rear���ڵ���һ����front
    if ((cQ.rear + 1) % cQ.queueSize == cQ.front)
    {
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/* 07_ѭ�����С����ӿ�*/
Status queueEmpty_Cq(CQueue cQ)
{
    // ����ָ�����βָ���غϼ���ʾ����Ϊ��
    return cQ.front == cQ.rear;
}

/* 08_ѭ�����С�����ȡ����Ԫ��*/
Status getFront_Cq(CQueue cQ, ElementType& elem)
{
    // ���Ϊ�գ�����NULL
    if (queueEmpty_Cq(cQ))
    {
        elem = NULL;
        return ERROR;
    }
    elem = *(cQ.elem + cQ.front);
    return OK;
}
