#include "vector"
#include "algorithm"
#include "unordered_set"
#include <cstdio>
#include "string"
#include <cstring>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int size = s.size();
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        vector<bool> dp(size + 1, false); // 是否能组成字符串
        dp[0] = true;
        /*求排列数,先遍历背包,再遍历物品*/
        for (int i = 1; i <= size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                string word = s.substr(j, i - j);                 // 截取当前区间的子串
                if (wordset.find(word) != wordset.end() && dp[j]) // 检查是否能在子串中找到
                    dp[i] = true;
            }
        }
        return dp[size];
    }
};

int main(void)
{
    Solution sol;
    vector<string> wordDict = {"leet", "code"};
    string s = "leetcode";
    bool i = true;
    i = sol.wordBreak(s, wordDict);
    if (i == true)
        printf("true");
    else
        printf("false");
}