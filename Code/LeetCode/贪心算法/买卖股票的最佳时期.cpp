#include "vector"

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;             // 处理空数组的情况
        int MinStock = prices[0]; // 记录最小股票值
        int CurProfit = 0;        // 记录最大利润
        int MaxProfit = 0;        // 上一利润值
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < MinStock) // 当前值小于假设的最小股票值
            {
                MinStock = prices[i];
            }
            else
            {
                CurProfit = prices[i] - MinStock; // 计算当前利润
                if (CurProfit > MaxProfit)        // 如果当前利润大于上一次利润
                {
                    MaxProfit = CurProfit;
                }
            }
        }
        return MaxProfit;
    }
};