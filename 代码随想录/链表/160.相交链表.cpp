/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30202
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "algorithm"
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int LenA = 0;
        int LenB = 0;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA != nullptr)
        {
            curA = curA->next;
            LenA++;
        }
        while (curB != nullptr)
        {
            curB = curB->next;
            LenB++;
        }
        curA = headA;
        curB = headB;
        if (LenB > LenA)
        {
            swap(LenA, LenB);
            swap(curA, curB);
        }
        int nums = LenA - LenB;
        while (nums--)
        {
            curA = curA->next;
        }
        while (curA != nullptr)
        {
            if (curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */
