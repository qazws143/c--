#include "vector"
#include "cstdio"
#include "string"

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0)); // 最小重复子序列长度
        int ret = 0;
        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])    // 如果值相等
                    dp[i][j] = dp[i - 1][j - 1] + 1; // 取当前值
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 向左或上取最大值
                if (dp[i][j] > ret)
                    ret = dp[i][j];
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution sol;
    string ch1 = "abcde";
    string ch2 = "ace";
    int i = 0;
    i = sol.longestCommonSubsequence(ch1, ch2);
    printf("最长公共子序列的长度为:%d\n", i);
}