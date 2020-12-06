#pragma once
#include <stdio.h>
#include <stdlib.h>

// 定义返回状态及返回码
#define Status int
#define OK 1
#define ERROR 0
// 定义存储的元素类型
#define LinkedListElementType int

/* 定义单链表结点*/
typedef struct SL_Node
{
	// 存储的元素
	LinkedListElementType data;
	// 指向下一个结点的指针
	SL_Node* next;
}HNode, *SL;

// 测试单链表的方法
void testSingleLinkedList();

// 带头结点的测试方法
void testWithHead(LinkedListElementType* datas, int length);

// 不带头结点的测试方法
void testWithoutHead(LinkedListElementType* datas, int length);

// 测试两个链表合并的方法
void testMerge();

// 将两个递增序列链表合并为一个递减序列的链表
SL mergeTwoList(SL headA, SL headB);

// 01_单链表——初始化_带头结点
Status initList_SLh(SL& head);

// 02_单链表——初始化_无头结点
Status initList_SL(SL& sL);

// 03_单链表——长度_带头结点
int listLength_SLh(SL head);

// 04_单链表——长度_无头结点
int listLength_SL(SL sL);

// 05_单链表——销毁_带头结点
void destroy_SLh(SL& head);

// 06_单链表——销毁_无头结点
void destroy_SL(SL& sL);

// 07_单链表——尾插法建立_带头结点
Status tailInsert_SLh(SL& head, LinkedListElementType* datas, int length);

// 08_单链表——尾插法建立_不带头结点
Status tailInsert_SL(SL& sL, LinkedListElementType* datas, int length);

// 09_单链表——头插法建立_带头结点
Status headInsert_SLh(SL& head, LinkedListElementType* datas, int length);

// 10_单链表——头插法建立_不带头结点
Status headInsert_SL(SL& sL, LinkedListElementType* datas, int length);

// 11_单链表——遍历_带头结点
void traveseList_SLh(SL head);

// 12_单链表——遍历_不带头结点
void traverseList_SL(SL sL);

// 13_单链表——访问方法
void visit(HNode hnode);

// 14_单链表——删除结点_带头结点
void deleteElem_SLh(SL& head, LinkedListElementType data);

// 15_单链表——删除结点_不带头结点
void deleteElem_SL(SL& sL, LinkedListElementType data);

// 16_单链表——原地逆置_带头结点
void invertList_SLh(SL& head);

// 17_单链表——原地逆置_不带头结点
void invertList_SL(SL& sL);

// 18_单链表——初始化_带头结点2
Status initList_SLh2(HNode** hNode);