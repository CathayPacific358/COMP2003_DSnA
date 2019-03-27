#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int *a, int n){
    int i, p, key;
    //Set key starts from the second element of the array and compare it with for former one
    for(p = 1; p < n; p++){
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

void Merge(int *a, int left, int centre, int right){
    int i1, i2, i, b[100000];

    i1 = left;
    i2 = centre + 1;
    i = left;

    while(i1 <= centre && i2 <= right){
        //Compare the element in two sub arrays
        if(a[i1] < a[i2]){
            b[i++] = a[i1++];
        }else{
            b[i++] = a[i2++];
        }
    }
    //Place the former sorted part into B
    while(i1 <= centre){
        b[i++] = a[i1++];
    }
    //Place the latter sorted part into B
    while(i2 <= right){
        b[i++] = a[i2++];
    }
    //Copy b to a
    for(int  n=left ; n <= right; n++){
        a[n] = b[n];
    }
}

void MergeSort(int *a, int left, int right){

    if(left >= right)
        return;

    int centre = (left + right) / 2;
    MergeSort(a, left, centre);
    MergeSort(a, centre + 1, right);
    Merge(a, left, centre, right);
}

int main(){
    int *a, *b;
    clock_t startInsertionSort, finishInsertionSort, startMergeSort, finishMergeSort;
    //Allocate memory
    a = (int*) malloc(sizeof(int)*100000);
    b = (int*) malloc(sizeof(int)*100000);

    //Randomly set array A
    printf("arrA: ");
    for(int i = 0; i < 100000; i++){
        a[i] = rand()%101;
        printf("%d ", a[i]);
    }

    printf("\n");

    //Copy array A to B
    printf("arrB: ");
    for(int m = 0; m < 100000; m++){
        b[m] = a[m];
        printf("%d ", b[m]);
    }

    printf("\n");

    //InsertionSort and time check
    startInsertionSort = clock();
    InsertionSort(a, 100000);
    finishInsertionSort = clock();

    //Print the result after InsertionSort
    printf("arrA used InsertionSort: ");
    for(int i = 0; i < 100000; i++){
        printf("%d ", a[i]);
    }

    printf("\n");

    //MergeSort and time check
    startMergeSort = clock();
    MergeSort(b, 0, 99999);
    finishMergeSort = clock();

    //Print the result after MergeSort
    printf("arrB used MergeSort: ");
    for(int i = 0; i < 100000; i++){
        printf("%d ", b[i]);
    }

    printf("\n");

    //Print the result of elapsed time
    printf("Elapsed time for InsertionSort: %ld\n", finishInsertionSort - startInsertionSort);
    printf("Elapsed time for MergeSort: %ld", finishMergeSort - startMergeSort);
}