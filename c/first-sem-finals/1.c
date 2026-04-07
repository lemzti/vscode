#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int arr[100];
    int i, j;

    // fill array with random integers 1–200 range
    for (i = 0; i < 100; i++) {
        arr[i] = rand() % 200 + 1;
    }

    int totalSearches = 100;
    int successfulSearches = 0;
    int totalTests = 0;

    // do 100 searches
    for (i = 0; i < totalSearches; i++) {
        int target = rand() % 200 + 1;
        int found = 0;
        int testsThisSearch = 0;

        // sequential search
        for (j = 0; j < 100; j++) {
            if ( (testsThisSearch++, arr[j] == target) ) {
                found = 1;
                break;
            }
        }

        if (found) {
            successfulSearches++;
        }

        totalTests += testsThisSearch;
    }

    // statistic stuff
    double successPercentage =
        (successfulSearches / (double) totalSearches) * 100.0;

    double averageTests =
        totalTests / (double) totalSearches;

    // pwint eff
    printf("Number of searches completed: %d\n", totalSearches);
    printf("Number of successful searches: %d\n", successfulSearches);
    printf("Percentage of successful searches: %.2f%%\n", successPercentage);
    printf("Average number of tests per search: %.2f\n", averageTests);

    return 0;
}