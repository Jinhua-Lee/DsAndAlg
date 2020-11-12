#include"02_SingleLinkedList.h"
/* 测试单链表的方法*/
void testSingleLinkedList()
{
	// 创建带头结点的指针
	SL_Node* hNode = initList_SLh();
	// 创建不带头结点的指针
	SL_Node* SL = initList_SL();
}

/* 01_单链表——初始化单链表_带头结点*/
SL_Node* initList_SLh()
{
	// 指向头节点的指针
	SL_Node* hNode = (SL_Node*)malloc(sizeof(SL_Node));
	if (!hNode)
	{
		return NULL;
	}
	hNode->next = NULL;
	return hNode;
}

/* 02_单链表——初始化单链表_无头结点*/
SL_Node* initList_SL()
{
	SL_Node* SL = NULL;
	return SL;
}

/* 03_单链表——求单链表长度_带头结点*/
int listLength_SLh(hNode hNode)
{
	// 初始迭代长度
	int length = 0;
	// 指向头结点的变量
	SL_Node* p = hNode.next;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

/* 04_单链表——求单链表长度_无头结点*/
int listLength_SL(SL sL)
{
	int length = 0;
	// 从头指针开始迭代
	SL_Node* p = sL;
	while (sL)
	{
		length++;
		p = p->next;
	}
	return length;
}

/* 05_单链表——销毁单链表_带头节点*/
void destroy_SLh(hNode& hNode)
{
	// 定义p指针，指向头节点后的待删除结点
	SL_Node* p;
	// 当前存在待删除结点
	while (hNode.next)
	{
		// 指向待删除结点
		p = hNode.next;
		// 头结点连接到后继结点
		hNode.next = p->next;
		// 进行当前结点的删除
		p->elem = NULL;
		p->next = NULL;
		free(p);
	}
}

/* 06_单链表——销毁单链表_无头节点*/
void destroy_SL(SL& sL)
{
	// 指针p，指向当前待删除结点
	SL p;
	while (sL)
	{
		// 每次先指向待删除结点
		p = sL;
		// 头指针指向后继节点
		if (p->next)
		{
			sL = p->next;
		}
		// 进行删除操作
		p->elem = NULL;
		p->next = NULL;
		free(p);
	}
}

/* 07_单链表——尾插法建立单链表_带头节点*/
SL_Node* tailInsert_SLh(hNode& hNode)
{
	return NULL;
}

/* 08_单链表——尾插法建立单链表_不带头节点*/
SL_Node* tailInsert_SL(SL& sL)
{
	return NULL;
}

/* 09_单链表——头插法建立单链表_带头结点*/
SL_Node* headInsert_SLh(hNode& hNode)
{
	return NULL;
}

/* 10_单链表——头插法建立单链表_不带头结点*/
SL_Node* headInsert_SL(SL& sL)
{
	return NULL;
}
