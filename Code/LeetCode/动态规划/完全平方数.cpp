#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n, 0); // 表示完全平方数最小数量
        if (n <= 1)
            return n;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n; i++)
        {
            dp[i] = min(dp[i - 1]);
        }
        return dp[n];
    }
};