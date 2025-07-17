#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int N = cost.size();
        vector<int> dp(N + 1, 0); // 一共有N+1个楼梯
        dp[0] = 0;
        dp[1] = 0; // 表示一次性上台阶的花费
        for (int i = 2; i <= N; i++)
        {
            /*跳一次台阶和两次台阶的最小价格*/
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[N];
    }
};