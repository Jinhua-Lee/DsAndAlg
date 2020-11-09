#include"01_SequenceList.h"

/* 01_˳����������ձ�û��Ԫ�أ�����Ϊ0��Ĭ������������*/
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

/* 02_˳�������ʼ������˳����ĩβ�������������Ԫ��*/
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
			sL.listSize = sL.length + LIST_INCREMENT;
		}
		// ����ʧ�ܷ��ش���
		else
		{
			return ERROR;
		}
	}
	// ��Ԫ�ؼӵ�˳���β��
	for (int i = srcLength; i < sL.length; i++)
	{
		sL.elem[i] = elems[i - srcLength];
	}
	return OK;
}

/* 03_˳���������*/
void traverseList_Sq(SqList& sL)
{
	for (int i = 0; i < sL.length; i++)
	{
		visit(sL.elem[i]);
	}
}

/* ����Ԫ��*/
void visit(ElementType elem)
{
	printf("%-4d ", elem);
}

/* �Ƚ�Ԫ��*/
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

/* 04_˳���������Ԫ�أ����ҷ��ص�һ��ƥ�䵽��Ԫ��*/
int locateElem_Sq(SqList& sL, ElementType elem)
{
	// �õ�˳����ָ��
	int* p = sL.elem;
	// �ҵ�����λ������
	for (int i = 0; i < sL.length; i++)
	{
		if (compareElem(elem, *(p + i)))
		{
			return i;
		}
	}
	// �Ҳ������� -1
	return -1;
}
/* 05_˳���������Ԫ�أ���ָ������ index ֮ǰ����һ��Ԫ��*/
Status insertElem_Sq(SqList& sL, int index, ElementType elem)
{
	// �������Ϸ�
	if (index < 0)
	{
		return ERROR;
	}
	// �Ƿ��������
	if (sL.length + 1 >= sL.listSize)
	{
		sL.elem = (ElementType*)malloc((sL.listSize + (size_t)sL.incrementSize) * sizeof(ElementType));
		// ����ʧ��
		if (!sL.elem)
		{
			return ERROR;
		}
		sL.listSize += sL.incrementSize;
	}
	// ��ĩβ���
	if (index >= sL.length)
	{
		//sL.elem[sL.length] = elem;
		*(sL.elem + sL.length) = elem;
	}
	else
	{
		// ����ǰ�Ӻ���ǰ�ƶ�Ԫ�أ�ע������ȡֵ
		/*for (int i = sL.length - 1; i >= index; i--)
		{
			sL.elem[i + 1] = sL.elem[i];
		}*/
		for (ElementType* p = sL.elem + sL.length + 1; p >= sL.elem + index; p--)
		{
			*(p + 1) = *p;
		}
		//sL.elem[index] = elem;
		*(sL.elem + index) = elem;
	}
	// ��Ҫ���ǳ���
	sL.length++;

	return OK;
}
/* 06_˳��������*/
Status clearList_Sq(SqList& sL)
{
	// ����������е�ֵ
	delete[] sL.elem;
	// ���·���
	sL.elem = (ElementType*)malloc(LIST_INIT_SIZE * sizeof(ElementType));
	if (!sL.elem)
	{
		return ERROR;
	}
	// ���೤����Ϊ��ʼ
	sL.length = 0;
	sL.listSize = LIST_INIT_SIZE;
	sL.incrementSize = LIST_INCREMENT;
	return OK;
}
/* 07_˳���������*/
Status destroyList_Sq(SqList& sL)
{
	// ��������ռ�
	delete[] sL.elem;
	//free(sL.elem);
	// �������Ԫ����Ϊ0
	sL.length = 0;
	sL.listSize = 0;
	sL.incrementSize = 0;
	return OK;
}

// ˳��������
void testSqList()
{
	SqList sqList;
	// ����������
	createList_Sq(sqList, LIST_INIT_SIZE, LIST_INCREMENT);
	int length = 200;
	// ������ʼ��Ԫ��
	ElementType* elems = new ElementType[200];
	for (int i = 0; i < length; i++)
	{
		elems[i] = i * 2;
	}
	initList_Sq(sqList, elems, length);

	// ����Ԫ��
	traverseList_Sq(sqList);
	// ����Ԫ��
	int aLocation = locateElem_Sq(sqList, 126);
	int bLocation = locateElem_Sq(sqList, 125);
	printf("\naLocation = %-2d\t", aLocation);
	printf("bLocation = %-2d\n", bLocation);
	// ����Ԫ��
	insertElem_Sq(sqList, 2, -234);
	traverseList_Sq(sqList);
}
