//Author: Shawn Esseltine 400145888
//Problem 2

//Import all required libraries
#include <stdio.h>
#include <math.h>

int multiple(int, int); //Function prototype

int main(void){
    //Generate and print test cases
    for(int i = 2; i <= 20; i++){
        for(int j = i - 1; j > 1; j--){
            printf("%5d%5d%5d\n", i, j, multiple(i, j));
        }
    }
}

int multiple(int a, int b){
    //Check if a evenly divides into b (making it a multiple)
    if(a % b == 0){
        //If it does return true (1)
        return 1;
    }else{
        //If it doesn't return false (0)
        return 0;
    }
}
