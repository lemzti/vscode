#include <stdio.h>


double harmonicSum(int n);


int main() {

    int n = 0;
    double sum = 0;
    char flag;

    do {
        printf("Enter n: ");
        scanf("%d", &n);

        sum = harmonicSum(n);

        printf("Sum = %lf", sum);

        printf("\nPress any key to continue [n-to stop]: ");
        scanf(" %c", &flag);

    } while (flag != 'n' && flag != 'N');
    
    return 0;
}


double harmonicSum(int n) {

    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }

    return sum;
}