#include "iostream"
#include "algorithm"
#include "vector"
// 203 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *pre;         // 设置一个虚拟头节点
        ListNode *list = head; // 从头节点开始遍历链表
        while (list)
        {
            if (list->val == val) // 如果有删除的元素
            {
                if (list == head) // 如果是头节点
                {
                    head = list->next; // 头节点后移
                    delete (list);     // 删除原头节点
                    list = head;       // 新头节点
                }
                else
                {
                    pre->next = list->next; // 跳过list元素
                    delete (list);          // 删除跳过的元素
                    list = pre->next;       // 指向跳过元素的下一个元素
                }
            }
            else
            {
                pre = list;        // pre指向当前节点
                list = list->next; // list指向当前节点的下一个节点
            }
        }
        return head;
    }
};