#include <stdio.h>
#include <stdlib.h>
#include "Insertion&Quick&HeapSort.h"
#include <time.h>

int main(){
    int *a, *b;
    //clock_t startInsertionSort, finishInsertionSort, startMergeSort, finishMergeSort;
    //Allocate memory
    a = (int*) malloc(sizeof(int)*100000);
    b = (int*) malloc(sizeof(int)*100000);

    //Randomly set array A
    printf("arrA: ");
    for(int i = 0; i < 100000; i++){
        a[i] = rand()%101;
        printf("%d ", a[i]);
    }

    //Randomly set array B
    printf("arrB: ");
    for(int j = 0; j < 100000; j++){
        b[j] = rand()%101;
        printf("%d ", b[j]);
    }

    printf("\n");

    clock_t qStart, qEnd, hStart, hEnd;

    qStart = clock();
    QuickSort(a, 0, 100000);
    qEnd = clock();

    hStart = clock();
    HeapSort(b, 100000);
    hEnd = clock();


    //Print array A after quick sort
    printf("arrA used QuickSort: ");
    for(int i = 0; i < 100000; i++){
        printf("%d ", a[i]);
    }

    //Print array B after heap sort
    printf("arrB used HeapSort: ");
    for(int j = 0; j < 100000; j++){
        printf("%d ", b[j]);
    }

    printf("\n");
    printf("Time for QuickSort is: %d\n", qEnd - qStart);
    printf("Time for HeapSort is: %d\n", hEnd - hStart);
}