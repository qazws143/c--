#include "iostream"
#include "vector"
#include "algorithm"
// 541 反转字符串II
using namespace std;
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        /*每次遍历2k个字符*/
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            /*如果剩余字符大于等于k,反转前k个字符*/
            if (i + k <= s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            /*如果剩余字符少于k个,将剩余字符反转*/
            else
            {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};