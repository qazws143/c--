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
        vector<int> dp(size);
        int minprofit = prices[0];

        for (int i = 1; i < size; i++)
        {
            if (minprofit > prices[i]) // 记录股票最低时买入
                minprofit = prices[i];
            dp[i] = max(dp[i - 1], prices[i] - minprofit); // 股票在最低购入后最大值卖出
        }
        return dp[size - 1];
    }
};

int main(void)
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int i = sol.maxProfit(prices);
    printf("能获取的最大利润%d", i);
}