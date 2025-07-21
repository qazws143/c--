#include "vector"
#include <cstdio>
#include "algorithm"

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        if (size == 0)
            return 0;
        vector<vector<int>> dp(size, vector<int>(3, 0));

        dp[0][0] = 0;          // 不持有股票且不处于冷冻期（可以买入）
        dp[0][1] = -prices[0]; // 持有股票（可以卖出）
        dp[0][2] = 0;          // 处于冷冻期（不能买入）

        for (int i = 1; i < size; i++)
        {
            // 状态0：处于冷冻期
            // 可以从两种状态转移而来：
            // 1. 前一天也不持有且不处于冷冻期（保持状态）
            // 2. 前一天处于冷冻期（冷冻期结束）
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);

            // 状态1：持有股票
            // 可以从两种状态转移而来：
            // 1. 前一天也持有股票（保持状态）
            // 2. 前一天不持有且不处于冷冻期，今天买入（注意冷冻期限制）
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);

            // 状态2：不持有且处于冷冻期
            // 只能从一种状态转移而来：
            // 前一天持有股票，今天卖出（卖出后进入冷冻期）
            dp[i][2] = dp[i - 1][1] + prices[i];
        }
        // 最终最大利润只能来自两种状态：
        // 1. 最后一天不持有股票且不处于冷冻期
        // 2. 最后一天不持有股票且处于冷冻期（即最后一天卖出）
        // 不能持有股票结束，因为那样没有实际卖出
        return max(dp[size - 1][0], dp[size - 1][2]);
    }
};

int main(void)
{
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2};
    int i = sol.maxProfit(prices);
    printf("能获取的最大利润%d", i);
}