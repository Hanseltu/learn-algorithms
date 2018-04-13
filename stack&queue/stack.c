#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct Stack{
	int capability;
	int sp;
	int *data;
};
typedef struct Stack *slink;

//建立栈
slink create_stack(int capability){
	slink stack=malloc(sizeof(struct Stack));
	if(!stack)
		return stack;
	stack->capability=capability;
	stack->sp=-1;
	stack->data=(int*)malloc(sizeof(int)*capability);
	return stack;
}


//判断栈空
int empty(slink stack){
	return stack->sp==-1;
}

//判断栈满
int full(slink stack){
	return stack->sp==stack->capability-1;
}

//入栈操作
void push_stack(slink stack,int item){
	stack->data[++stack->sp]=item;
}

//出栈操作
int pop_stack(slink stack){
	if(empty(stack))
		return -1;
	return stack->data[stack->sp--];
}

bool isValid(char* s) {
  initStack();
  int i = 0;
  while(s[i] != '\0'){
    switch(s[i]){
      case '(':push('(');
        break;
      case '[':push('[');
        break;
      case '{':push('{');
        break;
      case ')':
        e1 = pop();
        if (e1 != '(')
          return false;
        break;
      case ']':
	e2 = pop();
        if (e2 != '[')
          return false;
        break;
      case '}':
	e3 = pop();
        if(e3 != '{')
          return false;
      default:
        break;
    }
    i++;
    if (!isEmpty()){
      printf("Not ok!");
      return false;
    }
    else
    {
      printf("OK!");
      return true;
    }
  }
}




int main(){
	slink stack=create_stack(5);
	int data[]={1,2,3,4,5,6,7,8,9};
	int i=0;
	while(!full(stack))
		push_stack(stack,data[i++]);
	while(!empty(stack))
		printf("%d\n",pop_stack(stack) );
	while(i<9 && !full(stack))
		push_stack(stack,data[i++]);
	while(!empty(stack))
		printf("%d\n",pop_stack(stack) );
}

