//Author: Shawn Esseltine 400145888
//Problem 1

//Import all required libraries
#include <stdio.h>

void singles(int * a, unsigned int); // function prototype

int main(void){
    // Test case 1
    int a[10] = {1,2,4,4,4,6,7,6,9,10};
    singles(a, sizeof a / sizeof a[0]);

    // Test case 2
    unsigned int size;
    printf("Length of desired array: ");
    scanf("%u", &size);
    int b[size];
    for(unsigned int i = 0; i < size; i++){
        int temp;
        printf("Enther the %u element: ", i + 1);
        scanf("%d", &temp);
        b[i] = temp;
    }
    singles(b, sizeof b / sizeof b[0]);
}

void singles(int * a, unsigned int len){
    // instantiate the required variable
    unsigned int counter = 0;
    // create testing value loop
    for(unsigned int k = 0; k < len; k++){
        // reset the counter for the current test value
        counter = 0;
        // create full loop for each testing value
        for(unsigned int j = 0; j < len; j++){
            // If the current loop of the array (j) mactches the testing value (k)
            if(a[j] == a[k]){
                // Increment the counter
                counter++;
                // If 2 or more occurences of the test value break the loop
                if(counter >= 2){
                    break;
                }
            }
        }
        // If the element is only in the array once, print it
        if(counter == 1){
            printf("%d, ", a[k]);
        }
    }puts("");
}
