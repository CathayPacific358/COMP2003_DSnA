#include "AVL.h"
#include "stdlib.h"
#include "stdio.h"

int height(Node *root){
    //Ensure left and right not containing NULL
    //Otherwise, calculation cannot be performed
    if(root == NULL){
        return 0;
    }
    //Output the processed height value
    return root->height;
}

void updateHeight(Node **proot) {
    //It is root itself
    if ((*proot) != NULL) {
        if (!(*proot)->left && !(*proot)->right) {
            (*proot)->height = 0;
        }
        //Pick the bigger one
        else{
            (*proot)->height = (height((*proot)->left) > height((*proot)->right)) ? ((*proot)->height = height((*proot)->left) + 1) : ((*proot)->height = height((*proot)->right) + 1);
        }
    }
}

Node* rightRotate(Node *root){
    Node *newHead = root->left;
    //Duplicate node
    Node *oldHead;
    oldHead = (Node*)malloc(sizeof(Node));
    oldHead->left = NULL;
    oldHead->right = NULL;
    oldHead->key = root->key;
    oldHead->height = 0;
    oldHead->right = root->right;
    updateHeight(&oldHead);
    oldHead->left = newHead->right;
    //Perform swap
    root->right = oldHead;
    root->left = newHead->left;
    root->key = newHead->key;
    updateHeight(&root);
    free(newHead);
}

void leftRotate(Node *root){
    Node *newHead = root->right;
    //Duplicate node
    Node *oldHead;
    oldHead = (Node*)malloc(sizeof(Node));
    oldHead->left = NULL;
    oldHead->right = NULL;
    oldHead->key = root->key;
    oldHead->height = 0;
    oldHead->left = root->left;
    updateHeight(&oldHead);
    oldHead->right = newHead->left;
    //Perform swap
    root->left = oldHead;
    root->right = newHead->right;
    root->key = newHead->key;
    updateHeight(&root);
    free(newHead);
}

int checkBalance(Node *root){
    //Minus to check whether need rebalance
    if(root == NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
}

int isBalance(Node **proot){
    if((*proot) == NULL){
        return 0;
    }else{
        if(height(*proot) == 2 && (*proot)->right == NULL){
            if ((*proot)->left->left == NULL){
                return 2;//LR case
            }
            return 1;//LL case
        }
        if((height(*proot) == 2 && (*proot)->left == NULL)){
            if((*proot)->right->right == NULL){
                return 4;//RL case
            }
            return 3;//RR case
        }
        if(checkBalance(*proot) > 1){
            if((*proot)->left->left == NULL){
                return 2;//LR case
            }
            return 1;//LL case
        }
        if(checkBalance(*proot) < -1){
            if((*proot)->right->right == NULL){
                return 4;//RL case
            }
            return 3;//RR case
        }
    }
}

void rebalance(Node **proot) {
    switch (isBalance(proot)) {
        case 1:
            //The LL case
            rightRotate(*proot);
            break;
        case 2:
            //The LR case
            leftRotate((*proot)->left);
            rightRotate(*proot);
            break;
        case 3:
            //The RR case
            leftRotate(*proot);
            break;
        case 4:
            //The RL case
            rightRotate((*proot)->right);
            leftRotate(*proot);
            break;
        default:
            break;
    }
}

Node* insertNode(Node **proot, int x){
    Node *newNode;
    // if the value already exists, insertion abort
    if(findNode(*proot, x) != NULL){
        return NULL;
    }
    // if it is empty, create a tree
    // else, use recursion to compare
    if(*proot == NULL) {
        *proot = (Node *) malloc(sizeof(Node));
        (*proot)->key = x;
        (*proot)->left = NULL;
        (*proot)->right = NULL;
        (*proot)->height = 0;
        return *proot;
    }else if(x < (*proot)->key){
        newNode = insertNode(&((*proot)->left), x);
    }else{
        newNode = insertNode(&((*proot)->right), x);
    }
    updateHeight(proot);
    rebalance(proot);
    return newNode;
}

Node* deleteMin(Node **proot){
    Node *minNode;
    //Remove and return the minimum node
    //in the sub-tree lead by root
    if((*proot)->left == NULL){
        //Root is the minimum node
        //and it has no left child
        minNode = *proot;
        *proot = (*proot)->right;
        return minNode;
    }
    minNode = deleteMin(&(*proot)->left);
    updateHeight(proot);
    rebalance(proot);
    return minNode;
}

Node* deleteRoot(Node **proot){
    //Remove and retuan the root
    Node *currNode = *proot;
    Node *minNode;
    if(currNode->left == NULL){
        *proot = (*proot)->right;
        return currNode;
    }
    if(currNode->right == NULL){
        *proot = (*proot)->left;
        return currNode;
    }
    //Root has two children
    minNode = deleteMin(&(*proot)->right);
    minNode->left = (*proot)->left;
    minNode->right = (*proot)->right;
    *proot = minNode;
    return currNode;
}

Node* deleteNode(Node **proot, int x){
    Node *matchNode;
    if(proot == NULL){
        return NULL;
    }
    if((*proot)->key > x){
        matchNode = deleteNode(&(*proot)->left, x);
    }else if((*proot)->key < x){
        matchNode = deleteNode(&(*proot)->right, x);
    }else{
        matchNode = deleteRoot(proot);
    }
    updateHeight(proot);
    rebalance(proot);
    return matchNode;
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