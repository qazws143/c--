#include "vector"
#include "string"
#include "stack"

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' ||
                s[i] == '[' ||
                s[i] == '{')
            {
                stk.push(s[i]);
            }
            else
            {
                if (stk.empty())
                    return false;
                char top = stk.top();
                if ((s[i] == ')' && top != '(') ||
                    (s[i] == ']' && top != '[') ||
                    (s[i] == '}' && top != '{'))
                {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};