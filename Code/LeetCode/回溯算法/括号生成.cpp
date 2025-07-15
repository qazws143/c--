#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution
{
public:
    vector<string> result;
    void backtrack(vector<string> &result, string current, int open, int close, int end)
    {
        if (current.size() == end * 2)
        {
            result.push_back(current);
            return;
        }
        if (open < end)
            backtrack(result, current + '(', open + 1, close, end);
        if (close < open)
            backtrack(result, current + ')', open, close + 1, end);
    }
    vector<string> generateParenthesis(int n)
    {
        backtrack(result, "", 0, 0, n);
        return result;
    }
};