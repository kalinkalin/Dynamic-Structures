#pragma once
#include "DynamicStructure.h"
using namespace std;

enum color{
  red,
  black
};

class RBTree : public DynamicStructure{
  private:
    struct Node{
      Node* parent;
      Node* left;
      color nodeColor;
      Node* right;
      string value;
      ~Node();
    };
    Node* root;
    static Node* NIL;

  public:
    ~RBTree();
    RBTree();
    void insert(string value);
    void bst_insert(Node* newNode);
    void right_rotate(Node* node);
    void left_rotate(Node* node);
    string min();
    string max();
    void deleteNode(string value);
    void delete_fixup(Node*node);
    void inorderWalk();
    void inorderWalk(Node* node);
    Node* nodeSuccessor(string value);
    string successor(string value);
    Node* findNode(string value);
    bool find(string value);
    Node* getRoot();
    void rewriteStructure(DynamicStructure* structure);
    void inorderRewrite(Node* node, DynamicStructure* structure);
};
