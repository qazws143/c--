#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int child = 0;  // 满足孩子数
        int cookie = 0; // 饼干
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (child < g.size() && cookie < s.size())
        {
            if (s[cookie] >= g[child])
            {
                child++;
            }
            cookie++;
        }
        return child;
    }
};