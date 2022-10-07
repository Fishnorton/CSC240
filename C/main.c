//Fisher Norton CSC 240
//10/6/22

#include <stdio.h> //printf/scanf
#include <stdlib.h> //RNG
#include <time.h> //System Clock

//Initialize Functions
int diceRoll();
void displayScore(int p1Score, int p2Score);
int calcRollScore(int die1, int die2);
int playerHasWon(int p1Score, int p2Score);
int playerTurn(char playerNumber);

//Main function to play the game
int main() {
   int p1Score = 0, p2Score = 0;
   do {
       displayScore(p1Score, p2Score);//Display the scores
       p1Score = p1Score + playerTurn('1');//Add the score of player 1 to their previous score and play their turn
       p2Score = p2Score + playerTurn('2');//Add the score of player 2 to their previous score and play their turn
   } while (playerHasWon(p1Score, p2Score) != 1); //If a winner is found, exit the game
   return 0; 
}

//prints out the current scores of player1 and player2
void displayScore(int p1Score, int p2Score) {
    printf("\nPlayer1 score: %d\nPlayer2 score: %d\n", p1Score, p2Score);
    printf("+------------------------------------------------------------+\n");
}

//Takes in the players number, plays the game (takes in input) and returns their score to the main function
int playerTurn(char playerNumber) {
    srand(time(NULL));
    int die1 = 0, die2 = 0, points = 0;
    char again = 'n';
    do {
        die1 = diceRoll();//Roll die1
        die2 = diceRoll();//Roll die2
        points = points + calcRollScore(die1, die2);//Calculate the score created by the two dice rolls (and it it to the current turns points)
        if (calcRollScore(die1, die2) == 0) { //If the player gets a 1 in their number, set their points for the turn to 0 and exit the loop
            printf("Player%c rolls a %d and %d. Your total for this turn is 0\n", playerNumber, die1, die2);
            points = 0;
            again = 'n';
        } else { //Give the option to let the player roll again
            printf("Player%c rolls a %d and %d. Your total for this turn is %d\n", playerNumber, die1, die2, points);
            printf("Do you want to roll again? (Y/N)");
            scanf(" %c", &again);
        }
    } while (again == 'y' || again == 'Y');
    return points;
}

//Checks if a player has won and returns 1 if either of them have (or tie)
int playerHasWon(int p1Score, int p2Score) {
    if (p1Score >= 100 || p2Score >= 100) {
        if (p1Score > p2Score) {
            printf("\nPlayer 1 Wins!");
            return 1; //End the game
        } else if (p2Score > p1Score) {
            printf("\nPlayer 2 Wins!");
            return 1; //End the game
        } else {
            printf("\nIts a tie!");
            return 1; 
        }
    }
    return 0; //The game continues on
}

//Returns the score of a diceroll given two die
int calcRollScore(int die1, int die2) {
    if (die1 == die2) {                     //If its a double
        if (die1 == 1) {                    //If both are 1's
            return 25;
        } else {                            //If its a non 1 double
            return 2*(die1+die2);
        }
    } else {                                //If its not a double
        if (die1 == 1 || die2 == 1) {       //If either are 1's (but not both)
            return 0;
        } else {                            //If its two non 1, non double numbers
            return die1+die2;
        }
    }
}

//Rolls a die and returns a value 1 through 6
int diceRoll() {
    return rand() % 6 + 1;
}