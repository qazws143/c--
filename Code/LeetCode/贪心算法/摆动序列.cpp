#include "vector"

using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        int currDiff = 0; // 当前元素对差值
        int preDiff = 0;  // 前一对元素差值
        int result = 1;   // 摆动元素个数
        for (int i = 0; i < nums.size() - 1; i++)
        {
            currDiff = nums[i + 1] - nums[i];
            if ((currDiff > 0 && preDiff <= 0) || (currDiff < 0 && preDiff >= 0))
            {
                result++;
                preDiff = currDiff;
            }
        }
        return result;
    }
};