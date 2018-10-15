//Author: Shawn Esseltine 400145888
//Problem 1

//Import all required libraries
#include <stdio.h>
#include <math.h>

double hypotenuse(double, double); // Function prototype

int main(void){
    //Print out test cases
    printf("%f\n", hypotenuse(3.0, 4.0));
    printf("%f\n", hypotenuse(5.0, 12.0));
    printf("%f\n", hypotenuse(8.0, 15.0));
}

//Define the required hypotenuse function
double hypotenuse(double s1, double s2){
    //Return the value of c in pythagreous:
    //sqrt(s1^2 + s2^2)
    return pow(pow(s1, 2.0) + pow(s2, 2.0), 0.5);
}
