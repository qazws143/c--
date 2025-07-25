#include "vector"
#include "stack"
#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        // 初始化dp数组,记录行列操作数
        for (int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++)
            dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                // 如果当前字符相同,不需要进行操作
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else // 不等于则进行替换,删除,增加
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main()
{
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";
    int ret = sol.minDistance(word1, word2);
    printf("将word1转换为word2所使用最少操作数:%d", ret);
    return 0;
}
