#include "stack"
#include "iostream"
#include "cstdlib"

struct LinkNode
{
    int val;
    LinkNode *next;
};

// 创建结点
struct LinkNode *createNode(int data)
{
    LinkNode *newNode = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
};

struct stack
{
    LinkNode *stackTop; // 栈顶
    int size;           // 栈中元素
};

// 创建栈
struct stack *createstack()
{
    stack *Stack = (struct stack *)malloc(sizeof(struct stack));
    Stack->stackTop = NULL;
    Stack->size = 0;
    return Stack;
}

void push(stack *stack, int data)
{
    // 创建插入结点
    LinkNode *Node = createNode(data);
    // 入栈就是链表头插入
    Node->next = stack->stackTop;
    stack->stackTop = Node;
    stack->size++;
}

// 获取栈顶元素
int top(stack *Stack)
{
    if (Stack->size == 0)
    {
        printf("栈为空,无栈顶元素\n");
        return Stack->size;
    }
    return Stack->stackTop->val;
}

// 出栈
void pop(stack *Stack)
{
    if (Stack->size == 0)
    {
        printf("栈为空,无法出栈\n");
    }
    else
    {
        LinkNode *nextnode = Stack->stackTop->next;
        free(Stack->stackTop);
        Stack->stackTop = nextnode;
        Stack->size--;
    }
}

int empty(stack *Stack)
{
    if (Stack->size == 0)
        return 0;
    return 1;
}
int main()
{
    stack *Stack = createstack();
    push(Stack, 1);
    push(Stack, 2);
    push(Stack, 3);
    while (empty(Stack))
    {
        printf("%d\t", top(Stack));
        pop(Stack);
    }
    printf("\n");

    return 0;
}