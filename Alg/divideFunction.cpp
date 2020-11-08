#include<math.h>
#include<stdio.h>

inline void testDivideFunction();
// n 个 ele 组成的数，可以被 divisor 整除。
inline int divideFunction(int, long);
// 获取ele个num组成的值
inline long long getValue(int ele, int num);
inline long long getValue2(int ele, int num);

void testDivideFunction()
{
	int num, ele;
	long divisor;

	printf("依次输入元素ele和个数num：\n");
	scanf_s("%d %d", &ele, &num);

	printf("请输入被除数 divisor：\n");
	scanf_s("%d", &divisor);

	printf("Test1： %d 个 %d 的值为 %lld\n", num, ele, getValue(ele, num));
	printf("Test2： %d 个 %d 的值为 %lld\n", num, ele, getValue2(ele, num));

	printf("%d 个 %d 可以被 %d整除！\n", divideFunction(ele, divisor), ele, divisor);
}

/**
 * n 个 ele 组成的数，可以被 divisor 整除。
 * 返回 n
 */
int divideFunction(int ele, long divisor)
{
	if (divisor == 0)
	{
		return -1;
	}
	int num = 0;
	long long value;
	do
	{
		value = getValue2(ele, ++num);
	} while (value % divisor != 0);

	return num;
}

/**
 * 循环实现求 num 个 ele 的值
 *		1. 若个数 < 0，返回-1
 * 		2. 若元素不在0~9内，返回-2
 */
long long getValue(int ele, int num)
{
	long long value = 0;
	if (num < 0)
	{
		return -1;
	}
	if (ele < 0 || ele > 9)
	{
		return -2;
	}
	for (int i = num - 1; i >= 0; i--)
	{
		value += ele * (long long)pow(10, i);
	}
	return value;
}

/**
 * 递归实现求 num 个 ele 的值
 *		1. 若个数 < 0，返回-1
 * 		2. 若元素不在0~9内，返回-2
 */
long long getValue2(int ele, int num)
{
	long long temp = ele * pow(10, (long long)num - 1);
	if (num == 1)
	{
		return temp;
	}
	else
	{
		return temp + getValue2(ele, num - 1);
	}
}