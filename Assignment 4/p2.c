//Author: Shawn Esseltine 400145888
//Problem 2

//Import all required libraries
#include <stdio.h>

int upperTriangularSum(int (*a), int, int); // function prototype

int main(void){
    // Test case 1
    int test1[3][3] = {
        {1,2,4},
        {3,4,6},
        {3,8,8}
    };
    printf("%d\n", upperTriangularSum(test1, sizeof test1 / sizeof test1[0], sizeof test1[0] / sizeof test1[0][0]));
}

int upperTriangularSum(int (*a), int nCols, int nRows){
    // Declare the sum that will be returned
    int sum = 0;
    // Loop through each row in the array
    for(unsigned int r = 0; r < nRows; r++){
        // Loop through each col from the rth value + 1 to the end of the col
        for(unsigned int c = r + 1; c < nCols; c++){
            // Add to the running sum
            sum += a[r*nCols+c];
        }
    }
    // Return the calculated sum
    return sum;
}
