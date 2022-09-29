//Pointer notes:
//int x = 1
//int x (location in memory)
//1 (data in that location (address))
//&gets the address of a variable (not the value)
#include <stdio.h>

int main() {
    //int x = 1, y = 2, z[10];
    //int *intPointer;            /* ip is a pointer to an int */
    //intPointer = &x;            /* ip points to (contains the memory address of) x */
    //y = *intPointer;            /* y is now 1, indirectly copied from x using ip */
    //*intPointer = 0;            /* x is now 0 */
    //intPointer = &z[5];         /* ip now points to z[5] */
    //int a = 42; //42 is in the "a" address
    //int *ip; //Creating a pointer type int
    //double d = 6.34; //6.34 is in the "d" address
    //double *dp //Creating a pointer type int
    
    //ip = &a; //Set the ADDRESS of 'a' equal to the ADDRESS ip
    //So now the data in "id" is now equal to the a
    
    
    //Answer for this block of code: (4,4) for F, and (3,7) for main 
    int m = 3, n = 5;
    F(m, &n);
    printf("%d, %d\n", m, n);
    return 0;
}

void F (int a, int *b) {
    a = 7;
    *b = a;
    b = &a;
    *b = 4;
    printf("%d, %d\n", a, *b);
}