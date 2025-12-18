#include <stdio.h>
#include <stdbool.h>

// Fixed variable declarations
char* children[] = {"child1", "child2", "child3", "child4", "child5"};
int candies[] = {2, 3, 5, 1, 4};
int extraCandy = 3;
int numChildren = 5;

// Function declarations
bool* checkBoard(int candies[], int extraCandy, int size);
int findMax(int arr[], int size);
void printResults(bool results[], int size);

int main(void)
{
    bool* results = checkBoard(candies, extraCandy, numChildren);
    printResults(results, numChildren);

    return 0;
}

// Function to check which children can have the most candies with extra candy
bool* checkBoard(int candies[], int extraCandy, int size)
{
    static bool output[5]; // Static array to persist after function returns

    // Find the maximum number of candies any child has
    int maxCandies = findMax(candies, size);

    // Check for each child if they can have the most candies with extra candy
    for (int i = 0; i < size; i++)
    {
        if (candies[i] + extraCandy >= maxCandies)
        {
            output[i] = true;
        }
        else
        {
            output[i] = false;
        }
    }

    return output;
}

// Helper function to find maximum value in array
int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Function to print the results
void printResults(bool results[], int size)
{
    printf("Children: ");
    for (int i = 0; i < size; i++)
    {
        printf("%s ", children[i]);
    }
    printf("\n");

    printf("Candies:  ");
    for (int i = 0; i < size; i++)
    {
        printf("%d       ", candies[i]);
    }
    printf("\n");

    printf("Results:  ");
    for (int i = 0; i < size; i++)
    {
        printf("%s    ", results[i] ? "true" : "false");
    }
    printf("\n\n");

    printf("Detailed breakdown:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s: %d candies + %d extra = %d -> %s\n",
               children[i], candies[i], extraCandy,
               candies[i] + extraCandy,
               results[i] ? "Can have most" : "Cannot have most");
    }
}