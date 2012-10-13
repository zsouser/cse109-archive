#include "table.t"
#include "/proj/csc109/p3/word.h"

/**
   Zach Souser
   zrs212
   Program 3
   Lookup Table
   CSE 109
**/

void testRek();
void testTable();
/**
   Main Method
   tests classes Rek and Table with the testRek() and testTable()
   methods
**/
int main(){
  testRek();
  testTable();
}
/**
   Test Rek
   tests the Rek class by implementing 3 records and demonstrating
   functionality of operators
**/
void testRek(){
  Rek<int,int> t(9),u(3,4),v(u);
  cout<<t.getKey()<<endl;
  v.data=99;
  cout<<t<<u<<v<<endl;
};
/**
   Test Table
   Implements and tests the lookup table
**/
void testTable(){
  Table<int,int> t(20);
  t[1]=2;
  t[2]=1;
  cout<<t<<endl;

  Table<Word,Word> w;
  w["one"]="ONE";
  w["two"]="TOW";
  cout<<w;

  Table<Word,Word>  v(w),x;
  cout<<v;
  x=v;
  x["Sequoia"]="Tree";
  v["one"]="GOOOD";
  cout<<"Copies"<<x<<v;
}
/*******************************OUTPUT
9
{9, 0}{3, 4}{3, 99}

-------------------------
{1, 2}
{2, 1}
-------------------------


-------------------------
{one, ONE}
{two, TOW}
-------------------------

-------------------------
{one, ONE}
{two, TOW}
-------------------------
Copies
-------------------------
{Sequoia, Tree}
{one, ONE}
{two, TOW}
-------------------------

-------------------------
{one, GOOOD}
{two, TOW}
-------------------------
*********************************END OF OUTPUT*/
