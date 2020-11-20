#include "06_CircularQueue.h"

/* 01_循环队列——初始化*/
Status initQueue_Cq(CQueue& cQ)
{
    // 数据部分的存储空间申请
    cQ.elem = (ElementType*)malloc((Queue_INIT_SIZE) * sizeof(ElementType));
    // 空间分配失败，返回错误
    if (!cQ.elem)
    {
        return ERROR;
    }
    // 初始状态，队首和队尾重合
    // 有元素时候，需要注意rear始终指向队尾元素的下一个位置
    cQ.front = 0;
    cQ.rear = 0;
    // 容量和增量初始化
    cQ.queueSize = Queue_INIT_SIZE;
    cQ.incrementSize = Queue_INCREMENT;
    return OK;
}

/* 02_循环队列——队列长度*/
int queueLength_Cq(CQueue cQ)
{
    // 1. 方法1，通过front和rear
    int length = cQ.front > cQ.rear ? cQ.front - cQ.rear + cQ.queueSize : cQ.front - cQ.rear;

    // 2. 方法2，直接通过的元素个数计数变量
    int length = cQ.count;

    return length;
}

/* 03_循环队列——入队列*/
Status enqueue_Cq(CQueue& cQ, ElementType elem)
{
    // TODO:
    return OK;
}

/* 04_循环队列——出队列*/
Status dequeue_Cq(CQueue& cQ, ElementType& elem)
{
    // TODO
    return OK;
}

/* 05_循环队列——扩容*/
Status incrementQueue_Cq(CQueue& cQ)
{
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
    // 重合即表示队列为空
    return cQ.front == cQ.rear;
}


