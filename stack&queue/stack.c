#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

#define STACK_INIT_SIZE 10
#define STACKINCREMENT 2
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct SqStack{
    int* base;
    int* top;
    int stacksize;
}SqStack;

/* 顺序栈的9个基本操作 */

/* 1.构建一个空栈 */
Status InitStack(SqStack* S){
    S->base = (int*)malloc(sizeof(ElemType)*STACK_INIT_SIZE);
    if (!S->base)
    {
        exit(OVERFLOW);  /* 存储分配失败 */
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

/* 2.销毁栈 */
Status DestroyStack(SqStack *S){
    S->top = NULL;
    S->stacksize = 0;
    free (S->base);
    return OK;
}

/* 3.清空栈 */
Status ClearStack(SqStack *S){
    S->top = S->base;
    return OK;
}

/* 4.判断栈是否为空，非空返回1 */
Status StackEmpty(SqStack *S){
    if (S->top == S->base)
    {
        return ERROR;
    }
    else
    {
        return TRUE;
    }
}

/* 5.求栈的长度*/
Status StackLength(SqStack *S){
    if(S->top == S->base)
    {
        return FALSE;
    }
    else
    {
        return (S->top - S->base);
    }
}

/* 6.求栈顶元素 */
Status GetTop(SqStack *S, ElemType e){
    if (S->top == S->base)
    {
        return FALSE;
    }
    else
    {
        e = *(S->top - 1);
    }
    return e;
}

/* 7.栈顶插入元素 */
Status Push(SqStack *S,ElemType e){
    if (S->top - S->base >= STACK_INIT_SIZE)
    {
        S->base = (ElemType*)realloc(S->base,(S->stacksize + STACKINCREMENT)*sizeof(ElemType));
        if (!S->base)
        {
            return FALSE;
        }
        S->top = S->base + STACK_INIT_SIZE;
        S->stacksize = S->stacksize + STACKINCREMENT;
    }
    *S->top = e;
    S->top ++;
    return OK;
}


/* 8.删除栈顶元素 */
Status Pop(SqStack *S,ElemType e){
    if (S->top == S->base)
    {
        return FALSE;
    }
    else
    {
        S->top --;
        e = *S->top;
        return e;
    }
}

/* 9.遍历栈 */
Status StackTraverse(SqStack *S){
    if (S->base == NULL)
    {
        return ERROR;
    }
    if (S->top == S->base)
    {
        printf("There are no more elements in the stack");
    }
    ElemType *p;
    p = S->top;
    while (p > S->base)
    {
        p --;
        printf("%d \n",*p);
    }
    return OK;
}



int main(){
    SqStack* S = NULL;
    InitStack(S);
    for (int i = 0; i < 5; i ++)
    {
        Push(S,i);
    }
    printf ("----------------");
    StackTraverse(S);
    return OK;
}
