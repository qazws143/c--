#include "vector"

using namespace std;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0); // 哑节点
        ListNode *tail = dummy;
        int carry = 0; // 进位值

        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;                    // 计算进位
            tail->next = new ListNode(sum % 10); // 创建新节点存储当前位
            tail = tail->next;
        }

        ListNode *result = dummy->next;
        delete dummy; // 释放哑节点
        return result;
    }
};