#include <stdio.h>

int main()
{
    int nums[] = {0, 2, 12, 9, 0, 10, 0, 11};
    int size = sizeof(nums) / sizeof(nums[0]);
    int nonzeroIndex = 0;
    int lastIndex;
    int temp;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] != 0)
        {
            nums[nonzeroIndex] = nums[i];
            nonzeroIndex++;
        }
    }
    for (int i = nonzeroIndex; i < size; i++)
    {
        nums[i] = 0;
    }

    // After All zero to the end
    printf("Moving all zero to end and before sorting the array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    for (int i = 0; i < size; i++)
    {
        if (nums[i] == 0)
        {
            lastIndex = i;
            break;
        }
    }

    for (int i = 0; i < lastIndex; i++)
    {
        for (int j = i; j < lastIndex; j++)
        {
            if (nums[i] > nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    printf("After sorting the array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }


    return 0;
}