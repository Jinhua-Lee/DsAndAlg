#include "03_DoublyLinkedList.h"

/* ����˫��ѭ������ķ���*/
void testDoublyLinkedList()
{
	int length;
	printf("�����������ȣ�\n");
	scanf_s("%d", &length);
	DuLinkedListElementType* datas = new DuLinkedListElementType[length];
	printf("����������� %d ��Ԫ�أ�\n", length);
	for (int i = 0; i < length; i++)
	{
		scanf_s("%d", datas + i);
	}

	DuL duL;

	// ���Գ�ʼ��
	initList_DuL(duL);
	printf("\n=====��ʼ����������=====\n");
	printf("duL -> %p\n", duL);
	printf("prior -> %p\n", duL->prior);
	printf("next -> %p\n", duL->next);

	// ��������λ��ǰ����Ԫ�أ��˴����Ӧ���� 0 -> 1 -> 2
	insertByIndex_DuL(duL, 1, 0);
	insertByIndex_DuL(duL, 1, 2);
	insertByIndex_DuL(duL, 1, 1);
	printf("\n=====ָ������ǰ����=====\n");
	traverseList_DuL(duL);

	// �����ڱ�β��������Ԫ�صķ���
	batchInsertToTail_DuL(duL, datas, length);
	printf("\n=====��β��������=====\n");
	traverseList_DuL(duL);

	// ���԰�����ɾ��Ԫ�صķ���
	DuLinkedListElementType data = deleteByIndex_DuL(duL, 1);
	printf("\n=====������ɾ��Ԫ��=====\n");
	traverseList_DuL(duL);
	printf("\nɾ����Ԫ��Ϊ��%d\n", data);

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
Status insertByIndex_DuL(DuL& duL, int index, DuLinkedListElementType data)
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
	// �����ĺ�̽��
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

/* 06_˫��ѭ�������������������ݵ���β*/
Status batchInsertToTail_DuL(DuL& duL, DuLinkedListElementType* datas, int length)
{
	// �������λ��
	DuL tail = duL->prior;
	// ������Ľ�����
	DuL cur = NULL;
	for (int i = 0; i < length; i++)
	{
		// ÿ�δ���һ�����
		cur = (DuL)malloc(sizeof(DuNode));
		// ����ʧ���򷵻ش���
		if (!cur)
		{
			return ERROR;
		}
		cur->data = *(datas + i);
		// ����ǰ�ý��
		tail->next = cur;
		cur->prior = tail;
		// ���Ӻ�̽��
		cur->next = duL;
		duL->prior = cur;
		// ��һ��
		tail = cur;
	}
	return OK;
}

/* 07_˫��ѭ��������ɾ��ָ��������Ԫ��*/
DuLinkedListElementType deleteByIndex_DuL(DuL& duL, int index)
{
	DuLinkedListElementType data;
	DuL cur = duL->next;
	// ֱ���ҵ��ý�㣬������ǰ��
	for (int i = 0; i < index; i++)
	{
		if (cur->next == duL)
		{
			return NULL;
		}
		cur = cur->next;
	}
	// ���淵��ֵ
	data = cur->data;
	// ��ǰ�ý��ͺ�̽����������
	cur->prior->next = cur->next;
	cur->next->prior = cur->prior;
	// �ͷſռ�
	free(cur);
	return data;
}
