//Dev Kumar,dk9nr,8/31/2017, ListNode.cpp
#include <iostream>
#include "HashNode.h"
#include "hashTable.h"
#include <string>
using namespace std;

HashNode::HashNode(int key, string value){
  this->key=key;
  this->value=value;
}

int HashNode::getKey(){
  return key;
}

string HashNode::getValue(){
  return value;
}


 
