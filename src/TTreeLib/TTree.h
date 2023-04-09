#pragma once
#include <algorithm>

template <class Key, class Data>
class TTree {
  
  class Node 
  {
  public:
    Key key;
    Data value;
    unsigned char height;
    Node* left;
    Node* right;
    Node(const Key&_key, const Data& _value): key(_key), value(_value), height(1), left(nullptr), right(nullptr) {}
  };
private:
  Node* root;
  size_t sz;

public:
  unsigned int height(Node* node) 
  {
    return (node != nullptr ? node->height : 0);
  }
  int balance_factor(Node* node) 
  {
    return (int)(height(node->right)) - (int)(height(node->left));
  }
  void fix_height(Node* node) 
  {
    node->height = std::max(height(node->left), height(node->right)) + 1;
  }

  Node* _RotateLeft(Node* node) 
  {
    Node* new_node = node->right;
    node->right = new_node->left;
    new_node->left = node;
    fix_height(node);
    fix_height(new_node);
    return new_node;
  }
  Node* _RotateRight(Node* node) 
  {
    Node* new_node = node->left;
    node->left = new_node->right;
    new_node->right = node;
    fix_height(node);
    fix_height(new_node);
    return new_node;
  }
  Node* balance(Node* node) 
  {
    fix_height(node);
    if (balance_factor(node) == 2) {
      if (balance_factor(node->right) < 0)
        node->right = _RotateRight(node->right);
      node = _RotateLeft(node);
    }
    if (balance_factor(node) == -2) {
      if (balance_factor(node->left) > 0)
        node->left = _RotateLeft(node->left);
      node = _RotateRight(node);
    }
    return node;
  }

  Node* findmin(Node* node) 
  {
    return node->left ? findmin(node->left) : node;
  }
  Node* removemin(Node* node) 
  {
    if (node->left == nullptr)
      return node->right;
    node->left = removemin(node->left);
    return balance(node);
  }

  Node* __Insert(Node* node, const Key& key, const Data& value, bool replacement) 
  {
    if (node == nullptr) {
      sz++;
      return new Node(key, value);
    }
    if (key < node->key)
      node->left = __Insert(node->left, key, value, replacement);
    else if (key > node->key)
      node->right = __Insert(node->right, key, value, replacement);
    else if (replacement) {
      node->value = value;
    }

    return balance(node);
  }
  Node* __Remove(Node* node, const Key& key)
  {
    if (node == nullptr)
      return nullptr;
    if (key < node->key)
      node->left = __Remove(node->left, key);
    else if (key > node->key)
      node->right = __Remove(node->right, key);
    else //  key == node->key
    {
      Node* left_node = node->left;
      Node* right_node = node->right;
      delete node;
      sz--;
      if (right_node == nullptr)
        return left_node;
      Node* min = findmin(right_node);
      min->right = removemin(right_node);
      min->left = left_node;
      return balance(min);
    }
    return balance(node);
  }
  Node* __Find(Node* node, const Key& key) 
  {
    if (node == nullptr)
      return nullptr;

    if (key < node->key)
      return __Find(node->left, key);
    if (key > node->key)
      return __Find(node->right, key);

    return node;
  }

  TAVLTree()
    : root(nullptr),
    sz(0) {
  }

  size_t size() const noexcept 
  {
    return sz;
  }
  bool empty() const noexcept 
  {
    return sz == 0;
  }

  void insert(const Key& key, const Data& value, bool replacement = false)
  {
    root = __Insert(root, key, value, replacement);
  }

  void remove(const Key& key) 
  {
    root = __Remove(root, key);
  }

  bool find(const Key& key) 
  {
    return __Find(root, key) != nullptr;
  }
  Data& at(const Key& key)
  {
    Node* place = __Find(root, key);
    if (place == nullptr)
      throw "No key in table";
    return place->value;
  }
};