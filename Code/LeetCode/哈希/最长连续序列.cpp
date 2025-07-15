#include "vector"
#include "algorithm"
#include "unordered_set"

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int longstreak = 0;                               // 初始化最长序列为0
        unordered_set<int> set(nums.begin(), nums.end()); // 将数组放入哈希表
        for (int num : set)                               // 遍历哈希表
        {
            if (set.find(num - 1) == set.end())
            { // 将遍历的每个数字减一,并在哈希表中寻找,如果存在则往下进行
                int currentnum = num;
                int currentstreak = 1;
                while (set.find(currentnum + 1) != set.end())
                {
                    currentnum++;
                    currentstreak++;
                }
                longstreak = max(currentstreak, longstreak);
            }
        }
        return longstreak;
    }
};