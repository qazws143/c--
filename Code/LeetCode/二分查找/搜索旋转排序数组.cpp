#include "vector"

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1; // 修正：end 应该是 size-1

        // 处理空数组情况
        if (nums.empty())
            return -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
                return mid;

            // 判断左半部分是否有序
            if (nums[start] <= nums[mid])
            {
                if (nums[start] <= target && target < nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            // 右半部分有序的情况
            else
            {
                if (nums[mid] < target && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};