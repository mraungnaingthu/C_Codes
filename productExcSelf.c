//
// Created by Aung Naing Thu on 12/14/2025.
//

#include <stdio.h>

int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    int output[5];

    int size = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < size; i++)
    {
        output[i] = 1;
        for (int j = 0; j < size; j++)
        {
            if (j == i) continue;
            output[i] *= nums[j];
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", output[i]);
    }


    return 0;
}
