#include "unordered_map"

using namespace std;

class LRUCache
{
private:
    struct ListNode
    {
        int key;
        int val;
        ListNode *prev;
        ListNode *next;
        ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    ListNode *head; // 虚拟头结点
    ListNode *tail; // 虚拟尾节点
    unordered_map<int, ListNode *> cache;

    // 将节点添加到链表头部
    void addToHead(ListNode *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // 将节点移动到链表头部
    void moveToHead(ListNode *node)
    {
        // 先从链表中移除节点
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // 再插入到头部
        addToHead(node);
    }

    // 删除尾部节点（最近未使用）
    ListNode *removeTail()
    {
        ListNode *node = tail->prev;
        node->prev->next = tail;
        tail->prev = node->prev;
        return node;
    }

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        // 初始化虚拟头尾节点
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        ListNode *node = cache[key];
        moveToHead(node); // 更新为最近使用
        return node->val;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            // 如果 key 已存在，更新 value 并移到头部
            ListNode *node = cache[key];
            node->val = value;
            moveToHead(node);
        }
        else
        {
            // 创建新节点并添加到头部
            ListNode *newNode = new ListNode(key, value);
            cache[key] = newNode;
            addToHead(newNode);
            // 如果超出容量，删除最久未使用的节点
            if (cache.size() > capacity)
            {
                ListNode *tailNode = removeTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
        }
    }
};