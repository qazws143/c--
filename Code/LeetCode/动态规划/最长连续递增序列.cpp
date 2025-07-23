#include "vector"
#include "cstdio"

using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int size = nums.size();
        if (size <= 1)
            return size;
        vector<int> dp(size, 1); // 连续递增子序列长度
        int ret = 0;
        for (int i = 1; i < size; i++)
        {
            if (nums[i] > nums[i - 1]) // 如果当前元素大于前一个元素
                dp[i] = dp[i - 1] + 1; // 前一个序列长度加1
            if (dp[i] > ret)
                ret = dp[i];
        }
        return ret;
    }
};

int main(void)
{
    Solution sol;
    vector<int> n = {-2, 0, -1};
    int i = 0;
    i = sol.findLengthOfLCIS(n);
    printf("连续递增的子序列的长度为:%d\n", i);
}