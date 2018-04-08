#include<stdio.h>
#include<stdlib.h>

/* 双链表结点组成 */
typedef struct DNode{
    int data;
    struct DNode* prior;
    struct DNode* next;
}DNode,*DLinkListPtr;

typedef int Status;
typedef int Elemtype;

/* 新建双链表 */
DLinkListPtr creat_dlist(int n){
    DLinkListPtr head = (DLinkListPtr)malloc(sizeof(DNode));
    head->prior = NULL;
    head->next = NULL;
    head->data = n;

    return head;
}



