#include "vector"

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result(numRows);
        vector<int> path;
        for (int i = 0; i < numRows; i++)
        {
            result[i].resize(i + 1, 1);
            for (int j = 1; j <= i; j++)
            {
                result[i][j] = result[i][j - 1] + result[i][j + 1]; // 右上角元素加上左上角元素
            }
        }
        return result;
    }
};