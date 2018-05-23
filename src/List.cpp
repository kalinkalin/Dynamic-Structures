#include "List.h"
#include <iostream>
using namespace std;

List::List(){
  size = 0;
  head = NULL;
  tail = NULL;
}

List::~List(){
  delete head;
}
List::Node::~Node(){
  delete next;
}

void List::insert(string value){
  inserts++;
  Node* newNode = new Node();
  newNode->value = value;

  if(head == NULL){
    newNode->next = NULL;
    head = newNode;
    tail = head;
  }
  else{
    tail->next = newNode;
    tail = newNode;
  }
  size ++;
}
void List::deleteNode(string value){
   Node* temp = head;
   Node* previous = temp;
   Node* toDelete = NULL;

   if(value == head->value){
     head = head->next;
   }
   else{
     while(previous->next != NULL && value != previous->next->value){
       previous = previous->next;
     }
     if(previous->next != NULL){
       removals++;
       toDelete = previous->next;

       if(previous->next== tail){
          tail = previous;
          previous->next = NULL;
        }
        else{
          previous->next = previous->next->next;
        }
        toDelete->next = NULL;
        delete toDelete;
     }
   }
}

bool List::find(string value){
  Node* temp = head;

  while(temp != NULL){
    findComparisions++;
    if(value == temp->value){
      return true;
    }
    temp = temp->next;
  }

  return false;
}
void List::inorderWalk(){
  Node* temp = head;
  while(temp != NULL){
    cout << temp->value << endl;
    temp = temp->next;
  }
}
void List::rewriteStructure(DynamicStructure* structure){
  Node* temp = head;
  while(temp != NULL){
    structure->insert(temp->value);
    temp = temp->next;
  }
  delete this;
}
