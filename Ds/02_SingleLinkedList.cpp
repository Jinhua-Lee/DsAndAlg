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

	// ���Դ�ͷ���
	printf("=====��ͷ���=====");
	testWithHead(datas, length);

	// ���Բ���ͷ���
	printf("=====����ͷ���=====");
	testWithoutHead(datas, length);

}

/* ��ͷ���Ĳ��Է���*/
void testWithHead(ElementType* datas, int length)
{
	// =====��ͷ���=====
	// ָ��ͷ�ڵ��ָ�룺ͷָ��
	SL head = NULL;

	// ��ʼ��
	int initStatus = initList_SLh(head);
	printf("��ʼ��״̬: %d\n", initStatus);

	// β�巨
	int tailInsertStatus = tailInsert_SLh(head, datas, length);
	printf("β�巨״̬: %d\n", tailInsertStatus);
	traveseList_SLh(head);

	// ͷ�巨
	int headInsertStatus = headInsert_SLh(head, datas, length);
	printf("ͷ�巨״̬: %d\n", headInsertStatus);
	traveseList_SLh(head);

	// ����
	int listLength = listLength_SLh(head);
	printf("��ͷ��㣬��������Ϊ�� %d\n", listLength);
}

/* ����ͷ���Ĳ��Է���*/
void testWithoutHead(ElementType* datas, int length)
{
	// =====����ͷ���=====
	SL sL;

	// ��ʼ��
	int initStatus = initList_SL(sL);
	printf("��ʼ��״̬: %d\n", initStatus);

	// β�巨
	int tailInsertStatus2 = tailInsert_SL(sL, datas, length);
	printf("β�巨״̬: %d\n", tailInsertStatus2);
	traverseList_SL(sL);

	// ͷ�巨
	int headInsertStatus2 = headInsert_SL(sL, datas, length);
	printf("ͷ�巨״̬: %d\n", headInsertStatus2);
	traverseList_SL(sL);

	// ����
	int listLength2 = listLength_SL(sL);
	printf("����ͷ��㣬��������Ϊ�� %d\n", listLength2);
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
	SL p = head;
	// ָ��q�����ڴ����µĽ��
	SL q = NULL;

	for (int i = 0; i < length; i++)
	{
		// ÿ��ͨ��ͷ��㴴���½��
		q = (SL)malloc(sizeof(SL_Node));
		if (!q)
		{
			return ERROR;
		}
		q->data = *(datas + i);
		// Ԫ�ؽӵ�ͷ����
		head->next = q;
		// ��һ��������
		if (!i)
		{
			// ��һ����㼴Ϊ��β���
			q->next = NULL;
			// ָ��p������Ϊ��һ������Ľ��
			
		}
		// �ǵ�һ�����
		else
		{
			// ���ǰ��Ϊͷ���
			head->next = q;
			// �����Ϊ��һ�����
			q->next = p;
		}
		// ָ��p���浱�β���Ľ��λ��
		p = q;
	}
	return OK;
}

/* 10_��������ͷ�巨����_����ͷ���*/
Status headInsert_SL(SL& sL, ElementType* datas, int length)
{
	// ͬ�ϣ�ָ��p����������һ�������Ľ��
	SL p = sL;
	// ָ��q�����������µĽڵ�
	SL q = NULL;

	for (int i = 0; i < length; i++)
	{
		q = (SL)malloc(sizeof(SL_Node));
		if (!q)
		{
			return ERROR;
		}
		q->data = *(datas + i);
		// ��һ�����
		if (!i)
		{
			// ��һ�������Ϊ��β���
			q->next = NULL;
		}
		else
		{
			// ���ӵ���һ�β���Ľ��
			q->next = p;
		}
		// ���ӵ���ʼ
		sL = q;
		// ����Ϊ��һ�����
		p = q;
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
