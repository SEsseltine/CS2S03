//Author: Shawn Esseltine 400145888
//Problem 3

// Import all required libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create required data structures
struct treeNode{
    struct treeNode *leftPtr;
    int data;
    struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

// Function Prototypes
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void searchTree(TreeNodePtr treePtr, int min, int max);

int main(void){
    TreeNodePtr rootPtr = NULL;

    insertNode(&rootPtr, 4);
    insertNode(&rootPtr, 8);
    insertNode(&rootPtr, 12);
    insertNode(&rootPtr, 20);
    insertNode(&rootPtr, 22);

    searchTree(rootPtr, 10, 22);
    puts("");
}

void insertNode(TreeNodePtr *treePtr, int value){
    // if tree is empty
    if(*treePtr == NULL){
        *treePtr = malloc(sizeof(TreeNode));

        // if memory was allocated, then assign data
        if(*treePtr != NULL){
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }else{
            printf("%d not inserted.  No memory available.\n", value);
        }
    }else{ // tree is not empty
        //data to insert is less than data in current node
        if(value < (*treePtr)->data){
            insertNode(&((*treePtr)->leftPtr), value);
        }
        //data to insert is greater than data in current node
        else if(value > (*treePtr)->data){
            insertNode(&((*treePtr)->rightPtr), value);
        }else{ // duplicate data, ignore
            puts("dup");
        }
    }
}

void inOrder(TreeNodePtr treePtr){
    // if tree is not empty, then traverse
    if(treePtr != NULL){
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

// search the tree for all values between min and max
void searchTree(TreeNodePtr treePtr, int min, int max){
    // if tree is not empty, then traverse
    if(treePtr != NULL){
        int val = treePtr->data; // current working value
        if(min < val) // more possible values that are lesser
            searchTree(treePtr->leftPtr, min, max);
        if(min <= val && max >= val) // in the min <-> max range
            printf("%3d", val);
        if(max > val) // more possible values that are greater
            searchTree(treePtr->rightPtr, min, max);
    }
}
