#include "stdio.h"
#include "stdlib.h"

// 队列结点
struct Node
{
    int data;
    Node *next;
};

// 创建队列结点
struct Node *createNode(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
// 队列
struct Queue
{
    Node *front;
    Node *tail;
    int size;
};
// 创建队列
struct Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->tail = NULL;
    queue->size = 0;
    return queue;
}

void push(Queue *queue, int data)
{
    Node *node = createNode(data);
    if (queue->size == 0)
    {
        queue->front = queue->tail = node;
    }
    else
    {
        queue->tail->next = node;
        queue->tail = node;
    }
    queue->size++;
}

void pop(Queue *queue)
{
    if (queue->size == 0)
    {
        printf("队为空,无法出队\n");
        return;
    }
    else
    {
        Node *node = queue->front->next;
        free(queue->front);
        queue->front = node;
        queue->size--;
    }
}

int front(Queue *queue)
{
    if (queue->size == 0)
    {
        printf("队为空,无法获取队头元素\n");
        return 0;
    }
    return queue->front->data;
}

int empty(Queue *queue)
{
    if (queue->size == 0)
        return 0;
    return 1;
}

int main()
{
    Queue *queue = createQueue();
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    while (empty(queue))
    {
        printf("%d\t", front(queue));
        pop(queue);
    }
    printf("\n");
    return 0;
}