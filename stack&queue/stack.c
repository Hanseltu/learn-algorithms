#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
/*
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



Status InitStack(SqStack* S){
    S->base = (int*)malloc(sizeof(ElemType)*STACK_INIT_SIZE);
    if (!S->base)
    {
        exit(OVERFLOW);
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}


Status DestroyStack(SqStack *S){
    S->top = NULL;
    S->stacksize = 0;
    free (S->base);
    return OK;
}

Status ClearStack(SqStack *S){
    S->top = S->base;
    return OK;
}


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

*/

#define STACK_SIZE 20
typedef struct stack{
    int top;
    int array[STACK_SIZE];
}STACK;

STACK S;

// init
int initStack(){
    S.top = 0;
    return 0;
}

// isEmpty
bool isEmpty(){
    if(0 == S.top)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// isFull
bool isFull(){
    if(STACK_SIZE == S.top)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// push
int push(int e){
    if(isFull())
    {
        printf("stack overflow! stop push element\n");
        return -1;
    }
    else
    {
        S.top++;
        S.array[S.top-1] = e;
        return S.top;
    }
}

// pop
int pop(){
    if (isEmpty())
    {
        printf("stack empty! pop null\n");
    }
    else
    {
        S.top--;
        return S.array[S.top+1];
    }
    return 0;
}

// clear
void clear(){
    while(!isEmpty())
    {
        pop();
    }
}

// printAll
void printAll(){
    if(isEmpty())
    {
        printf("empty stack! print nothing");
    }
    int i = 0;
    for(i=0; i< S.top; i++)
    {
        printf("%d  ", S.array[i]);
    }
    printf("\n");
}

// getLength
int getLength(){
    return S.top;
}


int main(void){

    initStack();

    int i = 0;
    for (i = 0; i < 10; i++) {
        int ret = push(i);
        if(-1 == ret)
            break;
    }

    printAll();

    pop();

    printAll();

    for (i = 11; i < 30; i++) {
        int ret = push(i);
        if(-1 == ret)
            break;
    }

    printAll();

    printf("getLength: %d\n", getLength());

    printf("clear all\n");
    clear();

    printf("getLength: %d\n", getLength());
    printAll();

    return 0;
}
