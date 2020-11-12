#include"02_SingleLinkedList.h"
/* ���Ե�����ķ���*/
void testSingleLinkedList()
{
	// ������ͷ����ָ��
	SL_Node* hNode = initList_SLh();
	// ��������ͷ����ָ��
	SL_Node* SL = initList_SL();
}

/* 01_����������ʼ��������_��ͷ���*/
SL_Node* initList_SLh()
{
	// ָ��ͷ�ڵ��ָ��
	SL_Node* hNode = (SL_Node*)malloc(sizeof(SL_Node));
	if (!hNode)
	{
		return NULL;
	}
	hNode->next = NULL;
	return hNode;
}

/* 02_����������ʼ��������_��ͷ���*/
SL_Node* initList_SL()
{
	SL_Node* SL = NULL;
	return SL;
}

/* 03_����������������_��ͷ���*/
int listLength_SLh(hNode hNode)
{
	// ��ʼ��������
	int length = 0;
	// ָ��ͷ���ı���
	SL_Node* p = hNode.next;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

/* 04_����������������_��ͷ���*/
int listLength_SL(SL sL)
{
	int length = 0;
	// ��ͷָ�뿪ʼ����
	SL_Node* p = sL;
	while (sL)
	{
		length++;
		p = p->next;
	}
	return length;
}

/* 05_�����������ٵ�����_��ͷ�ڵ�*/
void destroy_SLh(hNode& hNode)
{
	// ����pָ�룬ָ��ͷ�ڵ��Ĵ�ɾ�����
	SL_Node* p;
	// ��ǰ���ڴ�ɾ�����
	while (hNode.next)
	{
		// ָ���ɾ�����
		p = hNode.next;
		// ͷ������ӵ���̽��
		hNode.next = p->next;
		// ���е�ǰ����ɾ��
		p->elem = NULL;
		p->next = NULL;
		free(p);
	}
}

/* 06_�����������ٵ�����_��ͷ�ڵ�*/
void destroy_SL(SL& sL)
{
	// ָ��p��ָ��ǰ��ɾ�����
	SL p;
	while (sL)
	{
		// ÿ����ָ���ɾ�����
		p = sL;
		// ͷָ��ָ���̽ڵ�
		if (p->next)
		{
			sL = p->next;
		}
		// ����ɾ������
		p->elem = NULL;
		p->next = NULL;
		free(p);
	}
}

/* 07_��������β�巨����������_��ͷ�ڵ�*/
SL_Node* tailInsert_SLh(hNode& hNode)
{
	return NULL;
}

/* 08_��������β�巨����������_����ͷ�ڵ�*/
SL_Node* tailInsert_SL(SL& sL)
{
	return NULL;
}

/* 09_��������ͷ�巨����������_��ͷ���*/
SL_Node* headInsert_SLh(hNode& hNode)
{
	return NULL;
}

/* 10_��������ͷ�巨����������_����ͷ���*/
SL_Node* headInsert_SL(SL& sL)
{
	return NULL;
}
