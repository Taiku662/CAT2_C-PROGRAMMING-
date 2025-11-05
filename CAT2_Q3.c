/*
Purity Taiku 
CT100/G/25152/25

*/
    #include <stdio.h>
#include <stdlib.h>

// Function prototypes
void inputIntegersToFile();
void processIntegers();
void displayFiles();
int checkFileError(FILE *file, const char *filename);

int main() {
    int choice;
    
    do {
        printf("\n=== Integer Processing Program ===\n");
        printf("1. Input 10 integers to file\n");
        printf("2. Process integers and calculate sum/average\n");
        printf("3. Display file contents\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                inputIntegersToFile();
                break;
            case 2:
                processIntegers();
                break;
            case 3:
                displayFiles();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    } while(choice != 4);
    
    return 0;
}

// Function to check for file errors
int checkFileError(FILE *file, const char *filename) {
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }
    return 0;
}

// Function 1: Input 10 integers and store in "input.txt"
void inputIntegersToFile() {
    FILE *inputFile;
    int num, i;
    
    inputFile = fopen("input.txt", "w");
    if (checkFileError(inputFile, "input.txt")) {
        return;
    }
    
    printf("Enter 10 integers:\n");
    for(i = 0; i < 10; i++) {
        printf("Integer %d: ", i + 1);
        scanf("%d", &num);
        fprintf(inputFile, "%d\n", num);
    }
    
    fclose(inputFile);
    printf("Successfully wrote 10 integers to 'input.txt'\n");
}

// Function 2: Read integers, calculate sum and average, write to "output.txt"
void processIntegers() {
    FILE *inputFile, *outputFile;
    int num, sum = 0, count = 0;
    float average;
    
    // Open input file for reading
    inputFile = fopen("input.txt", "r");
    if (checkFileError(inputFile, "input.txt")) {
        return;
    }
    
    // Read integers and calculate sum
    while(fscanf(inputFile, "%d", &num) != EOF) {
        sum += num;
        count++;
    }
    fclose(inputFile);
    
    // Check if we read exactly 10 numbers
    if (count != 10) {
        printf("Warning: Expected 10 integers but found %d in input.txt\n", count);
    }
    
    // Calculate average
    average = (float)sum / count;
    
    // Open output file for writing
    outputFile = fopen("output.txt", "w");
    if (checkFileError(outputFile, "output.txt")) {
        return;
    }
    
    // Write results to output file
    fprintf(outputFile, "Sum: %d\n", sum);
    fprintf(outputFile, "Average: %.2f\n", average);
    fprintf(outputFile, "Number of integers processed: %d\n", count);
    
    fclose(outputFile);
    printf("Successfully processed data and wrote results to 'output.txt'\n");
    printf("Sum: %d, Average: %.2f\n", sum, average);
}

// Function 3: Display contents of both files in formatted manner
void displayFiles() {
    FILE *inputFile, *outputFile;
    int num, count = 0;
    char line[100];
    
    // Display input.txt contents
    printf("\n=== Contents of input.txt ===\n");
    inputFile = fopen("input.txt", "r");
    if (checkFileError(inputFile, "input.txt")); {
        return;
    }
    
    printf("Integers stored in input.txt:\n");
    while(fscanf(inputFile, "%d", &num) != EOF) {
        printf("Number %d: %d\n", ++count, num);
    }
    fclose(inputFile);
    
    if (count == 0) {
        printf("No integers found in input.txt\n");
    }
    
    // Display output.txt contents
    printf("\n=== Contents of output.txt ===\n");
    outputFile = fopen("output.txt", "r");
    if (checkFileError(outputFile, "output.txt")) {
        return;
    }
    
    