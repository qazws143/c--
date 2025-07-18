#include "vector"
#include <cstdio>
#include "algorithm"

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0) // 判断数组的和是否能分成两个子集
            return false;
        int target = sum / 2; // 一个子集的总和

        vector<int> dp(target + 1, 0); // 在每个背包中,数值既是它的价值也是它的重量

        dp[0] = 0;
        for (int i = 0; i < size; i++) // 遍历数组中的个数,即为物品个数
        {
            for (int j = target; j >= nums[i]; j--) // 倒序遍历避免一个元素被多次使用
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target)
            return true;
        return false;
    }
};

int main(void)
{
    Solution sol;
    vector<int> n = {1, 5, 11, 5};
    bool i;
    i = sol.canPartition(n);
    if (i == true)
        printf("能分成两个子集\n");
    else if (i == false)
        printf("不能分成两个子集\n");
}