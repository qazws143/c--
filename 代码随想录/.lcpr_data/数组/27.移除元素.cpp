/*
 * @lc app=leetcode.cn id=27 lang=cpp
 * @lcpr version=30202
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0;
        int fast = 0;
        for (fast; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            else
                continue;
        }
        return slow;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n2\n
// @lcpr case=end

 */
