#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &o)
    {
        int count = 0;
        int row = o.size();                           // 行的个数
        int col = o[0].size();                        // 列的个数
        if (o[0][0] == 1 || o[row - 1][col - 1] == 1) // 如果障碍在起始位置
            return 0;
        vector<vector<int>> dp(row, vector<int>(col, 0));

        /*每次走右边或下边*/
        for (int i = 0; i < row && o[i][0] == 0; i++) // 只有当遇到0时才赋值1
            dp[i][0] = 1;
        for (int j = 0; j < col && o[0][j] == 0; j++)
            dp[0][j] = 1;
        /*走到最底部加上走到最右边的路径和*/
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (o[i][j] == 1) // 当遇到给的地图中的障碍物,则跳过本次循环
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[row - 1][col - 1];
    }
};