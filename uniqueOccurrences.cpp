#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
    int uniqueOccur(vector<int> vecArr)
    {
        unordered_map<int, int> freq;
        for (int element : vecArr)
        {
            freq[element]++;
        }

        for (auto& [element, frequency] : freq)
        {
            if (element == frequency)
            {
                return element;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> vec = {1, 2, 3, 2, 9, 8};
    Solution solution;
    int result = solution.uniqueOccur(vec);

    if (result == -1)
    {
        cout << "No such element" << endl;
    }
    else
    {
        cout << "Occurrence is " << result << endl;
    }
}