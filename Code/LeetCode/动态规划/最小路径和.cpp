#include "vector"
#include "cstdio"

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int rowsize = grid.size();
        int colsize = grid[0].size();
        if (rowsize == 0 || colsize == 0)
            return 0;
        vector<vector<int>> dp(rowsize, vector<int>(colsize));

        dp[0][0] = grid[0][0];
        for (int i = 1; i < rowsize; i++) // 将grid数组的数据填充到新数组中
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < colsize; j++)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < rowsize; i++)
        {
            for (int j = 1; j < colsize; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                // 左方和上方最小值加上当前值
            }
        }
        return dp[rowsize - 1][colsize - 1];
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    int i = 0;
    i = sol.minPathSum(grid);
    printf("路径上的数字最小总和为:%d\n", i);
}