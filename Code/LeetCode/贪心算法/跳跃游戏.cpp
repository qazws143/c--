#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        int maxjump = 0; // 最大跳跃距离
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > maxjump) // 当前位置超过最大跳跃距离
                return false;
            maxjump = max(maxjump, i + nums[i]);
            if (maxjump >= nums.size() - 1) // 到达最后一个数
                return true;
        }
        return true;
    }
};