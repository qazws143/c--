#include "vector"
#include "algorithm"
#include <cstdio>
#include <cstring>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, n + 1); // 表示完全平方数最小数量

        dp[0] = 0; // n为0完全平方数为0
        dp[1] = 1;
        for (int i = 2; i <= n; i++) // 计算每个数的最小完全平方和的数量
        {
            for (int j = 0; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main(void)
{
    Solution sol;
    int i = 0;
    int n = 12;
    i = sol.numSquares(n);
    printf("一共有%d个完全平方数的最少数量的和为:%d\n", i, n);
}