### 链表

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

* **头插法**建立单链表(关键步骤)
```c
node->data = &data;
node->next = list->next;
list->next = node;
```

