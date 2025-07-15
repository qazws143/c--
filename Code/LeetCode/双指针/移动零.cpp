#include "vector"

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        for (fast; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0)
            {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};