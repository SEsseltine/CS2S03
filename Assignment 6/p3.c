//Author: Shawn Esseltine 400145888
//Problem 3

// Import all required libraries
#include <stdio.h>

// Function Prototypes
void displayBits(unsigned int);
void unpackCharacters(unsigned int);


int main(void){
    // test case 1
    unpackCharacters(16706);

    return 0;
}

void unpackCharacters(unsigned int passed){
    // isolate the first char value
    unsigned int first = passed & 65280;
    // shift the first char value back by 8 bits to its original position
    first = first >> 8;
    // isolate the second char value
    unsigned int second = passed & 255;
    // declare the original a and b from first and second
    char a = first, b = second;

    // print the results
    printf("The first char was: %c\nwith values:\n", a);
    displayBits(a);
    printf("The second char was: %c\nwith values:\n", b);
    displayBits(b);
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
