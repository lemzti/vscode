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

/*
PRODUCT <= n

example: n = 50

Table of 15:
15x1=15
...
15x3=45

45 last multiple because 15x4=60,
which is more than 50 (n)
*/

void multiplicationTable(int range);


int main() {

    int n = 0; // range
    char flag;

    do {
        printf("Enter range: ");
        scanf("%d", &n);

        multiplicationTable(n);

        printf("\nPress any key to continue [n-to stop]: ");
        scanf(" %c", &flag);

    } while (flag != 'n' && flag != 'N');
    
    return 0;
}


void multiplicationTable(int range) {
    for (int i = 1; i <= range; i++) {
        printf("\nTable of %d:", i);
        
        for (int j = 1; (i * j) <= range; j++) {
            printf("\n%dx%d=%d", i, j, i * j);
        }

        printf("\n");
    }
}