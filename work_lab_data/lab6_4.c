#include <stdio.h>
#include <stdlib.h>
#include <time.h> // เพิ่มการ include เพื่อให้สามารถใช้ time(NULL) ได้

void radixSort(int num[], int n);
int getMax(int num[], int n);
void countSort(int num[], int n, int exp);

int main()
{
    int i, n = 20;
    srand((unsigned) time(NULL)); // Initializes random number generator
    int num[n];

    printf("Number before sorting\n");
    for (i = 0; i < n; i++) {
        num[i] = rand() % 32768; // random number between 0-32767
        printf("%d ", num[i]);
    }
    printf("\n");

    // Call radixSort to sort the numbers
    radixSort(num, n);

    // Print the sorted numbers
    printf("Numbers after sorting\n");
    for (i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}

// Function for Radix Sort
void radixSort(int num[], int n)
{
    int max = getMax(num, n);  // Find the maximum number to know the number of digits

    // Apply counting sort for every digit.
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(num, n, exp);
    }
}

// Function to get the maximum value in num[]
int getMax(int num[], int n)
{
    int max = num[0];
    for (int i = 1; i < n; i++) {
        if (num[i] > max)
            max = num[i];
    }
    return max;
}

// A function to do counting sort of num[] according to the digit represented by exp
void countSort(int num[], int n, int exp)
{
    int output[n];  // output array to store sorted numbers
    int count[10] = {0};  // count array to store count of occurrences of digits (0-9)

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(num[i] / exp) % 10]++;
    }

    // Change count[i] to contain the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array using the count array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(num[i] / exp) % 10] - 1] = num[i];
        count[(num[i] / exp) % 10]--;
    }

    // Copy the sorted numbers into num[]
    for (int i = 0; i < n; i++) {
        num[i] = output[i];
    }
}
