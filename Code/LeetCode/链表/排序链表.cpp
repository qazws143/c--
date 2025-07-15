#include "vector"
#include "algorithm"

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
    ListNode *Merge(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 分割链表
        ListNode *mid = slow->next;
        slow->next = nullptr;
        // 递归排序
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);

        return Merge(left, right);
    }
};