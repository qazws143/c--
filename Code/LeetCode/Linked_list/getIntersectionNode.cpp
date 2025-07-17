#include "iostream"

// 160 相交链表
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;
        int len;
        while (curA != NULL)
        {
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL)
        {
            lenB++;
            curB = curB->next;
        }
        /*因为A和B已经遍历完了,所以重新指向头节点*/
        curA = headA;
        curB = headB;
        if (lenB > lenA)
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        len = lenA - lenB;
        while (len--)
            curA = curA->next;
        while (curA != NULL)
        {
            if (curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};