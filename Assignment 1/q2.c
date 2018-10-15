//Author: Shawn Esseltine 400145888
//Question 2

//Import all required libraries
#include <stdio.h>

int main(void){
    //Initialize required variables
    unsigned int number = 0, largest = 0;

    //Create input loop
    for(unsigned int counter = 1; counter <= 10; counter++){
        //Prompt the user for input
        printf("%s", "Input number of sales: ");
        scanf("%u", &number);

        //Check if input is greater than the previously largest
        if(number > largest){
            //Update the largest to be the inputted number
            largest = number;
        }
    }
    //Display the largest number of sales
    printf("%s %u\n", "Largest number of sales: ", largest);
}
