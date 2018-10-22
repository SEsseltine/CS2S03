//Author: Shawn Esseltine 400145888
//Problem 3

//Import all required libraries
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void randomize(int * a, unsigned int); //function prototype

int main(void){
    // Test case 1
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    randomize(a, sizeof a / sizeof a[0]);
    // Print the randomized values
    for(unsigned int i = 0; i < 10; i++){
        printf("Shuffled a[%d]: %d\n", i, a[i]);
    }
}

void randomize(int * a, unsigned int len){
    // Generate a random seed based on the time
    srand(time(NULL));
    // Create a loop that will swap 200 values
    for(unsigned int c = 0; c < 200; c++){
        // Choose a random index 1 and 2 to swap
        int rand1 = (rand() % len), rand2 = (rand() % len), temp;
        // Ensure the numbers to be swapped arent the same
        while(rand1 == rand2){
            rand2 = (rand() % len);
        }
        // Swap the two indexed values
        temp = a[rand1];
        a[rand1] = a[rand2];
        a[rand2] = temp;
    }
}
