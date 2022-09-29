//Fisher Norton CSC 240
//9/29/22

#include <stdio.h> //printf/scanf
#include <stdlib.h> //RNG
#include <time.h> //System Clock

//Main program execution
int diceRoll();

int main() {
    int die1, die2, points, p1points, p2points;
    char again;
    srand(time(NULL));
    printf("Player 1 Rolls: ");
    die1 = diceRoll();
    die2 = diceRoll();
    printf("%d,%d \n", die1, die2);
    if (die1 == die2) {                     //If its a double
        if (die1 == 1) {                    //If both are 1's
            points = 25;
        } else {                            //If its a non 1 double
            points = 2*(die1+die2);
        }
    } else {                                //If its not a double
        if (die1 == 1 || die2 == 1) {       //If either are 1's (but not both)
            points = 0;
        } else {                            //If its two non 1, non double numbers
            points = die1+die2;
        }
    }
    printf("P1 total for this turn is ");
    printf("%d", points);
    printf("\nWould you like to roll again?");
    scanf(" %c", &again);
    if (again == 'y' || again == 'Y') {
        printf("AGAIN!");
    }
    /////////////////////////////////////////////////////////////////////////
    do {
        //Scores
        printf("Player 1 score: %d", p1points);
        printf("Player 2 score: %d", p2points);
        printf("+-----------------------------------------------------------------+");
        int playerNum;
        if (isP1Turn) {
            playerNum = 1;
        } else {
            playerNum = 2;
        }
        //Gameplay method
        printf("Player %d Rolls %d,%d\n", playerNum, die1, die2 );
        printf("Player %d total for this turn is ");
    } while ()
    return 0;
}

//Rolls a die and returns a point value
int diceRoll() {
    return rand() % 6 + 1;
}