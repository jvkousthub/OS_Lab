#include<stdio.h>
#include<string.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE *source;
    FILE *destination;
    char ch;

    // Check correct number of arguments
    if (argc != 3) {
        printf("Syntax: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // Open source file for reading
    source = fopen(argv[1], "r");
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }

    // Open destination file for writing
    destination = fopen(argv[2], "w");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);  // Close source before exiting
        return 1;
    }

    // Copy file contents
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    // Close files
    fclose(source);
    fclose(destination);

    printf("File copied successfully\n");
    return 0;
}

