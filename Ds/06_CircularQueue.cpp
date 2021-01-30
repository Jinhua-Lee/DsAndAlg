#include "06_CircularQueue.h"

/* 测试循环队列的方法*/
void testCircularQueue()
{
    //CQueue cQ;

 //   // 初始化
 //   int initStatus = initQueue_Cq(cQ);
 //   printf("CQ init Status: %d\n", initStatus);

 //   // 针对扩容的测试用例，size = 7，6个元素为满
 //   CQueueElementType front;
 //   enqueue_Cq(cQ, 1);
	//enqueue_Cq(cQ, 2);
	//enqueue_Cq(cQ, 3);
	//enqueue_Cq(cQ, 4);
	//enqueue_Cq(cQ, 5);
	//enqueue_Cq(cQ, 6);

 //   getFront_Cq(cQ, front);
 //   printf("获取队首元素：%-4d\n", front);
 //   printf("count: %-4d\n", cQ.count);

 //   printf("队列满之前：\n");
 //   testTraverse(cQ);

 //   CQueueElementType elem = NULL;
 //   // 出队4个，再入队
 //   for (int i = 0; i < cQ.incrementSize + 1; i++)
 //   {
 //       dequeue_Cq(cQ, elem);
 //       printf("\n再入队元素： %-2d", elem);
 //       enqueue_Cq(cQ, elem);
 //   }

	//printf("\n重新入队后：\n");
	//testTraverse(cQ);

 //   // 此时进行扩容，并移动了元素
 //   enqueue_Cq(cQ, 11);
 //   printf("\n遍历扩容后：\n");
 //   testTraverse(cQ);

}

/* 以数组的方式来遍历，用于测试*/
void testTraverse(CQueue cQ)
{
	//for (int i = 0; i < cQ.queueSize; i++)
	//{
	//	printf("%-4d  ", *(cQ.elem + i));
	//}
}

/* 01_循环队列——初始化*/
Status initQueue_Cq(CQueue& cQ)
{
    // 数据部分的存储空间申请
    cQ.elem = (CQueueElementType*)malloc((Queue_INIT_SIZE) * sizeof(CQueueElementType));
    // 空间分配失败，返回错误
    if (!cQ.elem)
    {
        return ERROR;
    }
    // 初始状态，队首和队尾重合
    // 有元素时候，需要注意rear始终指向队尾元素的下一个位置
    cQ.front = 0;
    cQ.rear = 0;
    cQ.count = 0;
    // 容量和增量初始化
    cQ.queueSize = Queue_INIT_SIZE;
    cQ.incrementSize = Queue_INCREMENT;
    return OK;
}

/* 02_循环队列——队列长度*/
int queueLength_Cq(CQueue cQ)
{
    int length;
    // 1. 方法1，通过front和rear
    length = cQ.front > cQ.rear ? cQ.rear - cQ.front + cQ.queueSize : cQ.rear - cQ.front;

    // 2. 方法2，直接通过的元素个数计数变量
    length = cQ.count;

    return length;
}

/* 03_循环队列——入队列*/
Status enqueue_Cq(CQueue& cQ, CQueueElementType elem)
{
    // 如果队列满了进行扩容
    if (queueFull_Cq(cQ))
    {
        // 如果扩容失败，返回
        if (!incrementQueue_Cq(cQ)) {
            return ERROR;
        }
    }
    // 入队列操作
    *(cQ.elem + cQ.rear) = elem;
    cQ.rear = (cQ.rear + 1) % cQ.queueSize;
    // 别忘记队列长度
    cQ.count++;
    return OK;
}

/* 04_循环队列——出队列*/
Status dequeue_Cq(CQueue& cQ, CQueueElementType& elem)
{
    // 如果队列为空，返回失败
    if (queueEmpty_Cq(cQ))
    {
        elem = NULL;
        return ERROR;
    }
    // 进行出队列操作
    elem = *(cQ.elem + cQ.front);
    *(cQ.elem + cQ.front) = NULL;
    cQ.front = (cQ.front + 1) % cQ.queueSize;
    // 别忘记队列长度
    cQ.count--;
    return OK;
}

/* 05_循环队列——扩容*/
/**
 * 循环队列扩容场景分析：
 * 1. 如果队列满时候 rear > front，即满队状态没有进行循环。则realloc可以直接使用。
 * 2. 如果队列满时候 rear < front，即满队状态有元素越过 size - 1的索引，从0再存，
 *      那么此时直接使用realloc会导致获取队列元素，队列中会有很多空的位置。
 *      这种情况是需要处理的。
 *      a. 先进行realloc重新分配，再进行元素移动。本函数采用该方法实现
 *      b. 创建新数组，依次出队列，入队到新数组，毁原数组。
 */
Status incrementQueue_Cq(CQueue& cQ)
{
    CQueueElementType* newElem;
    newElem = (CQueueElementType*)realloc(cQ.elem, (cQ.queueSize + (size_t)cQ.incrementSize) * sizeof(CQueueElementType));
    // 扩容失败返回错误
	if (!newElem)
	{
		return ERROR;
	}
    cQ.elem = newElem;
    cQ.queueSize += cQ.incrementSize;
    printf("\n扩容后，移动前\n");
    testTraverse(cQ);
    // 当有用到循环，从数组0处再入队时候，需要对元素的位置进行操作，设置rear索引
    if (cQ.rear < cQ.front)
    {
        // 当数组索引 rear 之前元素个数小于等于扩容的大小
        if (cQ.rear <= cQ.incrementSize)
        {
            // 队头的元素移动部分或全部到队尾
            for (int i = 0; i < cQ.rear; i++)
            {
                *(cQ.elem + cQ.queueSize - cQ.incrementSize + i) = *(cQ.elem + i);
            }
            // 设置rear索引
            cQ.rear += cQ.queueSize - cQ.incrementSize;
        }
        else
        {
			for (int i = 0; i < cQ.rear; i++)
			{
				// 前increment个元素全部移到后面
				if (i < cQ.incrementSize)
				{
                    *(cQ.elem + cQ.queueSize - cQ.incrementSize + i) = *(cQ.elem + i);
				}
				// 多出的放队列数组首部
				else
				{
					*(cQ.elem + i - cQ.incrementSize) = *(cQ.elem + i);
				}
			}
            // 设置rear索引
            cQ.rear -= cQ.incrementSize;
        }
    }
    
    return OK;
}

/* 06_循环队列——队满*/
Status queueFull_Cq(CQueue cQ)
{
    // 判断队满条件是循环【队首元素】和【队尾】中间隔一个，由于rear指向队尾的下一个，所以rear相邻的下一个是front
    if ((cQ.rear + 1) % cQ.queueSize == cQ.front)
    {
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/* 07_循环队列——队空*/
Status queueEmpty_Cq(CQueue cQ)
{
    // 队首指针与队尾指针重合即表示队列为空
    return cQ.front == cQ.rear;
}

/* 08_循环队列——获取队首元素*/
Status getFront_Cq(CQueue cQ, CQueueElementType& elem)
{
    // 如果为空，返回NULL
    if (queueEmpty_Cq(cQ))
    {
        elem = NULL;
        return ERROR;
    }
    elem = *(cQ.elem + cQ.front);
    return OK;
}
