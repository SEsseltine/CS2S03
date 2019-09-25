//Author: Shawn Esseltine 400145888
//Problem 1

// Import all required libraries
#include <stdio.h>
#include <stdlib.h>

// Required data structures
struct listNode{
    char data; // each listNode contains an integer
    struct listNode *nextptr; // pointer to the next node
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

// Function Prototypes
void menu(void);
ListNodePtr* revList(ListNodePtr currentPtr);
void push(ListNodePtr *topPtr, char in);
void printList(ListNodePtr currentPtr);

int main(void){
    ListNodePtr startPtr = NULL; // initially there are no nodes

    push(&startPtr, 'J');
    push(&startPtr, 'I');
    push(&startPtr, 'H');
    push(&startPtr, 'G');
    push(&startPtr, 'F');
    push(&startPtr, 'E');
    push(&startPtr, 'D');
    push(&startPtr, 'C');
    push(&startPtr, 'B');
    push(&startPtr, 'A');

    ListNodePtr scndPtr = *revList(startPtr);

    puts("The list is:");
    printList(startPtr);

    puts("The list in reverse is:");
    printList(scndPtr);
}

void menu(void){
    puts("Enter your choice:");
    puts("1 to insertItem an element into the list");
    puts("2 to recursively search list for an element");
    puts("3 to end");
}

void appendItem(ListNodePtr *sPtr, int in){
    ListNodePtr newPtr = malloc(sizeof(ListNode));

    if(newPtr != NULL){ // if memory allocated successfully
        newPtr->data = in; // store the input as the data
        newPtr->nextptr = NULL; // start by linking to no other node

        ListNodePtr previousPtr = NULL; // no elements before the first
        ListNodePtr currentPtr = *sPtr; // start at the first element

        while(currentPtr != NULL && currentPtr->data < in){
            // move to the next element
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextptr;
        }
        if(previousPtr == NULL){ // is the smallest element
            newPtr->nextptr = *sPtr; // link to the first element
            *sPtr = newPtr; // make the new element the start of the list
        }else{
            previousPtr->nextptr = newPtr; // previous element points to this element
            newPtr->nextptr = currentPtr; // this element points to the next element
        }
    }else{
        puts("ERROR: Not inserted.  No available memory.");
    }
}

void printList(ListNodePtr currentPtr){
    if(currentPtr == NULL){ // if the list is empty
        puts("List is empty.");
    }else{
        while(currentPtr != NULL){ // while more elements in the list
            printf("%c ", currentPtr->data); // print data
            currentPtr = currentPtr->nextptr; // increment the ptr
        }
        puts("*");
    }
}

ListNodePtr* revList(ListNodePtr currentPtr){
    if(currentPtr == NULL){ // if the list is empty
        puts("Failed to reverse.  List is empty.");
    }else{
        ListNodePtr retPtr = NULL;
        while(currentPtr != NULL){ // while more elements in the list
            push(&retPtr, currentPtr->data); // print data
            currentPtr = currentPtr->nextptr; // increment the ptr
        }
        return &retPtr;
    }
    return NULL;
}

void push(ListNodePtr *topPtr, char in){
    ListNodePtr newPtr = malloc(sizeof(ListNode)); // create a new node
    if(newPtr != NULL){ // if proper memory allocation
        newPtr->data = in; // store the passed value in data
        newPtr->nextptr = *topPtr; // point to the old top
        *topPtr = newPtr; // move the top tot the current element
    }else{ // failed to assign memory
        puts("ERROR: No memory allocated.  Unsuccessful push.");
    }
}
