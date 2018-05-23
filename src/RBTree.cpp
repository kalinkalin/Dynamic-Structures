#include <iostream>
#include "RBTree.h"
using namespace std;

RBTree::Node* RBTree::NIL = new Node();

RBTree::RBTree(){
  NIL->nodeColor=black;
  NIL->right = NIL;
  NIL->left = NIL;
  NIL->parent = NIL;

  root=NIL;
  root->parent=NIL;
}

RBTree::~RBTree(){
  delete root;
}
RBTree::Node::~Node(){
  if(left != NIL)
    delete left;
  if(right != NIL)
    delete right;
}

void RBTree::deleteNode(string value){
  removals++;
  Node* delNode = findNode(value);
  if(delNode ==NIL){
    return;
  }
  elements--;
  Node* toDelete = NIL;
  Node* repNode = NIL;

  if(delNode->left == NIL || delNode->right == NIL){
    toDelete = delNode;
  }
  else{
    toDelete = nodeSuccessor(value);
  }
  if(toDelete->left != NIL){
    repNode = toDelete->left;
  }
  else{
    repNode = toDelete->right;
  }
  repNode->parent = toDelete->parent;

  if(toDelete->parent == NIL){
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
  if(toDelete->nodeColor==black){
    delete_fixup(repNode);
  }
  toDelete->left = NULL;
  toDelete->right = NULL;
  delete toDelete;
}
void RBTree::delete_fixup(Node* node){
  Node* temp = NIL;

  while(node!=root && node->nodeColor == black){

    if(node->parent->left == node){
      temp = node->parent->right;

      if(temp->nodeColor == red){
        temp->nodeColor = black;
        node->parent->nodeColor = black;
        left_rotate(node->parent);
        temp = node->parent->right;
      }
      if(temp->left->nodeColor == black && temp->right->nodeColor == black){
        temp->nodeColor = red;
        node = node->parent;
      }
      else{
        if(temp->right->nodeColor==black){
          temp->left->nodeColor = black;
          temp->nodeColor = red;
          right_rotate(temp);
          temp = node->parent->right;
        }
        temp->nodeColor = node->parent->nodeColor;
        node->parent->nodeColor = black;
        temp->right->nodeColor = black;
        left_rotate(node->parent);
        node = root;
      }
    }
    else{ // node->parent->right = node
      temp = node->parent->left;

      if(temp->nodeColor == red){
        temp->nodeColor = black;
        node->parent->nodeColor = black;
        right_rotate(node->parent);
        temp = node->parent->left;
      }
      if(temp->right->nodeColor == black && temp->left->nodeColor == black){
        temp->nodeColor = red;
        node = node->parent;
      }
      else{
        if(temp->left->nodeColor==black){
          temp->right->nodeColor = black;
          temp->nodeColor=red;
          left_rotate(temp);
          temp = node->parent->left;
        }
        temp->nodeColor = node->parent->nodeColor;
        node->parent->nodeColor = black;
        temp->left->nodeColor = black;
        right_rotate(node->parent);
        node = root;
      }
    }
  }
}

void RBTree::insert(string value){
  elements++;
  inserts++;
  Node* newNode = new Node();
  newNode->value = value;
  newNode->left = NIL;
  newNode->right = NIL;
  newNode->nodeColor = red;
  bst_insert(newNode);

  Node* pointer = newNode;
  Node* temp = NIL;

while(pointer != root && pointer->parent->nodeColor==red){
    if(pointer->parent == pointer->parent->parent->left){
        temp = pointer->parent->parent->right;
        if(temp->nodeColor == red){
          pointer->parent->nodeColor = black;
          temp->nodeColor = black;
          pointer->parent->parent->nodeColor = red;
          pointer = pointer->parent->parent;
        }
        else{
          if(pointer == pointer->parent->right){
            pointer = pointer->parent;
            left_rotate(pointer);
        }
          pointer->parent->nodeColor = black;
          pointer->parent->parent->nodeColor = red;
          right_rotate(pointer->parent->parent);
        }

    }
    else{  // if pointer->parent = pointer->parent->parent->right
        temp=pointer->parent->parent->left;

        if(temp->nodeColor==red){
          pointer->parent->nodeColor = black;
          temp->nodeColor=black;
          pointer->parent->parent->nodeColor = red;
          pointer=pointer->parent->parent;
        }
        else{
          if(pointer == pointer->parent->left){
            pointer=pointer->parent;
            right_rotate(pointer);
          }
          pointer->parent->nodeColor = black;
          pointer->parent->parent->nodeColor = red;
          left_rotate(pointer->parent->parent);
        }
    }
  }
  root->nodeColor=black;
}
void RBTree::bst_insert(Node* newNode){
  Node* current = root;
  Node* parent = NIL;

  while(current != NIL){
    parent = current;

    if(newNode->value > current->value){
      current = current->right;
    }
    else{
      current = current->left;
    }
  }
  newNode->parent = parent;

  if(parent == NIL){
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

void RBTree::left_rotate(Node* node){
  Node* rNode = node->right;
  node->right = rNode->left;

  if(rNode->left != NIL){
    rNode->left->parent = node;
  }
  rNode->parent = node->parent;
  if(node->parent == NIL){
    root = rNode;
  }
  else if(node->parent->left == node){
    node->parent->left = rNode;
  }
  else{
    node->parent->right = rNode;
  }
  rNode->left = node;
  node->parent = rNode;
}

void RBTree::right_rotate(Node* node){
  Node* rNode = node->left;
  node->left = rNode->right;

  if(rNode->right != NIL){
    rNode->right->parent = node;
  }
  rNode->parent = node->parent;
  if(node->parent == NIL){
    root = rNode;
  }
  else if(node->parent->left == node){
    node->parent->left = rNode;
  }
  else{
    node->parent->right = rNode;
  }
  rNode->right = node;
  node->parent = rNode;
}

string RBTree::min(){
  Node* node = root;

  while(node->left !=NIL){
    node=node->left;
  }
  return node->value;
}

string RBTree::max(){
  Node* node = root;

  while(node->right !=NIL){
    node=node->right;
  }
  return node->value;
}

RBTree::Node* RBTree::findNode(string value){
  Node* node = root;
  while(node != NIL){
    findComparisions++;
    if(value == node->value)
      return node;
    else if(value > node->value && findComparisions++){
      node = node->right;
    }
    else{
      node = node->left;
    }
  }

  return node;
}
bool RBTree::find(string value){
  if(findNode(value) == NIL){
    return false;
  }
  else{
    return true;
  }
}

RBTree::Node* RBTree::nodeSuccessor(string value){
  Node* successor = NIL;
  Node* node = findNode(value);

  if(node != NIL){
    if(node->right != NIL){
      successor = node->right;

      while(successor->left != NIL){
        successor = successor->left;
      }
    }
    else{
      successor = node->parent;
      while(successor != NIL && successor->right == node){
        node = successor;
        successor = successor->parent;
      }
    }
  }
  return successor;
}
string RBTree::successor(string value){
  return nodeSuccessor(value)->value;
}
void RBTree::inorderWalk(){
  inorderWalk(root);
}

void RBTree::inorderWalk(Node* node){
  if(node != NIL){
    inorderWalk(node->left);
    cout << "\033[34m" << node->value << "\033[0m"<< endl;
    inorderWalk(node->right);
  }
}

RBTree::Node* RBTree::getRoot(){
  return root;
}
void RBTree::rewriteStructure(DynamicStructure* structure){
  inorderRewrite(root,structure);
  inorderWalk();
}
void RBTree::inorderRewrite(Node* node,DynamicStructure* structure){
  if(node != NIL){
    inorderWalk(node->left);
    structure->insert(node->value);
    inorderWalk(node->right);
  }
}
