//
// Created by Aung Naing Thu on 12/23/2025.
//
#include "iostream"
#include "vector"

using namespace std;

class MaxCount
{
private:
    // Helper Function to check all elements are 1 ?
    bool checkAllOnes(const vector<int>& vecArr)
    {
        for (int element : vecArr)
        {
            if (element != 1) return false;
        }
        return true;
    }

    // Helper Function to check all elements are 0 ?
    bool checkAllZeros(const vector<int>& vecArr)
    {
        for (int element : vecArr)
        {
            if (element != 0) return false;
        }
        return true;
    }

    // Helper Function to count zeros in the array
    int countZeros(const vector<int>& vecArr)
    {
        int count = 0;
        for (int element : vecArr)
        {
            if (element == 0) count++;
        }
        return count;
    }

    // Helper Function to count consecutive ones to the left of position i
    int countLeftOnes(vector<int> vecArr, int index)
    {
        int leftOnes = 0;
        for (int j = index-1; j > 0; j--)
        {
            if (vecArr[j] == 1)
            {
                leftOnes++;
            }
            else
            {
                break;
            }
        }
        return leftOnes;
    }

    // Helper Function to count consecutive ones to the right of position i
    int countRightOnes(vector<int> vecArr, int index)
    {
        int rightOnes = 0;
        for (int j = index+1; j < vecArr.size(); j++)
        {
            if (vecArr[j] == 1)
            {
                rightOnes++;
            }
            else
            {
                break;
            }
        }
        return rightOnes;
    }

    // Helper Function to check maximum length where there are multiple zeros
    int findMaxLen(const vector<int> vecArr)
    {
        int maxLen = 0;
        for (int i = 1; i < vecArr.size(); i++)
        {
            if (vecArr[i] == 0)
            {
                int leftOnes = countLeftOnes(vecArr, i);
                int rightOnes = countRightOnes(vecArr, i);

                if (leftOnes + rightOnes > maxLen)
                {
                    maxLen = leftOnes + rightOnes;
                }
            }
        }
        return maxLen;
    }

public:
    int counter(vector<int> vecArr)
    {
        // Step 1 Checking
        if (vecArr.empty())
        {
            cout << "The vector is empty." << endl;
            return 0;
        }

        // Step 2 Checking
        if (checkAllZeros(vecArr))
        {
            cout << "The vector is all zeros." << endl;
            return 0;
        }

        // Step 3 Checking
        if (checkAllOnes(vecArr))
        {
            cout << "The vector is all ones." << endl;
            return vecArr.size();
        }

        // Step 4 Checking
        int zeroCount = countZeros(vecArr);
        if (zeroCount == 1)
        {
            return vecArr.size()-1;
        }

        int maxLen = findMaxLen(vecArr);
        return maxLen;
    }
};


int main()
{
    vector<int> vecArr = {0, 1, 1, 1, 0, 1, 1, 0};
    MaxCount maxCount;
    int maxLen = maxCount.counter(vecArr);

    cout << "Consecutive 1 element after removing one Zero: " << maxLen << endl;


    return 0;
}