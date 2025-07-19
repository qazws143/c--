#include "vector"
#include "algorithm"
#include <cstdio>
#include <cstring>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<unsigned long long> dp(amount + 1, 0); // 可以凑到目标数目的方法数
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) // 遍历物品
        {
            for (int j = coins[i]; j <= amount; j++) // 遍历背包容量
            {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

int main(void)
{
    Solution sol;
    vector<int> coins = {1, 2, 3};
    int i = 0;
    int amount = 4;
    i = sol.change(amount, coins);
    printf("一共有%d种方法可以凑成总金额%d\n", i, amount);
}