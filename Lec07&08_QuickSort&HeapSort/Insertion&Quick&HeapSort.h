#include <stdio.h>

//InsertionSort
void InsertionSort(int *a, int left, int n);

//QuickSort
void QuickSort(int *a, int left, int right);
int Partition(int *a, int left, int right);
void swap(int *a, int *b);
void Median3(int *a, int left, int right);

//HeapSort
int DeleteMin(int *a, int size);
bool Insert(int *a, int size, int x);
void HeapSort(int *a, int size);