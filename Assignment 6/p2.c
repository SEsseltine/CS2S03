//Author: Shawn Esseltine 400145888
//Problem 2

// Import all required libraries
#include <stdio.h>

// Function Prototypes
void displayBits(unsigned int);

int main(void){
    // initialize required variables
    char a, b;
    // prompt the user to enter 2 chars
    printf("Enter two characters: ");
    scanf("%c %c", &a, &b);

    // print the results for the first entered char
    printf("'%c' in bits as an unsigned integer is:\n", a);
    displayBits(a);

    // print the restults for the second entered char
    printf("'%c' in bits as an unsigned integer is:\n", b);
    displayBits(b);

    // print the value for shifted first and second
    printf("'%c' and '%c' packed in an unsigned integer:\n", a, b);
    displayBits(a << 8 | b);

    return 0;
}


// display bits of an unsigned int value
void displayBits(unsigned int value){
    // declare displayMask and left shift 31 bits
    unsigned int displayMask = 1 << 31;

    printf("%7u = ", value);

    // loop through bits
    for (unsigned int c = 1; c <= 32; ++c){
        putchar(value & displayMask ? '1' : '0');
        value <<=1; // shift left by 1

        if (c % 8 == 0){
            putchar(' ');
        }
    }
    putchar('\n');
}
