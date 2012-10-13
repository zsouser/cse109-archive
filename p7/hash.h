#ifndef HASH_H
#define HASH_H
#include "/proj/csc109/p5/table.t"
#include "/proj/csc109/p5/word.h"
#include <fstream>
#include <iostream>

class Node {
public:
  int freq;
  Word str;
  bool set;
  Node() : str(),freq(0),set(false) { }
  Node(Word& w) : str(w),freq(1),set(true) { }
  ~Node() { }
};

class Hash {
private:
  Node * table;
  int findPrime(int n); 
  bool isPrime(int n);
  int hash(Word& w);
  int findNode(Word& w);
  int size;
public:
  Hash(ifstream& in);
  ~Hash();
  void add(Word& w);
  void find(ifstream& in);
  int find(Word& w);
};

#endif
