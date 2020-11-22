#include "05_LinkedStack.h"

/* ���Ե���ջ�ķ���*/
void testLinkedStack()
{
    // ���嵥��ջ
    LS Ls;

    // ��ʼ��
    printf("LinkedStack init...\n");
    initStack_LS(Ls);

    // ��ջ
    ElementType top;
    printf("LinkedStack push...\n");

    push_LS(Ls, 5);
    getTop_LS(Ls, top);
    printf("Top elem -> %d\n", top);

	push_LS(Ls, 6);
	getTop_LS(Ls, top);
	printf("Top elem -> %d\n", top);

	push_LS(Ls, 7);
	getTop_LS(Ls, top);
	printf("Top elem -> %d\n", top);

    // ��ջ
	ElementType poped;
    while (pop_LS(Ls, poped))
	{
		printf("Pop:\ttop = %d\n", poped);
	}
}

/* 01_����ջ������ʼ��*/
Status initStack_LS(LS& Ls)
{
    Ls = NULL;
    return OK;
}

/* 02_����ջ����ȡջ��*/
Status getTop_LS(LS& Ls, ElementType& elem)
{
    if (stackEmpty_LS(Ls))
    {
        return ERROR;
    }
    elem = Ls->data;
    return OK;
}

/* 03_����ջ������ջ*/
Status push_LS(LS& Ls, ElementType elem)
{
    // �����ڵ������ͷ�巨
    // ָ��p�����´������
    LS p = (LS)malloc(sizeof(S_Node));
    // ָ��q��������
    LS q = Ls;
    // �������ʧ�ܣ�����
    if (!p)
    {
        return ERROR;
    }
    p->data = elem;
    // ����ͷ��
    p->next = q;
    Ls = p;
    return OK;
}

/* 04_����ջ������ջ*/
Status pop_LS(LS& Ls, ElementType& elem)
{
    // ջΪ�գ����ش���
    if (stackEmpty_LS(Ls))
    {
        return ERROR;
    }
    LS p = Ls;
    // ��ֵ
    elem = p->data;
    // ָ�����
    Ls = Ls->next;
    // ���ٳ�ջ���
    delete p;
    return OK;
}

/* 05_����ջ����ջ����*/
int stackLength_LS(LS Ls)
{
    int length = 0;
    // ֱ����s�����������Բ���ȡ��������
    while (Ls)
    {
        length++;
        Ls = Ls->next;
    }
	return length;
}

/* 06_����ջ�����п�*/
Status stackEmpty_LS(LS Ls)
{
    // Ϊ�շ��ط�0�����򷵻�0
    return Ls == NULL ? OK : ERROR;
}

/* 07_����ջ�������*/
Status clearStack_LS(LS& Ls)
{
    // ָ��p������ջ��Ԫ��
    LS p;
    while (Ls)
    {
        // ����ջ��Ԫ��
        p = Ls;
        // ջ��ָ�����
        Ls = Ls->next;
        // ����ջ��Ԫ��
        delete p;
    }
    delete Ls;
    return OK;
}
