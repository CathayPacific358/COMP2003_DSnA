#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

//To create a stack whose capacity is size
bool CreateStack(Stack* stack, int size){
    if(size <= 0){
        return false;
    }
    //Allocate memory
    stack -> values = (double*)malloc(sizeof(double)*size);
    stack -> top = -1;//The index starts from 0
    stack -> maxTop = size - 1;//The index starts from 0
    return true;
}

//Allocate memory
bool IsEmpty(Stack *stack){
    if(stack -> top < 0)
        return true;
    return false;
}

//Check if the stack is full
bool IsFull(Stack *stack){
    if(stack -> top == stack -> maxTop)
        return true;
    return false;
}

//Passes the value of the top element to x
bool Top(Stack *stack, double *x){
    if(IsEmpty(stack))
        return false;
    *x = stack->values[stack->top];//Use *x because the value cannot be directly assigned
    return true;
}

//To add element into the stack
bool Push(Stack *stack, double x){
    //A full stack cannot be added any elements
    if(IsFull(stack))
        return false;
    stack -> values[++stack -> top] = x;//Make stack +1 become the top
    return true;
}

//Passes the value of the top element to x and delete the top element
bool Pop(Stack *stack, double *x){
    if(IsEmpty(stack))
        return false;
    *x = stack -> values[stack -> top];//Pass the value
    stack -> top--;//Move the pointer downward
    return true;
}

//Print out the whole stack
void DisplayStack(Stack *stack){
    for(int i = stack -> top; i >= 0; i--){
        if(i == stack -> top){
            printf("top -->\t");
        }else{
            printf("\t");
        }
        printf("|\t%g\t|\n", stack -> values[i]);
    }
}

//Free the memory
void DestroyStack(Stack *stack){
    free(stack -> values);
    stack -> top = -1;
}