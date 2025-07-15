#include "iostream"
#include "vector"
#include "stack"
// 20 有效的括号
using namespace std;

bool isValid(string s)
{
    int size = s.size();
    stack<char> Valid;

    if (size % 2 != 0)
        return false;

    for (int i = 0; i < size; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            Valid.push(s[i]);
        }
        else
        {
            if (Valid.empty())
            {
                return false;
            }
            char top = Valid.top();
            if ((s[i] == ')' && top != '(') ||
                (s[i] == ']' && top != '[') ||
                (s[i] == '}' && top != '{'))
            {
                return false;
            }
            Valid.pop();
        }
    }
    return Valid.empty();
}

int main()
{
    cout << "输入的为()[]{}: ";
    cout << isValid("()[]{}") << endl;

    cout << "输入的为([)]: ";
    cout << isValid("([)]") << endl;

    cout << "输入的为(]: ";
    cout << isValid("(]") << endl;
    return 0;
}