#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the mean of the array

double mean(float *array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Function to calculate the mode of the array

float mode(float *array, int size) {
    float mode = array[0];
    int maxCount = 0;
    // Count the frequency of each element
    for (int i = 0; i < size; i++) {
        int count = 0;
        // Count the frequency of the current element
        for (int j = 0; j < size; j++) {
            if (array[j] == array[i]) {
                count++;
            }
        }
        // Check if the current element is the mode
        if (count > maxCount) {
            maxCount = count;
            mode = array[i];
        }
    }
    return mode;
}

// Function to calculate the geometric mean of the array

double geometric_mean(float *array, int size) {
    double product = 1;
    for (int i = 0; i < size; i++) {
        product *= array[i];
    }
    double Nth_root = 1.0/size;
    return pow(product, Nth_root);
}

// Function to calculate the harmonic mean of the array

float harmonic_mean(float *array, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += 1 / array[i];
    }
    return size / sum;
}

// Function to calculate the median of the array

float median(float *array, int size) {
    // Sort the array
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                float temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // Compute the median
    float median;
    // If the size of the array is even, the median is the average of the two middle elements
    if (size % 2 == 0) {
        median = (array[size / 2 - 1] + array[size / 2]) / 2;
    } 
    // If the size of the array is odd, the median is the middle element
    else {
        median = array[size / 2];
    }
    return median;
}

// Function to calculate the standard deviation of the array

double standard_deviation(float *array, int size) {
    double mean_for_std = mean(array, size);
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (array[i] - mean_for_std) * (array[i] - mean_for_std);
    }
    return sqrt(sum / size);
}

// Function to read the data from the file and store it in the array

float *read_data(const char *filename, int *size, int *capacity) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error:%s is NULL\n", filename);
        exit(1);
    }
    // Initialize the array with 20 elements
    float *array = malloc(*capacity * sizeof(float));
    if (array == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(1);
    }
    int i = 0;
    // Read the data from the file
    while (fscanf(file, "%f", &array[i]) == 1) {
        i++;
        // If the array is full, allocate a new array with double the capacity
        if (i == *capacity) {
            // Double the capacity of the array
            *capacity *= 2;
            // If the array is full, allocate a new array with double the capacity
            float *new_array = malloc(*capacity * sizeof(float));
            if (new_array == NULL) {
                fprintf(stderr, "Error: Unable to allocate memory\n");
                exit(1);
            }
            for (int j = 0; j < i; j++) {
                new_array[j] = array[j];
            }
            // Free the old array
            free(array);
            array = new_array;
        }
    }
    *size = i;
    fclose(file);
    return array;
}

// Function to print all statistics 
void print_statistics(float *array, int size) {
    printf("Result:\n");
    printf("-----------------\n");
    printf("      Num values: %d\n", size);
    printf("            Mean: %.3f\n", mean(array, size));
    printf("            Mode: %.3f\n", mode(array, size));
    printf("  Geometric Mean: %.3f\n", geometric_mean(array, size));
    printf("   Harmonic Mean: %.3f\n", harmonic_mean(array, size));
    printf("          Median: %.3f\n", median(array, size));
    printf("           Stddv: %.3f\n", standard_deviation(array, size));
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        printf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    int size = 20;
    int capacity = 20;
    // Initialize the array with 20 elements. If the array is full, duplicate it into a double size array. And free the old array.
    float *array = read_data(argv[1], &size, &capacity);
    print_statistics(array, size);
    free(array);
    return 0;
}
