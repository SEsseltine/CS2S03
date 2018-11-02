//Author: Shawn Esseltine 400145888
//Problem 3

//Import all required libraries
#include <stdio.h>
#include <string.h>

#define SIZE 256

void pigLatin(char s[SIZE]);

int main(void){
    char text[SIZE]; // array to hold user input
    scanf("%[^\n]s", text); // input of user string with '\n' ending input
    pigLatin(text); // translate the input into pig latin
}

void pigLatin(char s[SIZE]){
    // Tokenize the passed in string with spaces as delimiters
    char* token = strtok(s, " ");
    // Recurse through each token
    while (token) {
        // Print the pig latin modification
        printf("%s%c%s ", token + 1, token[0], "ay");
        token = strtok(NULL, " ");
    }
    puts("");
}
