#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;          // 定义一个哈希表
        for (int i = 0; i < nums.size(); i++) // 遍历数组
        {
            auto num = map.find(target - nums[i]); // 寻找两数之和的其中一个数
            if (num != map.end())
                return {num->second, i};            // 返回下标
            map.insert(pair<int, int>(nums[i], i)); // 将找到的数插入哈希表
        }
        return {};
    }
};