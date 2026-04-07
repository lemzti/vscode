#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void printArray10(const int arr[], int n);
void printOddValues(const int arr[], int n);
void printOddIndexValues(const int arr[], int n);
int countEven(const int arr[], int n);
int sumArray(const int arr[], int n);
int findSmallestIndex(const int arr[], int n);
int findLargestIndex(const int arr[], int n);
int copyPositive(const int arr[], int posArr[]);
int copyNegative(const int arr[], int negArr[]);

int main() {
    srand(time(NULL));

    int arr[SIZE];

    // build the array with random 1–999,
    // but make divisibles of 3 and 7 negative
    for (int i = 0; i < SIZE; i++) {
        int val = rand() % 999 + 1;

        if (val % 3 == 0 || val % 7 == 0)
            val = -val;

        arr[i] = val;
    }

    printf("FULL ARRAY (10 per line):\n");
    printArray10(arr, SIZE);

    printf("\nODD VALUES (10 per line):\n");
    printOddValues(arr, SIZE);

    printf("\nVALUES AT ODD INDEX POSITIONS (10 per line):\n");
    printOddIndexValues(arr, SIZE);

    printf("\nCOUNT OF EVEN VALUES: %d\n", countEven(arr, SIZE));
    printf("SUM OF ALL VALUES: %d\n", sumArray(arr, SIZE));

    int smallestIndex = findSmallestIndex(arr, SIZE);
    int largestIndex  = findLargestIndex(arr, SIZE);

    printf("LOCATION OF SMALLEST VALUE: %d (value = %d)\n",
           smallestIndex, arr[smallestIndex]);
    printf("LOCATION OF LARGEST VALUE: %d (value = %d)\n",
           largestIndex, arr[largestIndex]);

    int posArr[SIZE], negArr[SIZE];
    int posCount = copyPositive(arr, posArr);
    int negCount = copyNegative(arr, negArr);

    printf("\nPOSITIVE VALUES (10 per line):\n");
    printArray10(posArr, posCount);

    printf("\nNEGATIVE VALUES (10 per line):\n");
    printArray10(negArr, negCount);

    return 0;
}

void printArray10(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%6d", arr[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    if (n % 10 != 0)
        printf("\n");
}

void printOddValues(const int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            printf("%6d", arr[i]);
            count++;
            if (count % 10 == 0)
                printf("\n");
        }
    }
    if (count % 10 != 0)
        printf("\n");
}

void printOddIndexValues(const int arr[], int n) {
    int count = 0;
    for (int i = 1; i < n; i += 2) {
        printf("%6d", arr[i]);
        count++;
        if (count % 10 == 0)
            printf("\n");
    }
    if (count % 10 != 0)
        printf("\n");
}

int countEven(const int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            count++;
    return count;
}

int sumArray(const int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int findSmallestIndex(const int arr[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[idx])
            idx = i;
    return idx;
}

int findLargestIndex(const int arr[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[idx])
            idx = i;
    return idx;
}

int copyPositive(const int arr[], int posArr[]) {
    int j = 0;
    for (int i = 0; i < SIZE; i++)
        if (arr[i] > 0)
            posArr[j++] = arr[i];
    return j;
}

int copyNegative(const int arr[], int negArr[]) {
    int j = 0;
    for (int i = 0; i < SIZE; i++)
        if (arr[i] < 0)
            negArr[j++] = arr[i];
    return j;
}
