#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isOK(int n, int r);
int combos(int n, int r);
int factorial(int num);

int main() {
    
    int n;
    int r;
    char again;
    
    do {
        printf("Enter total items");
        scanf("%d", &n);

        printf("Enter items taken at one time: ");
        scanf("%d", &r);

        if (isOK(n,r)) {
            printf("\nC(%d,%d) = %d\n", n, r, combos(n,r));
        } else {
            printf("\nError - Invalid input.\n");
        }

        printf("\nWould you like to calculate another combonation? (Y/N)");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    return 0;
}

int isOK(int n, int r) {
    if (n > 0 && r > 0 && n >= r) {
        return TRUE;
    } else {
        return FALSE;
    }
}


//calculates number of combonations using the formula
int combos(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n-r));
}

int factorial(int num) {
    if (num == 0) {
        return 1;
    }
    return num * factorial(num-1);
}