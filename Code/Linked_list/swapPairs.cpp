#include "iostream"
// 24 两两交换链表中的节点
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        /*建立一个虚节点,指向头节点*/
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        /*当指向位置不为空时,继续遍历*/
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            /*创建临时缓冲区保存交换节点*/
            ListNode *tmp = cur->next;
            ListNode *tmp1 = cur->next->next->next;
            /*将第二个节点与第一个节点进行交换*/
            cur->next = cur->next->next;
            cur->next->next = tmp;
            /*将交换后的节点指向第三个节点*/
            /*交换后为B->A->C->D,如果不指向第三个节点*/
            /*则会变成B->A->B->A*/
            cur->next->next->next = tmp1;
            /*后移两位进行下一次交换*/
            cur = cur->next->next;
        }
        ListNode *result = dummyHead->next;
        /*删除，防止内存泄漏*/
        delete dummyHead;
        return result;
    }
};