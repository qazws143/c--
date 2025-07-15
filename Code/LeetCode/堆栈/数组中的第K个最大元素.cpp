#include "vector"
#include "stack"
#include "string"

using namespace std;

class Solution
{
public:
    // 将数组从大到小排列
    int Quick(vector<int> &nums, int left, int right)
    {
        int key = nums[left]; // 基准元素
        int l = left + 1;     // 基准元素的下一个数
        int r = right;
        while (l <= r)
        {
            // 如果左指针数小于基准数,右指针大于基准数,交换他们
            if (nums[l] < key && nums[r] > key)
                swap(nums[l++], nums[r--]);
            // 如果左指针指向的元素 >= key，左指针右移
            if (nums[l] >= key)
                l++;
            // 如果右指针指向的元素 <= key，右指针左移
            if (nums[r] <= key)
                r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (1)
        {
            int index = Quick(nums, left, right);
            if (index == k - 1)
                return nums[index];
            else if (index < k - 1) // 基准位置小于目标位置,说明目标在右边
                left = index + 1;
            else
                right = index - 1; // 基准位置大于目标位置,说明目标在左边
        }
    }
};