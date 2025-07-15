#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *tail;
    int size;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *queue = (MyStack *)malloc(sizeof(MyStack));
    queue->front = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

Node *myNodeCreate(int x)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}

void myStackPush(MyStack *obj, int x)
{
    Node *node = myNodeCreate(x);
    if (obj->tail)
    {
        obj->tail->next = node;
    }
    else
    {
        obj->front = node;
    }
    obj->tail = node;
    obj->size++;
}

int myStackPop(MyStack *obj)
{
    int target = obj->tail->val;
    if (obj->front == obj->tail)
    {
        free(obj->front);
        obj->front = obj->tail = NULL;
    }
    else
    {
        Node *pre = obj->front;        // 从头开始遍历
        while (pre->next != obj->tail) // 找到tail的前一个结点
            pre = pre->next;
        free(obj->tail);
        obj->tail = pre;
        obj->tail->next = NULL;
    }
    obj->size--;
    return target;
}

int myStackTop(MyStack *obj)
{
    return obj->tail->val;
}

bool myStackEmpty(MyStack *obj)
{
    return obj->size == 0;
}

void myStackFree(MyStack *obj)
{
    Node *cur = obj->front;
    while (cur != NULL)
    {
        Node *temp = cur->next;
        free(cur);
        cur = temp;
    }
    free(obj);
}