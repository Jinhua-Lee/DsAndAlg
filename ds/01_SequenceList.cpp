#include"01_SequenceList.h"

/*创建一个空的顺序表*/
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

/*初始化一个空的顺序表，将元素加入到顺序表末尾*/
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
			sL.listSize = srcLength + targetLength + LIST_INCREMENT;
		}
		// 分配失败返回错误
		else
		{
			return ERROR;
		}
	}
	// 将元素加到顺序表尾部
	for (int i = srcLength; i < sL.length + targetLength; i++)
	{
		sL.elem[i] = elems[i - srcLength];
	}
	return OK;
}

/*遍历顺序表的元素*/
void traverseList_Sq(SqList& sL)
{
	for (int i = 0; i < sL.length; i++)
	{
		visit(sL.elem[i]);
	}
}

/*访问元素*/
void visit(ElementType elem)
{
	printf("%-4d ", elem);
}

/*比较元素*/
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

/*查找元素，并且返回第一个匹配到的元素*/
int locateElem_Sq(SqList& sL, ElementType elem)
{
	// 拿到顺序表的指针
	int* p = sL.elem;
	// 找到返回位置索引
	for (int i = 0; i < sL.length; i++)
	{
		if (compareElem(elem, p[i]))
		{
			return i;
		}
	}
	// 找不到返回 -1
	return -1;
}