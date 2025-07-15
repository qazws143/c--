#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = 0;
        int rownum = matrix.size() - 1;

        for (row = 0; row <= rownum; row++)
        {
            int left = 0;                       // 每行重新初始化 left
            int right = matrix[row].size() - 1; // 每行重新初始化 right

            while (left <= right)
            {
                int mid = left + (right - left) / 2;

                // 检查 mid、left、right 是否等于 target
                if (matrix[row][mid] == target || matrix[row][left] == target || matrix[row][right] == target)
                {
                    return true;
                }

                // 调整二分查找逻辑
                if (matrix[row][mid] < target)
                {
                    left = mid + 1; // 目标在右侧
                }
                else
                {
                    right = mid - 1; // 目标在左侧
                }
            }
        }
        return false;
    }
};