#include <stdio.h>
#include <stdlib.h> //rng
#include <time.h>

#define SIZE 10

//Prototype Satement
void genRandInts(int nums[]);
void display(int nums[]);

int main() {
    int nums[SIZE];

    srand(time(NULL)); //uses the time to see the rng
    
    //Gen ran Numbers
    genRandInts(nums);
    //display array
    display(nums);

    return 0;
}

genRandInts(int nums[]) {
    for (int i = 0; i < SIZE; i++) {
        nums[i] = rand() % 100+1; //0-99, so if we want to do 1-100, we use +1
    }
}

void display(int nums[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%5d", nums[i]);
    }
    printf("\n"); //Field width of 8th, 
}