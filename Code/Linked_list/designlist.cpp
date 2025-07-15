#include "iostream"
// 707 设计链表
using namespace std;

class MyLinkedList
{
public:
    struct LinkNode
    {
        int val;
        LinkNode *next;
        LinkNode(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList() // 初始化链表
    {
        dummyHead = new LinkNode(0);
        size = 0;
    }

    int get(int index)
    {
        /*如果索引大于链表长度或小于初始化长度*/
        if (index > (size - 1) || index < 0)
            return -1;
        /*定义一个链表节点,让虚拟节点指向它,代表头节点*/
        /*为了获取真实索引,所以不能从虚拟节点开始*/
        LinkNode *cur = dummyHead->next;
        /*进行链表遍历*/
        while (index--)
            /*将指针移动到获取节点的前一个节点*/
            cur = cur->next;
        /*找到该节点,返回节点值*/
        return cur->val;
    }

    void addAtHead(int val)
    {
        /*创建一个新节点,将值赋给节点*/
        LinkNode *newnode = new LinkNode(val);
        /*新节点指向虚拟头节点指向的节点,也就是头节点*/
        newnode->next = dummyHead->next;
        /*虚拟头节点指向新节点*/
        dummyHead->next = newnode;
        /*链表长度增加*/
        size++;
    }

    void addAtTail(int val)
    {
        LinkNode *newnode = new LinkNode(val);
        /*从虚拟节点开始遍历,避免了空节点的情况(nullptr->next)*/
        LinkNode *cur = dummyHead;
        /*遍历是否查找到空节点,也就是是否到达结尾*/
        while (cur->next != nullptr)
        { /*将指针移动到添加节点的前一个节点*/
            cur = cur->next;
        }
        /*尾节点指向新节点*/
        cur->next = newnode;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        /*如果索引大于链表长度,返回空*/
        if (index > size)
            return;
        /*如果小于链表长度,代表在头节点添加*/
        if (index < 0)
            index = 0;
        LinkNode *newnode = new LinkNode(val);
        /*从虚拟节点开始,保证能在头节点与尾节点插入节点*/
        LinkNode *cur = dummyHead;
        /*遍历链表*/
        while (index--)
            /*将指针移动到添加节点的前一个节点*/
            cur = cur->next;
        /*新节点指向索引到节点指向的节点*/
        newnode->next = cur->next;
        /*索引节点指向新节点*/
        cur->next = newnode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        /*如果索引大于或等于链表长度,返回空*/
        if (index >= size || size < 0)
            return;
        /*虚拟节点开始,确保遍历每个节点*/
        LinkNode *cur = dummyHead;
        /*遍历节点*/
        while (index--)
            /*将指针移动到删除节点的前一个节点*/
            cur = cur->next;
        /*新建一个节点保存删除节点*/
        LinkNode *tmp = cur->next;
        /*将前驱节点的next指针指向被删除节点的下一个节点*/
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        size--;
    }

private:
    int size;
    LinkNode *dummyHead;
};