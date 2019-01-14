#include "list.h"
#include <stdio.h>
#include <stdlib.h>

//Main function for testing
int main(){
    //Create a list
    Node *head = 0;

    //Add elements to the list
    for(int i = 0; i < 5; i++)
        InsertNode(&head, i, i);
    DisplayList(head);

    //Test InsertNode() by inserting node from index 0
    for(int i = 0; i < 5; i++)
        InsertNode(&head, 0, i);
    DisplayList(head);

    //Test FindNode()
    for(int i = 0; i <= 6; i += 2){
        int index = FindNode(head, i);
        if(index > 0)
            printf("%d is at position %d.\n", i, index);
        else
            printf("%d is not in the list.\n", i);
    }

    //Test DeleteNode()
    DeleteNode(&head, 0);
    DisplayList(head);

    //Destroy the list
    DestroyList(head);
}


//Check the list is empty or not
bool IsEmpty(Node *head){
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

//Insert a node after a specific index
Node *InsertNode(Node **phead, int index, double x){
    //Check whether the input index is valid
    if(index < 0){
        return NULL;
    }

    //To locate the value
    int currIndex = 1;
    Node *currNode = *phead;

    while(currNode && index > currIndex){
        currNode = currNode -> next;
        currIndex++;
    }

    //If does not exist, return null
    if(index > 0 && currNode == 0){
        return 0;
    }

    //Create a new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = x;

    //Insert as new head or after currNode
    if(index == 0) {
        newNode->next = *phead;
        *phead = newNode;
    }else{
        newNode -> next = currNode -> next;
        currNode -> next = newNode;
    }

    return newNode;
}

//Find a node with certain data
int FindNode(Node *head, double x){
    Node *currNode = head;
    int currIndex = 1;

    while(currNode -> data != x){
        if(currNode -> next == NULL){
            return 0;
        }else{
            currNode = currNode -> next;
            currIndex++;
        }
    }
    return currIndex;
}

//Delete a node with certain data
int DeleteNode(Node **phead, double x){
    Node *currNode = *phead;
    Node *delNode;
    int currIndex = 1;

    if(currNode -> data == x){
        *phead = currNode -> next;
        free(currNode);
        return currIndex;
    }else{
        currIndex += 1;//Plus one because already processing the next node
        while(currNode -> next -> data != x){
            if(currNode -> next -> data != NULL){
                currNode = currNode -> next;
                currIndex++;
            }else{
                return 0;//No result
            }
        }
        delNode = currNode -> next;//currNode -> next is the wanted node
        currNode -> next = currNode -> next -> next;
        free(delNode);//Delete the node
        return currIndex;
    }
}

//Print all the data of the list
void DisplayList(Node *head){
    Node* currNode = head;

    if(IsEmpty(head)){
        printf("The list is empty\n");
    }else{
        while(currNode != NULL){
            printf("%lf\n", currNode -> data);
            currNode = currNode -> next;
        }
    }
}

//Destroy the list
void DestroyList(Node *head){
    Node *currNode = head;
    Node *delNode = head;

    if(IsEmpty(head)){
        printf("The list is empty\n");
    }else{
        while(currNode != NULL){
            delNode = currNode;
            currNode = currNode -> next;
            free(delNode);
        }
    }
}