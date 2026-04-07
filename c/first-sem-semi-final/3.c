#include <stdio.h>


int isPalindrome(int num);


int main() {

    const int FIRST = 1, LAST = 1000;

    char flag;

    do {
        int isFirst = 1;

        printf("Palindromic numbers from %d to %d: ", FIRST, LAST);

        for (int i = FIRST; i <= LAST; i++) {
            if (isPalindrome(i)) {
                if (!isFirst) {
                    printf(", ");
                }
                printf("%d", i);
                isFirst = 0;
            }
        }

        printf("\nPress any key to continue [n-to stop]: ");
        scanf(" %c", &flag);

    } while (flag != 'n' && flag != 'N');

    return 0;
}


int isPalindrome(int num) {

    int n = num, reversed = 0, digit = 0;
    
    while (n > 0) {
        digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return num == reversed;
}