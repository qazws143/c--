#include "vector"

using namespace std;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode() : val(x), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy;
        /*1,2,3,4*/
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *tmp = cur->next;              // tmp->1
            ListNode *tmp1 = cur->next->next->next; // tmp1->3

            cur->next = cur->next->next;  // dummy.next->2
            cur->next->next = tmp;        // 2.next->1
            cur->next->next->next = tmp1; // 1.next->3

            /*一组两个交换,交换一次后移两个结点*/
            cur = cur->next->next; // cur->1
        }
        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};