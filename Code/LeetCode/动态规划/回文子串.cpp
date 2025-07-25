#include "vector"
#include "cstdio"
#include "string"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        int ret = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = i; j < size; j++)
            {
                if (s[i] == s[j]) // 判断两边元素是否相同
                {
                    if (j - i <= 1) // 元素相等时两元素仅相距1
                    {
                        ret++;
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1]) // 判断i到j的区间是不是回文
                    {
                        ret++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution sol;
    string s = "aaa";
    int i = sol.countSubstrings(s);
    printf("最长的回文子串:%d\n", i);
}