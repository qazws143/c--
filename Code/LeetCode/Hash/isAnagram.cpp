#include "unordered_map"
#include "string"
// 242 有效的字母异位词
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> charCount;
        if (s.size() != t.size())
            return false;
        for (char c : s)
            charCount[c]++;

        for (char c : t)
        {
            charCount[c]--;
            // 如果某个字符的计数小于0，说明t中有s不存在的字符
            if (charCount[c] < 0)
            {
                return false;
            }
        }
        return true;
    }
};