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
    else
    {
        DLinkListPtr p = dlist;

        /* 找到要插入位置的前一个结点 */
        for(int i = 0;i < pos - 1;i++)
        {
            p = p->next;
        }
        if (p->next == NULL) /* 如果插入的位置在最后一个结点 */
        {
            p->next = temp;
            temp->prior = p;
        }
        else /* 插入的位置是中间结点 */
        {
            p->next->prior = temp;
            temp->next = p->next;
            temp->prior = p;
            p->next = temp;
        }
    }
    return dlist;
}

/* 删除结点（特定数值的结点） */
DLinkListPtr deleteBydata(DLinkListPtr dlist,Elemtype data){
    DLinkListPtr p = dlist;
    while(p)
    {
        if (p->data == data)
        {
            p->prior->next = p->next;
            p->next->prior = p->prior;
            free(p);
            return dlist;
        }
        p = p->next;
    }
    printf("There is no data in the list which data is %d \n",data);
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
    DLinkListPtr list2 = insert_dlist(list,11,10);
    printDLink(list2);
    printf("-----------------------insert----------------------\n");
    DLinkListPtr list3 = deleteBydata(list,11);
    printDLink(list3);
    return 0;
}



