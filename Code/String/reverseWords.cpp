#include "iostream"
#include "vector"
#include "cstring"
// 151 翻转字符串里的单词
using namespace std;

class Solution
{
public:
    void reverse(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
            swap(s[i], s[j]);
    }

    void removeExtraSpaces(string &str)
    {
        int slow = 0;
        /*遍历整个字符串*/
        for (int i = 0; i < str.size(); ++i)
        {
            /*如果当前不为空格,说明遇到单词了*/
            if (str[i] != ' ')
            {
                /*slow不等于0说明不为第一个单词*/
                if (slow != 0)
                    str[slow++] = ' ';
                /*将单词向前一位*/
                while (i < str.size() && str[i] != ' ')
                {
                    str[slow++] = str[i++];
                }
            }
        }
        str.resize(slow);
    }
    string reverseWords(string s)
    {
        /*删除多余空格*/
        removeExtraSpaces(s);
        /*先将整体翻转过来*/
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if (s[i] == ' ' || i == s.size())
            {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};