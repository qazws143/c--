#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        for (int i = 0; i < intervals.size();)
        {
            int end = intervals[i][1]; // 设置一个临时变量为每个数组的结尾数
            int next = i + 1;          // next表示下一个数

            // 一直遍历直到结尾或大于上一个数组的起始数
            while (next < intervals.size() && intervals[next][0] <= end)
            {
                // 将下一个数组的结尾数赋值给上一个数组的结尾数
                end = max(end, intervals[next][1]);
                next++; // 赋值完后向后移
            }
            result.push_back({intervals[i][0], end});
            i = next;
        }
        return result;
    }
};