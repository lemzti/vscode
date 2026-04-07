#include <stdio.h>


void decimalToBinary(int num);


int main() {

    int num = 0, binary = 0;
    char flag;

    do {
        printf("Enter decimal number: ");
        scanf("%d", &num);

        decimalToBinary(num);

        printf("\nPress any key to continue [n-to stop]: ");
        scanf(" %c", &flag);

    } while (flag != 'n' && flag != 'N');
    
    return 0;
}


void decimalToBinary(int num) {

    printf("Binary = ");

    int place = 1;
    while (place <= (num / 2)) {
        place *= 2;
    }

    while (place > 0) {
        int bit = num / place;
        printf("%d", bit);

        num %= place;
        place /= 2;
    }
}
