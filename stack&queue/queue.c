#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


/****************** 队列的顺序存储（数组实现）*******************/

#define MaxSize 50

typedef struct {
    int data[MaxSize];
    int front,rear;
}SqQueue;
SqQueue q;
//初始化
int initQueue(){
    q.front = q.rear = 0;
    return 0;
}

//判队空
bool isEmpty(SqQueue q){
    if (q.rear == q.front)
    {
        return true;
    }
    else
        return false;
}

//入队
bool enQueue(SqQueue q,int x){
    if ((q.rear+1)%MaxSize == q.front) //队满
    {
        return false;
    }
    q.data[q.rear] = x;
    q.rear = (q.rear+1)%MaxSize;
    return true;
}

//出队
int deQueue(SqQueue q){  //返回出队的值
    int e;
    if(q.rear == q.front)
    {
        return false;
    }
    e = q.data[q.front];
    q.front = (q.rear+1)%MaxSize;
    return e;
}


/****************** 队的链式存储（链式存储）**************************/

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;



//初始化
void InitQueue(LinkQueue *Q){
    LinkNode *p =(LinkNode*)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
}

//判队空
bool IsEmpty(LinkQueue* Q){
    if(Q->front == Q->rear)
        return true;
    else
        return false;
}


//入队
void EnQueue(int x){
    LinkQueue *Q = NULL;
    LinkNode *s = NULL;
    s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL; //新建一个结点

    s->next = Q->rear->next;
    Q->rear->next = s;
    Q->rear=s;
}

//出队
int DeQueue(LinkQueue *Q){
    int e;
    if(Q->front == Q->rear)
    {
        return false;
    }
    LinkNode *p = Q->front->next;
    e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p)
    {
        Q->rear = Q->front;
    }
    free(p);
    return true;
}

int main(){
    LinkQueue *Q = NULL;
    InitQueue(Q);
    for (int i = 0; i < 10; i++)
    {
        EnQueue(i);
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d\n",DeQueue(Q));
    }
    return 0;
}
