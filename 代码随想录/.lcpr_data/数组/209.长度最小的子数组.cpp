/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30202
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include "vector"
#include "algorithm"

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0;
        int end = 0; // 窗口大小
        int sum = 0;
        int len = nums.size() + 1;
        for (end; end < nums.size(); end++)
        {
            sum += nums[end];
            while (sum >= target)
            {
                len = min(len, end - start + 1);
                sum -= nums[start++];
            }
        }
        return len <= nums.size() ? len : 0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */
