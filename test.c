#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary using recursion
void decimalToBinary(int n, char *binary, int index) {
    if (n > 0) {
        decimalToBinary(n / 2, binary, index - 1);
        binary[index] = (n % 2) + '0';
    } else if (index >= 0) {
        binary[index] = '0';
        decimalToBinary(n / 2, binary, index - 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <n> <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    const char *sourceFile = argv[2];
    const char *destinationFile = argv[3];

    FILE *source = fopen(sourceFile, "r");
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }

    int decimal;
    char binary[17]; // 16 bits for binary + 1 for null terminator

    for (int i = 0; i < n && fscanf(source, "%d", &decimal) != EOF; i++) {
        memset(binary, '0', sizeof(binary) - 1);
        binary[16] = '\0';
        decimalToBinary(decimal, binary, 15);

        fprintf(destination, "The binary equivalent of %d is %s\n", decimal, binary);
    }

    fclose(source);
    fclose(destination);

    // Display the content of the output file
    destination = fopen(destinationFile, "r");
    if (destination == NULL) {
        perror("Error opening destination file for reading");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), destination) != NULL) {
        printf("%s", line);
    }

    fclose(destination);

    return 0;
}
