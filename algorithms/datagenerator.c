#include "datagenerator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generateData(const char *baseFilename, int count) {                                                        //
    char filename[256];                                                                                         //
    if (strstr(baseFilename, ".txt") == NULL) {                                                                 //
        snprintf(filename, sizeof(filename), "%s.txt", baseFilename);                                           // This serves for  generating a .txt file with random book sizes
    } else {                                                                                                    // it also ensures the filename is properly formatted
        strncpy(filename, baseFilename, sizeof(filename));                                                      //
        filename[sizeof(filename) - 1] = '\0';                                                                  //
    }                                                                                                           //

    printf("Creating file: %s\n", filename);                                                                    //
    FILE *file = fopen(filename, "w");                                                                          //
    if (!file) {                                                                                                // This serves for opening the file for writing
        perror("ERROR: There has been a problem when trying to open this file!");                               //
        return;                                                                                                 //
    }                                                                                                           //

    srand((unsigned int)time(NULL));                                                                            // This is for a random generator

    const int chunk_size = 1000000;                                                                             //
    int *buffer = malloc(chunk_size * sizeof(int));                                                             //
    if (!buffer) {                                                                                              //
        perror("ERROR: Failed to allocate memory");                                                             // This defines a reasonable chunk size and allocates a buffer
        fclose(file);                                                                                           //
        return;                                                                                                 //
    }                                                                                                           //

    int written = 0;                                                                                            //
    while (written < count) {                                                                                   //
        int limit = (count - written > chunk_size) ? chunk_size : count - written;                              //
        for (int i = 0; i < limit; i++) {                                                                       //
            buffer[i] = rand() % 1000 + 1;                                                                      // This serves for writing data in a file
        }                                                                                                       // it also generates random book sizes between 1 and 1000 pages
        for (int i = 0; i < limit; i++) {                                                                       //
            fprintf(file, "%d ", buffer[i]);                                                                    //
        }                                                                                                       //
        written += limit;                                                                                       //
    }                                                                                                           //

    free(buffer);                                                                                               // This frees the b uffer
    fclose(file);                                                                                               // Simply closes the file
    printf("Data generated and stored in %s\n", filename);                                                      //
}                                                                                                               //
