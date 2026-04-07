#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50
#define ROWS 5
#define COLS 10

void printArray(int arr[]);
void selectionSort(int arr[], int size, int *comp, int *moves);
void bubbleSort(int arr[], int size, int *comp, int *moves);
void insertionSort(int arr[], int size, int *comp, int *moves);
void fillRandom(int arr[]);
void fillNearlySorted(int arr[]);

int main() {
    srand(time(NULL));

    int original[SIZE];

    // random array
    printf("=== RANDOM ARRAY ===\n");
    fillRandom(original);
    printArray(original);

    // create copies for each sort
    int arr[SIZE];

    // selection
    for (int i = 0; i < SIZE; i++) arr[i] = original[i];
    int comp = 0, moves = 0;
    selectionSort(arr, SIZE, &comp, &moves);
    printf("--- Selection Sort ---\n");
    printArray(arr);
    printf("Comparisons: %d, Moves: %d\n\n", comp, moves);

    // bubble
    for (int i = 0; i < SIZE; i++) arr[i] = original[i];
    comp = moves = 0;
    bubbleSort(arr, SIZE, &comp, &moves);
    printf("--- Bubble Sort ---\n");
    printArray(arr);
    printf("Comparisons: %d, Moves: %d\n\n", comp, moves);

    // insertion
    for (int i = 0; i < SIZE; i++) arr[i] = original[i];
    comp = moves = 0;
    insertionSort(arr, SIZE, &comp, &moves);
    printf("--- Insertion Sort ---\n");
    printArray(arr);
    printf("Comparisons: %d, Moves: %d\n\n", comp, moves);

    // nearly sorted array
    printf("=== NEARLY SORTED ARRAY ===\n");
    fillNearlySorted(original);
    printArray(original);

    // selection
    for (int i = 0; i < SIZE; i++) arr[i] = original[i];
    comp = moves = 0;
    selectionSort(arr, SIZE, &comp, &moves);
    printf("--- Selection Sort ---\n");
    printArray(arr);
    printf("Comparisons: %d, Moves: %d\n\n", comp, moves);

    // bubble
    for (int i = 0; i < SIZE; i++) arr[i] = original[i];
    comp = moves = 0;
    bubbleSort(arr, SIZE, &comp, &moves);
    printf("--- Bubble Sort ---\n");
    printArray(arr);
    printf("Comparisons: %d, Moves: %d\n\n", comp, moves);

    // insertion
    for (int i = 0; i < SIZE; i++) arr[i] = original[i];
    comp = moves = 0;
    insertionSort(arr, SIZE, &comp, &moves);
    printf("--- Insertion Sort ---\n");
    printArray(arr);
    printf("Comparisons: %d, Moves: %d\n\n", comp, moves);

    return 0;
}

// print array in 5x10 matrix
void printArray(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%5d", arr[i]);
        if ((i + 1) % COLS == 0) printf("\n");
    }
    printf("\n");
}

// selection sort with comparison and move counting
void selectionSort(int arr[], int size, int *comp, int *moves) {
    int i, j, minIndex;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            (*comp)++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i]; arr[i] = arr[minIndex]; arr[minIndex] = temp;
            *moves += 3; // counting as 3 moves for swap
        }
    }
}

// bubble sort with comparison and move counting
void bubbleSort(int arr[], int size, int *comp, int *moves) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            (*comp)++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
                *moves += 3; // swap counts as 3 moves
            }
        }
    }
}

// insertion sort with comparison and move counting
void insertionSort(int arr[], int size, int *comp, int *moves) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        (*moves)++; // moving key
        j = i - 1;
        while (j >= 0 && (++(*comp), arr[j] > key)) {
            arr[j + 1] = arr[j];
            (*moves)++;
            j--;
        }
        arr[j + 1] = key;
        (*moves)++;
    }
}

// fill random array
void fillRandom(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000 + 1;
    }
}

// fill nearly sorted array
void fillNearlySorted(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
        if ((i + 1) % 10 == 0) arr[i] -= 5;
    }
}