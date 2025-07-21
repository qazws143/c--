#include "vector"
#include <cstdio>
#include "algorithm"

using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        // 处理边界情况：如果价格数组为空或k为0，直接返回0利润
        if (prices.empty() || k == 0)
            return 0;

        int size = prices.size();
        // 创建动态规划表，dp[i][j]表示第i天第j个状态时的最大利润
        // 状态数量为2k+1：0(无操作),1(第一次买入),2(第一次卖出),...,2k-1(第k次买入),2k(第k次卖出)
        vector<vector<int>> dp(size, vector<int>(2 * k + 1, 0));

        // 初始化第一天的情况
        for (int j = 1; j < 2 * k; j = j + 2)
        {
            // 所有奇数位置(买入状态)初始化为第一次买入的价格
            dp[0][j] = -prices[0];
        }

        // 填充动态规划表
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < 2 * k - 1; j = j + 2)
            {
                // 处理买入状态：保持前一天的买入状态或从前一天的卖出状态转为买入
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                // 处理卖出状态：保持前一天的卖出状态或从前一天的买入状态转为卖出
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }

        // 返回最后一天完成k次交易后的最大利润
        return dp[size - 1][2 * k];
    }
};

int main(void)
{
    Solution sol;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    int i = sol.maxProfit(k, prices);
    printf("买卖%d次能获取的最大利润%d", k, i);
}