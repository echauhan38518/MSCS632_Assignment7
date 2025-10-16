#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (for qsort)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to calculate the mean
double calculateMean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return (double)sum / n;
}

// Function to calculate the median
double calculateMedian(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    if (n % 2 == 0)
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    else
        return arr[n / 2];
}

// Function to calculate the mode
int calculateMode(int arr[], int n) {
    int maxCount = 0, mode = arr[0];
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }
    return mode;
}
// main function
int main() {
    int arr[] = {24, 92, 88, 86, 24, 93, 42};
    // calculate the length of array 
    int size = sizeof(arr) / sizeof(arr[0]);

    double mean = calculateMean(arr, size);
    double median = calculateMedian(arr, size);
    int mode = calculateMode(arr, size);

    // print the mean, median and mode
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: %d\n", mode);

    return 0;
}