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

int updateHeight(Node **proot){
    //Pick the bigger one
    return (height((*proot)->left) > height((*proot)->right)) ? ((*proot)->height = height((*proot)->left) + 1) : ((*proot)->height = height((*proot)->right) + 1);
}

void rightRotate(Node **proot){
    Node *k2 = *proot;
    Node *k1 = k2->left;
    Node *y = k1->right;

    //Rotate
    *proot = k1;
    k1->right = k2;
    k2->left = y;
    updateHeight(&k2);
    updateHeight(&k1);
}

void leftRotate(Node **proot){
    Node *k2 = *proot;
    Node *k1 = k2->right;
    Node *y = k1->left;

    //Rotate
    k1->left = *proot;
    (*proot)->right = y;
    updateHeight(&k2);
    updateHeight(&k1);
}

int checkBalance(Node *root){
    if(root == NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
}

void rebalance(Node **proot){
    if(checkBalance(*proot) > 1){
        //The LL case
        if((*proot)->left != NULL){
            rightRotate(proot);
        }
            //The LR case
        else{
            leftRotate(&(*proot)->left);
            rightRotate(proot);
        }
    }else if(checkBalance(*proot) < -1){
        //The RR case
        if((*proot)->right != NULL){
            leftRotate(proot);
        }
            //The RL case
        else{
            rightRotate(&(*proot)->right);
            leftRotate(proot);
        }
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

Node* deleteNode(Node **proot, int x){
	return 0;
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