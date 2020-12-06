#include "07_LinkedQueue.h"

/* 测试链栈的方法*/
void testLinkedQueue()
{
	LinkedQueue lq;
	
	// 测试带头结点
	testQueueWithHead(lq);

	// 测试不带头结点
	testQueueWithoutHead(lq);

}

/* 测试带头结点的方法*/
void testQueueWithHead(LinkedQueue& lqh)
{
	// 初始化
	printf("Linked Queue with head initializing...\n");
	initQueue_Lqh(lqh);
	printf("Linked Queue with head initialized.\n");

	// 入队列
	printf("enQueue...\n");
	enqueue_Lqh(lqh, 5);
	enqueue_Lqh(lqh, 6);
	enqueue_Lqh(lqh, 7);
	printf("enqueued.\n");

	// 出队列
	LinkedQueueElementType deq;
	while (dequeue_Lqh(lqh, deq))
	{
		printf("dequeued elem: %-2d\n", deq);
	}
}

/* 测试不带头结点的方法*/
void testQueueWithoutHead(LinkedQueue& lq)
{
	// 初始化
	printf("Linked Queue without head initializing...\n");
	initQueue_Lqh(lq);
	printf("Linked Queue without head initialized.\n");

	// 入队列
	printf("enQueue...\n");
	enqueue_Lqh(lq, 5);
	enqueue_Lqh(lq, 6);
	enqueue_Lqh(lq, 7);
	printf("enqueued.\n");

	// 出队列
	LinkedQueueElementType deq;
	while (dequeue_Lqh(lq, deq))
	{
		printf("dequeued elem: %-2d\n", deq);
	}
}

/* 01_链队列——初始化_带头结点*/
Status initQueue_Lqh(LinkedQueue& linkedQH)
{
	// 分配队列结构维护结点的空间
	linkedQH = (LinkedQueue)malloc(sizeof(LinkedQueueNode));
	// 分配失败返回错误
	if (!linkedQH)
	{
		return ERROR;
	}
	// 创建头结点
	Queue head = (Queue)malloc(sizeof(QueueNode));
	// 创建失败返回错误
	if (!head)
	{
		return ERROR;
	}
	// 将头结点设置到队列维护结点中
	linkedQH->front = head;
	linkedQH->rear = head;
	linkedQH->count = 0;
	return OK;
}

/* 02_链队列——初始化_不带头结点*/
Status initQueue_Lq(LinkedQueue& linkedQ)
{
	// 分配队列维护结点空间
	linkedQ = (LinkedQueue)malloc(sizeof(QueueNode));
	if (!linkedQ)
	{
		return ERROR;
	}
	// 无头结点，则两个指向为NULL
	linkedQ->front = NULL;
	linkedQ->rear = NULL;
	linkedQ->count = 0;
	return OK;
}

/* 03_链队列——队列长度_头结点/不带头结点*/
int queueLength_Lq(LinkedQueue linkedQ)
{
	// 由于链队列的统计信息需要遍历，所以将长度等信息记录到队列的维护结点中
	return linkedQ->count;
}

/* 04_链队列——队空_带头结点*/
Status queueEmpty_Lqh(LinkedQueue linkedQH)
{
	// 同时指向头结点，则为空
	return (linkedQH->front == linkedQH->rear) ? OK : ERROR;
}

/* 05_链队列——队空_不带头结点*/
Status queueEmpty_Lq(LinkedQueue linkedQ)
{
	// 都为空，则队列为空
	return (linkedQ->front == NULL && linkedQ->rear == NULL) ? OK : ERROR;
}

/* 06_链队列——入队列_带头结点*/
Status enqueue_Lqh(LinkedQueue& linkedQH, LinkedQueueElementType elem)
{
	// 对rear的修改需要取引用
	Queue& rear = linkedQH->rear;
	// 建立结点
	Queue newRear = (Queue)malloc(sizeof(QueueNode));
	if (!newRear)
	{
		return ERROR;
	}
	newRear->data = elem;
	newRear->next = NULL;

	// 设置队尾结点
	rear->next = newRear;
	rear = rear->next;
	// 别忘记队列元素个数
	linkedQH->count++;
	return OK;
}

/* 07_链队列——入队列_不带头结点*/
Status enqueue_Lq(LinkedQueue& linkedQ, LinkedQueueElementType elem)
{
	// 先建立结点
	Queue enQueue = (Queue)malloc(sizeof(QueueNode));
	if (!enQueue)
	{
		return ERROR;
	}
	// 不带头结点的链队列，队空的时候队首和队尾都为NULL
	if (queueEmpty_Lq(linkedQ))
	{
		// 同时指向新入队结点
		linkedQ->front = enQueue;
		linkedQ->rear = enQueue;
	}
	else
	{
		// 先连接队尾，再修改维护结点的队尾指针
		linkedQ->rear->next = enQueue;
		linkedQ->rear = linkedQ->rear->next;
	}
	// 别忘记队列元素个数
	linkedQ->count++;
	return OK;
}

/* 08_链队列——出队列——带头结点*/
Status dequeue_Lqh(LinkedQueue& linkedQH, LinkedQueueElementType& elem)
{
	// 队列为空，报错
	if (queueEmpty_Lqh(linkedQH))
	{
		return ERROR;
	}
	// 保存待出队列的结点数据
	Queue& head = linkedQH->front;
	elem = head->next->data;
	head->next = head->next->next;
	// 如果只有一个元素，则涉及修改队尾指针
	if (linkedQH->count == 1)
	{
		linkedQH->rear = head;
	}
	// 别忘了队列元素个数
	linkedQH->count--;
	return OK;
}

/* 09_链队列——出队列_不带头结点*/
Status dequeue_Lq(LinkedQueue& linkedQ, LinkedQueueElementType& elem)
{
	// 队列为空，报错
	if (queueEmpty_Lqh(linkedQ))
	{
		return ERROR;
	}
	// 保存待出队列的结点数据
	elem = linkedQ->front->data;
	// 出队列，front结点后移
	linkedQ->front = linkedQ->front->next;
	// 如果只有一个元素，则涉及修改队尾指针
	if (linkedQ->count == 1)
	{
		linkedQ->rear = NULL;
	}
	// 别忘了队列元素个数
	linkedQ->count--;
	return OK;
}
