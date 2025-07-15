#include "unordered_map"
#include "vector"
#include "string"

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> pcount; // 字符串p中字符的频率
        unordered_map<char, int> window; // 滑动窗口中字符的频率
        vector<int> index;

        for (char c : p)
        {
            pcount[c]++; // 字符统计
        }

        int left = 0, right = 0;
        int size = pcount.size(); // 需要匹配的字符数
        int formed = 0;           // 已匹配的不同字符数

        while (right < s.size()) // 遍历s字符串
        {
            char c = s[right];
            window[c]++; // 将s字符串元素放入窗口中

            // 查看窗口中是否包含字符串p的字符
            if (pcount.find(c) != pcount.end() && window[c] == pcount[c])
            {
                formed++;
            }
            // 当窗口大小等于字符串p的长度时,检查是否有异位词
            while (left <= right && (right - left + 1) == p.size())
            {
                if (formed == size)
                {
                    index.push_back(left); // 将异位词头字符索引放入
                }
                // 移动左指针,缩小窗口
                char leftchar = s[left];
                if (pcount.find(leftchar) != pcount.end() && window[leftchar] == pcount[leftchar])
                {
                    formed--;
                }
                window[leftchar]--;
                left++;
            }
            right++;
        }
        return index;
    }
};