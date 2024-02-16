/*
Name: Alan Shami
Course: CS530 - System Software
Term: Spring 2024
Assignment #1: xed program
File Name: methods.c
*/

#include "method.h"
#include <ctype.h>

void printHex(FILE *file) {
    unsigned char buffer[16];
    size_t bytesRead;
    unsigned long address = 0;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        printf("%07lx: ", address);
        for (size_t i = 0; i < 16; i++) {
            if (i < bytesRead) {
                printf("%02x", buffer[i]);
            } else {
                printf("  ");
            }
            if (i % 2 != 0) printf(" ");
        }

        for (size_t i = 0; i < bytesRead; i++) {
            printByteAsChar(buffer[i]);
        }

        printf("\n");
        address += 16;
    }
}

void printBinary(FILE *file) {
    unsigned char byte;
    unsigned long address = 0;
    int column = 0;
    int firstByte = 1; //Track first byte

    while (fread(&byte, 1, 1, file) == 1) {
        if (column % 16 == 0) {
            if (!firstByte) {
                // Check if this is not the first byte
                printf(" ");
            }
            printf("%s%07lx: ", firstByte ? "" : "\n", address); // Added to Remove newline for the first line
            address += 16;
            firstByte = 0; // Clear the flag after the first byte has been processed
        }

        for (int i = 7; i >= 0; i--) {
            printf("%c", (byte & (1 << i)) ? '1' : '0');
        }

        printByteAsChar(byte);
        column++;
    }
    if (column > 0) printf("\n"); // Ensure there's a newline after the last line if any bytes were printed
}


void printByteAsChar(unsigned char byte) {
    if (isprint(byte)) {
        printf("%c", byte);
    } else {
        printf(".");
    }
}
