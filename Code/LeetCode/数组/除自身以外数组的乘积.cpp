#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> answer(size, 1);

        // 计算左侧乘积
        int left = 1; // 初始化第一个数前缀积为1
        for (int i = 0; i < size; i++)
        {
            answer[i] = left; // 将前缀积放入数组
            left *= nums[i];  // 计算下一个数的前缀积
        }

        // 计算右侧乘积
        int right = 1;
        for (int i = size - 1; i >= 0; i--)
        {
            answer[i] *= right; // 后缀积乘以前缀积
            right *= nums[i];   // 计算后缀积
        }
        return answer;
    }
};