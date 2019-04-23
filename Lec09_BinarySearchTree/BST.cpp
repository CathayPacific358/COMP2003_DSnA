#include "BST.h"
#include "stdlib.h"

Node* insertNode(Node **proot, int x){
    // if the value already exists, insertion abort
    if(findNode(*proot, x) != NULL){
        return NULL;
    }
    // if it is empty, create a tree
    // else, use recursion to compare
    if(*proot == NULL){
        *proot = (Node*)malloc(sizeof(Node));
        (*proot) -> key = x;
        (*proot) -> left = NULL;
        (*proot) -> right = NULL;
        return *proot;
    }else if(x <= (*proot) -> key){
        (*proot) -> left = insertNode(&((*proot) -> left), x);
    }else{
        (*proot) -> right = insertNode(&((*proot) -> right), x);
    }
    return *proot;
}

Node* deleteNode(Node **proot, int x){
    Node *currNode = *proot;
    Node *parent = *proot;

    while(currNode -> key != x){
        parent = currNode;
        if(x > currNode -> key){
            currNode = currNode -> right;
        }else{
            currNode = currNode -> left;
        }
    }
    // For no child
    if(currNode -> left == NULL && currNode -> right == NULL){
        if(x == parent -> right -> key){
            parent -> right = NULL;
        }else if(x == parent -> left -> key){
            parent -> left = NULL;
        }
        return currNode;
    }

    //For one child
    //If child is on the left
    if(currNode -> right == NULL && currNode -> left != NULL){
        //The current node is the left one of the parent
        if(parent -> left == currNode){
            parent -> left = currNode -> left;
        }
        //The current node is the right one of the parent
        else if(parent -> right == currNode){
            parent -> right = currNode -> left;
        }
        //The current node is the root
        else{
            *proot = currNode -> left;
        }
        return currNode;
    }
    //If child is on the right
    else if(currNode -> right != NULL && currNode -> left == NULL){
        //The current node is the right one of the parent
        if(parent -> right == currNode){
            parent -> right = currNode -> right;
        }
        //The current node is the left one of the parent
        else if(parent -> left == currNode){
            parent -> left = currNode -> left;
        }
        //The current node is the root
        else{
            *proot = currNode -> right;
        }
        return currNode;
    }

    //For two children
    if(currNode -> left != NULL && currNode -> right != NULL){
        Node *temp = currNode -> right;
        //Find the minimum value from the right subtree
        while(temp -> left != NULL){
            parent = temp;//Mart the parent of the minimum value
            temp = temp -> left;//Find the minimum value
        }
        currNode -> key = temp -> key;//Assign the key of minimum to the node that should be deleted
        parent -> left = temp -> right;//Connect the tree after delete
        return temp;
    }
}

Node* findNode(Node *root, int x){

    if(root == NULL){
        return NULL;
    }
    if(root -> key == x){
        return root;
    }
    if(root -> key > x){
        return findNode(root -> left, x);
    }

	return findNode(root -> right, x);
}

void destroyTree(Node *root){
    if(root == NULL){
        return;
    }
    if(root -> left != NULL){
        destroyTree(root -> left);
    }
    if(root -> right != NULL){
        destroyTree(root -> right);
    }
    free(root);
}