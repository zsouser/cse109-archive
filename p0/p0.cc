/**

Programming Assignment 0
Zach Souser
CSE 109
Spring 2010
zrs212

**/
#include "alu.h"

int getChoice();
void test1();
void test2();
void test3();
void test4();
void test5();


/** Main Method
    prompts the user for a selection
    and performs the selected test
*/

  int main(){
  switch(getChoice()){
  case 1: test1(); break;
  case 2: test2(); break;
  case 3: test3(); break;
  case 4: test4(); break;
  case 5: test5(); break;
  } 
  return 1;
}

/** getChoice()
    performs the user prompt
*/
int getChoice(){
  char ch;
  do{
    cout<<"Enter a digit from 1 to 5, depending on which of\n"
	<<"the five tests you wish to run- ";
    cin>>ch;
    if(ch<'1' || ch>'5')
      cout<<"Bad entry; please try again\n";
  }while(ch<'1' || ch>'5');
  return ch-'0';
}

/** test1()
    creates four ALU objects to perform various mathematical operations
*/
void test1(){
  ALU a,b(2),c(3,4),d(c);
  a.set1(23).set2(25);
  cout<<"Expect 48: "<<a.op(a.ADD).acc()<<endl;
  cout<<"Expect -2: "<<a.op(a.SUB).acc()<<endl;
  cout<<"Expect 575: "<<a.op(ALU::MUL).acc()<<endl;
  a.set1(27).set2(5);
  cout<<"Expect 5: "<<a.op(a.DIV).acc()<<endl;
  cout<<"Expect 2: "<<a.op(a.MOD).acc()<<endl;
  cout<<"Expect {acc: 2, reg1: 27, reg2: 5}: "<<a<<endl;
  cout<<"Expect 27, 5: "<<a.get1()<<", "<<a.get2()<<endl;
}

/** test2()
	performs division by zero
*/

void test2(){
  ALU a(2,0);
  a.op(a.DIV);
}

/** test3()
	performs modulus by zero
*/

void test3(){
  ALU a(2,0);
  a.op(a.MOD);
}

/** test4() 
	tests invalid input
*/
void test4(){
  ALU a;
  a.op(-2);
}
/** test5() 
	tests operation on empty ALU
*/
void test5(){
  ALU a;
  a.op(5);
}
