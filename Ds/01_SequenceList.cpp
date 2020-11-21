#include "01_SequenceList.h"

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
	ElementType* newElem;
	// ���ռ䲻�㣬�����ռ�
	if (srcLength + targetLength > sL.listSize)
	{
		// �����С�պ�Ϊ������ܳ��� +����
		newElem = (ElementType*)realloc(sL.elem, (srcLength + (size_t)targetLength + LIST_INCREMENT) * sizeof(ElementType));
		// ����ɹ�������˳�������
		if (newElem)
		{
			sL.listSize = sL.length + targetLength + LIST_INCREMENT;
			sL.elem = newElem;
		}
		// ����ʧ�ܷ��ش���
		else
		{
			return ERROR;
		}
	}
	// ��Ԫ�ؼӵ�˳���β��
	for (int i = srcLength; i < srcLength + targetLength; i++)
	{
		sL.elem[i] = elems[i - srcLength];
		sL.length++;
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

/* 04_˳���������Ԫ�أ����ҷ��ص�һ��ƥ�䵽��Ԫ������*/
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
	++sL.length;

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

/*  08_˳�����ɾ����ɾ��ָ��������Ԫ��*/
ElementType deleteElem_Sq(SqList& sL, int index)
{
	// �������Ԫ��������Χ��
	if (index < 0 || index >= sL.length)
	{
		return -1;
	}
	
	ElementType toDelete = *(sL.elem + index);
	// ���鷽ʽ
	/*for (int i = index; i < sL.length - 1; i++)
	{
		sL.elem[i] = sL.elem[i + 1];
	}*/
	// ָ�뷽ʽ
	ElementType* p = sL.elem + index;
	ElementType* q = sL.elem + sL.length - 1;
	while (p < q)
	{
		*p = *(p + 1);
		p++;
	}
	// �����ǳ��ȼ�һ
	sL.length--;
	return toDelete;
}

/* 09_˳������ϲ�����A�м���B�����е�Ԫ�أ����ɾ��B*/
Status purgeList_Sq(SqList& sLa, SqList& sLb)
{
	ElementType bElem;
	// ÿ�δ�B��ȡ����Ԫ����A�ж�λ�����û�ҵ��������
	while (sLb.length > 0)
	{
		bElem = deleteElem_Sq(sLb, 0);
		printf("��Bɾ���ˣ�%d\n", bElem);
		// ��A������Ҳ�����Ԫ�أ�������Ԫ��
		if (locateElem_Sq(sLa, bElem) == -1)
		{
			insertElem_Sq(sLa, sLa.length, bElem);
			printf("��A�����ˣ�%d\n", bElem);
		}
	}
	// �������B
	destroyList_Sq(sLb);
	return OK;
}

// ˳��������
void testSqList()
{
	SqList sLa;

	int aLength = 200;
	// ������ʼ��Ԫ��
	ElementType* elems = new ElementType[aLength];
	for (int i = 0; i < aLength; i++)
	{
		elems[i] = i * 2;
	}

	// ����������A����ʼ��
	createList_Sq(sLa, LIST_INIT_SIZE, LIST_INCREMENT);
	initList_Sq(sLa, elems, aLength);
	// ����Ԫ��
	traverseList_Sq(sLa);

	// ����Ԫ��
	int aLocation = locateElem_Sq(sLa, 126);
	int bLocation = locateElem_Sq(sLa, 125);
	printf("\naLocation = %-2d\tbLocation = %-2d\n", aLocation, bLocation);

	// ����Ԫ��
	insertElem_Sq(sLa, 2, -234);
	traverseList_Sq(sLa);

	printf("\nɾ��ָ������Ԫ�غ�\n");
	// ɾ��ָ������Ԫ��
	ElementType toDelete = deleteElem_Sq(sLa, 5);
	traverseList_Sq(sLa);
	printf("\n��ɾ��Ԫ��Ϊ��%d\n", toDelete);

	printf("\n=====================================\n");

	// �ڶ���˳������
	SqList sLb;
	int bLength = 20;
	ElementType* elems2 = new ElementType[bLength];
	for (int i = 0; i < bLength; i++)
	{
		elems2[i] = -i;
	}
	createList_Sq(sLb, LIST_INIT_SIZE, LIST_INCREMENT);
	initList_Sq(sLb, elems2, bLength);

	printf("\nB �ĳ��ȣ�%d\n", sLb.length);

	traverseList_Sq(sLb);
	// �ϲ�A��B������
	purgeList_Sq(sLa, sLb);
	printf("\n�����ϲ����A��\n");
	traverseList_Sq(sLa);

}
