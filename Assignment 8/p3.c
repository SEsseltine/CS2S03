//Author: Shawn Esseltine 400145888
//Problem 3

// Import all required libraries
#include <stdio.h>
#include <stdlib.h>

// Define stack datatype
struct stackNode{
    int data; // the data of this node
    struct stackNode *next; // pointer to the next node in the stack
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

// Function Prototypes
void push(StackNodePtr *topPtr, int in);
int pop(StackNodePtr *topPtr);
void printStack(StackNodePtr currentPtr);
void removeMiddle(StackNodePtr *topPtr);

int main(void){
    //Initialize required variables
    StackNodePtr test1Ptr = NULL;
    StackNodePtr test2Ptr = NULL;
    char input[255];

    // Test case 1
    push(&test1Ptr, 6);
    push(&test1Ptr, 5);
    push(&test1Ptr, 4);
    push(&test1Ptr, 3);
    push(&test1Ptr, 2);
    push(&test1Ptr, 1);
    printf("Stack[] = ");
    printStack(test1Ptr);
    printf("Stack[] = ");
    removeMiddle(&test1Ptr);

    puts("");

    // Test case 2
    push(&test2Ptr, 5);
    push(&test2Ptr, 4);
    push(&test2Ptr, 3);
    push(&test2Ptr, 2);
    push(&test2Ptr, 1);
    printf("Stack[] = ");
    printStack(test2Ptr);
    printf("Stack[] = ");
    removeMiddle(&test2Ptr);
}

void push(StackNodePtr *topPtr, int in){
    StackNodePtr newPtr = malloc(sizeof(StackNode)); // create a new node
    if(newPtr != NULL){ // if proper memory allocation
        newPtr->data = in; // store the passed value in data
        newPtr->next = *topPtr; // point to the old top
        *topPtr = newPtr; // move the top tot the current element
    }else{ // failed to assign memory
        puts("ERROR: No memory allocated.  Unsuccessful push.");
    }
}

int pop(StackNodePtr *topPtr){
    StackNodePtr tempPtr = *topPtr; // point to the top of the stack
    int retVal = (*topPtr)->data; // the value at the top of the stack
    *topPtr = (*topPtr)->next; // remove the top of the stack
    free(tempPtr); // free the no longer required memory
    return retVal; // return the removed value
}

void printStack(StackNodePtr currentPtr){
    printf("["); // for formatting
    while (currentPtr != NULL) { // while still more elements
        // print the element
        if(currentPtr->next == NULL)
            printf("%d", currentPtr->data);
        else
            printf("%d, ", currentPtr->data);
        currentPtr = currentPtr->next; // move to the next element
    }puts("]"); // for formatting
}

void removeMiddle(StackNodePtr *topPtr){
    StackNodePtr currentPtr = *topPtr; // point to the passed list
    StackNodePtr tempStack = NULL; // create a temporary empty stack
    unsigned int count = 0, mid;

    // find the length of the stack
    while(currentPtr != NULL){
        count++;
        currentPtr = currentPtr->next;
    }

    // calculate the middle of the list
    mid = count / 2;

    if(2*mid == count) // if the stack is even length
        mid--; // take the first of the 2 possible middles

    for(unsigned int i = 0; i < mid; i++){
        int popVal = pop(topPtr); // take off all of the values before the mid
        push(&tempStack, popVal); // put them in a temp stack
    }

    pop(topPtr); // pop the value we want to remove

    // restack the previously popped values from the temp stack
    for(unsigned int i = 0; i < mid; i++){
        int popVal = pop(&tempStack);
        push(topPtr, popVal);
    }
    printStack(*topPtr); // print the new configuration of the stack
}
