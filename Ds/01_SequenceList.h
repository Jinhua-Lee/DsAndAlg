#pragma once
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
#define SqListElemType int

// 顺序表的存储结构定义
typedef struct
{
	// 线性表存储空间地址
	SqListElemType* elem;

	// 线性表当前存放元素的个数
	int length;

	// 当前线性表的容量
	int listSize;

	// 约定每次扩容的增量
	int incrementSize;
}SqList;

// 01_顺序表——创建空表：没有元素，长度为0，默认容量和增量
Status createList_Sq(SqList& sL, int initSize, int incrementSize);
// 02_顺序表——初始化：向顺序表的末尾加入数组的所有元素
Status initList_Sq(SqList& sL, SqListElemType* elems, int targetLength);
// 03_顺序表——遍历
void traverseList_Sq(SqList& sL);
// 访问顺序表元素
void visit(SqListElemType elem);
// 比较元素
int compareElem(SqListElemType a, SqListElemType b);
// 04_顺序表——查找元素：并且返回第一个匹配到的元素索引
int locateElem_Sq(SqList& sL, SqListElemType elem);
// 05_顺序表——插入元素：在指定索引 index 之前插入一个元素
Status insertElem_Sq(SqList& sL, int index, SqListElemType elem);
// 06_顺序表——清空
Status clearList_Sq(SqList& sL);
// 07_顺序表——销毁
Status destroyList_Sq(SqList& sL);
// 08_顺序表——删除：删除指定索引的元素，返回被删除的元素值
SqListElemType deleteElem_Sq(SqList& sL, int index);
// 09_顺序表——合并：向A中加入B中特有的元素，最后删除B
Status purgeList_Sq(SqList& sLa, SqList& sLb);

// 测试方法
void testSqList();