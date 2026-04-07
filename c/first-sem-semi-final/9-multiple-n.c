/*
Multiplication Table in Range

Problem:
Generate multiplication tables from 1 up to n using nested loops.

Concepts: nested for loops, formatting output.

Example Output:
Enter range: 3
Table of 1:
1x1=1
1x2=2
...
Table of 2:
2x1=2
...
Table of 3:
3x1=3
...
Press any key to continue [n-to stop]:
*/

#include <stdio.h>

// MULTIPLE OF n range VERSION (up to n squared)

void multiplicationTable(int range);


int main() {

    int n = 0; // range
    char flag;

    do {
        printf("Enter range: ");
        scanf("%d", &n);

        multiplicationTable(n); // range, multiple params

        printf("\nPress any key to continue [n-to stop]: ");
        scanf(" %c", &flag);

    } while (flag != 'n' && flag != 'N');
    
    return 0;
}


void multiplicationTable(int range) {
    for (int i = 1; i <= range; i++) {
        printf("\nTable of %d:", i);
        
        for (int j = 1; j <= range; j++) {
            printf("\n%dx%d=%d", i, j, i * j);
        }

        printf("\n");
    }
}