#include <stdio.h>


int isPerfectNumber(int num);


int main() {

    int num = 0;
    char flag;

    do {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (isPerfectNumber(num)) {
            printf("%d is a perfect number.", num);
        } else {
            printf("%d is NOT a perfect number.", num);
        }

        printf("\nPress any key to continue [n-to stop]: ");
        scanf(" %c", &flag);

    } while (flag != 'n' && flag != 'N');

    return 0;
}


int isPerfectNumber(int num) {

    int sum = 0;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return sum == num;
}