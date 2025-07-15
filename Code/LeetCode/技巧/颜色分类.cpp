#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int key;
        int pre;
        for (int i = 1; i < nums.size(); i++)
        {
            key = nums[i];                       // 基准元素
            pre = i - 1;                         // 前一个元素
            while (pre >= 0 && key <= nums[pre]) // 如果基准元素小于前一个元素
            {
                nums[pre + 1] = nums[pre]; // 将前一个元素放到基准元素位置
                pre--;
            }
            nums[pre + 1] = key;
        }
    }
};