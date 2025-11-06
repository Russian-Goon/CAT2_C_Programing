/* 
Name: SAMMY KIOKO KAMENE
Reg No: CT101/G/26524/25
Date: 6/11/2025
Description: A C program that reads integers from a file, processes them, 
             and writes results to another file.
*/

#include <stdio.h>
#include <stdlib.h>

void writeIntegersToFile();
void processIntegers();
void displayFileContents();

int main() {
    writeIntegersToFile();
    processIntegers();
    displayFileContents();
    return 0;
}

// Function to input 10 integers and save them to input.txt
void writeIntegersToFile() {
    FILE *fptr;
    int i, num;

    fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        printf("Error: Cannot open input.txt for writing.\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &num);
        fprintf(fptr, "%d\n", num);
    }

    fclose(fptr);
    printf("\nNumbers successfully written to input.txt\n\n");
}

// Function to read integers, calculate sum and average, and write to output.txt
void processIntegers() {
    FILE *input, *output;
    int num, count = 0, sum = 0;
    float avg;

    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error: Cannot open input.txt for reading.\n");
        exit(1);
    }

    while (fscanf(input, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    fclose(input);

    if (count == 0) {
        printf("No integers found in input.txt.\n");
        return;
    }

    avg = (float) sum / count;

    output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error: Cannot open output.txt for writing.\n");
        exit(1);
    }

    fprintf(output, "Sum = %d\nAverage = %.2f\n", sum, avg);
    fclose(output);
    printf("Results successfully written to output.txt\n\n");
}

// Function to display the contents of both files
void displayFileContents() {
    FILE *fptr;
    char ch;

    printf("----- Contents of input.txt -----\n");
    fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        printf("Error: Cannot open input.txt for reading.\n");
        exit(1);
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);

    printf("\n----- Contents of output.txt -----\n");
    fptr = fopen("output.txt", "r");
    if (fptr == NULL) {
        printf("Error: Cannot open output.txt for reading.\n");
        exit(1);
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);

    printf("\n---------------------------------\n");
}