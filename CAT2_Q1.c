/*
PURITY TAIKU
CT100/G/26152/25
PROMPTING USER TO STORE DATA ELEMENTS
*/
#include <stdio.h>

int main() {
    // Declare and initialize the array
    int scores[2][2] = {
        {65, 92},
        {84, 72}
    };

    // Print the array using nested loops
    printf("The elements of the array are:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }

    return 0;

}
