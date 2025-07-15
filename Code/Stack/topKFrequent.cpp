#include "iostream"
#include "vector"
#include "unordered_map"
#include "queue"

// 347 前k个高频元素
using namespace std;

class Solution
{
public:
    class comparison
    {
    public: // 比较器类,用于比较第二个元素,即频率
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++; // 统计数组中元素出现的次数
        }
        // 定义一个优先队列
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparison> pri_que;

        for (auto it = map.begin(); it != map.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pri_que.top().first; // 弹出数字部分
            pri_que.pop();
        }
        return result;
    }
};