#include "vector"
#include "cstdio"
#include "string"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int Word_size1 = word1.size();
        int Word_size2 = word2.size();
        vector<vector<int>> dp(Word_size1 + 1, vector<int>(Word_size2 + 1, 0));

        for (int i = 0; i <= Word_size1; i++)
        {
            dp[i][0] = i;
        }

        for (int j = 0; j <= Word_size2; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= Word_size1; i++)
        {
            for (int j = 1; j <= Word_size2; j++)
            {
                if (word1[i - 1] == word2[j - 1]) // 字符相等
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
        return dp[Word_size1][Word_size2];
    }
};

int main(void)
{
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";
    int i = sol.minDistance(word1, word2);
    printf("将word1转换成word2所使用的最少操作数:%d\n", i);
}