#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class moreFluid
{
public:
    struct Result {
        int maxArea;
        int leftIndex;
        int rightIndex;
    };

    static Result maxArea(const vector<int> &height)
    {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        int bestLeft = 0;
        int bestRight = height.size() - 1;

        while (left < right)
        {
            int h = min(height[left], height[right]);
            int width = right - left;
            int currentArea = width * h;

            if (currentArea > maxArea)
            {
                maxArea = currentArea;
                bestLeft = left;
                bestRight = right;
            }

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return {maxArea, bestLeft, bestRight};
    }
};

int main()
{
    vector<int> tank = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    moreFluid::Result result = moreFluid::maxArea(tank);

    cout << "Left index: " << result.leftIndex << " (value: " << tank[result.leftIndex] << ")" << endl;
    cout << "Right index: " << result.rightIndex << " (value: " << tank[result.rightIndex] << ")" << endl;
    cout << "Maximum Area: " << result.maxArea << endl;



    return 0;
}