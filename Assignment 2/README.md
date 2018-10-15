# Assignment 2

## Problem 1 - Hypotenuse Calculations
Define a function called **hypotenuse** that calculates the length of the hypotenuse of a right triangle when the other two sides are given. The function should take two arguments of type double and return the hypotenuse as a double. Test your program with the side values specified in the following table:

|  Triangle  |  Side 1  |  Side 2  |
|:----------:|:--------:|:--------:|
|1|3.0|4.0|
|2|5.0|12.0|
|3|8.0|15.0|

## Problem 2 - Multiples
Write a function multiple that determines for a pair of integers whether the second integer is a multiple of the first. The function should take two integer arguments and return 1 (true) if the second is a multiple of the first, and 0 (false) otherwise. Use this function in a program that inputs a series of pairs of integers.

## Problem 3 - Greatest Common Divisor
The greatest common divisor (GCD) of two integers is the largest integer that evenly divides each of the two numbers. Write function gcd that returns the greatest common divisor of two integers.

## Problem 4 - Craps Game Modification
Modify the craps program of Fig. 5.14 to allow wagering. Package as a function the portion of the program that runs one game of craps. Initialize variable bankBalance to 1000 dollars. Prompt the player to enter a wager. Use a while loop to check that wager is less than or equal to bankBalance, and if not, prompt the user to reenter wager until a valid wager is entered. After a correct wager is entered, run one game of craps. If the player wins, increase bankBalance by wager and print the new bankBalance. If the player loses, decrease bankBalance by wager, print the new bankBalance, check whether bankBalance has become zero, and if so print the message, "Sorry. You busted!" As the game progresses, print various messages to create some *“chatter”* such as, "Oh, you're going for broke, huh?" or "Aw cmon, take a chance!" or "You're up big. Now's the time to cash in your chips!"
