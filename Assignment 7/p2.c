//Author: Shawn Esseltine 400145888
//Problem 2

// Import all required libraries
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define SIZE 255

// Function Prototypes
void listRecurse(char path[]);

int main(void){
    //Initialize required variables
    char path[SIZE]; // will store the directory path

    printf("Enter the directory path: ");
    scanf("%s", path); // store the desired path

    listRecurse(path); // list the contents of the path
}

void listRecurse(char path[]){
    char newPath[SIZE]; // define a new path that will be passed on
    struct dirent *reader; // define a directory reader
    DIR *dir; // define a directory pointer

    if((dir = opendir(path)) == NULL){
        return; // failed to open a directory return nothing
    }else{
        while((reader = readdir(dir)) != NULL){ // while there is more in the directory

            // ensure we don't create an infinite loop
            if (strcmp(reader->d_name, ".") != 0 && strcmp(reader->d_name, "..") != 0){
                // print the current file / directory
                printf("%s\n", reader->d_name);

                // build a new path to be passed on
                strcpy(newPath, path);
                strcat(strcat(newPath, "/"), reader->d_name);

                // try calling the function on the new path
                listRecurse(newPath);
            }
        }
    }
}
