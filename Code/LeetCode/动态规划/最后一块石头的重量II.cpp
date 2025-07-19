#include "vector"
#include "algorithm"
#include <cstdio>

using namespace std;

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int size = stones.size();
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += stones[i];
        }
        int target = sum / 2; // 将一堆石头分割成两个重量和相近的石头,再一相撞就成为了最小重量

        vector<int> dp(target + 1, 0); // 石头的最小重量
        for (int i = 0; i < size; i++) // 遍历石头的个数
        {
            for (int j = target; j >= stones[i]; j--) // 最多可装
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};

int main(void)
{
    Solution sol;
    vector<int> n = {31, 26, 33, 21, 40};
    int i = 0;
    i = sol.lastStoneWeightII(n);
    printf("最小石头为:%d\n", i);
}