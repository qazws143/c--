#include "vector"
#include "algorithm"
#include <cstdio>
#include <cstring>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1); // 凑成目标金额需要的最少硬币个数

        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] > amount)
            return -1;
        return dp[amount];
    }
};

int main(void)
{
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int i = 0;
    int amount = 11;
    i = sol.coinChange(coins, amount);
    printf("一共有%d最少的硬币个数可以凑成总金额:%d\n", i, amount);
}