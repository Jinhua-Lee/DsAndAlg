#include<math.h>
#include<stdio.h>

inline void testDivideFunction();

inline int divideFunction(int, long);

inline long long getValue(int, int);
inline long long getValue2(int, int);

void testDivideFunction()
{
	int num, ele;
	long divisor;

	printf("��������Ԫ��ele�͸���num��\n");
	scanf_s("%d %d", &ele, &num);

	printf("�����뱻���� divisor��\n");
	scanf_s("%d", &divisor);

	printf("Test1�� %d �� %d ��ֵΪ %lld\n", num, ele, getValue(ele, num));
	printf("Test2�� %d �� %d ��ֵΪ %lld\n", num, ele, getValue2(ele, num));

	printf("%d �� %d ���Ա� %d������\n", divideFunction(ele, divisor), ele, divisor);
}

/**
 * n �� ele ��ɵ��������Ա� divisor ������
 * ���� n
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
 * ѭ��ʵ���� num �� ele ��ֵ
 *		1. ������ < 0������-1
 * 		2. ��Ԫ�ز���0~9�ڣ�����-2
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
 * �ݹ�ʵ���� num �� ele ��ֵ
 *		1. ������ < 0������-1
 * 		2. ��Ԫ�ز���0~9�ڣ�����-2
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