#ifndef WORD_H
#define WORD_H
#include <iostream>
using namespace std;

// a wrapper class for char *
//to avoid NULL pointers
//  if I have char * x;
//      x="a wstring"
//     x actually points to 10 characters, the 9 above
//     termiating with '\0'

class Word{
private:
  char *wd;
public:
  Word();
  Word(const Word &w);
  ~Word();//deallocate wd
  Word(char ch);
  //  "a" is not the same as 'a', "a" is an array of two
  // characters, 'a' and '\0'
  Word(const char *ch);//   Word a("hello"). If ch==NULL, store ""
  // "" is the string of length 0, terminated by '\0'
  Word(Word& wrd); // Copy constructor
  friend ostream & operator<<(ostream &out,const Word &w);
  friend istream & operator>>(istream &in,Word &w);// read up to '\n'
  //   OR  end of file
  friend bool operator<(const Word &a, const Word &b);
  friend bool operator>(const Word &a, const Word &b);
  friend bool operator>=(const Word &a, const Word &b);
  friend bool operator<=(const Word &a, const Word &b);
  friend bool operator!=(const Word &a, const Word &b);
  friend bool operator==(const Word &a, const Word &b);
  char & operator[](int b)const;
  static Word fromInt(int k);// only allow k>=0
  int toInt()const; //converts wd to an int IF all digits
  const Word & operator=(const Word &w);
  void copy(const char * ch);
  const char *toString();
  int length();
};







#endif
