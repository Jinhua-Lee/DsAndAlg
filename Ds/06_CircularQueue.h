#include <stdio.h>
#include <stdlib.h>

// 定义初始大小和增量
#define LIST_INIT_SIZE 150
#define LIST_INCREMENT 20
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
	int length;

	// 队头的索引
	int front;

	// 队尾索引
	int rear;

	// 队列容量
	int queueSize;
}CQueue, *Q;

// 01_循环队列——初始化