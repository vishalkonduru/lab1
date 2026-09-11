 

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[100];

    // Ask user for file name
    printf("Enter the name of the file to create: ");
    if (scanf("%99s", filename) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Open file in write mode ("w" creates a new file or overwrites if it exists)
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error creating file");
        return 1;
    }

    printf("File '%s' created successfully.\n", filename);

    // Optional: Write something to the file
    fprintf(fp, "This is a new file created in C.\n");

    // Close the file
    if (fclose(fp) != 0) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}

