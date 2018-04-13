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

/*
队列是一种先进先出的线性表，它只允许在表的一端进行插入，而在另一端删除元素。
在队列中，允许插入的一端叫队尾，允许删除的一端称为队头。
*/
/*
在队头--删除元素
在队尾--添加元素
就和排队一样
*/
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2


#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2


typedef int QElemType;
typedef int Status;

typedef struct QNode{
    QElemType  data;
    struct QNode  *next;
}QNode,*QueuePtr;


//该结构体维护一个队头指针和队尾指针
//指针指向队列的节点
typedef struct{
    QueuePtr front; //队头指针
    QueuePtr rear;  //队尾指针
 }LinkQueue;


//基本操作的函数原型说明
Status init_queue(LinkQueue *q); //构造一个空队列
Status destroy_queue(LinkQueue *q);
Status clear_queue(LinkQueue *q);
Status queue_empty(LinkQueue *q);
int queue_length(LinkQueue *q);
Status get_head(LinkQueue *q);
Status enter_queue(LinkQueue *q,QElemType e);
Status delete_queue(LinkQueue *q,QElemType *e);
Status display_queue(LinkQueue *q);

Status init_queue(LinkQueue *q){
    //构造一个空队列，队头指针和队尾指针指向头结点
    q-> front = q-> rear = (QueuePtr)malloc(sizeof(QNode));
    if(!q->front){
        exit(OVERFLOW);
    }
    q->front->next = NULL;
	return OK;
}

//销毁队列，队列不在存在
//从队列的队头开始销毁每一个节点
//先删除头结点，然后删除第一个节点，然后删除第二个节点，依次删除，直到删除队尾指针指向的节点
Status destroy_queue(LinkQueue *q){

    /*
    q->front指向头节点，q->front->next指向队列的第一个节点
    */
    while(q->front){
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
    return OK;
}

Status destroy_queue_2(LinkQueue *q){
    while(q->front){
        QueuePtr temp = q->front->next;
        free(q->front);
        q->front = temp;
    }
    return OK;
}

Status enter_queue(LinkQueue *q,QElemType e){
    //插入元素e为新的队尾元素
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(!p){
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
	return OK;
}

Status delete_queue(LinkQueue *q,QElemType *e){
    //若队列不为空，则删除队列的队头元素，用e表示返回其值，并返回OK
    if(q->front==q->rear){
        return ERROR;
    }
   QueuePtr p =  q->front->next; //要删除的队头元素
   *e = p->data;   //要删除的队头元素
   q->front->next = p->next; //让头指针指向要删除节点的下一个节点
   if(q->rear==p){  //如果要删除的元素是队尾元素，则队列为空
      q->rear = q->front;
   }
   free(p);
   return OK;
}

Status display_queue(LinkQueue *q){
	if(q->front==NULL){
		printf("queue is not exist\n");
	}else if(q->front==q->rear){
        printf("queue is empty\n");
    }else {
        //这种方法最后会使q->front=q->rear
        QueuePtr temp=NULL;
        while(temp!=q->rear){
            temp = q->front->next;
            printf("%d\n",temp->data);
            q->front = temp;
        }
    }
	return OK;
}

Status display_queue_2(LinkQueue *q){

    if(q->front==NULL){
		printf("queue is not exist\n");
	}else if(q->front==q->rear){
        printf("queue is empty\n");
    }else {
        //这就是链表的遍历
        QNode *p;
        p=q->front->next;
        while (p)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
	return OK;
}

int main(){
    LinkQueue q;
    printf("====构造一个空队列\n");
    init_queue(&q);
    printf("====构造空队列结束\n");
    int i,n;
    printf("输入队列的元素的个数n\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        //元素进入队列
        enter_queue(&q,i);
    }
	printf("打印输出队列\n");
    display_queue_2(&q);
    printf("删除队头元素\n");
	QElemType e;
	delete_queue(&q,&e);
	printf("删除的元素为%d\n",e);
	//system("pause");
	printf("销毁队列\n");
	printf("再次打印输出队列\n");
	display_queue_2(&q);
	destroy_queue_2(&q);
	printf("再次打印输出队列\n");
	display_queue_2(&q);
	//system("pause");
    return 0;
}
