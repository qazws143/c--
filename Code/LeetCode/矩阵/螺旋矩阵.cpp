#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int top = 0, bottom = matrix.size() - 1;    // 上下边界
        int left = 0, right = matrix[0].size() - 1; // 左右边界
        while (left <= right && top <= bottom)
        {
            // 从左向右遍历
            for (int i = left; i <= right; i++)
                result.push_back(matrix[top][i]);
            top++;
            // 从上往下遍历
            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;

            // 从右向左遍历
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    result.push_back(matrix[bottom][i]);
                bottom--;
            }
            // 从下往上遍历
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }
        return result;
    }
};