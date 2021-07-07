#include "bst.h"

// int main(int argc, char const *argv[]) //exercise 1 e 2
// {
//   int r, N = 3;
//   // scanf("%d", &N);

//   Tree *t = create_empty_tree();

//   srand(time(NULL));

//   for (unsigned i = 0; i < N; i++)
//   {
//     r = rand();
//     t = insert_tree(t, r);
//   }
//   // print_tree(t);
//   printf("|Height: %d|\n", tree_height(t));
//   destroy_tree(t);
//   return 0;
// }

void line(void)
{
  printf("\n\n--------------\n");
}

// int main(int argc, char const *argv[]) //exercise 3
// {

//   Tree *t = create_empty_tree();

//   t = insert_tree(t, 5);
//   t = insert_tree(t, 4);
//   t = insert_tree(t, 3);
//   t = insert_tree(t, 2);
//   t = insert_tree(t, 1);
//   t = insert_tree(t, 9);
//   t = insert_tree(t, 8);
//   t = insert_tree(t, 7);
//   t = insert_tree(t, 6);

//   print_preorder(t);
//   line();

//   print_inorder(t);
//   line();

//   print_posorder(t);
//   line();

//   destroy_tree(t);
//   return 0;
// }
