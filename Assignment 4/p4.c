//Author: Shawn Esseltine 400145888
//Problem 4

//Import all required libraries
#include <stdio.h>

int max(int (*p), int); // function prototype

int main(void){
    // Test case 1
    int a[5];
    for(int i = 0; i < 5; i++)
        a[i] = i;
    printf("%d\n", max(a, sizeof a / sizeof a[0]));

    // Test case 2
    int b[5];
    for(int k = 5; k > 0; k--)
        b[k-1] = k;
    printf("%d\n", max(b, sizeof b / sizeof b[0]));

    // Test case 3
    int c[9] = {1,3,5,7,4,6,3,2,4};
    printf("%d\n", max(c, sizeof c / sizeof c[0]));


}

int max(int (*p), int len){
    // base case when there is only 1 element left in the array
    if(len == 1)
        return p[0];
    // return the larger of the current value and the max(n-1)
    return p[len-1] > max(p, len-1) ? p[len-1] : max(p, len-1);
}
