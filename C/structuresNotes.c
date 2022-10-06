#include <stdio.h>
#include <string.h> //C Language string manipulation library

//Typedef basically renames data types
//typedef int boo0oolean x = 0;
//typedef char FlagType;

//struct person {
//    char name[30];
//    int id;
//};

//Candy Type Structure (Objects)
struct CandyType {
    char name[30];
    char size[11];
    int quantity;
};

//Rename the Structure (This makes it so we can just type out "Candy" instead of "struct CandyType" )
typedef struct CandyType Candy;

int main() {
    //boo0oolean x = 0;
    //int counter;
    //FlagType y = 'A';
    
    //struct person x, y;
    //scanf("%s", x.name);
    //scanf("%d", &x.id);
    //printf("Name is: %s\n", x.name);
    //printf("ID is: %d", x.id);
    
    Candy snickers;
    
    printf("Enter a name: ");
    //scanf("%s", &snickers.name[0]); Scanf is looking for an address, so you can grab the address of the first element
    scanf("%s", snickers.name); //Name also stores the address of the first element of the array
    
    printf("Enter the size: ");
    scanf("%s", snickers.size); //Size represents a meory address
    
    printf("Enter the quantity: ");
    scanf("%d", &snickers.quantity); //Quantity is a value, but scanf is expecting an address, so we use &
    
    snickers.quantity = 10;
    strcpy(snickers.size,  "Full Size"); //snickers.size = "full size"
    
    printf("\n\nI have %d %s %s.\n", snickers.quantity, snickers.size, snickers.name);
    
    printf("%lu bytes in Candy", sizeof(Candy)); //Returns 48 bytes (30(For name) + 11(For size) + 4 (For integers) + (extra 3 nice even numbers ))
    
    //Another candy variable
    Candy kitkat;
    kitkat = snickers; //Does a member wise copy
    
    printf("\n\nI have %d %s %s.\n", kitkat.quantity, kitkat.size, kitkat.name);
    
    strcpy(snickers.name, "KitKat"); //Changes the name of snickers to kitkat, so when we reprint kitkat, it uses the snickers (deep copy)
    
    printf("\n\nI have %d %s %s.\n", kitkat.quantity, kitkat.size, kitkat.name);

    return 0;
}


