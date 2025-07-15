#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    struct ListNode
    {
        ListNode *next;
        int val;
    };
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;

        /*计算两个链表的长度*/
        int lenA = 0;
        while (curA != nullptr)
        {
            lenA++;
            curA = curA->next;
        }

        int lenB = 0;
        while (curB != nullptr)
        {
            lenB++;
            curB = curB->next;
        }

        /*重新赋值*/
        curA = headA;
        curB = headB;
        /*交换长度与元素,方便计算*/
        if (lenA < lenB)
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        /*计算二者差值*/
        int nums = lenA - lenB;
        /*将curA往后移相差的数量*/
        while (nums--)
            curA = curA->next;
        /*移动后进行比较*/
        while (curA != nullptr)
        {
            /*第一个元素相等,即为相交结点*/
            if (curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};