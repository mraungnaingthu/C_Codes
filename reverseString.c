#include <stdio.h>
#include <string.h>

// Helper function to reverse characters in a range
void reverse(char str[], int start, int end) {
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

char* reverseString(char str[]) {
  int len = strlen(str);

  // 1. Reverse the entire string
  reverse(str, 0, len - 1);
  // 2. Reverse each word
  int start = 0;
  for (int i = 0; i <= len; i++) {
    if (str[i] == ' ' || str[i] == '\0') {
      reverse(str, start, i - 1);
      start = i + 1;
    }
  }

  return str;
}

int main() {
  char str[100] = "hello to the world";

  char* result = reverseString(str);
  printf("%s\n", result);

  return 0;
}
