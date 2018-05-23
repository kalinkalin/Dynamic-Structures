#include "DynamicStructure.h"
#include <functional>
#include <string>
#define hashSize 124
#define maxSize 120

class HashTable : public DynamicStructure{
  private:
    struct ChainStructure{
      int size;
      bool RBTree;
      DynamicStructure* structure;
    };
    ChainStructure* hashArray[hashSize];
    std::hash<std::string> hashFunction;
  public:
    HashTable();
    void insert(string value);
    void deleteNode(string value);
    int hashCode(string value);
    bool find(string);
};
