#include <stdio.h>

// Function to perform bubble sort
void bubbleSort() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array) / sizeof(array[0]);
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // swap the elements
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}