#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

bool CreateQueue(Queue *queue, int size){
    //Cannot create a queue whose size is negative
    if(size <= 0)
        return false;

    //Allocate memory
    queue -> values = (double*)malloc(sizeof(double)*size);
    queue -> front = 0;
    queue -> rear = -1;
    queue -> counter = 0;
    queue -> maxSize = size;
    return true;
}

bool IsEmpty(Queue *queue){
    //Use counter to check empty
    if(queue -> counter == 0)
        return true;
    return false;
}

bool IsFull(Queue *queue){
    //Use counter to check full
    if(queue -> counter == queue -> maxSize)
        return true;
    return false;
}

bool Enqueue(Queue *queue, double x){
    //Check the queue is full or not
    if(IsFull(queue)){
        //Warn that the queue is already full
        printf("Error: the queue is full\n");
        return false;
    }

    //When not full, proceed enqueue
    queue -> rear = (queue -> rear + 1) % queue -> maxSize;//Calculate the index use modulo
    queue -> values[queue -> rear] = x;//Assign x to the value
    queue -> counter++;
    return true;
}

bool Dequeue(Queue *queue, double *x){
    //Check the queue is empty or not
    if(IsEmpty(queue))
        return false;

    *x = queue -> values[queue -> front];//Store the value to x
    queue -> front = (queue -> front + 1) % queue -> maxSize;//Calculate the index use modulo
    queue -> counter--;
    return true;
}

void DisplayQueue(Queue *queue){
    //Print the queue from front
    for(int i = 0; i < queue -> counter; i++){
        //Use currIndex to indicate the index after modulo
        int currIndex = ((queue -> front + i)) % (queue -> maxSize);

        //Check is front or not
        if(currIndex == queue -> front){
            printf("front-->\t");
        }else{
            printf("\t\t");
        }

        //Common situation
        printf("%g", queue -> values[currIndex]);

        //Check is rear or not
        if(currIndex == queue -> rear){
            printf("\t<--rear\n");
        }else{
            printf("\n");
        }
    }
}

void DestroyQueue(Queue *queue){
    //Free all the values
    free(queue -> values);
}