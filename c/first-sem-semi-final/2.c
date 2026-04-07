#include <stdio.h>


int isStrongNumber(long long num);
long long factorial(int num);


int main() {

    long long num = 0;
    char flag;

    do {
        printf("Enter a number: ");
        scanf("%lld", &num);

        if (isStrongNumber(num)) {
            printf("%lld is a Strong number.", num);
        } else {
            printf("%lld is NOT a Strong number.", num);
        }

        printf("\nPress any key to continue [n-to stop]: ");
        scanf(" %c", &flag);

    } while (flag != 'n' && flag != 'N');

    return 0;
}


int isStrongNumber(long long num) {

    long long n = num;
    long long sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += factorial(digit);
        n /= 10;
    }

    return sum == num;
}


long long factorial(int num) {
    long long f = 1;

    for (int i = 1; i <= num; i++) {
        f *= i;
    }

    return f;
}