// Write a for-loop that will produce the following sequence:
// The sum of the numbers between 1 and 15 inclusive

// Liboga sa problem Miss hahahaha
// Between pa, inclusive pa

#include <stdio.h>


int main() {

    int sum = 0;

    for (int i = 1; i <= 15; i++) {
        sum += i;
    }

    printf("Sum: %d", sum);

    return 0;
}