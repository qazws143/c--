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
        int CurStock = 0;         // 记录当前股票值
        int CurProfit = 0;        // 记录最大利润
        int MaxProfit = 0;        // 上一利润值
        for (int i = 1; i < prices.size(); i++)
        {
            CurStock = prices[i];
            if (CurStock < MinStock) // 当前值小于假设的最小股票值
            {
                MinStock = CurStock;
            }
            else
            {
                CurProfit = CurStock - MinStock; // 计算当前利润
                if (CurProfit > PreProfit)       // 如果当前利润大于上一次利润
                {
                    PreProfit = CurProfit;
                }
            }
        }
        return PreProfit;
    }
};