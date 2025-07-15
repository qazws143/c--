#include "stdio.h"
// 232 用栈实现队列
typedef struct
{
    int stackIntop, stackOuttop;
    int stackIn[100], stackOut[100];

} MyQueue;

/// @brief 创建栈
/// @return 队列
MyQueue *myQueueCreate()
{
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->stackIntop = 0;
    queue->stackOuttop = 0;
    return queue;
}

/// @brief 压入队列元素
/// @param obj
/// @param x 元素
void myQueuePush(MyQueue *obj, int x)
{
    obj->stackIn[(obj->stackIntop)++] = x;
}

int myQueuePop(MyQueue *obj)
{
    int stackIntop = obj->stackIntop;
    int stackouttop = obj->stackOuttop;

    if (stackouttop == 0) // 判断出栈数组是否为空
    {
        while (stackIntop > 0)
        {
            // 将入栈元素压入存放到出栈
            obj->stackOut[stackouttop++] = obj->stackIn[--stackIntop];
        }
    }
    int top = obj->stackOut[--stackouttop];

    // 将输出栈元素放回输入栈中,模拟队列输出
    while (stackouttop > 0)
    {
        obj->stackIn[stackIntop++] = obj->stackOut[--stackouttop];
    }
    obj->stackIntop = stackIntop;
    obj->stackOuttop = stackouttop;

    return top;
}

/// @brief 返回栈顶指针
int myQueuePeek(MyQueue *obj)
{
    return obj->stackIn[0];
}

/// @brief 判断是否为空
/// @param obj
/// @return
bool myQueueEmpty(MyQueue *obj)
{
    return obj->stackIntop == 0 && obj->stackOuttop == 0;
}

void myQueueFree(MyQueue *obj)
{
    obj->stackIntop = 0;
    obj->stackOuttop = 0;
}