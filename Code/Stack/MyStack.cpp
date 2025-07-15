#include "iostream"
#include "vector"
#include "queue"

using namespace std;

class MyStack
{
public:
    queue<int> queue;
    MyStack()
    {
    }

    void push(int x)
    {
        queue.push(x);
    }

    int pop()
    {
        int size = queue.size();
        size--; // 除了最后一个元素,其余元素先移出去，再移动最后一个
        while (size--)
        {
            queue.push(queue.front());
            queue.pop();
        }
        int result = queue.front();
        queue.pop();
        return result;
    }

    int top()
    {
        int size = queue.size();
        size--; // 除了最后一个元素,其余元素先移出去，再移动最后一个
        while (size--)
        {
            queue.push(queue.front());
            queue.pop();
        }
        int result = queue.front();
        queue.push(queue.front()); // 元素获取完后,重新放回队列
        queue.pop();
        return result;
    }

    bool empty()
    {
        return queue.empty();
    }
};