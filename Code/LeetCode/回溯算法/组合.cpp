#include "vector"

using namespace std;

class Solution
{
public:
    vector<vector<int>> result; // 保存组合
    vector<int> path;           // 每一行的组合
    /*end表示最大范围,nums表示每组元素数目,index防止重复*/
    void backtrack(int end, int nums, int index)
    {
        if (path.size() == nums) // 当元素数量等于要求每组元素个数时
        {
            result.push_back(path);
            return;
        }
        for (int i = index; i <= end; i++)
        {
            path.push_back(i);
            backtrack(end, nums, i + 1); // index+1表示从下一个开始,防止重复
            path.pop_back();             // 撤销回溯
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        backtrack(n, k, 1);
        return result;
    }
};