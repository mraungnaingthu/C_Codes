//
// Created by Aung Naing Thu on 12/20/2025.
//

#include "iostream"
#include "vector"

using namespace std;

class Solution
{
    public:
    // Method 1
    static int maxNum(const vector<int>& nums, int k)
    {
        int count = 0;
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++)
        {
            for (int j = i + 1; j < numsSize; j++)
            {
                if (nums[i] + nums[j] == k)
                {
                    count++;
                }
            }
        }
        return count;
    }

    // Method 2
    static int maxNumRaw(const int* nums, int numSize, int k)
    {
        int count = 0;
        for (int i = 0; i < numSize; i++)
        {
            for (int j = i + 1; j < numSize; j++)
            {
                if (nums[i] + nums[j] == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4};
    int k = 5;

    int result1 = Solution::maxNum(nums, k);
    cout << "Maximum operation removing numbers that were " << k << " = " << result1 << endl;

    int result2 = Solution::maxNumRaw(nums.data(), nums.size(), k);
    cout << "Maximum operation removing numbers that were " << k << " = " << result2 << endl;



    return 0;
}