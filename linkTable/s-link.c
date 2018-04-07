#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define OK 1;
#define ERROR 0;

typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node* next;
}Node,LinkList,*LinkListPtr;

/* 头插法建立单链表 */
LinkListPtr creat_head(int n){
    LinkListPtr list,node;
    //ElemType data;
    int i;

    list = (LinkListPtr)malloc(sizeof(Node));
    list->next = NULL;
    //printf("Please input the number of the single linktable: \n");
    for (i = 0; i < n; i++)
    {
        int a[] = {1,2,3,4,5,6,7,8,9};
        node = (LinkListPtr)malloc(sizeof(Node));
        //scanf("%d",&data);
        node->data = a[i];   /* 关键步骤 */
        node->next = list->next;
        list->next = node;
    }
    return list;
}

/* 尾插法建立单链表 */
LinkListPtr creat_tail(int n){
    LinkListPtr list,node,p;
    //ElemType data;
    int i;

    list = (LinkListPtr)malloc(sizeof(Node));
    list->next = NULL;
    p = list;
    //printf("Please input the number of the single linktable: \n");
    for (i = 0; i < n;i++)
    {
        node = (LinkListPtr)malloc(sizeof(Node));
        //scanf("%d",&data);
        int a[] = {1,2,3,4,5,6,7,8,9,10};
        node->data = a[i];  /* 关键步骤 */
        while(p->next) /* 指针移到最后一个结点 */
        {
            p = p->next;
        }
        node->next = NULL;
        p->next = node;
    }
    return list;
}


Status printLinkList(LinkListPtr list){
    LinkListPtr p;
    p = list->next;
    while (p)
    {
        printf("%d \t",p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}
int main(){
    LinkListPtr list = creat_tail(10);
    //LinkListPtr list = creat_head(10);
    printLinkList(list);
    return 0;
}
