#include "iostream"
// 142 环形链表II
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        /*快慢指针从头节点开始遍历*/
        ListNode *fast = head;
        ListNode *slow = head;
        /*遇到空节点时,代表没有环*/
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            /*相遇节点*/
            if (fast == slow)
            {
                /*设相遇节点为index1*/
                ListNode *index1 = fast;
                /*设index2指针指向头节点*/
                ListNode *index2 = head;
                /*两者相遇位置即为环入口*/
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
};