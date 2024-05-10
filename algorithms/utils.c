#include "distribution.h"

/*
int min(int a, int b) {                                   //
    return a < b ? a : b;                                 // This function serves to find the minimum of two numbers
}                                                         //

int max(int a, int b) {                                   //
    return a > b ? a : b;                                 // This function serves to find the maximum of two numbers
}                                                         //

int abs_diff(int a, int b) {                              //
    return a > b ? a - b : b - a;                         // This function serves to to calculate the absolute difference
}                                                         //
*/

int compare(const void *a, const void *b) {               //
    return *(int*)b - *(int*)a;                           // This serves for sorting in descending order
}                                                         //
