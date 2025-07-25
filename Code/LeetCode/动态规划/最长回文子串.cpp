#include "vector"
#include "cstdio"
#include "string"
#include "algorithm"

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n <= 1)
            return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, max_len = 1;

        // 所有单个字符都是回文
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true; // 单字符无论正反转都是回文
        }

        // 检查长度为2的子串
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                start = i;
                max_len = 2; // 更新start 和 max_len，以便后续比较更长的回文
            }
        }

        // 检查长度>=3的子串
        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++) // 子串起始位置
            {
                int j = i + len - 1; // 结束位置
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    if (len > max_len)
                    {
                        start = i;
                        max_len = len; // 更新最大长度
                    }
                }
            }
        }

        return s.substr(start, max_len);
    }
};

int main(void)
{
    Solution sol;
    string s = "aaaaaaa";
    string i = sol.longestPalindrome(s);
    printf("最长的回文子串:%s\n", i.c_str());
}