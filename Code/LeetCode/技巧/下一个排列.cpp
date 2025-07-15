#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int size = nums.size() - 1;
        int index = size - 1;
        /*先从右边两个元素一组开始遍历,直到找到前一个小于后一个的元素*/
        while (index >= 0 && nums[index] >= nums[index + 1])
        {
            index--;
        }
        /*找到后前一个元素不变,后一个元素从末尾开始与前一个元素开始比较*/
        if (index >= 0 && nums[index] < nums[index + 1])
        {
            int last_index = size;
            while (nums[last_index] <= nums[index]) // 找到刚好大于前一个元素的数
                last_index--;
            swap(nums[index], nums[last_index]); // 交换
        }
        // 要保证刚好大于,所有要给index后的元素进行排序
        reverse(nums.begin() + index + 1, nums.end());
    }
};