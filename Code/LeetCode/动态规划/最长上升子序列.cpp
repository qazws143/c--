#include "vector"
#include "cstdio"

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int size = nums.size();
        if (size <= 1) // 处理边界情况
            return size;

        vector<int> dp(size, 1); // 初始化dp数组，所有元素初始值为1
        int ret = 0;             // 用于记录最长长度

        for (int i = 1; i < size; i++)
        { // 遍历数组
            for (int j = 0; j < i; j++)
            { // 检查i之前的所有元素
                if (nums[i] > nums[j])
                {                                  // 如果当前元素大于前面的元素
                    dp[i] = max(dp[i], dp[j] + 1); // 更新dp[i]
                }
            }
            if (dp[i] > ret) // 更新最大值
                ret = dp[i];
        }
        return ret;
    }
};

int main(void)
{
    Solution sol;
    vector<int> n = {10, 9, 2, 5, 3, 7, 101, 18};
    int i = 0;
    i = sol.lengthOfLIS(n);
    printf("最长严格递增子序列的长度为:%d\n", i);
}