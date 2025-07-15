#include "vector"
#include <iostream>
#include <string>
#include "algorithm"

using namespace std;

class Solution
{
public:
    vector<vector<string>> result;
    vector<string> path;
    bool isPalindrome(const string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
    void backtrack(const string &s, int index)
    {
        if (index >= s.size()) // 索引到子串结尾
        {
            result.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i)) // 判断是否为回文数
            {
                string str = s.substr(index, i - index + 1);
                path.push_back(str);
            }
            else
                continue;
            backtrack(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s)
    {
        backtrack(s, 0);
        return result;
    }
};