#ifndef TABLE_T
#define TABLE_T
#include "rek.t"
/**
   Zach Souser
   Class Table
   CSE 109
   Lookup Table
   P3
**/

// Declaration of class

template<class K, class D>
class Table {
public:
  Rek<K,D> **table;
  int count;
  Table() : table(new Rek<K,D>*[10]),count(10){ }
  Table(int x) : table(new Rek<K,D>*[x]),count(x) { }
  Table(const Table<K,D>& t) : table(t.table), count(t.count) { }
  ~Table();
  Rek<K,D> & operator[](K k);
  Table<K,D> & operator=(Table<K,D>& t);
};

// Operator overloading - equals sign
// Copies the contents of one table over to the other

template<class K, class D>
Table<K,D> & Table<K,D>::operator=(Table<K,D>& t) {
  count = t.count;
  for (int i = 0; i < count; i++)
    table[i] = t.table[i];
  return *this;
}

// Destructor - deletes the table

template<class K, class D>
Table<K,D>::~Table() {
  delete [] table;
}

// Operator overload - []
// Assigns a record to the lookup table or returns the value of a
// record identified by key

template<class K, class D>
Rek<K,D> & Table<K,D>::operator[](K k) {
  int i = 0;
  do {
    if (table[i] == NULL) {
      table[i] = new Rek<K,D>(k);
      count++;
      break;
    }
    else if (table[i]->key == k) return *table[i];
    i++;
  } while (i < count);
  return *table[i];
}

// Operator overload - <<
// Outputs the table in a formatted manner

template<class K, class D>
ostream & operator<<(ostream& out, Table<K,D>& t) {
  out << endl <<  "------------------------" << endl;
  int i = 0;
  while(t.table[i] != NULL) {
    out << *t.table[i] << endl;
    i++;
  }
  return out << "------------------------" << endl;
}

#endif

