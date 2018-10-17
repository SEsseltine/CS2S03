//Author: Shawn Esseltine 400145888
//Problem 1

//Import all required libraries
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

unsigned long long int fibRecurse(unsigned int); // function prototype

unsigned long long int fibIterative(unsigned int); // function prototype

long getMemoryUsage(void); // function prototype

int main(void){
    printf("%22s%30s\n", "Iterative", "Recursive");
    printf("%3s |%14s%14s |%14s%14s\n", "n", "Value", "Exec. Time", "Value", "Exec. Time");
    printf("%s\n", "----+-----------------------------+-----------------------------");
    for(unsigned int k = 0; k <= 50; k++){
        printf("%3d |", k);

        // from text figure E.11 to calculate runtime
        time_t startTime1 = time(NULL);
        unsigned long long int result1 = fibIterative(k);
        time_t endTime1 = time(NULL);

        printf("%14llu", result1);
        printf("%14.1f |", difftime(endTime1, startTime1));

        // from text figure E.11 to calculate runtime
        time_t startTime2 = time(NULL);
        unsigned long long int result2 = fibRecurse(k);
        time_t endTime2 = time(NULL);

        printf("%14llu", result2);
        printf("%14.1f\n", difftime(endTime2, startTime2));
    }
}


// Recursive definition of function fibonacci
unsigned long long int fibRecurse(unsigned int n){
    // base case
    if (0 == n || 1 == n) {
        return n;
    }
    else { // recursive step
        return fibRecurse(n - 1) + fibRecurse(n - 2);
    }
}

// Iterative definition of function fibonacci
unsigned long long int fibIterative(unsigned int n){
    // Declare required variables where:
    // a is the n - 2 term, b is the n - 1 term & nextTerm is the next fib term
    unsigned long long int a = 0, b = 1, nextTerm;
    // Count to the nth + 1 case
    for(int k = 0; k < n; k++){
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    return a; // return the nth cases
}
