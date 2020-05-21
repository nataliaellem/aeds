#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
  struct tree *left;
  struct tree *right;
  int data;
} Tree;

Tree* new_node(int value){
    Tree *node = (Tree*) malloc (sizeof(Tree));
    node->left = (Tree*) NULL;
    node->right = (Tree*) NULL;
    node->data = value;
    return node;
}

void main(){
  int array[7] = {1,2,3,4,5,6,7};
  Tree *root = new_node(array[0]);
  root->left = new_node(array[1]);
  root->left->left = new_node(array[2]);
  root->left->right = new_node(array[3]);
  root->right = new_node(array[4]);
  root->right->left = new_node(array[5]);
  root->right->right = new_node(array[6]);  
}
