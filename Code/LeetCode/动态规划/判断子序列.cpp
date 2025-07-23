#include "vector"
#include "cstdio"
#include "string"

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.size() == 0)
            return true;
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
        int ret = s.size();
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (dp[i][j] == ret)
                    return true;
            }
        }
        return false;
    }
};

int main(void)
{
    Solution sol;
    string s = "axc";
    string t = "ahbgdc";
    bool i = false;
    i = sol.isSubsequence(s, t);
    if (i == true)
        printf("s是t的子序列\n");
    else
        printf("s不是t的子序列\n");
}