#include <stdio.h>
#include <string.h>

void reverseVowel(char* str);
int isVowel(char c);

int main()
{
    char originalString[] = "AeroPlanE";
    printf("Original String: %s\n", originalString);

    reverseVowel(originalString);
    printf("Reverse Vowel: %s\n", originalString);

    return 0;
}

int isVowel(char c)
{
    // Check for both lowercase vowels
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void reverseVowel(char* str)
{
    int len = strlen(str);
    int left = 0, right = len - 1;

    while (left < right)
    {
        // Find vowel from left (skip non-vowels)
        while (left < right && !isVowel(str[left]))
        {
            left++;
        }

        // Find vowel from right (skip non-vowels)
        while (left < right && !isVowel(str[right]))
        {
            right--;
        }

        // Swap the vowels
        if (left < right)
        {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;

            // Move pointers after swapping
            left++;
            right--;
        }
    }
}