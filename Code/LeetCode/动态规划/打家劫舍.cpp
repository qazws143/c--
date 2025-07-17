#include "vector"

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

        int size = nums.size();
        vector<int> dp(size, 0);
        dp[0] = nums[0];               // 只有一个房间时只能偷一个
        dp[1] = max(nums[0], nums[1]); // 有两个房间时,哪个多偷哪个
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]); // 比较偷当前房子和不偷当前房子的最大值
        }
        return dp[size - 1];
    }
};