//Author: Shawn Esseltine 400145888
//Problem 2

// Import all required libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 255

// Define stack datatype
struct stackNode{
    char* data; // the data of this node
    struct stackNode *next; // pointer to the next node in the stack
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

// Function Prototypes
char *strrev(char *str);
void push(StackNodePtr *topPtr, char* in);
char* pop(StackNodePtr *topPtr);
void toPostfix(char *prefix);
void printStack(StackNodePtr currentPtr);

int main(void){
    //Initialize required variables
    char prefix[SIZE];

    printf("Prefix: ");
    scanf("%s", prefix); // get the prefix equation
    printf("Postfix: ");
    toPostfix(prefix); // conver the equation
}

void toPostfix(char *prefix){
    strrev(prefix); // reverse the string
    StackNodePtr stackPtr = NULL; // create an empty stack

    // loop through each char of the string
    for(unsigned int i = 0; i < strlen(prefix); i++){
        if(isalpha(prefix[i]) || isdigit(prefix[i])){ // if its an operand
            // push it on the stack as a string
            char* subStr = malloc(sizeof(prefix[i]));
            strncpy(subStr, &prefix[i],1);
            push(&stackPtr, subStr);
        }else{
            //combine the two previous operands and the operator
            char* temp = malloc(sizeof(stackPtr->data) + sizeof(stackPtr->next->data) + 1);
            strcpy(temp, pop(&stackPtr));
            strcat(temp, pop(&stackPtr));
            temp[strlen(temp)] = prefix[i];
            push(&stackPtr, temp); // push them all back on the stack
        }
    }
    printStack(stackPtr);
}

void push(StackNodePtr *topPtr, char* in){
    StackNodePtr newPtr = malloc(sizeof(StackNode));
    if(newPtr != NULL){ // if proper memory allocation
        newPtr->data = in;
        newPtr->next = *topPtr;
        *topPtr = newPtr;
    }else{
        puts("ERROR: No memory allocated.  Unsuccessful push.");
    }
}

char* pop(StackNodePtr *topPtr){
    StackNodePtr tempPtr = *topPtr; // point to the current top
    char* retVal = (*topPtr)->data; // store the data within
    *topPtr = (*topPtr)->next; // move the top to the next element
    free(tempPtr); // free the old top
    return retVal; // return the stored value
}

void printStack(StackNodePtr currentPtr){
    if(currentPtr == NULL){ // failed to create memory space
        puts("The stack is empty");
    }else{
        while(currentPtr != NULL){
            printf("%s", currentPtr->data); // print the current string
            currentPtr = currentPtr->next; // move to the next char
        }
    }puts("");
}

// Code from Sumit Naik on StackOverflow
// https://stackoverflow.com/questions/8534274/is-the-strrev-function-not-available-in-linux
// strrev not a standard function of string.h in unix gcc
char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}
