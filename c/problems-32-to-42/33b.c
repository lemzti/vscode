// Write a for-loop that will produce the following sequence:
// 7, 9, 11, 13, ..., 67

#include <stdio.h>


int main() {

    for (int i = 7; i <= 67; i += 2) {
        printf("%4d", i);
    }

    return 0;
}