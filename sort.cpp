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
	printf("请输入数组长度 length：\n");
	int length;
	scanf_s("%d", &length);
	int* arr = new int[length];

	inputArray(arr, length);
	printf("-------排序-------\n");
	printf("排序前： \n");
	traverseArray(arr, length);

	//bubbleSort(arr, length);
	//selectSort(arr, length);
	//insertSort(arr, length);
	//shellSort(arr, length);
	//quickSort(arr, 0, length - 1);
	heapSort(arr, length);

	printf("排序后： \n");
	traverseArray(arr, length);
}

void inputArray(int *arr, int length)
{
	printf("请输入int类型数组，空格隔开：\n");
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
 * 交换int数组的两个位置的值
 */
void swapInt(int* arr,  int index1,  int index2) {
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

/**
 * 01_冒泡排序法
 *      1) 每轮会选出最大的元素到末端
 *      2) 改进：增加一个变量标记该轮是否有交换过元素，若没有交换，则已经排好序
 */
void bubbleSort(int *arr, int length)
{
	// 外层表示循环次数，循环 length - 1次
	for (int i = 0; i < length - 1; i++)
	{
		// 该轮是否排交换过的标志变量，若没改变，则表示没进行过交换，已经排好
		bool swap = false;
		// 每一轮排序（外层），会将大的值排到数组末端， 所以内层每轮到的数组位置是越来越小（length - i - 1）
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
 * 02_简单选择排序
 */
void selectSort(int* arr, int length)
{
	// 外层循环：i即可表示，如果产生小值要放入的位置。
	for (int i = 0; i < length; i++)
	{
		int value = arr[i];
		int position = i;
		for (int j = i + 1; j < length; j++)
		{
			// 选出小的值，记录小值的位置
			if (arr[j] < value)
			{
				value = arr[j];
				position = j;
			}
		}
		// 交换最小值和当前外层遍历的位置
		arr[position] = arr[i];
		arr[i] = value;
	}
}

/**
 * 03_直接插入排序
 */
void insertSort(int* arr, int length)
{
	int value;
	// 外层从1开始，第一个数不用插入
	for (int i = 1; i < length; i++)
	{
		// 缓存当前值
		value = arr[i];
		// j是从后向前的，每次设置初始值为i的前一个
		int j = i - 1;
		// 大于当前待插入的值才移动
		while (j >= 0 && arr[j] > value)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		// 出循环前j--，则要插入的位置，需要取 [j + 1] 位置
		arr[j + 1] = value;
	}
}

/**
 * 04_希尔排序
 *		1) 改进的直接插入排序；
 *		2) 增加了分组。按增量进行分组，组内仍使用直接插入排序
 *		3) 组内的直接插入排序找前一个元素，从固定移动1，改为指定步长
 */
void shellSort(int *arr, int length) 
{
	int srcLength = length;
	while (length > 0) 
	{
		// 增量公式，简单折半
		length /= 2;
		// 第一层，是分组，每组执行插入排序
		for (int i = 0; i < length; i++)
		{
			//	每组从第二个元素开始，按增量确定该组的元素
			for (int j = i + length; j < srcLength; j += length)
			{
				// 该组的待插入元素
				int value = arr[j];
				// 有序序列最后一个元素的位置
				int k = j - length;

				/*for (; k >= 0 && value < arr[k]; k -= length) {
					arr[k + length] = arr[k];
				}*/
				// 从后往前，如果大于待插入值，则该值向后移动
				while (k >= 0 && arr[k] > value)
				{
					arr[k + length] = arr[k];
					// 按步长向前移动
					k -= length;
				}
				// 出循环前，k减去length，所以真正插入的位置，需要加上length
				arr[k + length] = value;
			}
		}
	}
}

/**
 * 05_快速排序
 *		初始调用，从0到length - 1
 */
void quickSort(int* arr, int start, int end)
{
	if(start < end) {
		// 选基准值
		int baseNum = arr[start];
		// 记录中间值
		int tempNum;
		// 开始和结束，用于迭代
		int i = start;
		int j = end;
		while (i < j)
		{
			// 从左开始找大于于基准值的下标
			while (arr[i] < baseNum && i < end)
			{
				i++;
			}
			// 从右边开始找小于基准值的下标
			while (arr[j] > baseNum && j > start)
			{
				j--;
			}
			if (i <= j)
			{
				// 两个值做交换（位置相等时候不用换）
				if (i < j)
				{
					swapInt(arr, i, j);
				}
				// 从下一个位置开始继续找
				i++;
				j--;
			}
		}
		// 利用递归，开始分治
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
 * 06_堆排序
 *		1. 大顶堆的特性：父节点大于任意两个子节点的值，可用于从小到大排序。反之小顶堆。
 *		2. 堆是一个完全二叉树，只需要父节点，就可以由完全二叉树的特性知道其子节点
 *		3. 堆排序是通过遍历非叶子节点，将大的值替换到父节点，逐步替换到堆顶。
 *		4. 堆顶元素替换到最后一个叶子节点，完成该次最大值的选取。下一次构建堆就舍弃最后的叶子节点。
 *		5. 堆的构建通过循环来实现简单，但必须从最后一个非叶子节点到堆顶，这样才能选出当次有效最大值。
 *		6. 堆的相关公式：
 *			1) 最后一个非叶子节点：
 *					a. 节点数 / 2 - 1;
 *					b. (最后一个节点下标 - 1) / 2;
 *			2) 任意一个节点下标n：
 *					a. 左孩子：2n + 1;
 *					b. 右孩子：2(n + 1);
 *			3) 判断节点是否有叶子节点
 *					a. 如果有左孩子 2n + 1 < length
 *					b. 如果有叶子节点
 */	
void heapSort(int* arr, int length)
{
	// 反向遍历，保证最大值能被选到0位置
	for (int last = length -1; last >= 0; last--)
	{
		buildTopMaxHeap(arr, last);
		// 交换堆顶和堆尾，堆尾脱落
		swapInt(arr, 0, last);
	}
}

/**
 * 将数组从下标0到lastIndex位置的数构建为大顶堆。
 */
inline void buildTopMaxHeap(int* arr, int lastIndex)
{
	// 找到最后一个非叶子节点的下标
	int lastNonLeaf = (lastIndex - 1) / 2;
	for (int curIndex = lastNonLeaf; curIndex >= 0; curIndex--)
	{
		// 如果有左孩子
		if (curIndex * 2 < lastIndex)
		{
			// 存孩子节点中值更大的一个的下标
			int biggerIndex = curIndex * 2 + 1;

			// 若右孩子存在，且右孩子值更大，则替换为右孩子的下标
			if (biggerIndex < lastIndex && arr[biggerIndex] < arr[biggerIndex + 1])
			{
				biggerIndex++;
			}
			// 保证父节点更大
			if (arr[curIndex] < arr[biggerIndex])
			{
				swapInt(arr, curIndex, biggerIndex);
			}
		}
	}
}
