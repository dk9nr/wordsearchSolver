// Dev Kumar dk9nr 10/9/2017 TreeCalc.h
// TreeCalc.h: Tree Calculator class definition
// CS 2150: Lab 5
// NOTE: You may use any stack implementation that you wish
// You must submit ALL code to make your project build correctly


#ifndef HASHTABLE_H
#define HASHTABLE_H


using namespace std;

class HashNode;
class hashTable {
public:
  hashTable();
  ~hashTable();
  int HashFunc(string value);
  void Insert(string value);
  bool Search(string valu);
  HashNode **table;
  int counter(string filename);
  const int siz();

private:

    
    friend class HashNode;
    //  friend class wordSearch;

};

#endif
