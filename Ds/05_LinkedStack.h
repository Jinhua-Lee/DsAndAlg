#include <stdio.h>
#include <stdlib.h>
#include "02_SingleLinkedList.h"

// 定义返回状态及返回码
#define Status int
#define OK 1
#define ERROR 0
// 定义存储的元素类型
#define LinkedStackElementType int

// 采用单链表的结点定义，由于操作简单，所以不带头结点即可
// 定义指向该单链栈结点的指针类型
typedef SL_Node S_Node, *LS;

// 测试单链栈的方法
void testLinkedStack();

// 01_单链栈——初始化
Status initStack_LS(LS& Ls);

// 02_单链栈——取栈顶
Status getTop_LS(LS& Ls, LinkedStackElementType& elem);

// 03_单链栈——入栈
Status push_LS(LS& Ls, LinkedStackElementType elem);

// 04_单链栈——出栈
Status pop_LS(LS& Ls, LinkedStackElementType& elem);

// 05_单链栈——栈长度
int stackLength_LS(LS Ls);

// 06_单链栈——判空
Status stackEmpty_LS(LS Ls);

// 07_单链栈——清空
Status clearStack_LS(LS& Ls);