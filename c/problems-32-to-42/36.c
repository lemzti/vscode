/*
Write a program that asks the user to enter a list of integers.
The program is to determine the largest value entered and the number of times 
it was entered.

For example, if the following series is entered:
5 2 15 3 7 15 8 9 5 2 15 3 7

It would output that the largest value is 15 
and it was entered 3 times.
*/

#include <stdio.h>


int main() {

    int x = 0, largest = 0, frequency = 0, flag = 1;

    printf("Input a list of numbers (0 to stop): ");

    while (1) {
        scanf("%d", &x);
        if (x == 0) break;
        
        if (flag) {
            largest = x;
            frequency = 1;
            flag = 0;
        } else if (x > largest) {
            largest = x;
            frequency = 1;
        } else if (x == largest) {
            frequency++;
        }
    }

    printf("The largest value is %d and it was entered %d time(s).", largest, frequency);

    return 0;
}