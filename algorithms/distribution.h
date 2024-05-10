#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

//#define BOOKS 9
#define EMPLOYEES 3                                                                            // Defines the number of employees
                                                                                               //
//int min(int a, int b);                                                                         // This function serves to find the minimum of two numbers
//int max(int a, int b);                                                                         // This function serves to find the maximum of two numbers
//int abs_diff(int a, int b);                                                                    // This function serves to to calculate the absolute difference
//void findBestDistribution(int books[], int n, int index, int employees[EMPLOYEES]);            // This recursive function serves to find the most balanced(best) way to assign books
void greedyDistribution(int books[], int n, int employees[EMPLOYEES]);                         // This recursive function serves for sorting

#endif // DISTRIBUTION_H
