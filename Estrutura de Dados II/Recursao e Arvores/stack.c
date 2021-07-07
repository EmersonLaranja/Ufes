#include "stack.h"

struct stack
{
  int top;
  Tree *node[MAX_LIM_STACK_SIZE];
};

Stack *create_stack(void)
{
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->top = 0;
  return s;
};

Tree *pop(Stack *s){

};

void push(Stack *s, Tree *t){

};

bool stack_is_empty(Stack *s){

};

void destroy_stack(Stack *s){

};