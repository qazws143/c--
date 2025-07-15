#include "vector"

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;
        if (nums.empty())
            return -1;
        while (start < end)
        {
            // 设最小值为索引为mid
            mid = start + (end - start) / 2;
            // 最小值在右边
            if (nums[end] < nums[mid])
            {
                start = mid + 1;
            }
            // 最小值在左边
            else
            {
                end = mid;
            }
        }
        return nums[start];
    }
};