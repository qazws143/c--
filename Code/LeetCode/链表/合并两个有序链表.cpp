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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        /*遍历两个链表*/
        while (list1 && list2)
        {
            /*比较链表值*/
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
        /*处理链表剩余的元素*/
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};