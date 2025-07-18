#include "vector"
#include <cstdio>
#include "algorithm"

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0); // 二叉搜索数的个数
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main(void)
{
    Solution sol;
    int n = 5;
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        i = sol.numTrees(j);
        printf("二叉树有%d个节点,有%d个树\n", j, i);
    }
}