#include "vector"
#include "algorithm"
#include <cstdio>
#include <cstring>

using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int size = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 记录符合要求的最大子串个数

        for (string str : strs)
        { // 遍历物品
            int one = 0, zero = 0;
            for (char c : str)
            {
                if (c == '0')
                    zero++;
                else
                    one++;
            }
            for (int j = m; j >= zero; j--) // 第i个子串中0的个数
            {
                for (int k = n; k >= one; k--) // 第i个子串中1的个数
                {
                    dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(void)
{
    Solution sol;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int i = 0;
    int m = 5;
    int n = 3;
    i = sol.findMaxForm(strs, m, n);
    printf("最大子集长度为%d\n", i);
}