#include "iostream"
#include "vector"
#include "algorithm"
// 15 三数之和
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;

        /*进行升序排列*/
        sort(nums.begin(), nums.end());
        /*进行三数寻找*/
        for (int i = 0; i < nums.size(); i++)
        {
            /*如果有一个数大于0,那么三个数无论如何也不会相加为0*/
            if (nums[i] > 0)
            {
                return result;
            }
            /*跳过重复的数值*/
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)
            {
                /*如果和比0小，说明left小了*/
                if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                /*如果和比0大，说明right大了*/
                else if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else
                {
                    /*将找到的数组添加进result*/
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    /*跳过重复数字,避免多余的三元组*/
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};