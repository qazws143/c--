#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[nums[0]];

        // 找到相遇点
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // 找到环的入口（重复数字）
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};