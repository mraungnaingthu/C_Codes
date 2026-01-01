//
// Created by Aung Naing Thu on 12/27/2025.
//

// 3    1    2    2
// 1    4    4    5
// 2    4    2    2
// 2    4    2    2

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> equalRowAndCol(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    vector<pair<int, int> > result;;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            bool isEqual = true;
            for (int i = 0; i < n; i++)
            {
                if (matrix[row][i] != matrix[i][col])
                {
                    isEqual = false;
                    break;
                }
            }
            if (isEqual)
            {
                result.push_back({row, col});
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<int> > matrix = {
        {2, 1, 3, 2},
        {1, 4, 4, 1},
        {2, 4, 2, 3},
        {2, 5, 2, 2}

    };

    vector<pair<int, int> > matchingPair = equalRowAndCol(matrix);
    cout << ">>> Same row and column <<<" << endl;
    for (auto& pair : matchingPair)
    {
        cout << "[row" << pair.first << ", " << "col" << pair.second << "]" << endl;
    }



    return 0;
}