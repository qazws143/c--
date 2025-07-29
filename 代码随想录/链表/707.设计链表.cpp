/*
 * @lc app=leetcode.cn id=707 lang=cpp
 * @lcpr version=30202
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList
{
public:
    struct LinkNode
    {
        int val;
        LinkNode *next;
        LinkNode(int val) : val(val), next(nullptr) {}
    };

    LinkNode *dummy;
    int size = 0;

    MyLinkedList()
    {
        dummy = new LinkNode(0);
        int size = 0;
    }

    int get(int index)
    {
        if (index > (size - 1) || index < 0)
            return -1; // 索引无效时返回-1
        LinkNode *cur = dummy->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        LinkNode *headnode = new LinkNode(val);
        headnode->next = dummy->next;
        dummy->next = headnode;
        size++;
    }

    void addAtTail(int val)
    {
        LinkNode *cur = dummy; // 初始化为虚拟头文件,确保每个都遍历
        int index = size;
        while (index--)
        {
            cur = cur->next;
        }
        cur->next = new LinkNode(val);
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index < 0)
            index = 0;
        LinkNode *indexnode = new LinkNode(val);
        LinkNode *cur = dummy;
        while (index--)
        {
            cur = cur->next;
        }
        indexnode->next = cur->next;
        cur->next = indexnode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index > (size - 1) || index < 0)
            return;
        LinkNode *cur = dummy;
        while (index--)
        {
            cur = cur->next;
        }
        LinkNode *temp = cur->next;
        cur->next = cur->next->next;
        delete (temp);
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
