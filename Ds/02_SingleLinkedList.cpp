#include"02_SingleLinkedList.h"

/* ���Ե�����ķ���*/
void testSingleLinkedList()
{
	int length;
	printf("�����������ȣ�\n");
	scanf_s("%d", &length);
	ElementType* datas = new ElementType[length];
	printf("����������� %d ��Ԫ�أ�\n", length);
	for (int i = 0; i < length; i++)
	{
		scanf_s("%d", datas + i);
	}

	// =====��ͷ���=====
	// ָ��ͷ�ڵ��ָ�룺ͷָ��
	SL head = NULL;

	// ��ʼ��
	int initStatus = initList_SLh(head);
	printf("initStatus: %d\n", initStatus);

	// β�巨
	int tailInsertStatus = tailInsert_SLh(head, datas, length);
	printf("tailInsertStatus: %d\n", tailInsertStatus);

	// ����
	int listLength = listLength_SLh(head);
	printf("��ͷ��㣬��������Ϊ�� %d\n", listLength);

	// ����
	traveseList_SLh(head);

	// =====����ͷ���=====
	SL sL;

	// ��ʼ��
	int initStatus2 = initList_SL(sL);
	printf("initStatus2: %d\n", initStatus2);

	// β�巨
	int tailInsertStatus2 = tailInsert_SL(sL, datas, length);
	printf("tailInsertStatus2: %d\n", tailInsertStatus2);

	// ����
	int listLength2 = listLength_SL(sL);
	printf("����ͷ��㣬��������Ϊ�� %d\n", listLength2);

	// ����
	traverseList_SL(sL);

}

/* 01_����������ʼ��_��ͷ���
*/
Status initList_SLh(SL& head)
{
	// ָ��ͷ�ڵ��ָ��
	head = (SL)malloc(sizeof(SL_Node));
	if (!head)
	{
		return ERROR;
	}
	head->data = NULL;
	head->next = NULL;
	return OK;
}

/* 02_����������ʼ��_��ͷ���*/
Status initList_SL(SL& sL)
{
	sL = NULL;
	return OK;
}

/* 03_������������_��ͷ���*/
int listLength_SLh(SL head)
{
	// ��ʼ��������
	int length = 0;
	// ָ��ͷ���ı���
	SL p = head->next;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

/* 04_������������_��ͷ���*/
int listLength_SL(SL sL)
{
	int length = 0;
	// ��ͷָ�뿪ʼ����
	SL p = sL;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

/* 05_������������_��ͷ�ڵ�*/
void destroy_SLh(SL& head)
{
	// ����pָ�룬ָ��ͷ�ڵ��Ĵ�ɾ�����
	SL_Node* p;
	// ��ǰ���ڴ�ɾ�����
	while (head->next)
	{
		// ָ���ɾ�����
		p = head->next;
		// ͷ������ӵ���̽��
		head->next = p->next;
		// ���е�ǰ����ɾ��
		p->data = NULL;
		p->next = NULL;
		free(p);
	}
}

/* 06_������������_��ͷ�ڵ�*/
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
		p->data = NULL;
		p->next = NULL;
		free(p);
	}
}

/* 07_��������β�巨����_��ͷ�ڵ�*/
Status tailInsert_SLh(SL& head, ElementType *datas, int length)
{
	// ָ��p�����һ�����
	SL p = head;
	// �����½��Ľ��
	SL q = NULL;

	for (int i = 0; i < length; i++)
	{
		// ָ��p��ÿ��ѭ�������һ�����ָ���򣬽��н�㴴��
		q = (SL)malloc(sizeof(SL_Node));
		if (!q)
		{
			return ERROR;
		}
		q->data = *(datas + i);
		q->next = NULL;
		// �½�����ӵ���һ�����
		p->next = q;
		// ����
		p = q;
		q = q->next;
	}
	return OK;
}

/* 08_��������β�巨����_����ͷ�ڵ�*/
Status tailInsert_SL(SL& sL, ElementType* datas, int length)
{
	// ָ��p������������һ�����
	SL p = sL;
	// ָ��q�����ڴ����½��
	SL q = p;

	for (int i = 0; i < length; i++)
	{
		// ָ��p��ÿ��ѭ�������һ�����ָ���򣬽��н�㴴��
		q = (SL)malloc(sizeof(SL_Node));
		if (!q)
		{
			return ERROR;
		}
		q->data = *(datas + i);
		q->next = NULL;
		// ��Ϊ��һ�����ʱ
		if (i)
		{
			// ���½ڵ�����p����
			p->next = q;
			// �½ڵ���Ϊ��һ�����
			p = q;
			
		}
		// Ϊ��һ�����ʱq�´����ĵ�ַ��ֵ�������ʶsL���Լ���һ������ʶp
		else
		{
			sL = q;
			p = q;
		}
		// ָ��q�����ƶ����½�㴴��λ��
		q = q->next;
	}
	return OK;
}

/* 09_��������ͷ�巨����_��ͷ���*/
Status headInsert_SLh(SL& head, ElementType* datas, int length)
{
	// ָ��p������������һ�������Ľ�㣬ʹ��ͷ�ڵ�ָ����´������ָ����һ����㡣
	SL p = head->next;
	for (int i = 0; i < length; i++)
	{
		// ÿ��ͨ��ͷ��㴴���½��
		head->next = (SL)malloc(sizeof(SL_Node));
		if (!head->next)
		{
			return ERROR;
		}
		head->next->data = *(datas + i);
		// i==0����һ����㼴Ϊ��������һ��Ԫ�أ�next�ÿ�
		if (i)
		{
			head->next->next = NULL;
		}
		else
		{
			head->next->next = p;
		}
		p = head->next;
	}
	return OK;
}

/* 10_��������ͷ�巨����_����ͷ���*/
Status headInsert_SL(SL& sL, ElementType* datas, int length)
{
	// ͬ�ϣ�ָ��p����������һ�������Ľ�㣬���½ڵ㴴��ʱ��next��ֵ��p
	SL p = sL;
	for (int i = 0; i < length; i++)
	{
		sL = (SL)malloc(sizeof(SL_Node));
		if (!sL)
		{
			return ERROR;
		}
		sL->data = *(datas + i);
		// i==0����һ����㼴Ϊ��������һ��Ԫ�أ�next�ÿ�
		if (i)
		{
			sL->next = NULL;
		}
		else
		{
			sL->next = p;
		}
		p = sL;
	}
	return OK;
}

/* 11_������������_��ͷ�ڵ�*/
void traveseList_SLh(SL head)
{
	SL p = head->next;
	printf("��ʼ������\n");
	while (p)
	{
		visit(*p);
		p = p->next;
	}
	printf("����������\n");
}

/* 12_������������_����ͷ���*/
void traverseList_SL(SL sL)
{
	SL p = sL;
	printf("��ʼ������\n");
	while (p)
	{
		visit(*p);
		p = p->next;
	}
	printf("����������\n");
}
/* 13_�����������ʷ���*/
void visit(Hnode hnode)
{
	printf("data -->> %d\n", hnode.data);
}
