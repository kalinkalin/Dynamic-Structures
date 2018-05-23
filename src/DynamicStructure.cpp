
#include "DynamicStructure.h"
#include <iostream>
using namespace std;

DynamicStructure::~DynamicStructure(){}
DynamicStructure::DynamicStructure(){
  findComparisions=0;
  inserts=0;
  removals=0;
  elements=0;
}
bool DynamicStructure::find(string value){
  return false;
}
string DynamicStructure::max(){
  return (string)"";
}
string DynamicStructure::min(){
  return (string)"";
}
string DynamicStructure::successor(string value){
  return (string)"";
}
void DynamicStructure::inorderWalk(){
  cout << endl;
}
void DynamicStructure::rewriteStructure(DynamicStructure* structure){
}
int DynamicStructure::getRemovals(){
  return removals;
}
int DynamicStructure::getInserts(){
  return inserts;
}
int DynamicStructure::getElements(){
  return elements;
}
int DynamicStructure::getComparisions(){
  return findComparisions;
}
