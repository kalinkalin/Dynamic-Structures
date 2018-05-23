#pragma once

#include <cstdio>
#include <string>
using namespace std;

/**
*all structures are extending this class and implementing virtual methods.
*/

class DynamicStructure{
  protected:
    double totalTime;
    int findComparisions;
    int inserts;
    int removals;
    int elements;
  public:
    DynamicStructure();
    virtual void insert(string value) = 0;
    virtual void inorderWalk();
    virtual void deleteNode(string value)=0;
    virtual bool find(string value);
    virtual string max();
    virtual string min();
    virtual string successor(string value);
    virtual void rewriteStructure(DynamicStructure* structure);
    int getRemovals();
    int getInserts();
    int getElements();
    int getComparisions();
    virtual ~DynamicStructure()=0;
};
