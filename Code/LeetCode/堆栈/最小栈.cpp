#include "vector"
#include "stack"
using namespace std;

class MinStack
{
public:
    vector<int> stk;     // 主堆栈
    vector<int> min_stk; // 最小堆栈
    MinStack()
    {
    }

    void push(int val)
    {
        stk.push_back(val);
        // 如果最小堆栈为空或新加进来的数小于前一个数
        if (min_stk.empty() || val <= min_stk.back())
            min_stk.push_back(val);
    }

    void pop()
    {
        if (stk.empty() || min_stk.empty())
            return;
        // 若主堆栈和最小堆栈最后一个元素相同
        // 最小堆栈也要弹出
        if (stk.back() == min_stk.back())
            min_stk.pop_back();
        stk.pop_back();
    }

    int top()
    {
        if (stk.empty())
            return NULL;
        return stk.back();
    }

    int getMin()
    {
        return min_stk.back();
    }
};