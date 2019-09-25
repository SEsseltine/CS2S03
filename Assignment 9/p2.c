//Author: Shawn Esseltine 400145888
//Problem 2

// Import all required libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define stack datatype
struct stackNode{
    char data; // the data of this node
    struct stackNode *next; // pointer to the next node in the stack
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

// Function Prototypes
void push(StackNodePtr *topPtr, int in);
int pop(StackNodePtr *topPtr);
void printStack(StackNodePtr currentPtr);
void removeMiddle(StackNodePtr *topPtr);
unsigned int palinTest(StackNodePtr *topPtr, unsigned int count);

int main(void){
    //Initialize required variables
    StackNodePtr palinPtr = NULL;
    char input[255];
    unsigned int flag = 0, counter = 0;

    puts("Enter a line of text: ");
    gets(input);

    // Form a stack without spaces or punctuation
    for(unsigned int i = 0; i < strlen(input); i++){
        if(isalpha(input[i]) || isdigit(input[i])){
            push(&palinPtr, input[i]);
            counter ++; // size of the stack
        }
    }

    // check if its a palindrome
    flag = palinTest(&palinPtr, counter);

    // display the appropriate message
    if(flag == 0){
        printf("\"%s\" is not a palindrome\n", input);
    }else{
        printf("\"%s\" is a palindrome\n", input);
    }
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
    while (currentPtr != NULL) { // while still more elements
        // print the element
        printf("%c", currentPtr->data);
        currentPtr = currentPtr->next; // move to the next element
    }puts(""); // for formatting
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
}

unsigned int palinTest(StackNodePtr *topPtr, unsigned int count){
    // If the string isn't even length we can disregard the middle char
    if(count % 2 != 0){
        removeMiddle(topPtr);
        count--;
    }

    unsigned int mid = count / 2; // the middle of the string
    StackNodePtr stackPtr = NULL; // create an empty stack

    // create two stacks that can be compared side by side
    for(unsigned int k = 0; k < mid; k++){
        push(&stackPtr, pop(topPtr));
    }

    // loop through all values in the stacks
    while(stackPtr != NULL || *topPtr != NULL){
        // if they arent the same
        if(pop(topPtr) != pop(&stackPtr)){
            return 0; // it's not a palindrom
        }
    }
    return 1; // it is a palindrome
}
