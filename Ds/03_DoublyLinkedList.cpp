#include "03_DoublyLinkedList.h"

/* 测试双向循环链表的方法*/
void testDoublyLinkedList()
{
	int length;
	printf("请输入链表长度：\n");
	scanf_s("%d", &length);
	DuLinkedListElementType* datas = new DuLinkedListElementType[length];
	printf("请输入链表的 %d 个元素：\n", length);
	for (int i = 0; i < length; i++)
	{
		scanf_s("%d", datas + i);
	}

	DuL duL;

	// 测试初始化
	initList_DuL(duL);
	printf("\n=====初始化方法测试=====\n");
	printf("duL -> %p\n", duL);
	printf("prior -> %p\n", duL->prior);
	printf("next -> %p\n", duL->next);

	// 测试索引位置前插入元素：此处结果应该是 0 -> 1 -> 2
	insertByIndex_DuL(duL, 1, 0);
	insertByIndex_DuL(duL, 1, 2);
	insertByIndex_DuL(duL, 1, 1);
	printf("\n=====指定索引前插入=====\n");
	traverseList_DuL(duL);

	// 测试在表尾批量插入元素的方法
	batchInsertToTail_DuL(duL, datas, length);
	printf("\n=====表尾批量插入=====\n");
	traverseList_DuL(duL);

	// 测试按索引删除元素的方法
	DuLinkedListElementType data = deleteByIndex_DuL(duL, 1);
	printf("\n=====按索引删除元素=====\n");
	traverseList_DuL(duL);
	printf("\n删除的元素为：%d\n", data);

}

/* 01_双向循环链表——初始化_带头结点*/
Status initList_DuL(DuL& duL)
{
	duL = (DuL)malloc(sizeof(DuL_Node));
	if (!duL)
	{
		return ERROR;
	}
	duL->data = NULL;
	// 循环链表，初始前置和后继时候指向自己
	duL->prior = duL;
	duL->next = duL;
	return OK;
}

/* 02_双向循环链表——在指定索引位置前插入元素*/
Status insertByIndex_DuL(DuL& duL, int index, DuLinkedListElementType data)
{
	// 定义：插入之前的元素结点
	DuL beforeInsert = duL;
	// 先找到待插入为值的前置结点
	for (int i=0;i<index;i++)
	{
		// 如果索引大于链表元素个数，则直接放最后
		if (beforeInsert->next != duL)
		{
			beforeInsert = beforeInsert->next;
		}
	}
	// 插入后的后继结点
	DuL afterInsert = beforeInsert->next;
	// 建立插入结点
	DuL curInsert = (DuL)malloc(sizeof(DuL_Node));
	if (!curInsert)
	{
		return ERROR;
	}
	curInsert->data = data;

	// 与前置结点关联
	beforeInsert->next = curInsert;
	curInsert->prior = beforeInsert;
	// 与后继结点关联
	curInsert->next = afterInsert;
	afterInsert->prior = curInsert;

	return OK;
}

/* 03_双向循环链表——正序遍历*/
void traverseList_DuL(DuL duL)
{
	DuL p = duL->next;
	while (p != duL)
	{
		visit(*p);
		p = p->next;
	}
}

/* 04_双向循环链表——反向遍历*/
void backTraverseList_DuL(DuL duL)
{
	DuL p = duL->prior;
	while (p != duL)
	{
		visit(*p);
		p = p->prior;
	}
}

/* 05_双向循环链表——访问*/
void visit(DuNode duNode)
{
	printf("duNode data -> %d\n", duNode.data);
}

/* 06_双向循环链表——批量插入数据到表尾*/
Status batchInsertToTail_DuL(DuL& duL, DuLinkedListElementType* datas, int length)
{
	// 待插入的位置
	DuL tail = duL->prior;
	// 待插入的结点迭代
	DuL cur = NULL;
	for (int i = 0; i < length; i++)
	{
		// 每次创建一个结点
		cur = (DuL)malloc(sizeof(DuNode));
		// 插入失败则返回错误
		if (!cur)
		{
			return ERROR;
		}
		cur->data = *(datas + i);
		// 连接前置结点
		tail->next = cur;
		cur->prior = tail;
		// 连接后继结点
		cur->next = duL;
		duL->prior = cur;
		// 下一个
		tail = cur;
	}
	return OK;
}

/* 07_双向循环链表——删除指定索引的元素*/
DuLinkedListElementType deleteByIndex_DuL(DuL& duL, int index)
{
	DuLinkedListElementType data;
	DuL cur = duL->next;
	// 直接找到该结点，不用找前置
	for (int i = 0; i < index; i++)
	{
		if (cur->next == duL)
		{
			return NULL;
		}
		cur = cur->next;
	}
	// 保存返回值
	data = cur->data;
	// 将前置结点和后继结点连接起来
	cur->prior->next = cur->next;
	cur->next->prior = cur->prior;
	// 释放空间
	free(cur);
	return data;
}
