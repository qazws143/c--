#include "vector"

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int cursum = 0;
        int max_sum = nums[0]; // 假设数组第一个元素为最大和
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果当前和小于0,则将当前元素赋给和，不做处理
            cursum = (cursum < 0) ? nums[i] : cursum + nums[i];
            if (cursum > max_sum) // 如果当前元素大于最大和
                max_sum = cursum; // 更新
        }
        return max_sum;
    }
};