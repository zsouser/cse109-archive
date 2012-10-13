/**
   Zach Souser
   CSE 109
   Spring 2010
   Programming Assignment #1

**/

#include "chip.h"

void testChip();
void testMemory();

int main(){
  testMemory();
  testChip();
  return 0;
}

void testChip(){
  Chip a(2,5);
  a.op(a.ADD);  // accum has 7
  a.push().push().push();  //three copies of 7 pushed
  a.top(-1).pop().top(-2).op(a.MUL); //put top in reg1, discard top,
  //put top in reg2, multiply to get 49
  a.pop();   //get rid of top
  a.push().pop(-1).pop(-2).op(a.MUL);  //push 49, pop to reg1, pop the
				       //7 to reg2, multiply
  cout<<"Expect 343: "<<a.acc()<<endl;
  a.store(1).load1(1).load2(1).op(a.ADD); //put 343 in mem[1],
  //load memroy to reg1 and reg2, add
  cout<<"Expect accum==686: "<<a<<endl;

  a.set1(20).set2(3).op(a.ADD);
  a.push().pop(30);
  a.op(a.SUB);
  cout<<"Accumulator (expect 17): "<<a<<endl;
  a.load1(30).load2(30);
  a.op(a.MUL);
  cout<<"Accumulator (expect 529): "<<a.acc()<<endl;
}

void testMemory(){
  Memory a,b(2),c(2);
  cout<<"Expect 2: "<<b.get()<<endl;
  cout<<"Expect 2: "<<c.get()<<endl;
  /*THE NEXT LINE SHOULD CRASH, BECAUSE a IS UNDEFINED
  cout<<a.get();
  */
  a.set(20);
  cout<<"Expect 20: "<<a.get()<<endl;
}

/*SAMPLE OUTPUT

Expect 2: 2
Expect 2: 2
Expect 20: 20
Expect 343: 343
Expect accum==686: {acc: 686, reg1: 343, reg2: 343}
Accumulator (expect 17): {acc: 17, reg1: 20, reg2: 3}
Accumulator (expect 529): 529

END OF SAMPLE OUTPUT
*/
