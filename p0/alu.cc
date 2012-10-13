#include "alu.h"


// Constructors
ALU::ALU() {
  reg1 = 0;
  reg2 = 0;
  accum = 0;
}

ALU::ALU(int x) {
  reg1 = x;
  reg2 = 0;
  accum = 0;
}

ALU::ALU(int x, int y) {
  reg1 = x;
  reg2 = y;
  accum = 0;
}

ALU::ALU(ALU& a) {
  reg1 = a.get1();
  reg2 = a.get2();
  accum = 0;
}

// Accessor methods
int ALU::get1() {
  return reg1;
}

int ALU::get2() {
  return reg2;
}

// Mutator methods
ALU& ALU::set1(int x) {
  reg1 = x;
  return *this;
}

ALU& ALU::set2(int x) {
  reg2 = x;
  return *this;
}

// Operations
ALU& ALU::op(const int flag) {
  if (flag < 0 || flag > 5) cout << "Invalid operation\n";
  switch (flag) {
  case ADD: accum = reg1 + reg2; break;
  case SUB: accum = reg1 - reg2; break;
  case MUL: accum = reg1 * reg2; break;
  case DIV: if (reg2 == 0) cout<<"Divide by zero\n"; else accum = reg1 / reg2; break;
  case MOD: if (reg2 == 0) cout<<"Divide by zero\n"; else accum = reg1 % reg2; break;
  }
  return *this;
}

int ALU::acc() {
  return accum;
}

ostream & operator <<(ostream & out, ALU& a) {
  out << "{ acc:" << a.accum << ", reg1:" << a.reg1 << ", reg2:" << a.reg2 << " }";
  return out;
}

