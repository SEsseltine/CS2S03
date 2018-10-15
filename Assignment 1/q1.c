//Author: Shawn Esseltine 400145888
//Question 1

//Import all required libraries
#include <stdio.h>

int main(void){
    //Initialize required variables
    unsigned int flag = 1;
    double sales = 0, commission = 0;

    //Create input loop
    do{
        //Prompt the user for input
        printf("%s", "Enter sales in dollars (-1 to end): ");
        scanf("%lf", &sales);
        //Determine if user intends to finish program
        if(sales == -1){
            //Set flag to false (0)
            flag--;
        }else{
            //Calculate the commission to be paid
            commission = 0.09 * sales + 200;
            //Print the employees salary
            printf("%s%.2f\n", "Salary is: ", commission);
        }
    }while(flag);
}
