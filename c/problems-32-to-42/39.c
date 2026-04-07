/*
Write a function that creates the following pattern,
given the height (number of rows) and the width (print characters per line):
===========
*         *
*         *
*         *
*         *
*         *
===========
*/

/* 

!!! MISS: READ BEFORE PROCEEDING !!!
- This is assuming the === line kay apil sa row computation
- For example, input 5 rows and columns:

YES:                NO:
=====               =====
*   *               *   *          
*   *               *   *
*   *               *   *
=====               *   *   
                    *   *
                    =====
*/

#include <stdio.h>


void coolBox(int rows, int columns) {
    if (rows <= 0 || columns <= 0) return;

    for (int i = 1; i <= rows; i++) {

        // the === line
        if ( (i == 1) || (i == rows) ) {
            for (int j = 1; j <= columns; j++) {
                printf("=");
            }
        
        // the * * line
        } else {
            for (int j = 1; j <= columns; j++) {
                if ( (j == 1) || (j == columns) ) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }

        printf("\n");
    }
}


int main() {

    // height     width
    int rows = 0, columns = 0;

    printf("Input # of rows and columns (separated by space): ");
    scanf("%d %d", &rows, &columns);

    coolBox(rows, columns);

    return 0;
}