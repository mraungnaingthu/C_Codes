#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int size, int data) {
    int step = sqrt(size);
    int prev = 0;
    while (arr[step] < data) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1;
        }
    }
    for (int i = prev; i < step; i++) {
        if (arr[i] == data) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int data = 5;
    int index = jumpSearch(arr, size, data);
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }
    return 0;
}