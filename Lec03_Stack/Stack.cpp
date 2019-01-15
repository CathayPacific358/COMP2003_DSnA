#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

//To create a stack whose capacity is size
bool CreateStack(Stack *stack, int size){
    //Cannot create a stack whose size is not positive
    if(size <= 0){
        return false;
    }
    //Allocate memory
    stack -> value = (double*)malloc(sizeof(double)*size);
    stack -> top = -1;//The index starts from 0
    stack -> maxTop = size - 1;//The index starts from 0
    return true;
}

//To add element into the stack
bool Push(Stack *stack, double x){
    //A full stack cannot be added any elements
    if(IsFull(stack)) {
        return false;
    }

    stack -> value[++stack -> top] = x;//Make stack + 1 become the top
    return true;
}

//Check if the stack is empty
bool IsEmpty(Stack *stack){
    if(stack -> top < 0) {
        return true;
    }else{
        return false;
    }
}

//Check if the stack is full
bool IsFull(Stack *stack){
    if(stack -> top == stack -> maxTop){
        return true;
    }else{
        return false;
    }
}

//Passes the value of the top element to x
bool Top(Stack *stack, double *x){
    //If the stack if empty, pass nothing
    if(IsEmpty(stack)){
        return false;
    }else{
        *x = stack -> value[stack -> top];
        return true;
    }
}

//Passes the value of the top element to x and delete the top element
bool Pop(Stack *stack, double *x){
    //If the stack is empty, do nothing
    if(IsEmpty(stack)){
        return false;
    }else{
        *x = stack -> value[stack -> top];//Pass the value
        stack -> top--;//Move the pointer downward
        return true;
    }
}

//Print out the whole stack
void DisplayStack(Stack *stack){
    //Print the stack from the top element
    for(int i = stack -> top; i >= 0; i--){
        if(i == stack -> top){
            printf("top -->\t");
        }else{
            printf("\t");
        }
        printf("|\t%f\t|\n", stack -> value[i]);
    }
}

//Free the memory
void DestroyStack(Stack *stack){
    free(stack -> value);
    stack -> top = -1;
}