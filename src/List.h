#include "DynamicStructure.h"
#include <string>

class List : public DynamicStructure{

  private:
    int size;
    struct Node{
      string value;
      Node* next;
      ~Node();
    };
    Node* head;
    Node* tail;

  public:
    List();
    ~List();
    void insert(string value);
    void deleteNode(string value);
    bool find(string value);
    void inorderWalk();
    void rewriteStructure(DynamicStructure* structure);
};
