#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // 先对矩阵进行元素交换
        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = row; col < matrix[0].size(); col++)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // 镜像矩阵
        for (int row = 0; row < matrix.size(); row++)
        {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};