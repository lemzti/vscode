#include <stdio.h>

#define MAX_STUDENTS 40
#define QUIZZES 5

void printTabs(int n);

int main() {
    // Ma'am, need "quiz-data.txt" file in same folder sa .c file
    // pede ra rename file vvvvv
    FILE *fp = fopen("quiz-data.txt", "r");
    if (fp == NULL) {
        printf("Can't open file... dang\n");
        return 1;
    }

    int studentID[MAX_STUDENTS];
    int scores[MAX_STUDENTS][QUIZZES];
    int numStudents = 0;

    // read data from file
    while (numStudents < MAX_STUDENTS &&
           fscanf(fp, "%d %d %d %d %d %d",
                  &studentID[numStudents],
                  &scores[numStudents][0],
                  &scores[numStudents][1],
                  &scores[numStudents][2],
                  &scores[numStudents][3],
                  &scores[numStudents][4]) == 6) {
        numStudents++;
    }
    fclose(fp);

    int tabCount = 2; // number of tabs to use between columns

    // header
    printf("Student");
    for (int q = 0; q < QUIZZES; q++) {
        printTabs(tabCount);
        printf("Quiz %d", q + 1);
    }
    printf("\n");

    // student scores
    for (int s = 0; s < numStudents; s++) {
        printf("%d", studentID[s]);
        for (int q = 0; q < QUIZZES; q++) {
            printTabs(tabCount);
            printf("%d", scores[s][q]);
        }
        printf("\n");
    }

    // highest row
    printf("Highest");
    for (int q = 0; q < QUIZZES; q++) {
        int high = scores[0][q];
        for (int s = 0; s < numStudents; s++)
            if (scores[s][q] > high) high = scores[s][q];
        printTabs(tabCount);
        printf("%d", high);
    }
    printf("\n");

    // lowest row
    printf("Lowest");
    for (int q = 0; q < QUIZZES; q++) {
        int low = scores[0][q];
        for (int s = 0; s < numStudents; s++)
            if (scores[s][q] < low) low = scores[s][q];
        printTabs(tabCount);
        printf("%d", low);
    }
    printf("\n");

    // average row
    printf("Average");
    for (int q = 0; q < QUIZZES; q++) {
        int sum = 0;
        for (int s = 0; s < numStudents; s++) sum += scores[s][q];
        double avg = (double)sum / numStudents;
        printTabs(tabCount);
        printf("%.1f", avg);
    }
    printf("\n");

    return 0;
}

void printTabs(int n) {
    for (int i = 0; i < n; i++) {
        printf("\t");
    }
}