#include "vector"
#include "algorithm"
#include <cstdio>
#include <cstring>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int range1 = robrange(nums, 0, nums.size() - 2); // 不考虑最后一个房子的情况
        int range2 = robrange(nums, 1, nums.size() - 1); // 不考虑第一个房子的情况
        int Max = max(range1, range2);
        return Max;
    }
    int robrange(vector<int> &nums, int start, int end) // 代码和打家劫舍一样
    {
        if (end == start)
            return nums[start];

        vector<int> dp(end + 1, 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        return dp[end];
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int i = 0;
    i = sol.rob(nums);
    printf("一夜之内能够偷窃到的最高金额为:%d\n", i);
}