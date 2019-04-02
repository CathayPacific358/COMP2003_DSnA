#include <stdio.h>
#include "list.h"

int main() {
    Node *head = 0;
    for(int i=0; i<5; i++)
        InsertNode(&head, i, i);
    printf("Before reverse\n");
    DisplayList(head);
    InverseNodes(&head);//Test InverseNodes
    printf("After reverse\n");
    DisplayList(head);

    //Insert duplicates to test RemoveDuplicates
    InsertNode(&head, 5, 0);
    InsertNode(&head, 6, 0);
    InsertNode(&head, 7, 0);
    //InsertNode(&head, 3, 4);
    //InsertNode(&head, 4, 4);
    printf("Before remove duplicates\n");
    DisplayList(head);

    //Remove duplicates
    RemoveDuplicates(&head);
    printf("After remove duplicates\n");
    DisplayList(head);
    printf("\n");

    //Insert 5 more data
    printf("Insert 5 data again\n");
    for(int i=0; i<5; i++)
        InsertNode(&head, 0, i);
    DisplayList(head);
    printf("\n");

    //Print position
    printf("Show position\n");
    for(int i=0; i<7; i+=2){
        int idx = FindNode(head, i);
        if(idx>0)
            printf("%d is at position %d.\n", i, idx);
        else
            printf("%d is not in the list.\n", i);
    }
    printf("\n");

    //Test DeleteNode
    DeleteNode(&head, 0);
    printf("After deleted 0\n");
    DisplayList(head);

    //Destroy
    DestroyList(head);
}