#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include "hashTable.h"
#include "HashNode.h"
#include <math.h>
#include<stdio.h>
#include <fstream>
using namespace std;

const int tablesize = 136711; 

  
const int hashTable::siz()
{
  return tablesize;
}


hashTable::hashTable()
	{
	  //int TABLE_SIZE=250;
	  table = new HashNode * [tablesize];
	  for (int i = 0; i< tablesize; i++)
	    {
	      table[i] = NULL;
	    }
	  
	  
	  
	}
hashTable::~hashTable(){
  for (int i=0; i<tablesize;i++){
    delete table[i];
  }
}
// int hashTable::HashFunc(const string &value){
//   int sum=0;
//   for (int k=0;k<value.length();k++)
//     {sum=37*sum+(value[k]);
//     }
//   if (sum<0)
//     sum+=9000;
//   return sum%tablesize;
// }

int hashTable::HashFunc(string value){
  int sum=0;
  for (int k=0;k<value.length();k++)
    {sum=sum +int(value[k]);
    }
 
  
  return sum;
}


int hashTable::counter(string filename){
  int answer=0;
  string line;
  ifstream myfile(filename.c_str());
  while(getline(myfile,line))
    answer++;
  cout <<answer<<endl;
  return answer;
}





void hashTable::Insert(string value)
{
  int key= HashFunc(value);
  while (table[key]!=NULL){
    
    key=key*2654435761%tablesize;
  }
  if (table[key]==NULL){
    table[key]=new HashNode(key, value);
  }
  else
    cout<< "hi"<< endl;
}





    

bool hashTable::Search(string valu){
  int hash = HashFunc(valu);
  while (table[hash]!= NULL && table[hash]->getValue() !=valu)
    {
      hash=hash*2654435761%tablesize;
    }
  if (table[hash] ==NULL){
    return false;
      }
  else
    //cout<<table[hash]->getKey();
    return true;
}








































