// Write a for-loop that will produce the following sequence:
// The first 50 numbers in the series 1, 4, 7, 10, ... 
// Calculate the total (1 + 4 + 7 + 10 + ...)

#include <stdio.h>


int main() {

    int sum = 0; 
    int num = 1, increment = 3;

    for (int i = 1; i <= 50; i++) {
        printf("%4d", num);

        sum += num;
        num += increment;
    }

    printf("\nSum: %d", sum);

    return 0;
}