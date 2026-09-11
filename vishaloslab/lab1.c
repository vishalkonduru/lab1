#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[256];

    // Step 1: Create the file and write "hii vishal"
    fp = fopen("simple.txt", "w");
    if (fp == NULL) {
        perror("Error creating file");
        return 1;
    }

    fprintf(fp, "hii vishal\n");

    if (fclose(fp) != 0) {
        perror("Error closing file after writing");
        return 1;
    }

    // Step 2: Open the file again for reading
    fp = fopen("simple.txt", "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    printf("Contents of 'simple.txt':\n");

    // Step 3: Read and print contents
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // Step 4: Close the file
    if (fclose(fp) != 0) {
        perror("Error closing file after reading");
        return 1;
    }

    return 0;
}
