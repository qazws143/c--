#include "iostream"
#include "vector"
#include "cstring"
// 344 反转字符串
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        size_t left = 0;
        size_t right = s.size() - 1;
        while (left < right)
        {
            char tmp;
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};