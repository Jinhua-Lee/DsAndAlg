#include<stdio.h>
#include<stdlib.h>

// 定义返回状态及返回码
#define Status int
#define OK 1
#define ERROR 0
// 定义存储的元素类型
#define ElementType int

/* 定义单链表结点*/
typedef struct SL_Node
{
	// 存储的元素
	ElementType elem;
	// 指向下一个结点的指针
	SL_Node* next;
}hNode, *SL;

// 测试单链表的方法
void testSingleLinkedList();

// 01_单链表——初始化单链表_带头结点
SL_Node* initList_SLh();
// 02_单链表——初始化单链表_无头结点
SL_Node* initList_SL();
// 03_单链表——求单链表长度_带头结点
int listLength_SLh(hNode hNode);
// 04_单链表——求单链表长度_无头结点
int listLength_SL(SL sL);
// 05_单链表——销毁单链表_带头节点
void destroy_SLh(hNode& hNode);
// 06_单链表——销毁单链表_无头节点
void destroy_SL(SL& sL);
// 07_单链表——尾插法建立单链表_带头节点
SL_Node* tailInsert_SLh(hNode& hNode);
// 08_单链表——尾插法建立单链表_不带头节点
SL_Node* tailInsert_SL(SL& sL);
// 09_单链表——头插法建立单链表_带头结点
SL_Node* headInsert_SLh(hNode& hNode);
// 10_单链表——头插法建立单链表_不带头结点
SL_Node* headInsert_SL(SL& sL);