#include "vector"
#include "string"
#include "cstring"

using namespace std;

class Solution
{
public:
    vector<string> result;
    string path;
    const string map[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };
    void backtrack(const string &digits, int index)
    {
        if (index == digits.length()) // 遍历结束
        {
            result.push_back(path);
            return;
        }
        int digit = digits[index] - '0';         // 处理多位数
        string letters = map[digit];             // 将数字和字符串对应
        for (int i = 0; i < letters.size(); i++) // 遍历找到的字符串
        {
            path.push_back(letters[i]);
            backtrack(digits, index + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return result;
        backtrack(digits, 0);
        return result;
    }
};