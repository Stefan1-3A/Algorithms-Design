#include "distribution.h"
#include "utils.h"
#include <limits.h>


void greedyDistribution(int books[], int n, int employees[EMPLOYEES]) {                                                             // This is for sorting books in descending order
    qsort(books, n, sizeof(int), compare);                                                                                          //

    int pages[EMPLOYEES] = {0};                                                                                                     // Simply initializes pages array

    for (int i = 0; i < n; i++) {                                                                                                   //
        int minIndex = 0;                                                                                                           //
        for (int j = 1; j < EMPLOYEES; j++) {                                                                                       //
            if (pages[j] < pages[minIndex]) {                                                                                       //
                minIndex = j;                                                                                                       // This serves for assigning books to the employee with the
            }                                                                                                                       // least pages
        }                                                                                                                           //
        pages[minIndex] += books[i];                                                                                                //
    }                                                                                                                               //

    int maxPages = pages[0], minPages = pages[0];                                                                                   //
    for (int i = 1; i < EMPLOYEES; i++) {                                                                                           //
        if (pages[i] > maxPages) maxPages = pages[i];                                                                               //
        if (pages[i] < minPages) minPages = pages[i];                                                                               //
    }                                                                                                                               // This serves for outputting the distribution and calculating
    printf("Greedy Distribution: ");                                                                                                // the minDiff (minimum difference)
    for (int i = 0; i < EMPLOYEES; i++) {                                                                                           //
        printf("%d ", pages[i]);                                                                                                    //
    }                                                                                                                               //
    printf("\nMin Difference: %d\n", maxPages - minPages);                                                                          //
}                                                                                                                                   //
