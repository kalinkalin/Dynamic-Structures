#include "BSTree.h"
#include <iostream>

BSTree::~BSTree(){
  delete root;
}
BSTree::Node::~Node(){
  delete left;
  delete right;
}

void BSTree::insert(string key){
  elements++;
  inserts++;
  Node* newNode = new Node();
  newNode->value = key;
  newNode->left = NULL;
  newNode->right = NULL;
  Node* current = root;
  Node* parent = NULL;

  while(current != NULL){
    parent = current;

    if(key > current->value){
      current = current->right;
    }
    else{
      current = current->left;
    }
  }
  newNode->parent = parent;

  if(parent == NULL){
    root = newNode;
  }

  else {
    if(newNode->value > parent->value){
      parent->right = newNode;
    }
    else{
      parent->left = newNode;
    }
  }
}

void BSTree::deleteNode(string value){
  removals++;
  Node* delNode = findNode(value);
  if(delNode ==NULL){
    return;
  }
  elements--;
  Node* toDelete = NULL;
  Node* repNode = NULL;

  if(delNode->left == NULL || delNode->right == NULL){
    toDelete = delNode;
  }
  else{
    toDelete = nodeSuccessor(value);
  }
  if(toDelete->left != NULL){
    repNode = toDelete->left;
  }
  else{
    repNode = toDelete->right;
  }
  if(repNode != NULL){
    repNode->parent = toDelete->parent;
  }
  if(toDelete->parent == NULL){
    root = repNode;
  }
  else if(toDelete == toDelete->parent->left){
    toDelete->parent->left = repNode;
  }
  else{
    toDelete->parent->right = repNode;
  }
  if(delNode != toDelete){
  delNode->value = toDelete->value;
  }
  toDelete->left = NULL;
  toDelete->right = NULL;

  delete toDelete;
}

void BSTree::inorderWalk(){
  inorderWalk(root);
}

void BSTree::inorderWalk(Node* node){
  if(node != NULL){
    inorderWalk(node->left);
    cout << "\033[34m" << node->value << "\033[0m"<< endl;
    inorderWalk(node->right);
  }
}

string BSTree::min(){
  Node* node = root;

  while(node->left !=NULL){
    node=node->left;
  }
  return node->value;
}

string BSTree::max(){
  Node* node = root;

  while(node->right !=NULL){
    node=node->right;
  }
  return node->value;
}

BSTree::Node* BSTree::findNode(string value){
  Node* node = root;

  while(node != NULL){
    if(value == node->value){
      return node;
    }
    else if(value > node->value){
      node = node->right;
    }
    else{
      node = node->left;
    }
  }
  return node;
}
bool BSTree::find(string value){
  Node* node = root;

  while(node != NULL){
    findComparisions++;
    if(value == node->value){
      break;
    }
    else if(value > node->value && findComparisions++){
      node = node->right;
    }
    else{
      node = node->left;
    }
  }
  if(node == NULL){
    return false;
  }
  else{
    return true;
  }
}
BSTree::Node* BSTree::nodeSuccessor(string value){
  Node* successor = NULL;
  Node* node = findNode(value);

  if(node != NULL){
    if(node->right != NULL){
      successor = node->right;

      while(successor->left != NULL){
        successor = successor->left;
      }
    }
    else{
      successor = node->parent;
      while(successor != NULL && successor->right == node){
        node = successor;
        successor = successor->parent;
      }
    }
  }
  return successor;
}

string BSTree::successor(string value){
  return nodeSuccessor(value)->value;
}
