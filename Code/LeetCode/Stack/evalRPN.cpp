#include "iostream"
#include "vector"
#include "stack"
#include "string"
// 150 逆波兰表达式求值
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> math;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" ||
                tokens[i] == "-" ||
                tokens[i] == "*" ||
                tokens[i] == "/")
            {
                long long num1 = math.top();
                math.pop();
                long long num2 = math.top();
                math.pop();
                if (tokens[i] == "+")
                    math.push(num2 + num1);
                if (tokens[i] == "-")
                    math.push(num2 - num1);
                if (tokens[i] == "*")
                    math.push(num2 * num1);
                if (tokens[i] == "/")
                    math.push(num2 / num1);
            }
            else
            {
                math.push(stoll(tokens[i]));
            }
        }
        long long result = math.top();
        math.pop();
        return result;
    }
};