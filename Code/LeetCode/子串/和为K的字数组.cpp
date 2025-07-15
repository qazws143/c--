#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        map[0] = 1;         // 初始前缀和0为1次
        int currentSum = 0; // 当前前缀和
        int count = 0;      // 满足条件的数量
        for (int num : nums)
        {
            currentSum += num; // 计算当前前缀和
            if (map.find(currentSum - k) != map.end())
                count += map[currentSum - k];
            map[currentSum]++;
        }
        return count;
    }
};