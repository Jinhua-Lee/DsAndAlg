#include"02_SingleLinkedList.h"
/* ���Ե�����ķ���*/
void testSingleLinkedList()
{

}

/* 01_����������ʼ��������_��ͷ�ڵ�*/
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

/* 02_����������ʼ��������_��ͷ�ڵ�*/
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
