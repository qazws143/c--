#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = nums[0];     // 初始化最大和
        int currentSum = nums[0]; // 当前最大和

        for (int i = 1; i < nums.size(); i++)
        {
            /*将当前数组元素与之前的数组和相加,并与之前的数组和相比较*/
            currentSum = max(nums[i], currentSum + nums[i]);
            /*比较出最大的数组和*/
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};