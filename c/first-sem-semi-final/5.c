#include <stdio.h>


int isPalindrome(int num);


int main() {

    int num = 0;
    char flag;
    
    do {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (isPalindrome(num)) {
            printf("%d is a palindrome.", num);
        } else {
            printf("%d is NOT a palindrome.", num);
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