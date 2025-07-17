#include "vector"

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int size = nums.size();
        vector<int> dp(size + 1, 0);
        dp[0] = 0;       // 表示房子没东西可偷
        dp[1] = nums[0]; // 表示只有一个房子可偷
        for (int i = 2; i <= nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]); // 比较偷当前房子和不偷当前房子的最大值
        }
        return dp[size];
    }
};