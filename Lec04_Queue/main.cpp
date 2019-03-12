#include <stdio.h>
#include "queue.h"

int main(void) {
    Queue queue;
    double value;
    CreateQueue(&queue, 5);
    puts("Enqueue 5 items.");
    for (int x = 0; x < 5; x++)
        Enqueue(&queue, x);
    puts( "Now attempting to enqueue again...");
    Enqueue(&queue, 5);
    DisplayQueue(&queue);
    Dequeue(&queue, &value);
    printf("Retrieved element = %g\n", value);
    DisplayQueue(&queue);
    Enqueue(&queue, 7);
    DisplayQueue(&queue);
    DestroyQueue(&queue);
}