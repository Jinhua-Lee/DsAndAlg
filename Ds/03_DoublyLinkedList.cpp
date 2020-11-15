#include "03_DoublyLinkedList.h"

/* 测试双向循环链表的方法*/
void testDoublyLinkedList()
{
	DuL duL;

	// 测试初始化
	initList_DuL(duL);
	// 打印指针
	printf("duL -> %p\n", duL);
	printf("prior -> %p\n", duL->prior);
	printf("next -> %p\n", duL->next);

	// 测试索引位置前插入元素：此处结果应该是 4 -> 6 -> 5
	insertByIndex_DuL(duL, 1, 4);
	insertByIndex_DuL(duL, 1, 5);
	insertByIndex_DuL(duL, 1, 6);
	traverseList_DuL(duL);

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
Status insertByIndex_DuL(DuL& duL, int index, ElementType data)
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
	// 插入后的后继节点
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
