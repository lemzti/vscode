/*
Write a function that creates the following pattern,
given the height (number of rows):
*
***
*****
*******
*********
*********
*******
*****
*** 
*
*/

#include <stdio.h>


void maybePyramid(int rows) {
    int midpoint = (rows + 1) / 2; // peak of the pyramid

    for (int i = 1; i <= rows; i++) {
        int stars;

        // top half
        if (i <= midpoint)
            stars = 2 * i - 1;

        // bottom half
        else
            stars = 2 * (rows - i + 1) - 1;

        // actually printing now
        for (int j = 1; j <= stars; j++)
            printf("*");

        printf("\n");
    }
}


int main() {

    int rows = 0;

    printf("Input # of rows: ");
    scanf("%d", &rows);

    maybePyramid(rows);

    return 0;
}