//Author: Shawn Esseltine 400145888
//Problem 3

//Import all required libraries
#include <stdio.h>
#include <math.h>

int gcd(int, int); //Funtion prototype

int main(void){
    //Print out test cases
    printf("%d\n", gcd(10, 5));
    printf("%d\n", gcd(5, 10));
    printf("%d\n", gcd(9, 27));
    printf("%d\n", gcd(9, 36));
}

//Define the required gcd funtion
int gcd(int a, int b){
    //Ensure that a is the larger int and b is the smaller int
    if(a < b){
        //If b is larger than a, swap them
        int temp = b;
        b = a;
        a = temp;
    }

    //Start a checking variable i at the largest possible greatest common denom.
    for(int i = b; i > 0; i--){
        //If the modulus of both a and b is zero, i is a common factor
        if(a % i == 0 && b % i == 0){
            //return the common factor
            return i;
        }
    }
    //If no common factor is found, return 0
    return 0;
}
