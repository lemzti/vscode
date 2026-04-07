// Write a for-loop that will produce the following sequence:
// The sum of the odd numbers between 15 and 45 inclusive

// Liboga sa problem Miss hahahaha
// Between pa, inclusive pa

#include <stdio.h>


int main() {

    int sum = 0;

    for (int i = 15; i <= 45; i += 2) {
        if (i % 2 == 0) continue;
        sum += i;
    }

    printf("Sum: %d", sum);

    return 0;
}