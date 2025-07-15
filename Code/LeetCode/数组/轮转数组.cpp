#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int size = nums.size(); // 数组大小
        k %= size;
        reverse(nums.begin(), nums.end());       // 先全部翻转
        reverse(nums.begin(), nums.begin() + k); // 再翻转取模后的前k个
        reverse(nums.begin() + k, nums.end());
    }
};