#if !defined(STACK_H)
#define STACK_H
#define MAX_LIM_STACK_SIZE 100

#include "bst.h"
#include <stdbool.h>

typedef struct stack Stack;

Stack *create_stack(void);

Tree *pop(Stack *s);

void push(Stack *s, Tree *t);

bool stack_is_empty(Stack *s);

void destroy_stack(Stack *s);

#endif // STACK_H
