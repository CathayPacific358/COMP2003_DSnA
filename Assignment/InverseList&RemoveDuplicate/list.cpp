#include "list.h"
#include <stdio.h>
#include <stdlib.h>

bool IsEmpty(Node *head){
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

Node* InsertNode(Node** phead, int index, double x){
    //Check whether the input index is valid
    if(index < 0){
        return 0;
    }

    //To locate the value
    int currIndex = 1;
    Node* currNode = *phead;

    while(currNode && index > currIndex){
        currNode = currNode -> next;
        currIndex ++;
    }

    //If does not exist, return NULL
    if(index > 0 && currNode == 0){
        return 0;
    }

    //Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = x;

    //Insert as new head or after currNode
    if(index == 0){
        newNode -> next = *phead;
        *phead = newNode;
    }else{
        newNode -> next = currNode -> next;
        currNode -> next = newNode;
    }

    return newNode;
}

int FindNode(Node *head, double x){
    Node* currNode = head;
    int currIndex = 1;

    if(currNode == NULL){
        return 0;
    }

    while(currNode -> data != x){
        if(currNode -> next == NULL) {
            return 0;
        }else{
            currNode = currNode -> next;
            currIndex++;
        }
    }
    return currIndex;
}

int DeleteNode(Node** phead, double x){
    Node* currNode = *phead;
    Node *delNode;
    int currIndex = 1;
    if(currNode == NULL){
        return 0;
    }
    if(currNode -> data == x){
        *phead = currNode -> next;
        free(currNode);
        return currIndex;
    }else{
        currIndex += 1;
        while(currNode -> next -> data != x){
            if(currNode -> next -> data != NULL){
                currNode = currNode -> next;
                currIndex++;
            }else{
                return 0;
            }
        }
        delNode = currNode -> next;
        currNode -> next = currNode -> next -> next;
        free(delNode);
        return currIndex;
    }
}

void InverseNodes(Node** phead){
    Node* prev = NULL;
    Node* currPTR = *phead;
    Node* next;

    while(currPTR != NULL){
        //Assign the next node to store
        next = currPTR -> next;

        //Link the current node with the previous node
        currPTR -> next = prev;

        //Move the pointer for one position
        prev = currPTR;//Move the prev to current position
        currPTR = next;//Move the current node to next position
    }
    *phead = prev;//Let the last node be head
}

void RemoveDuplicates(Node** phead){
    Node* currPTR = *phead;
    double value;

    while(currPTR != NULL && currPTR -> next != NULL){
        //Assign data to value before it being deleted
        value = currPTR -> data;
        //When the former data equals the latter
        if(currPTR -> data == currPTR -> next -> data){
            //Find the corresponding value and delete all of them
            while(FindNode(*phead, value) != 0) {
                DeleteNode(phead, value);//Delete the node
            }
            currPTR = *phead;//Reset the pointer to the current position

            //If the list is empty, stop the programme
            if(currPTR == NULL){
                return;
            }
        }else{//When not equal, move the pointer to the next
            currPTR = currPTR -> next;
        }
    }
}

void DisplayList(Node* head) {
    Node *currNode = head;

    if (IsEmpty(head)) {
        printf("The list is empty\n");
    } else {
        while (currNode != NULL) {
            printf("%lf\n", currNode -> data);
            currNode = currNode -> next;
        }
    }
}

void DestroyList(Node* head){
    Node* currNode = head;
    Node* delNode = head;

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