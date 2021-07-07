#include "bst.h"

struct tree
{
  Tree *left;
  Tree *right;
  int key;
};

Tree *create_empty_tree(void)
{
  return NULL;
}

Tree *insert_tree(Tree *t, int new_key)
{
  if (t == NULL)
  {
    t = (Tree *)malloc(sizeof(Tree));
    t->left = t->right = NULL;
    t->key = new_key;
  }
  else if (t->key > new_key)
    t->left = insert_tree(t->left, new_key);
  else
    t->right = insert_tree(t->right, new_key);

  return t;
}

void *print_tree(Tree *t)
{
  if (t != NULL)
  {
    print_tree(t->left);
    printf("%d ", t->key);
    print_tree(t->right);
  }
}

int tree_height(Tree *t)
{
  int u, v;
  if (t == NULL)
    return -1;

  u = tree_height(t->left);
  v = tree_height(t->right);

  if (u > v)
    return u + 1;
  else
    return v + 1;
}

void *destroy_tree(Tree *t)
{
  if (t != NULL)
  {
    destroy_tree(t->left);
    destroy_tree(t->right);
    free(t);
  }

  return NULL;
}

void print_preorder(Tree *t)
{
  if (t != NULL)
  {
    printf("%d ", t->key);
    print_preorder(t->left);
    print_preorder(t->right);
  }
}
void print_inorder(Tree *t)
{
  if (t != NULL)
  {
    print_inorder(t->left);
    printf("%d ", t->key);
    print_inorder(t->right);
  }
}
void print_posorder(Tree *t)
{
  if (t != NULL)
  {
    print_posorder(t->left);
    print_posorder(t->right);
    printf("%d ", t->key);
  }
}