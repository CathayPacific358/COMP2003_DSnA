#include <stdio.h>
#include "Insertion&Quick&HeapSort.h"

/* InsertionSort */
void InsertionSort(int *a, int left, int n){
    int i, p, key;
    //Set key starts from the second element of the array and compare it with for former one
    for(p = left + 1; p < n; p++){
        key = a[p];
        i = p - 1;

        //Move elements of a[0..p-1] that are greater than the key to one position ahead of their current position
        while(i >= 0 && a[i] > key){
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

/* QuickSort */
//Function to use median of 3 strategy
void Median3(int *a, int left, int right){
    int temp, centre = (left + right) / 2;

    if(a[left] > a[right]){
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;
    }

    if(a[right] < a[centre]) {
        temp = a[right];
        a[right] = a[centre];
        a[centre] = temp;
    }

    if(a[left] > a[centre]){
        temp = a[left];
        a[left] = a[centre];
        a[centre] = temp;
    }

    //Swap the pivot to the second last position
    temp = a[centre];
    a[centre] = a[right - 1];
    a[right - 1] = temp;
}

//Function use to swap elements
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to take the array apart and move according to pivot
int Partition(int *a, int left, int right){
    Median3(a, left, right);
    int i = left + 1, j = right - 2, pivot = a[right - 1];

    while(true) {
        //When i part is smaller than pivot, check next
        while (a[i] < pivot) {
            i++;
        }
        //When j part is bigger than pivot, check previous
        while (a[j] > pivot) {
            j--;
        }
        //Swap a[i] and a[j]
        if (i < j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        } else {
            break;
        }
    }
    swap(&a[i], &a[right - 1]);
    return i;//Return the last position
}

//Function to proceed hybrid quick sort
void QuickSort(int *a, int left, int right){
    //When the data amount is less then 10, use insertion sort
    if(left >= right - 10){
        InsertionSort(a, left, right);
        return;
    }
    //Proceed quick sort
    int q = Partition(a, left, right);
    QuickSort(a, left, q - 1);
    QuickSort(a, q + 1, right);
}

/* HeapSort */
int DeleteMax(int *a, int size) {
    int max = a[0], hole = 0, x = a[--size], sid;

    if(hole > size){
        return 0;
    }

    //When have children
    while((2 * hole + 1) < size && (2 * hole + 2) < size){
        //Sid is the index of bigger one
        if(a[(2 * hole + 1)] > a[(2 * hole + 2)]){
            sid = 2 * hole + 1;
        }else{
            sid = 2 * hole + 2;
        }

        if(x >= a[sid]){
            break;
        }
        a[hole] = a[sid];
        hole = sid;
    }

    a[hole] = x;
    return max;
}

bool Insert(int *a, int size, int x) {
    int hole = size;
    //When have hole and the value in hole is bigger than its parent
    while (hole > 0 && x >= a[(hole - 1) / 2]) {
        a[hole] = a[(hole - 1) / 2];
        hole = (hole - 1) / 2;
    }
    a[hole] = x;
    return true;
}

void HeapSort(int *a, int size){
    for(int i = 0; i < size - 1; i++){
        Insert(a, i, a[i]);
    }
    for(int i = size - 1; i > 0; i--){
        a[i] = DeleteMax(a, i + 1);
    }
}