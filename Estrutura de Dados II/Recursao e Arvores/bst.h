#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tree Tree;

Tree *create_empty_tree(void);

Tree *insert_tree(Tree *t, int new_key);

void *destroy_tree(Tree *t);

void *print_tree(Tree *t);

int tree_height(Tree *t);

void print_preorder(Tree *t);

void print_inorder(Tree *t);

void print_posorder(Tree *t);

#endif /*BST_H*/
