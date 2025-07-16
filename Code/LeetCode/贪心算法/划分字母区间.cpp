#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> nums;             // 保存每个字符串字符个数
        unordered_map<char, int> map; // 记录每个字符出现的次数
        int start = 0;                // 滑动窗口起始位置
        int end = 0;                  // 滑动窗口结束位置
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i]] = i;
        }
        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, map[s[i]]); // 记录元素最后出现的位置
            int num = end - start + 1; // 记录区间内元素个数
            if (i == end)              // 当索引到窗口结尾时再更新
            {
                start = end + 1; // 重新开始一个区间
                nums.push_back(num);
            }
        }
        return nums;
    }
};