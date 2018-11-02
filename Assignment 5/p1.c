//Author: Shawn Esseltine 400145888
//Problem 1

//Import all required libraries
#include <stdio.h>
#include <math.h>

void circleCircumference(double); // function prototype
void circleArea(double); // function prototype
void sphereVolume(double); // function prototype


int main(void){
    // Initialize array of 3 pointers to functions that each take a
    // double argument and return void
    void (*f[3])(double) = {circleCircumference, circleArea, sphereVolume};

    printf("%s", "Enter a number between 0 and 2, 3 to end: ");
    size_t choice; // variable to hold users choice
    scanf("%zu", &choice);

    // process user's choice
    while(choice >= 0 && choice < 3){
        printf("%s", "Enter a radius: ");
        double radius; // variable to hold user enter radius
        scanf("%lf", &radius);

        // invoke function at location choice in array f and pass
        // radius as an argument
        (*f[choice])(radius);

        printf("%s", "Enter a number between 0 and 2, 3 to end: ");
        scanf("%zu", &choice);
    }
}

void circleCircumference(double r){
    // print the circumference of circle radius r
    printf("%s%lf%s%lf\n", "Circumference of circle radius ", r, " = ", 2 * M_PI * r);
}

void circleArea(double r){
    // print the area of circle radius r
    printf("%s%lf%s%lf\n", "Area of circle radius ", r, " = ", M_PI * pow(r,2));
}

void sphereVolume(double r){
    // print the volume of sphere radius r
    printf("%s%lf%s%lf\n", "Volume of sphere radius ", r, " = ", (4.0/3.0) * M_PI * pow(r,3));
}
