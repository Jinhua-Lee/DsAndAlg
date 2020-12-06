#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "02_SingleLinkedList.h"

// 定义返回状态及返回码
#define Status int
#define OK 1
#define ERROR 0
// 定义存储的元素类型
#define LinkedQueueElementType int

// 引用单链表结点，一个数据域，一个指针域
typedef SL_Node QueueNode, *Queue;

// 定义维护链队列的结构
typedef struct LinkedQueueNode
{
	// 队首结点指针
	QueueNode* front;
	// 队尾结点指针
	QueueNode* rear;
	// 队列元素个数计数
	int count;
}*LinkedQueue;

// 定义测试链栈的方法
void testLinkedQueue();

// 测试带头结点的方法
void testQueueWithHead(LinkedQueue& lqh);

// 测试不带头结点的方法
void testQueueWithoutHead(LinkedQueue& lq);

// 01_链队列——初始化_带头结点
Status initQueue_Lqh(LinkedQueue& linkedQH);

// 02_链队列——初始化_不带头结点
Status initQueue_Lq(LinkedQueue& linkedQ);

// 03_链队列——队列长度_头结点/不带头结点
int queueLength_Lq(LinkedQueue linkedQ);

// 04_链队列——队空_带头结点
Status queueEmpty_Lqh(LinkedQueue linkedQH);

// 05_链队列——队空_不带头结点
Status queueEmpty_Lq(LinkedQueue linkedQ);

// 06_链队列——入队列_带头结点
Status enqueue_Lqh(LinkedQueue& linkedQH, LinkedQueueElementType elem);

// 07_链队列——入队列_不带头结点
Status enqueue_Lq(LinkedQueue& linkedQ, LinkedQueueElementType elem);

// 08_链队列——出队列——带头结点
Status dequeue_Lqh(LinkedQueue& linkedQH, LinkedQueueElementType& elem);

// 09_链队列——出队列_不带头结点
Status dequeue_Lq(LinkedQueue& linkedQ, LinkedQueueElementType& elem);