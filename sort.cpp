#include<stdio.h>
#include<stdlib.h>

inline void inputArray(int* arr, int length);
inline void traverseArray(int* arr, int length);
inline void swapInt(int* arr, int index1, int index2);

inline void bubbleSort(int* arr, int length);
inline void selectSort(int* arr, int length);
inline void insertSort(int* arr, int length);
inline void shellSort(int* arr, int length);
inline void quickSort(int* arr, int start, int end);
inline void heapSort(int* arr, int length);
inline void buildTopMaxHeap(int* arr, int lastIndex);

inline void testSort();

void testSort()
{
	printf("���������鳤�� length��\n");
	int length;
	scanf_s("%d", &length);
	int* arr = new int[length];

	inputArray(arr, length);
	printf("-------����-------\n");
	printf("����ǰ�� \n");
	traverseArray(arr, length);

	//bubbleSort(arr, length);
	//selectSort(arr, length);
	//insertSort(arr, length);
	//shellSort(arr, length);
	//quickSort(arr, 0, length - 1);
	heapSort(arr, length);

	printf("����� \n");
	traverseArray(arr, length);
}

void inputArray(int *arr, int length)
{
	printf("������int�������飬�ո������\n");
	for (int i = 0; i < length; i++)
	{
		scanf_s("%d", arr + i);
	}
}

void traverseArray(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("arr[%2d] = %-4d", i, arr[i]);
	}
	printf("\n");
}

/**
 * ����int���������λ�õ�ֵ
 */
void swapInt(int* arr,  int index1,  int index2) {
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

/**
 * 01_ð������
 *      1) ÿ�ֻ�ѡ������Ԫ�ص�ĩ��
 *      2) �Ľ�������һ��������Ǹ����Ƿ��н�����Ԫ�أ���û�н��������Ѿ��ź���
 */
void bubbleSort(int *arr, int length)
{
	// ����ʾѭ��������ѭ�� length - 1��
	for (int i = 0; i < length - 1; i++)
	{
		// �����Ƿ��Ž������ı�־��������û�ı䣬���ʾû���й��������Ѿ��ź�
		bool swap = false;
		// ÿһ��������㣩���Ὣ���ֵ�ŵ�����ĩ�ˣ� �����ڲ�ÿ�ֵ�������λ����Խ��ԽС��length - i - 1��
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap = true;
				swapInt(arr, j, j + 1);
			}
			if (!swap)
			{
				break;
			}
		}
	}
}

/**
 * 02_��ѡ������
 */
void selectSort(int* arr, int length)
{
	// ���ѭ����i���ɱ�ʾ���������СֵҪ�����λ�á�
	for (int i = 0; i < length; i++)
	{
		int value = arr[i];
		int position = i;
		for (int j = i + 1; j < length; j++)
		{
			// ѡ��С��ֵ����¼Сֵ��λ��
			if (arr[j] < value)
			{
				value = arr[j];
				position = j;
			}
		}
		// ������Сֵ�͵�ǰ��������λ��
		arr[position] = arr[i];
		arr[i] = value;
	}
}

/**
 * 03_ֱ�Ӳ�������
 */
void insertSort(int* arr, int length)
{
	int value;
	// ����1��ʼ����һ�������ò���
	for (int i = 1; i < length; i++)
	{
		// ���浱ǰֵ
		value = arr[i];
		// j�ǴӺ���ǰ�ģ�ÿ�����ó�ʼֵΪi��ǰһ��
		int j = i - 1;
		// ���ڵ�ǰ�������ֵ���ƶ�
		while (j >= 0 && arr[j] > value)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		// ��ѭ��ǰj--����Ҫ�����λ�ã���Ҫȡ [j + 1] λ��
		arr[j + 1] = value;
	}
}

/**
 * 04_ϣ������
 *		1) �Ľ���ֱ�Ӳ�������
 *		2) �����˷��顣���������з��飬������ʹ��ֱ�Ӳ�������
 *		3) ���ڵ�ֱ�Ӳ���������ǰһ��Ԫ�أ��ӹ̶��ƶ�1����Ϊָ������
 */
void shellSort(int *arr, int length) 
{
	int srcLength = length;
	while (length > 0) 
	{
		// ������ʽ�����۰�
		length /= 2;
		// ��һ�㣬�Ƿ��飬ÿ��ִ�в�������
		for (int i = 0; i < length; i++)
		{
			//	ÿ��ӵڶ���Ԫ�ؿ�ʼ��������ȷ�������Ԫ��
			for (int j = i + length; j < srcLength; j += length)
			{
				// ����Ĵ�����Ԫ��
				int value = arr[j];
				// �����������һ��Ԫ�ص�λ��
				int k = j - length;

				/*for (; k >= 0 && value < arr[k]; k -= length) {
					arr[k + length] = arr[k];
				}*/
				// �Ӻ���ǰ��������ڴ�����ֵ�����ֵ����ƶ�
				while (k >= 0 && arr[k] > value)
				{
					arr[k + length] = arr[k];
					// ��������ǰ�ƶ�
					k -= length;
				}
				// ��ѭ��ǰ��k��ȥlength���������������λ�ã���Ҫ����length
				arr[k + length] = value;
			}
		}
	}
}

/**
 * 05_��������
 *		��ʼ���ã���0��length - 1
 */
void quickSort(int* arr, int start, int end)
{
	if(start < end) {
		// ѡ��׼ֵ
		int baseNum = arr[start];
		// ��¼�м�ֵ
		int tempNum;
		// ��ʼ�ͽ��������ڵ���
		int i = start;
		int j = end;
		while (i < j)
		{
			// ����ʼ�Ҵ����ڻ�׼ֵ���±�
			while (arr[i] < baseNum && i < end)
			{
				i++;
			}
			// ���ұ߿�ʼ��С�ڻ�׼ֵ���±�
			while (arr[j] > baseNum && j > start)
			{
				j--;
			}
			if (i <= j)
			{
				// ����ֵ��������λ�����ʱ���û���
				if (i < j)
				{
					swapInt(arr, i, j);
				}
				// ����һ��λ�ÿ�ʼ������
				i++;
				j--;
			}
		}
		// ���õݹ飬��ʼ����
		if (start < j)
		{
			quickSort(arr, start, j);
		}
		if (end > i)
		{
			quickSort(arr, i, end);
		}
	}
}

/**
 * 06_������
 *		1. �󶥶ѵ����ԣ����ڵ�������������ӽڵ��ֵ�������ڴ�С�������򡣷�֮С���ѡ�
 *		2. ����һ����ȫ��������ֻ��Ҫ���ڵ㣬�Ϳ�������ȫ������������֪�����ӽڵ�
 *		3. ��������ͨ��������Ҷ�ӽڵ㣬�����ֵ�滻�����ڵ㣬���滻���Ѷ���
 *		4. �Ѷ�Ԫ���滻�����һ��Ҷ�ӽڵ㣬��ɸô����ֵ��ѡȡ����һ�ι����Ѿ���������Ҷ�ӽڵ㡣
 *		5. �ѵĹ���ͨ��ѭ����ʵ�ּ򵥣�����������һ����Ҷ�ӽڵ㵽�Ѷ�����������ѡ��������Ч���ֵ��
 *		6. �ѵ���ع�ʽ��
 *			1) ���һ����Ҷ�ӽڵ㣺
 *					a. �ڵ��� / 2 - 1;
 *					b. (���һ���ڵ��±� - 1) / 2;
 *			2) ����һ���ڵ��±�n��
 *					a. ���ӣ�2n + 1;
 *					b. �Һ��ӣ�2(n + 1);
 *			3) �жϽڵ��Ƿ���Ҷ�ӽڵ�
 *					a. ��������� 2n + 1 < length
 *					b. �����Ҷ�ӽڵ�
 */	
void heapSort(int* arr, int length)
{
	// �����������֤���ֵ�ܱ�ѡ��0λ��
	for (int last = length -1; last >= 0; last--)
	{
		buildTopMaxHeap(arr, last);
		// �����Ѷ��Ͷ�β����β����
		swapInt(arr, 0, last);
	}
}

/**
 * ��������±�0��lastIndexλ�õ�������Ϊ�󶥶ѡ�
 */
inline void buildTopMaxHeap(int* arr, int lastIndex)
{
	// �ҵ����һ����Ҷ�ӽڵ���±�
	int lastNonLeaf = (lastIndex - 1) / 2;
	for (int curIndex = lastNonLeaf; curIndex >= 0; curIndex--)
	{
		// ���������
		if (curIndex * 2 < lastIndex)
		{
			// �溢�ӽڵ���ֵ�����һ�����±�
			int biggerIndex = curIndex * 2 + 1;

			// ���Һ��Ӵ��ڣ����Һ���ֵ�������滻Ϊ�Һ��ӵ��±�
			if (biggerIndex < lastIndex && arr[biggerIndex] < arr[biggerIndex + 1])
			{
				biggerIndex++;
			}
			// ��֤���ڵ����
			if (arr[curIndex] < arr[biggerIndex])
			{
				swapInt(arr, curIndex, biggerIndex);
			}
		}
	}
}
