#include"01_SequenceList.h"

/* 01_顺序表——创建空表：没有元素，长度为0，默认容量和增量*/
Status createList_Sq(SqList& sL, int initSize = LIST_INIT_SIZE, int incrementSize = LIST_INCREMENT)
{
	// 开辟顺序表存储空间
	sL.elem = (ElementType*)malloc(initSize * sizeof(ElementType));
	// 创建失败，返回错误码
	if (!sL.elem)
	{
		return ERROR;
	}
	sL.length = 0;
	sL.listSize = initSize;
	sL.incrementSize = incrementSize;
	return OK;
}

/* 02_顺序表——初始化：向顺序表的末尾加入数组的所有元素*/
Status initList_Sq(SqList& sL, ElementType* elems, int targetLength)
{
	int srcLength = sL.length;
	// 若空间不足，则分配空间
	if (srcLength + targetLength > sL.listSize)
	{
		// 分配大小刚好为填入后总长度 +增量
		sL.elem = (ElementType*)malloc((srcLength + (size_t)targetLength + LIST_INCREMENT) * sizeof(ElementType));
		// 分配成功，设置顺序表容量
		if (sL.elem)
		{
			sL.length = srcLength + targetLength;
			sL.listSize = sL.length + LIST_INCREMENT;
		}
		// 分配失败返回错误
		else
		{
			return ERROR;
		}
	}
	// 将元素加到顺序表尾部
	for (int i = srcLength; i < sL.length; i++)
	{
		sL.elem[i] = elems[i - srcLength];
	}
	return OK;
}

/* 03_顺序表——遍历*/
void traverseList_Sq(SqList& sL)
{
	for (int i = 0; i < sL.length; i++)
	{
		visit(sL.elem[i]);
	}
}

/* 访问元素*/
void visit(ElementType elem)
{
	printf("%-4d ", elem);
}

/* 比较元素*/
int compareElem(ElementType a, ElementType b)
{
	// 相等返回1，不相等返回0
	if (a == b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* 04_顺序表——查找元素：并且返回第一个匹配到的元素*/
int locateElem_Sq(SqList& sL, ElementType elem)
{
	// 拿到顺序表的指针
	int* p = sL.elem;
	// 找到返回位置索引
	for (int i = 0; i < sL.length; i++)
	{
		if (compareElem(elem, *(p + i)))
		{
			return i;
		}
	}
	// 找不到返回 -1
	return -1;
}
/* 05_顺序表——插入元素：在指定索引 index 之前插入一个元素*/
Status insertElem_Sq(SqList& sL, int index, ElementType elem)
{
	// 索引不合法
	if (index < 0)
	{
		return ERROR;
	}
	// 是否进行扩容
	if (sL.length + 1 >= sL.listSize)
	{
		sL.elem = (ElementType*)malloc((sL.listSize + (size_t)sL.incrementSize) * sizeof(ElementType));
		// 扩容失败
		if (!sL.elem)
		{
			return ERROR;
		}
		sL.listSize += sL.incrementSize;
	}
	// 在末尾添加
	if (index >= sL.length)
	{
		//sL.elem[sL.length] = elem;
		*(sL.elem + sL.length) = elem;
	}
	else
	{
		// 插入前从后往前移动元素，注意索引取值
		/*for (int i = sL.length - 1; i >= index; i--)
		{
			sL.elem[i + 1] = sL.elem[i];
		}*/
		for (ElementType* p = sL.elem + sL.length + 1; p >= sL.elem + index; p--)
		{
			*(p + 1) = *p;
		}
		//sL.elem[index] = elem;
		*(sL.elem + index) = elem;
	}
	// 不要忘记长度
	sL.length++;

	return OK;
}
/* 06_顺序表——清空*/
Status clearList_Sq(SqList& sL)
{
	// 先清空数组中的值
	delete[] sL.elem;
	// 重新分配
	sL.elem = (ElementType*)malloc(LIST_INIT_SIZE * sizeof(ElementType));
	if (!sL.elem)
	{
		return ERROR;
	}
	// 其余长度置为初始
	sL.length = 0;
	sL.listSize = LIST_INIT_SIZE;
	sL.incrementSize = LIST_INCREMENT;
	return OK;
}
/* 07_顺序表——销毁*/
Status destroyList_Sq(SqList& sL)
{
	// 回收数组空间
	delete[] sL.elem;
	//free(sL.elem);
	// 其余控制元素置为0
	sL.length = 0;
	sL.listSize = 0;
	sL.incrementSize = 0;
	return OK;
}

// 顺序表测试类
void testSqList()
{
	SqList sqList;
	// 创建空链表
	createList_Sq(sqList, LIST_INIT_SIZE, LIST_INCREMENT);
	int length = 200;
	// 批量初始化元素
	ElementType* elems = new ElementType[200];
	for (int i = 0; i < length; i++)
	{
		elems[i] = i * 2;
	}
	initList_Sq(sqList, elems, length);

	// 遍历元素
	traverseList_Sq(sqList);
	// 查找元素
	int aLocation = locateElem_Sq(sqList, 126);
	int bLocation = locateElem_Sq(sqList, 125);
	printf("\naLocation = %-2d\t", aLocation);
	printf("bLocation = %-2d\n", bLocation);
	// 插入元素
	insertElem_Sq(sqList, 2, -234);
	traverseList_Sq(sqList);
}
