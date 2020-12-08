#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "08_LinkedBinaryTree.h"

// 定义初始大小和增量
#define STACK_INIT_SIZE 150
#define STACK_INCREMENT 20
// 定义返回状态及返回码
#define Status int
#define OK 1
#define ERROR 0
// 定义存储的元素类型
#define SqStackElemType BinaryTree

// 顺序栈的结构定义
typedef struct SqStack
{
	// 存储元素的数组
	SqStackElemType* elem;
	// 栈顶元素的索引（这里称为栈顶指针）
	int top;
	// 栈容量
	int stackSize;
	// 每次扩容的大小
	int incrementSize;
}SqStack;

// 测试顺序栈的方法
void testSequenceStack();

// 01_顺序栈——初始化
Status initStack_Sq(SqStack& sS);

// 02_顺序栈——取栈顶元素
Status getTop_Sq(SqStack sS, SqStackElemType& e);

// 03_顺序栈——入栈
Status push_Sq(SqStack& sS, SqStackElemType e);

// 04_顺序栈——出栈
Status pop_Sq(SqStack& sS, SqStackElemType& e);

// 05_顺序栈——销毁
Status destroyStack_Sq(SqStack& sS);

// 06_顺序栈——判断栈空
Status stackEmpty_Sq(SqStack sS);

// 07_顺序栈——清空栈
Status clearStack_Sq(SqStack& sS);

// 08_顺序栈——扩容
Status incrementStack_Sq(SqStack& sS);

// 09_顺序栈——栈长度
int stackLength_Sq(SqStack sS);