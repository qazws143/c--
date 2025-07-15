#include "vector"
#include "queue"
#include "unordered_map"
#include "stack"
#include "stdio.h"

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int num = 0;
        int vote = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (vote == 0)
                num = nums[i];
            vote += (nums[i] == num) ? 1 : -1;
        }
        return num;
    }
};