//Author: Shawn Esseltine 400145888
//Problem 1

// Import all required libraries
#include <stdio.h>
#include <stdlib.h>

// Required data structures
struct listNode{
    int data; // each listNode contains an integer
    struct listNode *nextptr; // pointer to the next node
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

// Function Prototypes
void menu(void);
void insertItem(ListNodePtr *sPtr, int in);
void printList(ListNodePtr currentPtr);
ListNodePtr search(ListNodePtr *sPtr, int search);

int main(void){
    ListNodePtr startPtr = NULL; // initially there are no nodes
    int in; // integer input from user

    menu();
    printf("? ");
    unsigned int selector;
    scanf("%u", &selector);

    while(selector != 3){ // 3 will exit
        switch(selector){
            case 1: // add an item
                printf("Enter an integer: ");
                scanf("%d", &in);
                insertItem(&startPtr, in);
                printList(startPtr);
                break;
            case 2: // search for item
                printf("Enter an integer to recursively search for: ");
                scanf("%d", &in);
                search(&startPtr, in);
                if(search(&startPtr, in) != NULL){
                    printf("%d is in the list\n", in);
                }else{
                    printf("%d is not in the list\n", in);
                }
            case 3: // end
                break;
            default:
                puts("Invalid choice");
                menu();
                break;
        }
        printf("? ");
        scanf("%u", &selector);
    }

}

void menu(void){
    puts("Enter your choice:");
    puts("1 to insertItem an element into the list");
    puts("2 to recursively search list for an element");
    puts("3 to end");
}

void insertItem(ListNodePtr *sPtr, int in){
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
        puts("The list is:");
        while(currentPtr != NULL){ // while more elements in the list
            printf("%d --> ", currentPtr->data); // print data
            currentPtr = currentPtr->nextptr; // increment the ptr
        }
        puts("NULL");
    }
}

ListNodePtr search(ListNodePtr *sPtr, int in){
    ListNodePtr searchPtr = *sPtr; // start at the first element
    if(searchPtr->data == in){ // current value is what we are searching for
        return *sPtr; // return a pointer to the address
    // reached the end of the list or passed the value
    }else if(searchPtr->nextptr == NULL || searchPtr->data > in){
        return NULL; // return nothing
    }else{ // continue searching;
        return search(&(searchPtr->nextptr), in); // search at the next element
    }
}
