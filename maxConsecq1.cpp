#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxConsecutive(vector<int>& nums, int k) {
        vector<int> result;
        int maxLength = 0;
        int startIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            int zeroCount = 0;
            int currentLength = 0;

            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == 0) {
                    zeroCount++;
                    if (zeroCount > k) break;
                }
                currentLength = j - i + 1;

                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    startIndex = i;
                }
            }
        }

        int zeroCount = 0;
        for (int i = startIndex; i < nums.size(); i++) {
            if (i - startIndex >= maxLength) break;

            if (nums[i] == 0 && zeroCount < k) {
                result.push_back(1);  // This 0 is flipped to 1
                zeroCount++;
            } else if (nums[i] == 1) {
                result.push_back(1);
            } else {
                result.push_back(nums[i]);
            }
        }

        return result;
    }

    vector<int> counter(vector<int>& nums, int k) {
        vector<int> counts(2, 0);
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                counts[0]++;
            } else if (nums[i] == 0) {
                counts[1]++;
            }
        }

        return counts;
    }

    vector<vector<int>> findAllConsecutiveSequences(vector<int>& nums) {
        vector<vector<int>> sequences;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                vector<int> currentSeq;
                int start = i;

                while (i < nums.size() && nums[i] == 1) {
                    currentSeq.push_back(nums[i]);
                    i++;
                }

                sequences.push_back(currentSeq);
                i--;
            }
        }

        return sequences;
    }
};

int main() {
    Solution solution;

    // Test with Example 1
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;

    cout << "Example 1:" << endl;
    cout << "Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2" << endl;

    vector<int> counts1 = solution.counter(nums1, k1);
    cout << "Total 1s in array: " << counts1[0] << endl;
    cout << "Total 0s in array: " << counts1[1] << endl;

    vector<int> result1 = solution.maxConsecutive(nums1, k1);

    cout << "Longest sequence after flipping at most " << k1 << " zeros: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Length of longest sequence: " << result1.size() << endl;
    cout << endl;

    // Test with Example 2
    vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1};
    int k2 = 3;

    cout << "Example 2:" << endl;
    cout << "Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3" << endl;

    vector<int> counts2 = solution.counter(nums2, k2);
    cout << "Total 1s in array: " << counts2[0] << endl;
    cout << "Total 0s in array: " << counts2[1] << endl;

    vector<int> result2 = solution.maxConsecutive(nums2, k2);

    cout << "Longest sequence after flipping at most " << k2 << " zeros: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Length of longest sequence: " << result2.size() << endl;

    // Additional: Find all consecutive 1 sequences
    cout << "\nFinding all consecutive 1 sequences in Example 2:" << endl;
    vector<vector<int>> sequences = solution.findAllConsecutiveSequences(nums2);
    cout << "Found " << sequences.size() << " consecutive 1 sequences:" << endl;
    for (int i = 0; i < sequences.size(); i++) {
        cout << "Sequence " << i + 1 << ": ";
        for (int num : sequences[i]) {
            cout << num << " ";
        }
        cout << " (Length: " << sequences[i].size() << ")" << endl;
    }



    return 0;
}