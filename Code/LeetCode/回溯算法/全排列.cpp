#include "vector"

using namespace std;

class Solution
{
public:
    vector<vector<int>> result; // 存放最终排列结果
    vector<int> path;           // 存放当前行排列结国
    void backtrack(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path); // 返回一行排列
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == true)
                continue; // 如果当前元素已被使用,跳过循环
            // 做选择
            used[i] = true;
            path.push_back(nums[i]);
            // 进入下一层
            backtrack(nums, used);
            // 撤销回溯
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return result;
    }
};