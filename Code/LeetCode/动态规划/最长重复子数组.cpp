#include "vector"
#include "cstdio"

using namespace std;

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> dp(vector<int>(nums2.size() + 1, 0)); // 公共的、长度最长的子数组的长度
        int ret = 0;
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = nums2.size(); j > 0; j--)
            {
                if (nums2[j - 1] == nums1[i - 1]) // 如果相等
                    dp[j] = dp[j - 1] + 1;        // 则数组长度加1
                else
                    dp[j] = 0; // 否则为0
                if (dp[j] > ret)
                    ret = dp[j];
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution sol;
    vector<int> ch1 = {1, 2, 3, 2, 1};
    vector<int> ch2 = {3, 2, 1, 4, 7};
    int i = 0;
    i = sol.findLength(ch1, ch2);
    printf("两个数组中公共的、长度最长的子数组的长度为:%d\n", i);
}