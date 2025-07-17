#include "iostream"
// 19 删除链表的倒数第N个节点
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *fast = dummyHead;
        ListNode *slow = dummyHead;
        while (n-- && fast != nullptr)
            fast = fast->next;
        /*不能使用if,因为只会判断一次*/
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};