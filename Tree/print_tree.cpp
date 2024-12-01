#include <iostream>

struct Node {
  Node* left;
  Node* right;
  int value;
};

bool has_value(Node *root, int value){

  if (root == nullptr){
    
    }
    
   has_value(root->left, value);
   has_value(root->right, value);
}

void print_tree(Node* root) {
  if (root == nullptr) {return;}
  
  print_tree(root->left);
  std::cout<<root->value;
  print_tree(root->right);
  }

int main () {
  Node* root = new Node{nullptr, nullptr, 4};
  root->left = new Node{nullptr, nullptr, 2};
  root->left->left = new Node{nullptr, nullptr, 1};
  root->left->right = new Node{nullptr, nullptr, 3};
  root->right = new Node{nullptr, nullptr, 6};
  root->right->left = new Node{nullptr, nullptr, 5};
  root->right->right = new Node{nullptr, nullptr, 7};

  print_tree(root);
  std:: cout << std::endl;

  std::cout << has_value(root, 1) << std::endl; // 1
  std::cout << has_value(root, 2) << std::endl; // 1
  std::cout << has_value(root, 3) << std::endl; // 1
  std::cout << has_value(root, 4) << std::endl; // 1
  std::cout << has_value(root, 5) << std::endl; // 1
  std::cout << has_value(root, 6) << std::endl; // 1
  std::cout << has_value(root, 7) << std::endl; // 1
  std::cout << has_value(root, 42) << std::endl; // 0
}