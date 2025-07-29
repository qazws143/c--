/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30202
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head;                // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode *cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *swap1 = cur->next;             // swap1=1
            ListNode *swap2 = cur->next->next->next; // swap2=3

            cur->next = cur->next->next;   // dummy->2
            cur->next->next = swap1;       // 2->1
            cur->next->next->next = swap2; // 1->3

            cur = cur->next->next;
        }
        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
