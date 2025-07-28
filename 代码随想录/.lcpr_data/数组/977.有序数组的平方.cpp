/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30202
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int slow = 0;
        int fast = nums.size() - 1;
        int k = nums.size() - 1;
        vector<int> ret(nums.size(), 0);
        while (slow <= fast)
        {
            if (nums[slow] * nums[slow] < nums[fast] * nums[fast])
            {
                ret[k--] = nums[fast] * nums[fast];
                fast--;
            }
            else
            {
                ret[k--] = nums[slow] * nums[slow];
                slow++;
            }
        }
        return ret;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */
