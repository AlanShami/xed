/*
Name: Alan Shami
Course: CS530 - System Software
Term: Spring 2024
Assignment #1: xed program
File Name: main.c
*/

#include "method.h"
#include <string.h>

int main(int argc, char *argv[]) {
    // Check for minimum number of arguments
    if (argc < 2) {
        printf("Usage: %s [-b] <filename>\n", argv[0]);
        return 1;
    }

    int binary = 0;
    char *filename;

    // Parse command line arguments
    if (argc == 3 && strcmp(argv[1], "-b") == 0) {
        binary = 1;
        filename = argv[2];
    } else {
        filename = argv[1];
    }

    // Open file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Print file contents in the specified format
    if (binary) {
        printBinary(file);
    } else {
        printHex(file);
    }

    // Close file
    fclose(file);
    return 0;
}
