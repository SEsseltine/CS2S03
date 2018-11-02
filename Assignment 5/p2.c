//Author: Shawn Esseltine 400145888
//Problem 2

//Import all required libraries
#include <stdio.h>
#include <math.h>

void add(double, double); // function prototype
void sub(double, double); // function prototype
void mul(double, double); // function prototype
void divide(double, double); // function prototype


int main(void){
    // Initialize array of 3 pointers to functions that each take a
    // double argument and return void
    void (*f[4])(double, double) = {add, sub, mul, divide};

    printf("%s", "Enter a number between 0 and 3, 4 to end: ");
    size_t choice; // variable to hold users choice
    scanf("%zu", &choice);

    // process user's choice
    while(choice >= 0 && choice < 4){
        printf("%s", "Enter a first number: ");
        double a; // variable to hold user enter first arg
        scanf("%lf", &a);

        printf("%s", "Enter a second number: ");
        double b; // variable to hold user enter second arg
        scanf("%lf", &b);

        // invoke function at location choice in array f and pass
        // radius as an argument
        (*f[choice])(a, b);

        printf("%s", "Enter a number between 0 and 3, 4 to end: ");
        scanf("%zu", &choice);
    }
}

void add(double a, double b){
    // print the addition of a + b
    printf("%lf%s%lf%s%lf\n", a, " + ", b, " = ", a + b);
}

void sub(double a, double b){
    // print the subtraction of a - b
    printf("%lf%s%lf%s%lf\n", a, " - ", b, " = ", a - b);
}

void mul(double a, double b){
    // print the multiplication of a * b
    printf("%lf%s%lf%s%lf\n", a, " x ", b, " = ", a * b);
}

void divide(double a, double b){
    // print the division of a / b
    printf("%lf%s%lf%s%lf\n", a, " / ", b, " = ", a / b);
}
