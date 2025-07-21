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
        vector<vector<int>> dp(size, vector<int>(5, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;
        for (int i = 1; i < size; i++)
        {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // 第一次持有股票
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]); // 第一次卖出股票
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]); // 第二次持有股票
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]); // 第二次卖出股票
        }
        return dp[size - 1][4];
    }
};

int main(void)
{
    Solution sol;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int i = sol.maxProfit(prices);
    printf("能获取的最大利润%d", i);
}