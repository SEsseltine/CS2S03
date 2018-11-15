//Author: Shawn Esseltine 400145888
//Problem 3

// Import all required libraries
#include <stdio.h>

#define SIZE 255

int main(void){
    //Initialize required variables
    char inputPath[SIZE], line[SIZE];
    FILE *fPtr;
    unsigned int count;

    // get the file path to work with
    printf("Input the file name to be opened: ");
    scanf("%s", inputPath);

    // ensure proper opening of file
    if ((fPtr = fopen(inputPath, "a")) == NULL){
        puts("Error opening the file.");
    }else{
        // get the number of lines to be written
        printf("Input the number of lines to be written: ");
        scanf("%d", &count);

        while(count--){ // while there are more lines
            if(ftell(fPtr) != 0) // if the file isn't empty
                fputs("\n", fPtr); // break the previous line
            scanf("%s", line); // get the input for the line to add
            fputs(line, fPtr); // add the inputted line to the file
        }

        fclose(fPtr); // close the open file
    }
}
