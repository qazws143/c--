#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int maxjump = 0; // 最大跳跃距离
        int end = 0;     // 跳跃边界
        int minstep = 0; // 最小跳跃次数
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxjump = max(maxjump, i + nums[i]);
            if (i == end) // 索引到边界
            {
                minstep++;     // 进行跳转
                end = maxjump; // 更新跳跃边界
            }
            if (end >= nums.size() - 1)
                break;
        }
        return minstep;
    }
};