#include "vector"
#include "cstdio"
#include "string"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int Max_product;
        int Min_product;
        int ret;
        Max_product = Min_product = ret = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)                    // 如果当前数小于0
                swap(Max_product, Min_product); // 交换数值,因为乘以负数会使乘积大小变换
            Max_product = max(nums[i], Max_product * nums[i]);
            Min_product = min(nums[i], Min_product * nums[i]);
            ret = max(Max_product, ret);
        }
        return ret;
    }
};

int main(void)
{
    Solution sol;
    vector<int> ch1 = {-2, 3, -4};
    int i = 0;
    i = sol.maxProduct(ch1);
    printf("乘积最大的非空连续子数组的乘积:%d\n", i);
}