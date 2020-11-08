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

SqList sqList;


// ����һ���յ�˳���
inline Status createList_Sq(SqList& sL, int initSize, int incrementSize);
// ��˳����ĩβ�������������Ԫ��
inline Status initList_Sq(SqList& sL, ElementType* elems, int targetLength);
// ����˳���
inline void traverseList_Sq(SqList& sL);
// ����˳���Ԫ��
inline void visit(ElementType elem);
// �Ƚ�Ԫ��
inline int compareElem(ElementType a, ElementType b);
// ����Ԫ�أ����ҷ��ص�һ��ƥ�䵽��Ԫ��
inline int locateElem_Sq(SqList& sL, ElementType elem);