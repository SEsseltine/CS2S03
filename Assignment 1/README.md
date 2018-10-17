# Assignment 1

## Problem 1 - Sales Commission Calculator
One large chemical company pays its salespeople on a commission basis. The salespeople receive $200 per week plus 9% of their gross sales for that week. For example, a salesperson who sells $5000 worth of chemicals in a week receives $200 plus 9% of $5000, or a total of $650. Develop a program that will input each salesperson’s gross sales for last week and will calculate and display that salesperson’s earnings. Process one salesperson's figures at a time. Here is a sample input/output dialog:
```
Enter sales in dollars (-1 to end): 5000.00
Salary is: $650.00
Enter sales in dollars (-1 to end): 1234.56
Salary is: $311.11
Enter sales in dollars (-1 to end): -1
```

## Problem 2 - Find the Largest Number
The process of finding the largest number (i.e., the maximum of a group of numbers) is used frequently in computer applications. For example, a program that determines the winner of a sales contest would input the number of units sold by each salesperson. The salesperson who sells the most units wins the contest. Write a pseudo code program and then a program that inputs a series of 10 non-negative numbers and determines and prints the largest of the numbers. *Hint*: Your program should use three variables as follows:
```
Counter: A counter to count to 10 (i.e., to keep track of how many numbers have been input and to determine when all 10 numbers have been processed)
Number: The current number input to the program
Largest: The largest number found so far
```

## Problem 3
What does the following program segment do?
``` C
for(i = 1; i <= 5; ++i){
    for (j = 1; j <= 3; ++j){
        for (k = 1; k <= 4; ++k)
            printf( "%s","*");
        puts( "");
    }
    puts("");
}
```
