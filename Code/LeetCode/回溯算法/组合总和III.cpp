#include "vector"

using namespace std;

class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    int currentsum = 0;
    void backtrack(int nums, int sum, int currentsum, int index)
    {
        if (path.size() == nums && currentsum == sum) // 满足数组大小,且和等于要求值时
        {
            result.push_back(path);
            return;
        }
        if (path.size() > nums || currentsum > sum) // 终止无效数组
        {
            return;
        }
        for (int i = index; i <= 9; i++)
        {
            path.push_back(i);
            backtrack(nums, sum, currentsum + i, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtrack(k, n, currentsum, 1);
        return result;
    }
};