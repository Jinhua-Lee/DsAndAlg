#include "03_DoublyLinkedList.h"

/* ����˫��ѭ������ķ���*/
void testDoublyLinkedList()
{
	DuL duL;

	// ���Գ�ʼ��
	initList_DuL(duL);
	// ��ӡָ��
	printf("duL -> %p\n", duL);
	printf("prior -> %p\n", duL->prior);
	printf("next -> %p\n", duL->next);

	// ��������λ��ǰ����Ԫ�أ��˴����Ӧ���� 4 -> 6 -> 5
	insertByIndex_DuL(duL, 1, 4);
	insertByIndex_DuL(duL, 1, 5);
	insertByIndex_DuL(duL, 1, 6);
	traverseList_DuL(duL);

}

/* 01_˫��ѭ����������ʼ��_��ͷ���*/
Status initList_DuL(DuL& duL)
{
	duL = (DuL)malloc(sizeof(DuL_Node));
	if (!duL)
	{
		return ERROR;
	}
	duL->data = NULL;
	// ѭ��������ʼǰ�úͺ��ʱ��ָ���Լ�
	duL->prior = duL;
	duL->next = duL;
	return OK;
}

/* 02_˫��ѭ����������ָ������λ��ǰ����Ԫ��*/
Status insertByIndex_DuL(DuL& duL, int index, ElementType data)
{
	// ���壺����֮ǰ��Ԫ�ؽ��
	DuL beforeInsert = duL;
	// ���ҵ�������Ϊֵ��ǰ�ý��
	for (int i=0;i<index;i++)
	{
		// ���������������Ԫ�ظ�������ֱ�ӷ����
		if (beforeInsert->next != duL)
		{
			beforeInsert = beforeInsert->next;
		}
	}
	// �����ĺ�̽ڵ�
	DuL afterInsert = beforeInsert->next;
	// ����������
	DuL curInsert = (DuL)malloc(sizeof(DuL_Node));
	if (!curInsert)
	{
		return ERROR;
	}
	curInsert->data = data;

	// ��ǰ�ý�����
	beforeInsert->next = curInsert;
	curInsert->prior = beforeInsert;
	// ���̽�����
	curInsert->next = afterInsert;
	afterInsert->prior = curInsert;

	return OK;
}

/* 03_˫��ѭ���������������*/
void traverseList_DuL(DuL duL)
{
	DuL p = duL->next;
	while (p != duL)
	{
		visit(*p);
		p = p->next;
	}
}

/* 04_˫��ѭ���������������*/
void backTraverseList_DuL(DuL duL)
{
	DuL p = duL->prior;
	while (p != duL)
	{
		visit(*p);
		p = p->prior;
	}
}

/* 05_˫��ѭ������������*/
void visit(DuNode duNode)
{
	printf("duNode data -> %d\n", duNode.data);
}
