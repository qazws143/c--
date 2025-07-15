#include "vector"

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;                  // 从头遍历
        int right = height.size() - 1; // 从尾部遍历
        int Area = 0;
        int currentArea = 0;
        while (left < right) // 左右指针相遇时停止遍历
        {
            if (height[left] > height[right]) // 移动两者短的一个元素
            {
                currentArea = (right - left) * height[right];
                right--;
            }
            else
            {
                currentArea = (right - left) * height[left];
                left++;
            }
            Area = max(Area, currentArea); // 更新最大面积
        }
        return Area;
    }
};