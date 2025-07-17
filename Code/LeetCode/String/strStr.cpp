#include "iostream"
#include "vector"
#include "algorithm"
#include "cstring"
// 28 找出字符串中第一个匹配项的下标
using namespace std;
class Solution
{
public:
    void getNext(int *next, const string &s)
    {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            /*前后缀不相同*/
            while (j >= 0 && s[i] != s[j + 1])
                j = next[j]; // 向前回退
            /*前后缀相同,同时移动i和j*/
            if (s[i] == s[j + 1])
                j++;
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;
        vector<int> next(needle.size());
        getNext(&next[0], needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j >= 0 && haystack[i] != needle[j + 1])
                j = next[j];
            if (haystack[i] == needle[j + 1])
                j++;
            if (j == needle.size() - 1)
                return i - j;
        }
        return -1;
    }
};
