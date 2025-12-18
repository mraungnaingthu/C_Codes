#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to check if a string divides another string
int isDivisor(char* str, char* divisor) {
    int str_len = strlen(str);
    int div_len = strlen(divisor);

    if (str_len % div_len != 0) {
        return 0;
    }

    for (int i = 0; i < str_len; i++) {
        if (str[i] != divisor[i % div_len]) {
            return 0;
        }
    }
    return 1;
}

char* searchIntersect(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Find the minimum length
    int min_len = len1 < len2 ? len1 : len2;

    // Try all possible divisor lengths from largest to smallest
    for (int i = min_len; i > 0; i--) {
        // Check if this length divides both string lengths
        if (len1 % i == 0 && len2 % i == 0) {
            // Extract candidate substring
            char* candidate = (char*)malloc(i + 1);
            strncpy(candidate, str1, i);
            candidate[i] = '\0';

            // Check if candidate divides both strings
            if (isDivisor(str1, candidate) && isDivisor(str2, candidate)) {
                return candidate;
            }

            free(candidate);
        }
    }

    return "";
}

// Alternative more efficient solution using GCD of lengths
char* searchIntersectGCD(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Calculate GCD of lengths
    int gcd_length = 0;
    int a = len1, b = len2;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    gcd_length = a;

    // Extract candidate substring
    char* candidate = (char*)malloc(gcd_length + 1);
    strncpy(candidate, str1, gcd_length);
    candidate[gcd_length] = '\0';

    // Verify candidate divides both strings
    if (isDivisor(str1, candidate) && isDivisor(str2, candidate)) {
        return candidate;
    }

    free(candidate);
    return "";
}

int main(void) {
    // Test cases
    char* test1_str1 = "ABCABC";
    char* test1_str2 = "ABC";
    printf("Test 1: '%s' and '%s' -> '%s'\n",
           test1_str1, test1_str2, searchIntersect(test1_str1, test1_str2));

    char* test2_str1 = "ABABAB";
    char* test2_str2 = "ABABAB";
    printf("Test 2: '%s' and '%s' -> '%s'\n",
           test2_str1, test2_str2, searchIntersect(test2_str1, test2_str2));

    char* test3_str1 = "LEET";
    char* test3_str2 = "CODE";
    printf("Test 3: '%s' and '%s' -> '%s'\n",
           test3_str1, test3_str2, searchIntersect(test3_str1, test3_str2));

    return 0;
}