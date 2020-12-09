#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "08_LinkedBinaryTree.h"

// 定义初始大小和增量
#define Queue_INIT_SIZE 7
#define Queue_INCREMENT 3
// 定义返回状态及返回码
#define Status int
#define OK 1
#define ERROR 0
// 定义存储的元素类型
#define CQueueElementType BinaryTree

// 循环队列的存储结构
typedef struct CircularQueue
{
	// 存储数据的数组
	CQueueElementType* elem;

	// 队列的当前元素个数
	int count;

	// 队头的索引
	int front;

	// 队尾索引，需要注意rear始终指向队尾元素的下一个位置
	int rear;

	// 队列容量,需要注意【实际容量】是比这个值小1的，为了区别队满和队空的情况
	int queueSize;

	// 循环队列扩容的增量
	int incrementSize;
}CQueue;

// 测试循环队列的方法
void testCircularQueue();

// 以数组的方式来遍历，用于测试
void testTraverse(CQueue cQ);

// 01_循环队列——初始化
Status initQueue_Cq(CQueue& cQ);

// 02_循环队列——队列长度
int queueLength_Cq(CQueue cQ);

// 03_循环队列——入队列
Status enqueue_Cq(CQueue& cQ, CQueueElementType elem);

// 04_循环队列——出队列
Status dequeue_Cq(CQueue& cQ, CQueueElementType& elem);

// 05_循环队列——扩容
Status incrementQueue_Cq(CQueue& cQ);

// 06_循环队列——队满
Status queueFull_Cq(CQueue cQ);

// 07_循环队列——队空
Status queueEmpty_Cq(CQueue cQ);

// 08_循环队列——获取队首元素
Status getFront_Cq(CQueue cQ, CQueueElementType& elem);