#include "vector"
#include "cstdio"

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];   // 若数组只有一个则第一个为最大和
        int ret = nums[0]; // 假设为最大和
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 判断当前数和前面的数加上这个数的和哪个大
            if (dp[i] > ret)
                ret = dp[i];
        }
        return ret;
    }
};

int main(void)
{
    Solution sol;
    vector<int> ch1 = {5, 4, -1, 7, 8};
    int i = 0;
    i = sol.maxSubArray(ch1);
    printf("最大和的连续子数组的和:%d\n", i);
}