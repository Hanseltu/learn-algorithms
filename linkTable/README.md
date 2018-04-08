## 链表

* 单链表

* 双链表

#### 单链表的基本操作

* 结构体定义
```c
typedef struct Node{
        ElemType data; //数据域
        struct Node* next; //指针域
    }Node;
```

* **头插法**建立单链表
```c
node->data = &data;
node->next = list->next;
list->next = node;
```

* **尾插法**建立单链表
```c
node->data = &data;
while(p->next)  //将指针移到最后一个结点
{
    p = p->next;
}
node->next = NULL;
p-next = node;
```

* **插入**数据到指定位置
```c
while(i < pos-1 && p) //将指针移动到第pos-1个结点位置
{
    p = p->next;
    i++;
}
newNode->data = e;
newNode->next = p->next;
p->next = newNode;
```

* **删除**第pos个结点
```c
while(p && i < pos-1) //将指针移动到第pos-1个结点位置
{
    p = p->next;
    i++;
}
q = p->next;
*e = q->data;
p->next = q->next;
free(q);
```

### 双链表的基本操作

* 结构体定义
```c
typedef struct DNode{
    Elemtype data;
    DNode* struct prior;
    DNode* struct next;
    }Node,*DLinkListPtr;
```

 * **建立**双链表
 ```c
p->next = node;
node->prior = p;
p = p->next;
 ```





