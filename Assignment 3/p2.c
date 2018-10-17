//Author: Shawn Esseltine 400145888
//Problem 2

//Import all required libraries
#include <stdio.h>

void towersRecurse(unsigned int, unsigned int, unsigned int, unsigned int); // function prototype

int main(void){
    // Print test case
    towersRecurse(3,1,3,2);
}

void towersRecurse(unsigned int n, unsigned int iPeg, unsigned int dPeg, unsigned int tPeg){
    if(n == 1){ // base case
        printf("%d → %d\n", iPeg, dPeg);
        return;
    }
    towersRecurse(n - 1, iPeg, tPeg, dPeg); // move all but base ring to temp peg
    printf("%d → %d\n", iPeg, dPeg); // move base ring to dest peg
    towersRecurse(n - 1, tPeg, dPeg, iPeg); // move all pegs to dest peg
}
