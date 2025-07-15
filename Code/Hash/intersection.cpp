#include "iostream"
#include "unordered_set"
#include "vector"
// 349 两个数组交集
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result;
        unordered_set<int> set(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); i++)
        {
            /*set.end()表示未找到时返回*/
            if (set.find(nums2[i]) != set.end())
            {
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};