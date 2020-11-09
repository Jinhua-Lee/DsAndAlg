#include"01_SequenceList.h"

/*����һ���յ�˳���*/
Status createList_Sq(SqList& sL, int initSize = LIST_INIT_SIZE, int incrementSize = LIST_INCREMENT)
{
	// ����˳���洢�ռ�
	sL.elem = (ElementType*)malloc(initSize * sizeof(ElementType));
	// ����ʧ�ܣ����ش�����
	if (!sL.elem)
	{
		return ERROR;
	}
	sL.length = 0;
	sL.listSize = initSize;
	sL.incrementSize = incrementSize;
	return OK;
}

/*��ʼ��һ���յ�˳�����Ԫ�ؼ��뵽˳���ĩβ*/
Status initList_Sq(SqList& sL, ElementType* elems, int targetLength)
{
	int srcLength = sL.length;
	// ���ռ䲻�㣬�����ռ�
	if (srcLength + targetLength > sL.listSize)
	{
		// �����С�պ�Ϊ������ܳ��� +����
		sL.elem = (ElementType*)malloc((srcLength + (size_t)targetLength + LIST_INCREMENT) * sizeof(ElementType));
		// ����ɹ�������˳�������
		if (sL.elem)
		{
			sL.length = srcLength + targetLength;
			sL.listSize = srcLength + targetLength + LIST_INCREMENT;
		}
		// ����ʧ�ܷ��ش���
		else
		{
			return ERROR;
		}
	}
	// ��Ԫ�ؼӵ�˳���β��
	for (int i = srcLength; i < sL.length + targetLength; i++)
	{
		sL.elem[i] = elems[i - srcLength];
	}
	return OK;
}

/*����˳����Ԫ��*/
void traverseList_Sq(SqList& sL)
{
	for (int i = 0; i < sL.length; i++)
	{
		visit(sL.elem[i]);
	}
}

/*����Ԫ��*/
void visit(ElementType elem)
{
	printf("%-4d ", elem);
}

/*�Ƚ�Ԫ��*/
int compareElem(ElementType a, ElementType b)
{
	// ��ȷ���1������ȷ���0
	if (a == b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*����Ԫ�أ����ҷ��ص�һ��ƥ�䵽��Ԫ��*/
int locateElem_Sq(SqList& sL, ElementType elem)
{
	// �õ�˳����ָ��
	int* p = sL.elem;
	// �ҵ�����λ������
	for (int i = 0; i < sL.length; i++)
	{
		if (compareElem(elem, p[i]))
		{
			return i;
		}
	}
	// �Ҳ������� -1
	return -1;
}