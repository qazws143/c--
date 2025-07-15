#include "iostream"
#include "vector"
#include "algorithm"
// 18 四数之和
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // 跳过重复的 nums[i]

            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue; // 跳过重复的 nums[j]

                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum < target)
                    {
                        left++;
                    }
                    else if (sum > target)
                    {
                        right--;
                    }
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                            left++; // 跳过重复的 left
                        while (left < right && nums[right] == nums[right - 1])
                            right--; // 跳过重复的 right

                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};