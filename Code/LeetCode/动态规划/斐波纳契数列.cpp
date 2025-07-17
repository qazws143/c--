#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n == 1 || n == 0)
            return n;
        int sum = 0;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n; i++)
        {
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return sum;
    }
};