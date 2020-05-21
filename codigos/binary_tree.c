#include <stdio.h>
#include <stdlib.h>

// Node
typedef struct node {
  struct node *left;
  struct node *right;
  int data;
} Node;

Node* new_node(int value) {
  Node *node = (Node*) malloc (sizeof(Node));
  node->left = (Node*) NULL;
  node->right = (Node*) NULL;
  node->data = value;
  return node;
}

void print_tree_preorder(Node *node) {
  if (node != NULL) {
    printf("%d -> ", node->data);         // Lê
    print_tree_preorder(node->left);    // Esquerda
    print_tree_preorder(node->right);   // Direita
  }
}

void print_tree_inorder(Node *node) {
  if (node != NULL) {
    print_tree_inorder(node->left);
    printf("%d -> ", node->data);
    print_tree_inorder(node->right);
  }
}

void print_tree_postorder(Node *node) {
  if (node != NULL) {
    print_tree_inorder(node->left);
    print_tree_inorder(node->right);
    printf("%d -> ", node->data);
  }
}

// Tree
typedef struct tree {
   Node *root;
} Tree;

Tree new_tree(int value) {
  Tree new_tree;
  new_tree.root = new_node(value);
  return new_tree;
}

void insert_inorder(Node *node, int value) {
  if (node != NULL) {
    if (value > node->data) {
      if (node->right != NULL) {
        insert_inorder(node->right, value);
      } else {
        node->right = new_node(value);
      }
    } else {
      if (node->left != NULL) {
        insert_inorder(node->left, value);
      } else {
        node->left = new_node(value);
      }
    }
  }
}

void main() {
  Tree tree = new_tree(5);

  insert_inorder(tree.root, 1);
  insert_inorder(tree.root, 7);
  insert_inorder(tree.root, 4);
  insert_inorder(tree.root, 3);
  insert_inorder(tree.root, 2);
  insert_inorder(tree.root, 6);

  print_tree_inorder(tree.root);
  printf("\n");
}
