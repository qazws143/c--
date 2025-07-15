#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int right = 0;
        int len = 0;
        unordered_set<char> result; // 存储字符

        for (right; right < s.size(); right++)
        {
            while (result.count(s[right])) // 判断字符是否存在哈希表
            {
                result.erase(s[left]); // 存在则删除哈希表中元素,直到无重复
                left++;
            }
            result.insert(s[right]); // 没有则加入元素
            len = max(len, right - left + 1);
        }
        return len;
    }
};