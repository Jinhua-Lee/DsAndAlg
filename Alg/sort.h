#pragma once
#include <stdio.h>
#include <stdlib.h>

// 输入数组
void inputArray(int* arr, int length);

// 遍历数组
void traverseArray(int* arr, int length);
// 交换索引位置的两个值
void swapInt(int* arr, int index1, int index2);

// 01_冒泡排序
void bubbleSort(int* arr, int length);
// 02_选择排序
void selectSort(int* arr, int length);
// 03_插入排序
void insertSort(int* arr, int length);
// 04_希尔排序
void shellSort(int* arr, int length);
// 05_快速排序
void quickSort(int* arr, int start, int end);

// 堆排序的建堆与主循环体定义
void heapSort(int* arr, int length);
void buildTopMaxHeap(int* arr, int lastIndex);

// 归并排序的递归与合并定义
void mergeSort(int* arr, int length, int left, int right, int* tempArr);
void merge(int* arr, int left, int middle, int right, int* tempArr);

// 测试排序的方法
void testSort();