#include "iostream"
#include "unordered_set"

// 202 快乐数
using namespace std;

class Solution
{
public:
    int get_sum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        unordered_set<int> set;
        while (1)
        {
            int sum = get_sum(n);
            if (sum == 1)
                return true;
            /*如果有重复的说明程序进入死循环,返回false*/
            if (set.find(sum) != set.end())
            {
                return false;
            }
            else // 没有则将和加入到哈希表,进行下一次比较
            {
                set.insert(sum);
            }
            n = sum;
        }
    }
};