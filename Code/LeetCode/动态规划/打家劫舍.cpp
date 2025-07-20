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
        if (nums.szie() == 1)
            return nums[0];

        int size = nums.size();
        vector<int> dp(size, 0); // 偷这些房子的最大金额
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++)
        {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
            printf("%d ", dp[i]);
        }
        return dp[size];
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