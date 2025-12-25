//
// Created by Aung Naing Thu on 12/25/2025.
//

#include "iostream"
#include "vector"

using namespace std;

class PivotIndex
{

private:
    vector<int> numbers;

    int findPivotIndex()
    {
        for(int i = 0; i < numbers.size(); i++)
        {
            int leftSum = 0;
            int rightSum = 0;

            // Sum of the elements on the right side of the pivot
            for (int j = i + 1; j < numbers.size(); j++)
            {
                rightSum += numbers[j];
            }

            // Sum of the elements of the left side of the pivot
            for (int j = 0; j < i; j++)
            {
                leftSum += numbers[j];
            }
            if (leftSum == rightSum)
            {
                return i;
            }
            else
            {
                return -1;
            }
        }
    }

public:
    PivotIndex(vector<int> nums)
    {
        numbers = nums;
    }

    void findAndPrintPivotIndex()
    {
        int result = findPivotIndex();
        if (result == -1)
        {
            cout << "Pivot index not found" << endl;
        }
        else
        {
            cout << "Pivot Index: " << result << endl;
            cout << "Pivot Numbers: " << numbers[result] << endl;
        }
    }
};

int main()
{
    vector<int> nums = {1, 7, 3, 5, 3, 9};
    PivotIndex piv = PivotIndex(nums);
    piv.findAndPrintPivotIndex();
}