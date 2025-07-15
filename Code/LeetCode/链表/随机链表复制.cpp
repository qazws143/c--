#include "vector"

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        /*创建一个复制结点,将结点插入到原结点*/
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            Node *cur = new Node(node->val);
            cur->next = node->next;
            node->next = cur;
        }

        /*再将原链表的random节点复制到复制链表*/
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            Node *cur = node->next;
            cur->random = (node->random != nullptr) ? node->random->next : nullptr;
        }

        /*将原链表与复制链表分开*/
        Node *headnew = head->next;
        for (Node *node = head; node != nullptr; node->next)
        {
            Node *cur = node->next;
            node->next = node->next->next;
            cur->next = (cur->next != nullptr) ? cur->next->next : nullptr;
        }
        return headnew;
    }
};