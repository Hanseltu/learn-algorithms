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
    DLinkListPtr p = head;

    for (int i = 0;i < n;i++)
    {
        DLinkListPtr node = (DLinkListPtr)malloc(sizeof(DNode));
        node->prior = NULL;
        node->next = NULL;
        node->data = i;

        /* 修改指针 */
        p->next = node;
        node->prior = p;
        p = p->next;
    }
    return head;
}

/* 插入数据到第pos个位置 */
DLinkListPtr insert_dlist(DLinkListPtr dlist,Elemtype data,int pos){
    /* 新建数据域为data的结点 */
    DLinkListPtr temp = (DLinkListPtr)malloc(sizeof(DNode));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;

    /* 特殊情况：插入到链表头 */
    if(pos == 1)
    {
        temp->next = dlist;
        dlist->prior = temp;
        dlist = temp;
    }
    return dlist;
}
Status printDLink(DLinkListPtr dlist){
    DLinkListPtr p = dlist;
    p = dlist->next;
    while (p)
    {
        printf("%d \t",p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}
int main(){
    DLinkListPtr list = creat_dlist(10);
    printDLink(list);
    return 0;
}



