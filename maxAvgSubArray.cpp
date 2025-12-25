#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
protected:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0 || k == 0) return 0;
        if (k > n) return 0;

        double currentSum = 0;
        for (int i = 0; i < k; i++) {
            currentSum += nums[i];
        }

        double maxSum = currentSum;

        for (int i = k; i < n; i++) {

            currentSum = currentSum - nums[i - k] + nums[i];

            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }

        return maxSum / k;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = solution.findMaxAverage(nums, k);
    cout << "Maximum average: " << result << endl;

    return 0;
}