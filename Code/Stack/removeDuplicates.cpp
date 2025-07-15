#include "iostream"
#include "algorithm"
#include "vector"
#include "stack"
// 1047 删除字符串中的所有相邻重复项
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        int size = s.size();
        stack<char> remove;
        for (int i = 0; i < size; i++)
        {
            if (remove.empty() || remove.top() != s[i])
            {
                remove.push(s[i]);
            }
            else
            {
                remove.pop();
            }
        }
        string result = "";
        while (!remove.empty())
        {
            result += remove.top();
            remove.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};