#include <stdio.h>


void coolCenteredPyramid(int rows);


int main() {

    const int ROWS = 5;
    // more than 9 and the formatting that relies on spaces breaks.
    // since the problem didn't mention any input and the output shows a limit of 5,
    // i will assume the number spacing isn't dynamic because i don't want to think
    // too hard about the solution (i already have an idea but nah)

    char flag;

    do {
        coolCenteredPyramid(ROWS);

        printf("\nPress any key to continue [n-to stop]: ");
        scanf(" %c", &flag);

    } while (flag != 'n' && flag != 'N');
    
    return 0;
}


void coolCenteredPyramid(int rows) {

    for (int i = 1; i <= rows; i++) {
        
        // print spaces
        for (int j = (rows - i); j >= 1; j--) {
            printf("  ");
        }

        // print number up to i
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        // print missing numbers and stuff, inverted
        // to know what in the balls I'm talking about,
        // see what happens when this for-loop is commented out
        for (int j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }

        printf("\n");
    }
}
