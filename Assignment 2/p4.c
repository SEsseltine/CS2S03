//Author: Shawn Esseltine 400145888
//Problem 4

//Import all required libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// enumeration constants represent game status
enum Status { CONTINUE, WON, LOST };

int rollDice(void); // function prototype

int playGame(int); // function prototype

int main(void){

    //Initialize required variables
    int bankBalance = 1000, wager = 0;

    // Play the game while the player still has money
    do{
        // Get the players wager
        printf("Wager: ");
        scanf("%d", &wager);

        if(wager <= 0 || wager > bankBalance){ // Check wager validity
            puts("Invalid wager. Please enter a valid wager.");
        }else if(wager >= (bankBalance * 0.5)){ // Big wager (50%+) "chatter"
            puts("Oh, you're going for broke, huh?");
            bankBalance += playGame(wager);
        }else if(wager <= (bankBalance * 0.05)){ // Small wager (5%-) "chatter"
            puts("Aw cmon, take a chance!");
            bankBalance += playGame(wager);
        }else{ // No "chatter" just play
            bankBalance += playGame(wager);
        }

        // Display player bank balance
        printf("Bank Balance: %d\n", bankBalance);

        // If the player has doubled their money display "chatter"
        if(bankBalance >= 2000){
            puts("You're up big. Now's the time to cash in your chips!");
        }

    }while(bankBalance > 0);
    puts("Sorry. you busted!");
}

int playGame(int wager){
    // randomize random number generator using current time
    srand(time(NULL));

    int myPoint; // player must make this point to win
    enum Status gameStatus; // can contain CONTINUE, WON, or LOST
    int sum = rollDice(); // first roll of the dice
    // determine game status based on sum of dice
    switch(sum) {
        // win on first roll
        case 7: // 7 is a winner
        case 11: // 11 is a winner
            gameStatus = WON;
            break;
        // lose on first roll
        case 2: // 2 is a loser
        case 3: // 3 is a loser
        case 12: // 12 is a loser
            gameStatus = LOST;
            break;

        // remember point
        default:
            gameStatus = CONTINUE; // player should keep rolling
            myPoint = sum; // remember the point
            printf("Point is %d\n", myPoint);
            break; // optional
    }

    // while game not complete
    while (CONTINUE == gameStatus) { // player should keep rolling
        sum = rollDice(); // roll dice again

        // determine game status
        if (sum == myPoint) { // win by making point
            gameStatus = WON;
        }else {
            if (7 == sum) { // lose by rolling 7
               gameStatus = LOST;
            }
        }
    }

    // display won or lost message
    if (WON == gameStatus) { // did player win?
        puts("Player wins");
        return wager; // Return positive wager to increase balance
    }else { // player lost
        puts("Player loses");
        return wager * (-1); // Return negative wager to decrease balance
    }
}

// roll dice, calculate sum and display results
int rollDice(void) {
    int die1 = 1 + (rand() % 6); // pick random die1 value
    int die2 = 1 + (rand() % 6); // pick random die2 value
    printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
    return die1 + die2; // return sum of dice
}
