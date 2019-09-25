//Author: Shawn Esseltine 400145888
//Problem 2

// Import all required libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create required data structures
struct treeNode{
    struct treeNode *leftPtr;
    char data;
    struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

// Function Prototypes
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);

int main(void){
    // Create all of the required nodes
    TreeNodePtr rootPtr = malloc(sizeof(TreeNode));
    TreeNodePtr L = malloc(sizeof(TreeNode));
    TreeNodePtr LL = malloc(sizeof(TreeNode));
    TreeNodePtr LR = malloc(sizeof(TreeNode));
    TreeNodePtr R = malloc(sizeof(TreeNode));
    TreeNodePtr RL = malloc(sizeof(TreeNode));

    // Assign the respective values
    rootPtr->data = 'A';
    rootPtr->leftPtr = L;
    rootPtr->rightPtr = R;

    L->data = 'B';
    L->leftPtr = LL;
    L->rightPtr = LR;

    LL->data = 'D';
    LL->leftPtr = NULL;
    LL->rightPtr = NULL;

    LR->data = 'E';
    LR->leftPtr = NULL;
    LR->rightPtr = NULL;

    R->data = 'C';
    R->leftPtr = RL;
    R->rightPtr = NULL;

    RL->data = 'F';
    RL->leftPtr = NULL;
    RL->rightPtr = NULL;

    // Print the test cases
    puts("Inorder Sequence: ");
    inOrder(rootPtr);
    puts("");

    puts("Preorder Sequence: ");
    preOrder(rootPtr);
    puts("");
}

void inOrder(TreeNodePtr treePtr){
    // if tree is not empty, then traverse
    if(treePtr != NULL){
        inOrder(treePtr->leftPtr);
        printf("%3c", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

void preOrder(TreeNodePtr treePtr){
    // if tree is not empty, then traverse
    if(treePtr != NULL){
        printf("%3c", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}
