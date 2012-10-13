#include "hash.h"
#include <cmath>
using namespace std;  


// Construct the hash table by taking in a file of words and storing
// it in a temporary table to determine the size of the file, and then
// add each word to the actual hash table

Hash::Hash(ifstream& in) : size(0) {
  Table<int,Word> words(1000);
  while (!in.eof()) {
    in >> words[size++];
  }
  table=new Node[findPrime(size*2)];
  for (int i = 0; i < size; i++) {
    add(words[i]);
  }
}

// Deconstructor 

Hash::~Hash() {
  delete[] table;
}

// function add()
// find the correct node and insert it, or update the frequency

void Hash::add(Word& w) {
  if (table[findNode(w)].set) table[findNode(w)].freq++;
  else table[findNode(w)] = Node(w);
}

// function findNode()
// implement quadratic probing to find the correct

int Hash::findNode(Word& w) {
  int probes = 0;
  int pos = hash(w);
  while(table[pos].set && table[pos].str != w) {
    pos += 2 * ++probes - 1;
  }
  return pos;
}

// function find()
// finds the frequency of a word in the table

int Hash::find(Word & w) {
  Node n = table[findNode(w)];
  if (!n.set) return 0;
  return n.freq;
}

// function find()
// reads in a file and finds the frequency of each word in the file

void Hash::find(ifstream& in) {
  check(!in.fail(),"Invalid query file.",__LINE__,__FILE__);
  while (!in.eof()) {
    Word word;
    in>>word;
    if (word != "")
    cout<<word<<" - "<<find(word)<<endl;
  }
}

// prime number checker

bool Hash::isPrime(int n) {
  if(n == 2 || n == 3)
    return true;
  if(n == 1 || n % 2 == 0)
    return false;
  for(int i = 3; i * i <= n; i += 2)
    if(n % i == 0)
      return false;
  return true;
}

// prime number calculator

int Hash::findPrime(int n) {
  if(n % 2 == 0)
    n++;
  while (!isPrime(n)) n += 2;
  return n;
}

// hash number generator

int Hash::hash(Word& w) {
  int hash = 0;
  for (int i = 0; i < w.length(); i++) 
    hash = hash + w[i];
  return hash % size;
}
