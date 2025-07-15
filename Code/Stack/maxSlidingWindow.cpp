#include "iostream"
#include "vector"
#include "queue"
// 239 滑动窗口最大值
using namespace std;

class Solution
{
private:
    class MyQueue
    {
    public:
        deque<int> queue;
        void pop(int value)
        { // 如果队头元素为最大值,也就是需要弹出的元素
            if (!queue.empty() && queue.front() == value)
                queue.pop_front();
        }
        void push(int value)
        { // 新加进来的元素大于前面的元素，则将前面的元素都弹出
            while (!queue.empty() && queue.back() < value)
            {
                queue.pop_back();
            }
            queue.push_back(value); // 推入新元素
        }
        int front()
        {
            return queue.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MyQueue queue;
        vector<int> result;
        for (int i = 0; i < k; i++)
            queue.push(nums[i]);
        result.push_back(queue.front()); // 记录第一个窗口对应的最大值
        for (int i = k; i < nums.size(); i++)
        {
            queue.pop(nums[i - k]);          // 滑动窗口移除最前面元素
            queue.push(nums[i]);             // 滑动窗口前加入最后面的元素
            result.push_back(queue.front()); // 记录对应的最大值
        }
        return result;
    }
};