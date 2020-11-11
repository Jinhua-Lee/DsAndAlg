#pragma once
#include<stdio.h>
#include<stdlib.h>

// 定义返回状态及返回码
#define Status int
#define OK 1
#define ERROR 0
// 定义存储的元素类型
#define ElementType int

/* 定义单链表节点*/
typedef struct SL_Node
{
	// 存储的元素
	ElementType elem;
	// 指向下一个节点的指针
	SL_Node* next;
}hNode, *pNode;

// 测试单链表的方法
void testSingleLinkedList();

// 01_单链表——初始化单链表_带头节点
SL_Node* initList_SL(SL_Node& hNode);
// 02_单链表——初始化单链表_无头节点
SL_Node* initList_SL2(SL_Node* pNode);
// 03_单链表——头插法建立单链表
SL_Node* headInsert_SL(SL_Node* pNode);
// 04_单链表——尾插法建立单链表
SL_Node* tailInsert_SL(SL_Node* pNode);
// 05_单链表——求单链表的长度
int length_SL(SL_Node* pNode);