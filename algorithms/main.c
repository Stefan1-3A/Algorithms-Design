#include <stdio.h>
#include <stdlib.h>
#include "distribution.h"
#include <limits.h>


int main() {
    int choice;                                                                                                     //
    printf("Select which option you would like to perform:\n");                                                     //
    printf("\n 1. Generate new experimental data\n");                                                                  // This is for picking a choice before proceeding with
    printf(" 2. Run distribution with books\n");                                                                     // the program
    printf("\nEnter choice (1 or 2): ");                                                                              //
    scanf("%d", &choice);                                                                                           //

    if (choice == 1) {                                                                                              //
        char filename[256];                                                                                         //
        int numberOfBooks;                                                                                          //
        printf("Enter a filename for the new experimental data: ");                                                 //
        scanf("%s", filename);                                                                                      // This serves for picking an option and displaying it on the console before
        printf("Enter a number of books to generate ( recommended amount 9, but your choice ): ");                  // proceeding with the program
        scanf("%d", &numberOfBooks);                                                                                //
        generateData(filename, numberOfBooks);                                                                      //
    } else if (choice == 2) {                                                                                       //
    FILE *file = fopen("books.txt", "r");                                                                           //
    if (!file) {                                                                                                    // This serves for opening a .txt file from the file directory
        perror("ERROR: There has been a problem when trying to open this file!");                                   // and if theres any obstacles that prevents the opening an error is displayed
        return 1;                                                                                                   //
    }                                                                                                               //

    int *books = NULL;                                                                                              // Pointer to hold the book sizes
    int size = 0;                                                                                                   // The number of books
    int capacity = 10;                                                                                              // Initial capacity for dynamic array
    books = malloc(capacity * sizeof(int));                                                                         // Allocates memory

    if (!books) {                                                                                                   //
        perror("ERROR: Failed to allocate memory");                                                                 //
        fclose(file);                                                                                               // This serves in a case theres any obstacles that prevents allocating memory
        return 1;                                                                                                   //
    }                                                                                                               //

    while (fscanf(file, "%d", &books[size]) == 1) {                                                                 //
        size++;                                                                                                     //
        if (size >= capacity) {                                                                                     //
            capacity *= 2;                                                                                          //
            books = realloc(books, capacity * sizeof(int));                                                         //
            if (!books) {                                                                                           // This serves for reading integers from the file
                perror("ERROR: Failed to reallocate memory");                                                       // and increasing the capacity as needed
                fclose(file);                                                                                       //
                return 1;                                                                                           //
            }                                                                                                       //
        }                                                                                                           //
    }                                                                                                               //

    fclose(file);                                                                                                   // This simply closes the file

    int employees[EMPLOYEES] = {0};                                                                                 // This is array to hold pages assigned to employees

    greedyDistribution(books, size, employees);                                                                     // Calls the distribution function

    free(books);                                                                                                    // Frees the dynamically allocated memory
    return 0;                                                                                                       //
}
return 0;
}
