#include "01_SequenceList.h"

/* 01_顺序表——创建空表：没有元素，长度为0，默认容量和增量*/
Status createList_Sq(SqList& sL, int initSize = LIST_INIT_SIZE, int incrementSize = LIST_INCREMENT)
{
	// 开辟顺序表存储空间
	sL.elem = (SqListElemType*)malloc(initSize * sizeof(SqListElemType));
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
Status initList_Sq(SqList& sL, SqListElemType* elems, int targetLength)
{
	int srcLength = sL.length;
	SqListElemType* newElem;
	// 若空间不足，则分配空间
	if (srcLength + targetLength > sL.listSize)
	{
		// 分配大小刚好为填入后总长度 +增量
		newElem = (SqListElemType*)realloc(sL.elem, (srcLength + (size_t)targetLength + LIST_INCREMENT) * sizeof(SqListElemType));
		// 分配成功，设置顺序表容量
		if (newElem)
		{
			sL.listSize = sL.length + targetLength + LIST_INCREMENT;
			sL.elem = newElem;
		}
		// 分配失败返回错误
		else
		{
			return ERROR;
		}
	}
	// 将元素加到顺序表尾部
	for (int i = srcLength; i < srcLength + targetLength; i++)
	{
		sL.elem[i] = elems[i - srcLength];
		sL.length++;
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
void visit(SqListElemType elem)
{
	printf("%-4d ", elem);
}

/* 比较元素*/
int compareElem(SqListElemType a, SqListElemType b)
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

/* 04_顺序表——查找元素：并且返回第一个匹配到的元素索引*/
int locateElem_Sq(SqList& sL, SqListElemType elem)
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
Status insertElem_Sq(SqList& sL, int index, SqListElemType elem)
{
	// 索引不合法
	if (index < 0)
	{
		return ERROR;
	}
	// 是否进行扩容
	if (sL.length + 1 >= sL.listSize)
	{
		sL.elem = (SqListElemType*)malloc((sL.listSize + (size_t)sL.incrementSize) * sizeof(SqListElemType));
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
		for (SqListElemType* p = sL.elem + sL.length + 1; p >= sL.elem + index; p--)
		{
			*(p + 1) = *p;
		}
		//sL.elem[index] = elem;
		*(sL.elem + index) = elem;
	}
	// 不要忘记长度
	++sL.length;

	return OK;
}

/* 06_顺序表——清空*/
Status clearList_Sq(SqList& sL)
{
	// 先清空数组中的值
	delete[] sL.elem;
	// 重新分配
	sL.elem = (SqListElemType*)malloc(LIST_INIT_SIZE * sizeof(SqListElemType));
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

/*  08_顺序表——删除：删除指定索引的元素*/
SqListElemType deleteElem_Sq(SqList& sL, int index)
{
	// 如果不在元素索引范围内
	if (index < 0 || index >= sL.length)
	{
		return -1;
	}
	
	SqListElemType toDelete = *(sL.elem + index);
	// 数组方式
	/*for (int i = index; i < sL.length - 1; i++)
	{
		sL.elem[i] = sL.elem[i + 1];
	}*/
	// 指针方式
	SqListElemType* p = sL.elem + index;
	SqListElemType* q = sL.elem + sL.length - 1;
	while (p < q)
	{
		*p = *(p + 1);
		p++;
	}
	// 别忘记长度减一
	sL.length--;
	return toDelete;
}

/* 09_顺序表——合并：向A中加入B中特有的元素，最后删除B*/
Status purgeList_Sq(SqList& sLa, SqList& sLb)
{
	SqListElemType bElem;
	// 每次从B中取出该元素在A中定位，如果没找到，则插入
	while (sLb.length > 0)
	{
		bElem = deleteElem_Sq(sLb, 0);
		printf("表B删除了：%d\n", bElem);
		// 表A中如果找不到该元素，则加入该元素
		if (locateElem_Sq(sLa, bElem) == -1)
		{
			insertElem_Sq(sLa, sLa.length, bElem);
			printf("表A加入了：%d\n", bElem);
		}
	}
	// 最后销毁B
	destroyList_Sq(sLb);
	return OK;
}

// 顺序表测试类
void testSqList()
{
	SqList sLa;

	int aLength = 200;
	// 批量初始化元素
	SqListElemType* elems = new SqListElemType[aLength];
	for (int i = 0; i < aLength; i++)
	{
		elems[i] = i * 2;
	}

	// 创建空链表A并初始化
	createList_Sq(sLa, LIST_INIT_SIZE, LIST_INCREMENT);
	initList_Sq(sLa, elems, aLength);
	// 遍历元素
	traverseList_Sq(sLa);

	// 查找元素
	int aLocation = locateElem_Sq(sLa, 126);
	int bLocation = locateElem_Sq(sLa, 125);
	printf("\naLocation = %-2d\tbLocation = %-2d\n", aLocation, bLocation);

	// 插入元素
	insertElem_Sq(sLa, 2, -234);
	traverseList_Sq(sLa);

	printf("\n删除指定索引元素后：\n");
	// 删除指定索引元素
	SqListElemType toDelete = deleteElem_Sq(sLa, 5);
	traverseList_Sq(sLa);
	printf("\n被删除元素为：%d\n", toDelete);

	printf("\n=====================================\n");

	// 第二个顺序表加入
	SqList sLb;
	int bLength = 20;
	SqListElemType* elems2 = new SqListElemType[bLength];
	for (int i = 0; i < bLength; i++)
	{
		elems2[i] = -i;
	}
	createList_Sq(sLb, LIST_INIT_SIZE, LIST_INCREMENT);
	initList_Sq(sLb, elems2, bLength);

	printf("\nB 的长度：%d\n", sLb.length);

	traverseList_Sq(sLb);
	// 合并A和B，遍历
	purgeList_Sq(sLa, sLb);
	printf("\n遍历合并后的A：\n");
	traverseList_Sq(sLa);

}
