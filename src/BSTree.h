#include "DynamicStructure.h"
using namespace std;

class BSTree : public DynamicStructure{
  private:
    struct Node{
      Node* parent;
      Node* left;
      Node* right;
      string value;
      ~Node();
    };
    Node* root;

  public:
    void insert(string value);
    string min();
    string max();
    void deleteNode(string value);
    void inorderWalk();
    void inorderWalk(Node* node);
    Node* nodeSuccessor(string k);
    string successor(string k);
    Node* findNode(string value);
    bool find(string value);
    ~BSTree();
};
