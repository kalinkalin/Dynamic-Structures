#include <iostream>
#include <string>
#include "HashTable.h"
#include "List.h"
#include "RBTree.h"
using namespace std;

HashTable::HashTable(){
  for(int i = 0; i < hashSize; i++){
    hashArray[i]=(ChainStructure*)malloc(sizeof(ChainStructure));
    hashArray[i]->structure = NULL;
    hashArray[i]->size = 0;
    hashArray[i]->RBTree = false;
  }
}

int HashTable::hashCode(string toHash)
{
    unsigned int num = hashFunction(toHash);
    return num%hashSize;
}
void HashTable::deleteNode(string value){
  removals++;
  elements--;
  int index = hashCode(value);
  hashArray[index]->structure->deleteNode(value);
  hashArray[index]->size--;

  if(hashArray[index]->size == maxSize && hashArray[index]->RBTree==true){
    hashArray[index]->structure->insert(value);
    List* tempList = new List();
    hashArray[index]->structure->rewriteStructure(tempList);
    hashArray[index]->structure = tempList;
    hashArray[index]->RBTree = false;
  }
}
void HashTable::insert(string value){
  inserts++;
  elements++;
  int index = hashCode(value);

  if(hashArray[index]->structure==NULL){
    hashArray[index]->RBTree = false;
    hashArray[index]->structure = new List();
    hashArray[index]->structure->insert(value);
  }
  else if(hashArray[index]->size == maxSize && hashArray[index]->RBTree==false){
    hashArray[index]->structure->insert(value);
    RBTree* tempRBT = new RBTree();
    hashArray[index]->structure->rewriteStructure(tempRBT);
    hashArray[index]->structure = tempRBT;
    hashArray[index]->RBTree = true;
  }
  else{
    hashArray[index]->structure->insert(value);
  }
  hashArray[index]->size++;
}

bool HashTable::find(string value){
  int index = hashCode(value);
  bool found = hashArray[index]->structure->find(value);
  findComparisions = hashArray[index]->structure->getComparisions();

  return found;
}
