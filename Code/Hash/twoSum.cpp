#include "iostream"
#include "vector"
#include "unordered_map"

// 1 两数之和
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /*创建一个map映射*/
        unordered_map<int, int> map;
        /*遍历数组*/
        for (int i = 0; i < nums.size(); i++)
        {
            /*判断两数中一个元素是否在map中*/
            auto num = map.find(target - nums[i]);
            if (num != map.end())
            {
                return {num->second, i}; // 有则返回索引
            }
            /*没有则将该数放入map中,pair的作用是将两个元素归为一个对象*/
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};