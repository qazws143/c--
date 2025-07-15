#include "iostream"
#include "vector"
#include "climits"
// 209 长度最小的子数组
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0;             // 起始位置
        int end;                   // 终止位置
        int sum = 0;               // 滑动窗口包含数据的和
        int len = nums.size() + 1; // 序列初始长度,定义为一个永远取不到的值
        for (end = 0; end < nums.size(); end++)
        {
            sum += nums[end]; // 计算窗口数据之和
            while (sum >= target)
            {
                len = min(len, end - start + 1); // 计算满足调节的最小的数组
                sum -= nums[start++];
            }
        }
        return len <= nums.size() ? len : 0;
    }
};