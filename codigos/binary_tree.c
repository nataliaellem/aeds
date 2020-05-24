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
    print_tree_postorder(node->left);
    print_tree_postorder(node->right);
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

void insert_postorder(Node *node, int value){
  if (node != NULL) {
    if (value <= node->data) {
      if (node->left == NULL) {
        node->left = new_node(value);
      }
      else if (node->left != NULL && node->right == NULL) {
        if (value > node->left->data){
          node->right = new_node(value);
        }
        else {
          int aux = node->left->data;
          node->left->data = value;
          node->right = new_node(aux);
        }

      }
      else if (node->left != NULL && node->right != NULL) {
        if (value > node->right->data) {
          int aux2 = node->right->data;
          node->right->data = value;
          insert_postorder(node->right, aux2);
          print_tree_postorder(node->right);
          printf("\n");
        } else if (value < node->left->data){
          insert_postorder(node->left, value);
        } else if (value > node->left->data && value < node->right->data){
          insert_postorder(node->right, value);
        }
      }
    } else if (value > node->data) {
      int aux = node->data;
      node->data = value;
      insert_postorder(node, aux);
    }
  }
}

void main() {
  Tree tree = new_tree(2);
  insert_postorder(tree.root, 7);
  insert_postorder(tree.root, 4);
  insert_postorder(tree.root, 3);
  insert_postorder(tree.root, 1);
  insert_postorder(tree.root, 6);
  insert_postorder(tree.root, 5);
  print_tree_postorder(tree.root);
  printf("\n");
}
