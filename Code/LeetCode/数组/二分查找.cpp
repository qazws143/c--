#include "vector"
#include "cstdio"

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
            if (nums[mid] > target)
                right = mid - 1;
            if (nums[mid] < target)
                left = mid + 1;
            if (nums[mid] == target)
                return mid;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 2;
    int ret = sol.search(nums, target);
    if (ret == -1)
        printf("不存在目标值\n");
    else
        printf("目标值的下标为%d\n", ret);
    return 0;
}