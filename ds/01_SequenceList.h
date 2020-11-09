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

// 顺序表的存储结构定义
typedef struct
{
	// 线性表存储空间地址
	ElementType* elem;

	// 线性表当前存放元素的个数
	int length;

	// 当前线性表的容量
	int listSize;

	// 约定每次扩容的增量
	int incrementSize;
}SqList;

// 创建一个空的顺序表
Status createList_Sq(SqList& sL, int initSize, int incrementSize);
// 向顺序表的末尾加入数组的所有元素
Status initList_Sq(SqList& sL, ElementType* elems, int targetLength);
// 遍历顺序表
void traverseList_Sq(SqList& sL);
// 访问顺序表元素
void visit(ElementType elem);
// 比较元素
int compareElem(ElementType a, ElementType b);
// 查找元素，并且返回第一个匹配到的元素
int locateElem_Sq(SqList& sL, ElementType elem);