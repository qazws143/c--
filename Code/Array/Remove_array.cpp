#include "iostream"
#include "vector"
// 27 移除元素
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int fast;
        int slow = 0;
        for (fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};