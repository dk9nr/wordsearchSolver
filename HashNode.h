// Dev Kumar dk9nr 9/7/2017 ListNode.h
/*
 * Filename: ListNode.h
 * Description: ListNode class definition
 */

#ifndef HASHNODE_H
#define HASHNODE_H

#include <iostream>
#include "hashTable.h"


using namespace std;

class HashNode {
public:
  HashNode(int key, string value);
  int key;
  string value;
  int getKey();
  string getValue();
};

#endif















