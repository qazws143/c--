#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0); // 最大乘积
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }
};