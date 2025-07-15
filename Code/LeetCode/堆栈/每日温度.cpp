#include "vector"
#include "stack"
#include "string"

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int size = temperatures.size();
        vector<int> days(size, 0);
        stack<int> st;
        st.push(0);
        // 遍历温度数组
        for (int i = 0; i < size; i++)
        {
            // 对比下标对应数的大小
            // 小于或者等于当前数,将索引加入栈中
            if (temperatures[i] < temperatures[st.top()])
                st.push(i);
            else if (temperatures[i] == temperatures[st.top()])
                st.push(i);
            else
            { // 如果遍历到的元素大于栈顶索引对应的元素
                while (!st.empty() && temperatures[i] > temperatures[st.top()])
                {
                    // 将当前索引减去栈顶索引,得出两者相距的距离
                    days[st.top()] = i - st.top();
                    // 比完后弹出之前的索引,不再遍历
                    st.pop();
                }
                st.push(i);
            }
        }
        return days;
    }
};