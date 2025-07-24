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
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                    {
                        ret++;
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1])
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