//
// Created by Aung Naing Thu on 12/25/2025.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    vector<vector<int>> differentArray(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> result(2);

        // For the first row
        for (int element1 : nums1 )
        {
            bool found = false;
            for (int element2 : nums2 )
            {
                if (element1 == element2)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                result[0].push_back(element1);
            }
        }

        // For the second row
        for (int element2 : nums2 )
        {
            bool found = false;
            for (int element1 : nums1 )
            {
                if (element2 == element1)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                result[1].push_back(element2);
            }
        }
        return result;
    }
};



int main()
{
    vector<int> nums1 = {1, 2, 9, 8};
    vector<int> nums2 = {8, 0, 2};
    Solution s;
    vector<vector<int>> output = s.differentArray(nums1, nums2);

    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }


}