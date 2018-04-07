### 链表

* 单链表

* 双链表

#### 单链表的基本操作

* 结构体定义
```
    typedef struct Node{
            ElemType data;
            struct Node* next;
        }Node;
```

* 头插法建立单链表 关键步骤
```
    node->data = &data;
    node->next = list->next;
    list->next = node;
```

