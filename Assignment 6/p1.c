//Author: Shawn Esseltine 400145888
//Problem 1

// Import all required libraries
#include <stdio.h>

// Function Prototypes
void power2(int, int);
void displayBits(unsigned int);

int main(void){
    // test case 1
    power2(5, 2);
    // test case 2
    power2(1, 5);
    return 0;
}

// print the value of num shifted left by the value of pow
void power2(int num, int pow){
    // displayBits of num shifted left by pow
    displayBits(num << pow);
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
