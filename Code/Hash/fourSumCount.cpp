#include "iostream"
#include "vector"
#include "unordered_map"
// 454 四数相加II
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> map;
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                /*统计a+b和出现的次数*/
                map[a + b]++;
            }
        }
        int count = 0;
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                /*判断map中是否存在-(c+d)*/
                /*用于判断a+b=-(c+d)*/
                if (map.find(0 - (c + d)) != map.end())
                {
                    count += map[0 - (c + d)];
                }
            }
        }
        return count;
    }
};