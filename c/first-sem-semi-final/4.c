#include <stdio.h>


int isArmstrongNumber(int num);
int getDigits(int num);


int main() {

    int num = 0;
    char flag;

    do {
        printf("Enter a number: ");
        scanf("%d", &num);
        
        if (isArmstrongNumber(num)) {
            printf("%d is an Armstrong number.", num);
        } else {
            printf("%d is NOT an Armstrong number.", num);
        }

        printf("\nPress any key to continue [n-to stop]: ");
        scanf(" %c", &flag);

    } while (flag != 'n' && flag != 'N');

    return 0;
}


int isArmstrongNumber(int num) {

    if (num == 0) return 1;

    int n = num, sum = 0;
    int numDigits = getDigits(n);
    
    while (n > 0) {
        int digit = n % 10, powered = digit;

        for (int i = 1; i < numDigits; i++)  {
            powered *= digit;
        }

        sum += powered;
        n /= 10;
    }

   return num == sum;
}


int getDigits(int num) {

    int d = 0;

    while (num > 0) {
        d += 1;
        num /= 10;
    }

    return d;
}