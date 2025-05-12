#include <stdio.h>

int binarySearch(int arr[], int left, int right, int data) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == data) {
            return mid;
        }
        if (arr[mid] > data) {
            return binarySearch(arr, left, mid - 1, data);
        }
        return binarySearch(arr, mid + 1, right, data);
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int data = 10;
    int result = binarySearch(arr, 0, n - 1, data);
    if (result == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }
    return 0;
}