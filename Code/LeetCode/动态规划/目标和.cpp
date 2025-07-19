#include "vector"
#include "algorithm"
#include <cstdio>

using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        int goalsum = (sum + target) / 2; // 找出若干个数字和等于数组和加目标值的一半
        if (abs(target) > sum || (sum + target) % 2 == 1)
            return 0;

        vector<int> dp(goalsum + 1, 0); // 正数子集的和的个数

        dp[0] = 1;                            // 和为0的子集的个数为1
        for (int i = 0; i < nums.size(); i++) // 遍历数组中的元素
        {
            for (int j = goalsum; j >= nums[i]; j--)
            {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[goalsum];
    }
};

int main(void)
{
    Solution sol;
    vector<int> n = {7, 9, 3, 8, 0, 2, 4, 8, 3, 9};
    int i = 0;
    int target = 0;
    i = sol.findTargetSumWays(n, target);
    printf("一共有%d种方法让最终目标和为%d\n", i, target);
}