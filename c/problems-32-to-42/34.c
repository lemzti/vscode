/*
Write a program that prompts the user to enter an integer, n,
and then n floating-point numbers. As the numbers are read, the program
will calculate the average of the positive numbers.
*/

#include <stdio.h>


int main() {

    int n = 0;
    int nPositive = 0;
    float average = 0;

    printf("Input a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("You input a negative number. Taking its absolute value...");
        n = -n;
    } // if negative ang input n, for-loop will not run

    printf("\nInput %d decimal/s (separated by spaces): ", n);

    for (int i = 1; i <= n; i++) {
        float f = 0;
        scanf("%f", &f);

        if (f > 0) {
            average += f;
            nPositive++;
        }
    }

    if (nPositive > 0) {
        average /= nPositive;
    }

    printf("Average: %.2f", average);

    return 0;
}