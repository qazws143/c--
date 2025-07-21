#include "vector"
#include <cstdio>
#include "algorithm"

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        int sum = 0; // 最大利润和
        for (int i = 1; i < size; i++)
        {
            sum += max(prices[i] - prices[i - 1], 0);
        }
        return sum;
    }
};

int main(void)
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int i = sol.maxProfit(prices);
    printf("能获取的最大利润%d", i);
}