#ifndef REK_T
#define REK_T
#include <iostream>
using namespace std;

/**
   Zach Souser
   zrs212
   Program 3
   Class Rek
   CSE 109
**/

// Class declaration

template <class K, class D>
class Rek {
public:
  K key;
  D data;
  Rek() : key(), data() { }
  Rek(K k) : key(*new K(k)), data() { }
  Rek(K k, D d) : key(*new K(k)), data(*new D(d)) { }
  Rek(const Rek<K,D>& r) : key(r.key), data(r.data) {  }
  ~Rek();
  K getKey();
  Rek<K,D> & operator=(D d);
};

// Destructor

template<class K, class D>
Rek<K,D>::~Rek() { }

// Key accessor method

template<class K, class D>
K Rek<K,D>::getKey() {
  return key;
}

// Assignment operator

template<class K, class D>
Rek<K,D> & Rek<K,D>::operator=(D d) {
  data = *new D(d);
  return *this;
}

// Output operator

template<class K, class D>
ostream & operator<<(ostream &out, const Rek<K,D> r) {
  out << "{" << r.key << ", " << r.data << "}";
  return out;
}

#endif
