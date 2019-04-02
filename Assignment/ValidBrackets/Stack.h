#include <stdio.h>

typedef struct {
    char *values;
    int top;
    int maxTop;
} Stack;

/* To create an empty stack whose capacity is size*/
bool CreateStack(Stack *stack, int size);

/* Check if the stack is empty
 * Returns true if the stack is empty and false otherwise*/
bool IsEmpty(Stack *stack);

/* Check if the stack is full
 * Returns true if the stack is empty and false otherwise*/
bool IsFull(Stack *stack);

/* Passes the value of the top element to x
 * Returns true if the operation is successful and false otherwise*/
bool Top(Stack *stack, char *x);

/* Add a new element with value x to the top of the stack
 * Returns true if the operation is successful and false otherwise*/
bool Push(Stack *stack, char x);

/* Remove an element from the top of the stack
 * Returns true if the operation is successful and false otherwise
 * Passes the value of the top element to x*/
bool Pop(Stack *stack);

void DisplayStack(Stack *stack);

/* Frees the memory occupied by the stack*/
void DestroyStack(Stack *stack);