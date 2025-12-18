#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to merge two strings alternately
char* mergeAlternately(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int totalLength = len1 + len2 + 1; // +1 for null terminator

    // Allocate memory for the result
    char* result = (char*)malloc(totalLength * sizeof(char));

    int i = 0, j = 0, k = 0;

    // Merge characters alternately
    while (i < len1 || j < len2) {
        if (i < len1) {
            result[k++] = word1[i++];
        }
        if (j < len2) {
            result[k++] = word2[j++];
        }
    }

    result[k] = '\0'; // Null terminate the string
    return result;
}

int main(void) {
    char word1[100], word2[100];

    // Get input from user
    printf("Please enter string 1: ");
    scanf("%99s", word1);  // Read as string, not single character

    printf("Please enter string 2: ");
    scanf("%99s", word2);

    // Merge the strings
    char* merged = mergeAlternately(word1, word2);

    // Print result
    printf("Merged string: %s\n", merged);

    // Free allocated memory
    free(merged);

    return 0;
}