#include<math.h>
#include".\Alg\sort.cpp"
#include".\Alg\divideFunction.cpp"
#include".\Ds\01_SequenceList.h"

// 引用和指针的测试
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

/*测试引用*/
void testRefer()
{
	int a = 123;
	int* p = &a;
	int& q = a;

	printf("指针测试：p的值 = %d, p的地址 = %p\n", *p, p);
	printf("引用测试：q的值 = %d, q的地址 = %p\n", q, &q);

	printf("p 和 q 地址相等bool输出结果：%d\n", p == &q);

}