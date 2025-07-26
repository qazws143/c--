#include "vector"
#include "stack"
#include "iostream"
#include "string"
#include "algorithm"
#include "unordered_map"
#include "unordered_set"
#include "cstdio"

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> Set(nums.begin(), nums.end());
        int cur_length = 0;
        int cur_number = 0;
        int Max_long = 0;
        for (const int &num : Set)
        {
            if (Set.find(num - 1) == Set.end())
            {
                cur_number = num;
                cur_length = 1;
            }
            while (Set.find(cur_number + 1) != Set.end())
            {
                cur_number++;
                cur_length++;
            }
            Max_long = max(Max_long, cur_length);
        }
        return Max_long;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int ret = sol.longestConsecutive(nums);
    printf("最长序列长度:%d\n", ret);
    return 0;
}
