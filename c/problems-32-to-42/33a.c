// Write a for-loop that will produce the following sequence:
// 6, 8, 10, 12, ..., 66

#include <stdio.h>


int main() {

    for (int i = 6; i <= 66; i += 2) {
        printf("%4d", i);
    }

    return 0;
}