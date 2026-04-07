/*
Write a function that creates the following pattern,
given the height (number of rows) and the width (asterisks per row):
*************
*************
*************
*************
*/

#include <stdio.h>


void box(int rows, int columns) {
    if (rows <= 0 || columns <= 0) return;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++){
            printf("*");
        }
        printf("\n");
    }
}


int main() {

    // height     width
    int rows = 0, columns = 0;

    printf("Input # of rows and columns (separated by space): ");
    scanf("%d %d", &rows, &columns);

    box(rows, columns);

    return 0;
}