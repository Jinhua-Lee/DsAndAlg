#include<math.h>
#include".\Alg\sort.cpp"
#include".\Alg\divideFunction.cpp"
#include".\Ds\01_SequenceList.h"

// ���ú�ָ��Ĳ���
void testRefer();

int main()
{
	//testArray();
	//testDivideFunction();

	//test();
	//testSort();
	//testRefer();

	testSqList();

	return 1;
}

/*��������*/
void testRefer()
{
	int a = 123;
	int* p = &a;
	int& q = a;

	printf("ָ����ԣ�p��ֵ = %d, p�ĵ�ַ = %p\n", *p, p);
	printf("���ò��ԣ�q��ֵ = %d, q�ĵ�ַ = %p\n", q, &q);

	printf("p �� q ��ַ���bool��������%d\n", p == &q);

}