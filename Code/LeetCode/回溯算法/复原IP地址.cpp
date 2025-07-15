#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution
{
public:
    vector<string> result;
    bool isIP(const string &s, int start, int end)
    {
        if (start > end || end > s.size())
            return false;
        if (s[start] == '0' && start != end)
            return false;
        int num = 0;
        for (int i = start; i <= end; i++)
        {
            if (!isdigit(s[i])) // 如果不是数字
                return false;
            num = num * 10 + (s[i] - '0');
            if (num > 255)
                return false;
        }
        return true;
    }
    void backtrack(const string &s, int index, int count, string current)
    {
        if (count == 4 && index == s.size())
        {
            result.push_back(current);
            return;
        }
        for (int i = 1; i <= 3; i++) // 分析接下来一到三个字符是否合法
        {
            if (isIP(s, index, index + i - 1)) // 分析开始到下一个字符是否是合法IP
            {
                string segment = s.substr(index, i); // 合法则将该范围的字符加入临时字符串

                // 判断是否为空,空则等于临时字符,不为空则加上分割.然后加上上一个字符串
                string newcurrent = current.empty() ? segment : current + '.' + segment;
                backtrack(s, index + i, count + 1, newcurrent); // 加上i,分析下一个字符串的合法性
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4 || s.size() > 12)
            return result;
        backtrack(s, 0, 0, "");
        return result;
    }
};