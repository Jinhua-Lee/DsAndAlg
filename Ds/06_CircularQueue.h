#include <stdio.h>
#include <stdlib.h>

// 定义初始大小和增量
#define Queue_INIT_SIZE 150
#define Queue_INCREMENT 20
// 定义返回状态及返回码
#define Status int
#define OK 1
#define ERROR 0
// 定义存储的元素类型
#define ElementType int

// 循环队列的存储结构
typedef struct CircularQueue
{
	// 存储数据的数组
	ElementType* elem;

	// 队列的当前元素个数
	int count;

	// 队头的索引
	int front;

	// 队尾索引
	int rear;

	// 队列容量
	int queueSize;

	// 循环队列扩容的增量
	int incrementSize;
}CQueue;

// 01_循环队列——初始化
Status initQueue_Cq(CQueue& cQ);

// 02_循环队列——队列长度
int queueLength_Cq(CQueue cQ);

// 03_循环队列——入队列
Status enqueue_Cq(CQueue& cQ, ElementType elem);

// 04_循环队列——出队列
Status dequeue_Cq(CQueue& cQ, ElementType& elem);

// 05_循环队列——扩容
Status incrementQueue_Cq(CQueue& cQ);

// 06_循环队列——队满
Status queueFull_Cq(CQueue cQ);

// 07_循环队列——队空
Status queueEmpty_Cq(CQueue cQ);