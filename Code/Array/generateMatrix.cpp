#include "iostream"
#include "vector"
// 59 螺旋矩阵II
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int mid = n / 2;        // 放置最后一个数字
        int loop = n / 2;       // 转几圈
        int count = 1;          // 赋值
        int offset = 1;         // 每循环一圈收缩一位
        int rowx = 0, coly = 0; // 起始位置
        while (loop--)
        {
            int row = rowx;
            int col = coly;
            /*从左往右*/
            for (col; col < n - offset; col++)
            {
                res[row][col] = count++;
            }
            /*从上往下*/
            for (row; row < n - offset; row++)
            {
                res[row][col] = count++;
            }
            /*从右往左*/
            for (col = n - offset; col > coly; col--)
            {
                res[row][col] = count++;
            }
            /*从下往上*/
            for (row = n - offset; row > rowx; row--)
            {
                res[row][col] = count++;
            }
            offset += 1; // 循环一圈,缩小范围
            rowx++;
            coly++; // 一圈过后起始位置+1
        }
        if (n % 2)
            res[mid][mid] = count;
        return res;
    }
};