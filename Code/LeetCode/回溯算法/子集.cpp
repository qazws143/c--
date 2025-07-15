#include "vector"

using namespace std;

class Solution
{
public:
    vector<vector<int>> result; // 存储子集
    vector<int> path;           // 存储当前行自己
    void backtrack(vector<int> &nums, int index)
    {
        result.push_back(path);
        if (index >= nums.size()) // 将空集也包含进去
        {
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        result.clear();
        path.clear();
        int index = 0;
        backtrack(nums, index);
        return result;
    }
};