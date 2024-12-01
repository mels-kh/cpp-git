#include <fstream>
#include <iostream>

struct Node {
  Node *left;
  Node *right;
  int value;
};

class BST {
  Node *root;

public:
  struct Iterator;

  BST(){};
  void push(int value) {
    Node *current = root;
    while (current) {
      if (current->value > value) {
        if (!current->right) {
          current->right = new Node{nullptr, nullptr, value};
          break;
        } else {
          current = current->right;
        }
      } else {
        if (!current->left) {
          current->left = new Node{nullptr, nullptr, value};
          break;
        } else {
          current = current->left;
        }
      }
    }
  }

  void clear(Node* node) {
    if(node == nullptr) {
      return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
  }
  Iterator begin() {
    Node* current;
    while(current && current->left) {
      current = current->left;
    }
    return Iterator{current};
  }

  struct Iterator {
  
    Node* node;
    Iterator& operator++() {
      if (node->right) {
        node = node->right;
        while(node && node->left) {
          node = node->left;
        }
      }
      else {
        
      }
      return *this;
    }
  };

  ~BST() { clear(root); root = nullptr;}
};

template <typename Func> void for_each(Node *root, Func function) {
  if (root == nullptr)
    return;
  for_each(root->left, function);
  function(root->value);
  for_each(root->right, function);
}

int main() {
  Node *root = new Node{nullptr, nullptr, 4};
  root->left = new Node{nullptr, nullptr, 2};
  root->left->left = new Node{nullptr, nullptr, 1};
  root->left->right = new Node{nullptr, nullptr, 3};
  root->right = new Node{nullptr, nullptr, 6};
  root->right->left = new Node{nullptr, nullptr, 5};
  root->right->right = new Node{nullptr, nullptr, 7};

  auto print = [](auto val) { std::cout << val << ' '; };
  for_each(root, print);
  std::cout << std::endl;

  // вывод дерева в файл
  std::ofstream out{"out.txt"};
  for_each(root, [&out](auto val) { out << val << ' '; });
}