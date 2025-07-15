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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        /*使用快慢指针,当快慢指针相遇时代表有环*/
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                /*再次使用快慢指针寻找索引*/
                ListNode *index = fast;
                ListNode *index_head = head;
                while (index != index_head)
                {
                    index = index->next;
                    index_head = index_head->next;
                }
                return index;
            }
        }
        return NULL;
    }
};