#include <stdio.h>

// i have 3 versions because idk the multiple:
// - multiple of 10 (this one)
// - multiple of n (if n = 50, Table of 50: ... up to 50x50=2500)
// - product of <= 50 (no idea why i did this, just thought it would be cool)

// using multiple of 10 version because it is most common

void multiplicationTable(int range, int multiple);


int main() {

    const int MULTIPLE = 10;

    int n = 0; // range
    char flag;

    do {
        printf("Enter range: ");
        scanf("%d", &n);

        multiplicationTable(n, MULTIPLE);

        printf("\nPress any key to continue [n-to stop]: ");
        scanf(" %c", &flag);

    } while (flag != 'n' && flag != 'N');
    
    return 0;
}


void multiplicationTable(int range, int multiple) {
    for (int i = 1; i <= range; i++) {
        printf("Table of %d:", i);
        
        for (int j = 1; j <= multiple; j++) {
            printf("\n%dx%d=%d", i, j, i * j);
        }

        printf("\n\n");
    }
}