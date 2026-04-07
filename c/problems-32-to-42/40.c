/*
Write a function that creates the following pattern,
given the height (number of rows):
*
***
*****
*******
*********
*/

#include <stdio.h>


void triangle(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}


int main() {

    int rows = 0;

    printf("Input # of rows: ");
    scanf("%d", &rows);

    triangle(rows);

    return 0;
}