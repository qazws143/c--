#include "vector"
#include "cstdio"

using namespace std;

/*和最长公共子序列一样*/
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int ret = 0;

        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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
    vector<int> ch1 = {1, 3};
    vector<int> ch2 = {1};
    int i = 0;
    i = sol.maxUncrossedLines(ch1, ch2);
    printf("绘制的直线相等且不与任何其他连线相交的个数:%d\n", i);
}