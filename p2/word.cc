/**
   Zach Souser
   zrs212
   Program #2
**/

#include "word.h"
#include "check.cc"
#include <cmath>
// Constructors
Word::Word(){
   char ch[1];
  ch[0]='\0';
  copy(ch);
}

Word::Word(char ch){
  char kh[2];
  kh[0]=ch;
  kh[1]='\0';
  copy(kh);
}

Word::Word(const char *ch){
  if(ch==NULL){
    char kh[1];
    kh[0]='\0';
    copy(kh);
  }
  else
    copy(ch);
}

Word::Word(Word& wrd) {
  copy(wrd.wd);
}
// Destructor
Word::~Word(){delete [] wd;}
// Operators
const Word & Word::operator=(const Word &w){
  delete []wd;
  copy(w.wd);
  return *this;
}

ostream & operator<<(ostream & out,const Word &w){
  return out<<w.wd;
}

istream & operator>>(istream &in,Word &w){//first arg added after class
  char *temp, *tempa;
  int loc,sz;
  temp=new char[11];
  sz=10;
  check(temp!=NULL,"Heap overflow",__LINE__,__FILE__);
  in.get(temp[0]);
  loc=0;
  while(in.good() && temp[loc]!='\n'){
    loc++;
    if(loc>=sz){
      sz*=2;
      tempa=new char[sz+1];
      check(tempa!=NULL,"Heap overflow",__LINE__,__FILE__);
      strcpy(tempa,temp);   //Java: String.?
      delete[]temp;
      temp=tempa;
    }
    in.get(temp[loc]);
  }
  temp[loc]='\0';
  delete[]w.wd;
  w.copy(temp);
  return in; //added after class
}

bool operator<(const Word &a, const Word &b){
  return strcmp(a.wd,b.wd)<0;}  // Java: String: compareTo
bool operator>(const Word &a, const Word &b){
  return strcmp(a.wd,b.wd)>0;}
bool operator>=(const Word &a, const Word &b){
  return strcmp(a.wd,b.wd)>=0;}
bool operator<=(const Word &a, const Word &b){
  return strcmp(a.wd,b.wd)<=0;}
bool operator!=(const Word &a, const Word &b){
  return strcmp(a.wd,b.wd)!=0;}
bool operator==(const Word &a, const Word &b){
  return strcmp(a.wd,b.wd)==0;}
char & Word::operator[](int b)const{
  return wd[b];}
/*
NOTE:  strlen(w.wd) returns the number of charaters in wd, not including \0
  strlen("a word")==6
*/

// Copy function

void Word::copy(const char * ch){
  wd=new char[strlen(ch)+1];
  strcpy(wd,ch);
}

// Length function - computes the length of the word

int Word::length(){
  return strlen(wd);
}

// toInt - converts string to int

int Word::toInt()const {
  return atoi(wd);
}

// fromInt - converts an integer to a string

Word Word::fromInt(int k) {
  check(k >= 0,"Invalid integer.",__LINE__,__FILE__);
  int i = (int)log(k)-1;
  char * temp = new char[i];
  temp[i] = '\0';
  while (i > 0) {
    i--;
    temp[i] = (char)(k%10)+'0';
    k/=10;
  }
  return *new Word(temp);
}

// toString - returns the word as a string

const char* Word::toString() {
  return wd;
}
