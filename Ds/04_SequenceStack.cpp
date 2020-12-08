#include "04_SequenceStack.h"

/* 测试顺序栈的方法*/
void testSequenceStack()
{
	SqStack sS;

	// 暂时注释，为了给二叉树非递归遍历用。
	//// 初始化
	//printf("Stack initializing: ...\n");
	//int initStatus = initStack_Sq(sS);
	//printf("init status: %d\n", initStatus);

	//// 入栈
	//printf("Pushing...\n");
	//push_Sq(sS, 5);
	//push_Sq(sS, 6);
	//push_Sq(sS, 7);
	//printf("Pushed.\n");

	//// 出栈测试
	//SqStackElemType top;
	//while (pop_Sq(sS, top))
	//{
	//	printf("Pop:\ttop = %d\n", top);
	//}
}

/* 01_顺序栈——初始化*/
Status initStack_Sq(SqStack& sS)
{
	sS.elem = (SqStackElemType*)malloc(STACK_INIT_SIZE * sizeof(SqStackElemType));
	if (!sS.elem)
	{
		return ERROR;
	}
	sS.top = -1;
	sS.stackSize = STACK_INIT_SIZE;
	sS.incrementSize = STACK_INCREMENT;
	return OK;
}

/* 02_顺序栈——取栈顶元素*/
Status getTop_Sq(SqStack sS, SqStackElemType& e)
{
	// 如果栈空，返回错误
	if (stackEmpty_Sq(sS))
	{
		return ERROR;
	}
	// 赋值
	e = *(sS.elem + sS.top);
	return OK;
}

/* 03_顺序栈——入栈*/
Status push_Sq(SqStack& sS, SqStackElemType e)
{
	// 达到栈大小，进行扩容
	if (sS.top + 1 == sS.stackSize)
	{
		// 扩容失败，返回失败
		if (!incrementStack_Sq(sS))
		{
			return ERROR;
		}
	}
	// 压入栈顶
	*(sS.elem + ++sS.top) = e;
	// 成功
	return OK;
}

/* 04_顺序栈——出栈*/
Status pop_Sq(SqStack& sS, SqStackElemType& e)
{
	// 如果栈为空，返回结果
	if (stackEmpty_Sq(sS))
	{
		return ERROR;
	}
	// 赋值并移动栈顶索引
	e = *(sS.elem + sS.top--);
	return OK;
}

/* 05_顺序栈——销毁*/
Status destroyStack_Sq(SqStack& sS)
{
	// 不存在，则标识已经销毁过了
	if (!sS.elem)
	{
		return ERROR;
	}
	// 删除指针
	delete sS.elem;
	// 结构定义字段置默认值
	sS.top = -1;
	sS.stackSize = 0;
	sS.incrementSize = 0;
	return OK;
}

/* 06_顺序栈——判断栈空*/
Status stackEmpty_Sq(SqStack sS)
{
	// 栈空条件即是栈顶索引为-1
	return sS.top == -1 ? OK : ERROR;
}

/*  07_顺序栈——清空栈*/
Status clearStack_Sq(SqStack& sS)
{
	// 只需要改变栈顶索引，因为对元素的存取都只对栈顶操作，其他位置的值无法读到
	sS.top = -1;
	return OK;
}

/* 08_顺序栈——扩容*/
Status incrementStack_Sq(SqStack& sS)
{
	SqStackElemType* newElem;
	// 进行扩容操作，当前容量加上增量
	newElem = (SqStackElemType*)realloc(sS.elem, (sS.stackSize + (size_t)sS.incrementSize) * sizeof(SqStackElemType));
	// 扩容失败，返回错误
	if (!sS.elem)
	{
		return ERROR;
	}
	sS.elem = newElem;
	// 扩容不要忘记修改容量
	sS.stackSize += sS.incrementSize;
	return OK;
}

/* 09_顺序栈——栈长度*/
int stackLength_Sq(SqStack sS)
{
	// 栈顶索引的长度+1 == 栈长度
	return sS.top + 1;
}
