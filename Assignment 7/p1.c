//Author: Shawn Esseltine 400145888
//Problem 1

// Import all required libraries
#include <stdio.h>

// Function Prototypes
void mergeFiles(char fpA[], char fpB[], char fpOut[]);

int main(void){
    // Initialize required variables
    // create vars to hold the file paths to input files and output file
    char fpA[70], fpB[70], fpOut[70];

    printf("Input the 1st file name: ");
    scanf("%s", fpA); // get and store the first file name to be merged

    printf("Input the 2nd file name: ");
    scanf("%s", fpB); // get and store the second file name to be merged

    printf("Input the new file name where to merge the above two files: ");
    scanf("%s", fpOut); // get and store the output file name

    mergeFiles(fpA, fpB, fpOut);
}

void mergeFiles(char fpA[], char fpB[], char fpOut[]){
    // declare file pointers for the two files to be merged and the output file
    FILE *afPtr, *bfPtr, *outfPtr;
    char c; // will hold retrieve and pass chars between files

    if((afPtr = fopen(fpA, "r")) == NULL){ // open the first file
        puts("1st file failed to open."); // possible error message
    }else if((bfPtr = fopen(fpB, "r")) == NULL){ // open the second file
        puts("2nd file failed to open."); // possible error message
    }else if((outfPtr = fopen(fpOut, "w")) == NULL){ // open the output file
        puts("Output file failed to open."); // possible error msg
    }else{
        c = fgetc(afPtr); // get the first char from the first file
        while(c != EOF){ // while there are more chars
            fputc(c, outfPtr); // print the char to the merge file
            c = fgetc(afPtr); // get the next char
        }
        c = fgetc(bfPtr); // get the first char from the second file
        while(c != EOF){ // while there are more chars
            fputc(c, outfPtr); // print the char to the merge file
            c = fgetc(bfPtr); // get the next char
        }
        printf("The two files merged into %s file successfully...!\n", fpOut);
    }
    // close all open files
    fclose(afPtr);
    fclose(bfPtr);
    fclose(outfPtr);
}
