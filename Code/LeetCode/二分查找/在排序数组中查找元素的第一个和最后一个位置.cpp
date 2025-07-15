#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = search(nums, target);
        if (nums.size() == start || nums[start] != target)
            return {-1, -1};
        int end = search(nums, target + 1) - 1;
        return {start, end};
    }
};