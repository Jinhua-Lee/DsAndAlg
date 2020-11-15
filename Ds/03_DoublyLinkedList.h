#include<stdio.h>
#include<stdlib.h>

// 定义返回状态及返回码
#define Status int
#define OK 1
#define ERROR 0
// 定义存储的元素类型
#define ElementType int

/* 双向链循环表存储结点*/
typedef struct DuL_Node
{
	// 指向前驱节点指针
	DuL_Node* prior;
	// 存储元素
	ElementType data;
	// 指向后继节点指针
	DuL_Node* next;
}DuNode, *DuL;

// 测试双向循环链表的方法
void testDoublyLinkedList();

// 01_双向循环链表——初始化_带头结点
Status initList_DuL(DuL& duL);

// 02_双向循环链表——在指定索引位置前插入元素
Status insertByIndex_DuL(DuL& duL, int index, ElementType data);

// 03_双向循环链表——正序遍历
void traverseList_DuL(DuL duL);

// 04_双向循环链表——反向遍历
void backTraverseList_DuL(DuL duL);

// 05_双向循环链表——访问
void visit(DuNode duNode);