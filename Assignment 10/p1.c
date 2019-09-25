//Author: Shawn Esseltine 400145888
//Problem 1

// Import all required libraries
#include <stdio.h>
#include <stdlib.h>

struct queueNode {
   char data;
   struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

// Function Prototypes
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
void instructions(void);

int main(void){
    QueueNodePtr headPtr = NULL;
    QueueNodePtr tailPtr = NULL;
    int choice;
    char item;

    instructions();
    printf("?");
    scanf("%d",&choice);

    while (choice != 3) {
       switch(choice) {
       case 1 :
          printf("Enter a character: ");
          scanf("\n%c",&item);
          enqueue(&headPtr,&tailPtr,item);
          printQueue(headPtr);
       break;
       case 2 :
          if (!isEmpty(headPtr)) {
             item = dequeue(&headPtr,&tailPtr);
             printf("%c has been dequeued.\n",item);
          }
          printQueue(headPtr);
       break;
       default:
          printf("Invalid choice.\n\n");
          instructions();
       break;
       }

       printf("?");
       scanf("%d",&choice);
    }

    printf("End of run.\n");
    return 0;
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value) {
   QueueNodePtr newPtr;

   newPtr = malloc(sizeof(QueueNode));

   if (newPtr != NULL) {
      newPtr->data =  value;
      newPtr->nextPtr = NULL;

      if (isEmpty(*headPtr)) {
         *headPtr = newPtr;
      }
      else {
         (*tailPtr)->nextPtr = newPtr;
      }
      *tailPtr = newPtr;

   }
   else {
      printf("%c not inserted.  No memory available.\n",value);
   }
}  /*  end enqueue  */

char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) {
   char value;
   QueueNodePtr tempPtr;

   value = (*headPtr)->data;
   tempPtr = *headPtr;
   *headPtr = (*headPtr)->nextPtr;

   if (isEmpty(*headPtr)) {
      *tailPtr = NULL;
   }

   free(tempPtr);

   return value;
}  /*  end dequeue  */

void printQueue(QueueNodePtr currentPtr) {
   while (currentPtr != NULL) {
      printf("%c->",currentPtr->data);
      currentPtr = currentPtr->nextPtr;
   }
   printf("NULL\n");
}


int isEmpty(QueueNodePtr headPtr) {
   return NULL == headPtr;
}  /*  end isEmpty  */


void instructions(void) {
   printf("Enter your choice:\n");
   printf("  1 to add an item to the queue\n");
   printf("  2 to remove an item from the queue\n");
   printf("  3 to end\n");
}
