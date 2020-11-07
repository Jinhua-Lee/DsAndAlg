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
inline void mergeSort(int* arr, int length, int left, int right, int* tempArr);
inline void merge(int* arr, int left, int middle, int right, int* tempArr);

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
	//heapSort(arr, length);
	// ����ռ������С����ԭ�ռ��С
	int* tempArr = new int[length];
	mergeSort(arr, length, 0, length - 1, tempArr);

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
 *		1) ��ʼ���ã���0��length - 1
 *		2) ��׼ֵѡȡ�����ַ�ʽ��
 *			a. ѡstart�±�λ��Ԫ�ػ�endλ�õ�Ԫ�� -> �ײ������ʵķָ�
 *			b. ѡstart��end��Χ�����λ�õ�Ԫ�� -> ���ײ������ʵķָ�
 *			c. ѡstart, end, (end - start) / 2������λ��Ԫ���У�ֵ��С�����м��Ԫ�� -> �����ֵ���һ��ʱ��
 */
void quickSort(int* arr, int start, int end)
{
	if(start < end) {
		srand(time_t(NULL));
		// ѡ��׼ֵ����ȡ�����ʽ
		int baseNum = arr[start + rand() % (end - start)];
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
				// ����ֵ��������λ�����ʱ���û�����֤�ȶ��ԣ�
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
void buildTopMaxHeap(int* arr, int lastIndex)
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

/**
 * 07_�鲢����
 *		1) ���õݹ飬������������������ϲ���
 *		2) ����������Ԫ�ض�����1ʱ���ٷֱ����������ٻ���Ϊ�������飻
 *		3) �ݹ鵽ÿ�������СΪ1ʱ�򣬿�ʼ���ݣ�
 *		4) ��������һ��ʼ�������洴�������ٵݹ��д���������
 */
void mergeSort(int* arr, int length, int left, int right, int *tempArr)
{
	// ������Ԫ�ز�Ϊ1ʱ�򣬼������֣�������Խ��й鲢
	if (left != right)
	{
		int middle = (left + right) / 2;
		// �ֱ������������ߣ��ٹ鲢����
		mergeSort(arr, length, left, middle, tempArr);
		mergeSort(arr, length, middle + 1, right, tempArr);
		merge(arr, left, middle, right, tempArr);
	}
	
}

/**
 * ����������������������ϲ�Ϊһ����������ķ���
 *		1) middle�����ָ������������飬��λ�õ�Ԫ��������߻��ұߣ��鲢��Ҫ���������ͨ�����ڳ�����������ȡ��������Ϊ���ڵ�һ������;
 *		2) ��Ҫ���������ռ� right -left + 1�����ڸö���ռ���ÿ�ι鲢ֻʹ��һ�Σ��ҹ鲢�������ԭ�����С�����Դ�Сֱ�ӷ���Ϊԭ�����С���ڵݹ��ⲿ����;
 *		3) ÿ�ι鲢�ź�������ԭ����λ�á�
 *		4) �鲢���ѵ����ڽ��������кϲ�Ϊһ���������У��˴���Ҫ��������̣��������׵��������±�Խ�磺
 *			a. �����߶���ֵ��ʱ�򣬽�ֵ�ȽϺ�һ�����뻺�����飻
 *			b. ִ���������ѭ����ֻ��һ����ֵ�ˣ�����һ��ʣ�µ�λ������ȫ���ŵ�����������ŵ�λ�á�
 */
void merge(int* arr, int left, int middle, int right, int* tempArr)
{
	// �ֱ���������飬�ұ����飬����������α�
	int i = left;
	int j = middle + 1;
	int k = left;
	// �����������������ֶ�����ֵ
	while (i <= middle && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			tempArr[k++] = arr[i++];
		}
		else
		{
			tempArr[k++] = arr[j++];
		}
	}
	// ִ������һ��ѭ����ֻ��һ�߻���ֵ���в�����ȫ���������α�ŵ�����������
	while (i <= middle)
	{
		tempArr[k++] = arr[i++];
	}
	while (j <= right)
	{
		tempArr[k++] = arr[j++];
	}
	// �����������ֵ�ŵ�ԭ����λ��
	for (i = left; i <= right; i++)
	{
		arr[i] = tempArr[i];
	}
}