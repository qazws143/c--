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
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        /*寻找中节点*/
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        /*找到中节点后翻转链表*/
        ListNode *pre = nullptr;
        while (slow != nullptr)
        {
            ListNode *tmp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tmp;
        }
        /*比较中点前后元素*/
        ListNode *cur1 = head;
        ListNode *cur2 = pre;
        while (cur2 != nullptr)
        {
            if (cur1->val != cur2->val)
                return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }
};