#include "vector"
#include "algorithm"
#include <cstdio>
#include <cstring>

// 求排列数时需要先遍历目标值,再遍历物品保证每个目标值都能排列一遍
// 比如[1,2],[2,1]在组合时会被认为是一个组合
// 排列则会将这两个当做不一样排列形式

using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<long long> dp(target + 1, 0); // 目标值组合数
        dp[0] = 1;
        for (size_t i = 1; i <= target; i++) // 遍历目标值
        {
            for (int j = 0; j < nums.size(); j++) // 遍历物品
            {
                if (nums[j] <= i)
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int i = 0;
    int target = 4;
    i = sol.combinationSum4(nums, target);
    printf("一共有%d种方法可以凑成目标值%d\n", i, target);
}