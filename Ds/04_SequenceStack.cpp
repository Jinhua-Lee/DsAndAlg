#include "04_SequenceStack.h"

/* ����˳��ջ�ķ���*/
void testSequenceStack()
{
	SqStack sS;

	// ��ʼ��
	printf("Stack initializing: ...\n");
	int initStatus = initStack_Sq(sS);
	printf("init status: %d\n", initStatus);

	// ��ջ
	printf("Pushing...\n");
	push_Sq(sS, 5);
	push_Sq(sS, 6);
	push_Sq(sS, 7);
	printf("Pushed.\n");

	// ��ջ����
	ElementType top;
	while (pop_Sq(sS, top))
	{
		printf("Pop:\ttop = %d\n", top);
	}
}

/* 01_˳��ջ������ʼ��*/
Status initStack_Sq(SqStack& sS)
{
	sS.elem = (ElementType*)malloc(STACK_INIT_SIZE * sizeof(ElementType));
	if (!sS.elem)
	{
		return ERROR;
	}
	sS.top = -1;
	sS.stackSize = STACK_INIT_SIZE;
	sS.incrementSize = STACK_INCREMENT;
	return OK;
}

/* 02_˳��ջ����ȡջ��Ԫ��*/
Status getTop_Sq(SqStack sS, ElementType& e)
{
	// ���ջ�գ����ش���
	if (stackEmpty_Sq(sS))
	{
		return ERROR;
	}
	// ��ֵ
	e = *(sS.elem + sS.top);
	return OK;
}

/* 03_˳��ջ������ջ*/
Status push_Sq(SqStack& sS, ElementType e)
{
	// �ﵽջ��С����������
	if (sS.top + 1 == sS.stackSize)
	{
		// ����ʧ�ܣ�����ʧ��
		if (!incrementStack_Sq(sS))
		{
			return ERROR;
		}
	}
	// ѹ��ջ��
	*(sS.elem + ++sS.top) = e;
	// ջ��С +1
	sS.stackSize++;
	// �ɹ�
	return OK;
}

/* 04_˳��ջ������ջ*/
Status pop_Sq(SqStack& sS, ElementType& e)
{
	// ���ջΪ�գ����ؽ��
	if (stackEmpty_Sq(sS))
	{
		return ERROR;
	}
	// ��ֵ���ƶ�ջ������
	e = *(sS.elem + sS.top--);
	// ջ��С -1
	sS.stackSize--;
	return OK;
}

/* 05_˳��ջ��������*/
Status destroyStack_Sq(SqStack& sS)
{
	// �����ڣ����ʶ�Ѿ����ٹ���
	if (!sS.elem)
	{
		return ERROR;
	}
	// ɾ��ָ��
	delete sS.elem;
	// �ṹ�����ֶ���Ĭ��ֵ
	sS.top = -1;
	sS.stackSize = 0;
	sS.incrementSize = 0;
	return OK;
}

/* 06_˳��ջ�����ж�ջ��*/
Status stackEmpty_Sq(SqStack sS)
{
	// ջ����������ջ������Ϊ-1
	return sS.top == -1 ? OK : ERROR;
}

/*  07_˳��ջ�������ջ*/
Status clearStack_Sq(SqStack& sS)
{
	// ֻ��Ҫ�ı�ջ����������Ϊ��Ԫ�صĴ�ȡ��ֻ��ջ������������λ�õ�ֵ�޷�����
	sS.top = -1;
	return OK;
}

/* 08_˳��ջ��������*/
Status incrementStack_Sq(SqStack& sS)
{
	// �������ݲ�������ǰ������������
	sS.elem = (ElementType*)malloc((sS.stackSize + (size_t)sS.incrementSize) * sizeof(ElementType));
	// ����ʧ�ܣ����ش���
	if (!sS.elem)
	{
		return ERROR;
	}
	// ���ݲ�Ҫ�����޸�����
	sS.stackSize += sS.incrementSize;
	return OK;
}