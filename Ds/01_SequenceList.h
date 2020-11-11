#include <stdio.h>
#include <stdlib.h>

// �����ʼ��С������
#define LIST_INIT_SIZE 150
#define LIST_INCREMENT 20
// ���巵��״̬��������
#define Status int
#define OK 1
#define ERROR 0
// ����洢��Ԫ������
#define ElementType int

// ˳���Ĵ洢�ṹ����
typedef struct
{
	// ���Ա�洢�ռ��ַ
	ElementType* elem;

	// ���Ա�ǰ���Ԫ�صĸ���
	int length;

	// ��ǰ���Ա������
	int listSize;

	// Լ��ÿ�����ݵ�����
	int incrementSize;
}SqList;

// 01_˳����������ձ�û��Ԫ�أ�����Ϊ0��Ĭ������������
Status createList_Sq(SqList& sL, int initSize, int incrementSize);
// 02_˳�������ʼ������˳����ĩβ�������������Ԫ��
Status initList_Sq(SqList& sL, ElementType* elems, int targetLength);
// 03_˳���������
void traverseList_Sq(SqList& sL);
// ����˳���Ԫ��
void visit(ElementType elem);
// �Ƚ�Ԫ��
int compareElem(ElementType a, ElementType b);
// 04_˳���������Ԫ�أ����ҷ��ص�һ��ƥ�䵽��Ԫ������
int locateElem_Sq(SqList& sL, ElementType elem);
// 05_˳���������Ԫ�أ���ָ������ index ֮ǰ����һ��Ԫ��
Status insertElem_Sq(SqList& sL, int index, ElementType elem);
// 06_˳��������
Status clearList_Sq(SqList& sL);
// 07_˳���������
Status destroyList_Sq(SqList& sL);
// 08_˳�����ɾ����ɾ��ָ��������Ԫ�أ����ر�ɾ����Ԫ��ֵ
ElementType deleteElem_Sq(SqList& sL, int index);
// 09_˳������ϲ�����A�м���B�����е�Ԫ�أ����ɾ��B
Status purgeList_Sq(SqList& sLa, SqList& sLb);

// ���Է���
void testSqList();