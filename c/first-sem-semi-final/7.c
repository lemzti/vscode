#include <stdio.h>


void displayPrimes(int n);
int isPrime(int n);
int intSqrt(int n);


int main() {

    int n = 0;
    char flag;

    do {
        printf("Enter limit: ");
        scanf("%d", &n);

        displayPrimes(n);

        printf("\nPress any key to continue [n-to stop]: ");
        scanf(" %c", &flag);

    } while (flag != 'n' && flag != 'N');
    
    return 0;
}


void displayPrimes(int limit) {

    int isFirst = 1;

    printf("Prime numbers: ");

    for (int i = 2; i <= limit; i++) {  
        if ( !isPrime(i) ) {
            continue;
        }

        if (!isFirst) {
                printf(", ");
        }
        printf("%d", i);
        isFirst = 0;
    }
}


int isPrime(int n) {

    if (n < 2) {
        return 0;
    } else {
        // trial division
        for (int i = 2; i <= intSqrt(n); i++) {
            if (n % i == 0) {
                return 0;
            }
        }
    }

    return 1;
}


// chatgpt on how to find integral square root:
// "what’s the largest number y such that y * y <= x?"
int intSqrt(int n) {

    int root = 1;

    do {
        root++;
    } while (root * root <= n);
    root--;

    return root;
}