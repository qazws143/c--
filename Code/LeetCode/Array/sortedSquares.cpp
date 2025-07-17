#include "iostream"
#include "cmath"
#include "vector"
// 997 有序数组的平方
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int start = 0;             // 起始位置
        int end = nums.size() - 1; // 终止位置
        int k = nums.size() - 1;
        vector<int> result(nums.size(), 0); // 创建一个全为0的数组
        while (start <= end)
        {
            if (nums[start] * nums[start] < nums[end] * nums[end])
            {
                result[k--] = nums[end] * nums[end];
                end--;
            }
            else
            {
                result[k--] = nums[start] * nums[start];
                start++;
            }
        }
        return result;
    }
};