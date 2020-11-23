#include "02_SingleLinkedList.h"

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
	printf("\n=====��ͷ���=====\n");
	testWithHead(datas, length);

	// ���Բ���ͷ���
	printf("\n=====����ͷ���=====\n");
	testWithoutHead(datas, length);

	// ������������ϲ�
	printf("\n=====��������ϲ�=====\n");
	testMerge();
}

/* ��ͷ���Ĳ��Է���*/
void testWithHead(ElementType* datas, int length)
{
	// =====��ͷ���=====
	// ָ��ͷ����ָ�룺ͷָ��
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

	// ɾ�����
	deleteElem_SLh(head, 5);
	traveseList_SLh(head);

	// ԭ�����õ�����
	invertList_SLh(head);
	traveseList_SLh(head);
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

	// ɾ�����
	deleteElem_SL(sL, 5);
	traverseList_SL(sL);

	// ԭ�����õ�����
	invertList_SL(sL);
	traverseList_SL(sL);

}

/* ������������ϲ��ķ���*/
void testMerge()
{
	SL headA, headB, head;
	initList_SLh(head);
	initList_SLh(headA);
	initList_SLh(headB);

	ElementType arrA[] = { 1, 3, 5, 7, 9 };
	ElementType arrB[] = { 0, 2, 4, 6, 8 };

	printf("=====����β�巨=====\n");
	tailInsert_SLh(headA, arrA, 5);
	tailInsert_SLh(headB, arrB, 5);
	traveseList_SLh(headA);
	traveseList_SLh(headB);

	printf("=====��ʼ�ϲ�=====\n");
	head = mergeTwoList(headA, headB);
	traveseList_SLh(head);
}

/* ������������������ϲ�Ϊһ���ݼ����е�����*/
SL mergeTwoList(SL headA, SL headB)
{
	// �����صĺϲ��������
	SL head;
	initList_SLh(head);
	// ָ��s��ָ��Ŀ����������һ�������Ԫ��
	SL s = NULL;

	SL p = headA->next;
	SL q = headB->next;
	// ������������Ԫ��ʱ��ȡС��Ԫ�ؽ���ͷ�巨
	while (p && q)
	{
		// ÿ�ν�ѭ����׼��ͷ�壬����Ŀ��������һ�β���Ľ��
		s = head->next;
		if (p->data <= q->data)
		{
			// Ŀ������ͷ��㣬ֱ��ָ��������Ԫ��
			head->next = p;
			// ��ѡȡԪ�ص�����ͷ���ָ��ѡԪ�صĺ��
			headA->next = p->next;
			// Ŀ������Ĵ�����Ԫ��ָ�򱣴����һ����㣬���ͷ��
			p->next = s;
			// ��ѡԪ�ص���һ�ε���
			p = headA->next;
		}
		else
		{
			head->next = q;
			headB->next = q->next;
			q->next = s;
			q = headB->next;
		}
	}
	// ֻ��һ��������Ԫ��ʱ�����ν�����Ԫ�ؽ���ͷ�巨
	while (p)
	{
		s = head->next;
		head->next = p;
		headA->next = p->next;
		p->next = s;
		p = headA->next;
	}
	while (q)
	{
		s = head->next;
		head->next = q;
		headB->next = q->next;
		q->next = s;
		q = headB->next;
	}
	free(headA);
	free(headB);
	return head;
}


/* 01_����������ʼ��_��ͷ���
*/
Status initList_SLh(SL& head)
{
	// ָ��ͷ����ָ��
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

/* 05_������������_��ͷ���*/
void destroy_SLh(SL& head)
{
	// ����pָ�룬ָ��ͷ����Ĵ�ɾ�����
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

/* 06_������������_��ͷ���*/
void destroy_SL(SL& sL)
{
	// ָ��p��ָ��ǰ��ɾ�����
	SL p;
	while (sL)
	{
		// ÿ����ָ���ɾ�����
		p = sL;
		// ͷָ��ָ���̽��
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

/* 07_��������β�巨����_��ͷ���*/
Status tailInsert_SLh(SL& head, ElementType *datas, int length)
{
	// ָ��p�����һ�����
	SL p = head;
	// �����½��Ľ��
	SL s = NULL;

	for (int i = 0; i < length; i++)
	{
		// ָ��p��ÿ��ѭ�������һ�����ָ���򣬽��н�㴴��
		s = (SL)malloc(sizeof(SL_Node));
		if (!s)
		{
			return ERROR;
		}
		s->data = *(datas + i);
		s->next = NULL;
		// �½�����ӵ���һ�����
		p->next = s;
		// ����
		p = s;
		s = s->next;
	}
	return OK;
}

/* 08_��������β�巨����_����ͷ���*/
Status tailInsert_SL(SL& sL, ElementType* datas, int length)
{
	// ָ��p������������һ�����
	SL p = sL;
	// ָ��s�����ڴ����½��
	SL s = NULL;

	for (int i = 0; i < length; i++)
	{
		// ָ��p��ÿ��ѭ�������һ�����ָ���򣬽��н�㴴��
		s = (SL)malloc(sizeof(SL_Node));
		if (!s)
		{
			return ERROR;
		}
		s->data = *(datas + i);
		s->next = NULL;
		// ��Ϊ��һ�����ʱ
		if (i)
		{
			// ���½������p����
			p->next = s;
			
		}
		// Ϊ��һ�����ʱs�´����ĵ�ַ��ֵ�������ʶsL���Լ���һ������ʶp
		else
		{
			sL = s;
		}
		// �½����Ϊ��һ�����
		p = s;
		// ָ��q�����ƶ����½�㴴��λ��
		s = s->next;
	}
	return OK;
}

/* 09_��������ͷ�巨����_��ͷ���*/
Status headInsert_SLh(SL& head, ElementType* datas, int length)
{
	// ָ��p������������һ�������Ľ�㣬ʹ��ͷ���ָ����´������ָ����һ����㡣
	SL p = head;
	// ָ��s�����ڴ����µĽ��
	SL s = NULL;

	for (int i = 0; i < length; i++)
	{
		// ÿ��ͨ��ͷ��㴴���½��
		s = (SL)malloc(sizeof(SL_Node));
		if (!s)
		{
			return ERROR;
		}
		s->data = *(datas + i);
		// Ԫ�ؽӵ�ͷ����
		head->next = s;
		// ��һ��������
		if (!i)
		{
			// ��һ����㼴Ϊ��β���
			s->next = NULL;
		}
		// �ǵ�һ�����
		else
		{
			// ���ǰ��Ϊͷ���
			head->next = s;
			// �����Ϊ��һ�����
			s->next = p;
		}
		// ָ��p���浱�β���Ľ��λ��
		p = s;
	}
	return OK;
}

/* 10_��������ͷ�巨����_����ͷ���*/
Status headInsert_SL(SL& sL, ElementType* datas, int length)
{
	// ͬ�ϣ�ָ��p����������һ�������Ľ��
	SL p = sL;
	// ָ��s�����������µĽ��
	SL s = NULL;

	for (int i = 0; i < length; i++)
	{
		s = (SL)malloc(sizeof(SL_Node));
		if (!s)
		{
			return ERROR;
		}
		s->data = *(datas + i);
		// ��һ�����
		if (!i)
		{
			// ��һ�������Ϊ��β���
			s->next = NULL;
		}
		else
		{
			// ���ӵ���һ�β���Ľ��
			s->next = p;
		}
		// ���ӵ���ʼ
		sL = s;
		// ����Ϊ��һ�����
		p = s;
	}
	return OK;
}

/* 11_������������_��ͷ���*/
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
void visit(HNode hnode)
{
	printf("data -->> %d\n", hnode.data);
}

/* 14_��������ɾ�����_��ͷ���*/
void deleteElem_SLh(SL& head, ElementType data)
{
	// �����ɾ��������һ�����
	SL p = head;
	// �����ɾ�����
	SL q = NULL;
	while (p->next)
	{
		// ָ��p��������һ������ʱ���жϳ���һ����������
		if (p->next->data == data)
		{
			q = p->next;
			// ָ��q���޺�̽�㣬��Ӱ��
			p->next = q->next;
			free(q);
			return;
		}
		// �����������
		p = p->next;
	}
}

/* 15_��������ɾ�����_����ͷ���*/
void deleteElem_SL(SL& sL, ElementType data)
{
	// ָ��p�������ɾ������ǰһ�����
	SL p = sL;
	// ָ��q��ָ��p�ĺ�̽��
	SL q = p->next;
	// �������û�н�㣬ֱ�ӷ���
	if (!p)
	{
		return;
	}
	// �����һ�������Ǵ�ɾ�����
	else if (p && p->data == data)
	{
		sL = q;
		free(p);
		return;
	}
	// �������Ͻ��
	while (p->next)
	{
		// ָ��p��������һ������ʱ���жϳ���һ����������
		if (p->next->data == data)
		{
			q = p->next;
			p->next = q->next;
			free(q);
			return;
		}
		p = p->next;
	}
}

/* 16_��������ԭ������_��ͷ���*/
/* ��������ԭ�����á�������⡣
1. ��˼·�ǽ����н���Ϊ����״̬������������á��͡������á���
2. �տ�ʼ��״̬�����н�㶼�Ǵ�����״̬��
3. ������Ԫ����⣬���������ִ�����ù����ж��н�㴦�����������״̬��
4. Ϊ�˷�����⣬�Ҳ�������Ԫ�������á��롺���������á�������Ϊ��ͬ�ӹ��̵�������������Ԫ������ù����С������һ���ս�㡻��Ϊ�����������״̬���Ľ�㡣
5. �˴�����ս����Ϊ�����������״̬��㡻�������㽫ѭ���廮�ֳ�����
6. �ѵ����ڻ��ֳ����ִε�ѭ�����̡�
*/
void invertList_SLh(SL& head)
{
	// ָ��p������һ�����ı�ָ���Ԫ�أ���֤�Ͽ���ͷ����ָ�����ҵ�
	SL p = head->next;
	// ��ָ��p�����ˣ��˴�һ��Ҫ�ÿգ���Ϊ������Ŀս��
	head->next = NULL;
	// ָ��s��Ҫ�ı�ָ���Ԫ��
	SL s = NULL;
	// �ر�ע������һ�ֵĹ��̣�����һ��NULL�����ͷ������Ԫ���֮�䣬��Ϊ����������á���Ԫ�ء�
	while (p)
	{
		// ��ǰ�������õ�Ԫ�ء���ɣ����á���һ��������Ԫ�ء�Ϊ����ǰ�����á���
		s = p;
		// ָ��p��Ϊ����һ�������á�
		p = p->next;
		// ��ǰ������Ԫ�أ�ָ����һ��������ɵ�Ԫ�أ���һ��������һ��Ԫ�ؼ���������Ŀս�㣬�˴��ڽ���ѭ��ǰ�ÿգ�
		s->next = head->next;
		// ��ǰԪ��������ɣ���ͷ���ָ��ָ���Ԫ�ء����ǡ���һ��������ɵ�Ԫ�ء�
		head->next = s;
	}
}

/* 17_��������ԭ������_����ͷ���*/
/* ����ͬ�ϣ�ԭ���޲�ͬ��ֻ��head->next�滻ΪsLͷָ��*/
void invertList_SL(SL& sL)
{
	SL p = sL;
	sL = NULL;
	SL s = NULL;
	while (p)
	{
		s = p;
		p = p->next;
		s->next = sL;
		sL = s;
	}
}

/* 18_����������ʼ��_��ͷ���2*/
Status initList_SLh2(HNode** hNode)
{
	*hNode = (HNode*)malloc(sizeof(SL_Node));
	if (!*hNode)
	{
		return ERROR;
	}
	(*hNode)->data = NULL;
	(*hNode)->next = NULL;
	return OK;
}
