#include"02_SingleLinkedList.h"
/* 测试单链表的方法*/
void testSingleLinkedList()
{

}

/* 01_单链表——初始化单链表_带头节点*/
SL_Node* initList_SL(SL_Node& hNode)
{
	SL_Node* p = &hNode;
	p = (SL_Node*)malloc(sizeof(SL_Node));
	if (!p)
	{
		return NULL;
	}
	p->next = NULL;
	return p;
}

/* 02_单链表——初始化单链表_无头节点*/
SL_Node* initList_SL2(SL_Node* pNode)
{
	pNode = (SL_Node*)malloc(sizeof(SL_Node));
	if (!pNode)
	{
		return NULL;
	}
	pNode->next = NULL;
	return pNode;
}
