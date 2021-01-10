#pragma once
#include <stdio.h>
#include <stdlib.h>

// ��������
void inputArray(int* arr, int length);

// ��������
void traverseArray(int* arr, int length);
// ��������λ�õ�����ֵ
void swapInt(int* arr, int index1, int index2);

// 01_ð������
void bubbleSort(int* arr, int length);
// 02_ѡ������
void selectSort(int* arr, int length);
// 03_��������
void insertSort(int* arr, int length);
// 04_ϣ������
void shellSort(int* arr, int length);
// 05_��������
void quickSort(int* arr, int start, int end);

// ������Ľ�������ѭ���嶨��
void heapSort(int* arr, int length);
void buildTopMaxHeap(int* arr, int lastIndex);

// �鲢����ĵݹ���ϲ�����
void mergeSort(int* arr, int length, int left, int right, int* tempArr);
void merge(int* arr, int left, int middle, int right, int* tempArr);

// ��������ķ���
void testSort();