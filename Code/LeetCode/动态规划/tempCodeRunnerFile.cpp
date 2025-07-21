class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        int sum = 0; // 最大利润和
        for (int i = 0; i < size; i++)
        {
            sum += max(prices[i] - prices[i - 1], 0);
        }
        return sum;
    }
};