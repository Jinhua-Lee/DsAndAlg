#include<math.h>
#include".\Alg\sort.cpp"
#include".\Alg\divideFunction.cpp"
#include".\Ds\01_SequenceList.h"

int main()
{
	//testArray();
	//testDivideFunction();

	//test();
	//testSort();

	//SqList sqList;
	// ����������
	createList_Sq(sqList, LIST_INIT_SIZE, LIST_INCREMENT);
	int length = 200;
	// ��������Ԫ��
	ElementType* elems = new ElementType[200];
	for (int i = 0; i < length; i++)
	{
		elems[i] = i * 2;
	}
	initList_Sq(sqList, elems, length);

	// ����Ԫ��
	traverseList_Sq(sqList);

	system("pause");
	return 1;
}