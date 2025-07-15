#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int index;

        /*判断目标值是否小于起始或大于结尾值*/
        if (nums.empty())
            return 0;
        if (nums[right] < target)
            return right + 1;
        if (nums[left] > target)
            return left;
        while (left <= right)
        {
            index = left + (right - left) / 2;
            if (nums[index] == target)
                return index;
            if (nums[index] < target)
                left = index + 1;
            if (nums[index] > target)
                right = index - 1;
        }
        return left;
    }
};