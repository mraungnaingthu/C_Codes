#include <stdio.h>
#include <stdbool.h>

bool* getFloweringResults(int arr[], int size);
int* getAvailablePositions(int arr[], int size, int *count);

int arr[5] = {1, 0, 1, 0, 0};

int main(void) {
  int size = sizeof(arr) / sizeof(arr[0]);
  int count;

  bool* results = getFloweringResults(arr, size);
  int* positions = getAvailablePositions(arr, size, &count);

  printf("Flowerbed array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n\n");

  printf("Simple rule: Can plant at ALL empty spots (0s):\n");
  for (int i = 0; i < size; i++) {
    printf("Position %d (index %d): %s\n",
           i + 1, i,
           results[i] ? "Available" : "Not available");
  }

  printf("\nAvailable positions (1-based): ");
  for (int i = 0; i < count; i++) {
    printf("%d ", positions[i] + 1);
  }
  printf("\n");

  return 0;
}

// SIMPLE VERSION: Plant at ALL 0 positions
bool* getFloweringResults(int arr[], int size) {
  static bool results[100];

  for (int i = 0; i < size && i < 100; i++) {
    // Just check if position is empty (0)
    results[i] = (arr[i] == 0);
  }
  return results;
}

int* getAvailablePositions(int arr[], int size, int *count) {
  static int positions[100];
  *count = 0;

  bool* results = getFloweringResults(arr, size);

  for (int i = 0; i < size && i < 100; i++) {
    if (results[i]) {
      positions[(*count)++] = i;
    }
  }
  return positions;
}