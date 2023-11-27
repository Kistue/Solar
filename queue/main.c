#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
/*
//定义链表节点
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
//定义队列结构
typedef struct Queue
{
    Node* front;
    Node* rear;
}Queue;
//初始化队列
void InitQueue(Queue* queue)
{
    queue->front = queue->rear = NULL;
}
//检查队列是否空
int IfEmpty(Queue* queue)
{
    return queue->front == NULL;
}
//入队操作
void Enqueue(Queue* queue , int element)
{
    Node* newNode = (Node*)malloc(sizeof (Node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->next = NULL;
    newNode->data = element;
    if(queue->rear == NULL){
        queue->front = newNode;
        queue->rear = newNode;
    } else{
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
//出队操作
int Dequeue(Queue* queue)
{
    if(IfEmpty(queue)){
        printf("Queue is empty.\n");
        exit(1);
    }
    int data = queue->front->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}
//获取队首元素
int Front(Queue* queue)
{
    if(IfEmpty(queue)){
        printf("Queue is empty.\n");
        exit(1);
    }
    return queue->front->data;
}
*/


/*用数组实现*/
/*
#define MAX_SIZE 100

typedef struct Queue
{
    int queue[MAX_SIZE];
    int front;
    int rear;
}Queue;

//初始化队列
void Initqueue(Queue* queue){
    queue->front = -1;
    queue->rear = -1;
}
//检查是否为空
int Ifempty(Queue* queue){
    return queue->front == -1;
}
//检查是否满
int Iffull(Queue* queue){
    return queue->rear == MAX_SIZE - 1;
}
//入队
void Enqueue(Queue* queue , int element){
    if(Iffull(queue)){
        printf("Queue is full.\n");
        exit(1);
    }
    if (Ifempty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->queue[queue->rear] = element;
}
//出队
int Dequeue(Queue* queue){
    if(Ifempty(queue)){
        printf("Queue is empty.\n");
        exit(1);
    }
    int data = queue->queue[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        // Reset the queue after last dequeue
        Initqueue(queue);
    }
    return data;
}
//获取队首元素
int Front(Queue* queue){
    if(Ifempty(queue)){
        printf("Queue is empty.\n");
        exit(1);
    }
    return queue->queue[queue->front];
}
*/
#define MAX_SIZE 10

typedef struct Queue
{
    int Array[MAX_SIZE];
    int front;
    int rear;
    int size;
}Queue;

void Initqueue(Queue* queue){
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}
int Ifempty(Queue* queue){
    return queue->size == 0;
}
int Iffull(Queue* queue){
    return queue->size == MAX_SIZE;
}
void Enqueue(Queue* queue , int element){
    if(Iffull(queue)){
        printf("Queue is full.\n");
        exit(1);
    }
        queue->Array[queue->rear] = element;
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->size++;
}
int Front(Queue* queue){
    if(Ifempty(queue)){
        printf("Queue is empty.\n");
        exit(1);
    }
    return queue->Array[queue->front];
}
int Dequeue(Queue* queue){
    if(Ifempty(queue)){
        printf("Queue is empty.\n");
        exit(1);
    }
    int data = queue->Array[queue->front];
    queue->size--;
    queue->front = (queue->front + 1) % MAX_SIZE;
    return data;
}
void Printqueue(Queue* queue){
    if(Ifempty(queue)){
        printf("Queue is empty.\n");
        exit(1);
    }
    int i = queue->front;
    do{
        printf("%d " , queue->Array[i]);
        i = (i + 1)%MAX_SIZE;
    } while (i != queue->rear );
    printf("\n");
}

int main() {
    Queue queue;
    Initqueue(&queue);
    printf("%d\n", Ifempty(&queue));
    //Enqueue(&queue , 1);
    Enqueue(&queue , 3);
    Enqueue(&queue , 5);
    Printqueue(&queue);
    printf("%d\n", Front(&queue));
    Dequeue(&queue);
    printf("%d\n", Front(&queue));
    Dequeue(&queue);
    printf("%d\n", Front(&queue));

    return 0;
}
