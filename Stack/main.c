#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/*
//定义链表节点
typedef struct Node
{
    int data;
    struct Node* Next;
}Node;

//定义栈
typedef struct Stack
{
    Node* Top;
    int Size;
}Stack;
//判断栈是否为空
int IfEmpty(Stack* stack)
{
    return stack->Top == NULL;
}
//初始化栈
void InitStack(Stack* stack)
{
    stack->Top = NULL;
    stack->Size = 0;
}
//入栈
void Push(Stack* stack , int element)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = element;
    newNode->Next = stack->Top;
    stack->Top = newNode;
    stack->Size++;
}
//出栈
int Pop(Stack* stack)
{
    if(IfEmpty(stack)){
        printf("Stack underflow.\n");
        exit(1);            //程序错误，跳出程序，返回状态码1给系统
    }
    Node* temp = stack->Top;
    stack->Top = temp->Next;
    int popped = temp->data;
    free(temp);
    stack->Size--;
    return popped;
}
//获取栈的大小
int Size(Stack* stack)
{
    return stack->Size;
}
//获取栈顶元素
int Peek(Stack* stack)
{
    if(IfEmpty(stack)){
        printf("Stack is empty.\n");
        exit(1);
    }
    return stack->Top->data;
}
*/

/*用数组实现*/
#define MAX_SIZE 100

typedef struct Stack
{
    int item[MAX_SIZE];
    int top;
}Stack;
//初始化栈
void InitStack(Stack* stack)
{
    stack->top = -1;
}
//检查栈是否为空
int IfEmpty(Stack* stack)
{
    return stack->top == -1;
}
//检查栈是否满了
int IfFull(Stack* stack)
{
    return stack->top == MAX_SIZE - 1;
}
//入栈
void Push(Stack* stack , int element)
{
    if(IfFull(&stack)){
        printf("Stack overflow.\n");
        exit(1);
    }
    stack->top++;
    stack->item[stack->top] = element;
}
//出栈
int Pop(Stack* stack)
{
    if(IfEmpty(stack)){
        printf("Stack is empty.\n");
        exit(1);
    }
    return stack->item[stack->top--];
}
//获取栈的当前大小
int Size(Stack* stack)
{
    return stack->top+1;
}
//获取栈顶元素
int Peek(Stack* stack)
{
    if(IfEmpty(stack)) {
        printf("Stack is empty.\n");
        exit(1);
    }
    return stack->item[stack->top];
}

int main() {
    Stack stack;
    InitStack(&stack);
    Push(&stack , 10);
    Push(&stack , 20);
    printf("%d\n" , Peek(&stack));
    printf("%d\n" , Size(&stack));
    Pop(&stack);
    printf("%d\n" , Peek(&stack));
    printf("%d\n" , Size(&stack));
    printf("%d\n" , IfEmpty(&stack));
    return 0;
}
